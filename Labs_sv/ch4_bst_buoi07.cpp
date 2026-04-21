// ============================================================
//  ch4_bst_buoi07.cpp
//  Bai tap 12 — Cay Nhi Phan Tim Kiem (BST)
//  Mon: Cau Truc Du Lieu & Giai Thuat  |  GV: Tran Anh Khoa
//
//  File nay gop 3 file goc lai de chay ngay:
//    BSTree.h  +  caidat.cpp  +  main.cpp
//
//  Compile:  g++ -std=c++17 ch4_bst_buoi07.cpp -o bst && ./bst
//  Windows:  g++ -std=c++17 ch4_bst_buoi07.cpp -o bst.exe
// ============================================================
//
//  PROMPT AI - DAN VAO CLAUDE / CHATGPT KHI CAN:
//  -----------------------------------------------
//  "Toi la sinh vien dang lam Bai tap 12 BST bang C++.
//   Toi dang o [Tiet ?]. Toi bi stuck o ham [ten ham].
//   Code cua toi: [paste code]. Khong viet code giup toi —
//   hay hoi toi 2 cau de tu tim ra van de."
// ============================================================

#include <iostream>
#include <algorithm>   // max()
#include <cstdlib>     // system()
using namespace std;

// ============================================================
// PHAN 1: BSTree.h — Khai bao cau truc & nguyen mau ham
// ============================================================

// Cau truc mot nut tren cay
struct NODE {
    int   key;       // Gia tri (khoa)
    NODE *pLeft;     // Con trai
    NODE *pRight;    // Con phai
};

// Cau truc cay nhi phan tim kiem
struct BIN_TREE {
    NODE *pRoot;     // Nut goc
    int   nCount;    // So luong nut hien co
};

// ── Nguyen mau ham (giao dien public) ────────────────────────
void  KhoiTao     (BIN_TREE &t);
NODE* TaoNut      (int x);
void  ThemNut     (NODE* &pRoot, int x);
void  TaoCay      (BIN_TREE &t);

void  NLR         (NODE* pRoot);           // Pre-order
void  LNR         (NODE* pRoot);           // In-order  (tang dan)
void  LRN         (NODE* pRoot);           // Post-order

NODE* BSTSearch   (NODE* pRoot, int x);
NODE* _SearchStandFor(NODE* &pRoot);       // Tim nut the mang
bool  BSTDelete   (NODE* &pRoot, int x);

int   TinhCC      (NODE* pRoot);           // Chieu cao cay
int   DemSoNut    (NODE* pRoot);           // So luong nut
NODE* TimMin      (NODE* pRoot);           // Nut nho nhat
NODE* TimMax      (NODE* pRoot);           // Nut lon nhat
void  XuatCayASCII(NODE* pRoot, int indent = 0); // Hien thi ASCII


// ============================================================
// PHAN 2: caidat.cpp — Cai dat chi tiet cac ham
// ============================================================

// ── Tiet 1: Khoi tao ─────────────────────────────────────────

// Khoi tao cay rong
void KhoiTao(BIN_TREE &t) {
    t.pRoot  = NULL;
    t.nCount = 0;
}

