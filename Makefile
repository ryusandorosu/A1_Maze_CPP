MAKEFLAGS += --no-print-directory
CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++17
COMPILE = $(CC) $(FLAGS)
OS = $(shell uname -s)

COMM_DIR = backend/common
CAVE_DIR = backend/cave
MAZE_DIR = backend/maze
CAVE_EXE = print_cave
MAZE_DRW_EXE = print_maze
MAZE_GEN_EXE = gen_maze
MAZE_SOL_EXE = solve_maze
CAVE_SRC = $(wildcard $(COMM_DIR)/*.cc $(CAVE_DIR)/*.cc)
MAZE_SRC = $(wildcard $(COMM_DIR)/*.cc $(MAZE_DIR)/*/*.cc)
COMM_SRC = $(wildcard $(COMM_DIR)/*.cc $(CAVE_DIR)/*.cc $(MAZE_DIR)/*/*.cc)
MAZE_DRW_SRC = $(wildcard $(COMM_DIR)/*.cc $(MAZE_DIR)/main/*.cc)
MAZE_GEN_SRC = $(wildcard $(COMM_DIR)/*.cc $(MAZE_DIR)/main/*.cc $(MAZE_DIR)/generator/*.cc)
MAZE_SOL_SRC = $(wildcard $(COMM_DIR)/*.cc $(MAZE_DIR)/main/*.cc $(MAZE_DIR)/solver/*.cc)
COMM_OBJ = $(patsubst %.cc, %.o, $(COMM_SRC))
#на линуксе объектные файлы собираются без предупреждений, на маке они есть хотя по идее быть не должно так как мы используем 17 стандарт а не <11
COMM_LIB = backend.a
COMM_TEST_EXE = testexe
COMM_GCOV = testgcov
CAVE_TEST_DIR = tests/cave
MAZE_TEST_DIR = tests/maze
COMM_TEST_SRC = $(wildcard $(CAVE_TEST_DIR)/*.cc $(MAZE_TEST_DIR)/*.cc)

all: install_backend
install_backend: install_cave install_maze
uninstall_backend: uninstall_cave uninstall_maze
clean:
	@make clean_objects
	@rm -rf debug
	@rm -rf report
	@rm -rf *.a
clean_objects:
	@rm -rf *.o */*/*.o */*/*/*.o
	@rm -rf isolation_areas_check.txt
	@rm -rf $(COMM_TEST_EXE)
clean_report:
	@rm -rf *.gcda *.gcno *.info
	@rm -rf $(COMM_GCOV)
	@make clean_objects
style:
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -i backend/*.* backend/*/*.* backend/*/*/*.* tests/*.* tests/*/*.*
	@clang-format -n backend/*.* backend/*/*.* backend/*/*/*.* tests/*.* tests/*/*.*
	@rm -f .clang-format

install_cave: uninstall_cave
	@$(COMPILE) $(CAVE_SRC) backend/console/cave.cc -o $(CAVE_EXE)
	@make clean
uninstall_cave: clean
	@rm -rf $(CAVE_EXE)

install_maze: uninstall_maze
	@$(COMPILE) $(MAZE_DRW_SRC) backend/console/maze_drawing.cc -o $(MAZE_DRW_EXE)
	@$(COMPILE) $(MAZE_GEN_SRC) backend/console/maze_gen.cc -o $(MAZE_GEN_EXE)
	@$(COMPILE) $(MAZE_SOL_SRC) backend/console/maze_solve.cc -o $(MAZE_SOL_EXE)
	@make clean
uninstall_maze: clean
	@rm -rf $(MAZE_DRW_EXE) $(MAZE_GEN_EXE) $(MAZE_SOL_EXE)

$(COMM_LIB): clean $(COMM_OBJ)
	@$(CC) -c $(FLAGS) $(COMM_SRC)
	@ar rcs $(COMM_LIB) $(COMM_OBJ)
test: clean $(COMM_LIB)
	@$(COMPILE) tests/unit_tests.cc $(COMM_TEST_SRC) $(COMM_SRC) -o $(COMM_TEST_EXE) -lgtest
	@./$(COMM_TEST_EXE)
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

memtest:
	@make test >> /dev/null
ifeq ($(OS), Linux)
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./$(COMM_TEST_EXE)
endif