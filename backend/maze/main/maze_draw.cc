#include "maze_parser.h"

// Функция для отрисовки лабиринта на консоли
void MazeParser::drawMaze() {
  int rows = horizontalWalls.size();
  int cols = verticalWalls.size();

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

      if (verticalWalls[i][j] != 0 && verticalWalls[i][j] != 1) {
        cerr << "Неизвестное значение в поле: " << verticalWalls[i][j] << endl;
        return;
      }

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

/* для вывода решения в консоль, не отрисовываются правые стенки */
vector<string> MazeParser::getMazeRepresentation() const {
  int rows = horizontalWalls.size();
  int cols = verticalWalls.size();
  vector<string> mazeRep;

  // Отрисовка верхней границы
  string topBorder;
  for (int j = 0; j < cols; ++j) {
    topBorder += "+---";
  }
  topBorder += "+";
  mazeRep.push_back(topBorder);  // Добавляем верхнюю границу в вектор

  for (int i = 0; i < rows; ++i) {
    string line = "|";  // Начинаем строку с левой границей
    for (int j = 0; j < cols; ++j) {
      line += "   ";  // Добавляем пустое пространство для ячейки

      // Отрисовка вертикальной стены справа от ячейки, если это не последняя
      // колонка
      if (j < cols - 1 && verticalWalls[i][j] == 1) {
        line += "|";
      } else {
        line += " ";  // Если стены нет, просто пробел
      }
    }
    mazeRep.push_back(line);  // Добавляем строку с ячейками в вектор

    // Отрисовка горизонтальных стен под ячейкой
    string horizontalWall = "+";
    for (int j = 0; j < cols; ++j) {
      if (horizontalWalls[i][j] == 1) {
        horizontalWall += "---";
      } else {
        horizontalWall += "   ";
      }
      horizontalWall += "+";
    }
    mazeRep.push_back(
        horizontalWall);  // Добавляем строку с горизонтальными стенами
  }

  return mazeRep;  // Возвращаем вектор строк
}
