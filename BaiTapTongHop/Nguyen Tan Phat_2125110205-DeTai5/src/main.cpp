#include "structures.h"

int main() {
    // Khoi tao me cung mac dinh kich thuoc 21x21
    MazeGame game(21, 21);

    while (true) {
        system("cls");
        cout << "==================================================\n";
        cout << "               CHUONG TRINH MAZE GAME               \n";
        cout << "==================================================\n";
        cout << "1. Tao lai me cung ngau nhien (DFS Backtracker)\n";
        cout << "2. Hien thi me cung ASCII\n";
        cout << "3. Tu choi (Phim W/A/S/D)\n";
        cout << "4. Tu dong giai bang BFS (Duong ngan nhat)\n";
        cout << "5. Tu dong giai bang DFS (Hien thi hanh trinh)\n";
        cout << "6. So sanh: BFS vs DFS\n";
        cout << "7. Dieu chinh do kho (Kich thuoc me cung)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "==================================================\n";
        cout << "Lua chon cua ban: ";

        int choice;
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1:
            game.generate();
            cout << "\nDa cap nhat va tao me cung moi ngau nhien! Nhan bat ky de tiep tuc...";
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
            cout << "Nhap chieu rong mong muon (Khuyen nghi so le >= 11): ";
            cin >> w;
            cout << "Nhap chieu cao mong muon (Khuyen nghi so le >= 11): ";
            cin >> h;
            game.setDifficulty(w, h);
            cout << "\nDa thiet lap do kho va tao lai me cung moi! Nhan phim bat ky...";
            _getch();
            break;
        }
        default:
            cout << "\nLua chon khong dung. Vui long chon lai!";
            _getch();
        }
    }
    return 0;
}