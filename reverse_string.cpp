#include <string>
#include <iostream>

void swap(char& a, char& b) {
  char hold = a;
  a = b;
  b = hold;
}

void reverse_string(std::string& str) {
  int back = str.length();
  for (int i = 0; i < back / 2; i++) {
    swap(str[i], str[back - i - 1]);
  }
}

int main(int argc, char *argv[]) {
  if (argc > 1)
  {
    std::string mystring = argv[1];
    reverse_string(mystring);
    std::cout << mystring;
  }
  return (0);
}
