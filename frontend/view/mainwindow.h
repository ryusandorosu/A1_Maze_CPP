#ifndef A1_MAZE_CPP_2_SRC_FRONTEND_VIEW_MAINWINDOW_H_
#define A1_MAZE_CPP_2_SRC_FRONTEND_VIEW_MAINWINDOW_H_

#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

#include "../../backend/include.h"
#include "../functions/cavewidget.h"
#include "../functions/mazewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow* ui;
  QString filePath_;
  Maze* mazeObj_;
  MazeWidget* mazeWidget_ = nullptr;
  int rowsParserMaze_ = 10;
  int colsParserMaze_ = 10;

  void spinBoxesConnect();
  void solve_console_draw(const Coord& start, const Coord& end);

 private slots:
  void on_spinBox_x_textChanged(const QString& arg1);
  void on_spinBox_y_textChanged(const QString& arg1);

  void on_pushbutton_open_maze_clicked();
  void on_pushbutton_open_cave_clicked();

  void on_pushbutton_generate_clicked();
  void on_pushbutton_save_maze_clicked();
  void on_pushbutton_solve_clicked();
};

#endif  // A1_MAZE_CPP_2_SRC_FRONTEND_VIEW_MAINWINDOW_H_
