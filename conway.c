#include "conway.h"

int count_alive(int field[HEIGHT][WIDTH], int x, int y) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int nx = x + i;
            int ny = y + j;

            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                count += field[ny][nx];
            }
        }
    }

    return count;
}

void evolve(int field[HEIGHT][WIDTH]) {
    int new_field[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int n = count_alive(field, x, y);

            if (field[y][x] == ALIVE) {
                new_field[y][x] = (n == 2 || n == 3) ? ALIVE : DEAD;
            } else {
                new_field[y][x] = (n == 3) ? ALIVE : DEAD;
            }
        }
    }

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            field[y][x] = new_field[y][x];
}

