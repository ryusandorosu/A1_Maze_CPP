#include "../unit_tests.h"

TEST(MAZE_SOLVE_CORRECT, maze_00_4x4) {
  MazeParser parser("files/maze_00_4x4.txt");
  EXPECT_EQ(parser.readMaze(), true);

  int rows = parser.getRows();
  int cols = parser.getCols();
  Coord start = {0, 0};
  Coord end = {cols - 1, cols - 1};
  MazeSolver solver(parser.getVerticalWalls(), parser.getHorizontalWalls(),
                    rows, cols);
  EXPECT_EQ(solver.solveMaze(start, end), true);

  Matrix solution;
  if (solver.solveMaze(start, end)) {
    solution = solver.getSolutionMatrix();
  }
  Matrix expectation = {{1, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 1, 1}, {0, 0, 1, 1}};
  EXPECT_EQ(compareMatrices(solution, expectation), true);
}

TEST(MAZE_SOLVE_CORRECT, maze_01_10x10) {
  MazeParser parser("files/maze_01_10x10.txt");
  EXPECT_EQ(parser.readMaze(), true);

  int rows = parser.getRows();
  int cols = parser.getCols();
  Coord start = {0, 0};
  Coord end = {cols - 1, cols - 1};
  MazeSolver solver(parser.getVerticalWalls(), parser.getHorizontalWalls(),
                    rows, cols);
  EXPECT_EQ(solver.solveMaze(start, end), true);

  Matrix solution;
  if (solver.solveMaze(start, end)) {
    solution = solver.getSolutionMatrix();
  }
  Matrix expectation = {
      {1, 1, 1, 1, 1, 0, 0, 0, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 0, 1, 1, 1},
      {0, 0, 0, 1, 1, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 1, 1, 1}};
  EXPECT_EQ(compareMatrices(solution, expectation), true);
}

TEST(MAZE_SOLVE_CORRECT, maze_02_10x10) {
  MazeParser parser("files/maze_02_10x10.txt");
  EXPECT_EQ(parser.readMaze(), true);

  int rows = parser.getRows();
  int cols = parser.getCols();
  Coord start = {0, 0};
  Coord end = {cols - 1, cols - 1};
  MazeSolver solver(parser.getVerticalWalls(), parser.getHorizontalWalls(),
                    rows, cols);
  EXPECT_EQ(solver.solveMaze(start, end), true);

  Matrix solution;
  if (solver.solveMaze(start, end)) {
    solution = solver.getSolutionMatrix();
  }
  Matrix expectation = {
      {1, 0, 1, 1, 1, 1, 1, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 1, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 1, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 1, 0, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
      {0, 0, 0, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 0, 1, 1, 1, 0, 1, 1, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
  EXPECT_EQ(compareMatrices(solution, expectation), true);
}

TEST(MAZE_SOLVE_CORRECT, maze_03_20x20) {
  MazeParser parser("files/maze_03_20x20.txt");
  EXPECT_EQ(parser.readMaze(), true);

  int rows = parser.getRows();
  int cols = parser.getCols();
  Coord start = {0, 0};
  Coord end = {cols - 1, cols - 1};
  MazeSolver solver(parser.getVerticalWalls(), parser.getHorizontalWalls(),
                    rows, cols);
  EXPECT_EQ(solver.solveMaze(start, end), true);

  Matrix solution;
  if (solver.solveMaze(start, end)) {
    solution = solver.getSolutionMatrix();
  }
  Matrix expectation = {
      {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
  EXPECT_EQ(compareMatrices(solution, expectation), true);
}

TEST(MAZE_SOLVE_CORRECT, maze_00_4x4_alternative) {
  MazeParser parser("files/maze_00_4x4.txt");
  EXPECT_EQ(parser.readMaze(), true);

  if (parser.readMaze()) {
    int rows = parser.getRows();
    int cols = parser.getCols();
    Coord start = {0, 0};
    Coord end = {cols - 1, cols - 1};
    MazeSolver solver(parser.getVerticalWalls(), parser.getHorizontalWalls(),
                      rows, cols);
    EXPECT_EQ(solver.solveMaze(start, end), true);

    ostringstream output;
    streambuf* coutBuffer = cout.rdbuf(output.rdbuf());
    solver.printSolutionMatrix();
    cout.rdbuf(coutBuffer);
    string expectedOutput =
        "1111\n"
        "0001\n"
        "0011\n"
        "0011\n";
    EXPECT_EQ(output.str(), expectedOutput);
  }
}