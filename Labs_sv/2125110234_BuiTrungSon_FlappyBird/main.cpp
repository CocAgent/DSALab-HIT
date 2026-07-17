#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

// --- CẤU TRÚC DỮ LIỆU (DSA) ---
struct Pipe {
    int x, gapY, gapSize; // gapSize: Độ rộng khe hở ngẫu nhiên
    Pipe* next;
    Pipe(int _x, int _y, int _size) : x(_x), gapY(_y), gapSize(_size), next(nullptr) {}
};

struct PipeQueue {
    Pipe* front, * rear;
    PipeQueue() : front(nullptr), rear(nullptr) {}
    void enqueue(int x, int y, int size) {
        Pipe* newNode = new Pipe(x, y, size);
        if (!rear) front = rear = newNode;
        else { rear->next = newNode; rear = newNode; }
    }
    void dequeue() {
        if (!front) return;
        Pipe* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }
    void clear() { while (front) dequeue(); }
};

struct Obstacle {
    int x, y;
};

// --- HÀM HỆ THỐNG & GIAO DIỆN ---
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoXY(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void manHinhLoading() {
    system("cls");
    cout << "\n\n\n\t\t" << "DANG KHOI TAO HE THONG..." << endl;
    cout << "\t\t";
    for (int i = 0; i <= 25; i++) {
        setColor(10); cout << (char)219;
        Sleep(40);
    }
    setColor(15); cout << " 100%" << endl;
    Sleep(500);
}

// --- QUẢN LÝ ĐIỂM KỶ LỤC (FILE I/O) ---
void luuDiem(int score) {
    ofstream f("highscore.txt", ios::app);
    if (f.is_open()) { f << score << endl; f.close(); }
}

void hienThiKyLuc() {
    vector<int> scores;
    ifstream f("highscore.txt");
    int s;
    while (f >> s) scores.push_back(s);
    f.close();
    sort(scores.rbegin(), scores.rend());
    system("cls");
    setColor(11); cout << "=== BANG XEP HANG KY LUC ===\n\n";
    setColor(15);
    for (int i = 0; i < (int)scores.size() && i < 5; i++)
        cout << "  HANG " << i + 1 << ": " << scores[i] << " diem\n";
    if (scores.empty()) cout << "  Chua co du lieu ky luc.\n";
    setColor(14); cout << "\nNhan phim bat ky de quay lai menu...";
    _getch();
}

// --- CHƯƠNG TRÌNH CHÍNH ---
int main() {
    srand((unsigned int)time(NULL));
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
    ci.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);

    manHinhLoading();

    while (true) {
        system("cls");
        setColor(11);
        cout << "=================================\n";
        cout << "   GAME FLAPPY BIRD - DO AN DSA  \n";
        cout << "=================================\n";
        setColor(15);
        cout << " 1. Bat dau choi\n";
        cout << " 2. Bang xep hang\n";
        cout << " 0. Thoat\n";
        cout << "---------------------------------\n";
        cout << " Lua chon cua ban: ";
        char mn = _getch();

        if (mn == '0') break;
        if (mn == '2') { hienThiKyLuc(); continue; }
        if (mn != '1') continue;

        system("cls");
        cout << "Chon do kho (1: De, 2: Vua, 3: Kho): ";
        int lv;
        if (!(cin >> lv)) lv = 1;

        int speed = (lv == 1) ? 180 : (lv == 2 ? 120 : 80);

        int bY = 10, bX = 5, score = 0, frame = 0;
        float vel = 0;
        bool gOver = false, started = false;
        PipeQueue pipes;

        // Khoi tao ong dau tien voi gapSize ngau nhien tu 5-7
        pipes.enqueue(35, rand() % 6 + 3, rand() % 3 + 5);
        vector<Obstacle> obsList;

        while (!gOver) {
            gotoXY(0, 0);
            setColor(11); cout << " DIEM: "; setColor(14); cout << score << "  ";
            if (!started) { setColor(15); cout << "| NHAN [SPACE] DE NHAY! "; }
            else cout << "                         ";

            for (int i = 0; i < 20; i++) {
                gotoXY(0, i + 1);
                for (int j = 0; j < 40; j++) {
                    if (i == 0 || i == 19) { setColor(11); cout << "="; }
                    else if (j == 0 || j == 39) { setColor(15); cout << "|"; }
                    else {
                        bool drawn = false;
                        if (i == bY && j == bX) {
                            setColor(14); cout << ">";
                            drawn = true;
                        }
                        if (!drawn) {
                            for (auto& ob : obsList) {
                                if (ob.x == j && ob.y == i) {
                                    setColor(12); cout << "*";
                                    drawn = true; break;
                                }
                            }
                        }
                        if (!drawn) {
                            Pipe* p = pipes.front;
                            while (p) {
                                // Ve ong dua tren vi tri gapY va gapSize ngau nhien cua rieng ong do
                                if (p->x == j && (i < p->gapY || i > p->gapY + p->gapSize)) {
                                    setColor(10); cout << "H";
                                    drawn = true; break;
                                }
                                p = p->next;
                            }
                        }
                        if (!drawn) cout << " ";
                    }
                }
                cout << "\n";
            }

            if (!started) {
                if (_kbhit()) { if (_getch() == ' ') started = true; }
                continue;
            }

            if (_kbhit()) {
                char c = _getch();
                if (c == ' ') { vel = -1.5; Beep(450, 20); }
            }
            vel += 0.35;
            bY += (int)vel;

            Pipe* currP = pipes.front;
            while (currP) { currP->x--; currP = currP->next; }
            for (auto& o : obsList) o.x -= 2;

            if (++frame % 25 == 0) {
                // Enqueue ong moi voi vi tri khe ho ngau nhien va do rong khe ho ngau nhien (5-7)
                int randomGapY = rand() % 6 + 3;
                int randomGapSize = rand() % 3 + 5;
                pipes.enqueue(38, randomGapY, randomGapSize);

                if (rand() % 10 < 2) obsList.push_back({ 38, rand() % 16 + 1 });
            }

            if (pipes.front && pipes.front->x < 0) { pipes.dequeue(); score++; }
            for (int i = 0; i < (int)obsList.size(); i++) {
                if (obsList[i].x < 0) { obsList.erase(obsList.begin() + i); i--; }
            }

            if (bY <= 0 || bY >= 19) gOver = true;
            Pipe* pCheck = pipes.front;
            while (pCheck) {
                // Kiem tra va cham dua tren gapSize rieng biet cua tung ong
                if (pCheck->x == bX && (bY < pCheck->gapY || bY > pCheck->gapY + pCheck->gapSize)) gOver = true;
                pCheck = pCheck->next;
            }
            for (auto& o : obsList) { if (o.x == bX && o.y == bY) gOver = true; }

            Sleep(speed);
        }

        Beep(300, 400);
        luuDiem(score);
        gotoXY(10, 10); setColor(12); cout << "TRO CHOI KET THUC! DIEM: " << score;
        gotoXY(8, 12); setColor(15); cout << "Nhan phim bat ky de ve Menu...";
        _getch();
    }
    return 0;
}
