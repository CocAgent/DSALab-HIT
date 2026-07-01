#include "structures.h"
#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <conio.h> 

using namespace std;

Maze::Maze(int h, int w) { resizeMaze(h, w); }

void Maze::resizeMaze(int h, int w) {
    if (h % 2 == 0) h++;
    if (w % 2 == 0) w++;
    height = h;
    width = w;
    grid.clear();
    grid.resize(height, vector<char>(width, '#'));
    initMaze();
    generateMazeDFS();
}

void Maze::initMaze() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = '#';
        }
    }
}

// DFS - Stack
void Maze::generateMazeDFS() {
    stack<Point> st;
    grid[1][1] = ' ';
    st.push({1, 1});

    while (!st.empty()) {
        Point current = st.top();
        vector<int> unvisitedNeighbors;

        for (int i = 0; i < 4; i++) {
            int nRow = current.r + dRow2[i];
            int nCol = current.c + dCol2[i];
            if (nRow > 0 && nRow < height - 1 && nCol > 0 && nCol < width - 1) {
                if (grid[nRow][nCol] == '#') unvisitedNeighbors.push_back(i);
            }
        }

        if (!unvisitedNeighbors.empty()) {
            int randDir = unvisitedNeighbors[rand() % unvisitedNeighbors.size()];
            grid[current.r + dRow2[randDir] / 2][current.c + dCol2[randDir] / 2] = ' ';
            int nextRow = current.r + dRow2[randDir];
            int nextCol = current.c + dCol2[randDir];
            grid[nextRow][nextCol] = ' ';
            st.push({nextRow, nextCol});
        } else {
            st.pop(); 
        }
    }
    grid[1][1] = 'S'; 
    grid[height - 2][width - 2] = 'E';
}

void Maze::printMaze(int playerR, int playerC) {
    system("cls");
    cout << "=== GAME ME CUNG (MAZE GAME) ===\n";
    cout << "S: Bat dau | E: Dich den | P: Nguoi choi | Duong di (* hoac .)\n\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == playerR && j == playerC) cout << "P "; 
            else if (grid[i][j] == '#') cout << char(219) << char(219); 
            else cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

void clearPath(vector<vector<char>>& g, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == '*' || g[i][j] == '.') g[i][j] = ' ';
        }
    }
}

// BFS - Queue
int Maze::solveBFS(bool silent) {
    clearPath(grid, height, width);
    queue<Point> q;
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    vector<vector<Point>> parent(height, vector<Point>(width, {-1, -1}));

    q.push({1, 1});
    visited[1][1] = true;
    bool found = false;
    int pathLength = 0;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.r == height - 2 && current.c == width - 2) { found = true; break; }

        for (int i = 0; i < 4; i++) {
            int nRow = current.r + dRow1[i];
            int nCol = current.c + dCol1[i];
            if (grid[nRow][nCol] != '#' && !visited[nRow][nCol]) {
                visited[nRow][nCol] = true;
                parent[nRow][nCol] = current;
                q.push({nRow, nCol});
            }
        }
    }

    if (found) {
        int currR = height - 2, currC = width - 2;
        while (!(currR == 1 && currC == 1)) {
            if (grid[currR][currC] != 'E' && !silent) grid[currR][currC] = '*';
            pathLength++;
            Point p = parent[currR][currC];
            currR = p.r; currC = p.c;
        }
        if (!silent) {
            printMaze();
            cout << "\n[+] BFS da tim thay duong NGAN NHAT!\n";
            cout << "    => So buoc di: " << pathLength << " buoc (Ky hieu '*').\n";
        }
        return pathLength;
    }
    return -1;
}

