#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

// ===== BOOK =====
struct Book {
    int id;
    string name;
};

// ===== BST NODE =====
struct Node {
    Book data;
    Node* left;
    Node* right;
};

// ===== GLOBAL =====
Node* root = NULL;
queue<string> waitList;
stack<string> history;

// ===== CREATE NODE =====
Node* createNode(Book b) {
    Node* node = new Node;
    node->data = b;
    node->left = node->right = NULL;
    return node;
}

// ===== INSERT BST =====
Node* insert(Node* root, Book b) {
    if (!root) return createNode(b);
    if (b.id < root->data.id)
        root->left = insert(root->left, b);
    else
        root->right = insert(root->right, b);
    return root;
}

// ===== SEARCH =====
Node* search(Node* root, int id) {
    if (!root || root->data.id == id) return root;
    if (id < root->data.id)
        return search(root->left, id);
    return search(root->right, id);
}

// ===== INORDER =====
void display(Node* root) {
    if (!root) return;
    display(root->left);
    cout << root->data.id << " - " << root->data.name << endl;
    display(root->right);
}

// ===== MENU =====
void menu() {
    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them sach\n";
        cout << "2. Tim sach\n";
        cout << "3. Hien thi\n";
        cout << "4. Muon sach\n";
        cout << "5. Undo\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        if (choice == 1) {
            Book b;
            cout << "Nhap ID: ";
            cin >> b.id;
            cin.ignore();
            cout << "Nhap ten: ";
            getline(cin, b.name);

            root = insert(root, b);
            history.push("Them sach");
        }

        else if (choice == 2) {
            int id;
            cout << "Nhap ID: ";
            cin >> id;
            Node* res = search(root, id);

            if (res) cout << "Tim thay: " << res->data.name << endl;
            else cout << "Khong tim thay\n";
        }

        else if (choice == 3) {
            display(root);
        }

        else if (choice == 4) {
            string name;
            cin.ignore();
            cout << "Nhap ten nguoi muon: ";
            getline(cin, name);

            waitList.push(name);
            history.push("Muon sach");
            cout << "Da them vao hang cho\n";
        }

        else if (choice == 5) {
            if (!history.empty()) {
                cout << "Undo: " << history.top() << endl;
                history.pop();
            } else {
                cout << "Khong co gi de undo\n";
            }
        }

    } while (choice != 0);
}

// ===== MAIN =====
int main() {
    menu();
    return 0;
}
