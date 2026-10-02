#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "conway.h"

void dump_field(int field[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(field[y][x] ? '#' : '.');
        }
        putchar('\n');
    }
}

int main(void) {
    int field[HEIGHT][WIDTH] = {0};

    srand((unsigned)time(NULL));

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            field[y][x] = (rand() % 100 < 25) ? ALIVE : DEAD;

    for (int gen = 0; gen < 200; gen++) {
        printf("\033[2J\033[H");
        printf("Generation %d\n", gen);
        dump_field(field);
        evolve(field);
        usleep(150000);
    }

    return 0;
}
