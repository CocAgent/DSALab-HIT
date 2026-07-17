// ============================================================
// structures.h
// Chua toan bo struct va khai bao ham (prototype)
// ============================================================
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <vector>
#include <string>
using namespace std;

// CONSTANTS — Hang so dung chung
const int WALL     = 1;   // Tuong
const int PATH     = 0;   // Duong di
const int SOLUTION = 2;   // Danh dau duong giai

// STRUCT: Cell — Mot o trong me cung
struct Cell {
    int row, col;

    bool operator==(const Cell& other) const {
        return row == other.row && col == other.col;
    }

    bool operator!=(const Cell& other) const {
        return !(*this == other);
    }

    // Can cho std::map
    bool operator<(const Cell& other) const {
        if (row != other.row) return row < other.row;
        return col < other.col;
    }
};

// STRUCT: Maze — Toan bo me cung
struct Maze {
    int rows, cols;
    vector<vector<int>> grid;   // 0=duong, 1=tuong
    Cell start;                  // O bat dau (S)
    Cell end;                    // O ket thuc (E)
    bool isGenerated;
};

// STRUCT: SolveResult — Ket qua giai me cung
struct SolveResult {
    vector<Cell> path;    // Danh sach o tu Start->End
    int cellsVisited;     // So o da tham
    bool found;           // Tim duoc duong khong?
    string algorithm;     // "BFS" hoac "DFS"
};

// PROTOTYPE — Khai bao ham
Maze initMaze(int rows, int cols);
void generateMaze(Maze& maze);
void printMaze(const Maze& maze);
void printMazeWithPath(const Maze& maze, const vector<Cell>& path);

SolveResult solveBFS(const Maze& maze);
SolveResult solveDFS(const Maze& maze);

bool isValid(const Maze& maze, int row, int col);
vector<Cell> getNeighbors(const Maze& maze, const Cell& cell);
void compareResults(const SolveResult& bfs, const SolveResult& dfs);

void showMenu();
int getValidInt(int minVal, int maxVal);

#endif // STRUCTURES_H
