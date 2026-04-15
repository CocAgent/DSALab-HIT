#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int ROW = 10;
const int COL = 20;

char maze[ROW][COL] = {
    "###################",
    "#S....#.........#E#",
    "#.##.#.#.#####.#..#",
    "#....#.#.....#.#..#",
    "####.#.#####.#.#..#",
    "#....#.....#.#....#",
    "#.#########.#.##..#",
    "#...........#.....#",
    "#.###############.#",
    "###################"
};

int playerX = 1, playerY = 1;

// Hiển thị mê cung
void drawMaze() {
    system("cls"); // Windows
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == playerX && j == playerY)
                cout << "P";
            else
                cout << maze[i][j];
        }
        cout << endl;
    }
}

// Di chuyển
void movePlayer(char dir) {
    int newX = playerX;
    int newY = playerY;

    if (dir == 'w') newX--;
    if (dir == 's') newX++;
    if (dir == 'a') newY--;
    if (dir == 'd') newY++;

    if (maze[newX][newY] != '#') {
        playerX = newX;
        playerY = newY;
    }

    if (maze[playerX][playerY] == 'E') {
        drawMaze();
        cout << "\nYOU WIN!\n";
        exit(0);
    }
}

void showInstructions() {
    cout << "===== MAZE GAME =====\n";
    cout << "Ky hieu:\n";
    cout << "# : Tuong\n";
    cout << ". : Duong di\n";
    cout << "S : Start\n";
    cout << "E : Exit\n";
    cout << "P : Nguoi choi\n\n";

    cout << "Dieu khien:\n";
    cout << "W - Di len\n";
    cout << "S - Di xuong\n";
    cout << "A - Di trai\n";
    cout << "D - Di phai\n\n";

    cout << "Muc tieu: Tim duong tu S den E\n";
    cout << "Nhan phim bat ky de bat dau...\n";

    cin.ignore();
    cin.get();
}
int main() {
    showInstructions();
    char input;

    while (true) {
        drawMaze();
        cout << "\nMove (W/A/S/D): ";
        cin >> input;
        movePlayer(tolower(input));
    }

    return 0;
}
