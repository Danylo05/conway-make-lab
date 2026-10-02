#ifndef CONWAY_H
#define CONWAY_H

#define WIDTH 80
#define HEIGHT 40
#define ALIVE 1
#define DEAD 0

int count_alive(int field[HEIGHT][WIDTH], int x, int y);
void evolve(int field[HEIGHT][WIDTH]);

#endif

