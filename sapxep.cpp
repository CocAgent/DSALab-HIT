#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
void HoanVi(int& a, int& b) { int t = a; a = b; b = t; }

void XuatMang(const int a[], int n, const string& ten = "") {
    if (!ten.empty()) cout << "  " << ten << ": ";
    cout << "[ ";
    for (int i = 0; i < n; i++) cout << setw(4) << a[i];
    cout << " ]\n";
// 1. Selection Sort

    void SelectionSort(int a[], int n) {
        int vt;
        for (int i = 0; i < n - 1; i++) {
            vt = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[vt]) vt = j;
            HoanVi(a[i], a[vt]);
        }
    }

// 2. Quick Sort (Lomuto Partition)
    void QuickSort(int a[], int l, int r) {
        int i = l, j = r, x;
        x = a[l + rand() % (r - l + 1)];
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


    oid Shift(int a[], int l, int r) {
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
    //3. heapsort
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
    // 4. Bubble Sort (Noi bot) - O(N^2)
    void BubbleSort(int a[], int n) {
        for (int i = 0; i < n - 1; i++)
            for (int j = n - 1; j > i; j--)
                if (a[j] < a[j - 1])
                    HoanVi(a[j], a[j - 1]);
    }
    //5. insertionSort
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
