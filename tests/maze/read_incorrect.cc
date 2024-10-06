#include "../unit_tests.h"

TEST(MAZE_READ_INCORRECT, not_existing_file) {
  MazeParser mazeParser("void");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_extension) {
  MazeParser mazeParser("files/images/maze_00_4x4.jpg");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, no_extension) {
  MazeParser mazeParser("files/incorrect/maze_read/maze_00_4x4");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, cave) {
  MazeParser mazeParser("files/cave_00_4x4.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, extra_column) {
  MazeParser mazeParser("files/incorrect/maze_read/extra_column.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, absent_column) {
  MazeParser mazeParser("files/incorrect/maze_read/absent_column.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

// TEST(MAZE_READ_INCORRECT, wrong_element_number) {
//   MazeParser
//   mazeParser("files/incorrect/maze_read/wrong_element_number.txt");
//   EXPECT_EQ(mazeParser.readMaze(), false);
// }

TEST(MAZE_READ_INCORRECT, wrong_element_letter) {
  MazeParser mazeParser("files/incorrect/maze_read/wrong_element_letter.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_dimension_row) {
  MazeParser mazeParser("files/incorrect/maze_read/wrong_dimension_row.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_dimension_col) {
  MazeParser mazeParser("files/incorrect/maze_read/wrong_dimension_col.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_dimensions) {
  MazeParser mazeParser("files/incorrect/maze_read/wrong_dimensions.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_dimensions_count) {
  MazeParser mazeParser("files/incorrect/maze_read/wrong_dimensions_count.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, no_space_column) {
  MazeParser mazeParser("files/incorrect/maze_read/no_space_column.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, extra_endline) {
  MazeParser mazeParser("files/incorrect/maze_read/extra_endline.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, empty_matrix_vertical) {
  MazeParser mazeParser("files/incorrect/maze_read/empty_matrix_vertical.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, maze_empty_matrix_horizontal) {
  MazeParser mazeParser(
      "files/incorrect/maze_read/empty_matrix_horizontal.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, maze_empty_matrix_both) {
  MazeParser mazeParser("files/incorrect/maze_read/empty_matrix_both.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, no_dimensions) {
  MazeParser mazeParser("files/incorrect/maze_read/no_dimensions.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, cave_51x51_correct) {
  MazeParser mazeParser("files/incorrect/maze_read/51x51_correct.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, cave_51x51_just_dimensions) {
  MazeParser mazeParser("files/incorrect/maze_read/51x51_just_dimensions.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}
