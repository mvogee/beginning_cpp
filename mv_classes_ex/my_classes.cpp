#include <iostream>
#include "header.hpp"


rectangle::rectangle(double s1, double s2) {
  side_one = s1;
  side_two = s2;
}

double rectangle::get_rect_area() {
  return (side_one * side_two);
}

rectangle::~rectangle(){
  std::cout << "freed rectangle";
}
