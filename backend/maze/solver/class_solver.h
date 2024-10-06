#ifndef A1_MAZE_CPP_1_SRC_BACKEND_MAZE_SOLVER_CLASS_H_
#define A1_MAZE_CPP_1_SRC_BACKEND_MAZE_SOLVER_CLASS_H_

#include <queue>
#include <tuple>

#include "../../maze/main/maze_parser.h"

class MazeSolver {
 public:
  MazeSolver(const Matrix& verticalWalls, const Matrix& horizontalWalls,
             int rows, int cols);

  bool solveMaze(const Coord& start, const Coord& end);
  Matrix getSolutionMatrix() const { return solutionMatrix; }

  void printSolutionMatrix() const;
  void drawMazeSolution(const Matrix& solution,
                        vector<string>& mazeRepresentation);

 private:
  Matrix verticalWalls;
  Matrix horizontalWalls;
  Matrix solutionMatrix;  // здесь храница матрица с координатами пути решения
  int rows = 0;
  int cols = 0;

  void reconstructPath(const CoordMatrix& predecessor, const Coord& start,
                       const Coord& end);
  bool canMove(int x, int y, int nx, int ny) const;
};

#endif  // A1_MAZE_CPP_1_SRC_BACKEND_MAZE_SOLVER_CLASS_H_
