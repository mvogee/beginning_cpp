#include <cmath>
#include <iostream>

bool narcissistic(int value){
  int base = log10(value);
  int valcopy = value;
  int sum = 0;

  while (valcopy > 0) {
    sum += pow(valcopy % 10, base);
    valcopy /= 10;
  }
  return sum == value;
}
