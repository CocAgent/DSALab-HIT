#include <iostream>
using namespace std;

// ================= Selection Sort =================
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
}

// ================= Insertion Sort =================
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

// ================= Bubble Sort =================
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// ================= Quick Sort =================
int partition(int a[], int low, int high) {
    int pivot = a[high];
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

// ================= Heap Sort =================
void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// ================= In mảng =================
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// ================= MAIN =================
int main() {
    int arr[] = { 3, -12, 14, 9, 11, -50, -100 };
    int n = 7;

    int a1[7], a2[7], a3[7], a4[7], a5[7];

    // Copy mảng
    for (int i = 0; i < n; i++) {
        a1[i] = a2[i] = a3[i] = a4[i] = a5[i] = arr[i];
    }

    cout << "Mang ban dau: ";
    printArray(arr, n);

    // Selection
    selectionSort(a1, n);
    cout << "Selection Sort: ";
    printArray(a1, n);

    // Insertion
    insertionSort(a2, n);
    cout << "Insertion Sort: ";
    printArray(a2, n);

    // Bubble
    bubbleSort(a3, n);
    cout << "Bubble Sort: ";
    printArray(a3, n);
    // Quick
    quickSort(a4, 0, n - 1);
    cout << "Quick Sort: ";
    printArray(a4, n);

    // Heap
    heapSort(a5, n);
    cout << "Heap Sort: ";
    printArray(a5, n);

    return 0;
}
