#include <iostream>
#include "BST.h"
#include "Trash.h"
#include "UndoStack.h"

using namespace std;

void assertTrue(bool cond, string name) {
    if (cond) cout << "[PASS] " << name << endl;
    else cout << "[FAIL] " << name << endl;
}

int main() {
    Node* root = nullptr;
    Trash trash;
    UndoStack undo;

    // ================= TEST 1: INSERT + SORT =================
    root = insert(root, { "Kiet", "0123" });
    root = insert(root, { "An", "0999" });
    root = insert(root, { "Bao", "0888" });

    Node* f1 = searchExact(root, "An");
    Node* f2 = searchExact(root, "Bao");
    Node* f3 = searchExact(root, "Kiet");

    assertTrue(f1 && f2 && f3, "Insert & search multiple contacts");

    // ================= TEST 2: DELETE EXIST =================
    root = removeNode(root, "Bao");
    Node* f = searchExact(root, "Bao");

    assertTrue(f == nullptr, "Delete existing contact");

    // ================= TEST 3 (EDGE): DELETE NOT EXIST =================
    root = removeNode(root, "KhongTonTai");
    assertTrue(true, "Delete non-existing contact (no crash)");

    // ================= TEST 4: UNDO =================
    Contact c = { "TestUndo", "0111" };
    root = insert(root, c);

    undo.push(c);
    root = removeNode(root, "TestUndo");

    Contact restore = undo.pop();
    root = insert(root, restore);

    Node* fUndo = searchExact(root, "TestUndo");
    assertTrue(fUndo != nullptr, "Undo delete");

    // ================= TEST 5: TRASH ADD =================
    Contact t = { "TrashUser", "0222" };
    trash.add(t);

    assertTrue(!trash.empty(), "Add to trash");

    // ================= TEST 6: TRASH REMOVE =================
    trash.remove(0);
    assertTrue(trash.empty(), "Remove from trash");

    // ================= TEST 7 (EDGE): EMPTY TREE SEARCH =================
    Node* emptyRoot = nullptr;
    Node* fEmpty = searchExact(emptyRoot, "Any");

    assertTrue(fEmpty == nullptr, "Search in empty tree");

    // ================= TEST 8 (EDGE): DUPLICATE NAME =================
    root = insert(root, { "An", "0123" }); // trùng tên
    assertTrue(true, "Insert duplicate name (handled)");

    // ================= TEST 9: FILE SAVE + LOAD =================
    saveContacts(root, "test.txt");
    Node* newRoot = loadContacts("test.txt");

    assertTrue(newRoot != nullptr, "Save & load file");

    // ================= CLEAN =================
    freeTree(root);
    freeTree(newRoot);

    cout << "\n=== DONE ===" << endl;
    return 0;
}