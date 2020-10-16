#include <string>
#include <iostream>

std::string duplicate_encoder(const std::string& word){
  int wordsize = word.size();
  std::string encoded(wordsize, 0);
  char code = ')'; // ) duplicates, ( no duplicates

  for (int i = 0; i < wordsize; i++) {
    code = '(';
    while (encoded[i] == ')') {
      i++;
    }
    for (int j = i + 1; j < wordsize; j++) {
      if (tolower(word[j]) == tolower(word[i])) {
        code = ')';
        encoded[j] = code;
      }
    }
    encoded[i] = code;
  }
  return (encoded);
}

int main(int argc, char const *argv[]) {
  std::string str;
  if (argc > 1) {
    str = duplicate_encoder(argv[1]);
    std::cout << str << "\n";
  }
  return 0;
}
