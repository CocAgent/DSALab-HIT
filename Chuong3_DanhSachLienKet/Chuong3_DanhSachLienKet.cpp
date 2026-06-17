// ============================================================
//  Chuong3_DanhSachLienKet.cpp
//  Noi dung: Con tro, DSLK don, Stack, Queue
//  Giao trinh: Cau truc du lieu & Giai thuat - CDCTTP.HCM
// ============================================================
// Thu vien chuan:
//   iostream : nhap/xuat (cin, cout)
//   cmath    : ham toan hoc (sqrt)
//   string   : xu ly chuoi ky tu
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// ============================================================
//  CAU TRUC NUT (NODE)
// ============================================================
// Moi nut chua:
//   data : gia tri luu tru (so nguyen)
//   next : con tro toi nut tiep theo; nullptr neu la nut cuoi
//
//   [ data | next ] --> [ data | next ] --> nullptr
struct Node {
    int data;   // gia tri cua nut
    Node* next; // tro toi nut ke tiep
};

// ============================================================
//  KHAI BAO DANH SACH
// ============================================================
// Danh sach lien ket don gom 2 con tro:
//   head : tro toi nut DAU tien (dung de duyet tu dau)
//   tail : tro toi nut CUOI cung (dung them cuoi O(1))
//
//   List: head --> [n1] --> [n2] --> ... --> [nk] <-- tail
struct List {
    Node* head; // con tro dau danh sach
    Node* tail; // con tro cuoi danh sach
};

// ============================================================
//  KHOI TAO VA TIEN ICH
// ============================================================

// Khoi tao danh sach rong: ca head va tail deu tro vao nullptr
void KhoiTaoDSLK(List& L) {
    L.head = L.tail = nullptr;
}

// Cap phat mot nut moi tren heap voi gia tri x.
// Tra ve con tro toi nut vua tao; nut chua tro vao nullptr.
Node* TaoNode(int x) {
    Node* p = new Node; // cap phat dong
    p->data = x;
    p->next = nullptr;
    return p;
}

// Kiem tra danh sach co rong khong (head == nullptr).
bool DanhSachRong(const List& L) {
    return L.head == nullptr;
}

// ============================================================
//  THEM PHAN TU
// ============================================================

// 1 - Them vao DAU danh sach   O(1)
//   Neu rong: nut moi dong thoi la head va tail.
//   Neu khong rong: nut moi tro vao head cu, cap nhat head.
//
//   Truoc: head -> [20] -> [30]
//   Sau : head -> [10] -> [20] -> [30]
void ThemDau(List& L, int x) {
    Node* p = TaoNode(x);
    if (DanhSachRong(L)) {
        L.head = L.tail = p;       // danh sach chi co 1 nut
    } else {
        p->next = L.head;          // p tro vao nut dau cu
        L.head = p;                // cap nhat head = nut moi
    }
}

// 2 - Them vao CUOI danh sach   O(1) nho co tail
//   Neu rong: tuong tu ThemDau.
//   Neu khong rong: tail cu tro vao p, cap nhat tail = p.
//
//   Truoc: [10] -> [20] <- tail
//   Sau : [10] -> [20] -> [30] <- tail
void ThemCuoi(List& L, int x) {
    Node* p = TaoNode(x);
    if (DanhSachRong(L)) {
        L.head = L.tail = p;
    } else {
        L.tail->next = p;          // nut cuoi cu tro sang p
        L.tail = p;                // cap nhat tail = p
    }
}

// 3 - Them sau mot nut q cu the   O(1)
//   - Neu q == nullptr: khong lam gi (tranh loi).
//   - Neu q la tail: them xong cap nhat tail.
//
//   Truoc: [q] -> [qNext]
//   Sau : [q] -> [p] -> [qNext]
void ThemSau(List& L, Node* q, int x) {
    if (q == nullptr) return;
    Node* p = TaoNode(x);
    p->next = q->next;             // p tro vao nut sau q
    q->next = p;                   // q gio tro vao p
    if (q == L.tail) L.tail = p;  // neu them sau cuoi, cap nhat tail
}

