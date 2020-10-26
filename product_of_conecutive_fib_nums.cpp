#include <vector>
typedef unsigned long long ull;
class ProdFib
{
public:
  static std::vector<ull> productFib(ull prod);
};

std::vector<ull> ProdFib::productFib(ull prod) {
  ull fib1 = 0;
  ull fib2 = 1;
  ull fib_sum;
  while (fib1 * fib2 < prod) {
    fib_sum = fib1 + fib2;
    fib1 = fib2;
    fib2 = fib_sum;
  }
  std::vector<ull> product;
  product.push_back(fib1);
  product.push_back(fib2);
  fib1 * fib2 == prod ? product.push_back(1) : product.push_back(0);

  return (product);
}
