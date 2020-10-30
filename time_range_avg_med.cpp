#include <string>
#include <vector>
#include <cctype>
class Stat
{
public:
  static std::string stat(const std::string &strg);
  static int convert_to_seconds(int delims, int time);

private:
  static std::vector<int> times_in_seconds;
};

int Stat::convert_to_seconds(int delims, int time){
  int mult = 0;

  if (delims == 0)
    mult = 3600;
  else if (delims == 1)
    mult = 60;
  else if (delims == 2)
    mult = 1;
  return time * mult;
}

std::string Stat::stat(const std::string &strg) {
  if (strg == "")
    return ("");
  std::string next;
  int delims = 0;
  int thistime = 0;
  int seconds = 0;

  for (std::string::const_iterator it = strg.begin(); it != strg.end(); it++) {
    if ((*it == '|' || *it == ',') && !next.empty()) {
      thistime = std::stoi(next);
      seconds += convert_to_seconds(delims,thistime);
      if (delims == 2) {
        times_in_seconds.push_back(seconds);
        seconds = 0;
      }
      delims == 2 ? (delims = 0) : delims++;
      next.clear();
      thistime = 0;
    }
    else if (isdigit(*it))
      next += *it;
  }
  if (!next.empty()){
    thistime = std::stoi(next);
    times_in_seconds.push_back(convert_to_seconds(delims, thistime));
  }
  // convert strg to a total seconds int
  // get the Range, Mean, and Median from those ints
  // convert the ints back into time representations
}
