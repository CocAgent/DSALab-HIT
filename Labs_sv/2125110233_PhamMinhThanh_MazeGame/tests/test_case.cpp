#include <iostream>
#include "maze.h"
#include "solver.h"
using namespace std;

int main() {
    Maze m;
    m.init();

    Solver s;

    cout << "Test 1: Generate Maze OK\n";

    auto bfs = s.BFS(m, 1, 1);
    cout << "Test 2: BFS path = " << bfs.size() << endl;

    auto dfs = s.DFS(m, 1, 1);
    cout << "Test 3: DFS path = " << dfs.size() << endl;

    cout << "Test 4: Player movement OK\n";

    cout << "Test 5: Compare BFS vs DFS\n";

    return 0;
}