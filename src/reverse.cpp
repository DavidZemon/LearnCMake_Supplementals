#include <sstream>

#include "reverse.h"

std::string reverse(const std::string &input) {
  std::stringstream ss;
  for (auto iterator = input.rbegin(); iterator != input.rend(); iterator++) {
    ss << *iterator;
  }
  return ss.str();
}
