#include "../maze/main/maze_parser.h"
#include "../maze/solver/class_solver.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Использование: " << argv[0] << " <путь к файлу>" << endl;
    return 1;
  }

  string filename = argv[1];

  MazeParser mazeParser(filename);
  if (!mazeParser.readMaze()) {
    return 1;
  }

  vector<string> maze = mazeParser.getMazeRepresentation();
  Matrix VW = mazeParser.getVerticalWalls();
  Matrix HW = mazeParser.getHorizontalWalls();
  int rows = mazeParser.getRows();
  int cols = mazeParser.getCols();

  MazeSolver solver(VW, HW, rows, cols);
  // по идее координаты должны устанавливаться пользователем произвольно
  // но я в консоли решил с этим не морочиться и задаю их здесь хардкодом:
  Coord start = {0, 0};              // левый верх
  Coord end = {rows - 1, cols - 1};  // правый низ

  mazeParser.drawMaze();  // оригинальная матрица для сравнения
  if (solver.solveMaze(start, end)) {
    solver.printSolutionMatrix();
    solver.drawMazeSolution(solver.getSolutionMatrix(), maze);
  } else {
    cout << "Решение не найдено!" << endl;
  }

  return 0;
}
