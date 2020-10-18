#include <cmath>

int findbase(int value) {
  int base = 0;
  while (value > 0) {
    base++;
    value = value / 10;
  }
  return (base);
}

bool narcissistic(int value){
  int base;
  int valcopy = value;
  int testnum = 0;

  base = findbase(value);
  while (value > 0) {
    testnum += pow(value % 10, base);
    value = value / 10;
  }
  if (testnum == valcopy)
    return (true);
  return (false);
}
