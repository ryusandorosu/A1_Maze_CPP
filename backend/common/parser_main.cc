#include "parser.h"

CommonParser::FileType CommonParser::determineFileType(const string& filename,
                                                       int expectedRows) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Не удалось открыть файл: " << filename << endl;
    return FileType::UNKNOWN;
  }

  string line;
  int count = 0;

  // Пропускаем первую строку с размерами
  getline(file, line);

  // Подсчет строк в файле, кроме первой
  while (getline(file, line)) {
    count++;
  }

  file.close();

  if (count == expectedRows) {
    return FileType::CAVE;
  } else if (count == expectedRows * 2 + 1) {
    return FileType::MAZE;
  } else {
    cerr << "Некорректное количество строк в файле или неверная размерность "
            "строк."
         << endl;
    return FileType::UNKNOWN;
  }
}

// Функция для проверки и считывания данных поля
bool CommonParser::readFieldData(ifstream& file, Matrix& field, int fileRows,
                                 int fileCols) {
  field.resize(fileRows, vector<int>(fileCols));

  for (int i = 0; i < fileRows; ++i) {
    for (int j = 0; j < fileCols; ++j) {
      if (!(file >> field[i][j])) {
        cerr << "Ошибка чтения данных поля." << endl;
        return false;
      }
    }
  }

  return true;
}

// Функция для чтения размеров и данных из файла
bool CommonParser::readFile(const string& filename, Matrix& field, int& rows,
                            int& cols) {
  ifstream file(filename);
  if (!CommonUtils::checkFileOpen(file, filename)) {
    return false;
  }

  int fileRows, fileCols;

  // Чтение размеров
  if (!CommonUtils::readDimensions(file, fileRows, fileCols)) {
    return false;
  }

  // Проверка на максимальные размеры
  if (fileRows > MAX_SIZE || fileCols > MAX_SIZE) {
    cerr << "Размеры поля превышают максимально допустимые (" << MAX_SIZE << "x"
         << MAX_SIZE << "): " << fileRows << "x" << fileCols << endl;
    return false;
  }

  // Определение типа файла для правильного подсчёта количества строк
  FileType fileType = determineFileType(filename, fileRows);
  if (fileType == FileType::UNKNOWN) {
    return false;
  } else if (fileType == FileType::CAVE) {
    if (!validateRowCount(filename, fileRows)) {
      return false;
    }
  } else if (fileType == FileType::MAZE) {
    int rowsInMatrix1 = 0;
    int rowsInMatrix2 = 0;
    if (!validateRowCount(filename, fileRows, rowsInMatrix1, rowsInMatrix2)) {
      return false;
    }
  }

  // Сбросим указатель на начало файла для повторного чтения
  file.clear();
  file.seekg(0);

  // Чтение размеров снова
  if (!CommonUtils::readDimensions(file, fileRows, fileCols)) {
    return false;
  }

  // Считывание данных поля, если размеры корректны
  if (!readFieldData(file, field, fileRows, fileCols)) {
    return false;
  }

  // Проверка на соответствие количества столбцов
  if (!validateColumnCount(file, fileCols)) {
    return false;
  }

  rows = fileRows;
  cols = fileCols;

  file.close();
  return true;
}

// нужен из-за особенности создания файлов в windows, line.empty() не
// воспринимается как пустая строка из-за наличия символа переноса строки
bool CommonParser::isBlankLine(const string& line) {
  return line.find_first_not_of(" \t\r") == string::npos;
}
//используется в мейзе
