#include <iostream>

/* RECURSIVE SOLUTION
int digital_root(int n)
{
  // recursively solves problem
    if (n < 10)
      return n;
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return (digital_root(sum));
}
*/

// non recursive solution
int digital_root(int n) {
  return --n % 9 + 1;
}
