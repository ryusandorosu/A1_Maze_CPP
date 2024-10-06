#include "cave_parser.h"

// Функция для отрисовки поля на консоли
void CaveParser::drawField() {
  for (const auto& row : field) {
    for (int cell : row) {
      if (cell == 0) {
        cout << "▓▓";
      } else if (cell == 1) {
        cout << "░░";
      } else {
        cerr << "Неизвестное значение в поле: " << cell << endl;
        return;
      }
    }
    cout << endl;
  }
}