// 4 - Them truoc mot nut q cu the   O(n)
//   - Neu q la head: goi ThemDau de xu ly dung.
//   - Neu khong: duyet tim nut ngay truoc q (prev),
//     chen p vao giua prev va q.
//
//   Truoc: [prev] -> [q]
//   Sau : [prev] -> [p] -> [q]
void ThemTruoc(List& L, Node* q, int x) {
    if (q == nullptr) return;
    if (q == L.head) { ThemDau(L, x); return; }
    Node* p = TaoNode(x);
    Node* cur = L.head;
    while (cur->next != q) cur = cur->next; // tim prev
    p->next = q;                            // p tro vao q
    cur->next = p;                          // prev tro vao p
}

// ============================================================
//  XOA PHAN TU
// ============================================================

// 5 - Xoa nut DAU   O(1)
//   Giu con tro p vao nut dau, tien head len, giai phong p.
//   Neu sau khi xoa danh sach rong thi dat tail = nullptr.
//
//   Truoc: head -> [10] -> [20] -> [30]
//   Sau : head ->         [20] -> [30]
void XoaDau(List& L) {
    if (DanhSachRong(L)) return;
    Node* p = L.head;
    L.head = L.head->next;               // tien head len 1 buoc
    if (L.head == nullptr) L.tail = nullptr; // danh sach gio rong
    delete p;                            // giai phong nut cu
}

// 6 - Xoa nut CUOI   O(n)
//   Phai duyet den nut ke truoc tail (vi DSLK don khong co prev).
//   Cap nhat tail = nut do, dat next = nullptr.
//
//   Truoc: ... -> [40] -> [50] <- tail
//   Sau : ... -> [40] <- tail
void XoaCuoi(List& L) {
    if (DanhSachRong(L)) return;
    if (L.head == L.tail) {             // chi con 1 nut
        delete L.head;
        L.head = L.tail = nullptr;
        return;
    }
    Node* cur = L.head;
    while (cur->next != L.tail) cur = cur->next; // tim nut truoc tail
    delete L.tail;                      // xoa nut cuoi cu
    L.tail = cur;                       // nut truoc gio la tail
    L.tail->next = nullptr;
}

// 7 - Xoa nut DAU TIEN co gia tri x   O(n)
//   Tra ve true neu tim thay va xoa, false neu khong tim thay.
//   Dung con tro prev de noi lai chuoi sau khi xoa.
bool XoaGiaTri(List& L, int x) {
    if (DanhSachRong(L)) return false;
    Node* cur = L.head, *prev = nullptr;
    // Tim nut co data == x
    while (cur != nullptr && cur->data != x) {
        prev = cur; cur = cur->next;
    }
    if (cur == nullptr) return false;   // khong tim thay
    if (prev == nullptr) XoaDau(L);     // xoa nut dau
    else {
        prev->next = cur->next;         // bo qua cur
        if (cur == L.tail) L.tail = prev; // cap nhat tail neu can
        delete cur;
    }
    return true;
}

// Giai phong toan bo bo nho cua danh sach (xoa tung nut tu dau).
void XoaDanhSach(List& L) {
    while (!DanhSachRong(L)) XoaDau(L);
}

// ============================================================
//  8 - DUYET DANH SACH (in ra man hinh)
// ============================================================
// Duyet tu head den nullptr, in gia tri va mui ten ->
// Mau: HEAD -> 10 -> 20 -> 30 -> NULL
void InDanhSach(const List& L) {
    if (DanhSachRong(L)) { cout << "  [Danh sach rong]\n"; return; }
    cout << "  HEAD -> ";
    Node* cur = L.head;
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next) cout << " -> ";
        cur = cur->next;
    }
    cout << " -> NULL\n";
}

