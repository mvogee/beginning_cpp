#include <vector>
#include <iostream>

void print_vector(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << "\n";
}

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  std::vector<int> snail;
  if (snail_map.empty()) {
    return {};
  }
  int col = 0;
  int row = 0;
  int goToHeight = snail_map.size() - 1;
  int goToWidth = snail_map.at(0).size() - 1;
  int zeroHeight = 0;
  int zeroWidth = 0;
  if (goToHeight == 0) {
    return (snail_map[0]);
  }
  while (goToHeight >= zeroHeight) {
    col = zeroWidth;
    while (col <= goToWidth) {
      snail.push_back(snail_map.at(row).at(col));
      col++;
    }
    col = goToWidth;
    zeroHeight++;
    row = zeroHeight;
    while (row <= goToHeight) {
      snail.push_back(snail_map.at(row).at(col));
      row++;
    }
    row--;
    goToWidth--;
    col = goToWidth;
    while (col >= zeroWidth) {
      snail.push_back(snail_map.at(row).at(col));
      col--;
    }
    col++;
    goToHeight--;
    row = goToHeight;
    while (row >= zeroHeight) {
      snail.push_back(snail_map.at(row).at(col));
      row--;
    }
    row++;
    zeroWidth++;
  }
  return snail;
}

bool doesPass(std::vector<int> snail, std::vector<int> expected) {
  bool passed = false;
  if (snail == expected) {
    std::cout << "Test Passed";
    passed = true;
  }
  else {
    std::cout << "Test Failed - Expected ";
    print_vector(expected);
    std::cout << "Actual output: ";
    print_vector(snail);
  }
  std::cout << "\n";
  return passed;
}

void test_snail() {
  std::vector<std::vector<int>> v;
    std::vector<int> expected;
    bool pass = true;
    int failed_tests = 0;
    v = {{}};
    expected = {};
    pass = doesPass(snail(v), expected);
    if (pass == false)
      failed_tests++;

    v = {{1}};
    expected = {1};
    pass = doesPass(snail(v), expected);
    if (pass == false)
      failed_tests++;

    v = {{1,2}, {4,3}};
    expected = {1,2,3,4};
    pass = doesPass(snail(v), expected);
    if (pass == false)
      failed_tests++;

    v = {{1,2,3}, {8,9,4}, {7,6,5}};
    expected = {1,2,3,4,5,6,7,8,9};
    pass = doesPass(snail(v), expected);
    if (pass == false)
      failed_tests++;

    v = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
    expected = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    pass = doesPass(snail(v), expected);
    if (pass == false)
      failed_tests++;
    if (failed_tests == 0)
      std::cout << "All tests Passed";
    else
      std::cout << "Failed " << failed_tests << " Tests.";
}

int main() {
  test_snail();
  return 0;
}
