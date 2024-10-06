#include "cave_parser.h"

bool CaveParser::readCave() {
  int rows, cols;

  if (!readFile(filename, field, rows, cols)) {
    return false;
  }

  return true;
}
