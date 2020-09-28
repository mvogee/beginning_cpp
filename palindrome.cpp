#include <iostream>
#include <string>

bool is_palindrome(std::string text) {
  int strlen;
  int i;

  strlen = text.length() - 1;
  i = 0;
  while (i < strlen) {
    if (text[i] != text[strlen]) {
      return (false);
    }
    i++;
    strlen--;
  }
  return (true);
}

int main(int argc, char const *argv[]) {
  /* code */
    std::cout << is_palindrome("") << "\n";
  return 0;
}
