#include "../maze/main/maze_parser.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Использование: " << argv[0] << " <путь к файлу>" << endl;
    return 1;
  }

  string filename = argv[1];

  /* этот участок прописать на фронте */
  MazeParser mazeParser(filename);

  if (!mazeParser.readMaze()) {
    return 1;
  }
  /* до сюда */

  // и за основу для отрисовки в ui взять этот метод:
  mazeParser.drawMaze();
  return 0;
}
