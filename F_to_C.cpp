#include <iostream>

int main() {
  double tempF;
  double tempC;

  std::cout << "Enter the temperature in Fahrenheit: ";
  std::cin >> tempF;

  tempC = (tempF - 32)/1.8;

  std::cout << "the temperature in Celcius is: " << tempC << "\n";

  return 0;
}
