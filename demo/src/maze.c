#include <stdio.h>
#include <stdlib.h>

#define H 7
#define W 11
#define ITERS 28

char maze[H][W] = {"+-+---+---+", "| |     |#|", "| | --+ | |", "| |   | | |",
                   "| +-- | | |", "|     |   |", "+-----+---+"};
char program[ITERS];

int x = 1, y = 1;   // Player position
int ox, oy; // Old player position
int iter = 0;


void win() {
  printf("You win!\n");
  printf("Your solution: %s\n", program);
  exit(0);
}


void lose() {
  printf("You lose...\n");
  exit(-1);
}


void draw() {
  int i, j;
  printf("Current position: (%d, %d)\n", y, x);
  printf("Iteration: %d / %d\n", iter, ITERS);
  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


void move(char program[ITERS]) {
  ox = x;
  oy = y;
  switch (program[iter]) {
  case 'w':
    y--;
    break;
  case 's':
    y++;
    break;
  case 'a':
    x--;
    break;
  case 'd':
    x++;
    break;
  default:
    printf("Only w,s,a,d accepted!)\n");
    lose();
  }
}


void status() {
  if (maze[y][x] == '#') {
    win();
  }
  if (maze[y][x] != ' ' &&
        !((y == 2 && maze[y][x] == '|' && x > 0 && x < W))) {
    x = ox;
    y = oy;
  }
  if (ox == x && oy == y) {
    lose();
  }
}


int main() {
  maze[y][x] = 'X';
  read(0, program, ITERS);

  while (iter < ITERS) {
    move(program);
    status();
    maze[y][x] = 'X';
    draw();
    iter++;
    sleep(1);
  }
  lose();
}
