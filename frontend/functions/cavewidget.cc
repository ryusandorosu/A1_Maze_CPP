#include "cavewidget.h"

#include <QPainter>
#include <algorithm>

CaveWidget::CaveWidget(QWidget* parent) : QWidget(parent), field_{} {}

// Установка поля пещеры и обновление виджета
void CaveWidget::setCave(const std::vector<std::vector<int>>& field) {
  field_ = field;
  update();
}

// Отрисовка пещеры
void CaveWidget::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  // Получаем размеры виджета
  int widgetWidth = this->width();
  int widgetHeight = this->height();

  // Размеры пещеры
  if (field_.empty() || field_.front().empty()) return;

  int caveWidth = field_.front().size();  // Количество столбцов
  int caveHeight = field_.size();         // Количество строк

  // Вычисляем размер ячейки
  int cellWidth = widgetWidth / caveWidth;
  int cellHeight = widgetHeight / caveHeight;

  // Используем минимальный размер ячейки для сохранения пропорций
  int cellSize = std::min(cellWidth, cellHeight);

  // Рисуем пещеру
  for (int y = 0; y < caveHeight; ++y) {
    for (int x = 0; x < caveWidth; ++x) {
      QRect rect(x * cellSize, y * cellSize, cellSize, cellSize);
      if (field_[y][x] == 0) {
        painter.fillRect(rect, Qt::lightGray);  // Препятствие
      } else if (field_[y][x] == 1) {
        painter.fillRect(rect, Qt::darkGray);  // Свободное пространство
      } else {
        painter.fillRect(rect, Qt::red);  // Ошибка
      }
    }
  }
}
