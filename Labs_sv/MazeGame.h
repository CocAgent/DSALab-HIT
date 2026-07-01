#ifndef MAZEGAM_H
#define MAZEGAM_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

// Quy ước ký hiệu ma trận ASCII
const char WALL_CHAR = '#';    
const char PATH_CHAR = ' ';    
const char PLAYER_CHAR = 'P';  
const char START_CHAR = 'S';   
const char END_CHAR = 'E';     
const char ROUTE_BFS = '.';    
const char ROUTE_DFS = '*';    

// Tọa độ điểm
struct Point {
    int r, c;
    bool operator==(const Point& o) const { return r == o.r && c == o.c; }
};

// =========================================================================
// [CTDL 1]: CUSTOM LINKED LIST - Danh sách liên kết đơn tự chế để làm Undo
// =========================================================================
struct HistoryNode {
    Point pos;
    HistoryNode* next;
    HistoryNode(Point p) : pos(p), next(nullptr) {}
};

class MazeGame {
private:
    // [CTDL 2]: 2D Array / Vector biểu diễn đồ thị ma trận lưới mê cung
    int width, height;
    vector<vector<char>> grid;
    Point start, target;
    Point player;

    int bfs_path_len;
    int dfs_path_len;

    // Quản lý đầu Danh sách liên kết đơn (History Undo)
    HistoryNode* historyHead;

    // Các hàm nội bộ bổ trợ
    void dfsGenerate(int r, int c);
    void pushHistory(Point p);
    Point popHistory();
    void clearHistory();

public:
    MazeGame(int w = 21, int h = 21);
    ~MazeGame(); // Destructor giải phóng bộ nhớ Linked List

    void setDifficulty(int w, int h);
    void generate();
    void display(const vector<vector<char>>& currentGrid);
    void displayCurrent();
    void play();
    
    // [CTDL 3 & 4]: Xử lý giải thuật bằng Queue (BFS) và Stack (DFS)
    void solveBFS(bool showVisual);
    void solveDFS(bool showVisual);
    void compareAlgorithms();

    // Chức năng nâng cao: Đọc/Ghi File
    void saveToFile(const string& filename);
    bool loadFromFile(const string& filename);

    // Getters bổ trợ cho file kiểm thử (Test Cases)
    int getBFSPathLen() { return bfs_path_len; }
    int getDFSPathLen() { return dfs_path_len; }
    bool isWall(int r, int c) { return grid[r][c] == WALL_CHAR; }
};

#endif
