#pragma once
#include <string>
#include <fstream>
using namespace std;

// ============================================================
//  STRUCT KHAI BAO
// ============================================================

// --- Sach ---
struct Book {
    int     id;
    string  title;
    string  author;
    int     quantity;   // so luong hien co trong thu vien
    int     borrowed;   // so luong dang duoc muon
    Book* left;
    Book* right;
    Book(int i, string t, string a, int q)
        : id(i), title(t), author(a), quantity(q), borrowed(0), left(nullptr), right(nullptr) {
    }
};

// --- Doc gia ---
struct Reader {
    int     id;
    string  name;
    string  phone;
    Reader* next;
    Reader(int i, string n, string p)
        : id(i), name(n), phone(p), next(nullptr) {
    }
};

// --- Ban ghi muon tra (danh sach cho + lich su) ---
struct BorrowRecord {
    int     readerId;
    int     bookId;
    string  readerName;
    string  bookTitle;
    string  action;     // "muon" hoac "tra"
};

// ============================================================
//  BST SACH
// ============================================================
Book* bst_insert(Book* root, int id, const string& title, const string& author, int qty);
Book* bst_search_id(Book* root, int id);
Book* bst_search_title(Book* root, const string& keyword);
Book* bst_delete(Book* root, int id);
Book* bst_min(Book* root);
void  bst_print_inorder(Book* root);

// ============================================================
//  LINKED LIST DOC GIA
// ============================================================
Reader* ll_add(Reader* head, int id, const string& name, const string& phone);
Reader* ll_remove(Reader* head, int id);
Reader* ll_find(Reader* head, int id);
void    ll_print(Reader* head);

// ============================================================
//  QUEUE (danh sach cho muon sach)
// ============================================================
struct QueueNode {
    BorrowRecord data;
    QueueNode* next;
    QueueNode(BorrowRecord r) : data(r), next(nullptr) {}
};

struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int        size;
    Queue() : front(nullptr), rear(nullptr), size(0) {}
};

void      q_enqueue(Queue& q, BorrowRecord r);
bool      q_dequeue(Queue& q, BorrowRecord& out);
bool      q_empty(const Queue& q);
void      q_print(const Queue& q);

// ============================================================
//  STACK (lich su thao tac – ho tro Undo)
// ============================================================
struct StackNode {
    BorrowRecord data;
    StackNode* next;
    StackNode(BorrowRecord r) : data(r), next(nullptr) {}
};

struct Stack {
    StackNode* top;
    int        size;
    Stack() : top(nullptr), size(0) {}
};

void      stk_push(Stack& s, BorrowRecord r);
bool      stk_pop(Stack& s, BorrowRecord& out);
bool      stk_peek(const Stack& s, BorrowRecord& out);
bool      stk_empty(const Stack& s);
void      stk_print(const Stack& s);

// ============================================================
//  FILE I/O
// ============================================================
Book* load_books(const string& filename);
Reader* load_readers(const string& filename);
void    save_books(Book* root, const string& filename);
void    save_readers(Reader* head, const string& filename);
