#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <conio.h> // H? tr? _getch() b?t phím trên Windows

using namespace std;

// ??nh ngh?a các ký t? hi?n th? trong Maze
const char WALL_CHAR = '#';    // T??ng
const char PATH_CHAR = ' ';    // ???ng ?i
const char PLAYER_CHAR = 'P';  // Ng??i ch?i
const char START_CHAR = 'S';   // ?i?m b?t ??u
const char END_CHAR = 'E';     // ?i?m ?ích
const char ROUTE_BFS = '.';    // ???ng ?i t? gi?i b?ng BFS
const char ROUTE_DFS = '*';    // ???ng ?i t? gi?i b?ng DFS

// C?u trúc ?i?m t?a ??
struct Point {
    int r, c;
    bool operator==(const Point& o) const { return r == o.r && c == o.c; }
};

// ??nh ngh?a l?p ch?a thu?c tính và nguyên m?u hàm
class MazeGame {
private:
    int width, height; // Kích th??c mê cung
    vector<vector<char>> grid;
    Point start, target;
    Point player;

    int bfs_path_len;
    int dfs_path_len;

    // Ch??ng trình con b? tr? n?i b? (Private)
    void dfsGenerate(int r, int c);

public:
    // Nguyên m?u các ch??ng trình con x? lý (Public Prototypes)
    MazeGame(int w = 21, int h = 21);
    void setDifficulty(int w, int h);
    void generate();
    void display(const vector<vector<char>>& currentGrid);
    void displayCurrent();
    void play();
    void solveBFS(bool showVisual);
    void solveDFS(bool showVisual);
    void compareAlgorithms();
};

#endif // MAZEGAME_H