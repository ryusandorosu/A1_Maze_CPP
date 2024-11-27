#ifndef A1_MAZE_CPP_2_SRC_FRONTEND_FILESELECTOR_H_
#define A1_MAZE_CPP_2_SRC_FRONTEND_FILESELECTOR_H_

#include <QApplication>
#include <QFileDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class FileSelector : public QWidget {
  Q_OBJECT

 public:
  explicit FileSelector(QWidget *parent = nullptr);

 private slots:
  void selectFile();

 private:
  QLabel *filePathLabel;
  QString selectedFilePath;
};

#endif  // A1_MAZE_CPP_2_SRC_FRONTEND_FILESELECTOR_H_
