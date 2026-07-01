#include "MazeGam.h"

int main() {
    MazeGame game(21, 21);

    while (true) {
        system("cls");
        cout << "==================================================\n";
        cout << "         PROJECT: GAME ME CUNG (MAZE GAME)        \n";
        cout << "   Sinh vien thuc hien: BUI VAN NAM - 2125110145  \n";
        cout << "==================================================\n";
        cout << "1. Khoi tao lai me cung moi (Ngau nhien)\n";
        cout << "2. In trang thai me cung hien tai ra man hinh\n";
        cout << "3. Vao che do choi thu cong (Co ho tro HOAN TAC - UNDO)\n";
        cout << "4. Chay Giai thuat BFS (Tim duong ngan nhat)\n";
        cout << "5. Chay Giai thuat DFS (Mop phong doi tim)\n";
        cout << "6. Phan tich & So sanh chi phi: BFS vs DFS\n";
        cout << "7. Thay doi size / Thiet lap do kho me cung\n";
        cout << "8. [BONUS] Luu me cung hien tai vao file txt\n";
        cout << "9. [BONUS] Doc va Nap lai me cung cu tu file txt\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "==================================================\n";
        cout << "Nhap lua chon cua ban: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
            case 1:
                game.generate();
                cout << "\nDa cap nhat me cung ngau nhien! Bam phim bat ky...";
                _getch();
                break;
            case 2:
                game.displayCurrent();
                cout << "\nNhan phim bat ky de ve Menu...";
                _getch();
                break;
            case 3:
                game.play();
                break;
            case 4:
                game.solveBFS(true);
                break;
            case 5:
                game.solveDFS(true);
                break;
            case 6:
                game.compareAlgorithms();
                break;
            case 7: {
                int w, h;
                cout << "Nhap chieu rong (so le >= 11): "; cin >> w;
                cout << "Nhap chieu cao (so le >= 11): "; cin >> h;
                game.setDifficulty(w, h);
                cout << "\nThay doi size thanh cong! Bam phim bat ky...";
                _getch();
                break;
            }
            case 8:
                game.saveToFile("maze_data.txt");
                break;
            case 9:
                if (game.loadFromFile("maze_data.txt")) {
                    cout << "\n[OK] Nap du lieu me cung tu file thanh cong! Bam phim bat ky...";
                } else {
                    cout << "\n[LOI] Chua co file du lieu hoac khong mo duoc file!";
                }
                _getch();
                break;
            default:
                cout << "\nLua chon sai. Vui long nhap lai!";
                _getch();
        }
    }
    return 0;
}
