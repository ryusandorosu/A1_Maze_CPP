#include "class_solver.h"

// Метод для вывода матрицы лабиринта с решением
void MazeSolver::printSolutionMatrix() const {
  for (const auto& row : solutionMatrix) {
    for (int cell : row) {
      cout << (cell == 1 ? '1' : '0');
    }
    cout << endl;
  }
}

void MazeSolver::drawMazeSolution(const Matrix& solution,
                                  vector<string>& mazeRepresentation) {
  // Проходим по всем ячейкам решения
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (solution[i][j] == 1) {
        // Находим координаты для вставки символа пути 'o' в представление
        // лабиринта
        int rowInRepresentation = 2 * i + 1;
        int colInRepresentation = 4 * j + 2;

        // Заменяем символ на 'o'
        mazeRepresentation[rowInRepresentation][colInRepresentation] = 'o';
      }
    }
  }

  // Выводим модифицированное представление лабиринта
  for (const auto& line : mazeRepresentation) {
    cout << line << endl;
  }
}
