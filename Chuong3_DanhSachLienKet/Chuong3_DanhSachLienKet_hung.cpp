// ============================================================
//  Chuong3_DanhSachLienKet_refined.cpp
//  Noi dung: Con tro, DSLK don, Stack, Queue
//  Muc tieu: Ban refined an toan hon, de doc hon, van giu tinh giao trinh
// ============================================================

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// ============================================================
//  CAU TRUC NUT (NODE)
// ============================================================
struct Node {
    int data;
    Node* next;
};

// ============================================================
//  DANH SACH LIEN KET DON
// ============================================================
struct List {
    Node* head;
    Node* tail;
};

void KhoiTaoDSLK(List& L) {
    L.head = nullptr;
    L.tail = nullptr;
}

bool DanhSachRong(const List& L) {
    return L.head == nullptr;
}

Node* TaoNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

Node* TimNodeTruoc(const List& L, Node* q) {
    if (q == nullptr || DanhSachRong(L) || q == L.head) {
        return nullptr;
    }

    Node* cur = L.head;
    while (cur != nullptr && cur->next != q) {
        cur = cur->next;
    }

    return cur;
}

bool ThuocDanhSach(const List& L, Node* q) {
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur == q) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void ThemDau(List& L, int x) {
    Node* p = TaoNode(x);
    if (DanhSachRong(L)) {
        L.head = L.tail = p;
        return;
    }

    p->next = L.head;
    L.head = p;
}

void ThemCuoi(List& L, int x) {
    Node* p = TaoNode(x);
    if (DanhSachRong(L)) {
        L.head = L.tail = p;
        return;
    }

    L.tail->next = p;
    L.tail = p;
}

bool ThemSau(List& L, Node* q, int x) {
    if (q == nullptr || !ThuocDanhSach(L, q)) {
        return false;
    }

    Node* p = TaoNode(x);
    p->next = q->next;
    q->next = p;

    if (q == L.tail) {
        L.tail = p;
    }

    return true;
}

bool ThemTruoc(List& L, Node* q, int x) {
    if (q == nullptr) {
        return false;
    }

    if (q == L.head) {
        ThemDau(L, x);
        return true;
    }

    Node* truocQ = TimNodeTruoc(L, q);
    if (truocQ == nullptr) {
        return false;
    }

    Node* p = TaoNode(x);
    p->next = q;
    truocQ->next = p;
    return true;
}

bool XoaDau(List& L) {
    if (DanhSachRong(L)) {
        return false;
    }

    Node* p = L.head;
    L.head = L.head->next;

    if (L.head == nullptr) {
        L.tail = nullptr;
    }

    delete p;
    return true;
}

bool XoaCuoi(List& L) {
    if (DanhSachRong(L)) {
        return false;
    }

    if (L.head == L.tail) {
        delete L.head;
        L.head = L.tail = nullptr;
        return true;
    }

    Node* cur = L.head;
    while (cur->next != L.tail) {
        cur = cur->next;
    }

    delete L.tail;
    L.tail = cur;
    L.tail->next = nullptr;
    return true;
}

bool XoaGiaTri(List& L, int x) {
    if (DanhSachRong(L)) {
        return false;
    }

    Node* cur = L.head;
    Node* prev = nullptr;

    while (cur != nullptr && cur->data != x) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == nullptr) {
        return false;
    }

    if (prev == nullptr) {
        return XoaDau(L);
    }

    prev->next = cur->next;
    if (cur == L.tail) {
        L.tail = prev;
    }
    delete cur;
    return true;
}

void XoaDanhSach(List& L) {
    while (XoaDau(L)) {
    }
}

void InDanhSach(const List& L) {
    if (DanhSachRong(L)) {
        cout << "  [Danh sach rong]\n";
        return;
    }

    cout << "  HEAD -> ";
    Node* cur = L.head;
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next != nullptr) {
            cout << " -> ";
        }
        cur = cur->next;
    }
    cout << " -> NULL\n";
}

bool TimMax(const List& L, int& maxValue) {
    if (DanhSachRong(L)) {
        return false;
    }

    maxValue = L.head->data;
    Node* cur = L.head->next;
    while (cur != nullptr) {
        if (cur->data > maxValue) {
            maxValue = cur->data;
        }
        cur = cur->next;
    }
    return true;
}

