#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// 1. Giải thuật Tìm kiếm Tuyến tính (Linear Search - Không lính canh)
int linearSearch(const vector<int>& a, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i; // Trả về vị trí (index) đầu tiên tìm thấy
        }
    }
    return -1; // Không tìm thấy
}

// 2. Giải thuật Tìm kiếm Nhị phân (Binary Search) trên mảng tăng dần
int binarySearch(const vector<int>& a, int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, x;
    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    // Phát sinh mảng a tăng dần
    vector<int> a(n);
    srand(time(0));
    if (n > 0) {
        a[0] = rand() % 20 - 100; // Số đầu tiên ngẫu nhiên
        for (int i = 1; i < n; i++) {
            a[i] = a[i - 1] + (rand() % 10 + 1); // Đảm bảo phần tử sau lớn hơn phần tử trước
        }
    }

    // Xuất mảng đã phát sinh
    cout << "Mang a tang dan: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // --- PP Tìm tuyến tính ---
    cout << "\n[PP Tim tuyen tinh] Nhap x: ";
    cin >> x;
    cout << "Ket qua vt = " << linearSearch(a, n, x) << endl;

    // --- PP Tìm nhị phân ---
    cout << "\n[PP Tim nhi phan tang] Nhap x: ";
    cin >> x;
    cout << "Ket qua vt = " << binarySearch(a, n, x) << endl;

    return 0;
}
