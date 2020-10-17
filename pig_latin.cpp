#include <string>
#include <iostream>

int wordlen(std::string str, int start_idx) {
  int length = 0;
  while (isalpha(str[start_idx])) {
    start_idx++;
    length++;
  }
  return (length);
}

std::string pig_it(std::string str) {
  int word_length = 0;
  std::string pig;

  int i = 0;
  while (str[i]) {
    std::cout << str[i] << "\n";
    if (isalpha(str[i])) {
      std::cout << "alpha\n";
      word_length = wordlen(str, i);

      if (word_length > 1) {
        pig.append(str, i + 1, word_length - 1); // hi; --> i
      }
      pig.append(str, i, 1); // hello --> h
      pig.append("ay");
      i += word_length;
    }
    else {
      std::cout << "else\n";
      pig.append(str, i, 1);
      i++;
    }
  }
  return (pig);
}

int main() {
  std::cout << pig_it(". ! h ?") << "\n";
  std::cout << pig_it("hello my name is doug.") << "\n";
}

/*
#include <string>
#include <regex>
using namespace std;
string pig_it(string Z) {
    regex reg(("(\\w)(\\w*)(\\s|$)"));
    return regex_replace(Z, reg, "$2$1ay$3");
}
*/