Node* TimX(const List& L, int x) {
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

bool TimChanDau(const List& L, int& value) {
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) {
            value = cur->data;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool TimChanCuoi(const List& L, int& value) {
    bool found = false;
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) {
            value = cur->data;
            found = true;
        }
        cur = cur->next;
    }
    return found;
}

void LietKeAm(const List& L) {
    cout << "  Cac phan tu am: ";
    Node* cur = L.head;
    bool co = false;

    while (cur != nullptr) {
        if (cur->data < 0) {
            cout << cur->data << " ";
            co = true;
        }
        cur = cur->next;
    }

    if (!co) {
        cout << "(khong co)";
    }
    cout << "\n";
}

long long TongDuong(const List& L) {
    long long tong = 0;
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data > 0) {
            tong += cur->data;
        }
        cur = cur->next;
    }
    return tong;
}

int DemAm(const List& L) {
    int dem = 0;
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data < 0) {
            ++dem;
        }
        cur = cur->next;
    }
    return dem;
}

bool LaChinhPhuong(int n) {
    if (n < 0) {
        return false;
    }

    int can = static_cast<int>(sqrt(static_cast<double>(n)));
    return can * can == n;
}

bool CoSoChinhPhuong(const List& L) {
    Node* cur = L.head;
    while (cur != nullptr) {
        if (LaChinhPhuong(cur->data)) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

int DemCucDai(const List& L) {
    int maxValue = 0;
    if (!TimMax(L, maxValue)) {
        return 0;
    }

    int dem = 0;
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data == maxValue) {
            ++dem;
        }
        cur = cur->next;
    }
    return dem;
}

void SapXepChonTrucTiep(List& L) {
    for (Node* i = L.head; i != nullptr && i->next != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void NoiDanhSach(List& L1, List& L2) {
    if (&L1 == &L2) {
        return;
    }

    if (DanhSachRong(L2)) {
        return;
    }

    if (DanhSachRong(L1)) {
        L1 = L2;
    } else {
        L1.tail->next = L2.head;
        L1.tail = L2.tail;
    }

    L2.head = nullptr;
    L2.tail = nullptr;
}

void TachChanLe(const List& L, List& LChan, List& LLe) {
    KhoiTaoDSLK(LChan);
    KhoiTaoDSLK(LLe);

    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) {
            ThemCuoi(LChan, cur->data);
        } else {
            ThemCuoi(LLe, cur->data);
        }
        cur = cur->next;
    }
}

// ============================================================
//  STACK (LIFO)
// ============================================================
struct Stack {
    Node* top;
};

void KhoiTaoStack(Stack& S) {
    S.top = nullptr;
}

bool StackRong(const Stack& S) {
    return S.top == nullptr;
}

void XoaStack(Stack& S) {
    while (!StackRong(S)) {
        Node* p = S.top;
        S.top = S.top->next;
        delete p;
    }
}

void Push(Stack& S, int x) {
    Node* p = TaoNode(x);
    p->next = S.top;
    S.top = p;
}

bool Pop(Stack& S, int& value) {
    if (StackRong(S)) {
        return false;
    }

    Node* p = S.top;
    value = p->data;
    S.top = S.top->next;
    delete p;
    return true;
}

bool PeekStack(const Stack& S, int& value) {
    if (StackRong(S)) {
        return false;
    }

    value = S.top->data;
    return true;
}

void InStack(const Stack& S) {
    cout << "  Stack (TOP->BOT): ";
    Node* cur = S.top;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

bool KiemTraNgoac(const string& s) {
    Stack S;
    KhoiTaoStack(S);

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            Push(S, c);
            continue;
        }

        if (c == ')' || c == ']' || c == '}') {
            int topValue = 0;
            if (!Pop(S, topValue)) {
                XoaStack(S);
                return false;
            }

            if ((c == ')' && topValue != '(') ||
                (c == ']' && topValue != '[') ||
                (c == '}' && topValue != '{')) {
                XoaStack(S);
                return false;
            }
        }
    }

    bool hopLe = StackRong(S);
    XoaStack(S);
    return hopLe;
}

