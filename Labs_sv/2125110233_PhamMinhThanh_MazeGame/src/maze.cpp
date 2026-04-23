#include "maze.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <random>

void Maze::init() {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            grid[i][j] = '#';

    srand(time(0));

    grid[1][1] = ' ';
    generateDFS(1, 1);

    grid[HEIGHT - 2][WIDTH - 2] = 'E';
}

void Maze::draw(int playerX, int playerY) {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == playerY && j == playerX)
                cout << 'P';
            else
                cout << grid[i][j];
        }
        cout << endl;
    }
}

bool Maze::isWall(int x, int y) {
    return grid[y][x] == '#';
}

void Maze::generateDFS(int x, int y) {
    vector<pair<int, int>> dirs = {
        {0,-2},{0,2},{-2,0},{2,0}
    };

    shuffle(dirs.begin(), dirs.end(), std::mt19937(std::random_device()()));

    for (auto [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx > 0 && nx < WIDTH - 1 && ny > 0 && ny < HEIGHT - 1) {
            if (grid[ny][nx] == '#') {
                grid[y + dy / 2][x + dx / 2] = ' ';
                grid[ny][nx] = ' ';
                generateDFS(nx, ny);
            }
        }
    }
}