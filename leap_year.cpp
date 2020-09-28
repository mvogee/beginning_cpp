#include <iostream>

int main() {
  int year;
  std::cout << "Enter a four digit year: ";
  std::cin >> year;
//check that input is a valid year
  if (year >= 1000 && year <= 9999) {
    // if year is evenly devisable by 4 it is a leap year.
    if (year % 4 == 0) {
      // if year is evenly divisible by 100 but not by 400 it is not a leap year
      if (year % 100 == 0 && year % 400 != 0) {
        std::cout << "This is not a leap year";
      }
      else {
        std::cout << "this is a leap year!";
      }
    }
    else {
      std::cout << "This is not a leap year";
    }
  }
  else {
    std::cout << "Year must be four digits";
  }
  return (0);
}
