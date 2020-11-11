#include <string>
#include <iostream>
/*
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
 */

int ctoi(char c) {
  return (c - '0');
}

 std::string sum_strings(const std::string& a, const std::string& b) {
  std::string product = "";
  int aidx = a.length(),
      bidx = b.length(),
      holder = 0;
      std::cout << "seg1\n";
  while (aidx > 0 && bidx > 0) {
    holder += ctoi(a[aidx - 1]) + ctoi(b[bidx - 1]);
    product.insert(0, std::to_string(holder % 10));
    holder >= 10 ? holder = 1 : holder = 0;
    aidx--;
    bidx--;
  }
  std::cout << "seg2\n";
  if (aidx > 0) {
    std::cout << "seg3\n";
    while (aidx > 0) {
      holder += ctoi(a[aidx - 1]);
      product.insert(0, std::to_string(holder % 10));
      holder >= 10 ? holder = 1 : holder = 0;
      aidx--;
    }
  }
  else if (bidx > 0) {
    std::cout << "seg4\n";
    while (bidx > 0) {
      std::cout << "loop1\n";
      holder += ctoi(b[bidx - 1]);
      product.insert(0, std::to_string(holder % 10));
      holder >= 10 ? holder = 1 : holder = 0;
      bidx--;
    }
  }
  std::cout << "seg5\n";
  if (holder > 0) {
    std::cout << "seg6\n";
    product.insert(0, "1");
    std::cout << "seg7\n";
  }

  return product;
}


int main() {
  std::string str = "";
  std::cout << str.length();
  //std::cout << '0' - '0' << "\n";
  //std::cout << (18 - (18 % 10)) / 10 << "\n";
  //std::cout << sum_strings("55", "55") << "\n";
  std::cout << sum_strings("", "10") << "\n";
  return 0;
}
