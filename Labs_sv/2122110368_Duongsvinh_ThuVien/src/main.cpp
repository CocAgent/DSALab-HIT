#include <iostream>
#include <string>
#include <limits>
#include "structures.h"
using namespace std;

// ============================================================
//  DU LIEU TOAN CUC
// ============================================================
Book* bookTree = nullptr;   // BST sach
Reader* readerList = nullptr; // Linked List doc gia
Queue   waitQueue;            // Queue danh sach cho muon
Stack   histStack;            // Stack lich su thao tac

const string BOOK_FILE = "data/books.txt";
const string READER_FILE = "data/readers.txt";

// ============================================================
//  TIEN ICH
// ============================================================
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseScreen() {
    cout << "\nNhan Enter de tiep tuc...";
    clearInput();
    cin.get();
}

void printLine(char c = '-', int len = 50) {
    for (int i = 0; i < len; i++) cout << c;
    cout << "\n";
}

// ============================================================
//  MENU
// ============================================================
void menuBook() {
    int choice;
    do {
        printLine('=');
        cout << "       QUAN LY SACH\n";
        printLine('=');
        cout << "  1. Them sach moi\n";
        cout << "  2. Xoa sach\n";
        cout << "  3. Xem tat ca sach (BST in-order)\n";
        cout << "  4. Tim sach theo Ma\n";
        cout << "  5. Tim sach theo Ten\n";
        cout << "  0. Quay lai\n";
        printLine();
        cout << "Chon: "; cin >> choice; clearInput();

        if (choice == 1) {
            int id, qty;
            string title, author;
            cout << "Ma sach: ";   cin >> id;   clearInput();
            cout << "Ten sach: ";  getline(cin, title);
            cout << "Tac gia: ";   getline(cin, author);
            cout << "So luong: ";  cin >> qty;  clearInput();
            bookTree = bst_insert(bookTree, id, title, author, qty);
            cout << ">> Da them sach thanh cong!\n";
            save_books(bookTree, BOOK_FILE);

        }
        else if (choice == 2) {
            int id;
            cout << "Ma sach can xoa: "; cin >> id; clearInput();
            Book* b = bst_search_id(bookTree, id);
            if (!b) { cout << ">> Khong tim thay sach!\n"; }
            else if (b->borrowed > 0) { cout << ">> Sach dang duoc muon, khong the xoa!\n"; }
            else {
                bookTree = bst_delete(bookTree, id);
                cout << ">> Da xoa sach!\n";
                save_books(bookTree, BOOK_FILE);
            }

        }
        else if (choice == 3) {
            printLine();
            cout << "DANH SACH SACH (sap xep theo ma):\n";
            bst_print_inorder(bookTree);

        }
        else if (choice == 4) {
            int id;
            cout << "Nhap ma sach: "; cin >> id; clearInput();
            Book* b = bst_search_id(bookTree, id);
            if (!b) cout << ">> Khong tim thay!\n";
            else cout << "  Tim thay: [" << b->id << "] " << b->title
                << " | " << b->author << " | SL: " << b->quantity
                << " | Dang muon: " << b->borrowed << "\n";

        }
        else if (choice == 5) {
            string kw;
            cout << "Nhap tu khoa ten sach: "; getline(cin, kw);
            Book* b = bst_search_title(bookTree, kw);
            if (!b) cout << ">> Khong tim thay!\n";
            else cout << "  Tim thay: [" << b->id << "] " << b->title
                << " | " << b->author << " | SL: " << b->quantity
                << " | Dang muon: " << b->borrowed << "\n";
        }

        if (choice != 0) pauseScreen();
    } while (choice != 0);
}

