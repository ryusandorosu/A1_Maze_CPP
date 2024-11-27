#include "../unit_tests.h"

TEST(MAZE_GENERATION, maze_neg4x4) {
  Maze generator(-4, 4);
  EXPECT_EQ(generator.checkDimensions(), false);
}

TEST(MAZE_GENERATION, isolation_areas_check) {
  Maze generator(4, 4);
  EXPECT_EQ(generator.checkDimensions(), true);

  if (generator.checkDimensions()) {
    generator.generateMaze();
  }

  EXPECT_EQ(checkNoIsolatedAreas(generator), true);
}
