#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <string>
#include <limits>
#define NOMINMAX
#include <windows.h> // dùng cho màu + clear screen

using namespace std;

// ================= COLOR =================
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
}

// ================= MOVIE =================
struct Movie {
    string id;
    string name;
    string time;
};

// ================= DATA =================
vector<Movie> movieList;
unordered_map<string, Movie> movieMap;

int seats[10][10] = { 0 };

queue<string> bookingQueue;
stack<pair<int, int>> undoStack;

// ================= MENU =================
void printMenu() {
    cout << "\n=====================================\n";
    cout << "      HE THONG DAT VE RAP PHIM      \n";
    cout << "=====================================\n";
    cout << "1. Them phim\n";
    cout << "2. Xem danh sach phim\n";
    cout << "3. Dat ve\n";
    cout << "4. Huy ve (Undo)\n";
    cout << "5. Tim phim\n";
    cout << "0. Thoat\n";
    cout << "-------------------------------------\n";
    cout << "Nhap lua chon: ";
}

// ================= FUNCTIONS =================

// Thêm phim
void addMovie() {
    Movie m;
    cout << "Nhap ID: ";
    cin >> m.id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap ten phim: ";
    getline(cin, m.name);

    cout << "Nhap gio chieu: ";
    getline(cin, m.time);

    movieList.push_back(m);
    movieMap[m.id] = m;

    setColor(10);
    cout << "\n[+] Da them phim!\n";
    setColor(7);
}

// Hiển thị phim
void showMovies() {
    cout << "\n===== DANH SACH PHIM =====\n";
    for (auto m : movieList) {
        cout << m.id << " | " << m.name << " | " << m.time << endl;
    }
}

// Hiển thị ghế
void showSeats() {
    cout << "\n        MAN HINH CHIEU\n";
    cout << "===========================\n\n";

    cout << "   ";
    for (int j = 0; j < 10; j++) cout << j << " ";
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << i << "  ";
        for (int j = 0; j < 10; j++) {
            if (seats[i][j] == 0) {
                setColor(10); // xanh
                cout << "O ";
            }
            else {
                setColor(12); // đỏ
                cout << "X ";
            }
            setColor(7);
        }
        cout << endl;
    }

    cout << "\nO: Ghe trong | X: Da dat\n";
}

// Đặt vé
void bookTicket() {
    int x, y;
    showSeats();

    cout << "\nNhap hang (0-9): ";
    cin >> x;
    cout << "Nhap cot (0-9): ";
    cin >> y;

    if (x < 0 || x >= 10 || y < 0 || y >= 10) {
        setColor(12);
        cout << "\n[!] Vi tri khong hop le!\n";
        setColor(7);
        return;
    }

    if (seats[x][y] == 0) {
        seats[x][y] = 1;
        bookingQueue.push("Booked");
        undoStack.push({ x, y });

        setColor(10);
        cout << "\n[+] Dat ve thanh cong!\n";
    }
    else {
        setColor(12);
        cout << "\n[!] Ghe da duoc dat!\n";
    }
    setColor(7);
}

// Hủy vé
void cancelTicket() {
    if (!undoStack.empty()) {
        auto last = undoStack.top();
        undoStack.pop();

        seats[last.first][last.second] = 0;

        setColor(14);
        cout << "\n[~] Da huy ve gan nhat!\n";
    }
    else {
        setColor(12);
        cout << "\n[-] Khong co ve de huy!\n";
    }
    setColor(7);
}

// Tìm phim
void searchMovie() {
    string id;
    cout << "Nhap ID phim: ";
    cin >> id;

    if (movieMap.find(id) != movieMap.end()) {
        Movie m = movieMap[id];

        setColor(11);
        cout << "\nTim thay: " << m.name << " | " << m.time << endl;
    }
    else {
        setColor(12);
        cout << "\nKhong tim thay phim!\n";
    }
    setColor(7);
}

// ================= MAIN =================
int main() {
    int choice;

    do {
        clearScreen();
        printMenu();
        cin >> choice;

        clearScreen();

        switch (choice) {
        case 1: addMovie(); break;
        case 2: showMovies(); break;
        case 3: bookTicket(); break;
        case 4: cancelTicket(); break;
        case 5: searchMovie(); break;
        case 0: cout << "Thoat...\n"; break;
        default: cout << "Lua chon khong hop le!\n";
        }

        cout << "\nNhan phim bat ky de tiep tuc...";
        cin.ignore();
        cin.get();

    } while (choice != 0);

    return 0;
}