// DFS Pathfinding - Stack
int Maze::solveDFS(bool silent) {
    clearPath(grid, height, width);
    stack<Point> st;
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    vector<vector<Point>> parent(height, vector<Point>(width, {-1, -1}));

    st.push({1, 1});
    visited[1][1] = true;
    bool found = false;
    int pathLength = 0;

    while (!st.empty()) {
        Point current = st.top();
        st.pop();

        if (current.r == height - 2 && current.c == width - 2) { found = true; break; }

        for (int i = 0; i < 4; i++) {
            int nRow = current.r + dRow1[i];
            int nCol = current.c + dCol1[i];
            if (grid[nRow][nCol] != '#' && !visited[nRow][nCol]) {
                visited[nRow][nCol] = true;
                parent[nRow][nCol] = current;
                st.push({nRow, nCol});
            }
        }
    }

    if (found) {
        int currR = height - 2, currC = width - 2;
        while (!(currR == 1 && currC == 1)) {
            if (grid[currR][currC] != 'E' && !silent) grid[currR][currC] = '.';
            pathLength++;
            Point p = parent[currR][currC];
            currR = p.r; currC = p.c;
        }
        if (!silent) {
            printMaze();
            cout << "\n[+] DFS da tim thay duong di!\n";
            cout << "    => So buoc di: " << pathLength << " buoc (Ky hieu '.').\n";
        }
        return pathLength;
    }
    return -1;
}

// A* - Priority Queue
int Maze::solveAStar(bool silent) {
    clearPath(grid, height, width);
    priority_queue<AStarNode, vector<AStarNode>, greater<AStarNode>> pq;
    vector<vector<int>> gScore(height, vector<int>(width, 1e9)); 
    vector<vector<Point>> parent(height, vector<Point>(width, {-1, -1}));

    int targetR = height - 2, targetC = width - 2;
    gScore[1][1] = 0;
    int h = abs(1 - targetR) + abs(1 - targetC); 
    pq.push({1, 1, 0, h});
    
    bool found = false;
    int pathLength = 0;

    while (!pq.empty()) {
        AStarNode current = pq.top();
        pq.pop();

        if (current.r == targetR && current.c == targetC) { found = true; break; }

        for (int i = 0; i < 4; i++) {
            int nRow = current.r + dRow1[i];
            int nCol = current.c + dCol1[i];

            if (grid[nRow][nCol] != '#') {
                int tentative_gScore = gScore[current.r][current.c] + 1;
                if (tentative_gScore < gScore[nRow][nCol]) {
                    parent[nRow][nCol] = {current.r, current.c};
                    gScore[nRow][nCol] = tentative_gScore;
                    int heuristic = abs(nRow - targetR) + abs(nCol - targetC);
                    pq.push({nRow, nCol, tentative_gScore, tentative_gScore + heuristic});
                }
            }
        }
    }

    if (found) {
        int currR = targetR, currC = targetC;
        while (!(currR == 1 && currC == 1)) {
            if (grid[currR][currC] != 'E' && !silent) grid[currR][currC] = '*';
            pathLength++;
            Point p = parent[currR][currC];
            currR = p.r; currC = p.c;
        }
        if (!silent) {
            printMaze();
            cout << "\n[+] A* da tim thay duong NGAN NHAT!\n";
            cout << "    => So buoc di: " << pathLength << " buoc (Ky hieu '*').\n";
        }
        return pathLength;
    }
    return -1;
}

void Maze::playGame() {
    int pRow = 1, pCol = 1; 
    while (true) {
        printMaze(pRow, pCol);
        if (pRow == height - 2 && pCol == width - 2) {
            cout << "\nCHUC MUNG! Ban da tu giai duoc me cung!\n";
            break;
        }
        cout << "\nDung W/A/S/D de di chuyen. An 'Q' de thoat.\n";
        char move = _getch(); 

        int nextR = pRow, nextC = pCol;
        if (move == 'w' || move == 'W') nextR--;
        if (move == 's' || move == 'S') nextR++;
        if (move == 'a' || move == 'A') nextC--;
        if (move == 'd' || move == 'D') nextC++;
        if (move == 'q' || move == 'Q') break;

        if (grid[nextR][nextC] != '#') {
            pRow = nextR;
            pCol = nextC;
        }
    }
}