// 9 - Tim phan tu LON NHAT   O(n)
//   Khoi tao max = data cua head, duyet so sanh tung nut.
int TimMax(const List& L) {
    if (DanhSachRong(L)) return -1;
    int mx = L.head->data;
    Node* cur = L.head->next;
    while (cur != nullptr) {
        if (cur->data > mx) mx = cur->data;
        cur = cur->next;
    }
    return mx;
}

// 10 - Tim nut DAU TIEN co gia tri x   O(n)
//   Tra ve con tro toi nut tim thay, nullptr neu khong co.
Node* TimX(const List& L, int x) {
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data == x) return cur;
        cur = cur->next;
    }
    return nullptr;
}

// 11 - Tim so CHAN DAU TIEN trong danh sach   O(n)
//   Tra ve gia tri cua so chan dau tien gap, -1 neu khong co.
int TimChanDau(const List& L) {
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) return cur->data;
        cur = cur->next;
    }
    return -1;
}

// 12 - Tim so CHAN CUOI CUNG trong danh sach   O(n)
//   Duyet toan bo, ghi de bien kq moi khi gap so chan.
//   Cuoi vong lap, kq = so chan cuoi cung.
int TimChanCuoi(const List& L) {
    int kq = -1;
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) kq = cur->data;
        cur = cur->next;
    }
    return kq;
}

// 13 - Liet ke tat ca phan tu AM (< 0)
void LietKeAm(const List& L) {
    cout << "  Cac phan tu am: ";
    Node* cur = L.head;
    bool co = false;
    while (cur != nullptr) {
        if (cur->data < 0) { cout << cur->data << " "; co = true; }
        cur = cur->next;
    }
    if (!co) cout << "(khong co)";
    cout << "\n";
}

// 14 - Tinh TONG cac phan tu DUONG (> 0)   O(n)
//   Dung long long tranh tran so voi danh sach lon.
long long TongDuong(const List& L) {
    long long s = 0;
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data > 0) s += cur->data;
        cur = cur->next;
    }
    return s;
}

// 15 - Dem so phan tu AM trong danh sach   O(n)
int DemAm(const List& L) {
    int dem = 0;
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data < 0) dem++;
        cur = cur->next;
    }
    return dem;
}

// 16 - Kiem tra mot so co phai SO CHINH PHUONG khong
//   n la chinh phuong neu sqrt(n) nguyen, tuc s*s == n.
//   Vi du: 0, 1, 4, 9, 16, 25 ... la chinh phuong.
bool LaChinhPhuong(int n) {
    if (n < 0) return false;
    int s = (int)sqrt((double)n);
    return s * s == n;  // tranh sai so dau phay dong
}

// Kiem tra danh sach co chua IT NHAT MOT so chinh phuong.
bool CoSoChinhPhuong(const List& L) {
    Node* cur = L.head;
    while (cur != nullptr) {
        if (LaChinhPhuong(cur->data)) return true;
        cur = cur->next;
    }
    return false;
}

// 17 - Dem so lan xuat hien cua PHAN TU CUC DAI   O(n)
//   Buoc 1: Tim max bang TimMax.
//   Buoc 2: Duyet dem so nut co data == max.
int DemCucDai(const List& L) {
    if (DanhSachRong(L)) return 0;
    int mx = TimMax(L), dem = 0;
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data == mx) dem++;
        cur = cur->next;
    }
    return dem;
}

// ============================================================
//  SAP XEP DSLK - Chon truc tiep (Selection Sort)   O(n^2)
// ============================================================
// Y tuong: vong ngoai i chay tu dau den gan cuoi,
//   vong trong j chay tu i->next den cuoi.
//   Neu i->data > j->data thi hoan doi DATA (khong hoan doi nut).
//   Vong lap hoan thanh: danh sach da sap xep tang dan.
void SapXepChonTrucTiep(List& L) {
    for (Node* i = L.head; i != nullptr && i->next != nullptr; i = i->next)
        for (Node* j = i->next; j != nullptr; j = j->next)
            if (i->data > j->data) {
                int t = i->data; i->data = j->data; j->data = t;
            }
}

