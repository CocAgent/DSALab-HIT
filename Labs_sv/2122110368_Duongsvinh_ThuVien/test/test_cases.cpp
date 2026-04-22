#include <iostream>
#include <cassert>
#include "structures.h"
using namespace std;

int passed = 0, failed = 0;

void check(const string& name, bool cond) {
    if (cond) { cout << "  [PASS] " << name << "\n"; passed++; }
    else { cout << "  [FAIL] " << name << "\n"; failed++; }
}

// ── Test 1: BST them va tim kiem ────────────────────────────
void test_bst_insert_search() {
    cout << "\n[Test 1] BST: Them va tim kiem\n";
    Book* root = nullptr;
    root = bst_insert(root, 3, "C++ Primer", "Lippman", 5);
    root = bst_insert(root, 1, "Clean Code", "Martin", 3);
    root = bst_insert(root, 5, "DSAL Book", "Cormen", 2);

    check("Tim ma 3 ton tai", bst_search_id(root, 3) != nullptr);
    check("Tim ma 1 ton tai", bst_search_id(root, 1) != nullptr);
    check("Tim ma 99 khong ton tai", bst_search_id(root, 99) == nullptr);
    check("Tim theo ten 'Clean'", bst_search_title(root, "Clean") != nullptr);
    check("Tim theo ten 'xyz' = null", bst_search_title(root, "xyz") == nullptr);
}

// ── Test 2: BST xoa ─────────────────────────────────────────
void test_bst_delete() {
    cout << "\n[Test 2] BST: Xoa nut\n";
    Book* root = nullptr;
    root = bst_insert(root, 10, "Book A", "Au", 4);
    root = bst_insert(root, 5, "Book B", "Bu", 2);
    root = bst_insert(root, 15, "Book C", "Cu", 6);
    root = bst_delete(root, 5);
    check("Sau khi xoa 5, tim 5 = null", bst_search_id(root, 5) == nullptr);
    check("Sau khi xoa 5, goc 10 van ton tai", bst_search_id(root, 10) != nullptr);
}

// ── Test 3: Queue ────────────────────────────────────────────
void test_queue() {
    cout << "\n[Test 3] Queue: Danh sach cho\n";
    Queue q;
    check("Queue ban dau rong", q_empty(q));

    BorrowRecord r1 = { 1, 2, "Nguyen Van A", "DSAL Book", "muon" };
    BorrowRecord r2 = { 2, 2, "Tran Thi B",  "DSAL Book", "muon" };
    q_enqueue(q, r1);
    q_enqueue(q, r2);
    check("Queue sau 2 them = 2 phan tu", q.size == 2);

    BorrowRecord out;
    q_dequeue(q, out);
    check("Dequeue lay ra phan tu dau tien (FIFO)", out.readerId == 1);
    check("Queue con 1 phan tu", q.size == 1);
}

// ── Test 4: Stack ────────────────────────────────────────────
void test_stack() {
    cout << "\n[Test 4] Stack: Lich su (LIFO)\n";
    Stack s;
    check("Stack ban dau rong", stk_empty(s));

    BorrowRecord a = { 1, 1, "Alice", "Book1", "muon" };
    BorrowRecord b = { 2, 1, "Bob",   "Book1", "tra" };
    stk_push(s, a);
    stk_push(s, b);

    BorrowRecord top;
    stk_peek(s, top);
    check("Peek tra ve phan tu tren cung (Bob)", top.readerName == "Bob");

    BorrowRecord out;
    stk_pop(s, out);
    check("Pop lay ra Bob (LIFO)", out.readerName == "Bob");
    check("Stack con 1 phan tu", s.size == 1);
}

// ── Test 5: Linked List doc gia ──────────────────────────────
void test_linked_list() {
    cout << "\n[Test 5] Linked List: Doc gia\n";
    Reader* head = nullptr;
    head = ll_add(head, 1, "Nguyen Van A", "0901");
    head = ll_add(head, 2, "Tran Thi B", "0902");
    head = ll_add(head, 1, "Duplicate", "0000"); // id trung khong them

    check("Tim id 1 ton tai", ll_find(head, 1) != nullptr);
    check("Tim id 2 ton tai", ll_find(head, 2) != nullptr);
    check("Id trung khong them trung", ll_find(head, 1)->name == "Nguyen Van A");

    head = ll_remove(head, 1);
    check("Sau xoa id 1 khong con", ll_find(head, 1) == nullptr);
    check("Sau xoa id 1, id 2 van co", ll_find(head, 2) != nullptr);
}

// ── Main ─────────────────────────────────────────────────────
int main() {
    cout << "==========================================\n";
    cout << "        CHAY TEST CASES\n";
    cout << "==========================================\n";

    test_bst_insert_search();
    test_bst_delete();
    test_queue();
    test_stack();
    test_linked_list();

    cout << "\n==========================================\n";
    cout << "KET QUA: " << passed << " pass | " << failed << " fail\n";
    cout << "==========================================\n";
    return failed == 0 ? 0 : 1;
}
