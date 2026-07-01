#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <vector>

// Cấu trúc lưu tọa độ (r: dòng, c: cột) của một ô
struct Point {
    int r, c;
};

// Cấu trúc Node dành riêng cho thuật toán A* (Priority Queue)
struct AStarNode {
    int r, c;
    int g; // Chi phí thực tế (số bước)
    int f; // Tổng chi phí dự đoán: f = g + h
    
    // Nạp chồng toán tử > để Min-Heap sắp xếp f nhỏ nhất lên đầu
    bool operator>(const AStarNode& other) const {
        return f > other.f;
    }
};

// Class Quản lý Mê cung (Áp dụng 2D Array/Graph)
class Maze {
private:
    int height;
    int width;
    std::vector<std::vector<char>> grid;

    int dRow2[4] = {-2, 0, 2, 0};
    int dCol2[4] = {0, 2, 0, -2};
    
    int dRow1[4] = {-1, 0, 1, 0};
    int dCol1[4] = {0, 1, 0, -1};

public:
    Maze(int h, int w);
    void resizeMaze(int h, int w);
    void initMaze();
    void generateMazeDFS(); 
    void printMaze(int playerR = -1, int playerC = -1);
    
    int solveBFS(bool silent = false);   // Dùng Queue
    int solveDFS(bool silent = false);   // Dùng Stack
    int solveAStar(bool silent = false); // Dùng Priority Queue
    
    void playGame();
};

#endif // STRUCTURES_H