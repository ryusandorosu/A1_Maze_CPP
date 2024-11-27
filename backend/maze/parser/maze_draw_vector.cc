#include "../maze.h"

/* для вывода решения в консоль, не отрисовываются правые стенки */
vector<string> Maze::getMazeRepresentation() const {
  int rows = horizontalWalls.size();
  int cols = verticalWalls[0].size();
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
      } else if (verticalWalls[i][j] == 0) {
        line += " ";
      }
    }
    line += "|";
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
