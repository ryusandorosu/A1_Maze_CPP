MAKEFLAGS += --no-print-directory
CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++17
COMPILE = $(CC) $(FLAGS)
OS = $(shell uname -s)

BACK_DIR = backend
COMM_DIR = $(BACK_DIR)/common
CAVE_DIR = $(BACK_DIR)/cave
MAZE_DIR = $(BACK_DIR)/maze
FRONTEND = frontend
FRONTEXE = maze_cpp
DIST_DIR = build

CAVE_EXE = print_cave
MAZE_DRW_EXE = print_maze
MAZE_GEN_EXE = gen_maze
MAZE_SOL_EXE = solve_maze

CAVE_SRC = $(wildcard $(COMM_DIR)/*.cc $(CAVE_DIR)/*.cc)
MAZE_SRC = $(wildcard $(COMM_DIR)/*.cc $(MAZE_DIR)/*/*.cc)
COMM_SRC = $(wildcard $(COMM_DIR)/*.cc $(CAVE_DIR)/*.cc $(MAZE_DIR)/*/*.cc)
MAZE_DRW_SRC = $(wildcard $(COMM_DIR)/*.cc $(MAZE_DIR)/parser/*.cc)
MAZE_GEN_SRC = $(wildcard $(COMM_DIR)/*.cc $(MAZE_DIR)/parser/*.cc $(MAZE_DIR)/generator/*.cc)
MAZE_SOL_SRC = $(wildcard $(COMM_DIR)/*.cc $(MAZE_DIR)/parser/*.cc $(MAZE_DIR)/solver/*.cc)

#на линуксе объектные файлы собираются без предупреждений, на маке они есть хотя по идее быть не должно так как мы используем 17 стандарт а не <11
COMM_OBJ = $(patsubst %.cc, %.o, $(COMM_SRC))
COMM_LIB = $(BACK_DIR).a
COMM_TEST_EXE = testexe
COMM_GCOV = testgcov
CAVE_TEST_DIR = tests/cave
MAZE_TEST_DIR = tests/maze
COMM_TEST_SRC = $(wildcard $(CAVE_TEST_DIR)/*.cc $(MAZE_TEST_DIR)/*.cc)
ARCHNAME = cpp_maze_dist

all: install
install: install_backend install_frontend
uninstall:
	@rm -rf $(DIST_DIR)

clean:
	@make clean_objects
	@rm -f $(COMM_TEST_EXE)
	@rm -rf report
	@rm -rf $(ARCHNAME) $(ARCHNAME).tgz
clean_objects:
	@rm -rf *.o */*/*.o */*/*/*.o
	@rm -f $(COMM_LIB)
	@rm -f isolation_areas_check.txt
clean_report:
	@rm -rf *.gcda *.gcno *.info
	@rm -rf $(COMM_GCOV)
	@make clean_objects
clean_frontend:
	@rm -rf */.qt */CMakeFiles */CMakeCache */CMakeCache.txt */*.cmake */*_autogen
	@rm -rf */*_build*
	@rm -f */Makefile

install_frontend: uninstall_frontend
	@cd $(FRONTEND) && cmake CMakeLists.txt && make
	@make clean_frontend && make clean
	@make run

uninstall_frontend:
	@rm -f $(DIST_DIR)/$(FRONTEXE)

run:
ifeq ($(OS), Linux)
	@./$(DIST_DIR)/$(FRONTEXE)
else ifeq ($(OS), Darwin)
	@./$(DIST_DIR)/$(FRONTEXE).app/Contents/MacOS/$(FRONTEXE)
endif

install_backend: uninstall_backend
	@mkdir -p build
	@$(COMPILE) $(CAVE_SRC) $(BACK_DIR)/console/cave.cc -o $(DIST_DIR)/$(CAVE_EXE)
	@echo "console cave drawing executable build done"
	@$(COMPILE) $(MAZE_DRW_SRC) $(BACK_DIR)/console/maze_drawing.cc -o $(DIST_DIR)/$(MAZE_DRW_EXE)
	@echo "console maze drawing executable build done"
	@$(COMPILE) $(MAZE_GEN_SRC) $(BACK_DIR)/console/maze_gen.cc -o $(DIST_DIR)/$(MAZE_GEN_EXE)
	@echo "console maze generation executable build done"
	@$(COMPILE) $(MAZE_SOL_SRC) $(BACK_DIR)/console/maze_solve.cc -o $(DIST_DIR)/$(MAZE_SOL_EXE)
	@echo "console maze solving executable build done"
	@echo && echo "Backend modules compilation is successful!"
	@make clean

uninstall_backend: clean
	@rm -f $(DIST_DIR)/$(CAVE_EXE)
	@rm -f $(DIST_DIR)/$(MAZE_DRW_EXE)
	@rm -f $(DIST_DIR)/$(MAZE_GEN_EXE)
	@rm -f $(DIST_DIR)/$(MAZE_SOL_EXE)

$(COMM_LIB): clean $(COMM_OBJ)
	@$(CC) -c $(FLAGS) $(COMM_SRC)
	@ar rcs $(COMM_LIB) $(COMM_OBJ)

tests: clean $(COMM_LIB)
	@$(COMPILE) tests/unit_tests.cc $(COMM_TEST_SRC) $(COMM_SRC) -o $(COMM_TEST_EXE) -lgtest
	@./$(COMM_TEST_EXE)
	@make clean_objects

gcov_report: clean_report
	@$(COMPILE) -fprofile-arcs -ftest-coverage $(COMM_SRC) $(COMM_TEST_SRC) tests/unit_tests.cc -o $(COMM_GCOV) -lgtest
	@./$(COMM_GCOV) >> /dev/null
ifeq ($(OS), Linux)
	@lcov -t "$(COMM_GCOV)_report" -o $(COMM_GCOV).info --no-external -c -d . >> /dev/null
else
	@lcov -t "$(COMM_GCOV)_report" -o $(COMM_GCOV).info --no-external -c -d . --ignore-errors inconsistent,format,usage >> /dev/null
endif
	@genhtml -o report $(COMM_GCOV).info >> /dev/null
	@open ./report/index.html
	@make clean_report

style:
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -n $(BACK_DIR)/*.* $(BACK_DIR)/*/*.* $(BACK_DIR)/*/*/*.* tests/*.* tests/*/*.*
	@clang-format -n $(FRONTEND)/*/*.*
	@rm -f .clang-format

dist: clean clean_frontend
	@mkdir -p $(ARCHNAME)
	@cp -r $(BACK_DIR) $(FRONTEND) files tests Makefile $(ARCHNAME)
	@tar cvzf $(ARCHNAME).tgz $(ARCHNAME)/
	@rm -rf $(ARCHNAME)
#разархивирование:
xdist:
	@tar -xvzf $(ARCHNAME).tgz

dvi:
	@open README.md

memtest:
	@make test >> /dev/null
ifeq ($(OS), Linux)
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./$(COMM_TEST_EXE)
else ifeq ($(OS), Darwin)
	leaks --atExit -- ./$(COMM_TEST_EXE)
endif
