#include <string>
#include <iostream>

#include <string>
#include <iostream>

std::string add(const std::string& a, const std::string& b) {
  std::string big_num = "";
  int a_idx = a.length() - 1;
  int b_idx = b.length() - 1;
  int storval = 0;
  while (a_idx >= 0 && b_idx >=0) {
    storval += ((int)a[a_idx] - '0') + ((int)b[b_idx] - '0');
    if (storval == 0)
      big_num.insert(0, "0");
    else {
      big_num.insert(0, std::to_string(storval % 10));
      storval /= 10;
    }  
    a_idx--;
    b_idx--;
  }
  if (a_idx >= 0) {
    while (a_idx >= 0) {
      storval += (int)a[a_idx] - '0';
      if (storval == 0)
        big_num.insert(0, "0");
      else {
        big_num.insert(0, std::to_string(storval % 10));
        storval /= 10;
      }
      a_idx--;
    }
  }
    if (b_idx >= 0) {
    while (b_idx >= 0) {
      storval += (int)a[b_idx] - '0';
      if (storval == 0)
        big_num.insert(0, "0");
      else {
        big_num.insert(0, std::to_string(storval % 10));
        storval /= 10;
      }
      b_idx--;
    }
  }
    if (storval > 0)
      big_num.insert(0, std::to_string(storval));
  return big_num;
}

int main() {
  std::cout << add("123", "456") << "\n";
  std::cout << add("89", "35600") << "\n";
  std::cout << add("100", "1") << "\n";
  std::cout << add("99999", "9999") << "\n";
  std::cout << add("1234500912345678002345", "123456789") << "\n";
  std::cout << add("abcdefg", "abcdefg") << "\n";

}