string Dec2Bin(int n) {
    if (n == 0) {
        return "0";
    }

    Stack S;
    KhoiTaoStack(S);

    long long giaTri = n;
    bool am = giaTri < 0;
    if (am) {
        giaTri = -giaTri;
    }

    while (giaTri > 0) {
        Push(S, static_cast<int>(giaTri % 2));
        giaTri /= 2;
    }

    string ketQua;
    if (am) {
        ketQua += "-";
    }

    int bit = 0;
    while (Pop(S, bit)) {
        ketQua += to_string(bit);
    }

    return ketQua;
}

// ============================================================
//  QUEUE (FIFO)
// ============================================================
struct Queue {
    Node* front;
    Node* rear;
};

void KhoiTaoQueue(Queue& Q) {
    Q.front = nullptr;
    Q.rear = nullptr;
}

bool QueueRong(const Queue& Q) {
    return Q.front == nullptr;
}

void XoaQueue(Queue& Q) {
    while (!QueueRong(Q)) {
        Node* p = Q.front;
        Q.front = Q.front->next;
        delete p;
    }
    Q.rear = nullptr;
}

void Enqueue(Queue& Q, int x) {
    Node* p = TaoNode(x);
    if (QueueRong(Q)) {
        Q.front = Q.rear = p;
        return;
    }

    Q.rear->next = p;
    Q.rear = p;
}

bool Dequeue(Queue& Q, int& value) {
    if (QueueRong(Q)) {
        return false;
    }

    Node* p = Q.front;
    value = p->data;
    Q.front = Q.front->next;

    if (Q.front == nullptr) {
        Q.rear = nullptr;
    }

    delete p;
    return true;
}

