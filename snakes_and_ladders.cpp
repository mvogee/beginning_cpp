#include <sstream>
class SnakesLadders
{

  private:
  int board[100] = {0,36,0,0,0,0,7,23,0,0,
                    0,0,0,0,11,-10,0,0,0,0,
                    21,0,0,0,0,0,0,56,0,0,
                    0,0,0,0,0,8,0,0,0,0,
                    0,0,0,0,0,-21,0,0,-38,0,
                    16,0,0,0,0,0,0,0,0,0,
                    0,-43,0,-4,0,0,0,0,0,0,
                    20,0,0,-21,0,0,0,20,0,0,
                    0,0,0,0,0,0,7,0,-21,0,
                    0,-4,0,0,-20,0,0,0,-19,0};
  public:

  int players[2] = {0, 0}; // index 0 is p1 -- index 1 is p2
  int whosturn = 2; // starts at 2 to avoid division by 0
    SnakesLadders(){};
    std::string play(int die1, int die2)
    {
      std::ostringstream o; // to format the return string
      int p = whosturn % 2;
      if (players[0] == 100 || players[1] == 100)
        return "Game over!";
      players[p] += die1 + die2;
      if (players[p] > 100)
        players[p] = 100 - (players[p] - 100);
      if (players[p] == 100)
        o << "Player " << p + 1 << " Wins!";
      else {
        players[p] += board[players[p] - 1];
        o << "Player " << p + 1 << " is on square " << players[p];
      }

      if (die1 != die2) whosturn++;
      return o.str();
    };
};
