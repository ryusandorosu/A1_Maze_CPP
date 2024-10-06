#ifndef A1_MAZE_CPP_1_SRC_BACKEND_COMMON_UTILS_H_
#define A1_MAZE_CPP_1_SRC_BACKEND_COMMON_UTILS_H_

#include <sstream>

#include "includes.h"

class CommonUtils {
 public:
  static bool checkFileOpen(ifstream& file, const string& filename);
  static bool checkFileExtension(const string& filename,
                                 const string& expectedExtension);
  static bool readDimensions(ifstream& file, int& rows, int& cols);
};

#endif  // A1_MAZE_CPP_1_SRC_BACKEND_COMMON_UTILS_H_
