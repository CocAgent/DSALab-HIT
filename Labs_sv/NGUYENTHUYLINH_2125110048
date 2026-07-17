//CHUONG 4: CAU TRUC CAY
//HAM KHAI BAO
#pragma once
#include <iostream>


using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void KhoiTao (Node* pRoot, int& nCount);
Node* TaoNut(int x);
void ThemNut(Node*& pRoot, int x, int& nCount);
void NLR(Node* pRoot);
void LNR(Node* pRoot);
void LRN(Node* pRoot);
Node* BSTSearch(Node* root, int key);
Node* BSTDelete(Node* root, int key);

//HAM CAI DAT
#include "bstree.h"

void KhoiTao(Node* pRoot, int& nCount)
{
    pRoot = NULL;
    nCount = 0;
}
Node* TaoNut(int x)
{
    Node* p = new Node;
    if (p == NULL) return NULL; // kiem tra cap phat that bai

    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}
void ThemNut(Node*& pRoot, int x, int& nCount)
{
    // Neu cay rong -> tao nut moi
    if (pRoot == NULL) {
        pRoot = TaoNut(x);
        if (pRoot != NULL) nCount++;
        return;
    }
    // Neu x nho hon -> chen ben trai
    if (x < pRoot->data) {
        ThemNut(pRoot->left, x, nCount);
    }
    // Neu x lon hon -> chen ben phai
    else if (x > pRoot->data) {
        ThemNut(pRoot->right, x, nCount);
    }
    // Neu trung -> ko lam gi
}
//------------------------------------------
//Duyet cay
void NLR(Node* pRoot) 
{
    if (pRoot == NULL)
        return;
    cout << pRoot->data << " ";
    NLR(pRoot->left);
    NLR(pRoot->right);
}

void LNR(Node* pRoot)
{
    if (pRoot == NULL)
        return;
    LNR(pRoot->left);
    cout << pRoot->data << " ";
    LNR(pRoot->right);
}

void LRN(Node* pRoot)
{
    if (pRoot == NULL) 
        return;
    LRN(pRoot->left);
    LRN(pRoot->right);
    cout << pRoot->data << " ";
}
//-------------------------------------------------------
Node* BSTSearch(Node* root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return BSTSearch(root->left, key);
    else
        return BSTSearch(root->right, key);
}
Node* _SearchStandFor(Node* node)
{
    Node* p = node->right;
    while (p->left != NULL)
        p = p->left;
    return p;
}
//-------------------------------------------------------
Node* BSTDelete(Node* root, int key) 
{
    if (root == NULL) return NULL;

    if (key < root->key)
        root->left = BSTDelete(root->left, key);
    else if (key > root->key)
        root->right = BSTDelete(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
   Node* standFor = _SearchStandFor(root);
        root->key = standFor->key;
        root->right = BSTDelete(root->right, standFor->key);
    }

    return root;
}

//HAM MAIN
//---------------------------------------------------------------------
#include"bstree.h"

int Menu() 
{
    system("cls");
    int cv, k = 0;
    cout << "\n --- THAO TAC TREN CAY NHI PHAN TIM KIEM ---" << endl;
    cout << "\n 1. Tao cay "; k++;
    cout << "\n 2. NLR "; k++;
    cout << "\n 3. LNR "; k++;
    cout << "\n 4. LRN"; k++;
    cout << "\n 5. Tim nut"; k++;
    cout << "\n 6. Xoa nut"; k++;


    cout << "\n 0. Thoat";
    do 
    {
        cout << "\n Nhap thao tac: "; cin >> cv;
    } while (cv < 0 || cv > k);
    return cv;
}

int main()
{
    Node* pRoot=NULL;
    int cv, x, n;
    int nCount = 0;
    do
    {
        cv = Menu();
        switch (cv)
        {
        case 1:
            KhoiTao(pRoot, nCount);
            cout << "Nhap so luong node: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Nhap gia tri thu " << i + 1 << ": ";
                cin >> x;
                ThemNut(pRoot, x, nCount);
            }
            break;
        case 2:
            cout << "\nKet qua duyet NLR: ";
            NLR(pRoot);
            break;
        case 3:
            cout << "\nKet qua duyet LNR: ";
            LNR(pRoot);
            break;
        case 4:
            cout << "\nKet qua duyet LRN: ";
            LRN(pRoot);
            break;
        case 5:
            cout << "\nNhap gia tri can tim: "; cin >> x;
            if (BSTSearch(t.pRoot, x)) cout << "Tim thay!";
            else cout << "Khong ton tai!";
            break;
        case 6:
            cout << "\nNhap gia tri can xoa: "; cin >> x;
            if (BSTDelete(t.pRoot, x)) cout << "Da xoa thanh cong!";
            else cout << "Khong tim thay nut de xoa!";
            break;
        case 7:
            break;
        }
        cout << endl; system("pause");
    } while (cv != 0);
    return 0;
}
