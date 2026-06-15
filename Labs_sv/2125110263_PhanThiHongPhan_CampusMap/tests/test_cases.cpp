#include "../src/structures.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "===== TEST HE THONG CAMPUS MAP =====\n";

    CampusMap campus(5);

    // ===== Test thêm địa điểm =====
    cout << "\n[TEST] Them dia diem\n";
    campus.addLocation(0, "Cong", "Cong chinh");
    campus.addLocation(1, "Khu A", "Day A");
    campus.addLocation(2, "Khu B", "Day B");
    campus.addLocation(3, "Thu Vien", "Thu vien");
    campus.addLocation(4, "Can Tin", "An uong");

    campus.printAllLocations();

    // ===== Test thêm đường đi =====
    cout << "\n[TEST] Them duong di\n";
    campus.addPath(0, 1, 10);
    campus.addPath(1, 2, 20);
    campus.addPath(2, 3, 30);
    campus.addPath(3, 4, 40);

    // ===== Test tìm đường =====
    cout << "\n[TEST] Tim duong di ngan nhat (0 -> 4)\n";
    campus.findShortestPath(0, 4);

    // ===== Test hàng xóm =====
    cout << "\n[TEST] Dia diem ke voi 1\n";
    campus.showNeighbors(1);

    // ===== Test liên thông =====
    cout << "\n[TEST] Kiem tra lien thong\n";
    campus.checkConnectivity();

    // ===== Test xóa đường =====
    cout << "\n[TEST] Xoa duong 2 - 3\n";
    campus.removePath(2, 3);
    campus.findShortestPath(0, 4);

    // ===== Test xóa địa điểm =====
    cout << "\n[TEST] Xoa dia diem 4\n";
    campus.removeLocation(4);
    campus.printAllLocations();

    cout << "\n===== KET THUC TEST =====\n";
    return 0;
}