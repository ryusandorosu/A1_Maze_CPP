#include "mazewidget.h"

MazeWidget::MazeWidget(QWidget* parent)
    : QWidget(parent), horizontalWalls{}, verticalWalls{}, solutionPath{} {}

// Устанавливаем стены лабиринта
void MazeWidget::setMaze(const Matrix& horizontalWalls,
                         const Matrix& verticalWalls) {
  this->horizontalWalls = horizontalWalls;
  this->verticalWalls = verticalWalls;
  update();
}

// Устанавливаем решение лабиринта
void MazeWidget::setSolution(const Matrix& solutionPath) {
  this->solutionPath = solutionPath;
  update();
}

// Отрисовка лабиринта
void MazeWidget::paintEvent(QPaintEvent* event) {
  setGeometry(10, 10, 560, 560);
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  QPen pen;
  pen.setWidth(1);          // Тонкие линии для пути
  pen.setColor(Qt::green);  // Зеленый цвет для пути
  painter.setPen(pen);

  int rows = horizontalWalls.size();
  int cols = verticalWalls[0].size();
  int cellWidth = width() / cols;
  int cellHeight = height() / rows;

  painter.eraseRect(rect());  // Очищаем фон
  // Рисуем путь решения
  if (!solutionPath.empty()) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (solutionPath[i][j] == 1) {  // Если часть пути
          int x = j * cellWidth + cellWidth / 2;
          int y = i * cellHeight + cellHeight / 2;

          // Рисуем соединения с соседними клетками пути
          if (i > 0 && solutionPath[i - 1][j] == 1 &&
              horizontalWalls[i - 1][j] == 0) {
            int neighborY = (i - 1) * cellHeight + cellHeight / 2;
            painter.drawLine(x, y, x, neighborY);
          }
          if (i < rows - 1 && solutionPath[i + 1][j] == 1 &&
              horizontalWalls[i][j] == 0) {
            int neighborY = (i + 1) * cellHeight + cellHeight / 2;
            painter.drawLine(x, y, x, neighborY);
          }
          if (j > 0 && solutionPath[i][j - 1] == 1 &&
              verticalWalls[i][j - 1] == 0) {
            int neighborX = (j - 1) * cellWidth + cellWidth / 2;
            painter.drawLine(x, y, neighborX, y);
          }
          if (j < cols - 1 && solutionPath[i][j + 1] == 1 &&
              verticalWalls[i][j] == 0) {
            int neighborX = (j + 1) * cellWidth + cellWidth / 2;
            painter.drawLine(x, y, neighborX, y);
          }
        }
      }
    }
  }

  // Настройки для стен
  pen.setWidth(2);          // Толстые линии для стен
  pen.setColor(Qt::black);  // Черный цвет для стен
  painter.setPen(pen);

  // Рисуем границы лабиринта
  painter.drawLine(0, 0, width(), 0);   // Верхняя граница
  painter.drawLine(0, 0, 0, height());  // Левая граница

  // Рисуем вертикальные и горизонтальные стены
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (verticalWalls[i][j] == 1) {
        painter.drawLine((j + 1) * cellWidth, i * cellHeight,
                         (j + 1) * cellWidth, (i + 1) * cellHeight);
      }
      if (horizontalWalls[i][j] == 1) {
        painter.drawLine(j * cellWidth, (i + 1) * cellHeight,
                         (j + 1) * cellWidth, (i + 1) * cellHeight);
      }
    }
  }
}