// ============================================================
//  NOI VA TACH DANH SACH
// ============================================================

// Noi L2 vao sau L1   O(1) - chi thay doi con tro, khong sao chep
//   Sau khi noi: L2 bi "lam rong" (L2.head = L2.tail = nullptr)
//   vi cac nut cua L2 gio thuoc ve L1.
//
//   L1: [a]->[b]->nullptr        L2: [c]->[d]->nullptr
//   Sau: L1: [a]->[b]->[c]->[d]->nullptr   L2: rong
void NoiDanhSach(List& L1, List& L2) {
    if (DanhSachRong(L2)) return;
    if (DanhSachRong(L1)) { L1 = L2; }
    else { L1.tail->next = L2.head; L1.tail = L2.tail; }
    L2.head = L2.tail = nullptr; // L2 khong con quan ly nut nao
}

// Tach danh sach L thanh hai danh sach chan va le
//   L_chan: chua cac phan tu chan (data % 2 == 0)
//   L_le  : chua cac phan tu le  (data % 2 != 0)
//   Giu nguyen thu tu xuat hien trong L goc.
//   L goc KHONG bi thay doi (chi doc data, them vao DS moi).
void TachChanLe(List& L, List& L_chan, List& L_le) {
    KhoiTaoDSLK(L_chan);
    KhoiTaoDSLK(L_le);
    Node* cur = L.head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) ThemCuoi(L_chan, cur->data);
        else                     ThemCuoi(L_le, cur->data);
        cur = cur->next;
    }
}

// ============================================================
//  STACK (Ngan xep - LIFO: Last In, First Out)
// ============================================================
// Cai dat Stack bang DSLK don:
//   top tro den nut DAU cua DSLK = dinh stack.
//   Push: them vao dau (ThemDau) -> O(1)
//   Pop : xoa khoi dau (XoaDau)  -> O(1)
//
//   Push(3)  Push(7)  Push(1)
//   top->[ 1 ]->[ 7 ]->[ 3 ]->nullptr
//   (Dinh = 1, Day = 3)
struct Stack {
    Node* top; // con tro den dinh stack
};

// Khoi tao stack rong
void KhoiTaoStack(Stack& S) { S.top = nullptr; }

// Kiem tra stack rong chua
bool StackRong(const Stack& S) { return S.top == nullptr; }

// Push x vao dinh stack   O(1)
//   Tao nut moi, nut moi tro vao top cu, cap nhat top.
//   Truoc: top -> [old]
//   Sau : top -> [x] -> [old]
void Push(Stack& S, int x) {
    Node* p = TaoNode(x);
    p->next = S.top;  // p tro vao dinh cu
    S.top = p;        // dinh moi = p
}

// Pop: lay va xoa phan tu o DINH stack   O(1)
//   Giu con tro nut dinh, chuyen top xuong nut ke, xoa nut dinh.
//   Tra ve gia tri lay ra; tra -1 va bao loi neu stack rong.
int Pop(Stack& S) {
    if (StackRong(S)) { cout << "  Stack rong!\n"; return -1; }
    int val = S.top->data;
    Node* p = S.top;
    S.top = S.top->next; // ha dinh xuong 1 buoc
    delete p;
    return val;
}

// Peek: xem gia tri DINH ma khong xoa   O(1)
int PeekStack(const Stack& S) {
    if (StackRong(S)) return -1;
    return S.top->data;
}

// In stack tu dinh xuong day
void InStack(const Stack& S) {
    cout << "  Stack (TOP->BOT): ";
    Node* cur = S.top;
    while (cur) { cout << cur->data << " "; cur = cur->next; }
    cout << "\n";
}

