#ifndef A1_MAZE_CPP_1_SRC_BACKEND_COMMON_PARSER_H_
#define A1_MAZE_CPP_1_SRC_BACKEND_COMMON_PARSER_H_

#include "utils.h"

class CommonParser {
 public:
  CommonParser() = default;
  ~CommonParser() = default;
  bool readFile(const string& filename, Matrix& field, int& rows, int& cols);
  bool isBlankLine(const string& line);

 protected:
  static const int MAX_SIZE = 50;

  // Чисто виртуальные методы, которые будут реализованы в производных классах
  virtual bool validateRowCount(const string& filename, int expectedRows) = 0;
  virtual bool validateRowCount(const string& filename, int expectedRows,
                                int& rowsInMatrix1, int& rowsInMatrix2) = 0;
  virtual bool validateColumnCount(ifstream& file, int expectedCols) = 0;

 private:
  enum class FileType { CAVE, MAZE, UNKNOWN };
  FileType determineFileType(const string& filename, int expectedRows);
  bool readFieldData(ifstream& file, Matrix& field, int fileRows, int fileCols);
};

#endif  // A1_MAZE_CPP_1_SRC_BACKEND_COMMON_PARSER_H_
