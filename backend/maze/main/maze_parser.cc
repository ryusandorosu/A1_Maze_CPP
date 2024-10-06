#include "maze_parser.h"

// Функция для чтения стен
bool MazeParser::readWalls(ifstream& file, Matrix& walls, int rows, int cols) {
  walls.resize(rows, vector<int>(cols));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (!(file >> walls[i][j])) {
        cerr << "Ошибка чтения данных стен." << endl;
        return false;
      }
    }
  }

  return true;
}

// Функция для подсчета строк в файле
bool MazeParser::validateRowCount(const string& filename, int expectedRows,
                                  int& rowsInMatrix1, int& rowsInMatrix2) {
  ifstream file(filename);
  if (!file.is_open()) {
    return false;
  }

  string line;
  bool inMatrix1 = true;

  // Пропускаем первую строку с размерами
  getline(file, line);

  rowsInMatrix1 = 0;
  rowsInMatrix2 = 0;
  while (getline(file, line)) {
    if (isBlankLine(line)) {
      inMatrix1 = false;  // Переход ко второй матрице
      continue;
    }

    if (inMatrix1) {
      rowsInMatrix1++;
    } else {
      rowsInMatrix2++;
    }
  }

  file.close();

  // Проверяем количество строк в каждой матрице
  if (rowsInMatrix1 != expectedRows) {
    cerr << "Количество строк в первой матрице (" << rowsInMatrix1
         << ") не соответствует ожидаемому: " << expectedRows << endl;
    return false;
  }
  if (rowsInMatrix2 != expectedRows) {
    cerr << "Количество строк во второй матрице (" << rowsInMatrix2
         << ") не соответствует ожидаемому: " << expectedRows << endl;
    return false;
  }

  return true;
}

// метод-пустышка чтобы не было ошибок при компиляции
bool MazeParser::validateRowCount(const string& filename, int expectedRows) {
  int rowsInMatrix1 = 0, rowsInMatrix2 = 0;
  return validateRowCount(filename, expectedRows, rowsInMatrix1, rowsInMatrix2);
}

bool MazeParser::validateColumnCount(ifstream& file, int expectedCols) {
  string line;
  while (getline(file, line)) {
    istringstream iss(line);
    int count = 0;
    int value;
    bool hasNumber = false;

    while (iss >> value) {
      ++count;
      hasNumber = true;
    }

    if (hasNumber && count != expectedCols) {
      cerr << "Количество столбцов (" << count
           << ") в строке не совпадает с указанным размером: " << expectedCols
           << endl;
      return false;
    }
  }

  return true;
}
