#include <cmath>
#include <iostream>

class ASum
{
  public:
  static long long findNb(long long m) {
    long long N = 0;
    long long sum = 0;

    while (sum < m) {
      N++;
      sum += N * N * N;
    }
    if (sum > m)
      N = -1;
    return (N);
  };
};

int main() {

  std::cout << ASum::findNb(4183059834009) << "<--me : correct-->" << 2022 << "\n";
  std::cout << ASum::findNb(24723578342962) << "<--me : correct-->" << -1 << "\n";
  std::cout << ASum::findNb(135440716410000) << "<--me : correct-->" << 4824 << "\n";
  std::cout << ASum::findNb(40539911473216) << "<--me : correct-->" << 3568 << "\n";
  std::cout << ASum::findNb(26825883955641) << "<--me : correct-->" << 3218 << "\n";
    return (0);
};
