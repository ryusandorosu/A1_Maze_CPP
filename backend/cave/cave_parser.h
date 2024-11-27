#ifndef A1_MAZE_CPP_1_SRC_BACKEND_CAVE_PARSER_H_
#define A1_MAZE_CPP_1_SRC_BACKEND_CAVE_PARSER_H_

#include "../common/parser.h"
#include "../common/utils.h"

class CaveParser : public CommonParser {
 public:
  CaveParser(const string& filename) : filename(filename) {};
  bool readCave();
  void drawField();
  Matrix getField() { return field; }

 private:
  string filename;
  Matrix field;
  bool validateRowCount(const string& filename, int expectedRows);
  bool validateRowCount(const string& filename, int expectedRows,
                        int& rowsInMatrix1, int& rowsInMatrix2);
  bool validateColumnCount(ifstream& file, int expectedCols);
};

#endif  // A1_MAZE_CPP_1_SRC_BACKEND_CAVE_PARSER_H_
