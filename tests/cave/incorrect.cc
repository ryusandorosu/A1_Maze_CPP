#include "../unit_tests.h"

TEST(CAVE_READ_INCORRECT, not_existing_file) {
  CaveParser caveParser("void");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, no_file_specified) {
  CaveParser caveParser("");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, wrong_extension) {
  CaveParser caveParser("files/images/cave_00_4x4.jpg");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, no_extension) {
  CaveParser caveParser("files/incorrect/cave/cave_00_4x4");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, maze) {
  CaveParser caveParser("files/maze_00_4x4.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, extra_column) {
  CaveParser caveParser("files/incorrect/cave/extra_column.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, absent_column) {
  CaveParser caveParser("files/incorrect/cave/absent_column.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, wrong_element_number) {
  CaveParser caveParser("files/incorrect/cave/wrong_element_number.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, wrong_element_letter) {
  CaveParser caveParser("files/incorrect/cave/wrong_element_letter.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, wrong_dimension_row) {
  CaveParser caveParser("files/incorrect/cave/wrong_dimension_row.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, wrong_dimension_col) {
  CaveParser caveParser("files/incorrect/cave/wrong_dimension_col.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, wrong_dimensions) {
  CaveParser caveParser("files/incorrect/cave/wrong_dimensions.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, wrong_dimensions_count) {
  CaveParser caveParser("files/incorrect/cave/wrong_dimensions_count.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, no_space_column) {
  CaveParser caveParser("files/incorrect/cave/no_space_column.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, extra_endline) {
  CaveParser caveParser("files/incorrect/cave/extra_endline.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, empty_matrix) {
  CaveParser caveParser("files/incorrect/cave/empty_matrix.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, no_dimensions) {
  CaveParser caveParser("files/incorrect/cave/no_dimensions.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, cave_51x51_correct) {
  CaveParser caveParser("files/incorrect/cave/51x51_correct.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}

TEST(CAVE_READ_INCORRECT, cave_51x51_just_dimensions) {
  CaveParser caveParser("files/incorrect/cave/51x51_just_dimensions.txt");
  EXPECT_EQ(caveParser.readCave(), false);
}
