// ============================================================
// main.cpp
// Dieu khien menu va luong chuong trinh chinh
// ============================================================
#include "structures.h"
#include <iostream>
#include <limits>
using namespace std;

void showMenu() {
    cout << "\n+==============================+\n";
    cout << "|      MAZE GAME - DSA         |\n";
    cout << "|   2125110256_LamKhanhPhat    |\n";
    cout << "+==============================+\n";
    cout << "|  1. Tao me cung moi          |\n";
    cout << "|  2. Hien thi me cung         |\n";
    cout << "|  3. Giai bang BFS            |\n";
    cout << "|  4. Giai bang DFS            |\n";
    cout << "|  5. So sanh BFS vs DFS       |\n";
    cout << "|  0. Thoat                    |\n";
    cout << "+==============================+\n";
    cout << "  Chon: ";
}

int getValidInt(int minVal, int maxVal) {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail() || value < minVal || value > maxVal) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [!] Nhap lai (tu " << minVal << " den " << maxVal << "): ";
            continue;
        }
        break;
    }
    return value;
}

int main() {
    Maze maze; maze.isGenerated = false;
    SolveResult bfsResult, dfsResult;
    bool hasBFS = false, hasDFS = false;
    int choice;
    do {
        showMenu(); choice = getValidInt(0, 5);
        switch (choice) {
            case 1:
                cout << "  Nhap rows, cols (le, 5-31): ";
                maze = initMaze(getValidInt(5, 31), getValidInt(5, 31));
                generateMaze(maze); printMaze(maze);
                hasBFS = hasDFS = false; break;
            case 2: if (maze.isGenerated) printMaze(maze); break;
            case 3:
                if (maze.isGenerated) {
                    bfsResult = solveBFS(maze); hasBFS = true;
                    printMazeWithPath(maze, bfsResult.path);
                } break;
            case 4:
                if (maze.isGenerated) {
                    dfsResult = solveDFS(maze); hasDFS = true;
                    printMazeWithPath(maze, dfsResult.path);
                } break;
            case 5: if (hasBFS && hasDFS) compareResults(bfsResult, dfsResult); break;
        }
    } while (choice != 0);
    return 0;
}
