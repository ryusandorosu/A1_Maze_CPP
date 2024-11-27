#include "../maze/maze.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Использование: " << argv[0] << " <путь к файлу>" << endl;
    return 1;
  }

  string filename = argv[1];

  Maze object(filename);
  if (!object.readMaze()) {
    return 1;
  }

  vector<string> maze = object.getMazeRepresentation();
  int rows = object.getRows();
  int cols = object.getCols();

  // по идее координаты должны устанавливаться пользователем произвольно
  // но я в консоли решил с этим не морочиться и задаю их здесь хардкодом:
  Coord start = {0, 0};              // левый верх
  Coord end = {rows - 1, cols - 1};  // правый низ

  object.clearSolutionMatrix();
  // object.drawMaze();  // оригинальная матрица для сравнения
  if (object.solveMaze(start, end)) {
    // object.printSolutionMatrix();
    object.drawMazeSolution(object.getSolutionMatrix(), maze);
  } else {
    cout << "Решение не найдено!" << endl;
  }

  return 0;
}
