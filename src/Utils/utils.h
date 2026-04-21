// ============================================================
//  utils.h  -  Ham tien ich dung chung cho ca du an
//  Giao trinh: Cau truc du lieu & Giai thuat
//  Truong CĐ Cong Thuong TP.HCM
// ============================================================
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

// ---------- Hoan vi ----------
template <typename T>
void HoanVi(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// ---------- Nhap mang ----------
void NhapMang(int a[], int &n) {
    cout << "Nhap so luong phan tu (n): ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "  a[" << i << "] = ";
        cin >> a[i];
    }
}

// ---------- Xuat mang ----------
void XuatMang(const int a[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << " ]" << endl;
}

// ---------- Tao mang ngau nhien ----------
void TaoMangNgauNhien(int a[], int n, int min_val = 1, int max_val = 100) {
    srand((unsigned)time(0));
    for (int i = 0; i < n; i++)
        a[i] = min_val + rand() % (max_val - min_val + 1);
}

// ---------- In tieu de ----------
void InTieuDe(const string &tieu_de) {
    int len = (int)tieu_de.size() + 4;
    string duong(len, '=');
    cout << "\n" << duong << "\n  " << tieu_de << "\n" << duong << "\n";
}

#endif // UTILS_H
