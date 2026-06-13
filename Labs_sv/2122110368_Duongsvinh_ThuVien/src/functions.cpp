#include "structures.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

// ============================================================
//  BST SACH
// ============================================================

Book* bst_insert(Book* root, int id, const string& title, const string& author, int qty) {
    if (!root) return new Book(id, title, author, qty);
    if (id < root->id)       root->left = bst_insert(root->left, id, title, author, qty);
    else if (id > root->id)  root->right = bst_insert(root->right, id, title, author, qty);
    // id trung → cap nhat thong tin
    else { root->title = title; root->author = author; root->quantity = qty; }
    return root;
}

Book* bst_min(Book* root) {
    while (root && root->left) root = root->left;
    return root;
}

Book* bst_delete(Book* root, int id) {
    if (!root) return nullptr;
    if (id < root->id) {
        root->left = bst_delete(root->left, id);
    }
    else if (id > root->id) {
        root->right = bst_delete(root->right, id);
    }
    else {
        // Tim thay nut can xoa
        if (!root->left) {
            Book* tmp = root->right; delete root; return tmp;
        }
        if (!root->right) {
            Book* tmp = root->left;  delete root; return tmp;
        }
        // Co 2 con: lay nut nho nhat cua cay con phai
        Book* successor = bst_min(root->right);
        root->id = successor->id;
        root->title = successor->title;
        root->author = successor->author;
        root->quantity = successor->quantity;
        root->borrowed = successor->borrowed;
        root->right = bst_delete(root->right, successor->id);
    }
    return root;
}

Book* bst_search_id(Book* root, int id) {
    if (!root || root->id == id) return root;
    if (id < root->id) return bst_search_id(root->left, id);
    else               return bst_search_id(root->right, id);
}

// Tim kiem theo ten (chua chu khoa, in-order)
static Book* _found = nullptr;
void _bst_search_title_helper(Book* root, const string& kw) {
    if (!root) return;
    _bst_search_title_helper(root->left, kw);
    string t = root->title, k = kw;
    transform(t.begin(), t.end(), t.begin(), ::tolower);
    transform(k.begin(), k.end(), k.begin(), ::tolower);
    if (t.find(k) != string::npos && !_found) _found = root;
    _bst_search_title_helper(root->right, kw);
}

Book* bst_search_title(Book* root, const string& kw) {
    _found = nullptr;
    _bst_search_title_helper(root, kw);
    return _found;
}

void bst_print_inorder(Book* root) {
    if (!root) return;
    bst_print_inorder(root->left);
    cout << "  [" << root->id << "] " << root->title
        << " | Tac gia: " << root->author
        << " | SL: " << root->quantity
        << " | Dang muon: " << root->borrowed << "\n";
    bst_print_inorder(root->right);
}

// ============================================================
//  LINKED LIST DOC GIA
// ============================================================

Reader* ll_add(Reader* head, int id, const string& name, const string& phone) {
    // Kiem tra trung id
    Reader* cur = head;
    while (cur) { if (cur->id == id) return head; cur = cur->next; }
    Reader* node = new Reader(id, name, phone);
    node->next = head;
    return node;
}

Reader* ll_remove(Reader* head, int id) {
    if (!head) return nullptr;
    if (head->id == id) { Reader* tmp = head->next; delete head; return tmp; }
    Reader* cur = head;
    while (cur->next && cur->next->id != id) cur = cur->next;
    if (cur->next) { Reader* tmp = cur->next->next; delete cur->next; cur->next = tmp; }
    return head;
}

Reader* ll_find(Reader* head, int id) {
    while (head) { if (head->id == id) return head; head = head->next; }
    return nullptr;
}

void ll_print(Reader* head) {
    if (!head) { cout << "  (Chua co doc gia nao)\n"; return; }
    while (head) {
        cout << "  [" << head->id << "] " << head->name << " | SĐT: " << head->phone << "\n";
        head = head->next;
    }
}

// ============================================================
//  QUEUE
// ============================================================

