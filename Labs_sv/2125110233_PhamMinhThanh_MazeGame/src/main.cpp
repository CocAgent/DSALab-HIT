#include <iostream>
#include <conio.h>
#include "maze.h"
#include "player.h"
#include "solver.h"

using namespace std;

void menu() {
    cout << "1. Choi game\n";
    cout << "2. BFS\n";
    cout << "3. DFS\n";
    cout << "4. Thoat\n";
}

int main() {
    Maze maze;
    maze.init();

    Player player(1, 1);
    Solver solver;

    while (true) {
        system("cls");
        menu();

        int choice;
        cin >> choice;

        if (choice == 1) {
            while (true) {
                maze.draw(player.x, player.y);

                if (maze.grid[player.y][player.x] == 'E') {
                    cout << "Win!\n";
                    _getch();
                    break;
                }

                char c = _getch();
                if (c == 'q') break;

                player.move(c, maze);
            }
        }
        else if (choice == 2) {
            auto p = solver.BFS(maze, 1, 1);
            cout << "BFS path: " << p.size() << endl;
            _getch();
        }
        else if (choice == 3) {
            auto p = solver.DFS(maze, 1, 1);
            cout << "DFS path: " << p.size() << endl;
            _getch();
        }
        else break;
    }
}