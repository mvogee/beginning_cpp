#include <iostream>
#include "header.hpp"

game_board::game_board(){
  // initialize the game board array
  for (int i = 0; i < 9; i++) {
    board[i] = ' ';
  }
}

//place token in the array in the board location (0 - 8)
// will return 1 if succesful. 0 if fails
int game_board::place_token(char token, int board_location) {
  if (board_location >= 0 && board_location <= 8) {
    board[board_location] = token;
    return (1);
  }
  else {
    return (0);
  }
}

char game_board::get_spot_char(int board_location){
  return (board[board_location]);
}

// print out the game board
void game_board::print_board() {
  std::cout << "\n " << board[0] << " | " << board[1] << " | " << board[2] << " \n-----------\n"
  << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n-----------\n"
  << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}


//class destructor
game_board::~game_board() {
  std::cout << "Game board freed\n";
}
