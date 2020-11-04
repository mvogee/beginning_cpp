#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

/*
** Given two arrays a and b write a function comp(a, b))
** that checks whether the two arrays have the "same" elements,
** with the same multiplicities. "Same" means, here, that the elements
** in b are the elements in a squared, regardless of the order.
*/
class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b) {
      bool same = true;
      std::map<int, int> squares; // first is square second is iterator;
      for (auto i = a.begin(); i != a.end(); i++) {
        if (squares.find(*i * *i) != squares.end())
          squares[*i * *i] += 1;
        else
          squares[*i * *i] = 1;
      }
      for (auto j = b.begin(); j != b.end(); j++) {
        auto val = squares.find(*j);
        if (val != squares.end()) {
          if (val->second == 0) {
            same = false;
            break;
          }
          else
            val->second -= 1;
        }
        else { // val = squares.end()
          same = false;
          break;
        }
      }
      return same;
    }

    static bool comp2(std::vector<int>&a, std::vector<int> &b) {
      if (a.size() != b.size())
        return false;
      for (auto &v: a)
        v = v * v;
      return std::is_permutation(a.cbegin(), a.cend(), b.cbegin());
    }
};

void dotest(std::vector<int> a, std::vector<int> b, bool sol)
{
    bool ans = Same::comp2(a, b);
    std::string passed_or_not = (ans == sol ? "passed." : "failed");
    std::cout << passed_or_not << " value: " << ans << "\n";
}

int main() {

  std::vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
  std::vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
  dotest(a, b, true);
  a = {121, 144, 19, 161, 19, 144, 19, 11};
  b = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
  dotest(a, b, false);

}
