#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

using Clock = chrono::high_resolution_clock;

// ============================================================
// BAI 2: QUICK SORT - 3 CHIEN LUOC CHON PIVOT
// ============================================================

struct QStats {
    long long comparisons = 0;
    long long swaps = 0;
};

// --- Pivot: Dau mang ---
int partitionFirst(vector<int>& arr, int low, int high, QStats& s) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        s.comparisons++;
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            s.swaps++;
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    s.swaps++;
    return i - 1;
}
void quickSortFirst(vector<int>& arr, int low, int high, QStats& s) {
    if (low < high) {
        int pi = partitionFirst(arr, low, high, s);
        quickSortFirst(arr, low, pi - 1, s);
        quickSortFirst(arr, pi + 1, high, s);
    }
}

// --- Pivot: Cuoi mang ---
int partitionLast(vector<int>& arr, int low, int high, QStats& s) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        s.comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            s.swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    s.swaps++;
    return i + 1;
}

void quickSortLast(vector<int>& arr, int low, int high, QStats& s) {
    if (low < high) {
        int pi = partitionLast(arr, low, high, s);
        quickSortLast(arr, low, pi - 1, s);
        quickSortLast(arr, pi + 1, high, s);
    }
}

// --- Pivot: Giua mang ---
int partitionMiddle(vector<int>& arr, int low, int high, QStats& s) {
    int mid = low + (high - low) / 2;
    swap(arr[mid], arr[high]); // dua pivot ve cuoiint pivot = arr[high];
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        s.comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            s.swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    s.swaps++;
    return i + 1;
}

void quickSortMiddle(vector<int>& arr, int low, int high, QStats& s) {
    if (low < high) {
        int pi = partitionMiddle(arr, low, high, s);
        quickSortMiddle(arr, low, pi - 1, s);
        quickSortMiddle(arr, pi + 1, high, s);
    }
}

// --- Pivot: Ngau nhien ---
int partitionRandom(vector<int>& arr, int low, int high, QStats& s) {
    int randIdx = low + rand() % (high - low + 1);
    swap(arr[randIdx], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        s.comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            s.swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    s.swaps++;
    return i + 1;
}

void quickSortRandom(vector<int>& arr, int low, int high, QStats& s) {
    if (low < high) {
        int pi = partitionRandom(arr, low, high, s);
        quickSortRandom(arr, low, pi - 1, s);
        quickSortRandom(arr, pi + 1, high, s);
    }
}

void bai2_quicksort() {
    const int N = 1000;
    srand(42);

    // Tao mang ngau nhien goc
    vector<int> base(N);
    for (int i = 0; i < N; i++) base[i] = rand() % 10000;

    // Mang da sap xep (worst case cho pivot dau/cuoi)
    vector<int> sorted_asc = base;
    sort(sorted_asc.begin(), sorted_asc.end());

    // Mang nguoc chieu
    vector<int> sorted_desc = sorted_asc;
    reverse(sorted_desc.begin(), sorted_desc.end());

    cout << "============================================================\n";
    cout << "BAI 2: QUICK SORT - SO SANH 4 CHIEN LUOC CHON PIVOT\n";
    cout << "        (mang " << N << " phan tu)\n";
    cout << "============================================================\n\n";

    // Header
    cout << left
        << setw(18) << "Pivot"
        << setw(16) << "Mang ngau nhien"
        << setw(16) << ""
        << setw(16) << "Mang tang dan"
        << setw(16) << ""
        << setw(16) << "Mang nguoc chieu"
        << endl;
    cout << left << setw(18) << ""
        << setw(16) << "So sanh"
        << setw(16) << "Hoan vi"
        << setw(16) << "So sanh"
        << setw(16) << "Hoan vi"
        << setw(16) << "So sanh"
        << setw(16) << "Hoan vi"
        << endl;
    cout << string(98, '-') << endl;

    // Chay tung chien luoc voi 3 loai mang
    struct PivotTest {
        string name;
        void (*fn)(vector<int>&, int, int, QStats&);
    };

    // Do thoi gian
    auto measure = [](vector<int> arr, void (*fn)(vector<int>&, int, int, QStats&), QStats& s) -> double {
        auto start = Clock::now();
        fn(arr, 0, arr.size() - 1, s);
        return chrono::duration<double, micro>(Clock::now() - start).count();
        };

    auto runRow = [&](string name, void (*fn)(vector<int>&, int, int, QStats&)) {
        QStats s1, s2, s3;
        vector<int> a1 = base, a2 = sorted_asc, a3 = sorted_desc;
        fn(a1, 0, N - 1, s1);
        fn(a2, 0, N - 1, s2);
        fn(a3, 0, N - 1, s3);
        cout << left
            << setw(18) << name
            << setw(16) << s1.comparisons
            << setw(16) << s1.swaps
            << setw(16) << s2.comparisons
            << setw(16) << s2.swaps
            << setw(16) << s3.comparisons
            << setw(16) << s3.swaps
            << endl;
        };

    runRow("Pivot: Dau", quickSortFirst);
    runRow("Pivot: Cuoi", quickSortLast);
    runRow("Pivot: Giua", quickSortMiddle);
    runRow("Pivot: Ngau nhien", quickSortRandom);

    cout << "\nKET LUAN QUICK SORT:\n";
    cout << "- Pivot Dau/Cuoi: worst case O(n^2) khi mang da sap xep!\n";cout << "- Pivot Giua:     tot hon nhieu voi mang da sap xep\n";
    cout << "- Pivot Ngau nhien: hieu nang on dinh nhat, tranh worst case\n";
    cout << "=> Khuyen dung: Pivot Ngau nhien hoac Giua trong thuc te\n";
}

// ============================================================
// BAI 3: HEAP SORT - IN TUNG BUOC XAY DUNG HEAP
// ============================================================

int heapSize; // bien global cho heap

void printArr(const vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
// Heapify xuong (max-heap)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])   largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSortDemo(vector<int> arr) {
    int n = arr.size();

    cout << "\n--- Heap Sort (demo mang nho) ---\n";
    cout << "Ban dau:  "; printArr(arr, n);

    // === BUOC 1: Xay dung Max-Heap ===
    cout << "\n[BUOC 1] Xay dung Max-Heap (heapify tu duoi len):\n";
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        cout << "  Heapify node " << i << ": "; printArr(arr, n);
    }
    cout << "=> Max-Heap hoan chinh: "; printArr(arr, n);

    // === BUOC 2: Trich xuat tung phan tu lon nhat ===
    cout << "\n[BUOC 2] Trich xuat va sap xep:\n";
    for (int i = n - 1; i > 0; i--) {
        cout << "  Doi arr[0]=" << arr[0] << " voi arr[" << i << "]=" << arr[i] << " -> ";
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        printArr(arr, n);
    }

    cout << "\nKet qua: "; printArr(arr, n);
}

