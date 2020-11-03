#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <iostream>

class Stat
{
private:
  std::vector<int> times_in_seconds;

public:
  int convert_to_seconds(int delims, int time);
  std::string to_str_time(int seconds);

  std::string stat(const std::string &strg) {
    if (strg == "")
      return ("");
    std::string next;
    int delims = 0;
    int thistime = 0;
    int seconds = 0;

    for (std::string::const_iterator it = strg.begin(); it != strg.end(); it++) {
      if ((*it == '|' || *it == ',') && !next.empty()) {
        thistime = std::stoi(next);
        seconds += Stat::convert_to_seconds(delims,thistime);
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
      seconds += Stat::convert_to_seconds(delims, thistime);
      times_in_seconds.push_back(seconds);
    }
    std::sort(times_in_seconds.begin(), times_in_seconds.end());
    int range = (*(--times_in_seconds.end())) - *times_in_seconds.begin();
    int average = 0;
    int total = 0;
    for (auto it = times_in_seconds.begin(); it != times_in_seconds.end(); it++){
      std::cout << *it << "\n";
      average += *it;
      total++;
    }
    average /= total;
    int median = times_in_seconds.at(total / 2);
    std::string final = "Range ";
    final += to_str_time(range);
    final += ", Average " + to_str_time(average);
    final += ", Median " + to_str_time(median);
    return final;
  }

};

std::string Stat::to_str_time(int seconds){
  int hours = seconds / 3600;
  seconds %= 3600;
  int minutes = seconds / 60;
  seconds %= 60;

  std::string timestr = "";
  if (hours < 10)
    timestr += "0" + std::to_string(hours) + "|";
  else
    timestr += std::to_string(hours) + "|";
  if (minutes < 10)
    timestr += "0" + std::to_string(minutes) + "|";
  else
    timestr += std::to_string(minutes) + "|";
  if (seconds < 10)
    timestr += "0" + std::to_string(seconds);
  else
    timestr += std::to_string(seconds);
  return timestr;
}

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




int main() {
  const std::string times = "02|15|59, 2|47|16, 02|17|20, 2|32|34, 2|17|17, 2|22|00, 2|31|41";
  Stat mystats;

  std::cout << mystats.stat(times);
  return 0;
}
