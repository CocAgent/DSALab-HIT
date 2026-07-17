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

//bstree.h
// Cấu trúc Node
typedef struct tagBT_NODE
{
    int Data;
    tagBT_NODE* pLeft;
    tagBT_NODE* pRight;
} BT_NODE;

// Cấu trúc cây
typedef struct tagBIN_TREE
{
    BT_NODE* pRoot;
    int nCount;
} BIN_TREE;

// ===== KHAI BÁO HÀM =====
void KhoiTao(BIN_TREE& t);
BT_NODE* TaoNut(int x);
int BSTInsert(BT_NODE*& pCurr, int newkey);
void TaoCay(BIN_TREE& t);
 //Duyệt
void LNR(BT_NODE* pRoot);
void NLR(BT_NODE* pRoot);
void LRN(BT_NODE* pRoot);
// Tìm kiếm
BT_NODE* BSTSearch(BT_NODE* pRoot, int x);
//Xóa
int BSTDelete(BT_NODE*& pRoot, int x);
void SearchStandFor(BT_NODE*& p, BT_NODE*& q);
//Tiện ích
int TinhCC(BT_NODE* pRoot);
//caidat.cpp
#include"bstree.h"

void KhoiTao(BIN_TREE& t)
{
    t.pRoot = NULL;
    t.nCount = 0;
}
//----------------------------------------
BT_NODE* TaoNut(int x) 
{
    BT_NODE* p = new BT_NODE;
    if (p == NULL) return NULL;
    p->Data = x;
    p->pLeft = p->pRight = NULL;
    return p;
}
//------------------------------------------
int BSTInsert(BT_NODE*& pCurr, int newkey)
{
    if (pCurr == NULL) {
        pCurr =new BT_NODE;
        pCurr->Data = newkey;
        pCurr->pLeft = pCurr->pRight = NULL;
        return 1;
    }
    if (pCurr->Data > newkey)
        return BSTInsert(pCurr->pLeft, newkey);
    else if (pCurr->Data < newkey)
        return BSTInsert(pCurr->pRight, newkey);
    else return 0;
}
//------------------------------------------
void TaoCay(BIN_TREE& t) // Bỏ mảng a và n đi nếu muốn nhập từ phím
{
    int n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap gia tri thu " << i + 1 << ": ";
        cin >> x;
        int kq = BSTInsert(t.pRoot, x);
        if (kq == 0)
            cout << "Khoa " << x << " da co trong cay.\n";
        else
            t.nCount++;
    }
}
//-----------------------------------------------
void LNR(BT_NODE* pRoot)
{
    if (pRoot != NULL)
    {
        LNR(pRoot->pLeft);
        cout << pRoot->Data << " ";
        LNR(pRoot->pRight);
    }
}

// ================== DUYET NLR ==================
void NLR(BT_NODE* pRoot)
{
    if (pRoot != NULL)
    {
        cout << pRoot->Data << " ";
        NLR(pRoot->pLeft);
        NLR(pRoot->pRight);
    }
}

// ================== DUYET LRN ==================
void LRN(BT_NODE* pRoot)
{
    if (pRoot != NULL)
    {
        LRN(pRoot->pLeft);
        LRN(pRoot->pRight);
        cout << pRoot->Data << " ";
    }
}

// ================== TIM KIEM ==================
BT_NODE* BSTSearch(BT_NODE* pRoot, int x)
{
    if (pRoot == NULL) return NULL;

    if (pRoot->Data == x)
        return pRoot;

    if (x < pRoot->Data)
        return BSTSearch(pRoot->pLeft, x);
    else
        return BSTSearch(pRoot->pRight, x);
}

// ================== TIM NODE THE MANG ==================
void SearchStandFor(BT_NODE*& p, BT_NODE*& q)
{
    if (q->pLeft != NULL)
    {
        SearchStandFor(p, q->pLeft);
    }
    else
    {
        p->Data = q->Data;
        p = q;
        q = q->pRight;
    }
}

// ================== XOA NODE ==================
int BSTDelete(BT_NODE*& pRoot, int x)
{
    if (pRoot == NULL) return 0;

    if (x < pRoot->Data)
        return BSTDelete(pRoot->pLeft, x);
    else if (x > pRoot->Data)
        return BSTDelete(pRoot->pRight, x);
    else
    {
        BT_NODE* p = pRoot;

        // Node co 1 con hoac la la
        if (pRoot->pLeft == NULL)
            pRoot = pRoot->pRight;
        else if (pRoot->pRight == NULL)
            pRoot = pRoot->pLeft;
        else
        {
            // Node co 2 con
            SearchStandFor(p, pRoot->pRight);
        }

        delete p;
        return 1;
    }
}

// ================== TINH CHIEU CAO ==================
int TinhCC(BT_NODE* pRoot)
{
    if (pRoot == NULL) return 0;

    int left = TinhCC(pRoot->pLeft);
    int right = TinhCC(pRoot->pRight);

    return (left > right ? left : right) + 1;
}

// ================== DEM SO NUT ==================
int DemSoNut(BT_NODE* pRoot)
{
    if (pRoot == NULL) return 0;

    return 1 + DemSoNut(pRoot->pLeft) + DemSoNut(pRoot->pRight);
}

// ================== TIM MIN ==================
BT_NODE* TimMin(BT_NODE* pRoot)
{
    if (pRoot == NULL) return NULL;

    while (pRoot->pLeft != NULL)
        pRoot = pRoot->pLeft;

    return pRoot;
}

// ================== TIM MAX ==================
BT_NODE* TimMax(BT_NODE* pRoot)
{
    if (pRoot == NULL) return NULL;

    while (pRoot->pRight != NULL)
        pRoot = pRoot->pRight;

    return pRoot;
}
//ctc.cpp
#include "BSTree.h"

int Menu() {
    system("cls");
    int cv, k = 0;
    cout << "\n --- THAO TAC TREN CAY NHI PHAN TIM KIEM ---" << endl;
    cout << "\n 1. Nhap du lieu tao cay BST"; k++;
    cout << "\n 2. Duyet cay (LNR - xuat day tang dan)"; k++;
    cout << "\n 3. Tim kiem mot khoa tren cay"; k++;
    cout << "\n 4. Xoa mot nut tren cay"; k++;
    cout << "\n 5. Tinh chieu cao cua cay"; k++;

    cout << "\n 0. Thoat";
    do {
        cout << "\n Nhap thao tac: "; cin >> cv;
    } while (cv < 0 || cv > k);
    return cv;
}

int main() {
    BIN_TREE t;
    int cv, x ;
    KhoiTao(t);
    do {
        cv = Menu();
        switch (cv) {
        case 1: TaoCay(t); 
            break;
        case 2:
            cout << "\nKết quả duyệt giữa: "; LNR(t.pRoot);
            break;
        case 3:
            cout << "\nNhập giá trị cần tìm: "; cin >> x;
            if (BSTSearch(t.pRoot, x)) cout << "Tim thay!";
            else cout << "Khong ton tai!";
            break;
        case 4:
            cout << "\nNhập giá trị cần xóa: "; cin >> x;
            if (BSTDelete(t.pRoot, x)) cout << "Da xoa thành công!";
            else cout << "Khong tìm thấy nút để xóa!";
            break;
        case 5:
            cout << "\nChiều cao của cây là: " << TinhCC(t.pRoot);
            break;
        }
        cout << endl; system("pause");
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