// -------- Ung dung Stack 1: Kiem tra dan ngoac -----------
// Thuat toan:
//   - Duyet tung ky tu trong chuoi s.
//   - Gap ngoac MO ( [ { : push vao stack.
//   - Gap ngoac DONG ) ] } :
//       + Neu stack rong -> khong co ngoac mo tuong ung -> KHONG hop le.
//       + Pop dinh stack, kiem tra co khop voi ngoac dong khong.
//   - Cuoi cung: stack phai RONG moi hop le (moi ngoac mo da duoc dong).
//
//   Vi du: "{[()]}"
//   Push '{', Push '[', Push '('
//   Gap ')': Pop '(' -> khop OK
//   Gap ']': Pop '[' -> khop OK
//   Gap '}': Pop '{' -> khop OK
//   Stack rong -> HOP LE
bool KiemTraNgoac(const string& s) {
    Stack S; KhoiTaoStack(S);
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            Push(S, c);                          // ngoac mo: push
        else if (c == ')' || c == ']' || c == '}') {
            if (StackRong(S)) return false;      // chua co ngoac mo
            int top = Pop(S);
            // kiem tra tung cap ngoac
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;                    // sai cap ngoac
        }
        // bo qua ky tu khac (chu so, phep toan, khoang trang ...)
    }
    return StackRong(S); // hop le <=> stack rong
}

// -------- Ung dung Stack 2: Doi thap phan -> nhi phan ----
// Thuat toan chia lay du:
//   Chia n cho 2 lien tiep, push tung phan du (0 hoac 1) vao stack.
//   Pop stack de lay cac bit tu cao den thap.
//
//   Vi du: n = 10
//   10 / 2 = 5 du 0  -> Push 0
//    5 / 2 = 2 du 1  -> Push 1
//    2 / 2 = 1 du 0  -> Push 0
//    1 / 2 = 0 du 1  -> Push 1
//   Pop: 1 0 1 0 -> "1010"
string Dec2Bin(int n) {
    if (n == 0) return "0";
    Stack S; KhoiTaoStack(S);
    while (n > 0) { Push(S, n % 2); n /= 2; }
    string kq = "";
    while (!StackRong(S)) kq += to_string(Pop(S));
    return kq;
}

// ============================================================
//  QUEUE (Hang doi - FIFO: First In, First Out)
// ============================================================
// Cai dat Queue bang DSLK don:
//   front : dau hang (lay ra tu day)
//   rear  : cuoi hang (vao tu phia nay)
//
//   Enqueue: them vao REAR (O(1) nho co con tro rear)
//   Dequeue: lay khoi FRONT (O(1))
//
//   front -> [1] -> [2] -> [3] <- rear
//   Dequeue lay [1], Enqueue them [4]:
//   front -> [2] -> [3] -> [4] <- rear
struct Queue {
    Node* front; // dau hang doi (Dequeue tai day)
    Node* rear;  // cuoi hang doi (Enqueue tai day)
};

// Khoi tao hang doi rong
void KhoiTaoQueue(Queue& Q) { Q.front = Q.rear = nullptr; }

// Kiem tra hang doi rong chua
bool QueueRong(const Queue& Q) { return Q.front == nullptr; }

// Enqueue: them x vao CUOI hang doi   O(1)
void Enqueue(Queue& Q, int x) {
    Node* p = TaoNode(x);
    if (QueueRong(Q)) Q.front = Q.rear = p;  // hang rong: p la ca front lan rear
    else { Q.rear->next = p; Q.rear = p; }   // noi rear cu vao p, cap nhat rear
}

// Dequeue: lay va xoa phan tu o DAU hang doi   O(1)
//   Giu con tro front, tien front len, xoa nut cu.
//   Tra ve gia tri lay ra; bao loi neu rong.
int Dequeue(Queue& Q) {
    if (QueueRong(Q)) { cout << "  Queue rong!\n"; return -1; }
    int val = Q.front->data;
    Node* p = Q.front;
    Q.front = Q.front->next;                  // tien front len 1
    if (Q.front == nullptr) Q.rear = nullptr; // hang rong sau khi lay
    delete p;
    return val;
}

