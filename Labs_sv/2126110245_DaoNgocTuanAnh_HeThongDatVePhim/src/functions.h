#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"
#include <iomanip>

class CinemaManager {
private:
    static const int ROWS = 5;
    static const int COLS = 5;
    Seat seatMap[ROWS][COLS];
    stack<Transaction> undoStack;
    priority_queue<Customer> waitlist;
    BSTNode* customerRoot = nullptr;

    // Helper: Thêm khách vào BST
    BSTNode* insertBST(BSTNode* node, Customer c) {
        if (!node) return new BSTNode(c);
        if (c.id < node->data.id) node->left = insertBST(node->left, c);
        else if (c.id > node->data.id) node->right = insertBST(node->right, c);
        return node;
    }

    // Helper: Tìm khách trong BST
    BSTNode* searchBST(BSTNode* node, int id) {
        if (!node || node->data.id == id) return node;
        if (id < node->data.id) return searchBST(node->left, id);
        return searchBST(node->right, id);
    }

    // Giải phóng bộ nhớ cây BST (Để tránh Memory Leak)
    void clearBST(BSTNode* node) {
        if (node) {
            clearBST(node->left);
            clearBST(node->right);
            delete node;
        }
    }

public:
    CinemaManager() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                seatMap[i][j] = {i, j, false, -1};
            }
        }
    }

    ~CinemaManager() { clearBST(customerRoot); }

    void displayMap() {
        cout << "\n      [ MAN HINH ]\n";
        cout << "    ";
        for (int j = 0; j < COLS; j++) cout << j << "   ";
        cout << "\n";
        for (int i = 0; i < ROWS; i++) {
            cout << i << " ";
            for (int j = 0; j < COLS; j++) {
                cout << (seatMap[i][j].isBooked ? "[X] " : "[ ] ");
            }
            cout << "\n";
        }
        cout << "--------------------------\n";
    }

    void bookTicket(int id, string name, bool isVIP, int r, int c, bool saveUndo = true) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
            cout << "!! Vi tri khong hop le!\n"; return;
        }
        if (seatMap[r][c].isBooked) {
            cout << "!! Ghe da co nguoi. Dang dua vao hang cho...\n";
            waitlist.push({id, name, isVIP});
            return;
        }

        seatMap[r][c].isBooked = true;
        seatMap[r][c].customerId = id;
        customerRoot = insertBST(customerRoot, {id, name, isVIP});

        if (saveUndo) undoStack.push({BOOK, r, c, id});
        cout << ">> DAT VE THANH CONG: " << name << " (Ghe " << r << "," << c << ")\n";
    }

    void cancelTicket(int r, int c, bool saveUndo = true) {
        if (!seatMap[r][c].isBooked) {
            cout << "!! Ghe nay dang trong, khong the huy!\n"; return;
        }

        int oldId = seatMap[r][c].customerId;
        seatMap[r][c].isBooked = false;
        seatMap[r][c].customerId = -1;

        if (saveUndo) undoStack.push({CANCEL, r, c, oldId});
        cout << ">> DA HUY VE ghe (" << r << "," << c << ")\n";

        if (!waitlist.empty()) {
            Customer next = waitlist.top();
            waitlist.pop();
            cout << ">> UU TIEN: Ghe vua trong duoc cap cho khach cho: " << next.name << "\n";
            bookTicket(next.id, next.name, next.isVIP, r, c, false);
        }
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "!! Khong con thao tac nao de hoan tac.\n"; return;
        }
        Transaction last = undoStack.top();
        undoStack.pop();

        if (last.type == BOOK) {
            seatMap[last.row][last.col].isBooked = false;
            seatMap[last.row][last.col].customerId = -1;
            cout << ">> Undo: Da huy lai ghe vua dat.\n";
        } else {
            seatMap[last.row][last.col].isBooked = true;
            seatMap[last.row][last.col].customerId = last.customerId;
            cout << ">> Undo: Da dat lai ghe vua huy.\n";
        }
    }

    void findCustomer(int id) {
        BSTNode* res = searchBST(customerRoot, id);
        if (res) cout << ">> Tim thay: " << res->data.name << (res->data.isVIP ? " (VIP)" : " (Thuong)") << "\n";
        else cout << "!! Khong tim thay khach hang co ID: " << id << "\n";
    }
};

#endif
