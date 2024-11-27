#include "../unit_tests.h"

TEST(MAZE_READ_INCORRECT, not_existing_file) {
  Maze mazeParser("void");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, no_file_specified) {
  Maze mazeParser("");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_extension) {
  Maze mazeParser("files/images/maze_00_4x4.jpg");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, no_extension) {
  Maze mazeParser("files/incorrect/maze_read/maze_00_4x4");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, cave) {
  Maze mazeParser("files/cave_00_4x4.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, extra_column) {
  Maze mazeParser("files/incorrect/maze_read/extra_column.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, absent_column) {
  Maze mazeParser("files/incorrect/maze_read/absent_column.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_element_number_vertical) {
  Maze mazeParser(
      "files/incorrect/maze_read/wrong_element_number_vertical.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_element_number_horizontal) {
  Maze mazeParser(
      "files/incorrect/maze_read/wrong_element_number_horizontal.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_element_letter) {
  Maze mazeParser("files/incorrect/maze_read/wrong_element_letter.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_dimension_row) {
  Maze mazeParser("files/incorrect/maze_read/wrong_dimension_row.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_dimension_col) {
  Maze mazeParser("files/incorrect/maze_read/wrong_dimension_col.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_dimensions) {
  Maze mazeParser("files/incorrect/maze_read/wrong_dimensions.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, wrong_dimensions_count) {
  Maze mazeParser("files/incorrect/maze_read/wrong_dimensions_count.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, no_space_column) {
  Maze mazeParser("files/incorrect/maze_read/no_space_column.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, extra_endline) {
  Maze mazeParser("files/incorrect/maze_read/extra_endline.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, empty_matrix_vertical) {
  Maze mazeParser("files/incorrect/maze_read/empty_matrix_vertical.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, maze_empty_matrix_horizontal) {
  Maze mazeParser("files/incorrect/maze_read/empty_matrix_horizontal.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, maze_empty_matrix_both) {
  Maze mazeParser("files/incorrect/maze_read/empty_matrix_both.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, no_dimensions) {
  Maze mazeParser("files/incorrect/maze_read/no_dimensions.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, cave_51x51_correct) {
  Maze mazeParser("files/incorrect/maze_read/51x51_correct.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}

TEST(MAZE_READ_INCORRECT, cave_51x51_just_dimensions) {
  Maze mazeParser("files/incorrect/maze_read/51x51_just_dimensions.txt");
  EXPECT_EQ(mazeParser.readMaze(), false);
}
