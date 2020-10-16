#include <iostream>
#include <string>


std::string to_camel_case(std::string text)
{
  for(int i = 0; i < text.size(); ++i)
  {
    if(text[i] == '-' || text[i] == '_')
    {
      while (text[i] == '-' || text[i] == '_')
        text.erase(i,1);
      text[i] = toupper(text[i]);
    }
  }
  return text;
}
int main() {
  std::string str = "Makeme___--camel--";
  std::string cml;
  std::cout << str.length() << "\n";
  cml = to_camel_case(str);
  std::cout << cml.length() << "\n";
  std::cout << cml << "\n";

  return 0;
}
