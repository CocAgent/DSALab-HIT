#include <iostream>
using namespace std;

// ===================== HÀM IN MẢNG =====================
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ===================== 1. SELECTION SORT =====================
void selectionSort(int arr[], int n) {
    cout << "\n=== SELECTION SORT - Chi tiet tung buoc ===\n";
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
        cout << "Pass " << i + 1 << ": ";
        printArray(arr, n);
    }
}

// ===================== 2. INSERTION SORT =====================
void insertionSort(int arr[], int n) {
    cout << "\n=== INSERTION SORT - Chi tiet tung buoc ===\n";
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        cout << "i=" << i << ", Key=" << key << " -> ";
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
}

// ===================== 3. BUBBLE SORT =====================
void bubbleSort(int arr[], int n) {
    cout << "\n=== BUBBLE SORT - Chi tiet tung buoc ===\n";
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        cout << "Pass " << i + 1 << ": ";
        printArray(arr, n);
        if (!swapped) break;
    }
}

// ===================== 4. QUICK SORT =====================
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ===================== 5. HEAP SORT =====================
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    cout << "\n=== HEAP SORT - Chi tiet tung buoc ===\n";
    // Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    cout << "Sau khi build Max-Heap: ";
    printArray(arr, n);

    // Extract max
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        cout << "Sau lan extract " << (n - i) << ": ";
        printArray(arr, n);
    }
}

// ===================== MENU =====================
int main() {
    int arr[] = {3, -12, 14, 9, 11, -50, -100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;
    int temp[10];  // mảng tạm để giữ nguyên dữ liệu gốc

    do {
        // Copy lại mảng gốc mỗi lần chạy
        for (int i = 0; i < n; i++) temp[i] = arr[i];

        cout << "\n=====================================\n";
        cout << "        CHUONG TRINH SAP XEP\n";
        cout << "=====================================\n";
        cout << "1. Selection Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Heap Sort\n";
        cout << "0. Thoat\n";
        cout << "Chon thuat toan (0-5): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Mang ban dau: "; printArray(temp, n);
            selectionSort(temp, n);
            break;
        case 2:
            cout << "Mang ban dau: "; printArray(temp, n);
            insertionSort(temp, n);
            break;
        case 3:
            cout << "Mang ban dau: "; printArray(temp, n);
            bubbleSort(temp, n);
            break;
        case 4:
            cout << "Mang ban dau: "; printArray(temp, n);
            quickSort(temp, 0, n - 1);
            cout << "\nSau Quick Sort: ";
            printArray(temp, n);
            break;
        case 5:
            cout << "Mang ban dau: "; printArray(temp, n);
            heapSort(temp, n);
            break;
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}
