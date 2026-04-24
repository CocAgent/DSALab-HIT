// ============================================================
//  Chuong3_DanhSachLienKet.cpp
//  Noi dung: Con tro, DSLK don, Stack, Queue
//  Giao trinh: Cau truc du lieu & Giai thuat - CDCTTP.HCM
// ============================================================
#include <iostream>
#include <cmath>
using namespace std;

// ============================================================
//  CAU TRUC NUT (NODE)
// ============================================================
struct Node {
    int data;
    Node *next;
};

// ============================================================
//  KHAI BAO DANH SACH
// ============================================================
struct List {
    Node *head;
    Node *tail;
};

// ============================================================
//  KHOI TAO VA TIEN ICH
// ============================================================
void KhoiTaoDSLK(List &L) {
    L.head = L.tail = nullptr;
}

Node* TaoNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

bool DanhSachRong(const List &L) {
    return L.head == nullptr;
}

// ============================================================
//  THEM PHAN TU
// ============================================================

// Them vao dau
void ThemDau(List &L, int x) {
    Node *p = TaoNode(x);
    if (DanhSachRong(L)) {
        L.head = L.tail = p;
    } else {
        p->next = L.head;
        L.head = p;
    }
}

// Them vao cuoi
void ThemCuoi(List &L, int x) {
    Node *p = TaoNode(x);
    if (DanhSachRong(L)) {
        L.head = L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

// Them sau node q
void ThemSau(List &L, Node *q, int x) {
    if (q == nullptr) return;
    Node *p = TaoNode(x);
    p->next = q->next;
    q->next = p;
    if (q == L.tail) L.tail = p;
}

// Them truoc node q
void ThemTruoc(List &L, Node *q, int x) {
    if (q == nullptr) return;
    if (q == L.head) { ThemDau(L, x); return; }
    Node *p = TaoNode(x);
    Node *cur = L.head;
    while (cur->next != q) cur = cur->next;
    p->next = q;
    cur->next = p;
}

// ============================================================
//  XOA PHAN TU
// ============================================================

// Xoa dau
void XoaDau(List &L) {
    if (DanhSachRong(L)) return;
    Node *p = L.head;
    L.head = L.head->next;
    if (L.head == nullptr) L.tail = nullptr;
    delete p;
}

// Xoa cuoi
void XoaCuoi(List &L) {
    if (DanhSachRong(L)) return;
    if (L.head == L.tail) { delete L.head; L.head = L.tail = nullptr; return; }
    Node *cur = L.head;
    while (cur->next != L.tail) cur = cur->next;
    delete L.tail;
    L.tail = cur;
    L.tail->next = nullptr;
}

// Xoa node co gia tri x
bool XoaGiaTri(List &L, int x) {
    if (DanhSachRong(L)) return false;
    Node *cur = L.head, *prev = nullptr;
    while (cur != nullptr && cur->data != x) {
        prev = cur; cur = cur->next;
    }
    if (cur == nullptr) return false;
    if (prev == nullptr) XoaDau(L);
    else {
        prev->next = cur->next;
        if (cur == L.tail) L.tail = prev;
        delete cur;
    }
    return true;
}

// Giai phong bo nho
void XoaDanhSach(List &L) {
    while (!DanhSachRong(L)) XoaDau(L);
}

// ============================================================
//  DUYET DANH SACH
// ============================================================
void InDanhSach(const List &L) {
    if (DanhSachRong(L)) { cout << "  [Danh sach rong]\n"; return; }
    cout << "  HEAD -> ";
    Node *cur = L.head;
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next) cout << " -> ";
        cur = cur->next;
    }
    cout << " -> NULL\n";
}

// Tim phan tu lon nhat
int TimMax(const List &L) {
    if (DanhSachRong(L)) return -1;
    int mx = L.head->data;
    Node *cur = L.head->next;
    while (cur != nullptr) {
        if (cur->data > mx) mx = cur->data;
        cur = cur->next;
    }
    return mx;
}

