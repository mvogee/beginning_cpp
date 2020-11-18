#include <iostream>
#include <string>

bool islower(char c) {
  if (c <= 'z' && c >= 'a')
    return true;
  else
    return false;
}

bool isupper(char c) {
  if (c <= 'Z' && c >= 'A')
    return true;
  else
    return false;
}

std::string rot13(std::string msg) {
  std::string rot13;
  rot13.resize(msg.size());
  for (int i = 0; i < msg.length(); i++) {
    if (islower(msg[i])) {
      rot13[i] = 'a' + ((msg[i] - 'a' + 13) % 26);
    }
    else if (isupper(msg[i])) {
      rot13[i] = 'A' + ((msg[i] - 'A' + 13) % 26);
    }
    else {
      rot13[i] = msg[i];
    }
  }
  return rot13;
}


int main() {
  std::cout << rot13("matthew") << "\n";
  std::cout << rot13("test");
  return 0;
}
