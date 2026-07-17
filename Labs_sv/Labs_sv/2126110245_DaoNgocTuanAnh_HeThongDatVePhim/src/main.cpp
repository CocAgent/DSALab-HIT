#include "functions.h"

int main() {
    CinemaManager cinema;
    int choice;

    while (true) {
        cout << "\n======= HE THONG DAT VE =======\n";
        cout << "1. Xem so do ghe\n";
        cout << "2. Dat ve moi\n";
        cout << "3. Huy ve (Kich hoat hang cho)\n";
        cout << "4. Hoan tac (Undo)\n";
        cout << "5. Tim khach hang (BST)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Luu chon cua ban: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                cinema.displayMap();
                break;
            case 2: {
                int id, r, c, vip; string name;
                cout << "ID: "; cin >> id;
                cout << "Ten: "; cin.ignore(); getline(cin, name);
                cout << "VIP (1: Co, 0: Khong): "; cin >> vip;
                cout << "Hang & Cot (0-4): "; cin >> r >> c;
                cinema.bookTicket(id, name, vip == 1, r, c);
                break;
            }
            case 3: {
                int r, c;
                cout << "Nhap Hang & Cot can huy: "; cin >> r >> c;
                cinema.cancelTicket(r, c);
                break;
            }
            case 4:
                cinema.undo();
                break;
            case 5: {
                int id;
                cout << "Nhap ID khach hang: "; cin >> id;
                cinema.findCustomer(id);
                break;
            }
            default:
                cout << "!! Lua chon khong hop le.\n";
        }
    }

    cout << "Cam on ban da su dung he thong!\n";
    return 0;
}
