#include "unit_tests.h"

bool compareMatrices(const Matrix& matrix1, const Matrix& matrix2) {
  if (matrix1.size() != matrix2.size()) return false;
  for (size_t i = 0; i < matrix1.size(); ++i) {
    if (matrix1[i] != matrix2[i]) return false;
  }
  return true;
}

bool checkNoIsolatedAreas(const Maze& generator) {
  string filename = "isolation_areas_check.txt";
  generator.saveMazeToFile(filename);

  Maze parser(filename);
  if (!parser.readMaze()) {
    return false;
  }

  int rows = parser.getRows();
  int cols = parser.getCols();

  // Проверка для каждой клетки
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      for (int ni = 0; ni < rows; ++ni) {
        for (int nj = 0; nj < cols; ++nj) {
          if (!parser.solveMaze({i, j}, {ni, nj})) {
            cerr << "error at: start point {" << i << ", " << j
                 << "}, end point {" << ni << ", " << nj << "}" << endl;
            return false;  // Есть изолированные области
          }
        }
      }
    }
  }

  return true;  // Все клетки достижимы
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
