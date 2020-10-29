
#include <map>
#include <string>
#include <iostream>

int main() {
  std::map<int, std::string> mymap;
  std::map<int, std::string>::iterator it;
  mymap[1] = "Hello";
  mymap[2] = "World";
  mymap[3] = "dood";

  std::cout << mymap[1] << " " << mymap[2] << " " << mymap[3] << "\n";
  auto slide = mymap.find(5);
  mymap.insert(std::make_pair(4, "lol"));
  if (slide == mymap.end()) {
    std::cout << "end of map";
  }
  std::cout << mymap[4] << "\n";
  it = mymap.begin();
  while (it != mymap.end()) {
    std::cout << it->first << " : " << it->second << "\n";
    it++;
  }
  std::cout << it->first;
  mymap.erase(4);
  it = mymap.begin();
  while (it != mymap.end()) {
    std::cout << it->second << " ";
    it++;
  }
  std::cout << "\n";
  return (0);
}