// Tim phan tu x
Node* TimX(const List &L, int x) {
    Node *cur = L.head;
    while (cur != nullptr) {
        if (cur->data == x) return cur;
        cur = cur->next;
    }
    return nullptr;
}

// Tim chan dau
int TimChanDau(const List &L) {
    Node *cur = L.head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) return cur->data;
        cur = cur->next;
    }
    return -1;
}

// Tim chan cuoi
int TimChanCuoi(const List &L) {
    int kq = -1;
    Node *cur = L.head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) kq = cur->data;
        cur = cur->next;
    }
    return kq;
}

// Liet ke phan tu am
void LietKeAm(const List &L) {
    cout << "  Cac phan tu am: ";
    Node *cur = L.head;
    bool co = false;
    while (cur != nullptr) {
        if (cur->data < 0) { cout << cur->data << " "; co = true; }
        cur = cur->next;
    }
    if (!co) cout << "(khong co)";
    cout << "\n";
}

// Tinh tong phan tu duong
long long TongDuong(const List &L) {
    long long s = 0;
    Node *cur = L.head;
    while (cur != nullptr) {
        if (cur->data > 0) s += cur->data;
        cur = cur->next;
    }
    return s;
}

// Dem phan tu am
int DemAm(const List &L) {
    int dem = 0;
    Node *cur = L.head;
    while (cur != nullptr) {
        if (cur->data < 0) dem++;
        cur = cur->next;
    }
    return dem;
}

// Kiem tra so chinh phuong
bool LaChinhPhuong(int n) {
    if (n < 0) return false;
    int s = (int)sqrt((double)n);
    return s * s == n;
}

bool CoSoChinhPhuong(const List &L) {
    Node *cur = L.head;
    while (cur != nullptr) {
        if (LaChinhPhuong(cur->data)) return true;
        cur = cur->next;
    }
    return false;
}

// Dem phan tu cuc dai (lon nhat)
int DemCucDai(const List &L) {
    if (DanhSachRong(L)) return 0;
    int mx = TimMax(L), dem = 0;
    Node *cur = L.head;
    while (cur != nullptr) {
        if (cur->data == mx) dem++;
        cur = cur->next;
    }
    return dem;
}

// ============================================================
//  SAP XEP DSLK
// ============================================================
void SapXepChonTrucTiep(List &L) {
    for (Node *i = L.head; i != nullptr && i->next != nullptr; i = i->next)
        for (Node *j = i->next; j != nullptr; j = j->next)
            if (i->data > j->data) {
                int t = i->data; i->data = j->data; j->data = t;
            }
}

// ============================================================
//  NOI VA TACH DANH SACH
// ============================================================
void NoiDanhSach(List &L1, List &L2) {
    if (DanhSachRong(L2)) return;
    if (DanhSachRong(L1)) { L1 = L2; }
    else { L1.tail->next = L2.head; L1.tail = L2.tail; }
    L2.head = L2.tail = nullptr;
}

// Tach chan le: L -> L_chan, L_le
void TachChanLe(List &L, List &L_chan, List &L_le) {
    KhoiTaoDSLK(L_chan);
    KhoiTaoDSLK(L_le);
    Node *cur = L.head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) ThemCuoi(L_chan, cur->data);
        else ThemCuoi(L_le, cur->data);
        cur = cur->next;
    }
}

// ============================================================
//  STACK (Ngan xep - LIFO)
// ============================================================
struct Stack {
    Node *top;
};

void KhoiTaoStack(Stack &S) { S.top = nullptr; }
bool StackRong(const Stack &S) { return S.top == nullptr; }

void Push(Stack &S, int x) {
    Node *p = TaoNode(x);
    p->next = S.top;
    S.top = p;
}

