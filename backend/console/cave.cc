#include "../cave/cave_parser.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Использование: " << argv[0] << " <путь к файлу>" << endl;
    return 1;
  }

  string filename = argv[1];

  /* этот участок прописать на фронте */
  CaveParser caveParser(filename);

  if (!caveParser.readCave()) {
    return 1;
  }
  /* до сюда */

  // и за основу для отрисовки в ui взять этот метод:
  caveParser.drawField();
  return 0;
}
