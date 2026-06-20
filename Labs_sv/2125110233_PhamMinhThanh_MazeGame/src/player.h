#pragma once
#include "maze.h"

class Player {
public:
    int x, y;

    Player(int startX, int startY);
    void move(char input, Maze& maze);
};
