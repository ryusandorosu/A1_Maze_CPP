#include "../maze.h"

// Метод для поиска решения (BFS)
bool Maze::solveMaze(const Coord& start, const Coord& end) {
  BoolMatrix visited(rows, vector<bool>(cols, false));
  CoordMatrix predecessor(rows, vector<Coord>(cols, make_pair(-1, -1)));

  solutionMatrix.resize(rows, vector<int>(cols, 0));

  // Стартовая точка
  queue<Coord> pathQueue;
  pathQueue.push(start);
  visited[start.first][start.second] = true;

  // Векторы направлений: вверх, вниз, влево, вправо
  vector<Coord> directions;
  directions.emplace_back(-1, 0);
  directions.emplace_back(1, 0);
  directions.emplace_back(0, -1);
  directions.emplace_back(0, 1);

  while (!pathQueue.empty()) {
    const auto& front = pathQueue.front();
    int x = front.first;
    int y = front.second;
    pathQueue.pop();

    if (x == end.first && y == end.second) {
      // Если достигли конца, восстанавливаем путь
      reconstructPath(predecessor, start, end);
      return true;
    }

    // Пробуем двигаться во всех направлениях
    for (const auto& direction : directions) {
      int nx = x + direction.first;
      int ny = y + direction.second;

      if (canMove(x, y, nx, ny) && !visited[nx][ny]) {
        visited[nx][ny] = true;
        predecessor[nx][ny] = make_pair(x, y);
        pathQueue.push(make_pair(nx, ny));
      }
    }
  }

  return false;  // Если путь не найден
}

// Вспомогательный метод для поиска пути (BFS)
void Maze::reconstructPath(const CoordMatrix& predecessor, const Coord& start,
                           const Coord& end) {
  Coord current = end;
  while (current != start) {
    solutionMatrix[current.first][current.second] = 1;
    current = predecessor[current.first][current.second];
  }
  solutionMatrix[start.first][start.second] = 1;  // Отметить старт
}

// Проверка, можно ли двигаться в клетку (с учётом стен)
bool Maze::canMove(int x, int y, int nx, int ny) const {
  // Проверяем, находимся ли мы внутри лабиринта
  if (nx < 0 || ny < 0 || nx >= rows || ny >= cols) {
    return false;
  }

  // Проверка вертикальных и горизонтальных стен
  if (x == nx && abs(y - ny) == 1) {  // Двигаемся по горизонтали
    return verticalWalls[x][min(y, ny)] == 0;
  } else if (y == ny && abs(x - nx) == 1) {  // Двигаемся по вертикали
    return horizontalWalls[min(x, nx)][y] == 0;
  }
  return false;
}

void Maze::clearSolutionMatrix() {
  for (auto& row : solutionMatrix) {
    row.assign(row.size(), 0);
  }
}
