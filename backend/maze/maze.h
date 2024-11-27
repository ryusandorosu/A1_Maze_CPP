#ifndef A1_MAZE_CPP_1_SRC_BACKEND_MAZE_H_
#define A1_MAZE_CPP_1_SRC_BACKEND_MAZE_H_

#include <queue>
#include <random>
#include <tuple>

#include "../common/parser.h"
#include "../common/utils.h"

class Maze : public CommonParser {
 public:
  /* former main parser class */
  Maze(const string& filename) : filename(filename) {};
  bool readWalls(ifstream& file, Matrix& walls, int rows, int cols);
  bool readMaze();
  void drawMaze();

  // геттеры для класса MazeSolver
  Matrix getVerticalWalls() { return verticalWalls; }
  Matrix getHorizontalWalls() { return horizontalWalls; }
  int getRows() { return rows; }
  int getCols() { return cols; }
  vector<string> getMazeRepresentation() const;  // для вывода решения в консоль

  /* former generator class */
  Maze(int rows, int cols);
  bool checkDimensions();
  void generateMaze();
  void saveMazeToFile(const string& filename) const;

  /* former solver class */
  bool solveMaze(const Coord& start, const Coord& end);
  Matrix getSolutionMatrix() const { return solutionMatrix; }
  void clearSolutionMatrix();

  void printSolutionMatrix() const;
  void drawMazeSolution(const Matrix& solution,
                        vector<string>& mazeRepresentation);

 private:
  /* former main parser class */
  string filename;
  int rows = 0;
  int cols = 0;
  Matrix verticalWalls;
  Matrix horizontalWalls;

  bool validateRowCount(const string& filename, int expectedRows);
  bool validateRowCount(const string& filename, int expectedRows,
                        int& rowsInMatrix1, int& rowsInMatrix2);
  bool validateColumnCount(ifstream& file, int expectedCols);

  /* former generator class */
  static const int MIN_SIZE = 1;
  static const int MAX_SIZE = 50;

  int setID = 0;
  vector<int> currentRow;

  void createUniqueSet();
  bool randomBool();
  void mergeSet(int current, int next);
  void createVerticalWalls(int row);

  bool countIndeticalSet(int value);
  int countCellsWithoutHWalls(int value, int row);
  void createHorizontalWalls(int row);

  void duplicateCurrentLine(int row);
  void lastLineCheck();

  /* former solver class */
  Matrix solutionMatrix;  // здесь храница матрица с координатами пути решения
  void reconstructPath(const CoordMatrix& predecessor, const Coord& start,
                       const Coord& end);
  bool canMove(int x, int y, int nx, int ny) const;
};

#endif  // A1_MAZE_CPP_1_SRC_BACKEND_MAZE_H_