void InQueue(const Queue& Q) {
    cout << "  Queue (FRONT->REAR): ";
    Node* cur = Q.front;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

// ============================================================
//  DEMO
// ============================================================
void DemoDSLK() {
    cout << "\n=== DEMO DANH SACH LIEN KET DON ===\n";

    List L;
    KhoiTaoDSLK(L);

    cout << "  Them cuoi: 10, 20, 30, 40, 50\n";
    for (int x : {10, 20, 30, 40, 50}) {
        ThemCuoi(L, x);
    }
    InDanhSach(L);

    cout << "  Them dau: 5\n";
    ThemDau(L, 5);
    InDanhSach(L);

    cout << "  Them truoc 20 gia tri 15\n";
    Node* node20 = TimX(L, 20);
    cout << "  Ket qua: " << (ThemTruoc(L, node20, 15) ? "Thanh cong" : "That bai") << "\n";
    InDanhSach(L);

    cout << "  Them sau 40 gia tri 45\n";
    Node* node40 = TimX(L, 40);
    cout << "  Ket qua: " << (ThemSau(L, node40, 45) ? "Thanh cong" : "That bai") << "\n";
    InDanhSach(L);

    cout << "  Xoa dau: " << (XoaDau(L) ? "Thanh cong" : "That bai") << "\n";
    InDanhSach(L);

    cout << "  Xoa cuoi: " << (XoaCuoi(L) ? "Thanh cong" : "That bai") << "\n";
    InDanhSach(L);

    cout << "  Xoa gia tri 30: " << (XoaGiaTri(L, 30) ? "Thanh cong" : "That bai") << "\n";
    InDanhSach(L);

    int maxValue = 0;
    if (TimMax(L, maxValue)) {
        cout << "  Phan tu lon nhat: " << maxValue << "\n";
    }

    cout << "  Tim 20: " << (TimX(L, 20) != nullptr ? "Tim thay" : "Khong tim thay") << "\n";

    ThemCuoi(L, -5);
    ThemCuoi(L, -8);
    ThemCuoi(L, 16);
    cout << "\n  Sau khi them -5, -8, 16:\n";
    InDanhSach(L);

    LietKeAm(L);
    cout << "  Tong duong: " << TongDuong(L) << "\n";
    cout << "  Dem phan tu am: " << DemAm(L) << "\n";
    cout << "  Co so chinh phuong? " << (CoSoChinhPhuong(L) ? "Co" : "Khong") << "\n";
    cout << "  So phan tu cuc dai: " << DemCucDai(L) << "\n";

    cout << "\n  Sap xep DSLK:\n";
    SapXepChonTrucTiep(L);
    InDanhSach(L);

    List LChan, LLe;
    TachChanLe(L, LChan, LLe);
    cout << "  Danh sach chan:\n";
    InDanhSach(LChan);
    cout << "  Danh sach le:\n";
    InDanhSach(LLe);

    XoaDanhSach(L);
    XoaDanhSach(LChan);
    XoaDanhSach(LLe);
}

void DemoStack() {
    cout << "\n=== DEMO STACK (NGAN XEP) ===\n";

    Stack S;
    KhoiTaoStack(S);

    cout << "  Push: 10, 20, 30, 40\n";
    for (int x : {10, 20, 30, 40}) {
        Push(S, x);
    }
    InStack(S);

    int value = 0;
    if (Pop(S, value)) {
        cout << "  Pop: " << value << "\n";
    }
    if (Pop(S, value)) {
        cout << "  Pop: " << value << "\n";
    }
    InStack(S);

    cout << "\n  [Ung dung 1] Kiem tra dan ngoac:\n";
    string test1 = "{[()]}";
    string test2 = "({[}])";
    cout << "    \"" << test1 << "\" => "
         << (KiemTraNgoac(test1) ? "Hop le" : "Khong hop le") << "\n";
    cout << "    \"" << test2 << "\" => "
         << (KiemTraNgoac(test2) ? "Hop le" : "Khong hop le") << "\n";

    cout << "\n  [Ung dung 2] Doi so thap phan -> nhi phan:\n";
    for (int n : {0, 5, 10, 42, 255, -13}) {
        cout << "    " << n << " -> " << Dec2Bin(n) << "\n";
    }

    XoaStack(S);
}

void DemoQueue() {
    cout << "\n=== DEMO QUEUE (HANG DOI) ===\n";

    Queue Q;
    KhoiTaoQueue(Q);

    cout << "  Enqueue: 1, 2, 3, 4, 5\n";
    for (int x : {1, 2, 3, 4, 5}) {
        Enqueue(Q, x);
    }
    InQueue(Q);

    int value = 0;
    if (Dequeue(Q, value)) {
        cout << "  Dequeue: " << value << "\n";
    }
    if (Dequeue(Q, value)) {
        cout << "  Dequeue: " << value << "\n";
    }
    InQueue(Q);

    XoaQueue(Q);
}

void DemoBaiTap() {
    cout << "\n=== BAI TAP CHUONG 3 ===\n";

    List L;
    KhoiTaoDSLK(L);

    int arr[] = {7, 2, -3, 15, 4, -1, 9, 0, 25, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "  Danh sach:\n";
    for (int i = 0; i < n; ++i) {
        ThemCuoi(L, arr[i]);
    }
    InDanhSach(L);

    int chanDau = 0;
    int chanCuoi = 0;

    cout << "  So chan dau tien: "
         << (TimChanDau(L, chanDau) ? to_string(chanDau) : "Khong co") << "\n";
    cout << "  So chan cuoi cung: "
         << (TimChanCuoi(L, chanCuoi) ? to_string(chanCuoi) : "Khong co") << "\n";

    cout << "  Tong phan tu duong: " << TongDuong(L) << "\n";
    cout << "  Co so chinh phuong? " << (CoSoChinhPhuong(L) ? "Co" : "Khong") << "\n";

    List L2;
    KhoiTaoDSLK(L2);
    for (int x : {100, 200, 300}) {
        ThemCuoi(L2, x);
    }

    cout << "\n  Noi L va L2 = {100, 200, 300}:\n";
    NoiDanhSach(L, L2);
    InDanhSach(L);

    XoaDanhSach(L);
    XoaDanhSach(L2);
}

int main() {
    cout << "============================================================\n";
    cout << "  CHUONG 3: DANH SACH LIEN KET VA UNG DUNG\n";
    cout << "============================================================\n";

    DemoDSLK();
    DemoStack();
    DemoQueue();
    DemoBaiTap();

    cout << "\n============================================================\n";
    return 0;
}