void q_enqueue(Queue& q, BorrowRecord r) {
    QueueNode* node = new QueueNode(r);
    if (!q.rear) { q.front = q.rear = node; }
    else { q.rear->next = node; q.rear = node; }
    q.size++;
}

bool q_dequeue(Queue& q, BorrowRecord& out) {
    if (!q.front) return false;
    out = q.front->data;
    QueueNode* tmp = q.front;
    q.front = q.front->next;
    if (!q.front) q.rear = nullptr;
    delete tmp;
    q.size--;
    return true;
}

bool q_empty(const Queue& q) { return q.size == 0; }

void q_print(const Queue& q) {
    if (q_empty(q)) { cout << "  (Khong co ai trong danh sach cho)\n"; return; }
    QueueNode* cur = q.front;
    int i = 1;
    while (cur) {
        cout << "  " << i++ << ". Doc gia [" << cur->data.readerId << "] "
            << cur->data.readerName << " cho muon sach \"" << cur->data.bookTitle << "\"\n";
        cur = cur->next;
    }
}

// ============================================================
//  STACK
// ============================================================

void stk_push(Stack& s, BorrowRecord r) {
    StackNode* node = new StackNode(r);
    node->next = s.top;
    s.top = node;
    s.size++;
}

bool stk_pop(Stack& s, BorrowRecord& out) {
    if (!s.top) return false;
    out = s.top->data;
    StackNode* tmp = s.top;
    s.top = s.top->next;
    delete tmp;
    s.size--;
    return true;
}

bool stk_peek(const Stack& s, BorrowRecord& out) {
    if (!s.top) return false;
    out = s.top->data;
    return true;
}

bool stk_empty(const Stack& s) { return s.size == 0; }

void stk_print(const Stack& s) {
    if (stk_empty(s)) { cout << "  (Chua co lich su thao tac)\n"; return; }
    StackNode* cur = s.top;
    int i = 1;
    while (cur) {
        cout << "  " << i++ << ". [" << cur->data.action << "] Doc gia "
            << cur->data.readerName << " - Sach \"" << cur->data.bookTitle << "\"\n";
        cur = cur->next;
    }
}

// ============================================================
//  FILE I/O
// ============================================================

// Format file sach: id|title|author|quantity|borrowed
void save_books_helper(Book* root, ofstream& f) {
    if (!root) return;
    save_books_helper(root->left, f);
    f << root->id << "|" << root->title << "|" << root->author
        << "|" << root->quantity << "|" << root->borrowed << "\n";
    save_books_helper(root->right, f);
}

void save_books(Book* root, const string& fn) {
    ofstream f(fn);
    if (!f) { cerr << "Khong the ghi file " << fn << "\n"; return; }
    save_books_helper(root, f);
}

Book* load_books(const string& fn) {
    ifstream f(fn);
    if (!f) return nullptr;
    Book* root = nullptr;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string tok;
        int id, qty, bor;
        string title, author;
        getline(ss, tok, '|'); id = stoi(tok);
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, tok, '|'); qty = stoi(tok);
        getline(ss, tok, '|'); bor = stoi(tok);
        root = bst_insert(root, id, title, author, qty);
        Book* b = bst_search_id(root, id);
        if (b) b->borrowed = bor;
    }
    return root;
}

// Format file doc gia: id|name|phone
void save_readers(Reader* head, const string& fn) {
    ofstream f(fn);
    if (!f) { cerr << "Khong the ghi file " << fn << "\n"; return; }
    while (head) {
        f << head->id << "|" << head->name << "|" << head->phone << "\n";
        head = head->next;
    }
}

Reader* load_readers(const string& fn) {
    ifstream f(fn);
    if (!f) return nullptr;
    Reader* head = nullptr;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string tok;
        int id;
        string name, phone;
        getline(ss, tok, '|'); id = stoi(tok);
        getline(ss, name, '|');
        getline(ss, phone, '|');
        head = ll_add(head, id, name, phone);
    }
    return head;
}
