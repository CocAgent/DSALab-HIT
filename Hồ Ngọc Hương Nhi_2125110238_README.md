#include <iostream>
#include <string>
using namespace std;

// ===== STRUCT BOOK =====
struct Book {
    int id;
    string title;
    bool available;
    Book* left;
    Book* right;
};

// ===== STRUCT QUEUE =====
struct Queue {
    string name;
    Queue* next;
};

// ===== GLOBAL =====
Queue* front = nullptr;
Queue* rear = nullptr;

// ===== CREATE BOOK =====
Book* createBook(int id, string title) {
    Book* b = new Book;
    b->id = id;
    b->title = title;
    b->available = true;
    b->left = nullptr;
    b->right = nullptr;
    return b;
}

// ===== INSERT =====
Book* insertBook(Book* root, int id, string title) {
    if (root == nullptr)
        return createBook(id, title);

    if (id < root->id)
        root->left = insertBook(root->left, id, title);
    else if (id > root->id)
        root->right = insertBook(root->right, id, title);
    else
        cout << "ID da ton tai!\n";

    return root;
}

// ===== SEARCH =====
Book* searchBook(Book* root, int id) {
    if (root == nullptr || root->id == id)
        return root;

    if (id < root->id)
        return searchBook(root->left, id);

    return searchBook(root->right, id);
}

// ===== PRINT =====
void printBooks(Book* root) {
    if (root == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    }

    printBooks(root->left);

    cout << "ID: " << root->id
        << " | Ten: " << root->title
        << " | Trang thai: " << (root->available ? "Con" : "Het")
        << endl;

    printBooks(root->right);
}

// ===== QUEUE =====
void enqueue(string name) {
    Queue* temp = new Queue;
    temp->name = name;
    temp->next = nullptr;

    if (rear == nullptr) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

string dequeue() {
    if (front == nullptr) return "";

    Queue* temp = front;
    string name = temp->name;

    front = front->next;
    if (front == nullptr) rear = nullptr;

    delete temp;
    return name;
}

// ===== MENU =====
void menu() {
    cout << "\n===== THU VIEN =====\n";
    cout << "1. Them sach\n";
    cout << "2. Tim sach\n";
    cout << "3. In danh sach\n";
    cout << "4. Muon sach\n";
    cout << "5. Tra sach\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

// ===== MAIN =====
int main() {
    Book* root = nullptr;
    int choice;

    do {
        menu();

        if (!(cin >> choice)) {
            cout << "Nhap sai!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // ===== THEM =====
        if (choice == 1) {
            int n;
            cout << "Nhap so luong sach: ";
            cin >> n;
            cin.ignore(1000, '\n');

            for (int i = 0; i < n; i++) {
                int id;
                string title;

                cout << "\nSach thu " << i + 1 << endl;

                cout << "Nhap ID: ";
                cin >> id;
                cin.ignore(1000, '\n');

                cout << "Nhap ten sach: ";
                getline(cin, title);

                root = insertBook(root, id, title);
            }
        }

        // ===== TIM =====
        else if (choice == 2) {
            int id;
            cout << "Nhap ID: ";
            cin >> id;

            Book* b = searchBook(root, id);

            if (b)
                cout << "Tim thay: " << b->title << endl;
            else
                cout << "Khong tim thay\n";
        }

        // ===== IN =====
        else if (choice == 3) {
            printBooks(root);
        }

        // ===== MUON =====
        else if (choice == 4) {
            int id;
            cout << "Nhap ID sach muon: ";
            cin >> id;

            Book* b = searchBook(root, id);

            if (b == nullptr) {
                cout << "Khong ton tai sach!\n";
            }
            else if (b->available) {
                b->available = false;
                cout << "Muon thanh cong!\n";
            }
            else {
                string name;
                cin.ignore(1000, '\n');
                cout << "Sach het. Nhap ten: ";
                getline(cin, name);
                enqueue(name);
            }
        }

        // ===== TRA =====
        else if (choice == 5) {
            int id;
            cout << "Nhap ID sach tra: ";
            cin >> id;

            Book* b = searchBook(root, id);

            if (b == nullptr) {
                cout << "Khong ton tai sach!\n";
            }
            else {
                b->available = true;
                cout << "Tra sach thanh cong!\n";

                if (front != nullptr) {
                    string next = dequeue();
                    cout << "Nguoi tiep theo: " << next << endl;
                }
            }
        }

    } while (choice != 0);

    return 0;
}
