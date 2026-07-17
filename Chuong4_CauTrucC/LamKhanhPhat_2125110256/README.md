#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

// ================= CONFIG =================
const int ROWS = 12;
const int COLS = 1000;
const int VIEW = 30;

// 0 empty, 1 ground, 2 breakable, 3 coin, 5 mystery
int gameMap[ROWS][COLS];

// ================= PLAYER =================
struct Player {
    float x, y;
    float vx, vy;
    bool onGround;
    float speedBuff = 1.0;
    float jumpBuff = 1.0;
    int coins = 0;
};

// ================= ENEMY =================
struct Enemy {
    float x, y;
    int dir;
};

// ================= GLOBAL =================
Player mario = { 2, 5, 0, 0, false };
vector<Enemy> enemies;

int cameraX = 0;
int lastSpawnX = 0;
int difficulty = 1;

// ================= MENU =================
void showMenu() {
    system("cls");
    cout << "===== MARIO GAME =====\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "Chon do kho: ";
    cin >> difficulty;

    if (difficulty < 1 || difficulty > 3)
        difficulty = 1;
}

void applyDifficulty() {
    if (difficulty == 1) {
        mario.speedBuff = 1.0;
        mario.jumpBuff = 1.2;
    }
    else if (difficulty == 2) {
        mario.speedBuff = 1.2;
        mario.jumpBuff = 1.0;
    }
    else {
        mario.speedBuff = 1.5;
        mario.jumpBuff = 0.9;
    }
}

// ================= MAP =================
void initMap() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            gameMap[i][j] = 0;

    for (int i = 9; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            gameMap[i][j] = 1;
}

// ================= UTIL =================
bool isSolid(int x, int y) {
    if (x < 0 || x >= COLS || y < 0 || y >= ROWS) return true;
    int t = gameMap[y][x];
    return (t == 1 || t == 2 || t == 5);
}

bool isEmpty(int x, int y) {
    if (x < 0 || x >= COLS || y < 0 || y >= ROWS) return false;
    return gameMap[y][x] == 0;
}

// ================= SPAWN =================
void spawnPlatform(int row, int col, int w) {
    for (int j = col; j < col + w && j < COLS; j++)
        gameMap[row][j] = 1;
}

void spawnHole(int col, int w) {
    for (int j = col; j < col + w && j < COLS; j++)
        for (int i = 9; i < ROWS; i++)
            gameMap[i][j] = 0;
}

void spawnCoin(int r, int c) {
    if (isEmpty(c, r)) gameMap[r][c] = 3;
}

void spawnBlock(int r, int c) {
    if (isEmpty(c, r)) gameMap[r][c] = 2;
}

void spawnMystery(int r, int c) {
    if (isEmpty(c, r)) gameMap[r][c] = 5;
}

void spawnEnemy(int x) {
    if (x < COLS) enemies.push_back({ (float)x, 8, -1 });
}

// ================= SPAWN CAMERA =================
void spawnByCamera() {
    if (cameraX > lastSpawnX) {

        lastSpawnX = cameraX + 6;

        int spawnCount = (difficulty == 1 ? 2 : difficulty == 2 ? 3 : 5);

        for (int i = 0; i < spawnCount; i++) {

            int x = cameraX + VIEW + rand() % 40;

            spawnPlatform(9, x, 6);
            int type = rand() % 5;

            if (type == 0) spawnHole(x + 2, difficulty);
            if (type == 1) spawnBlock(8, x + 2);
            if (type == 2) spawnCoin(8, x + 2);
            if (type == 3) spawnMystery(6, x + 2);
            if (type == 4) spawnEnemy(x + 3);
        }
    }
}

