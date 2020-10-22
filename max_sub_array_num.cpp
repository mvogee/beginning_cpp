#include <vector>
#include <iostream>

using namespace std;

int maxSequence(const vector<int>& arr){
  if (!arr[0])
    return (0);
  int max = 0;
  int max_at_i = 0;
  for (int i = 0; i < (int) arr.size(); i++) {
    max_at_i += arr[i];
    if (max_at_i < 0)
      max_at_i = 0;
    else if (max_at_i > max)
      max = max_at_i;
  }
  return (max);
}

int main() {
  static const int arr[] = {-5, -1, -2, -7, -3, -1, -2, -1, -5, 6};;
  vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
  std::cout << "max: " << maxSequence(vec) << '\n';
  return 0;
}