int Pop(Stack &S) {
    if (StackRong(S)) { cout << "  Stack rong!\n"; return -1; }
    int val = S.top->data;
    Node *p = S.top;
    S.top = S.top->next;
    delete p;
    return val;
}

int PeekStack(const Stack &S) {
    if (StackRong(S)) return -1;
    return S.top->data;
}

void InStack(const Stack &S) {
    cout << "  Stack (TOP->BOT): ";
    Node *cur = S.top;
    while (cur) { cout << cur->data << " "; cur = cur->next; }
    cout << "\n";
}

// Ung dung Stack: Kiem tra dan ngoac
bool KiemTraNgoac(const string &s) {
    Stack S; KhoiTaoStack(S);
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') Push(S, c);
        else if (c == ')' || c == ']' || c == '}') {
            if (StackRong(S)) return false;
            int top = Pop(S);
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) return false;
        }
    }
    return StackRong(S);
}

// Ung dung Stack: Chuyen so thap phan sang nhi phan
string Dec2Bin(int n) {
    if (n == 0) return "0";
    Stack S; KhoiTaoStack(S);
    while (n > 0) { Push(S, n % 2); n /= 2; }
    string kq = "";
    while (!StackRong(S)) kq += to_string(Pop(S));
    return kq;
}

// ============================================================
//  QUEUE (Hang doi - FIFO)
// ============================================================
struct Queue {
    Node *front;
    Node *rear;
};

void KhoiTaoQueue(Queue &Q) { Q.front = Q.rear = nullptr; }
bool QueueRong(const Queue &Q) { return Q.front == nullptr; }

void Enqueue(Queue &Q, int x) {
    Node *p = TaoNode(x);
    if (QueueRong(Q)) Q.front = Q.rear = p;
    else { Q.rear->next = p; Q.rear = p; }
}

int Dequeue(Queue &Q) {
    if (QueueRong(Q)) { cout << "  Queue rong!\n"; return -1; }
    int val = Q.front->data;
    Node *p = Q.front;
    Q.front = Q.front->next;
    if (Q.front == nullptr) Q.rear = nullptr;
    delete p;
    return val;
}

void InQueue(const Queue &Q) {
    cout << "  Queue (FRONT->REAR): ";
    Node *cur = Q.front;
    while (cur) { cout << cur->data << " "; cur = cur->next; }
    cout << "\n";
}

// ============================================================
//  DEMO
// ============================================================
void DemoDSLK() {
    cout << "\n=== DEMO DANH SACH LIEN KET DON ===\n";
    List L; KhoiTaoDSLK(L);

    cout << "  Them cuoi: 10, 20, 30, 40, 50\n";
    for (int x : {10, 20, 30, 40, 50}) ThemCuoi(L, x);
    InDanhSach(L);

    cout << "  Them dau: 5\n";
    ThemDau(L, 5);
    InDanhSach(L);

    cout << "  Xoa dau:\n  ";
    XoaDau(L);
    InDanhSach(L);

    cout << "  Xoa cuoi:\n  ";
    XoaCuoi(L);
    InDanhSach(L);

    cout << "  Xoa gia tri 30:\n  ";
    XoaGiaTri(L, 30);
    InDanhSach(L);

    cout << "  Phan tu lon nhat: " << TimMax(L) << "\n";
    cout << "  Tim 20: ";
    Node *p = TimX(L, 20);
    cout << (p ? "Tim thay" : "Khong tim thay") << "\n";

    // Them cac so am de test
    ThemCuoi(L, -5); ThemCuoi(L, -8); ThemCuoi(L, 16);
    cout << "\n  Sau khi them -5, -8, 16: ";
    InDanhSach(L);

    LietKeAm(L);
    cout << "  Tong duong: " << TongDuong(L) << "\n";
    cout << "  Dem phan tu am: " << DemAm(L) << "\n";
    cout << "  Co so chinh phuong? " << (CoSoChinhPhuong(L) ? "Co" : "Khong") << "\n";
    cout << "  So phan tu cuc dai: " << DemCucDai(L) << "\n";

    // Sap xep
    cout << "\n  Sap xep DSLK:\n  ";
    SapXepChonTrucTiep(L);
    InDanhSach(L);

    // Tach
    List Lc, Ll;
    TachChanLe(L, Lc, Ll);
    cout << "  Danh sach chan: "; InDanhSach(Lc);
    cout << "  Danh sach le:  "; InDanhSach(Ll);

    XoaDanhSach(L);
    XoaDanhSach(Lc);
    XoaDanhSach(Ll);
}

