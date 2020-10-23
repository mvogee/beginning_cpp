#include <iostream>

char gamemap[10][10] = {
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '} ,
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '} ,
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '} ,
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '} ,
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '} ,
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '} ,
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '} ,
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '} ,
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '} ,
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '}
};

void print_map() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << gamemap[i][j];
    }
    std::cout << "\n";
  }
}

void seed_blinker() {
  char line[3] = {'#', '#', '#'};
  for (int i = 0; i < 3; i++) {
    gamemap[0][i] = line[i];
  }
}
void seed_block() {
  char block[2][2] = { {'#','#'}, {'#', '#'}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++)
      gamemap[i][j] = block[i][j];
  }
}
void seed_glider() {
  char glider[3][3] = {{' ', '#', ' '},{' ', ' ', '#'},{'#','#','#'}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      gamemap[i][j] = glider[i][j];
  }
}

void seed_life(int type) {
  switch (type) {
    case 1:
      seed_blinker();
      break;
    case 2:
      seed_block();
      break;
    case 3:
      seed_glider();
      break;
  }
}

void game_of_life() {
  
}

int main(int argc, char const *argv[]) {
  seed_life(3);
  print_map();
  for (int itterations = 0; itterations != 10; itterations++) {
    game_of_life();
    print_map();
  }
  // print the map
  // update life on the map
  return 0;
}
