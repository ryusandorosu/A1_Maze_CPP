#include "../cave/cave_parser.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Использование: " << argv[0] << " <путь к файлу>" << endl;
    return 1;
  }

  string filename = argv[1];

  CaveParser caveParser(filename);

  if (!caveParser.readCave()) {
    return 1;
  }

  caveParser.drawField();
  return 0;
}
