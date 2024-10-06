#include "class_gen.h"

MazeGenerator::MazeGenerator(int r, int c) : rows(r), cols(c) {
  if (rows < 0 || cols < 0) {
    return;
  }
  currentRow.resize(cols, 0);
  verticalWalls.resize(rows, vector<int>(cols, 0));
  horizontalWalls.resize(rows, vector<int>(cols, 0));
}

bool MazeGenerator::checkDimensions() {
  if (rows < MIN_SIZE || cols < MIN_SIZE || rows > MAX_SIZE ||
      cols > MAX_SIZE) {
    cerr << "Указаны неверные параметры для генерации: " << rows << "x" << cols
         << endl;
    cerr << "Параметры нужно указывать в диапазоне от " << MIN_SIZE << "x"
         << MIN_SIZE << " до " << MAX_SIZE << "x" << MAX_SIZE << endl;
    return false;
  }
  return true;
}

void MazeGenerator::generateMaze() {
  for (int i = 0; i < rows; i++) {
    if (i == rows - 1) {
      createVerticalWalls(i);
      lastLineCheck();
    } else {
      createVerticalWalls(i);
      createHorizontalWalls(i);
      duplicateCurrentLine(i);
    }
  }
}

void MazeGenerator::createUniqueSet() {
  for (auto &element : currentRow) {
    if (element == 0) {
      element = ++setID;
    }
  }
}

bool MazeGenerator::randomBool() {
  static random_device rd;
  static mt19937 generator(rd());
  static uniform_int_distribution<> distribution(0, 1);
  return distribution(generator) == 1;
}

void MazeGenerator::mergeSet(int current, int next) {
  for (int i = 0; i < cols; i++) {
    if (currentRow[i] == next) {
      currentRow[i] = current;
    }
  }
}

void MazeGenerator::createVerticalWalls(int row) {
  if (row == 0) {
    createUniqueSet();
  }
  for (int i = 0; i < cols - 1; ++i) {
    bool choise = randomBool();
    if (choise == true || (currentRow[i] == currentRow[i + 1])) {
      verticalWalls[row][i] = 1;
    } else if (choise == false) {
      mergeSet(currentRow[i], currentRow[i + 1]);
    }
  }
  verticalWalls[row][cols - 1] = 1;
}

bool MazeGenerator::countIndeticalSet(int value) {
  int count = 0;
  for (int i = 0; i < cols; i++) {
    if (currentRow[i] == value) {
      count++;
    }
  }
  return count > 1 ? true : false;
}

int MazeGenerator::countCellsWithoutHWalls(int value, int row) {
  int count = 0;
  for (int i = 0; i < cols; i++) {
    if (currentRow[i] == value && horizontalWalls[row][i] == 0) {
      count++;
    }
  }
  return count;
}

void MazeGenerator::createHorizontalWalls(int row) {
  for (int i = 0; i < cols; i++) {
    bool choise = randomBool();
    bool identicalSet = countIndeticalSet(currentRow[i]);
    if (choise == true && identicalSet) {
      horizontalWalls[row][i] = 1;
    }
    if (countCellsWithoutHWalls(currentRow[i], row) == 0) {
      horizontalWalls[row][i] = 0;
    }
  }
}

void MazeGenerator::duplicateCurrentLine(int row) {
  for (int i = 0; i < cols; i++) {
    setID++;
    if (horizontalWalls[row][i] == 1) {
      currentRow[i] = setID;
    }
  }
}

void MazeGenerator::lastLineCheck() {
  for (int i = 0; i < cols - 1; i++) {
    if (currentRow[i] != currentRow[i + 1]) {
      verticalWalls[rows - 1][i] = 0;
      mergeSet(currentRow[i], currentRow[i + 1]);
    }
    horizontalWalls[rows - 1][i] = 1;
  }
  horizontalWalls[rows - 1][cols - 1] = 1;
  verticalWalls[rows - 1][cols - 1] = 1;
}