// Cap phat mot nut moi chua gia tri x
// AI PROMPT: "Tai sao TaoNut dung 'new' ma khong dung malloc?
//             Su khac biet giua new va malloc trong C++ la gi?"
NODE* TaoNut(int x) {
    NODE* p  = new NODE;
    p->key   = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

// ── Tiet 2: Them nut (BSTInsert) ─────────────────────────────
//
// AI PROMPT: "Giai thich tai sao ThemNut dung de quy.
//             Neu toi dung vong lap while thay the quy co duoc khong?
//             Hoi toi 2 cau de tu tim ra."
//
// Quy tac BST: nho hon -> sang trai | lon hon -> sang phai
// Nut trung (==) bo qua (khong them trung khoa)
void ThemNut(NODE* &pRoot, int x) {
    if (pRoot == NULL) {
        pRoot = TaoNut(x);   // Vi tri dung -> chen vao
        return;
    }
    if (x < pRoot->key)
        ThemNut(pRoot->pLeft,  x);  // Nho hon: di trai
    else if (x > pRoot->key)
        ThemNut(pRoot->pRight, x);  // Lon hon:  di phai
    // x == pRoot->key: bo qua (khong them trung)
}

// Nhap du lieu tu ban phim, xay dung cay
void TaoCay(BIN_TREE &t) {
    int x;
    cout << "\nNhap cac gia tri (nhap -1 de ket thuc):\n";
    while (true) {
        cout << "  Nhap x = "; cin >> x;
        if (x == -1) break;
        ThemNut(t.pRoot, x);
        t.nCount++;
    }
    cout << "Da tao cay voi " << t.nCount << " nut.\n";
}

// ── Tiet 3: Duyet cay (NLR / LNR / LRN) ─────────────────────
//
// AI PROMPT: "Tai sao LNR tren BST cho ket qua tang dan?
//             Chung minh bang vi du voi cay: goc=5, trai=3, phai=7"
//
// NLR (Pre-order): Goc -> Trai -> Phai
void NLR(NODE* pRoot) {
    if (pRoot == NULL) return;
    cout << pRoot->key << " ";
    NLR(pRoot->pLeft);
    NLR(pRoot->pRight);
}

// LNR (In-order): Trai -> Goc -> Phai  =>  KQ: tang dan
void LNR(NODE* pRoot) {
    if (pRoot == NULL) return;
    LNR(pRoot->pLeft);
    cout << pRoot->key << " ";
    LNR(pRoot->pRight);
}

// LRN (Post-order): Trai -> Phai -> Goc
void LRN(NODE* pRoot) {
    if (pRoot == NULL) return;
    LRN(pRoot->pLeft);
    LRN(pRoot->pRight);
    cout << pRoot->key << " ";
}

// ── Tiet 4: Tim kiem & Xoa nut ───────────────────────────────

// Tim nut co khoa x, tra ve con tro toi nut do (NULL neu khong co)
// AI PROMPT: "Toi hieu BSTSearch roi. Giai thich tai sao ham
//             nay tra ve NODE* thay vi bool?"
NODE* BSTSearch(NODE* pRoot, int x) {
    if (pRoot == NULL)       return NULL;        // Khong tim thay
    if (x == pRoot->key)    return pRoot;        // Tim thay
    if (x < pRoot->key)
        return BSTSearch(pRoot->pLeft,  x);      // Tim o nhanh trai
    return     BSTSearch(pRoot->pRight, x);      // Tim o nhanh phai
}

// Tim nut the mang (nut nho nhat cay con PHAI)
// Dung khi xoa nut co 2 con.
// AI PROMPT: "Tai sao chon nut nho nhat cay con PHAI lam the mang?
//             Co the chon nut lon nhat cay con TRAI khong?"
NODE* _SearchStandFor(NODE* &pRoot) {
    if (pRoot->pLeft == NULL) {
        // Day la nut nho nhat (khong con con trai)
        NODE* temp = pRoot;
        pRoot = pRoot->pRight;  // Noi lai nhanh phai vao vi tri
        return temp;
    }
    return _SearchStandFor(pRoot->pLeft);  // Di trai tim tiep
}

// Xoa nut co khoa x khoi cay
// 3 truong hop:
//   (1) Nut la (leaf)         -> xoa thang
//   (2) Nut co 1 con          -> noi con vao vi tri nut bi xoa
//   (3) Nut co 2 con          -> tim nut the mang thay the
// AI PROMPT: "Truoc khi xem code BSTDelete, hay tu ve 3 truong hop
//             tren giay. Nut nao se thay cho nut 32 trong cay:
//             goc=74, trai(32): trai=17 phai=50, phai(125)?"
bool BSTDelete(NODE* &pRoot, int x) {
    if (pRoot == NULL) return false;  // Khong tim thay

    if (x < pRoot->key)
        return BSTDelete(pRoot->pLeft,  x);  // Tim o nhanh trai
    if (x > pRoot->key)
        return BSTDelete(pRoot->pRight, x);  // Tim o nhanh phai

    // Tim thay nut can xoa (pRoot->key == x)
    NODE* del = pRoot;

    if (pRoot->pLeft == NULL) {
        // Truong hop 1 & 2a: khong co con trai
        pRoot = pRoot->pRight;

    } else if (pRoot->pRight == NULL) {
        // Truong hop 2b: khong co con phai
        pRoot = pRoot->pLeft;

    } else {
        // Truong hop 3: co ca 2 con
        // Tim nut the mang (nho nhat cay con phai)
        NODE* standFor = _SearchStandFor(pRoot->pRight);
        standFor->pLeft  = pRoot->pLeft;
        standFor->pRight = pRoot->pRight;
        pRoot = standFor;
    }

    delete del;
    return true;
}

// ── Tiet 5: Cac ham tien ich ─────────────────────────────────

// Chieu cao cay (so muc lon nhat)
// AI PROMPT: "Chung minh cong thuc: TinhCC = 1 + max(CC_trai, CC_phai).
//             Cay chi co 1 nut co chieu cao bao nhieu?"
int TinhCC(NODE* pRoot) {
    if (pRoot == NULL) return 0;
    return 1 + max(TinhCC(pRoot->pLeft), TinhCC(pRoot->pRight));
}

// Dem tong so nut tren cay
int DemSoNut(NODE* pRoot) {
    if (pRoot == NULL) return 0;
    return 1 + DemSoNut(pRoot->pLeft) + DemSoNut(pRoot->pRight);
}

// Tim nut nho nhat: di trai cho den khi khong con con trai
NODE* TimMin(NODE* pRoot) {
    if (pRoot == NULL)          return NULL;
    if (pRoot->pLeft == NULL)   return pRoot;  // La nut nho nhat
    return TimMin(pRoot->pLeft);
}

// Tim nut lon nhat: di phai cho den khi khong con con phai
NODE* TimMax(NODE* pRoot) {
    if (pRoot == NULL)          return NULL;
    if (pRoot->pRight == NULL)  return pRoot;  // La nut lon nhat
    return TimMax(pRoot->pRight);
}

// Hien thi cay dang ASCII (rotate 90 do sang trai)
// Cay doc tu trai sang phai = cay that nhin tu tren xuong
void XuatCayASCII(NODE* pRoot, int indent) {
    if (pRoot == NULL) return;
    XuatCayASCII(pRoot->pRight, indent + 4);
    cout << string(indent, ' ') << "[" << pRoot->key << "]\n";
    XuatCayASCII(pRoot->pLeft,  indent + 4);
}


// ============================================================
// PHAN 3: main.cpp — Menu dieu khien
// ============================================================

int Menu() {
    // system("cls"); // Windows
    system("clear"); // Linux/Mac - doi thanh "cls" tren Windows

    int cv, k = 0;
    cout << "\n ===  THAO TAC TREN CAY NHI PHAN TIM KIEM  === \n";
    cout << "\n 1. Nhap du lieu tao cay BST";              k++;
    cout << "\n 2. Duyet cay LNR (xuat day tang dan)";     k++;
    cout << "\n 3. Duyet cay NLR (Pre-order)";             k++;
    cout << "\n 4. Duyet cay LRN (Post-order)";            k++;
    cout << "\n 5. Tim kiem mot khoa tren cay";             k++;
    cout << "\n 6. Xoa mot nut tren cay";                   k++;
    cout << "\n 7. Tinh chieu cao cay";                     k++;
    cout << "\n 8. Dem so nut";                             k++;
    cout << "\n 9. Tim Min / Max";                          k++;
    cout << "\n10. Hien thi cay ASCII";                     k++;
    cout << "\n 0. Thoat";

    do {
        cout << "\n\n Nhap thao tac (0-" << k << "): ";
        cin  >> cv;
    } while (cv < 0 || cv > k);

    return cv;
}

int main() {
    BIN_TREE t;
    int cv, x;
    KhoiTao(t);

    // ── Demo nhanh voi day so co san (comment lai neu muon nhap tay) ──
    cout << "=== Demo nhanh voi day: 74 125 32 17 50 320 62 ===\n";
    for (int v : {74, 125, 32, 17, 50, 320, 62}) {
        ThemNut(t.pRoot, v);
        t.nCount++;
    }
    cout << "Cay ASCII:\n";
    XuatCayASCII(t.pRoot);
    cout << "\nLNR (tang dan): "; LNR(t.pRoot);
    cout << "\nChieu cao: " << TinhCC(t.pRoot);
    cout << "\nSo nut: "    << DemSoNut(t.pRoot);
    NODE* mn = TimMin(t.pRoot); if (mn) cout << "\nMin: " << mn->key;
    NODE* mx = TimMax(t.pRoot); if (mx) cout << "\nMax: " << mx->key;
    cout << "\n\n(Nhan Enter de vao Menu...)"; cin.ignore(); cin.get();

    // ── Menu chinh ────────────────────────────────────────────
    do {
        cv = Menu();
        cout << "\n";

        switch (cv) {
            case 1:
                KhoiTao(t);
                TaoCay(t);
                break;

            case 2:
                cout << "Ket qua duyet giua (LNR - tang dan):\n  ";
                LNR(t.pRoot);
                break;

            case 3:
                cout << "Ket qua duyet truoc (NLR):\n  ";
                NLR(t.pRoot);
                break;

            case 4:
                cout << "Ket qua duyet sau (LRN):\n  ";
                LRN(t.pRoot);
                break;

            case 5:
                cout << "Nhap gia tri can tim: "; cin >> x;
                if (BSTSearch(t.pRoot, x))
                    cout << "Tim thay nut co khoa " << x << "!";
                else
                    cout << "Khong ton tai nut co khoa " << x << ".";
                break;

            case 6:
                cout << "Nhap gia tri can xoa: "; cin >> x;
                if (BSTDelete(t.pRoot, x)) {
                    t.nCount--;
                    cout << "Da xoa nut " << x << " thanh cong!";
                } else {
                    cout << "Khong tim thay nut co khoa " << x << ".";
                }
                break;

            case 7:
                cout << "Chieu cao cua cay: " << TinhCC(t.pRoot);
                break;

            case 8:
                cout << "So nut hien co: " << DemSoNut(t.pRoot);
                break;

            case 9: {
                NODE* pMin = TimMin(t.pRoot);
                NODE* pMax = TimMax(t.pRoot);
                if (pMin) cout << "Min = " << pMin->key << "\n";
                if (pMax) cout << "Max = " << pMax->key;
                break;
            }

            case 10:
                cout << "Cay BST (doc tu trai sang phai = tu tren xuong):\n\n";
                XuatCayASCII(t.pRoot);
                break;
        }

        cout << "\n"; system("pause");
    } while (cv != 0);

    return 0;
}


// ============================================================
// GHI CHU: CACH CHIA 3 FILE THEO DE BAI GIANG VIEN
// ============================================================
// Khi nop bai, tach file nay thanh 3 file:
//
//   BSTree.h    <- PHAN 1 (struct + nguyen mau ham)
//   caidat.cpp  <- PHAN 2 (cai dat cac ham)
//   main.cpp    <- PHAN 3 (Menu + main)
//
// main.cpp them dong: #include "BSTree.h"
// caidat.cpp them dong: #include "BSTree.h"
//
// ============================================================
// PROMPT AI THAM KHAO — DAN VAO CLAUDE/CHATGPT:
// ============================================================
//
// HIEU CONCEPT:
//   "Giai thich BST Insert bang vi du voi day 74,125,32,17,50,320,62.
//    Ve cay tung buoc va cho biet LNR cho ket qua gi?"
//
// DEBUG:
//   "Code BSTDelete cua toi bi loi khi xoa nut co 2 con.
//    [paste code]. Chi ra loi, khong sua ho toi."
//
// REVIEW TRUOC NOP:
//   "Review code BST cua toi. Tap trung vao BSTDelete co
//    xu ly dung 3 truong hop khong? [paste 3 file]"
//
// HOI SAU HON:
//   "BST degenerate la gi? Khi nao xay ra?
//    AVL Tree giai quyet van de do nhu the nao?"
// ============================================================
