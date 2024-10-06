#include "utils.h"

// Функция для проверки расширения файла
bool CommonUtils::checkFileExtension(const string& filename,
                                     const string& expectedExtension) {
  size_t dotPos = filename.rfind('.');
  if (dotPos == string::npos || dotPos == filename.length() - 1) {
    cerr << "Файл не имеет расширения или оно некорректно: " << filename
         << endl;
    return false;
  }

  string extension = filename.substr(dotPos + 1);
  if (extension != expectedExtension) {
    cerr << "Неправильное расширение файла. Ожидается ." << expectedExtension
         << endl;
    return false;
  }

  return true;
}

// Функция для проверки открытия файла
bool CommonUtils::checkFileOpen(ifstream& file, const string& filename) {
  if (!file.is_open()) {
    cerr << "Не удалось открыть файл: " << filename << endl;
    return false;
  }
  // Проверка расширения файла
  if (!checkFileExtension(filename, "txt")) {
    return false;
  }
  return true;
}

// Функция для чтения размеров поля из файла
bool CommonUtils::readDimensions(ifstream& file, int& rows, int& cols) {
  file >> rows >> cols;
  if (rows <= 0 || cols <= 0) {
    cerr << "Некорректные размеры поля: " << rows << "x" << cols << endl;
    return false;
  }
  return true;
}
