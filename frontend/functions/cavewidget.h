#ifndef A1_MAZE_CPP_2_SRC_FRONTEND_CAVEWIDGET_H_
#define A1_MAZE_CPP_2_SRC_FRONTEND_CAVEWIDGET_H_

#include <QPainter>
#include <QWidget>
#include <vector>

class CaveWidget : public QWidget {
  Q_OBJECT

 public:
  explicit CaveWidget(QWidget* parent = nullptr);
  void setCave(const std::vector<std::vector<int>>& field);

 protected:
  void paintEvent(QPaintEvent* event) override;

 private:
  std::vector<std::vector<int>> field_;
};

#endif  // A1_MAZE_CPP_2_SRC_FRONTEND_CAVEWIDGET_H_
