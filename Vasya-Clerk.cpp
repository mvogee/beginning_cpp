/*
The new "Avengers" movie has just been released! There are a lot of people at
the cinema box office standing in a huge line. Each of them has a
single 100, 50 or 25 dollar bill. An "Avengers" ticket costs 25 dollars.
Vasya is currently working as a clerk. He wants to sell a ticket to every single
person in this line. Can Vasya sell a ticket to every person and give change if
he initially has no money and sells the tickets strictly in the order people queue?
Return YES, if Vasya can sell a ticket to every person and give change with the
bills he has at hand at that moment. Otherwise return NO.
*/
#include <string>
#include <vector>
#include <iostream>

class Wallet{
  private:
  int twentyFives = 0;
  int fifties = 0;

  public:
  void take_money(int ammount);
  int give_change(int ammount);

};

void Wallet::take_money(int ammount){
  switch (ammount) {
      case 25:
        twentyFives++;
        break;
      case 50:
        fifties++;
        break;
  }
}

int Wallet::give_change(int ammount) {
  int change = 0;
  while (change != ammount) {
    if (ammount - change >= 50 && fifties > 0) {
      change += 50;
      fifties--;
    }
    else if (ammount - change >= 25 && twentyFives > 0) {
      change += 25;
      twentyFives--;
    }
    else
      break;
  }
  return change;
}

std::string tickets(const std::vector<int>& peopleInLine) {
  Wallet cashregister;
  int changeNeeded = 0;
  for (auto i : peopleInLine) {
    cashregister.take_money(i);
    changeNeeded = i - 25;
    if (cashregister.give_change(changeNeeded) != changeNeeded)
      return ("NO");
  }
  return ("YES");
}
