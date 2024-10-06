#include "../unit_tests.h"

TEST(MAZE_SOLVE_INCORRECT, out_of_boundaries) {
  MazeParser parser("files/maze_00_4x4.txt");
  EXPECT_EQ(parser.readMaze(), true);

  int rows = parser.getRows();
  int cols = parser.getCols();
  Coord start = {0, 0};
  Coord end = {cols, cols};
  MazeSolver solver(parser.getVerticalWalls(), parser.getHorizontalWalls(),
                    rows, cols);
  EXPECT_EQ(solver.solveMaze(start, end), false);
}

TEST(MAZE_SOLVE_INCORRECT, console_output) {
  MazeParser parser("files/maze_00_4x4.txt");
  EXPECT_EQ(parser.readMaze(), true);

  if (parser.readMaze()) {
    int rows = parser.getRows();
    int cols = parser.getCols();
    Coord start = {0, 0};
    Coord end = {cols - 1, cols - 1};
    vector<string> maze = parser.getMazeRepresentation();
    MazeSolver solver(parser.getVerticalWalls(), parser.getHorizontalWalls(),
                      rows, cols);
    EXPECT_EQ(solver.solveMaze(start, end), true);

    ostringstream output;
    streambuf* coutBuffer = cout.rdbuf(output.rdbuf());
    solver.drawMazeSolution(solver.getSolutionMatrix(), maze);
    cout.rdbuf(coutBuffer);
    string expectedOutput =
        "+---+---+---+---+\n"
        "| o   o   o   o |\n"
        "+---+   +---+   +\n"
        "|   |       | o |\n"
        "+   +   +---+   +\n"
        "|       | o   o |\n"
        "+---+---+   +---+\n"
        "|         o   o |\n"
        "+---+---+---+---+\n";
    EXPECT_TRUE(output.str() != expectedOutput);
  }
}