#include "../unit_tests.h"

TEST(MAZE_READ_CORRECT, maze_00_4x4) {
  MazeParser mazeParser("files/maze_00_4x4.txt");
  EXPECT_EQ(mazeParser.readMaze(), true);
  if (mazeParser.readMaze()) {
    ostringstream output;
    streambuf* coutBuffer = cout.rdbuf(output.rdbuf());
    mazeParser.drawMaze();
    cout.rdbuf(coutBuffer);
    string expectedOutput =
        "+---+---+---+---+\n"
        "|               |\n"
        "+---+   +---+   +\n"
        "|   |       |   |\n"
        "+   +   +---+   +\n"
        "|       |       |\n"
        "+---+---+   +---+\n"
        "|               |\n"
        "+---+---+---+---+\n";
    EXPECT_EQ(output.str(), expectedOutput);
  }
}

TEST(MAZE_READ_CORRECT, maze_01_10x10) {
  MazeParser mazeParser("files/maze_01_10x10.txt");
  EXPECT_EQ(mazeParser.readMaze(), true);
  if (mazeParser.readMaze()) {
    ostringstream output;
    streambuf* coutBuffer = cout.rdbuf(output.rdbuf());
    mazeParser.drawMaze();
    cout.rdbuf(coutBuffer);
    string expectedOutput =
        "+---+---+---+---+---+---+---+---+---+---+\n"
        "|           |                   |       |\n"
        "+   +---+   +   +   +---+---+---+   +   +\n"
        "|       |   |   |               |   |   |\n"
        "+---+---+   +   +---+---+---+   +   +   +\n"
        "|   |       |           |   |   |   |   |\n"
        "+   +   +---+---+---+   +   +   +   +   +\n"
        "|   |           |           |       |   |\n"
        "+   +---+---+   +   +---+   +   +---+   +\n"
        "|           |       |       |       |   |\n"
        "+---+   +---+---+---+   +---+---+---+   +\n"
        "|   |                   |   |       |   |\n"
        "+   +---+---+---+   +---+   +   +   +   +\n"
        "|               |   |           |       |\n"
        "+---+---+   +---+   +   +---+   +---+---+\n"
        "|                   |       |   |       |\n"
        "+   +---+---+---+---+   +   +   +---+   +\n"
        "|   |               |   |   |           |\n"
        "+---+   +---+   +   +   +   +---+---+---+\n"
        "|       |       |       |               |\n"
        "+---+---+---+---+---+---+---+---+---+---+\n";
    EXPECT_EQ(output.str(), expectedOutput);
  }
}

TEST(MAZE_READ_CORRECT, maze_02_10x10) {
  MazeParser mazeParser("files/maze_02_10x10.txt");
  EXPECT_EQ(mazeParser.readMaze(), true);
  if (mazeParser.readMaze()) {
    ostringstream output;
    streambuf* coutBuffer = cout.rdbuf(output.rdbuf());
    mazeParser.drawMaze();
    cout.rdbuf(coutBuffer);
    string expectedOutput =
        "+---+---+---+---+---+---+---+---+---+---+\n"
        "|   |   |                   |           |\n"
        "+   +   +   +---+   +---+   +   +---+   +\n"
        "|       |       |   |   |   |   |   |   |\n"
        "+   +---+---+   +   +   +   +   +   +   +\n"
        "|   |           |       |   |       |   |\n"
        "+   +   +   +---+---+---+   +---+   +   +\n"
        "|   |   |   |               |   |       |\n"
        "+   +   +---+---+---+---+   +   +   +   +\n"
        "|       |       |           |       |   |\n"
        "+   +   +   +---+   +---+---+   +   +   +\n"
        "|   |       |       |           |   |   |\n"
        "+   +---+---+   +---+   +---+---+---+   +\n"
        "|   |       |   |   |           |       |\n"
        "+---+---+   +   +   +---+---+   +   +---+\n"
        "|                       |       |   |   |\n"
        "+   +---+---+---+---+   +---+   +   +   +\n"
        "|   |   |           |           |       |\n"
        "+   +   +---+---+   +---+---+---+---+   +\n"
        "|               |                       |\n"
        "+---+---+---+---+---+---+---+---+---+---+\n";
    EXPECT_EQ(output.str(), expectedOutput);
  }
}

