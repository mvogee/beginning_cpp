#include <iostream>
#include <string>
#include "header.hpp"


int main(int argc, char const *argv[]) {
  // Print out the argc and argv
  int i = 1;
  double s1;
  double s2;
  std::cout << argc << "\n";
  for (i = 1; i < argc; i++) {
    std::cout << argv[i] << "\n";
  }
  // END argc argv printing;
if (argc == 3){
  // set s1 and s2 to the user input
  // catching for errors if the input isnt a valid double
  try {
    s1 = std::stod (argv[1]);
    s2 = std::stod (argv[2]);
  }
  catch(...) {
    std::cout << "an error occured\ndid you enter a valid rectangle?\n";
    return (0);
  }
  rectangle rect(s1, s2);
  std::cout << "Your rectangles area is: "<< rect.get_rect_area() << "\n";
}
else {
  std::cout << "please enter valid lengths for the sides of the rectangle";
}

  return 0;
}