// In hang doi tu front den rear
void InQueue(const Queue& Q) {
    cout << "  Queue (FRONT->REAR): ";
    Node* cur = Q.front;
    while (cur) { cout << cur->data << " "; cur = cur->next; }
    cout << "\n";
}

// ============================================================
//  DEMO DANH SACH LIEN KET DON
// ============================================================
void DemoDSLK() {
    cout << "\n=== DEMO DANH SACH LIEN KET DON ===\n";
    List L; KhoiTaoDSLK(L);

    // Tao danh sach: 10 -> 20 -> 30 -> 40 -> 50
    cout << "  Them cuoi: 10, 20, 30, 40, 50\n";
    for (int x : {10, 20, 30, 40, 50}) ThemCuoi(L, x);
    InDanhSach(L);

    // Them 5 vao dau: 5 -> 10 -> 20 -> 30 -> 40 -> 50
    cout << "  Them dau: 5\n";
    ThemDau(L, 5);
    InDanhSach(L);

    // Xoa dau (5): 10 -> 20 -> 30 -> 40 -> 50
    cout << "  Xoa dau:\n  ";
    XoaDau(L);
    InDanhSach(L);

    // Xoa cuoi (50): 10 -> 20 -> 30 -> 40
    cout << "  Xoa cuoi:\n  ";
    XoaCuoi(L);
    InDanhSach(L);

    // Xoa nut co gia tri 30: 10 -> 20 -> 40
    cout << "  Xoa gia tri 30:\n  ";
    XoaGiaTri(L, 30);
    InDanhSach(L);

    // Tim gia tri lon nhat va tim nut
    cout << "  Phan tu lon nhat: " << TimMax(L) << "\n";
    cout << "  Tim 20: ";
    Node* p = TimX(L, 20);
    cout << (p ? "Tim thay" : "Khong tim thay") << "\n";

    // Bo sung them du lieu de test cac ham thong ke
    ThemCuoi(L, -5); ThemCuoi(L, -8); ThemCuoi(L, 16);
    cout << "\n  Sau khi them -5, -8, 16: ";
    InDanhSach(L);

    LietKeAm(L);
    cout << "  Tong duong: " << TongDuong(L) << "\n";
    cout << "  Dem phan tu am: " << DemAm(L) << "\n";
    cout << "  Co so chinh phuong? " << (CoSoChinhPhuong(L) ? "Co" : "Khong") << "\n";
    cout << "  So phan tu cuc dai: " << DemCucDai(L) << "\n";

    // Sap xep tang dan bang Selection Sort
    cout << "\n  Sap xep DSLK:\n  ";
    SapXepChonTrucTiep(L);
    InDanhSach(L);

    // Tach danh sach thanh chan va le
    List Lc, Ll;
    TachChanLe(L, Lc, Ll);
    cout << "  Danh sach chan: "; InDanhSach(Lc);
    cout << "  Danh sach le:  "; InDanhSach(Ll);

    // Giai phong bo nho truoc khi ket thuc ham
    XoaDanhSach(L);
    XoaDanhSach(Lc);
    XoaDanhSach(Ll);
}

// ============================================================
//  DEMO STACK
// ============================================================
void DemoStack() {
    cout << "\n=== DEMO STACK (NGAN XEP) ===\n";
    Stack S; KhoiTaoStack(S);

    // Push 4 phan tu: dinh = 40, day = 10
    cout << "  Push: 10, 20, 30, 40\n";
    for (int x : {10, 20, 30, 40}) Push(S, x);
    InStack(S);

    // Pop 2 lan: lay ra 40 roi 30
    cout << "  Pop: " << Pop(S) << "\n"; // 40
    cout << "  Pop: " << Pop(S) << "\n"; // 30
    InStack(S);

    // Ung dung 1: Kiem tra dan ngoac
    cout << "\n  [Ung dung 1] Kiem tra dan ngoac:\n";
    string test1 = "{[()]}";   // hop le
    string test2 = "({[}])";   // sai: '}' dong truoc khi '[' duoc dong
    cout << "    \"" << test1 << "\" => " << (KiemTraNgoac(test1) ? "Hop le" : "Khong hop le") << "\n";
    cout << "    \"" << test2 << "\" => " << (KiemTraNgoac(test2) ? "Hop le" : "Khong hop le") << "\n";

    // Ung dung 2: Doi thap phan sang nhi phan
    cout << "\n  [Ung dung 2] Doi so thap phan -> nhi phan:\n";
    for (int n : {0, 5, 10, 42, 255}) {
        cout << "    " << n << " -> " << Dec2Bin(n) << "\n";
    }
}

