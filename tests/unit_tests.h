#ifndef A1_MAZE_CPP_1_SRC_TESTS_UNIT_TESTS_H_
#define A1_MAZE_CPP_1_SRC_TESTS_UNIT_TESTS_H_

#include <gtest/gtest.h>

#include "../backend/include.h"

extern bool compareMatrices(const Matrix& matrix1, const Matrix& matrix2);
extern bool checkNoIsolatedAreas(const Maze& generator);

#endif  // A1_MAZE_CPP_1_SRC_TESTS_UNIT_TESTS_H_
