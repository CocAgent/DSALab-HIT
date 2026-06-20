#pragma once
#include <iostream>
#include <vector>
using namespace std;

const int WIDTH = 21;
const int HEIGHT = 21;

class Maze {
public:
    char grid[HEIGHT][WIDTH];

    void init();
    void draw(int playerX, int playerY);
    bool isWall(int x, int y);

    void generateDFS(int x, int y);
};
