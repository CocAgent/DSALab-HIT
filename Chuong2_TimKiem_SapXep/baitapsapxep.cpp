#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// 1. Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

// 2. Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 3. Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

// 4. Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 5. Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int data[] = {3, -12, 14, 9, 11, -50, -100};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Day so ban dau: "; printArray(data, n);
    
    // Test 1 thuat toan (vi du Bubble Sort)
    bubbleSort(data, n);
    
    cout << "Ket qua sau khi sap xep tang dan: ";
    printArray(data, n);

    return 0;
}

/* PHÂN TÍCH ĐỘ PHỨC TẠP:
1. Selection Sort: O(n^2) - Luôn quét mảng tìm min.
2. Insertion Sort: Best O(n), Worst O(n^2) - Hiệu quả khi mảng gần đúng.
3. Bubble Sort: Best O(n), Worst O(n^2) - So sánh cặp cạnh nhau.
4. Quick Sort: Best O(n log n), Worst O(n^2) - Chia để trị.
5. Heap Sort: O(n log n) - Dựa trên cấu trúc Heap.
*/
