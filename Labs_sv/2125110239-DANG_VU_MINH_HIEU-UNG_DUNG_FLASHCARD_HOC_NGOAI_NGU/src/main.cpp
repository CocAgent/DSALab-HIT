#include "Flashcard.h"

int main() {
    FlashcardSystem system;
    system.loadFile("data.txt");
    string choiceStr;

    while (true) {
        cout << "\n===== FLASHCARD DSA SYSTEM =====";
        cout << "\n1. Them tu moi";
        cout << "\n2. Tim kiem tu dien (BST)";
        cout << "\n3. Bat dau phien hoc (Priority Queue)";
        cout << "\n4. Xem thong ke";
        cout << "\n5. Luu va Thoat";
        cout << "\nLua chon cua ban: ";

        getline(cin, choiceStr);
        if (choiceStr.empty()) continue;
        int choice = stoi(choiceStr);

        if (choice == 1) {
            string w, m, e;
            cout << "Tu: "; getline(cin, w);
            cout << "Nghia: "; getline(cin, m);
            cout << "Vi du: "; getline(cin, e);
            system.addCard(w, m, e);
            cout << ">> Da them thanh cong!\n";
        }
        else if (choice == 2) {
            string w;
            cout << "Nhap tu can tim: "; getline(cin, w);
            system.searchWord(w);
        }
        else if (choice == 3) {
            system.startSession();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        else if (choice == 4) {
            system.showStats();
        }
        else if (choice == 5) {
            system.saveFile("data.txt");
            cout << ">> Da luu du lieu. Tam biet!\n";
            break;
        }
    }
    return 0;
}