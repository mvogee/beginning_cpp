#include <iostream>

bool is_sum_of_consecutive_ints(unsigned int num) {
  return(num & (num-1) && num);
}

int main() {
  std::cout << is_sum_of_consecutive_ints(16) << '\n';
  std::cout << is_sum_of_consecutive_ints(19) << '\n';
}
