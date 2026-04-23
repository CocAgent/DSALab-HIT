#pragma once
#include <vector>
#include "maze.h"
using namespace std;

class Solver {
public:
    vector<pair<int, int>> BFS(Maze& maze, int sx, int sy);
    vector<pair<int, int>> DFS(Maze& maze, int sx, int sy);
};
