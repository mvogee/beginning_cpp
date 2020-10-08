#include "header.hpp"
#include <iostream>

void win_conditions(player *plyr, game_board *board, int last_play) {
  const char pt = plyr->get_token();
//[0][1][2]
//[3][4][5]
//[6][7][8]
  //position 0: 1,2: 4,8: 3,6
  //position 1: 0,2: 4,7
  //position 2: 0,1: 4,6, 5,8
  //position 3: 0,6: 4,5:
  //position 4: 3,5: 1,7: 0,8: 2,6
  //position 5: 2,8: 3,4:
  //position 6: 0,3: 7,8: 4,2
  //positino 7: 6,8: 1,4
  //position 8: 2,5: 6,7: 0,4
  switch (last_play) {
    case 0:
      if ((board->get_spot_char(1) == pt && board->get_spot_char(2) == pt) ||
      (board->get_spot_char(4) == pt && board->get_spot_char(8) == pt) ||
      (board->get_spot_char(3) == pt && board->get_spot_char(6) == pt))
      {
        plyr->winner = true;
        std::cout << plyr->get_name() << " is the winner! 0\n";
      }
      break;
    case 1:
      if ((board->get_spot_char(0) == pt && board->get_spot_char(2) == pt) ||
        (board->get_spot_char(4) == pt && board->get_spot_char(7) == pt))
      {
        plyr->winner = true;
        std::cout << plyr->get_name() << " is the winner! 1\n";
      }
      break;
    case 2:
      if ((board->get_spot_char(0) == pt && board->get_spot_char(1) == pt) ||
      (board->get_spot_char(4) == pt && board->get_spot_char(6) == pt) ||
      (board->get_spot_char(5) == pt && board->get_spot_char(8) == pt))
      {
        plyr->winner = true;
        std::cout << plyr->get_name() << " is the winner! 2\n";
      }
      break;
    case 3:
      if ((board->get_spot_char(0) == pt && board->get_spot_char(6) == pt) ||
      (board->get_spot_char(4) == pt && board->get_spot_char(5) == pt))
      {
        plyr->winner = true;
        std::cout << plyr->get_name() << " is the winner! 3\n";
      }
      break;
    case 4:
      if ((board->get_spot_char(3) == pt && board->get_spot_char(5) == pt) ||
      (board->get_spot_char(1) == pt && board->get_spot_char(7) == pt) ||
      (board->get_spot_char(0) == pt && board->get_spot_char(8) == pt) ||
      (board->get_spot_char(2) == pt && board->get_spot_char(6) == pt))
      {
        plyr->winner = true;
        std::cout << plyr->get_name() << " is the winner! 4\n";
      }
      break;
    case 5:
      if ((board->get_spot_char(2) == pt && board->get_spot_char(8) == pt) ||
      (board->get_spot_char(3) == pt && board->get_spot_char(4) == pt))
      {
        plyr->winner = true;
        std::cout << plyr->get_name() << " is the winner! 5\n";
      }
      break;
    case 6:
      if ((board->get_spot_char(0) == pt && board->get_spot_char(7) == pt) ||
      (board->get_spot_char(7) == pt && board->get_spot_char(8) == pt) ||
      (board->get_spot_char(4) == pt && board->get_spot_char(2) == pt))
      {
        plyr->winner = true;
        std::cout << plyr->get_name() << " is the winner! 6\n";
      }
      break;
    case 7:
      if ((board->get_spot_char(6) == pt && board->get_spot_char(8) == pt) ||
      (board->get_spot_char(1) == pt && board->get_spot_char(4) == pt))
      {
        plyr->winner = true;
        std::cout << plyr->get_name() << " is the winner! 7\n";
      }
      break;
    case 8:
      if ((board->get_spot_char(2) == pt && board->get_spot_char(5) == pt) ||
      (board->get_spot_char(6) == pt && board->get_spot_char(7) == pt) ||
      (board->get_spot_char(0) == pt && board->get_spot_char(4) == pt))
      {
        plyr->winner = true;
        std::cout << plyr->get_name() << " is the winner! 8\n";
      }
      break;
  }
}
