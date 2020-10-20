#include <vector>
#include <iostream>

// There is an even more clever way of doing this using the sum. expected sum vs actual sum

static long findMissing(std::vector<long> list){
  int common_difference = (int) (list.back() - list[0]) /  (int) list.size();
  int i = 0;
  while (list[i] + common_difference == list[i+1] && i < list.size() - 1)
    i++;
  return (list[i] + common_difference);
}

int main() {
  std::vector<long> v;
  v.push_back(-3);
  v.push_back(-11);
  v.push_back(-15);

  std::cout << findMissing(v) << " answer\n";
  std::cout << -12 / 3 << "\n";

  return 0;
}
