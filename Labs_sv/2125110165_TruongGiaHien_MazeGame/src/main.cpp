#include "structures.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // Thêm thư viện để làm sạch bộ nhớ đệm cin

using namespace std;

int main() {
    srand(time(0)); 
    Maze myMaze(21, 21); // Kích thước mặc định

    while (true) {
        system("cls");
        cout << "==== DO AN CAU TRUC DU LIEU: MAZE GAME ====\n";
        cout << "1. Hien thi Me cung hien tai\n";
        cout << "2. Tao Me cung moi ngau nhien (DFS - Stack)\n";
        cout << "3. Nguoi choi tu giai (W/A/S/D)\n";
        cout << "4. Giai bang BFS (Tim duong ngan nhat - Queue)\n";
        cout << "5. Giai bang DFS (Quay lui ngau nhien - Stack)\n";
        cout << "6. Giai bang A* (Tim duong ngan nhat co Trong so - Priority Queue)\n";
        cout << "7. [Chuc nang 6] So sanh quang duong BFS vs DFS\n";
        cout << "8. [Chuc nang 7] Dieu chinh do kho (Kich thuoc me cung)\n";
        cout << "9. Thoat\n";
        cout << "Moi ban chon (1-9): ";
        
        int choice;
        
        // BẪY LỖI: Chống crash nếu người dùng nhập chữ cái thay vì số
        if (!(cin >> choice)) {
            cin.clear(); // Xóa cờ lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua bộ nhớ đệm
            cout << "Loi: Vui long chi nhap so tu 1 den 9!\n";
            system("pause");
            continue; // Quay lại đầu menu
        }

        if (choice == 1) {
            myMaze.printMaze();
            system("pause");
        } else if (choice == 2) {
            myMaze.initMaze();
            myMaze.generateMazeDFS();
            cout << "Da tao me cung moi!\n";
            system("pause");
        } else if (choice == 3) {
            myMaze.playGame();
            system("pause");
        } else if (choice == 4) {
            myMaze.solveBFS(false);
            system("pause");
        } else if (choice == 5) {
            myMaze.solveDFS(false);
            system("pause");
        } else if (choice == 6) {
            myMaze.solveAStar(false);
            system("pause");
        } else if (choice == 7) {
            system("cls");
            cout << "Dang chay thuat toan de so sanh tren ma tran an...\n\n";
            int bfsSteps = myMaze.solveBFS(true); 
            int dfsSteps = myMaze.solveDFS(true);
            
            cout << "=== KET QUA SO SANH TRUY VET ===\n";
            cout << "- Chieu dai duong di cua BFS (Ngan nhat): " << bfsSteps << " buoc.\n";
            cout << "- Chieu dai duong di cua DFS (Quay lui):  " << dfsSteps << " buoc.\n\n";
            cout << "=> KET LUAN: BFS tim ra duong di toi uu, DFS di long vong hon rat nhieu.\n\n";
            system("pause");
        } else if (choice == 8) {
            int newSize;
            cout << "Nhap kich thuoc moi (nen tu 21 den 71, bat buoc nhap so le): ";
            // Bẫy lỗi phụ khi nhập kích thước
            if (!(cin >> newSize)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Loi: Kich thuoc phai la so!\n";
                system("pause");
                continue;
            }
            if (newSize < 5) newSize = 5;
            myMaze.resizeMaze(newSize, newSize);
            cout << "Da tang do kho! Me cung hien tai la " << newSize << "x" << newSize << ".\n";
            system("pause");
        } else if (choice == 9) {
            break;
        } else {
            cout << "Tuy chon khong hop le!\n";
            system("pause");
        }
    }

    return 0;
}