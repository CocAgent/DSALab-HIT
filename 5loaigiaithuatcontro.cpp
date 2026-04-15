


#include <iostream>
using namespace std;

// Swap hai giá trị thông qua con trỏ
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// In mảng
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

// 1. Bubble Sort (Nổi bọt)
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (*(arr + j) > *(arr + j + 1))
                swap(arr + j, arr + j + 1);
}

// 2. Selection Sort (Chọn)
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int* minPtr = arr + i;
        for (int j = i + 1; j < n; j++)
            if (*(arr + j) < *minPtr)
                minPtr = arr + j;
        swap(arr + i, minPtr);
    }
}

// 3. Insertion Sort (Chèn)
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = *(arr + i);
        int j = i - 1;
        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

// 4. Quick Sort (Sử dụng con trỏ)
int* partition(int* low, int* high) {
    int pivot = *high;
    int* i = low - 1;
    for (int* j = low; j <= high - 1; j++) {
        if (*j < pivot) {
            i++;
            swap(i, j);
        }
    }
    swap(i + 1, high);
    return i + 1;
}

void quickSort(int* low, int* high) {
    if (low < high) {
        int* pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

// 5. Merge Sort (Sử dụng con trỏ)
void merge(int* arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = *(arr + l + i);
    for (int j = 0; j < n2; j++) R[j] = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            *(arr + k++) = L[i++];
        else
            *(arr + k++) = R[j++];
    }
    while (i < n1) *(arr + k++) = L[i++];
    while (j < n2) *(arr + k++) = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu arr[" << i << "]: ";
        cin >> *(arr + i);
    }

    int choice;
    cout << "\nChon thuat toan sap xep:\n";
    cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n5. Merge Sort\n";
    cout << "Lua chon: ";
    cin >> choice;

    cout << "\nMang truoc khi sap xep: ";
    printArray(arr, n);

    switch (choice) {
    case 1: bubbleSort(arr, n); break;
    case 2: selectionSort(arr, n); break;
    case 3: insertionSort(arr, n); break;
    case 4: quickSort(arr, arr + n - 1); break;
    case 5: mergeSort(arr, 0, n - 1); break;
    default: cout << "Lua chon khong hop le!\n"; break;
    }

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}