#ifndef A1_MAZE_CPP_1_SRC_BACKEND_MAZE_MAIN_PARSER_H_
#define A1_MAZE_CPP_1_SRC_BACKEND_MAZE_MAIN_PARSER_H_

#include "../../common/parser.h"
#include "../../common/utils.h"

class MazeParser : public CommonParser {
 public:
  MazeParser(const string& filename) : filename(filename){};
  bool readWalls(ifstream& file, Matrix& walls, int rows, int cols);
  bool readMaze();
  void drawMaze();

  // геттеры для класса MazeSolver
  Matrix getVerticalWalls() { return verticalWalls; }
  Matrix getHorizontalWalls() { return horizontalWalls; }
  int getRows() { return rows; }
  int getCols() { return cols; }
  vector<string> getMazeRepresentation() const;  // для вывода решения в консоль

 private:
  string filename;
  int rows = 0;
  int cols = 0;
  Matrix verticalWalls;
  Matrix horizontalWalls;

  bool validateRowCount(const string& filename, int expectedRows);
  bool validateRowCount(const string& filename, int expectedRows,
                        int& rowsInMatrix1, int& rowsInMatrix2);
  bool validateColumnCount(ifstream& file, int expectedCols);
};

#endif  // A1_MAZE_CPP_1_SRC_BACKEND_MAZE_MAIN_PARSER_H_
