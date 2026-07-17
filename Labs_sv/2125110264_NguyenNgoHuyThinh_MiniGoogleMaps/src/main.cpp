#include "structures.h"

int main() {
    int choice;
    do {
        cout << "\n====== MINI GOOGLE MAPS ======\n";
        cout << "1. Them dia diem\n";
        cout << "2. Them duong di\n";
        cout << "3. Hien thi ban do\n";
        cout << "4. Duong ngan nhat (Dijkstra)\n";
        cout << "5. Duong it diem nhat (BFS)\n";
        cout << "6. Kham pha tu mot diem (DFS)\n";
        cout << "7. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
            case 1: addLocation();   break;
            case 2: addRoad();       break;
            case 3: showMap();       break;
            case 4: dijkstra();      break;
            case 5: bfsPath();       break;
            case 6: dfsTraversal();  break;
            case 7: cout << "Tam biet!\n"; break;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 7);

    return 0;
}
