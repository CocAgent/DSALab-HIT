// ============================================================
//  Chuong2_TimKiem_SapXep.cpp
//  Noi dung: 2 giai thuat tim kiem + 5 giai thuat sap xep
//  Giao trinh: Cau truc du lieu & Giai thuat - CDCTTP.HCM
// ============================================================
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

// ============================================================
//  HAM TIEN ICH
// ============================================================
void HoanVi(int &a, int &b) { int t = a; a = b; b = t; }

void XuatMang(const int a[], int n, const string &ten = "") {
    if (!ten.empty()) cout << "  " << ten << ": ";
    cout << "[ ";
    for (int i = 0; i < n; i++) cout << setw(4) << a[i];
    cout << " ]\n";
}

// ============================================================
//  PHAN 1: GIAI THUAT TIM KIEM
// ============================================================

// 1.1 Tim kiem tuyen tinh - O(N)
int TimTuyenTinh(const int a[], int n, int x) {
    int i = 0;
    while (a[i] != x && i < n) i++;
    if (i < n) return i;
    return -1;
}

// 1.2 Tim kiem nhi phan - O(log2 N) - yeu cau mang sap xep tang
int TimNhiPhan(const int a[], int n, int x) {
    int l = 0, r = n - 1, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (a[m] == x)  return m;
        else if (a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

// ============================================================
//  PHAN 2: GIAI THUAT SAP XEP
// ============================================================

// 2.1 Selection Sort (Chon truc tiep) - O(N^2)
void SelectionSort(int a[], int n) {
    int vt;
    for (int i = 0; i < n - 1; i++) {
        vt = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[vt]) vt = j;
        HoanVi(a[i], a[vt]);
    }
}

// 2.2 Insertion Sort (Chen truc tiep) - O(N^2)
void InsertionSort(int a[], int n) {
    int pos, x;
    for (int i = 1; i < n; i++) {
        pos = i;
        x = a[i];
        while (pos > 0 && a[pos - 1] > x) {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = x;
    }
}

// 2.3 Bubble Sort (Noi bot) - O(N^2)
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
                HoanVi(a[j], a[j - 1]);
}

// 2.4 Quick Sort (Sap xep nhanh) - O(N log N) trung binh
void QuickSort(int a[], int l, int r) {
    int i = l, j = r, x;
    x = a[(l + r) / 2];
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            HoanVi(a[i], a[j]);
            i++; j--;
        }
    } while (i <= j);
    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}

