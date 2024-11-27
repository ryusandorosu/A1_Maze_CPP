#ifndef A1_MAZE_CPP_2_SRC_FRONTEND_MAZEWIDGET_H_
#define A1_MAZE_CPP_2_SRC_FRONTEND_MAZEWIDGET_H_

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QWidget>
#include <vector>

#include "../backend/maze/maze.h"

class MazeWidget : public QWidget {
  Q_OBJECT

 public:
  explicit MazeWidget(QWidget* parent = nullptr);
  void setMaze(const Matrix& horizontalWalls, const Matrix& verticalWalls);
  void setSolution(const Matrix& solutionPath);

 protected:
  void paintEvent(QPaintEvent* event) override;

 private:
  Matrix horizontalWalls;
  Matrix verticalWalls;
  Matrix solutionPath;
};

#endif  // A1_MAZE_CPP_2_SRC_FRONTEND_MAZEWIDGET_H_
