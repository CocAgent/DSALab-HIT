// ============================================================
//  Chuong4_CauTrucCay.cpp
//  Noi dung: Cay nhi phan, duyet cay, BST
//  Giao trinh: Cau truc du lieu & Giai thuat - CDCTTP.HCM
// ============================================================
#include "bstree.h"
#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;
// ============================================================
//  CAU TRUC NUT CAY
// ============================================================
struct TreeNode 
{
    int data;
    TreeNode* left;
    TreeNode* right;
};
//cau truc node
typedef struct tagBT_NODE
{
    int Data;
    tagBT_NODE* pLeft;
    tagBT_NODE* pRight;
}BT_NODE;
//cau truc tree
typedef struct tagBIN_TREE
{
    int nCount;
    BT_NODE* pRoot;
}BIN_TREE;

// ============================================================
//  TAO NODE VA KHOI TAO
// ============================================================
TreeNode* TaoNode(int x) 
{
    TreeNode* p = new TreeNode;
    p->data = x;
    p->left = p->right = nullptr;
    return p;
}

// ============================================================
//  CAY NHI PHAN TIM KIEM (BST)
//  Tinh chat: left < root < right
// ============================================================

// Chen mot nut vao BST
TreeNode* Chen(TreeNode* root, int x) 
{
    if (root == nullptr) return TaoNode(x);
    if (x < root->data) root->left = Chen(root->left, x);
    else if (x > root->data) root->right = Chen(root->right, x);
    // x == root->data: khong chen trung
    return root;
}

// Tim mot nut trong BST
TreeNode* Tim(TreeNode* root, int x) 
{
    if (root == nullptr || root->data == x) return root;
    if (x < root->data) return Tim(root->left, x);
    return Tim(root->right, x);
}

// Tim nut nho nhat trong cay
TreeNode* TimNhoNhat(TreeNode* root) 
{
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) root = root->left;
    return root;
}

// Tim nut lon nhat trong cay
TreeNode* TimLonNhat(TreeNode* root) 
{
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) root = root->right;
    return root;
}

