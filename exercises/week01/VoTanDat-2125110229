# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.
1: Thời gian hằng số — O(1)
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
Giải thích: Đoạn code này chỉ thực hiện 3 phép gán cơ bản. Số lượng phép tính không thay đổi dù giá trị của a và b có lớn bao nhiêu đi chăng nữa. Do đó, độ phức tạp là hằng số.
Kết luận: O(1)

2: Vòng lặp đơn tuyến tính — O(n)
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
Giải thích: Vòng lặp for chạy từ 0 đến n - 1. Thân vòng lặp thực hiện một lệnh cout (tốn O(1)). Vì vòng lặp chạy đúng n lần, tổng số phép tính tỷ lệ thuận tuyến tính với n.
Kết luận: O(n)

3: Hai vòng lặp độc lập - O(n)
void duplicateLoops(int n) {
    for (int i = 0; i < n; i++) {
        // Thực hiện một số lệnh O(1)
    }
    for (int j = 0; j < n; j++) {
        // Thực hiện một số lệnh O(1)
    }
}
Giải thích: Đoạn code có hai vòng lặp rời nhau. Vòng lặp đầu tiên tốn O(n), vòng lặp thứ hai tốn O(n). Tổng thời gian chạy là n + n = 2n. Theo quy tắc bỏ qua hằng số trong Big-O, ta giữ lại O(n).
Kết luận: O(n).

4: Vòng lặp lồng nhau (Bình phương) — O(n^2)
void printPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i] << ", " << arr[j] << endl;
        }
    }
}
Giải thích: Vòng lặp ngoài chạy n lần. Với mỗi lần vòng lặp ngoài chạy, vòng lặp trong lại chạy n lần. Tổng số lần lệnh cout được thực hiện là n*n = n^2.
Kết luận: O(n^2)

5: Vòng lặp hình tam giác — O(n^2)
void printTriplets(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << i << " " << j << endl;
        }
    }
}
Giải thích:
    -Khi i = 0, vòng lặp trong chạy n - 1 lần.
    -Khi $i = 1$, vòng lặp trong chạy n - 2 lần.
    -...
    -Khi $i = n - 1$, vòng lặp trong chạy 0 lần.
    -Tổng số lần chạy là: (n - 1) + (n - 2) + ... + 1 + 0 = n(n-1)/2=n^2/2-n/2.
    -Theo quy tắc Big-O, ta chỉ giữ lại thành phần bậc cao nhất và bỏ qua hằng số, tức là n^2.
    Kết luận: O(n^2).
    
  6: Vòng lặp nhảy bước nhân/chia — O(\log n)
void binarySearchSimulation(int n) {
    int i = 1;
    while (i < n) {
        i = i * 2;
    }
}
Giải thích: Biến i bắt đầu từ 1 và nhân đôi sau mỗi vòng lặp (1, 2, 4, 8, 16,...). Sau k lần lặp, giá trị của i sẽ là 2^k. Vòng lặp dừng lại khi 2^k >=n->k~log_2(n)
Kết luận: O(\log n).

7:Vòng lặp lồng nhau kết hợp bước nhảy — O(n \log n)
void mixedLoops(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j = j * 2) {
            // Lệnh O(1)
        }
    }
}
Giải thích: Vòng lặp ngoài chạy tuyến tính n lần. Vòng lặp trong tương tự như Ví dụ 6, biến j nhân đôi liên tục nên nó chạy log_2(n) lần. Vì hai vòng lặp lồng nhau, ta nhân độ phức tạp của chúng lại: n*log_2(n).
Kết luận: O(n log n).

 8: Vòng lặp căn bậc hai — O(sqrt{n})
 bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
Giải thích: Điều kiện dừng của vòng lặp là i * i<= n, tương đương với i <= sqrt{n}. Do đó, biến i tăng tuyến tính từ 2 cho đến tối đa là sqrt{n}. Số lần lặp tối đa tỷ lệ thuận với sqrt{n}.
Kết luận: O(\sqrt{n})

9: Đệ quy tuyến tính — O(n)
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
Giải thích: Hàm đệ quy này gọi lại chính nó với tham số giảm dần 1 đơn vị: factorial(n) -> factorial(n-1) -> ... -> factorial(1). Sẽ có tổng cộng n tầng gọi đệ quy, mỗi tầng thực hiện phép tính với độ phức tạp O(1).
Kết luận: O(n)

10: Đệ quy nhánh (Cây nhị phân) — O(2^n)
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
Giải thích: Mỗi lần hàm fibonacci(n) được gọi, nó lại sinh ra 2 lời gọi đệ quy mới (fibonacci(n-1) và fibonacci(n-2)). Điều này tạo nên một cây quyết định dạng nhị phân. Chiều cao của cây là n, và ở mỗi tầng, số lượng lời gọi hàm tăng theo cấp số nhân: Tầng 0 có 1 cuộc gọi, Tầng 1 có 2, Tầng 2 có 4,..., Tầng n có khoảng 2^n cuộc gọi.
Kết luận: O(2^n)
### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.

### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.

### Bài 4: 🔥 Dự Án Mini — Big-O Benchmark Tool ⭐⭐⭐
> **Cảm hứng:** [algorithm-visualizer.org](https://algorithm-visualizer.org)

Viết chương trình **BenchmarkTool** hiển thị bảng so sánh tốc độ các thuật toán:
```
╔══════════════╦══════════╦══════════╦══════════╗
║   Thuật toán ║  n=1000  ║  n=10000 ║ n=100000 ║
╠══════════════╬══════════╬══════════╬══════════╣
║    O(1)      ║  0.001ms ║  0.001ms ║  0.001ms ║
║    O(log n)  ║  0.003ms ║  0.004ms ║  0.005ms ║
║    O(n)      ║  0.12ms  ║  1.2ms   ║  12ms    ║
║    O(n²)     ║  8ms     ║  800ms   ║  80000ms ║
╚══════════════╩══════════╩══════════╩══════════╝
```

**Yêu cầu:** dùng `std::chrono`, hiển thị bảng căn chỉnh đẹp, xuất ra file `benchmark.txt`.

---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
