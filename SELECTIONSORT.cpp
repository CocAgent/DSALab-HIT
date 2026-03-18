#include <iostream>
using namespace std;

// Hoán vị
void swap(int &a, int &b) {
    int t = a; a = b; b = t;
}

// ================= TÌM KIẾM =================

// Tuyến tính
int linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (a[i] == x) return i;
    return -1;
}

// Nhị phân (mảng đã tăng)
int binarySearch(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

// ================= SẮP XẾP =================

// Selection Sort
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        swap(a[i], a[min]);
    }
}

// Insertion Sort
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i], j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

// Bubble Sort
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}

// Quick Sort
void quickSort(int a[], int l, int r) {
    int i = l, j = r;
    int pivot = a[(l + r) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

// ================= MAIN =================
int main() {
    int a[] = {64, 25, 12, 22, 11};
    int n = 5;

    // Sắp xếp
    quickSort(a, 0, n - 1);

    cout << "Mang sau sap xep: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    // Tìm kiếm
    int x = 22;
    int pos = binarySearch(a, n, x);

    if (pos != -1)
        cout << "\nTim thay " << x << " tai vi tri " << pos;
    else
        cout << "\nKhong tim thay";

    return 0;
}
