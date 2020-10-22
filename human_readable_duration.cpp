#include <string>
#include <iostream>

std::string between_append(int count) {
  if (count > 1)
    return(", ");
  else if (count == 1)
    return (" and ");
  else
    return ("");
}

std::string format_duration(int seconds) {
  if (seconds == 0)
    return ("now");

  int seconds_in_year = 31536000;
  int seconds_in_day = 86400;
  int seconds_in_hour = 3600;
  int seconds_in_minute = 60;

  int years = 0;
  int days = 0;
  int hours = 0;
  int minutes = 0;
  int count = 0;
  std::string formatted_dur = "";

    years = seconds / seconds_in_year;
    seconds %=  seconds_in_year;
    days = seconds / seconds_in_day;
    seconds %=  seconds_in_day;
    hours = seconds / seconds_in_hour;
    seconds %=  seconds_in_hour;
    minutes = seconds / seconds_in_minute;
    seconds %=  seconds_in_minute;
    if (years)
      count++;
    if (days)
      count++;
    if (hours)
      count++;
    if (minutes)
      count++;
    if (seconds)
      count++;

    if (years > 0) {
      formatted_dur.append(std::to_string(years));
      years > 1 ? formatted_dur.append(" years") : formatted_dur.append(" year");
      count--;
      if (count)
        formatted_dur.append(between_append(count));
      }
    if (days > 0) {
      formatted_dur.append(std::to_string(days));
      days > 1 ? formatted_dur.append(" days") : formatted_dur.append(" day");
      count--;
      if (count)
        formatted_dur.append(between_append(count));
    }
    if (hours > 0) {
      formatted_dur.append(std::to_string(hours));
      hours > 1 ? formatted_dur.append(" hours") : formatted_dur.append(" hour");
      count--;
      if (count)
        formatted_dur.append(between_append(count));
    }
    if (minutes > 0) {
      formatted_dur.append(std::to_string(minutes));
      minutes > 1 ? formatted_dur.append(" minutes") : formatted_dur.append(" minute");
      count--;
      if (count)
        formatted_dur.append(between_append(count));
    }
    if (seconds > 0) {
      formatted_dur.append(std::to_string(seconds));
      seconds > 1 ? formatted_dur.append(" seconds") : formatted_dur.append(" second");
      count--;
      if (count)
        formatted_dur.append(between_append(count));
    }
    return (formatted_dur);
}

int main() {
  std::cout << format_duration(0) << '\n';
  std::cout << format_duration(3662) << '\n';
  std::cout << format_duration(120) << '\n';
  std::cout << format_duration(62) << '\n';
  std::cout << format_duration(1) << '\n';
  return (0);
}
