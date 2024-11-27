#include "../maze.h"

// Функция для отрисовки лабиринта на консоли
void Maze::drawMaze() {
  int rows = horizontalWalls.size();
  int cols = verticalWalls[0].size();

  // Отрисовка верхней границы
  for (int j = 0; j < cols; ++j) {
    cout << "+";
    cout << "---";
  }
  cout << "+" << endl;

  for (int i = 0; i < rows; ++i) {
    cout << "|";  // Отрисовка строки с левой границей и ячейками
    for (int j = 0; j < cols; ++j) {
      cout << "   ";  // Печать пустого пространства для ячейки
      // Отрисовка вертикальной стены справа от ячейки, если это не последняя
      // колонка
      if (j < cols - 1 && verticalWalls[i][j] == 1) {
        cout << "|";
      } else if (verticalWalls[i][j] == 0) {
        cout << " ";
      }
    }
    cout << "|" << endl;  // Отрисовка строки с правой границей

    // Отрисовка горизонтальных стен под ячейкой
    cout << "+";
    for (int j = 0; j < cols; ++j) {
      if (horizontalWalls[i][j] == 1) {
        cout << "---";
      } else if (horizontalWalls[i][j] == 0) {
        cout << "   ";
      }
      cout << "+";
    }
    cout << endl;
  }
}
