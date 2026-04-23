#include "player.h"

Player::Player(int startX, int startY) {
    x = startX;
    y = startY;
}

void Player::move(char input, Maze& maze) {
    int nx = x;
    int ny = y;

    if (input == 'w') ny--;
    if (input == 's') ny++;
    if (input == 'a') nx--;
    if (input == 'd') nx++;

    if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
        if (!maze.isWall(nx, ny)) {
            x = nx;
            y = ny;
        }
    }
}