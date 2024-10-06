#include "cave_parser.h"

// Функция для подсчета строк в файле
bool CaveParser::validateRowCount(const string& filename, int expectedRows) {
  ifstream file(filename);
  if (!CommonUtils::checkFileOpen(file, filename)) {
    return 0;
  }

  int count = 0;
  string line;
  while (getline(file, line)) {
    ++count;
  }
  file.close();

  int actualCount = count - 1;
  if (actualCount != expectedRows) {
    // -1 для первой строки с размерами
    cerr << "Количество строк (" << actualCount
         << ") не совпадает с указанным размером: " << expectedRows << endl;
    return false;
  }

  return true;
}

// метод-пустышка чтобы не было ошибок при компиляции
bool CaveParser::validateRowCount(const string& filename, int expectedRows,
                                  int& rowsInMatrix1, int& rowsInMatrix2) {
  rowsInMatrix1 = 0;
  rowsInMatrix2 = 0;
  return validateRowCount(filename, expectedRows);
}

bool CaveParser::validateColumnCount(ifstream& file, int expectedCols) {
  string line;
  while (getline(file, line)) {
    istringstream iss(line);
    int count = 0;
    int value;

    while (iss >> value) {
      ++count;
    }

    if (count != 0) {
      cerr << "Количество столбцов (" << count + expectedCols
           << ") в строке не совпадает с указанным размером: " << expectedCols
           << endl;
      return false;
    }
  }

  return true;
}
