#include <string>
#include <iostream>

void swap(char& a, char& b) {
  char hold = a;
  a = b;
  b = hold;
}

// in place
void reverse_string(std::string& str) {
  int back = str.length();
  for (int i = 0; i < back / 2; i++) {
    swap(str[i], str[back - i - 1]);
  }
}

// new string
std::string new_reverse_string(std::string str) {
  std::string reversed = "";
  for (int i = str.length() - 1; i >= 0; i--)
    reversed+= str.at(i);
  return (reversed);
}

int main(int argc, char *argv[]) {
  if (argc > 1)
  {
    std::string mystring = argv[1];
    reverse_string(mystring);
    std::cout << mystring << "\n";
    mystring = new_reverse_string(mystring);
    std::cout << mystring << "\n";
  }
  return (0);
}