void menuReader() {
    int choice;
    do {
        printLine('=');
        cout << "       QUAN LY DOC GIA\n";
        printLine('=');
        cout << "  1. Them doc gia\n";
        cout << "  2. Xoa doc gia\n";
        cout << "  3. Xem tat ca doc gia\n";
        cout << "  4. Tim doc gia theo Ma\n";
        cout << "  0. Quay lai\n";
        printLine();
        cout << "Chon: "; cin >> choice; clearInput();

        if (choice == 1) {
            int id;
            string name, phone;
            cout << "Ma doc gia: "; cin >> id; clearInput();
            cout << "Ho ten: ";     getline(cin, name);
            cout << "So dien thoai: "; getline(cin, phone);
            readerList = ll_add(readerList, id, name, phone);
            cout << ">> Da them doc gia!\n";
            save_readers(readerList, READER_FILE);

        }
        else if (choice == 2) {
            int id;
            cout << "Ma doc gia can xoa: "; cin >> id; clearInput();
            Reader* r = ll_find(readerList, id);
            if (!r) cout << ">> Khong tim thay doc gia!\n";
            else {
                readerList = ll_remove(readerList, id);
                cout << ">> Da xoa doc gia!\n";
                save_readers(readerList, READER_FILE);
            }

        }
        else if (choice == 3) {
            printLine();
            cout << "DANH SACH DOC GIA:\n";
            ll_print(readerList);

        }
        else if (choice == 4) {
            int id;
            cout << "Ma doc gia: "; cin >> id; clearInput();
            Reader* r = ll_find(readerList, id);
            if (!r) cout << ">> Khong tim thay!\n";
            else cout << "  Tim thay: [" << r->id << "] " << r->name
                << " | SĐT: " << r->phone << "\n";
        }

        if (choice != 0) pauseScreen();
    } while (choice != 0);
}

void menuBorrow() {
    int choice;
    do {
        printLine('=');
        cout << "       MUON / TRA SACH\n";
        printLine('=');
        cout << "  1. Muon sach\n";
        cout << "  2. Tra sach\n";
        cout << "  3. Xem danh sach cho muon (Queue)\n";
        cout << "  4. Xem lich su thao tac (Stack)\n";
        cout << "  5. Hoan tac (Undo) thao tac cuoi\n";
        cout << "  0. Quay lai\n";
        printLine();
        cout << "Chon: "; cin >> choice; clearInput();

        if (choice == 1) {
            int rid, bid;
            cout << "Ma doc gia: "; cin >> rid; clearInput();
            cout << "Ma sach:    "; cin >> bid; clearInput();

            Reader* r = ll_find(readerList, rid);
            Book* b = bst_search_id(bookTree, bid);

            if (!r) { cout << ">> Doc gia khong ton tai!\n"; }
            else if (!b) { cout << ">> Sach khong ton tai!\n"; }
            else {
                BorrowRecord rec;
                rec.readerId = r->id;
                rec.bookId = b->id;
                rec.readerName = r->name;
                rec.bookTitle = b->title;
                rec.action = "muon";

                int available = b->quantity - b->borrowed;
                if (available > 0) {
                    b->borrowed++;
                    stk_push(histStack, rec);
                    save_books(bookTree, BOOK_FILE);
                    cout << ">> Da cho muon sach \"" << b->title << "\" thanh cong!\n";
                    cout << "   Con lai: " << (b->quantity - b->borrowed) << " cuon.\n";
                }
                else {
                    q_enqueue(waitQueue, rec);
                    cout << ">> Sach het! Da them doc gia vao DANH SACH CHO.\n";
                    cout << "   Vi tri hang cho: " << waitQueue.size << "\n";
                }
            }

        }
        else if (choice == 2) {
            int rid, bid;
            cout << "Ma doc gia: "; cin >> rid; clearInput();
            cout << "Ma sach:    "; cin >> bid; clearInput();

            Reader* r = ll_find(readerList, rid);
            Book* b = bst_search_id(bookTree, bid);

            if (!r) { cout << ">> Doc gia khong ton tai!\n"; }
            else if (!b) { cout << ">> Sach khong ton tai!\n"; }
            else if (b->borrowed == 0) { cout << ">> Sach nay chua duoc muon!\n"; }
            else {
                b->borrowed--;
                BorrowRecord rec;
                rec.readerId = r->id; rec.bookId = b->id;
                rec.readerName = r->name; rec.bookTitle = b->title;
                rec.action = "tra";
                stk_push(histStack, rec);
                save_books(bookTree, BOOK_FILE);
                cout << ">> Da tra sach thanh cong!\n";

                // Tu dong cap cho nguoi dau hang doi
                if (!q_empty(waitQueue)) {
                    BorrowRecord next;
                    q_dequeue(waitQueue, next);
                    b->borrowed++;
                    BorrowRecord recNext = next;
                    recNext.action = "muon";
                    stk_push(histStack, recNext);
                    save_books(bookTree, BOOK_FILE);
                    cout << "   >> Tu dong cap sach cho doc gia dang cho: "
                        << next.readerName << "\n";
                }
            }

        }
        else if (choice == 3) {
            printLine();
            cout << "DANH SACH CHO MUON SACH:\n";
            q_print(waitQueue);

        }
        else if (choice == 4) {
            printLine();
            cout << "LICH SU THAO TAC (moi nhat tren cung):\n";
            stk_print(histStack);

        }
        else if (choice == 5) {
            BorrowRecord last;
            if (!stk_peek(histStack, last)) {
                cout << ">> Khong co thao tac nao de hoan tac!\n";
            }
            else {
                cout << "Hoan tac thao tac: [" << last.action << "] "
                    << last.readerName << " - \"" << last.bookTitle << "\"\n";
                cout << "Ban co chac? (y/n): ";
                char c; cin >> c; clearInput();
                if (c == 'y' || c == 'Y') {
                    stk_pop(histStack, last);
                    Book* b = bst_search_id(bookTree, last.bookId);
                    if (b) {
                        if (last.action == "muon") b->borrowed--;
                        else                       b->borrowed++;
                        save_books(bookTree, BOOK_FILE);
                    }
                    cout << ">> Da hoan tac!\n";
                }
            }
        }

        if (choice != 0) pauseScreen();
    } while (choice != 0);
}

