#include <iostream>
using namespace std;

// ================= NHAP MANG =================
void inputArray(int a[], int& n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

// ================= XUAT MANG =================
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// ================= SELECTION SORT =================
void selectionSortStep(int a[], int n) {
    cout << "\n=== Selection Sort ===\n";
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a[i], a[minIndex]);

        cout << "Buoc " << i + 1 << ": ";
        printArray(a, n);
    }
}

// ================= INSERTION SORT =================
void insertionSortStep(int a[], int n) {
    cout << "\n=== Insertion Sort ===\n";
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        cout << "Buoc " << i << ": ";
        printArray(a, n);
    }
}

// ================= BUBBLE SORT =================
void bubbleSortStep(int a[], int n) {
    cout << "\n=== Bubble Sort ===\n";
    int step = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);

                cout << "Buoc " << step++ << ": ";
                printArray(a, n);
            }
        }
    }
}

// ================= QUICK SORT =================
int partitionStep(int a[], int low, int high, int n) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);

            cout << "Swap: ";
            printArray(a, n);
        }
    }

    swap(a[i + 1], a[high]);
    cout << "Pivot swap: ";
    printArray(a, n);

    return i + 1;
}

void quickSortStep(int a[], int low, int high, int n) {
    if (low < high) {
        int pi = partitionStep(a, low, high, n);
        quickSortStep(a, low, pi - 1, n);
        quickSortStep(a, pi + 1, high, n);
    }
}

// ================= HEAP SORT =================
void heapifyStep(int a[], int n, int i, int total) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);

        cout << "Heapify: ";
        printArray(a, total);

        heapifyStep(a, n, largest, total);
    }
}

void heapSortStep(int a[], int n) {
    cout << "\n=== Heap Sort ===\n";

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyStep(a, n, i, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);

        cout << "Swap max: ";
        printArray(a, n);

        heapifyStep(a, i, 0, n);
    }
}

// ================= MAIN =================
int main() {
    int a[100], n;
    int b[100];

    inputArray(a, n);

    cout << "\nMang ban dau: ";
    printArray(a, n);

    // Selection Sort
    copy(a, a + n, b);
    selectionSortStep(b, n);

    // Insertion Sort  
    copy(a, a + n, b);
    insertionSortStep(b, n);

    // Bubble Sort
    copy(a, a + n, b);
    bubbleSortStep(b, n);

    // Quick Sort
    copy(a, a + n, b);
    cout << "\n=== Quick Sort ===\n";
    quickSortStep(b, 0, n - 1, n);
    cout << "Ket qua Quick Sort: ";
    printArray(b, n);

    // Heap Sort
    copy(a, a + n, b);
    heapSortStep(b, n);

    cout << "\n=== KET QUA CUOI CUNG ===\n";
    printArray(b, n);

    return 0;
}