// ================= INTERACT =================
void interact() {
    int px = (int)(mario.x + 0.5);
    int py = (int)(mario.y + 0.5);

    if (px < 0 || px >= COLS || py < 0 || py >= ROWS) return;

    int& tile = gameMap[py][px];

    if (tile == 2) tile = 0;
    else if (tile == 3) { mario.coins++; tile = 0; }
    else if (tile == 5) {
        int r = rand() % 3;
        if (r == 0) mario.speedBuff = 1.5;
        else if (r == 1) mario.jumpBuff = 1.5;
        else mario.coins += 5;
        tile = 0;
    }
}

// ================= INPUT =================
void input() {
    if (GetAsyncKeyState('A') & 0x8000) mario.vx -= 0.2 * mario.speedBuff;
    if (GetAsyncKeyState('D') & 0x8000) mario.vx += 0.2 * mario.speedBuff;

    if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && mario.onGround) {
        mario.vy = -1.0 * mario.jumpBuff;
        mario.onGround = false;
    }
}

// ================= PHYSICS =================
void physics() {

    mario.vy += 0.25;
    if (mario.vy > 1.5) mario.vy = 1.5;

    float newY = mario.y + mario.vy;

    if (mario.vy > 0) {
        if (isSolid((int)mario.x, (int)newY + 1)) {
            mario.y = (int)newY;
            mario.vy = 0;
            mario.onGround = true;
        }
        else {
            mario.y = newY;
            mario.onGround = false;
        }
    }
    else {
        if (!isSolid((int)mario.x, (int)newY))
            mario.y = newY;
        else mario.vy = 0;
    }

    mario.vx *= 0.9;
    float newX = mario.x + mario.vx;

    if (!isSolid((int)newX, (int)mario.y))
        mario.x = newX;

    interact();

    if (mario.y >= ROWS - 1) {
        system("cls");
        cout << "GAME OVER (FALL)\n";
        exit(0);
    }
}

// ================= ENEMY =================
void updateEnemies() {
    int speed = (difficulty == 3 ? 2 : 1);

    for (auto& e : enemies) {

        int nx = e.x + e.dir * speed;

        if (isSolid(nx, e.y) || !isSolid(nx, e.y + 1))
            e.dir *= -1;
        else
            e.x = nx;
    }
}

// ================= COLLISION =================
void collision() {
    for (int i = 0; i < enemies.size(); i++) {
        auto& e = enemies[i];

        if ((int)mario.x == (int)e.x && (int)mario.y == (int)e.y) {

            if (mario.vy > 0) {
                enemies.erase(enemies.begin() + i);
                mario.vy = -0.8; 
                return;
            }
            else {
                system("cls");
                cout << "GAME OVER (ENEMY)\n";
                exit(0);
            }
        }
    }
}

// ================= CAMERA =================
void updateCamera() {
    cameraX = mario.x - VIEW / 2;

    if (cameraX < 0) cameraX = 0;
    if (cameraX > COLS - VIEW) cameraX = COLS - VIEW;
}

// ================= DRAW =================
void draw() {
    system("cls");

    for (int i = 0; i < ROWS; i++) {
        for (int j = cameraX; j < cameraX + VIEW; j++) {

            if ((int)mario.x == j && (int)mario.y == i) {
                cout << "M";
                continue;
            }

            bool enemy = false;
            for (auto& e : enemies) {
                if ((int)e.x == j && (int)e.y == i) {
                    cout << "E";
                    enemy = true;
                    break;
                }
            }

            if (!enemy) {
                switch (gameMap[i][j]) {
                case 1: cout << "#"; break;
                case 2: cout << "B"; break;
                case 3: cout << "$"; break;
                case 5: cout << "?"; break;
                default: cout << ".";
                }
            }
        }
        cout << "\n";
    }

    cout << "Coins: " << mario.coins << "\n";
}

// ================= MAIN =================
int main() {
    srand(time(0));

    showMenu();          // ⭐ menu
    applyDifficulty();   // ⭐ áp dụng

    initMap();

    while (true) {
        input();
        physics();
        updateEnemies();
        collision();
        updateCamera();
        spawnByCamera();
        draw();

        Sleep(50);
    }
}
