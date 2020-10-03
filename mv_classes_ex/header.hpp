#include <iostream>

class rectangle {
  private:
  double side_one;
  double side_two;

  public:
  rectangle(double s1, double s2);
  double get_rect_side_two();
  double get_rect_side_one();
  double get_rect_area();
  ~rectangle();

};