// Ham heapify rieng de dem so sanh va hoan vi (tranh dung lambda de quy)
void heapifyCount(vector<int>& arr, int sz, int i, long long& cmps, long long& swps) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < sz) { cmps++; if (arr[l] > arr[largest]) largest = l; }
    if (r < sz) { cmps++; if (arr[r] > arr[largest]) largest = r; }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        swps++;
        heapifyCount(arr, sz, largest, cmps, swps);
    }
}

void heapSortCount(vector<int> arr, long long& cmps, long long& swps) {
    cmps = 0; swps = 0;
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapifyCount(arr, n, i, cmps, swps);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        swps++;
        heapifyCount(arr, i, 0, cmps, swps);
    }
}

void bai3_heapsort() {
    cout << "\n============================================================\n";
    cout << "BAI 3: HEAP SORT\n";
    cout << "============================================================\n";

    // Demo voi mang nho
    vector<int> demo = { 4, 10, 3, 5, 1, 8, 7 };
    heapSortDemo(demo);
    const int N = 5000;
    srand(42);
    vector<int> base(N);
    for (int i = 0; i < N; i++) base[i] = rand() % 10000;

    vector<int> sorted_asc = base;
    sort(sorted_asc.begin(), sorted_asc.end());
    vector<int> sorted_desc = sorted_asc;
    reverse(sorted_desc.begin(), sorted_desc.end());

    cout << "\n--- So sanh Heap Sort vs Basic Sorts (n=" << N << ") ---\n";

    // Bubble
    auto bubbleCount = [](vector<int> arr, long long& c, long long& s) {
        c = s = 0; int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            bool sw = false;
            for (int j = 0; j < n - i - 1; j++) { c++; if (arr[j] > arr[j + 1]) { swap(arr[j], arr[j + 1]); s++; sw = true; } }
            if (!sw) break;
        }
        };
    // Insertion
    auto insertCount = [](vector<int> arr, long long& c, long long& s) {
        c = s = 0; int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i], j = i - 1;
            while (j >= 0) { c++; if (arr[j] > key) { arr[j + 1] = arr[j]; s++; j--; } else break; }
            arr[j + 1] = key;
        }
        };

    cout << left << setw(22) << "Thuat toan"
        << setw(18) << "Ngau nhien (ss)"
        << setw(18) << "Tang dan (ss)"
        << setw(18) << "Nguoc chieu (ss)" << endl;
    cout << string(76, '-') << endl;

    auto printRow = [&](string name, auto fn) {
        long long c1, s1, c2, s2, c3, s3;
        fn(base, c1, s1);
        fn(sorted_asc, c2, s2);
        fn(sorted_desc, c3, s3);
        cout << left << setw(22) << name
            << setw(18) << c1
            << setw(18) << c2
            << setw(18) << c3 << endl;
        };

    printRow("Heap Sort", [&](vector<int> a, long long& c, long long& s) { heapSortCount(a, c, s); });
    printRow("Bubble Sort", bubbleCount);
    printRow("Insertion Sort", insertCount);

    cout << "\nKET LUAN HEAP SORT:\n";
    cout << "- Luon dat O(n log n) trong moi truong hop (best/worst/average)\n";
    cout << "- Khong can them bo nho phu (in-place)\n";
    cout << "- Nhanh hon Bubble Sort va Insertion Sort (worst case) rat nhieu\n";
    cout << "- Nhuoc diem: khong on dinh (unstable sort)\n";
}

// ============================================================
// MAIN
// ============================================================

int main() {
    bai2_quicksort();
    bai3_heapsort();
    return 0;
}
    // So sanh voi Bubble/Selection/Insertion tren mang lon
