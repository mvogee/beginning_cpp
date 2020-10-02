#include <iostream>
#include "header.hpp"


int main(int argc, char const *argv[]) {
  // Print out the argc and argv
  int i = 1;
  std::cout << argc << "\n";
  for (i = 1; i < argc; i++) {
    std::cout << argv[i] << "\n";
  }
  // END argc argv printing;

  rectangle rect(24, 25);
  std::cout << rect.rect_area(2, 2) << "\n";
  return 0;
}