// 2.5 Heap Sort (Vun dong) - O(N log N)
void Shift(int a[], int l, int r) {
    int x, i, j;
    i = l; j = 2 * i + 1;
    x = a[i];
    while (j <= r) {
        if (j < r && a[j] < a[j + 1]) j++;
        if (x >= a[j]) break;
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = x;
}

void HeapSort(int a[], int n) {
    // Giai doan 1: Xay dung Heap
    for (int k = n / 2 - 1; k >= 0; k--)
        Shift(a, k, n - 1);
    // Giai doan 2: Sap xep
    for (int r = n - 1; r > 0; r--) {
        HoanVi(a[0], a[r]);
        Shift(a, 0, r - 1);
    }
}

// ============================================================
//  SAO CHEP MANG (cho phep test nhieu lan)
// ============================================================
void SaoChepMang(const int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

// ============================================================
//  DEMO TIM KIEM
// ============================================================
void DemoTimKiem() {
    cout << "\n=== DEMO TIM KIEM ===\n";
    int a[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int n = 9;
    int aUnsorted[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int nu = 8;

    XuatMang(a, n, "Mang da sap xep");

    int x;
    cout << "  Nhap gia tri can tim: "; cin >> x;

    // Tim tren mang chua sap xep
    int vt = TimTuyenTinh(aUnsorted, nu, x);
    cout << "  [TuyenTinh] Tim " << x << " trong mang chua sap xep => ";
    if (vt == -1) cout << "Khong tim thay\n";
    else cout << "Tim thay tai vi tri " << vt << "\n";

    // Tim tren mang sap xep
    vt = TimNhiPhan(a, n, x);
    cout << "  [NhiPhan]   Tim " << x << " trong mang da sap xep  => ";
    if (vt == -1) cout << "Khong tim thay\n";
    else cout << "Tim thay tai vi tri " << vt << "\n";
}

// ============================================================
//  DEMO SAP XEP
// ============================================================
void DemoSapXep() {
    cout << "\n=== DEMO SAP XEP ===\n";
    const int n = 8;
    int goc[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int a[n];

    cout << "  Mang goc: ";
    XuatMang(goc, n);

    // Selection Sort
    SaoChepMang(goc, a, n);
    SelectionSort(a, n);
    cout << "  Selection : ";
    XuatMang(a, n);

    // Insertion Sort
    SaoChepMang(goc, a, n);
    InsertionSort(a, n);
    cout << "  Insertion : ";
    XuatMang(a, n);

    // Bubble Sort
    SaoChepMang(goc, a, n);
    BubbleSort(a, n);
    cout << "  Bubble    : ";
    XuatMang(a, n);

    // Quick Sort
    SaoChepMang(goc, a, n);
    QuickSort(a, 0, n - 1);
    cout << "  Quick     : ";
    XuatMang(a, n);

    // Heap Sort
    SaoChepMang(goc, a, n);
    HeapSort(a, n);
    cout << "  Heap      : ";
    XuatMang(a, n);
}

// ============================================================
//  BAI TAP CHUONG 2 (theo sach)
// ============================================================

// BT1: Tim kiem tren mang nguyen - tra ve vi tri dau tien
int BT1_TimXDauTien(const int a[], int n, int x) {
    return TimTuyenTinh(a, n, x);
}

// BT2: Tim vi tri phan tu lon nhat
int BT2_TimMax(const int a[], int n) {
    int vtmax = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[vtmax]) vtmax = i;
    return vtmax;
}

// BT3: Dem so lan xuat hien cua x trong mang
int BT3_DemXuatHien(const int a[], int n, int x) {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x) dem++;
    return dem;
}

// BT4: Sap xep tang, tim nhi phan
void BT4_SapXepTimNhiPhan(int a[], int n, int x) {
    QuickSort(a, 0, n - 1);
    cout << "  Mang sau sap xep: ";
    XuatMang(a, n);
    int vt = TimNhiPhan(a, n, x);
    if (vt == -1) cout << "  " << x << " khong co trong mang\n";
    else cout << "  " << x << " o vi tri " << vt << " (sau sap xep)\n";
}

// BT5: Sap xep giam dan bang Bubble Sort
void BT5_BubbleSortGiam(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j] > a[j - 1])
                HoanVi(a[j], a[j - 1]);
}

// BT6: Xuat phan tu xuat hien nhieu nhat
void BT6_PhanTuXuatHienNhieuNhat(int a[], int n) {
    int maxDem = 0, maxVal = a[0];
    for (int i = 0; i < n; i++) {
        int dem = 0;
        for (int j = 0; j < n; j++)
            if (a[j] == a[i]) dem++;
        if (dem > maxDem) { maxDem = dem; maxVal = a[i]; }
    }
    cout << "  Phan tu xuat hien nhieu nhat: " << maxVal
         << " (" << maxDem << " lan)\n";
}

void DemoBaiTap() {
    cout << "\n=== BAI TAP CHUONG 2 ===\n";
    int a[] = {5, 3, 8, 3, 1, 9, 3, 7, 2, 5};
    int n = 10;
    int b[10]; SaoChepMang(a, b, n);

    cout << "  Mang nhap: ";
    XuatMang(a, n);

    // BT2
    cout << "  [BT2] Vi tri phan tu lon nhat: " << BT2_TimMax(a, n) << "\n";

    // BT3
    cout << "  [BT3] So lan xuat hien cua 3: " << BT3_DemXuatHien(a, n, 3) << "\n";

    // BT4
    cout << "  [BT4] Sap xep tang, tim x=8:\n  ";
    BT4_SapXepTimNhiPhan(b, n, 8);

    // BT5
    SaoChepMang(a, b, n);
    BT5_BubbleSortGiam(b, n);
    cout << "  [BT5] Sap xep giam dan: ";
    XuatMang(b, n);

    // BT6
    cout << "  [BT6] ";
    BT6_PhanTuXuatHienNhieuNhat(a, n);
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "============================================================\n";
    cout << "  CHUONG 2: CAC GIAI THUAT TIM KIEM VA SAP XEP\n";
    cout << "============================================================\n";

    DemoTimKiem();
    DemoSapXep();
    DemoBaiTap();

    cout << "\n============================================================\n";
    return 0;
}
