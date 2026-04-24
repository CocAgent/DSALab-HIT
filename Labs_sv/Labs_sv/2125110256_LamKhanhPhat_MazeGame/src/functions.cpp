// ============================================================
// functions.cpp
// Cai dat tat ca cac ham khai bao trong structures.h
// ============================================================
#include "structures.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

Maze initMaze(int rows, int cols) {
    Maze maze;
    if (rows % 2 == 0) rows++;
    if (cols % 2 == 0) cols++;
    maze.rows = rows;
    maze.cols = cols;
    maze.grid.assign(rows, vector<int>(cols, WALL));
    maze.start = {1, 1};
    maze.end   = {rows - 2, cols - 2};
    maze.isGenerated = false;
    return maze;
}

bool isValid(const Maze& maze, int row, int col) {
    return (row >= 0 && row < maze.rows &&
            col >= 0 && col < maze.cols &&
            maze.grid[row][col] == PATH);
}

vector<Cell> getNeighbors(const Maze& maze, const Cell& cell) {
    vector<Cell> neighbors;
    int dr[] = {-1, 1,  0, 0};
    int dc[] = { 0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int newRow = cell.row + dr[i];
        int newCol = cell.col + dc[i];
        if (isValid(maze, newRow, newCol)) {
            neighbors.push_back({newRow, newCol});
        }
    }
    return neighbors;
}

void generateMaze(Maze& maze) {
    srand((unsigned int)time(nullptr));
    for (int r = 0; r < maze.rows; r++)
        for (int c = 0; c < maze.cols; c++)
            maze.grid[r][c] = WALL;

    vector<vector<bool>> visited(maze.rows, vector<bool>(maze.cols, false));
    stack<Cell> stk;
    Cell startCell = {1, 1};
    maze.grid[1][1] = PATH;
    visited[1][1]   = true;
    stk.push(startCell);

    while (!stk.empty()) {
        Cell current = stk.top();
        vector<Cell> unvisited;
        int dr[] = {-2, 2,  0, 0};
        int dc[] = { 0, 0, -2, 2};
        for (int i = 0; i < 4; i++) {
            int nr = current.row + dr[i];
            int nc = current.col + dc[i];
            if (nr > 0 && nr < maze.rows - 1 && nc > 0 && nc < maze.cols - 1 && !visited[nr][nc]) {
                unvisited.push_back({nr, nc});
            }
        }
        if (!unvisited.empty()) {
            int randIdx = rand() % unvisited.size();
            Cell next = unvisited[randIdx];
            int wallRow = (current.row + next.row) / 2;
            int wallCol = (current.col + next.col) / 2;
            maze.grid[wallRow][wallCol] = PATH;
            maze.grid[next.row][next.col] = PATH;
            visited[next.row][next.col] = true;
            stk.push(next);
        } else {
            stk.pop();
        }
    }
    maze.grid[maze.start.row][maze.start.col] = PATH;
    maze.grid[maze.end.row][maze.end.col]     = PATH;
    maze.isGenerated = true;
}

void printMaze(const Maze& maze) {
    cout << "\n";
    for (int r = 0; r < maze.rows; r++) {
        for (int c = 0; c < maze.cols; c++) {
            if (r == maze.start.row && c == maze.start.col) cout << "S ";
            else if (r == maze.end.row && c == maze.end.col) cout << "E ";
            else if (maze.grid[r][c] == WALL) cout << "# ";
            else cout << "  ";
        }
        cout << "\n";
    }
}

void printMazeWithPath(const Maze& maze, const vector<Cell>& path) {
    vector<vector<int>> display = maze.grid;
    for (const Cell& c : path) display[c.row][c.col] = SOLUTION;
    cout << "\n";
    for (int r = 0; r < maze.rows; r++) {
        for (int c = 0; c < maze.cols; c++) {
            if (r == maze.start.row && c == maze.start.col) cout << "S ";
            else if (r == maze.end.row && c == maze.end.col) cout << "E ";
            else if (display[r][c] == WALL) cout << "# ";
            else if (display[r][c] == SOLUTION) cout << ". ";
            else cout << "  ";
        }
        cout << "\n";
    }
}

SolveResult solveBFS(const Maze& maze) {
    SolveResult result;
    result.found = false; result.cellsVisited = 0; result.algorithm = "BFS";
    vector<vector<bool>> visited(maze.rows, vector<bool>(maze.cols, false));
    map<Cell, Cell> parent;
    queue<Cell> q;
    q.push(maze.start);
    visited[maze.start.row][maze.start.col] = true;
    while (!q.empty()) {
        Cell current = q.front(); q.pop();
        result.cellsVisited++;
        if (current == maze.end) { result.found = true; break; }
        for (const Cell& next : getNeighbors(maze, current)) {
            if (!visited[next.row][next.col]) {
                visited[next.row][next.col] = true;
                parent[next] = current;
                q.push(next);
            }
        }
    }
    if (result.found) {
        Cell cur = maze.end;
        while (cur != maze.start) { result.path.push_back(cur); cur = parent[cur]; }
        result.path.push_back(maze.start);
        reverse(result.path.begin(), result.path.end());
    }
    return result;
}

SolveResult solveDFS(const Maze& maze) {
    SolveResult result;
    result.found = false; result.cellsVisited = 0; result.algorithm = "DFS";
    vector<vector<bool>> visited(maze.rows, vector<bool>(maze.cols, false));
    map<Cell, Cell> parent;
    stack<Cell> stk;
    stk.push(maze.start);
    visited[maze.start.row][maze.start.col] = true;
    while (!stk.empty()) {
        Cell current = stk.top(); stk.pop();
        result.cellsVisited++;
        if (current == maze.end) { result.found = true; break; }
        for (const Cell& next : getNeighbors(maze, current)) {
            if (!visited[next.row][next.col]) {
                visited[next.row][next.col] = true;
                parent[next] = current;
                stk.push(next);
            }
        }
    }
    if (result.found) {
        Cell cur = maze.end;
        while (cur != maze.start) { result.path.push_back(cur); cur = parent[cur]; }
        result.path.push_back(maze.start);
        reverse(result.path.begin(), result.path.end());
    }
    return result;
}

void compareResults(const SolveResult& bfs, const SolveResult& dfs) {
    cout << "\n+================+=============+=============+\n";
    cout << "| Tieu chi       |     BFS     |     DFS     |\n";
    cout << "+================+=============+=============+\n";
    cout << "| Do dai duong   | " << bfs.path.size() << " buoc      | " << dfs.path.size() << " buoc      |\n";
    cout << "| So o da tham   | " << bfs.cellsVisited << " o         | " << dfs.cellsVisited << " o         |\n";
    cout << "+================+=============+=============+\n";
}
