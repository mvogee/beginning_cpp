#include "header.hpp"
#include <iostream>

player::player(char player_token, std::string p_name) {
  token = player_token;
  name = p_name;
  winner = false;
  turns = 0;
}

char player::get_token() {
  return (token);
}

int player::get_turns() {
  return (turns);
}

void player::add_turn() {
  turns++;
}

player::~player() {

}
