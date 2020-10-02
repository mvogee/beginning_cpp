#include <iostream>
// function will swap a & b
// retuns 1 if succesful, retuns 0 on error
int swap_nums(int &a, int &b) {
  int a_coppy;

  a_coppy = a;
  a = b;
  b = a_coppy;
  return 1;
}

int main() {
  int i = 10;
  int c = 5;
  if (swap_nums(i, c) == 1) {
    std::cout << i << "\n";
    std::cout << c << "\n";
  }

  return 0;
}