// Xoa mot nut khoi BST
TreeNode* Xoa(TreeNode* root, int x) 
{
    if (root == nullptr) return nullptr;
    if (x < root->data) 
    {
        root->left = Xoa(root->left, x);
    }
    else if (x > root->data) {
        root->right = Xoa(root->right, x);
    }
    else 
    {
        // Nut can xoa
        if (root->left == nullptr) 
        {
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == nullptr)
        {
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
void XoaCay(TreeNode* root) 
{
    if (root == nullptr) return;
    XoaCay(root->left);
    XoaCay(root->right);
    delete root;
}

// ============================================================
//  CAC PHUONG PHAP DUYET CAY
// ============================================================

// 1. Duyet goc truoc: NLR (Pre-order)
void DuyetTruoc(TreeNode* root)
{
    if (root == nullptr) return;
    cout << root->data << " ";
    DuyetTruoc(root->left);
    DuyetTruoc(root->right);
}

// 2. Duyet goc giua: LNR (In-order) - cho BST ra thu tu tang
void DuyetGiua(TreeNode* root) 
{
    if (root == nullptr) return;
    DuyetGiua(root->left);
    cout << root->data << " ";
    DuyetGiua(root->right);
}

// 3. Duyet goc sau: LRN (Post-order)
void DuyetSau(TreeNode* root)
{
    if (root == nullptr) return;
    DuyetSau(root->left);
    DuyetSau(root->right);
    cout << root->data << " ";
}

// 4. Duyet theo muc (BFS - Level-order)
void DuyetMuc(TreeNode* root)
{
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) 
    {
        TreeNode* cur = q.front(); q.pop();
        cout << cur->data << " ";
        if (cur->left)  q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

// ============================================================
//  CAC THAO TAC KHAC TREN CAY
// ============================================================
//ham tao cay
void TaoCay(BIN_TREE& t, const int a[], int n)
{
    int kq;
    for (int i = 0;i < n;i++)
    {
        kq = BSTInsert(t.pRoot, a[i]);
        if (kq == 0)
            cout << "\nKhoa " << a[i] << " da co trong cay.";
        else
            t.nCount++;
    }
}
//ham xuat cay
void LNR(const BT_NODE* pRoot)
{
    if (pRoot == NULL) return;
    LNR(pRoot->pLeft);
    cout << pRoot->Data << " ";
    LNR(pRoot->pRight);
}
int BSTInsert(BT_NODE*& pCurr, int newKey)
{
    if (pCurr == NULL)
    {
        pCurr = new BT_NODE;
        pCurr->Data = newKey;
        pCurr->pLeft = pCurr->pRight = NULL;
        return 1;
    }
    if (pCurr->Data > newKey)
        return BSTInsert(pCurr->pLeft, newKey);
    else 
        if (pCurr->Data < newKey);
    return BSTInsert(pCurr->pRight, newKey);
         return 0;
}
BT_NODE* BSTSearch(BT_NODE* pCurr, int Key)
{
    if (pCurr == NULL) return NULL;
    if (pCurr->Data == Key) return pCurr;
    else
        if (pCurr->Data > Key)
            return BSTSearch(pCurr->pLeft, Key);
        else
            return BSTSearch(pCurr->pRight, Key);
}
//tim phan tu thay the
BT_NODE* _SearchStandFor(BT_NODE*& p, BT_NODE* pCurr)
{
    if (p->pRight != NULL)
        return _SearchStandFor(p->pRight, pCurr);
    pCurr->Data = p->Data;
    BT_NODE* pTemp = p;
    p = p->pLeft;
    return pTemp;
}
void _Delete(BT_NODE*& pCurr)
{
    BT_NODE* pTemp = pCurr;
    if (pCurr->pRight == NULL)
        pCurr = pCurr->pLeft;
    else
        if (pCurr->pLeft == NULL)
            pCurr = pCurr->pRight;
        else
            pTemp = _SearchStandFor(pCurr->pLeft, pCurr);
    delete pTemp;
}
int BSTDelete(BT_NODE*& pCurr, int Key)
{
    if (pCurr == NULL) return 0;
    if (pCurr->Data > Key)
        return BSTDelete(pCurr->pLeft, Key);
    else
        if (pCurr->Data < Key)
            return BSTDelete(pCurr->pLeft, Key);
    _Delete(pCurr);
    return 1;
}

// Tinh chieu cao cay
int ChieuCao(TreeNode* root) 
{
    if (root == nullptr) return 0;
    int left_h = ChieuCao(root->left);
    int right_h = ChieuCao(root->right);
    return 1 + (left_h > right_h ? left_h : right_h);
}

// Dem so nut
int DemNut(TreeNode* root) 
{
    if (root == nullptr) return 0;
    return 1 + DemNut(root->left) + DemNut(root->right);
}

// Dem so nut la (leaf node)
int DemNutLa(TreeNode* root)
{
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return DemNutLa(root->left) + DemNutLa(root->right);
}

// Tinh tong tat ca cac nut
long long TinhTong(TreeNode* root)
{
    if (root == nullptr) return 0;
    return root->data + TinhTong(root->left) + TinhTong(root->right);
}

// Kiem tra cay la BST
bool LaBST(TreeNode* root, int minVal = INT_MIN, int maxVal = INT_MAX)
{
    if (root == nullptr) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return LaBST(root->left, minVal, root->data) &&
        LaBST(root->right, root->data, maxVal);
}

// In cay theo dang cay (de hieu hon)
void InCay(TreeNode* root, string prefix = "", bool isLeft = true)
{
    if (root == nullptr) return;
    InCay(root->right, prefix + (isLeft ? "|   " : "    "), false);
    cout << prefix << (isLeft ? "\\-- " : "/-- ") << root->data << "\n";
    InCay(root->left, prefix + (isLeft ? "    " : "|   "), true);
}

// Tim tien bo (successor) cua mot nut
TreeNode* TienBo(TreeNode* root, int x) 
{
    TreeNode* cur = Tim(root, x);
    if (cur == nullptr) return nullptr;
    if (cur->right) return TimNhoNhat(cur->right);
    TreeNode* successor = nullptr;
    TreeNode* ancestor = root;
    while (ancestor != cur)
    {
        if (x < ancestor->data) { successor = ancestor; ancestor = ancestor->left; }
        else ancestor = ancestor->right;
    }
    return successor;
}

// ============================================================
//  DEMO CAY NHI PHAN
// ============================================================
void DemoCAY() {
    cout << "\n=== DEMO CAY NHI PHAN TIM KIEM (BST) ===\n";
    TreeNode* root = nullptr;

    // Tao BST tu day so trong giao trinh
    int arr[] = { 5, 3, 7, 1, 4, 6, 8, 2 };
    int n = 8;
    cout << "  Chen cac nut: ";
    for (int x : arr) { cout << x << " "; root = Chen(root, x); }
    cout << "\n";

    // In cac kieu duyet
    cout << "\n  Duyet Pre-order  (NLR): "; DuyetTruoc(root); cout << "\n";
    cout << "  Duyet In-order   (LNR): "; DuyetGiua(root);  cout << "\n";
    cout << "  Duyet Post-order (LRN): "; DuyetSau(root);   cout << "\n";
    cout << "  Duyet Level-order(BFS): "; DuyetMuc(root);   cout << "\n";

    // Thong tin cay
    cout << "\n  Chieu cao cay   : " << ChieuCao(root) << "\n";
    cout << "  So nut          : " << DemNut(root) << "\n";
    cout << "  So nut la       : " << DemNutLa(root) << "\n";
    cout << "  Tong cac nut    : " << TinhTong(root) << "\n";
    cout << "  Nut nho nhat    : " << TimNhoNhat(root)->data << "\n";
    cout << "  Nut lon nhat    : " << TimLonNhat(root)->data << "\n";

    // Tim nut
    int x = 4;
    TreeNode* found = Tim(root, x);
    cout << "\n  Tim " << x << ": " << (found ? "Tim thay" : "Khong tim thay") << "\n";
    x = 10;
    found = Tim(root, x);
    cout << "  Tim " << x << ": " << (found ? "Tim thay" : "Khong tim thay") << "\n";

    // Xoa nut
    cout << "\n  Xoa nut 3:\n";
    root = Xoa(root, 3);
    cout << "  Sau khi xoa 3 - In-order: "; DuyetGiua(root); cout << "\n";
    cout << "  Sau khi xoa 3 - Level-order: "; DuyetMuc(root); cout << "\n";

    // In cay truc quan
    cout << "\n  Cau truc cay sau khi xoa 3:\n";
    InCay(root);

    XoaCay(root);
}

// ============================================================
//  BAI TAP CHUONG 4 (theo sach)
// ============================================================

// Dem so nut co gia tri chan
int DemNutChan(TreeNode* root) 
{
    if (root == nullptr) return 0;
    return (root->data % 2 == 0 ? 1 : 0)
        + DemNutChan(root->left)
        + DemNutChan(root->right);
}

// Dem so nut co gia tri le
int DemNutLe(TreeNode* root) 
{
    if (root == nullptr) return 0;
    return (root->data % 2 != 0 ? 1 : 0)
        + DemNutLe(root->left)
        + DemNutLe(root->right);
}

// Tinh tong nut la
long long TongNutLa(TreeNode* root)
{
    if (root == nullptr) return 0;
    if (!root->left && !root->right) return root->data;
    return TongNutLa(root->left) + TongNutLa(root->right);
}

// Tim phan tu lon thu k (In-order nguoc)
int k_counter = 0;
int TimPhanTuLonThuK(TreeNode* root, int k)
{
    if (root == nullptr) return -1;
    // Duyet RNL (ngược In-order)
    int val = TimPhanTuLonThuK(root->right, k);
    if (val != -1) return val;
    k_counter++;
    if (k_counter == k) return root->data;
    return TimPhanTuLonThuK(root->left, k);
}

// Kiem tra cay doi xung (symmetric)
bool LaDoiXung(TreeNode* L, TreeNode* R) 
{
    if (!L && !R) return true;
    if (!L || !R) return false;
    return (L->data == R->data)
        && LaDoiXung(L->left, R->right)
        && LaDoiXung(L->right, R->left);
}
bool LaDoiXung(TreeNode* root) 
{
    if (!root) return true;
    return LaDoiXung(root->left, root->right);
}

void DemoBaiTap() {
    cout << "\n=== BAI TAP CHUONG 4 ===\n";
    TreeNode* root = nullptr;
    int arr[] = { 10, 5, 15, 3, 7, 12, 20, 1, 4, 6, 9 };
    for (int x : arr) root = Chen(root, x);

    cout << "  BST voi cac nut: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    cout << "  In-order (tang dan): "; DuyetGiua(root); cout << "\n";
    cout << "  Chieu cao cay: " << ChieuCao(root) << "\n";
    cout << "  So nut la: " << DemNutLa(root) << "\n";
    cout << "  So nut chan: " << DemNutChan(root) << "\n";
    cout << "  So nut le: " << DemNutLe(root) << "\n";
    cout << "  Tong nut la: " << TongNutLa(root) << "\n";

    k_counter = 0;
    int k = 3;
    cout << "  Phan tu lon thu " << k << ": " << TimPhanTuLonThuK(root, k) << "\n";
    cout << "  La cay doi xung? " << (LaDoiXung(root) ? "Co" : "Khong") << "\n";

    // Tao cay doi xung de test
    TreeNode* sym = nullptr;
    sym = Chen(sym, 4);
    sym = Chen(sym, 2);
    // manual symmetric tree
    sym->left = TaoNode(2); sym->right = TaoNode(2);
    sym->left->left = TaoNode(3); sym->left->right = TaoNode(4);
    sym->right->left = TaoNode(4); sym->right->right = TaoNode(3);
    cout << "  Cay doi xung [4,2,2,3,4,4,3] -> " << (LaDoiXung(sym) ? "Co" : "Khong") << "\n";

    cout << "\n  Cau truc BST chinh:\n";
    InCay(root);

    XoaCay(root);
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "============================================================\n";
    cout << "  CHUONG 4: CAU TRUC DU LIEU CAY\n";
    cout << "============================================================\n";

    DemoCAY();
    DemoBaiTap();

    cout << "\n============================================================\n";
    return 0;
}
