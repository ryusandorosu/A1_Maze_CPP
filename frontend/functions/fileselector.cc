#include "fileselector.h"

FileSelector::FileSelector(QWidget *parent)
    : QWidget(parent), filePathLabel(new QLabel(this)) {
  QVBoxLayout *layout = new QVBoxLayout(this);

  QPushButton *openFileButton = new QPushButton("Выбрать файл", this);
  connect(openFileButton, &QPushButton::clicked, this,
          &FileSelector::selectFile);

  layout->addWidget(openFileButton);
  layout->addWidget(filePathLabel);
}

void FileSelector::selectFile() {
  QString filePath = QFileDialog::getOpenFileName(
      this, "Открыть файл", "", "Text Files (*.txt);;All Files (*)");
  if (!filePath.isEmpty()) {
    filePathLabel->setText("Путь к файлу: " + filePath);
    selectedFilePath = filePath;
  }
}
