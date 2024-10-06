#include "maze_parser.h"

bool MazeParser::readMaze() {
  MazeParser mazeParser(filename);

  // Чтение и проверка данных, чтение горизонтальных стен
  if (!mazeParser.readFile(filename, verticalWalls, rows, cols)) {
    return false;
  }

  ifstream file(filename);  // для повторного чтения через sstream
  if (!file.is_open()) {
    cerr << "Не удалось открыть файл: " << filename << endl;
    return false;
  }

  // Пропускаем чтение размеров и первой матрицы
  file.clear();
  file.seekg(0, ios::beg);

  // Пропустить строки с размерами
  string line;
  getline(file, line);  // Пропуск первой строки с размерами
  for (int i = 0; i < rows; ++i) {
    getline(file, line);  // Пропуск строк первой матрицы
  }

  // Чтение второй матрицы
  if (!mazeParser.readWalls(file, horizontalWalls, rows, cols)) {
    return false;
  }

  return true;
}
