#include <iostream>
using namespace std;

// ================= HAM TIEN ICH =================
void HoanVi(int& a, int& b) {
    int t = a; a = b; b = t;
}

void XuatMang(int a[], int n, const char* ten = "") {
    if (ten[0] != '\0') cout << ten << ": ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
}

// ================= TIM KIEM =================
int TimTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (a[i] == x) return i;
    return -1;
}

int TimNhiPhan(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

// ================= SAP XEP =================
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) HoanVi(a[j], a[j + 1]);
}

void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i], j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void SelectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        HoanVi(a[i], a[min]);
    }
}

void QuickSort(int a[], int l, int r) {
    if (l >= r) return;
    int pivot = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            HoanVi(a[i], a[j]);
            i++; j--;
        }
    }
    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}

// ================= BAI TAP =================
int TimViTriLonNhat(int a[], int n) {
    int vt = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[vt]) vt = i;
    return vt;
}

int DemSoLanXuatHien(int a[], int n, int x) {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x) dem++;
    return dem;
}

int PhanTuXuatHienNhieuNhat(int a[], int n) {
    int maxVal = a[0], maxDem = 0;
    for (int i = 0; i < n; i++) {
        int dem = 0;
        for (int j = 0; j < n; j++)
            if (a[j] == a[i]) dem++;
        if (dem > maxDem) {
            maxDem = dem;
            maxVal = a[i];
        }
    }
    return maxVal;
}

// ================= MAIN =================
int main() {
    int n;
    cout << "Nhap so phan tu n: ";
    cin >> n;

    int a[100];
    cout << "Nhap " << n << " phan tu:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    XuatMang(a, n, "Mang ban dau");

    // Sap xep
    int b[100];
    for (int i = 0; i < n; i++) b[i] = a[i];
    QuickSort(b, 0, n - 1);
    XuatMang(b, n, "Sau khi QuickSort");

    // Tim kiem
    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;

    cout << "Tim tuyen tinh: " << TimTuyenTinh(a, n, x) << '\n';
    cout << "Tim nhi phan: " << TimNhiPhan(b, n, x) << '\n';

    // Bai tap
    cout << "Vi tri phan tu lon nhat: " << TimViTriLonNhat(a, n) << '\n';
    cout << "So lan xuat hien cua " << x << ": " << DemSoLanXuatHien(a, n, x) << '\n';
    cout << "Phan tu xuat hien nhieu nhat: " << PhanTuXuatHienNhieuNhat(a, n) << '\n';

    return 0;
}
