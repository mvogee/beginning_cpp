#include <iostream>

int beeramid(int bonus, double price)
{
  if (bonus < price || bonus == 0) // quick check so we don't divide by 0;
    return 0;

  int total_cans = bonus / price;
  int height = 0;
  while (height * height <= total_cans) {
    total_cans = total_cans - (height * height);
    height++;
  }
  return height - 1;
}

int main() {
  std::cout << beeramid(9, 2) << "\n";
  std::cout << beeramid(10, 2) << "\n";
  std::cout << beeramid(11, 2) << "\n";
  std::cout << beeramid(4, 4) << "\n";
}
