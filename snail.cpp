#include <vector>
#include <iostream>

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
  if (goToHeight == 1) {
    return (snail_map[0]);
  }
  //std::cout << height << " : " << width << "\n"; // test for correct width and height

  // itterate through left to right until width is reached
  // decriment height
  while (goToHeight != zeroHeight) {
    col = zeroWidth;
    while (col <= goToWidth) {
      snail.push_back(snail_map.at(row).at(col));
      col++;
    }
    col--;
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
    goToHeight++;
    row = goToHeight;
    while (row >= zeroHeight) {
      snail.push_back(snail_map.at(row).at(col));
      row--;
    }
    row++;
    zeroWidth++;
  }
  std::cout << "\n";
  return snail;
}

void print_vector(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    std:: cout << vec[i] << " ";
  }
}

int main() {
  std::vector<std::vector<int>> v;
    std::vector<int> expected;

    v = {{}};
    expected = {};

    v = {{1}};
    expected = {1};

    v = {{1,2}, {4,3}};
    expected = {1,2,3,4};
    print_vector(snail(v));

    v = {{1,2,3}, {8,9,4}, {7,6,5}};
    expected = {1,2,3,4,5,6,7,8,9};
    print_vector(snail(v));

    v = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
    expected = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    print_vector(snail(v));
  }
