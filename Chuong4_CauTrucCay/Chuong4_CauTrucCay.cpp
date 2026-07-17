// ============================================================
//  Chuong4_CauTrucCay.cpp
//  Noi dung: Cay nhi phan, duyet cay, BST
//  Giao trinh: Cau truc du lieu & Giai thuat - CDCTTP.HCM
// ============================================================
#pragma once
#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;
// ============================================================
//  CAU TRUC NUT CAY
// ============================================================
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};
struct BIN_TREE
{
    int nCount;
    TreeNode* proot;
};
TreeNode* TaoNode(int x);
void taocay(BIN_TREE& t, const int a[], int n);
int BSTInsert(TreeNode*& pCurr, int newkey);
#include "baitap12.h"



// ============================================================
//  TAO NODE VA KHOI TAO
// ============================================================
TreeNode* TaoNode(int x) {
    TreeNode* p = new TreeNode;
    p->data = x;
    return p;
}
void khoitao(BIN_TREE& t)
{
    = NULL;
}
int BSTInsert(TreeNode*& pCurr, int newkey)
{
    if (pCurr == NULL)
    {
        pCurr = new TreeNode;
        pCurr->data = newkey;
        pCurr->left = pCurr->right = NULL;
        return 1;
    }
    if (pCurr->data > newkey)
        return BSTInsert(pCurr->left, newkey);
    else
        if (pCurr->data < newkey)
            return BSTInsert(pCurr->right, newkey);
        else
            return 0;

}
void taocay(BIN_TREE& t, const int a[], int n)
{
    int kq;
    for (int i = 0;i < n;i++)
    {
        kq = BSTInsert(t.proot, a[i]);
            if (kq == 0)
                cout << "\nKhoa" << a[i] << "da co trong cay.";
            else
                t.nCount++;
    }
}





// ============================================================
//  CAY NHI PHAN TIM KIEM (BST)
//  Tinh chat: left < root < right
// ============================================================

// Chen mot nut vao BST
TreeNode* Chen(TreeNode* root, int x) {
    if (root == nullptr) return TaoNode(x);
    if (x < root->data) root->left = Chen(root->left, x);
    else if (x > root->data) root->right = Chen(root->right, x);
    // x == root->data: khong chen trung
    return root;
}

// Tim mot nut trong BST
TreeNode* Tim(TreeNode* root, int x) {
    if (root == nullptr || root->data == x) return root;
    if (x < root->data) return Tim(root->left, x);
    return Tim(root->right, x);
}

// Tim nut nho nhat trong cay
TreeNode* TimNhoNhat(TreeNode* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) root = root->left;
    return root;
}

// Tim nut lon nhat trong cay
TreeNode* TimLonNhat(TreeNode* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) root = root->right;
    return root;
}

// Xoa mot nut khoi BST
TreeNode* Xoa(TreeNode* root, int x) {
    if (root == nullptr) return nullptr;
    if (x < root->data) {
        root->left = Xoa(root->left, x);
    }
    else if (x > root->data) {
        root->right = Xoa(root->right, x);
    }
    else {
        // Nut can xoa
        if (root->left == nullptr) {
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == nullptr) {
            TreeNode* tmp = root->left;
            delete root;
            return tmp;
        }
        else {
            // Thay the bang phan tu trai nhat cua cay con phai
            TreeNode* successor = TimNhoNhat(root->right);
            root->data = successor->data;
            root->right = Xoa(root->right, successor->data);
        }
    }
    return root;
}

// Giai phong bo nho
void XoaCay(TreeNode* root) {
    if (root == nullptr) return;
    XoaCay(root->left);
    XoaCay(root->right);
    delete root;
}

// ============================================================
//  CAC PHUONG PHAP DUYET CAY
// ============================================================

// 1. Duyet goc truoc: NLR (Pre-order)
void DuyetTruoc(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    DuyetTruoc(root->left);
    DuyetTruoc(root->right);
}

// 2. Duyet goc giua: LNR (In-order) - cho BST ra thu tu tang
void DuyetGiua(TreeNode* root) {
    if (root == nullptr) return;
    DuyetGiua(root->left);
    cout << root->data << " ";
    DuyetGiua(root->right);
}

// 3. Duyet goc sau: LRN (Post-order)
void DuyetSau(TreeNode* root) {
    if (root == nullptr) return;
    DuyetSau(root->left);
    DuyetSau(root->right);
    cout << root->data << " ";
}

// 4. Duyet theo muc (BFS - Level-order)
void DuyetMuc(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        cout << cur->data << " ";
        if (cur->left)  q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

// ============================================================
//  CAC THAO TAC KHAC TREN CAY
// ============================================================

// Tinh chieu cao cay
int ChieuCao(TreeNode* root) {
    if (root == nullptr) return 0;
    int left_h = ChieuCao(root->left);
    int right_h = ChieuCao(root->right);
    return 1 + (left_h > right_h ? left_h : right_h);
}

// Dem so nut
int DemNut(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + DemNut(root->left) + DemNut(root->right);
}

// Dem so nut la (leaf node)
int DemNutLa(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return DemNutLa(root->left) + DemNutLa(root->right);
}

// Tinh tong tat ca cac nut
long long TinhTong(TreeNode* root) {
    if (root == nullptr) return 0;
    return root->data + TinhTong(root->left) + TinhTong(root->right);
}

// Kiem tra cay la BST
bool LaBST(TreeNode* root, int min = INT_MIN, int max = INT_MAX) {
    if (root == nullptr) return true;
    if (root->data <= min || root->data >= max) return false;
    return LaBST(root->left, min, root->data) &&
        LaBST(root->right, root->data, max);
}

// In cay theo dang cay (de hieu hon)
void InCay(TreeNode* root, string prefix = "", bool isLeft = true) {
    if (root == nullptr) return;
    InCay(root->right, prefix + (isLeft ? "|   " : "    "), false);
    cout << prefix << (isLeft ? "\\-- " : "/-- ") << root->data << "\n";
    InCay(root->left, prefix + (isLeft ? "    " : "|   "), true);
}

// Tim tien bo (successor) cua mot nut
TreeNode* TienBo(TreeNode* root, int x) {
    TreeNode* cur = Tim(root, x);
    if (cur == nullptr) return nullptr;
    if (cur->right) return TimNhoNhat(cur->right);
    TreeNode* successor = nullptr;
    TreeNode* ancestor = root;
    while (ancestor != cur) {
        if (x < ancestor->data) { successor = ancestor; ancestor = ancestor->left; }
        else ancestor = ancestor->right;
    }
    return successor;
}
#include "baitap12.h"

int Menu() {
    system("cls");
    int cv, k = 0;
    cout << "\n --- THAO TAC TREN CAY NHI PHAN TIM KIEM ---" << endl;
    cout << "\n 1. Nhap du lieu tao cay BST"; k++;
    cout << "\n 2. Duyệt cây (LNR - Xuất dãy tăng dần)"; k++;
    cout << "\n 3. Tìm kiếm một khóa trên cây"; k++;
    cout << "\n 4. Xóa một nút trên cây"; k++;
    cout << "\n 5. Tính chiều cao của cây"; k++;
    cout << "\n 0. Thoat";
    do {
        cout << "\n Nhap thao tac: "; cin >> cv;
    } while (cv < 0 || cv > k);
    return cv;
}

int main() {
    BIN_TREE t;
    int cv, x;
    KhoiTao(t);
    do {
        cv = Menu();
        switch (cv) {
        case 1: taocay(t); break;
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
