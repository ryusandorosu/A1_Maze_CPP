#include "../maze/maze.h"

int main(int argc, char* argv[]) {
  if (argc != 4) {
    cerr << "Использование: " << argv[0] << " <путь к файлу> <строки> <столбцы>"
         << endl;
    return 1;
  }

  string filename = argv[1];

  int rows = stoi(argv[2]);
  int cols = stoi(argv[3]);

  Maze generator(rows, cols);
  if (!generator.checkDimensions()) {
    return 1;
  }
  generator.generateMaze();
  generator.saveMazeToFile(filename);

  Maze parser(filename);
  if (!parser.readMaze()) {
    return 1;
  }
  parser.drawMaze();
  return 0;
}
