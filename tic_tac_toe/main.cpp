#include <iostream>
#include "header.hpp"
#include <vector>

void print_commands() {
  std::cout << "\nto select a play square use:\n[tl][tm][tr]\n[ml][mm][mr]\n[bl][bm][mr]\n"
  << "to quit the game at anytime enter \"quit\"\n"
  << "to start the game enter \"play\"\n";
}

// checks to make sure the input is a valid location & returns the location number
int check_input(std::string inpt) {
  int i = 0;
  const char *valid_inputs[9] = {"tl", "tm", "tr", "ml", "mm", "mr", "bl", "bm", "br"};

  while (i < 9) {
    if (inpt == valid_inputs[i]) {
      return (i);
    }
    i++;
  }
  return (i);
}

bool player_turn(player *plyr, game_board *board) {
//  pl->add_turn();
//  b->print_board();
  //ask the player for a move
  std::string playerin;
  bool endturn = false;
  int chosen_loc;


// program is going into endless loop here
  while (!endturn) {
    std::cout << "Enter your play: ";
    std::cin >> playerin;
      //
      std::cout << "got player input\n";
      if (playerin == "quit" || playerin == "Quit") {
        std::cout << "first if\n";
        return (false);
        //exits and quits game
      }
      else if (playerin == "commands") {
        print_commands();
      }
      else {
        //check valid input
        chosen_loc = check_input(playerin);
        if (board->get_spot_char(chosen_loc) == ' ') {
          std::cout << "valid location\n";
          board->place_token(plyr->get_token(), chosen_loc);
          std::cout << "token placed\n";
          plyr->add_turn();
          std::cout << plyr->get_turns() << " turns taken\n";
          // here if player turn is > 3. check for a win from the last chosen loc
          // if there is a win set player->winner = true
          endturn = true;
          }
        else {
          std::cout << "invalid input\n";
        }
      }
    }
  // make sure that move isnt already taken
  //incriment player turns
  //place player turn on the board
  //if the player has played more than 3 turns. check for a win from the last plays position
  //if no win. exit the function return true;
  std::cout << "returning from playerturn\n";
  return (true);
}

void play_game() {
  int turn = 0;
  bool playing = true;

  player p1('x', "player 1");
  player p2('0', "player 2");
  game_board board;

  while (!p1.winner && !p2.winner && playing) {
    if (turn > 8) {
      std::cout << "Its a tie!";
      playing = false;
    }
    if (turn % 2 == 0 || turn == 0) {
      std::cout << p1.name << " it is your turn!\n:";
      playing = player_turn(&p1, &board);
    }
    else {
      std::cout << p2.name << " it is your turn!\n";
      playing = player_turn(&p2, &board);
    }
    board.print_board();
    turn++;
  }
}

int main(int argc, char const *argv[]) {
  std::string userin;
  bool playing = true;

/*
std::cout << "\n----------Welcome to Tic Tac Toe!-------------\n";
  while (playing) {
    std::cout << "\nFor a list of commands type \"commands\"\n"
    << "When you're ready to play enter play!\n"
    << "If you want to quit at any time enter quit\n";

    std::cin >> userin; // take the user input
    if (userin == "play" || userin == "Play") {
      playing = false;
      std::cout << "Starting game\n";
      //start code to play tic tac toe
      // this will break out the while loop
    }
    else if (userin == "commands" || userin == "Commands") {
      print_commands();
    }
    else if (userin == "quit" || userin == "Quit") {
      playing = false;
    }
    else {
      std::cout << "Enter one of the commands\n";
    }

  }
  */
// play testing
  game_board mygame_board;
  play_game();



  std::cout << "Thanks for playing.\n";
  return (0);
}
