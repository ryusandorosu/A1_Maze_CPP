#include "class_gen.h"

void MazeGenerator::saveMazeToFile(const string& filename) const {
  ofstream file(filename);
  if (!file.is_open()) {
    cerr << "Не удалось открыть файл для записи: " << filename << endl;
    return;
  }

  file << rows << " " << cols << endl;

  // Запись вертикальных стен
  for (const auto& row : verticalWalls) {
    for (int wall : row) {
      file << wall << " ";
    }
    file << endl;
  }

  file << endl;

  // Запись горизонтальных стен
  for (const auto& row : horizontalWalls) {
    for (int wall : row) {
      file << wall << " ";
    }
    file << endl;
  }

  file.close();
}
