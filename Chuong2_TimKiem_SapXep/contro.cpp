```cpp
#include <iostream>
using namespace std;

// 🔹 Hoán đổi 2 số bằng con trỏ
void swapNumbers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 🔹 Tính tổng mảng bằng con trỏ
int sumArray(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    return sum;
}

// 🔹 Tìm số lớn nhất trong mảng
int maxArray(int *arr, int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > maxVal) {
            maxVal = *(arr + i);
        }
    }
    return maxVal;
}

int main() {
    // ===== 1. Con trỏ cơ bản =====
    int a = 10;
    int *p = &a;

    cout << "Gia tri a: " << a << endl;
    cout << "Dia chi a: " << &a << endl;
    cout << "Con tro p: " << p << endl;
    cout << "Gia tri tai p (*p): " << *p << endl;

    // Thay đổi giá trị qua con trỏ
    *p = 50;
    cout << "Sau khi doi, a = " << a << endl;

    cout << "------------------------" << endl;

    // ===== 2. Hoán đổi =====
    int x = 5, y = 20;
    cout << "Truoc swap: x = " << x << ", y = " << y << endl;
    swapNumbers(&x, &y);
    cout << "Sau swap: x = " << x << ", y = " << y << endl;

    cout << "------------------------" << endl;

    // ===== 3. Mảng + con trỏ =====
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Tong mang: " << sumArray(arr, n) << endl;
    cout << "Max mang: " << maxArray(arr, n) << endl;

    cout << "Phan tu thu 3 (pointer): " << *(arr + 2) << endl;

    cout << "------------------------" << endl;

    // ===== 4. Cấp phát động =====
    int *ptr = new int;
    *ptr = 100;

    cout << "Gia tri cap phat dong: " << *ptr << endl;

    delete ptr; // giải phóng bộ nhớ

    return 0;
}
```
