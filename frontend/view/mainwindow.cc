#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  MainWindow::setFixedSize(800, 600);
  ui->setupUi(this);
  setWindowTitle("A1_Maze_CPP");
  spinBoxesConnect();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::spinBoxesConnect() {
  // Устанавливаем начальные значения
  ui->startXspinBox->setMaximum(ui->spinBox_x->value() - 1);
  ui->startYspinBox->setMaximum(ui->spinBox_y->value() - 1);
  ui->endXspinBox->setMaximum(ui->spinBox_x->value() - 1);
  ui->endYspinBox->setMaximum(ui->spinBox_y->value() - 1);
  ui->endXspinBox->setValue(ui->spinBox_x->value() - 1);
  ui->endYspinBox->setValue(ui->spinBox_y->value() - 1);

  // Привязываем максимальные значения и значения по умолчанию
  connect(ui->spinBox_x, QOverload<int>::of(&QSpinBox::valueChanged), this,
          [this](int value) {
            ui->startXspinBox->setMaximum(value - 1);
            ui->endXspinBox->setMaximum(value - 1);
            if (ui->endXspinBox->value() > value - 1) {
              ui->endXspinBox->setValue(value - 1);
            }
          });

  connect(ui->spinBox_y, QOverload<int>::of(&QSpinBox::valueChanged), this,
          [this](int value) {
            ui->startYspinBox->setMaximum(value - 1);
            ui->endYspinBox->setMaximum(value - 1);
            if (ui->endYspinBox->value() > value - 1) {
              ui->endYspinBox->setValue(value - 1);
            }
          });
}

void MainWindow::on_spinBox_x_textChanged(const QString& arg1) {
  rowsParserMaze_ = arg1.toInt();
}

void MainWindow::on_spinBox_y_textChanged(const QString& arg1) {
  colsParserMaze_ = arg1.toInt();
}

void MainWindow::on_pushbutton_open_maze_clicked() {
  filePath_ = QFileDialog::getOpenFileName(this, "Открыть файл", "",
                                           "Text File (*.txt)");
  mazeObj_ = new Maze(filePath_.toStdString());

  if (!mazeObj_->readMaze()) {
    qDebug() << "Failed to read the maze.";
    return;
  }

  ui->spinBox_x->setValue(mazeObj_->getRows());
  ui->spinBox_y->setValue(mazeObj_->getCols());

  mazeWidget_ = new MazeWidget(this);
  mazeWidget_->setMaze(mazeObj_->getHorizontalWalls(),
                       mazeObj_->getVerticalWalls());
  mazeWidget_->show();
}

void MainWindow::on_pushbutton_open_cave_clicked() {
  filePath_ = QFileDialog::getOpenFileName(this, "Открыть файл", "",
                                           "Text File (*.txt)");
  CaveParser caveParser(filePath_.toStdString());

  if (!caveParser.readCave()) {
    qDebug() << "Failed to read the cave.";
    return;
  }

  caveParser.drawField();
  CaveWidget* caveWidget = new CaveWidget(this);
  caveWidget->setCave(caveParser.getField());
  caveWidget->setGeometry(10, 10, 560, 555);

  caveWidget->show();
}

void MainWindow::on_pushbutton_generate_clicked() {
  mazeObj_ = new Maze(rowsParserMaze_, colsParserMaze_);

  if (!mazeObj_->checkDimensions()) {
    return;
  }

  mazeObj_->generateMaze();

  mazeWidget_ = new MazeWidget(this);
  mazeWidget_->setMaze(mazeObj_->getHorizontalWalls(),
                       mazeObj_->getVerticalWalls());
  mazeWidget_->show();
}

void MainWindow::on_pushbutton_save_maze_clicked() {
  QString filePath = QFileDialog::getSaveFileName(this, "Сохранить лабиринт",
                                                  "", "Text File (*.txt)");

  if (!filePath.isEmpty()) {
    mazeObj_->saveMazeToFile(filePath.toStdString());
  } else {
    qDebug() << "Файл не был выбран!";
  }
}

void MainWindow::on_pushbutton_solve_clicked() {
  if (!mazeObj_) {
    return;
  }

  int startX = ui->startXspinBox->value();
  int startY = ui->startYspinBox->value();
  int endX = ui->endXspinBox->value();
  int endY = ui->endYspinBox->value();

  // Получаем размеры лабиринта
  int rows = mazeObj_->getRows();
  int cols = mazeObj_->getCols();

  // Проверка координат на фронте
  if (startX < 0 || startX >= rows || startY < 0 || startY >= cols ||
      endX < 0 || endX >= rows || endY < 0 || endY >= cols) {
    QMessageBox::warning(this, "Ошибка координат",
                         "Координаты вне границ лабиринта!");
    return;
  }

  Coord start = {startX, startY};
  Coord end = {endX, endY};
  solve_console_draw(start, end);

  // Решаем лабиринт
  if (mazeObj_->solveMaze(start, end)) {
    mazeWidget_->setSolution(mazeObj_->getSolutionMatrix());
    mazeWidget_->show();
  } else {
    qDebug() << "Решение не найдено!";
  }
}

void MainWindow::solve_console_draw(const Coord& start, const Coord& end) {
  // консоль
  vector<string> maze = mazeObj_->getMazeRepresentation();

  mazeObj_->clearSolutionMatrix();
  if (mazeObj_->solveMaze(start, end)) {
    mazeObj_->drawMazeSolution(mazeObj_->getSolutionMatrix(), maze);
  } else {
    cout << "Решение не найдено!" << endl;
  }
}
