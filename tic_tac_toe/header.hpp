#include <string>

// game borad class (game_board.cpp)


class game_board {

  // game board is initialized.
  char board[9];

  public:
  game_board();
  int place_token(char token, int board_location);
  char get_spot_char(int board_location);
  void print_board();
  ~game_board();
};

class player {
  int turns;
  char token;

  public:
  bool winner;
  std::string name;
  player(char player_token, std::string p_name);
  void player_turn();
  char get_token();
  int get_turns();
  void add_turn();
  std::string get_name();
  ~player();
};


void win_conditions(player *plyr, game_board *board, int last_play);
