#include "structures.h"

#define _HAS_STD_BYTE 0
#include <windows.h>

void printMenu() {
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║    HE THONG BAN DO CAMPUS TRUONG     ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║  [1] Tra cuu thong tin dia diem       ║\n";
    cout << "║  [2] Xem tat ca dia diem              ║\n";
    cout << "║  [3] Tim duong di ngan nhat           ║\n";
    cout << "║  [4] Xem cac dia diem ke              ║\n";
    cout << "║  [5] Kiem tra lien thong ban do       ║\n";
    cout << "║  [6] Them dia diem moi                ║\n";
    cout << "║  [7] Xoa dia diem                     ║\n";
    cout << "║  [8] Them duong di moi                ║\n";
    cout << "║  [9] Xoa duong di                     ║\n";
    cout << "║  [0] Thoat                            ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    cout << "=> Nhap lua chon: ";
}

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    system("chcp 65001");

    CampusMap campus(10);

    campus.addLocation(0, "Cong Chinh",    "Loi vao chinh cua truong");
    campus.addLocation(1, "Khu A",         "Phong hoc ly thuyet - day A");
    campus.addLocation(2, "Khu D",         "Phong hoc ly thuyet - day D");
    campus.addLocation(3, "Can Tin",       "Khu an uong sinh vien, goc trai truong");
    campus.addLocation(4, "Thu Vien",      "Thu vien trung tam, tang tret");
    campus.addLocation(5, "Xuong 1",       "Xuong thuc hanh so 1 (canh Khu D)");
    campus.addLocation(6, "Xuong 2",       "Xuong thuc hanh so 2");
    campus.addLocation(7, "Xuong 3",       "Xuong thuc hanh so 3 (goc phai truong)");
    campus.addLocation(8, "Nha Xe",        "Bai giu xe sinh vien va giang vien");
    campus.addLocation(9, "Phong TC-HC",   "Phong to chuc - hanh chinh");

    campus.addPath(0, 1, 130);
    campus.addPath(0, 4, 150);
    campus.addPath(1, 2, 100);
    campus.addPath(1, 3,  50);
    campus.addPath(1, 4,  80);
    campus.addPath(2, 4,  90);
    campus.addPath(2, 5, 120);
    campus.addPath(5, 6,  80);
    campus.addPath(5, 8,  80);
    campus.addPath(6, 7,  90);
    campus.addPath(7, 8,  80);
    campus.addPath(4, 9, 110);
    campus.addPath(2, 9, 140);

    int choice;
    while (true) {
        printMenu();
        if (!(cin >> choice)) { cin.clear(); cin.ignore(1000,'\n'); continue; }
        cin.ignore();

        if (choice == 0) break;

        switch (choice) {
        case 1: {
            int id;
            cout << "Nhap ID: "; cin >> id;
            campus.searchAndPrint(id);
            break;
        }
        case 2:
            campus.printAllLocations();
            break;

        case 3: {
            int s, t;
            cout << "Nhap ID diem bat dau: "; cin >> s;
            cout << "Nhap ID diem ket thuc: "; cin >> t;
            campus.findShortestPath(s, t);
            break;
        }
        case 4: {
            int id;
            cout << "Nhap ID dia diem: "; cin >> id;
            campus.showNeighbors(id);
            break;
        }
        case 5:
            campus.checkConnectivity();
            break;

        case 6: {
            int id;
            string name, desc;
            cout << "Nhap ID moi (0-19): "; cin >> id; cin.ignore();
            cout << "Nhap ten dia diem : "; getline(cin, name);
            cout << "Nhap mo ta        : "; getline(cin, desc);
            campus.addLocation(id, name, desc);
            break;
        }
        case 7: {
            int id;
            cout << "Nhap ID can xoa: "; cin >> id;
            campus.removeLocation(id);
            break;
        }
        case 8: {
            int u, v, w;
            cout << "Nhap ID diem thu nhat : "; cin >> u;
            cout << "Nhap ID diem thu hai  : "; cin >> v;
            cout << "Khoang cach (met)     : "; cin >> w;
            campus.addPath(u, v, w);
            break;
        }
        case 9: {
            int u, v;
            cout << "Nhap ID diem thu nhat: "; cin >> u;
            cout << "Nhap ID diem thu hai : "; cin >> v;
            campus.removePath(u, v);
            break;
        }
        default:
            cout << "[!] Lua chon khong hop le!\n";
        }
    }

    cout << "\nCam on ban da su dung he thong!\n";
    return 0;
}