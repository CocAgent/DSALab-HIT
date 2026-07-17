#include <iostream>
using namespace std;

// ================= SELECTION SORT =================
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

// ================= INSERTION SORT =================
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// ================= BUBBLE SORT =================
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // tối ưu
    }
}

// ================= QUICK SORT =================
int partition(int a[], int low, int high) {
    int pivot = a[high]; // chọn pivot cuối
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// ================= HEAP SORT =================
void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // extract từng phần tử
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// ================= HÀM IN =================
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// ================= MAIN =================
int main() {
    int original[] = { 3, -12, 14, 9, 11, -50, -100 };
    int n = sizeof(original) / sizeof(original[0]);

    // Copy mảng cho từng thuật toán
    int a1[100], a2[100], a3[100], a4[100], a5[100];
    for (int i = 0; i < n; i++) {
        a1[i] = a2[i] = a3[i] = a4[i] = a5[i] = original[i];
    }

    cout << "Mang ban dau:\n";
    printArray(original, n);

    // Selection Sort
    selectionSort(a1, n);
    cout << "Selection Sort:\n";
    printArray(a1, n);

    // Insertion Sort
    insertionSort(a2, n);
    cout << "Insertion Sort:\n";
    printArray(a2, n);

    // Bubble Sort
    bubbleSort(a3, n);
    cout << "Bubble Sort:\n";
    printArray(a3, n);

    // Quick Sort
    quickSort(a4, 0, n - 1);
    cout << "Quick Sort:\n";
    printArray(a4, n);

    // Heap Sort
    heapSort(a5, n);
    cout << "Heap Sort:\n";
    printArray(a5, n);

    return 0;
}