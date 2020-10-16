#include <cmath>
#include <iostream>
long int findNextSquare(long int sq) {
  auto sqrt = std::sqrt(sq);

  return std::modf(sqrt, &sqrt) == 0 ? (sqrt + 1) * (sqrt + 1) : -1;
}

int main() {
std::cout <<  findNextSquare(144) << "\n";
std::cout << findNextSquare(676) << "\n";
std::cout << findNextSquare(114) << "\n";
  return 0;
}
