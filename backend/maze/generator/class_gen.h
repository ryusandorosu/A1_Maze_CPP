#ifndef A1_MAZE_CPP_1_SRC_BACKEND_MAZE_GENERATOR_CLASS_H_
#define A1_MAZE_CPP_1_SRC_BACKEND_MAZE_GENERATOR_CLASS_H_

#include <random>

#include "../../common/includes.h"

class MazeGenerator {
 public:
  MazeGenerator(int rows, int cols);
  bool checkDimensions();
  void generateMaze();
  void saveMazeToFile(const string& filename) const;

 private:
  static const int MIN_SIZE = 1;
  static const int MAX_SIZE = 50;

  int rows = 0;
  int cols = 0;
  int setID = 0;
  Matrix verticalWalls;
  Matrix horizontalWalls;
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
};

#endif  // A1_MAZE_CPP_1_SRC_BACKEND_MAZE_GENERATOR_CLASS_H_