void DemoStack() {
    cout << "\n=== DEMO STACK (NGAN XEP) ===\n";
    Stack S; KhoiTaoStack(S);

    cout << "  Push: 10, 20, 30, 40\n";
    for (int x : {10, 20, 30, 40}) Push(S, x);
    InStack(S);

    cout << "  Pop: " << Pop(S) << "\n";
    cout << "  Pop: " << Pop(S) << "\n";
    InStack(S);

    cout << "\n  [Ung dung 1] Kiem tra dan ngoac:\n";
    string test1 = "{[()]}";
    string test2 = "({[}])";
    cout << "    \"" << test1 << "\" => " << (KiemTraNgoac(test1) ? "Hop le" : "Khong hop le") << "\n";
    cout << "    \"" << test2 << "\" => " << (KiemTraNgoac(test2) ? "Hop le" : "Khong hop le") << "\n";

    cout << "\n  [Ung dung 2] Doi so thap phan -> nhi phan:\n";
    for (int n : {0, 5, 10, 42, 255}) {
        cout << "    " << n << " -> " << Dec2Bin(n) << "\n";
    }
}

void DemoQueue() {
    cout << "\n=== DEMO QUEUE (HANG DOI) ===\n";
    Queue Q; KhoiTaoQueue(Q);

    cout << "  Enqueue: 1, 2, 3, 4, 5\n";
    for (int x : {1, 2, 3, 4, 5}) Enqueue(Q, x);
    InQueue(Q);

    cout << "  Dequeue: " << Dequeue(Q) << "\n";
    cout << "  Dequeue: " << Dequeue(Q) << "\n";
    InQueue(Q);
}

// ============================================================
//  BAI TAP CHUONG 3 (theo sach)
// ============================================================
void DemoBaiTap() {
    cout << "\n=== BAI TAP CHUONG 3 ===\n";
    List L; KhoiTaoDSLK(L);

    // Tao danh sach tu nhap
    int arr[] = {7, 2, -3, 15, 4, -1, 9, 0, 25, -6};
    int n = 10;
    cout << "  Danh sach: ";
    for (int i = 0; i < n; i++) ThemCuoi(L, arr[i]);
    InDanhSach(L);

    // BT: Tim chan dau, chan cuoi
    int cd = TimChanDau(L);
    int cc = TimChanCuoi(L);
    cout << "  So chan dau tien: " << (cd == -1 ? "Khong co" : to_string(cd)) << "\n";
    cout << "  So chan cuoi cung: " << (cc == -1 ? "Khong co" : to_string(cc)) << "\n";

    // BT: Tong phan tu duong
    cout << "  Tong phan tu duong: " << TongDuong(L) << "\n";

    // BT: Kiem tra chinh phuong
    cout << "  Co so chinh phuong? " << (CoSoChinhPhuong(L) ? "Co" : "Khong") << "\n";

    // BT: Sap xep va noi
    List L2; KhoiTaoDSLK(L2);
    for (int x : {100, 200, 300}) ThemCuoi(L2, x);
    cout << "\n  Noi L va L2 = {100, 200, 300}:\n  ";
    NoiDanhSach(L, L2);
    InDanhSach(L);

    XoaDanhSach(L);
}

// ============================================================
//  MAIN
// ============================================================
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
