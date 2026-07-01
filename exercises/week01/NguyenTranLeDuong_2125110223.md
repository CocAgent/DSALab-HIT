/* 
 * DU AN 5: HE THONG RAP CHIEU PHIM
 * Cau truc: BST + Queue + Stack + 2D Array 
 * File: DuAn5_RapChieuPhim.cpp
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

// ============================================================
//  CAU HINH RAP
// ============================================================
const int HANG    = 8;
const int COT     = 10;
const int GIA_VE  = 80000; // 80,000 VND
const int MAX_UNDO = 5;

// ============================================================
//  BST: QUAN LY PHIM
// ============================================================
struct Phim {
    string maPhim;
    string tenPhim;
    string theLoai;
    int    thoiLuong; // phut
    string lichChieu;
    double doanhThu;

    Phim() : thoiLuong(0), doanhThu(0) {}
    Phim(string ma, string ten, string tl, int tl2, string lich)
        : maPhim(ma), tenPhim(ten), theLoai(tl), thoiLuong(tl2), lichChieu(lich), doanhThu(0) {}
};

struct NodeBST {
    Phim     phim;
    NodeBST* left;
    NodeBST* right;
    NodeBST(const Phim& p) : phim(p), left(nullptr), right(nullptr) {}
};

struct BST {
    NodeBST* root;
    BST() : root(nullptr) {}

    ~BST() { xoa(root); }

    void xoa(NodeBST* n) {
        if (!n) return;
        xoa(n->left); xoa(n->right); delete n;
    }

    void chen(const Phim& p) { root = chenNode(root, p); }

    NodeBST* chenNode(NodeBST* n, const Phim& p) {
        if (!n) return new NodeBST(p);
        if (p.maPhim < n->phim.maPhim) n->left  = chenNode(n->left,  p);
        else if (p.maPhim > n->phim.maPhim) n->right = chenNode(n->right, p);
        else cout << "  [!] Ma phim da ton tai!\n";
        return n;
    }

    NodeBST* tim(const string& ma) const { return timNode(root, ma); }

    NodeBST* timNode(NodeBST* n, const string& ma) const {
        if (!n) return nullptr;
        if (ma == n->phim.maPhim) return n;
        if (ma  < n->phim.maPhim) return timNode(n->left,  ma);
        return                           timNode(n->right, ma);
    }

    void xoaPhim(const string& ma) { root = xoaNode(root, ma); }

    NodeBST* minNode(NodeBST* n) {
        while (n->left) n = n->left;
        return n;
    }

    NodeBST* xoaNode(NodeBST* n, const string& ma) {
        if (!n) { cout << "  Khong tim thay phim!\n"; return nullptr; }
        if      (ma < n->phim.maPhim) n->left  = xoaNode(n->left,  ma);
        else if (ma > n->phim.maPhim) n->right = xoaNode(n->right, ma);
        else {
            if (!n->left)  { NodeBST* tmp = n->right; delete n; return tmp; }
            if (!n->right) { NodeBST* tmp = n->left;  delete n; return tmp; }
            NodeBST* succ  = minNode(n->right);
            n->phim        = succ->phim;
            n->right       = xoaNode(n->right, succ->phim.maPhim);
        }
        return n;
    }

    // Duyet In-order (A-Z theo maPhim)
    void inDanhSach() const {
        if (!root) { cout << "  (Chua co phim nao)\n"; return; }
        cout << "  " << left
             << setw(10) << "Ma phim"
             << setw(25) << "Ten phim"
             << setw(15) << "The loai"
             << setw(8)  << "Tg(ph)"
             << "Lich chieu\n";
        cout << "  " << string(70, '-') << "\n";
        inInOrder(root);
    }

    void inInOrder(NodeBST* n) const {
        if (!n) return;
        inInOrder(n->left);
        const Phim& p = n->phim;
        cout << "  " << left
             << setw(10) << p.maPhim
             << setw(25) << p.tenPhim
             << setw(15) << p.theLoai
             << setw(8)  << p.thoiLuong
             << p.lichChieu << "\n";
        inInOrder(n->right);
    }

    void thongKeDoanhThu() const {
        cout << "\n  --- DOANH THU THEO PHIM ---\n";
        thongKe(root);
    }

    void thongKe(NodeBST* n) const {
        if (!n) return;
        thongKe(n->left);
        if (n->phim.doanhThu > 0)
            cout << "  " << n->phim.tenPhim << ": "
                 << fixed << setprecision(0) << n->phim.doanhThu << " VND\n";
        thongKe(n->right);
    }
};

// ============================================================
//  SO DO GHE (2D ARRAY) + UNDO STACK + HOAN VE QUEUE
// ============================================================

struct ThaoTac {
    int hang, cot;
    char trangThai; // 'O'=dat, 'X'=huy
};

struct UndoStack {
    ThaoTac data[MAX_UNDO];
    int     top;
    UndoStack() : top(-1) {}
    bool isEmpty() const { return top == -1; }
    bool isFull()  const { return top == MAX_UNDO - 1; }
    void push(const ThaoTac& t) {
        if (isFull()) {
            for (int i = 0; i < top; i++) data[i] = data[i + 1];
            data[top] = t;
        } else {
            data[++top] = t;
        }
    }
    ThaoTac pop() { return data[top--]; }
};

const int MAX_QUEUE = 100;
struct HoanVeQueue {
    struct PhieuHoan {
        int    hang, cot;
        string tenKhach;
    };
    PhieuHoan data[MAX_QUEUE];
    int front, rear, soLuong;
    HoanVeQueue() : front(0), rear(0), soLuong(0) {}
    bool isEmpty() const { return soLuong == 0; }
    bool isFull()  const { return soLuong == MAX_QUEUE; }
    void enqueue(int h, int c, const string& ten) {
        if (isFull()) { cout << "  Hang hoan ve day!\n"; return; }
        data[rear] = {h, c, ten};
        rear = (rear + 1) % MAX_QUEUE;
        soLuong++;
    }
    PhieuHoan dequeue() {
        PhieuHoan p = data[front];
        front = (front + 1) % MAX_QUEUE;
        soLuong--;
        return p;
    }
    void inHang() const {
        if (isEmpty()) { cout << "  (Hang hoan ve trong)\n"; return; }
        int idx = front;
        for (int i = 0; i < soLuong; i++) {
            const PhieuHoan& p = data[(front + i) % MAX_QUEUE];
            cout << "  " << (i + 1) << ". " << p.tenKhach
                 << " | Ghe " << (char)('A' + p.hang) << (p.cot + 1) << "\n";
        }
    }
};

// ============================================================
//  PHONG CHIEU
// ============================================================
struct PhongChieu {
    char       ghe[HANG][COT];  // 'O'=trong, 'X'=da dat
    UndoStack  undoStack;
    HoanVeQueue hoanVeQueue;
    double     doanhThu;
    string     maPhimHienTai;

    PhongChieu() : doanhThu(0) {
        for (int i = 0; i < HANG; i++)
            for (int j = 0; j < COT; j++)
                ghe[i][j] = 'O';
    }

    void inSoDo() const {
        cout << "\n    ";
        for (int j = 0; j < COT; j++) cout << " " << setw(2) << (j + 1);
        cout << "\n";
        for (int i = 0; i < HANG; i++) {
            cout << "  " << (char)('A' + i) << " |";
            for (int j = 0; j < COT; j++) {
                if (ghe[i][j] == 'X') cout << " \033[31mX\033[0m ";
                else                  cout << " \033[32mO\033[0m ";
            }
            cout << "|\n";
        }
        cout << "\n  [O]=Trong  [X]=Da dat\n";
    }

    bool datVe(int h, int c) {
        if (h < 0 || h >= HANG || c < 0 || c >= COT) { cout << "  Ghe khong ton tai!\n"; return false; }
        if (ghe[h][c] == 'X') { cout << "  Ghe da bi dat!\n"; return false; }
        ghe[h][c] = 'X';
        undoStack.push({h, c, 'O'});
        doanhThu += GIA_VE;
        cout << "  Da dat ghe " << (char)('A' + h) << (c + 1) << " thanh cong!\n";
        return true;
    }

    bool huyVe(int h, int c) {
        if (h < 0 || h >= HANG || c < 0 || c >= COT) { cout << "  Ghe khong ton tai!\n"; return false; }
        if (ghe[h][c] == 'O') { cout << "  Ghe chua duoc dat!\n"; return false; }
        ghe[h][c] = 'O';
        undoStack.push({h, c, 'X'});
        doanhThu -= GIA_VE;
        cout << "  Da huy ghe " << (char)('A' + h) << (c + 1) << "\n";
        return true;
    }

    void undo() {
        if (undoStack.isEmpty()) { cout << "  Khong co thao tac nao de hoan tac!\n"; return; }
        ThaoTac t = undoStack.pop();
        if (t.trangThai == 'O') { // Hoan tac dat ve -> tra lai trong
            ghe[t.hang][t.cot] = 'O';
            doanhThu -= GIA_VE;
            cout << "  Hoan tac: Ghe " << (char)('A' + t.hang) << (t.cot + 1) << " -> Trong\n";
        } else {                   // Hoan tac huy ve -> dat lai
            ghe[t.hang][t.cot] = 'X';
            doanhThu += GIA_VE;
            cout << "  Hoan tac: Ghe " << (char)('A' + t.hang) << (t.cot + 1) << " -> Da dat\n";
        }
    }

    void doiGhe(int h1, int c1, int h2, int c2) {
        if (ghe[h1][c1] == 'O') { cout << "  Ghe nguon chua dat!\n"; return; }
        if (ghe[h2][c2] == 'X') { cout << "  Ghe dich da bi dat!\n"; return; }
        ghe[h1][c1] = 'O';
        ghe[h2][c2] = 'X';
        cout << "  Da doi tu " << (char)('A'+h1) << (c1+1)
             << " sang " << (char)('A'+h2) << (c2+1) << "\n";
    }

    void yeuCauHoanVe(const string& tenKhach, int h, int c) {
        if (ghe[h][c] != 'X') { cout << "  Ghe chua dat!\n"; return; }
        hoanVeQueue.enqueue(h, c, tenKhach);
        cout << "  Yeu cau hoan ve da duoc them vao hang doi.\n";
    }

    void xuLyHoanVe() {
        if (hoanVeQueue.isEmpty()) { cout << "  Khong co yeu cau hoan ve.\n"; return; }
        auto p = hoanVeQueue.dequeue();
        ghe[p.hang][p.cot] = 'O';
        doanhThu -= GIA_VE;
        cout << "  Da hoan ve cho " << p.tenKhach
             << " | Ghe " << (char)('A' + p.hang) << (p.cot + 1) << "\n";
    }

    int gheTrong() const {
        int dem = 0;
        for (int i = 0; i < HANG; i++)
            for (int j = 0; j < COT; j++)
                if (ghe[i][j] == 'O') dem++;
        return dem;
    }

    void xuatBaoCao(const string& tenPhim) const {
        cout << "\n  === BAO CAO PHONG CHIEU ===\n";
        cout << "  Phim        : " << tenPhim << "\n";
        cout << "  Tong ghe    : " << HANG * COT << "\n";
        cout << "  Ghe da dat  : " << (HANG * COT - gheTrong()) << "\n";
        cout << "  Ghe trong   : " << gheTrong() << "\n";
        cout << "  Doanh thu   : " << fixed << setprecision(0) << doanhThu << " VND\n";
        cout << "  Hang hoan ve: " << hoanVeQueue.soLuong << " yeu cau\n";
    }

    void xuatFile(const string& tenPhim) const {
        ofstream f("bao_cao_rap.txt");
        if (!f) { cout << "  Loi mo file!\n"; return; }
        f << "BAO CAO RAP CHIEU PHIM\n";
        f << "Phim: " << tenPhim << "\n";
        f << "Tong doanh thu: " << fixed << setprecision(0) << doanhThu << " VND\n\n";
        f << "So do ghe:\n   ";
        for (int j = 0; j < COT; j++) f << setw(3) << (j + 1);
        f << "\n";
        for (int i = 0; i < HANG; i++) {
            f << (char)('A' + i) << " |";
            for (int j = 0; j < COT; j++)
                f << " " << ghe[i][j] << " ";
            f << "|\n";
        }
        f.close();
        cout << "  Da xuat file \"bao_cao_rap.txt\"!\n";
    }
};

// ============================================================
//  TIEN ICH
// ============================================================
void duongKe(char c = '-', int n = 60) {
    for (int i = 0; i < n; i++) cout << c; cout << '\n';
}

bool docGhe(int& h, int& c) {
    cout << "  Nhap ghe (vi du A5): ";
    string s; cin >> s;
    if (s.size() < 2) return false;
    h = toupper(s[0]) - 'A';
    try { c = stoi(s.substr(1)) - 1; } catch (...) { return false; }
    return (h >= 0 && h < HANG && c >= 0 && c < COT);
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    BST       dsBST;
    PhongChieu phong;
    string    phimDangChieu = "(Chua chon)";
    int       lua;

    // Them phim mau
    dsBST.chen(Phim("P001", "Avengers: EndGame",     "Hanh dong", 181, "14:00 | 17:30 | 20:00"));
    dsBST.chen(Phim("P002", "Interstellar",           "Khoa hoc",  169, "13:00 | 16:00 | 19:30"));
    dsBST.chen(Phim("P003", "Your Name",              "Hoat hinh", 106, "10:00 | 14:00 | 17:00"));
    dsBST.chen(Phim("P004", "The Dark Knight",        "Toi pham",  152, "15:00 | 18:30 | 21:00"));
    dsBST.chen(Phim("P005", "Parasite",               "Drama",     132, "11:00 | 15:30 | 19:00"));

    do {
        duongKe('=');
        cout << "  RAP CHIEU PHIM | Phim hien chieu: " << phimDangChieu << "\n";
        duongKe();
        cout << "  --- QUAN LY PHIM (BST) ---\n";
        cout << "  1. Xem danh sach phim\n";
        cout << "  2. Tim phim theo ma\n";
        cout << "  3. Them phim moi\n";
        cout << "  4. Xoa phim\n";
        cout << "  5. Chon phim dang chieu\n";
        duongKe();
        cout << "  --- QUAN LY VE (2D Array + Stack + Queue) ---\n";
        cout << "  6. Xem so do ghe\n";
        cout << "  7. Dat ve\n";
        cout << "  8. Huy ve (truc tiep)\n";
        cout << "  9. Doi ghe\n";
        cout << "  10. Undo thao tac dat/huy (toi da " << MAX_UNDO << " lan)\n";
        cout << "  11. Yeu cau hoan ve (them vao hang doi)\n";
        cout << "  12. Xu ly hoan ve (FIFO)\n";
        cout << "  13. Xem hang doi hoan ve\n";
        duongKe();
        cout << "  --- BAO CAO ---\n";
        cout << "  14. Bao cao phong chieu\n";
        cout << "  15. Thong ke doanh thu theo phim\n";
        cout << "  16. Xuat bao cao ra file\n";
        cout << "  0. Thoat\n";
        duongKe('=');
        cout << "  Chon: "; cin >> lua;

        switch (lua) {

        case 1:
            cout << "\n";
            dsBST.inDanhSach();
            break;

        case 2: {
            cout << "  Nhap ma phim: "; string ma; cin >> ma;
            NodeBST* n = dsBST.tim(ma);
            if (!n) { cout << "  Khong tim thay!\n"; break; }
            const Phim& p = n->phim;
            cout << "\n  Tim thay:\n";
            cout << "  Ma: " << p.maPhim << " | Ten: " << p.tenPhim << "\n";
            cout << "  The loai: " << p.theLoai << " | TG: " << p.thoiLuong << " phut\n";
            cout << "  Lich: " << p.lichChieu << "\n";
            break;
        }

        case 3: {
            Phim p;
            cin.ignore();
            cout << "  Ma phim : "; cin >> p.maPhim;
            cin.ignore();
            cout << "  Ten phim: "; getline(cin, p.tenPhim);
            cout << "  The loai: "; getline(cin, p.theLoai);
            cout << "  Thoi luong (phut): "; cin >> p.thoiLuong;
            cin.ignore();
            cout << "  Lich chieu: "; getline(cin, p.lichChieu);
            dsBST.chen(p);
            cout << "  Da them phim!\n";
            break;
        }

        case 4: {
            cout << "  Ma phim can xoa: "; string ma; cin >> ma;
            dsBST.xoaPhim(ma);
            break;
        }

        case 5: {
            cout << "  Ma phim can chieu: "; string ma; cin >> ma;
            NodeBST* n = dsBST.tim(ma);
            if (!n) { cout << "  Khong tim thay phim!\n"; break; }
            phimDangChieu = n->phim.tenPhim;
            phong.maPhimHienTai = ma;
            // Reset phong
            for (int i = 0; i < HANG; i++)
                for (int j = 0; j < COT; j++)
                    phong.ghe[i][j] = 'O';
            cout << "  Da chon phim: " << phimDangChieu << "\n";
            break;
        }

        case 6:
            phong.inSoDo();
            break;

        case 7: {
            int h, c;
            if (docGhe(h, c)) {
                bool ok = phong.datVe(h, c);
                if (ok && !phong.maPhimHienTai.empty()) {
                    NodeBST* n = dsBST.tim(phong.maPhimHienTai);
                    if (n) n->phim.doanhThu += GIA_VE;
                }
            }
            break;
        }

        case 8: {
            int h, c;
            if (docGhe(h, c)) {
                bool ok = phong.huyVe(h, c);
                if (ok && !phong.maPhimHienTai.empty()) {
                    NodeBST* n = dsBST.tim(phong.maPhimHienTai);
                    if (n) n->phim.doanhThu -= GIA_VE;
                }
            }
            break;
        }

        case 9: {
            int h1, c1, h2, c2;
            cout << "  Ghe muon doi: ";
            if (!docGhe(h1, c1)) break;
            cout << "  Doi sang ghe: ";
            if (!docGhe(h2, c2)) break;
            phong.doiGhe(h1, c1, h2, c2);
            break;
        }

        case 10: phong.undo(); break;

        case 11: {
            int h, c;
            cout << "  Ghe can hoan ve: ";
            if (!docGhe(h, c)) break;
            cin.ignore();
            cout << "  Ten khach hang: "; string ten; getline(cin, ten);
            phong.yeuCauHoanVe(ten, h, c);
            break;
        }

        case 12: phong.xuLyHoanVe(); break;

        case 13:
            cout << "\n  --- Hang doi hoan ve ---\n";
            phong.hoanVeQueue.inHang();
            break;

        case 14:
            phong.xuatBaoCao(phimDangChieu);
            break;

        case 15:
            dsBST.thongKeDoanhThu();
            break;

        case 16:
            phong.xuatFile(phimDangChieu);
            break;

        case 0:
            cout << "  Tam biet!\n";
            break;

        default:
            cout << "  Lua chon khong hop le!\n";
        }

        if (lua != 0) {
            cout << "\n  [Nhan Enter de tiep tuc...]";
            cin.ignore(); cin.get();
        }

    } while (lua != 0);

    return 0;
}
