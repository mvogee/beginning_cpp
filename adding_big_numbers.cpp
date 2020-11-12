#include <string>
#include <iostream>

int ctoi(char c) {
  return (c - '0');
}

 std::string sum_strings(const std::string& a, const std::string& b) {
  std::string product = "";
  int aidx = a.length(),
      bidx = b.length(),
      holder = 0;
  while (aidx > 0 && bidx > 0) {
    holder += ctoi(a[aidx - 1]) + ctoi(b[bidx - 1]);
    product.insert(0, std::to_string(holder % 10));
    holder >= 10 ? holder = 1 : holder = 0;
    aidx--;
    bidx--;
  }
  if (aidx > 0) {
    while (aidx > 0) {
      holder += ctoi(a[aidx - 1]);
      product.insert(0, std::to_string(holder % 10));
      holder >= 10 ? holder = 1 : holder = 0;
      aidx--;
    }
  }
  else if (bidx > 0) {
    while (bidx > 0) {;
      holder += ctoi(b[bidx - 1]);
      product.insert(0, std::to_string(holder % 10));
      holder >= 10 ? holder = 1 : holder = 0;
      bidx--;
    }
  }
  if (holder > 0) {
    product.insert(0, "1");
  }
  return product;
}


int main() {
  std::cout << sum_strings("", "10") << "\n";
  std::cout << sum_strings("", "") << "\n";
  std::cout << sum_strings("999999999999999999999999", "999999999999999999") << "\n";
  std::cout << sum_strings("1234", "12345") << "\n";
  std::cout << sum_strings("12345345345346545644532454234534564567546643563453453456565464435435436546574563453453453456456", "8934759834798573498573498573984573948573948573948573984573984573948573948579384") << "\n";
  return 0;
}
