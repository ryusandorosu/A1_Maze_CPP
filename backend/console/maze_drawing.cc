#include "../maze/maze.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Использование: " << argv[0] << " <путь к файлу>" << endl;
    return 1;
  }

  string filename = argv[1];

  Maze mazeParser(filename);

  if (!mazeParser.readMaze()) {
    return 1;
  }

  mazeParser.drawMaze();
  return 0;
}
