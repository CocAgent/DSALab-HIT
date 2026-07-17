#include <iostream>
#include <windows.h>
using namespace std;

#define DELAY 300

// ================= MÀU =================
void color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// ================= CLEAR =================
void clear() {
    system("cls");
}

// ================= IN MẢNG =================
void printArray(int a[], int n, int x = -1, int y = -1, int sorted = -1) {
    cout << "\n";

    for (int i = 0; i < n; i++) {
        if (i == x || i == y) color(12);       // đỏ
        else if (i >= sorted) color(10);       // xanh
        else color(7);

        cout << a[i] << "\t";
    }

    cout << "\n";

    for (int i = 0; i < n; i++) {
        if (i == x || i == y) color(12);
        else if (i >= sorted) color(10);
        else color(7);

        for (int j = 0; j < a[i]; j++)
            cout << "#";

        cout << "\n";
    }

    color(7);
}

// ================= HOÁN VỊ =================
void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// ================= BUBBLE =================
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {

            clear();
            cout << "BUBBLE SORT\n";
            printArray(a, n, j - 1, j, n - i);
            Sleep(DELAY);

            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);

                clear();
                printArray(a, n, j - 1, j, n - i);
                Sleep(DELAY);
            }
        }
    }
}

// ================= SELECTION =================
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            clear();
            cout << "SELECTION SORT\n";
            printArray(a, n, min, j, i);
            Sleep(DELAY);

            if (a[j] < a[min]) min = j;
        }

        swap(a[i], a[min]);
    }
}

// ================= QUICK =================
void quickSortDemo(int a[], int l, int r, int n) {
    int i = l, j = r;
    int pivot = a[(l + r) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            clear();
            cout << "QUICK SORT (pivot=" << pivot << ")\n";
            printArray(a, n, i, j);
            Sleep(DELAY);

            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if (l < j) quickSortDemo(a, l, j, n);
    if (i < r) quickSortDemo(a, i, r, n);
}

// ================= MENU =================
void menu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Quick Sort\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

// ================= MAIN =================
int main() {
    int a[] = { 5, 1, 4, 2, 8 };
    int n = 5;
    int choice;

    do {
        clear();
        menu();
        cin >> choice;

        int b[5];
        for (int i = 0; i < n; i++) b[i] = a[i];

        switch (choice) {
        case 1:
            bubbleSort(b, n);
            break;

        case 2:
            selectionSort(b, n);
            break;

        case 3:
            quickSortDemo(b, 0, n - 1, n);
            break;
        }

        if (choice != 0) {
            cout << "\nHoan tat!\nNhan phim bat ky...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}
