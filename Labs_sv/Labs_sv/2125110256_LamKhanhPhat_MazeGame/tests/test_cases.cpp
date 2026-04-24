// ============================================================
// test_cases.cpp
// File test doc lap kiem tra tung chuc nang
// ============================================================
#include "structures.h"
#include <iostream>
using namespace std;

void test_createMaze() {
    Maze maze = initMaze(11, 11);
    generateMaze(maze);
    cout << "Test Tao Maze: " << (maze.isGenerated ? "PASS" : "FAIL") << "\n";
}

void test_Solvers() {
    Maze maze = initMaze(11, 11);
    generateMaze(maze);
    SolveResult bfs = solveBFS(maze);
    SolveResult dfs = solveDFS(maze);
    cout << "Test BFS: " << (bfs.found ? "PASS" : "FAIL") << "\n";
    cout << "Test DFS: " << (dfs.found ? "PASS" : "FAIL") << "\n";
}

int main() {
    cout << "--- RUNNING TESTS ---\n";
    test_createMaze();
    test_Solvers();
    return 0;
}