TEST(MAZE_READ_CORRECT, maze_03_20x20) {
  MazeParser mazeParser("files/maze_03_20x20.txt");
  EXPECT_EQ(mazeParser.readMaze(), true);
  if (mazeParser.readMaze()) {
    ostringstream output;
    streambuf* coutBuffer = cout.rdbuf(output.rdbuf());
    mazeParser.drawMaze();
    cout.rdbuf(coutBuffer);
    string expectedOutput =
        "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+-"
        "--+---+---+\n"
        "|                   |       |           |                             "
        "          |\n"
        "+   +---+---+---+   +   +   +   +---+   +   +---+---+---+---+---+---+ "
        "  +---+   +\n"
        "|               |   |   |       |           |   |           |       | "
        "  |       |\n"
        "+---+---+---+   +   +---+---+---+   +---+---+   +   +---+   +   +   + "
        "  +   +   +\n"
        "|   |           |                           |   |       |       |   | "
        "  |   |   |\n"
        "+   +   +---+---+---+---+---+---+---+---+   +   +---+   +---+---+   + "
        "  +   +   +\n"
        "|   |   |                           |       |       |       |       | "
        "  |   |   |\n"
        "+   +   +---+---+---+---+---+---+   +   +---+---+   +---+   +   +---+ "
        "  +   +   +\n"
        "|   |   |                           |   |                   |         "
        "  |   |   |\n"
        "+   +   +   +---+---+---+---+---+   +   "
        "+---+---+---+---+---+---+---+---+---+   +\n"
        "|       |       |                   |   |                             "
        "          |\n"
        "+---+   +---+   +---+---+---+---+---+   +   "
        "+---+---+---+---+---+---+---+---+---+\n"
        "|   |           |                       |           |                 "
        "          |\n"
        "+   +---+---+---+   +---+---+---+---+---+---+---+---+   "
        "+---+---+---+---+---+   +\n"
        "|               |       |       |                   |   |             "
        "          |\n"
        "+   +---+---+   +   +   +   +   +   +---+---+---+   +   +   "
        "+---+---+---+---+---+\n"
        "|   |       |   |   |   |   |   |   |               |   |   |   |     "
        "          |\n"
        "+   +   +   +   +   +   +   +   +   +   +---+   +---+   +   +   +   "
        "+---+---+---+\n"
        "|   |   |       |   |   |   |       |   |           |   |   |         "
        "          |\n"
        "+   +---+---+   +   +   +   +---+---+   +   +---+---+   +   "
        "+---+---+---+---+   +\n"
        "|           |       |       |           |           |   |       |     "
        "  |       |\n"
        "+---+---+   +---+   +   +---+   +---+---+---+---+   +   +   +   +   + "
        "  +---+   +\n"
        "|           |       |   |       |               |   |   |   |   |   | "
        "      |   |\n"
        "+---+---+---+---+---+   +---+---+---+---+   +   +   +   +   +   "
        "+---+---+   +   +\n"
        "|                                       |   |       |   |   |         "
        "      |   |\n"
        "+   +---+---+---+---+---+---+---+   +   +---+---+   +   +   "
        "+---+---+---+---+   +\n"
        "|   |       |                   |   |   |           |   |             "
        "          |\n"
        "+   +   +   +   +---+---+---+---+   +   +   +---+---+   "
        "+---+---+---+---+---+---+\n"
        "|   |   |   |                   |   |   |           |   |       |     "
        "  |       |\n"
        "+   +   +   +---+---+---+---+   +   +   +---+---+   +   +   +   +   + "
        "  +   +   +\n"
        "|   |   |                   |   |   |   |           |   |   |       | "
        "      |   |\n"
        "+   +   +   +---+---+---+   +   +   +   +   +---+---+   +   "
        "+---+---+---+---+---+\n"
        "|   |   |   |           |   |   |   |   |           |   |             "
        "          |\n"
        "+   +   +   +   +---+   +   +   +   +   +---+---+   +   "
        "+---+---+---+---+---+   +\n"
        "|   |   |   |       |   |   |   |   |   |           |                 "
        "          |\n"
        "+   +   +   +---+   +   +   +   +   +   "
        "+---+---+---+---+---+---+---+---+---+   +\n"
        "|   |   |   |       |       |   |   |   |                             "
        "          |\n"
        "+   +   +   +---+---+---+---+   +   +---+   "
        "+---+---+---+---+---+---+---+---+   +\n"
        "|       |                       |           |                         "
        "          |\n"
        "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+-"
        "--+---+---+\n";
    EXPECT_EQ(output.str(), expectedOutput);
  }
}

TEST(MAZE_READ_CORRECT, representation_coverage) {
  MazeParser mazeParser("files/maze_00_4x4.txt");
  vector<string> maze = mazeParser.getMazeRepresentation();
  EXPECT_EQ(maze.empty(), false);
}