// ============================================================
//  DEMO QUEUE
// ============================================================
void DemoQueue() {
    cout << "\n=== DEMO QUEUE (HANG DOI) ===\n";
    Queue Q; KhoiTaoQueue(Q);

    // Enqueue 5 phan tu: front=1, rear=5
    cout << "  Enqueue: 1, 2, 3, 4, 5\n";
    for (int x : {1, 2, 3, 4, 5}) Enqueue(Q, x);
    InQueue(Q);

    // Dequeue 2 lan: lay 1 roi 2 (FIFO)
    cout << "  Dequeue: " << Dequeue(Q) << "\n"; // 1
    cout << "  Dequeue: " << Dequeue(Q) << "\n"; // 2
    InQueue(Q);
}

// ============================================================
//  BAI TAP CHUONG 3 (theo sach)
// ============================================================
void DemoBaiTap() {
    cout << "\n=== BAI TAP CHUONG 3 ===\n";
    List L; KhoiTaoDSLK(L);

    // Tao danh sach co ca so am, so duong, so chan, so le, so chinh phuong
    int arr[] = { 7, 2, -3, 15, 4, -1, 9, 0, 25, -6 };
    int n = 10;
    cout << "  Danh sach: ";
    for (int i = 0; i < n; i++) ThemCuoi(L, arr[i]);
    InDanhSach(L);

    // Ket qua mong doi:
    //   Chan dau tien : 2  (vi tri thu 2)
    //   Chan cuoi cung: -6 (vi tri cuoi cung)
    int cd = TimChanDau(L);
    int cc = TimChanCuoi(L);
    cout << "  So chan dau tien: " << (cd == -1 ? "Khong co" : to_string(cd)) << "\n";
    cout << "  So chan cuoi cung: " << (cc == -1 ? "Khong co" : to_string(cc)) << "\n";

    // Tong duong: 7 + 2 + 15 + 4 + 9 + 25 = 62
    cout << "  Tong phan tu duong: " << TongDuong(L) << "\n";

    // Chinh phuong: 0=0^2, 9=3^2, 25=5^2 -> Co
    cout << "  Co so chinh phuong? " << (CoSoChinhPhuong(L) ? "Co" : "Khong") << "\n";

    // Noi L vao sau L (them L2 = {100, 200, 300})
    List L2; KhoiTaoDSLK(L2);
    for (int x : {100, 200, 300}) ThemCuoi(L2, x);
    cout << "\n  Noi L va L2 = {100, 200, 300}:\n  ";
    NoiDanhSach(L, L2); // L2 bi lam rong sau khi noi
    InDanhSach(L);

    XoaDanhSach(L);
}

// ============================================================
//  MAIN - Diem vao chuong trinh
// ============================================================
int main() {
    cout << "============================================================\n";
    cout << "  CHUONG 3: DANH SACH LIEN KET VA UNG DUNG\n";
    cout << "============================================================\n";

    DemoDSLK();   // minh hoa cac thao tac co ban tren DSLK don
    DemoStack();  // minh hoa Stack va 2 ung dung
    DemoQueue();  // minh hoa Queue
    DemoBaiTap(); // giai cac bai tap chuong 3

    cout << "\n============================================================\n";
    return 0; // tra ve 0 bao hieu chuong trinh ket thuc thanh cong
}
