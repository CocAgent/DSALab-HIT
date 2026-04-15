#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>

using namespace std;

// ===== SIZE =====
const int WIDTH = 40;
const int HEIGHT = 20;

// ===== PLAYER =====
int playerX = 5;
int playerY = HEIGHT - 2;

int velocityY = 0;
bool onGround = true;

// ===== OBSTACLE =====
struct Obstacle {
    int x, y;
};

vector<Obstacle> obs;

// ===== GAME =====
int score = 0;
bool gameOver = false;

// ===== INIT =====
void init() {
    srand(time(0));
}

// ===== DRAW =====
void draw() {
    system("cls");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {

            bool printed = false;

            // player
            if (i == playerY && j == playerX) {
                cout << "P";
                printed = true;
            }

            // obstacle
            for (auto& o : obs) {
                if (o.x == j && o.y == i) {
                    cout << "X";
                    printed = true;
                }
            }

            if (!printed) {
                if (i == HEIGHT - 1) cout << "="; // ground
                else cout << " ";
            }
        }
        cout << endl;
    }

    cout << "Score: " << score << endl;
    cout << "W: Jump | A/D: Move" << endl;
}

// ===== INPUT =====
void input() {
    if (_kbhit()) {
        char key = _getch();

        if (key == 'a' && playerX > 0) playerX--;
        if (key == 'd' && playerX < WIDTH - 1) playerX++;

        if (key == 'w' && onGround) {
            velocityY = -3;
            onGround = false;
        }
    }
}

// ===== UPDATE =====
void update() {

    // gravity
    velocityY += 1;
    playerY += velocityY;

    if (playerY >= HEIGHT - 2) {
        playerY = HEIGHT - 2;
        velocityY = 0;
        onGround = true;
    }

    // move obstacles
    for (auto& o : obs) {
        o.x--;
    }

    // remove
    obs.erase(remove_if(obs.begin(), obs.end(),
        [](Obstacle o) { return o.x < 0; }),
        obs.end());

    // spawn
    if (rand() % 10 < 2) {
        obs.push_back({ WIDTH - 1, HEIGHT - 2 });
    }

    // collision
    for (auto& o : obs) {
        if (o.x == playerX && o.y == playerY) {
            gameOver = true;
        }
    }

    score++;
}

// ===== MAIN =====
int main() {
    init();

    while (!gameOver) {
        draw();
        input();
        update();
        Sleep(80);
    }

    system("cls");
    cout << "GAME OVER! Score: " << score << endl;

    return 0;
}
