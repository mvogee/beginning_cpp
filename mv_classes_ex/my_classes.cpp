#include <iostream>
#include "header.hpp"


  rectangle::rectangle(double s1, double s2) {
    side_one = s1;
    side_two = s2;
  }

  double rectangle::rect_area(double const side_one, double const side_two) {
  return (side_one * side_two);
}