void menuStats() {
    printLine('=');
    cout << "       THONG KE\n";
    printLine('=');
    // Dem sach duoc muon nhieu nhat bang cach duyet BST
    struct StatHelper {
        static void find_most_borrowed(Book* root, Book*& best) {
            if (!root) return;
            find_most_borrowed(root->left, best);
            if (!best || root->borrowed > best->borrowed) best = root;
            find_most_borrowed(root->right, best);
        }
        static int count(Book* root) {
            if (!root) return 0;
            return 1 + count(root->left) + count(root->right);
        }
    };

    int totalBooks = StatHelper::count(bookTree);
    cout << "  Tong so dau sach: " << totalBooks << "\n";

    Book* mostBorrowed = nullptr;
    StatHelper::find_most_borrowed(bookTree, mostBorrowed);
    if (mostBorrowed)
        cout << "  Sach duoc muon nhieu nhat: \"" << mostBorrowed->title
        << "\" (" << mostBorrowed->borrowed << " luot)\n";

    int totalReaders = 0;
    Reader* cur = readerList;
    while (cur) { totalReaders++; cur = cur->next; }
    cout << "  Tong so doc gia: " << totalReaders << "\n";
    cout << "  So luong cho trong hang doi: " << waitQueue.size << "\n";
    cout << "  So thao tac trong lich su: " << histStack.size << "\n";
    pauseScreen();
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    // Tao thu muc data neu chua co
    system("mkdir -p data");

    // Load du lieu tu file
    bookTree = load_books(BOOK_FILE);
    readerList = load_readers(READER_FILE);

    int choice;
    do {
        printLine('=');
        cout << "   HE THONG QUAN LY THU VIEN\n";
        cout << "   DSA Final Project — C++17\n";
        printLine('=');
        cout << "  1. Quan ly Sach      (BST)\n";
        cout << "  2. Quan ly Doc gia   (Linked List)\n";
        cout << "  3. Muon / Tra sach   (Queue + Stack)\n";
        cout << "  4. Thong ke\n";
        cout << "  0. Thoat\n";
        printLine();
        cout << "Chon chuc nang: "; cin >> choice; clearInput();

        switch (choice) {
        case 1: menuBook();   break;
        case 2: menuReader(); break;
        case 3: menuBorrow(); break;
        case 4: menuStats();  break;
        case 0: cout << "Tam biet!\n"; break;
        default: cout << ">> Lua chon khong hop le!\n"; pauseScreen();
        }
    } while (choice != 0);

    return 0;
}
