//MSSV: 2125110180

# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.
Code 1: Vòng lặp đơn giản
cppvoid example1(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
}
Big-O: O(n)

Vòng lặp chạy đúng n lần
Mỗi lần lặp thực hiện thao tác O(1)
Tổng: n × O(1) = O(n)


Code 2: Vòng lặp lồng nhau
cppvoid example2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i * j << " ";
        }
    }
}
Big-O: O(n²)

Vòng ngoài chạy n lần
Vòng trong chạy n lần với mỗi lần lặp của vòng ngoài
Tổng: n × n = O(n²)


Code 3: Binary Search
cppint binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
Big-O: O(log n)

Mỗi lần lặp chia không gian tìm kiếm làm đôi
Số lần lặp tối đa: log₂(n)
Điển hình cho thuật toán “chia để trị”


Code 4: Ba vòng lặp tuần tự
cppvoid example4(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    
    for (int j = 0; j < n; j++) {
        cout << j << " ";
    }
    
    for (int k = 0; k < n; k++) {
        cout << k << " ";
    }
}
Big-O: O(n)

Vòng 1: O(n)
Vòng 2: O(n)
Vòng 3: O(n)
Tổng: O(n) + O(n) + O(n) = O(3n) = O(n)
Bỏ hằng số 3


Code 5: Vòng lặp với bước nhảy
cppvoid example5(int n) {
    for (int i = 1; i < n; i = i * 2) {
        cout << i << " ";
    }
}
Big-O: O(log n)

i tăng theo cấp số nhân: 1, 2, 4, 8, 16, ..., n
Số lần lặp k thoả mãn: 2^k = n → k = log₂(n)
Tương tự binary search


Code 6: Ba vòng lặp lồng nhau
cppvoid example6(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << i + j + k << " ";
            }
        }
    }
}
Big-O: O(n³)

Vòng 1: n lần
Vòng 2: n lần × vòng 1
Vòng 3: n lần × vòng 2
Tổng: n × n × n = O(n³)


Code 7: Vòng lặp phụ thuộc
cppvoid example7(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << i * j << " ";
        }
    }
}
Big-O: O(n²)

Vòng ngoài: n lần
Vòng trong: 0 + 1 + 2 + ... + (n-1) = n(n-1)/2
Công thức tổng cấp số cộng: O(n²/2) = O(n²)


Code 8: Thao tác hằng số
cppvoid example8(int n) {
    int x = n * 2;
    int y = x + 5;
    int z = y * y;
    cout << z;
}
Big-O: O(1)

Không có vòng lặp
Số lượng thao tác cố định, không phụ thuộc n
Độ phức tạp hằng số


Code 9: Đệ quy Fibonacci (naive)
cppint fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
Big-O: O(2ⁿ)

Mỗi lần gọi tạo ra 2 lời gọi đệ quy
Cây đệ quy có chiều cao n
Số nút trong cây: xấp xỉ 2ⁿ
Độ phức tạp mũ - rất chậm!


Code 10: Merge Sort
cppvoid merge(int arr[], int l, int m, int r) {
    // Merge hai mảng con - O(n)
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
Big-O: O(n log n)

Chia mảng làm đôi mỗi cấp: log n cấp
Mỗi cấp merge tất cả n phần tử: O(n)
Tong: O(n) × O(log n) = O(n log n)
Thuật toán sắp xếp hiệu quả nhất trong trường hợp tổng quát


### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.
╔════════════╦══════════════════╦══════════════════╦══════════════════╗
║     n      ║   O(log n)       ║     O(n)         ║     O(n²)        ║
╠════════════╬══════════════════╬══════════════════╬══════════════════╣
║      1.000 ║        18.30 μs  ║        17.40 μs  ║        24.17 ms  ║
║      5.000 ║        59.90 μs  ║        87.40 μs  ║       712.91 ms  ║
║     10.000 ║       109.10 μs  ║       163.50 μs  ║      2856.70 ms  ║
║     25.000 ║       237.10 μs  ║       430.30 μs  ║     17680.48 ms  ║
║     50.000 ║       493.40 μs  ║       805.70 μs  ║     70155.93 ms  ║
║     75.000 ║       704.00 μs  ║      1313.40 μs  ║    157344.62 ms  ║
║    100.000 ║      1080.50 μs  ║      1834.60 μs  ║    279348.20 ms  ║ 
╚════════════╩══════════════════╩══════════════════╩══════════════════╝

📊 Phân tích:
  • O(log n): Tăng rất chậm - gần như không đổi khi n tăng
  • O(n):     Tăng tuyến tính - gấp đôi n thì thời gian gấp đôi
  • O(n²):    Tăng bậc hai - gấp đôi n thì thời gian tăng gấp 4 lần

💡 Lưu ý: Với n > 10.000, thời gian O(n²) được ước tính để tránh chạy quá lâu.
### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.
1. Đếm cặp / tìm tổng (O(n²) → O(n log n) hoặc O(n))
Bản O(n²)
for (int i = 0; i < n; i++)
  for (int j = i+1; j < n; j++)
    if (a[i] + a[j] == k) count++;
Tối ưu O(n log n) (sort + 2 pointers)
sort(a, a+n);
int l = 0, r = n-1;
while (l < r) {
    int sum = a[l] + a[r];
    if (sum == k) { count++; l++; r--; }
    else if (sum < k) l++;
    else r--;
}

 Ý tưởng: thay vòng lặp đôi bằng “quét 2 đầu”

2. Tính tổng đoạn con nhiều lần (O(n²) → O(n))
Bản O(n²)
for (int i = 0; i < n; i++) {
  int sum = 0;
  for (int j = i; j < n; j++) {
    sum += a[j];
  }
}
Tối ưu O(n) (prefix sum)
prefix[0] = a[0];
for (int i = 1; i < n; i++)
    prefix[i] = prefix[i-1] + a[i];

// sum(i, j) = prefix[j] - prefix[i-1]

 Ý tưởng: tránh tính lại tổng nhiều lần

3. Kiểm tra trùng phần tử (O(n²) → O(n))
Bản O(n²)
for (int i = 0; i < n; i++)
  for (int j = i+1; j < n; j++)
    if (a[i] == a[j]) return true;
Tối ưu O(n) (hash set)
unordered_set<int> s;
for (int x : a) {
    if (s.count(x)) return true;
    s.insert(x);
}
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

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

class BenchmarkTool {
private:
    vector<int> sizes = { 1000, 10000, 100000 };
    const int ITERATIONS = 100; // Chạy 100 lần để lấy trung bình cho chính xác

    // Đo thời gian thực thi
    double measure(string type, int n) {
        auto start = high_resolution_clock::now();

        for (int it = 0; it < ITERATIONS; ++it) {
            volatile long long sum = 0;
            if (type == "O(1)") {
                sum += 1;
            }
            else if (type == "O(log n)") {
                for (int i = 1; i < n; i *= 2) sum += i;
            }
            else if (type == "O(n)") {
                for (int i = 0; i < n; ++i) sum += i;
            }
            else if (type == "O(n²)") {
                // Giới hạn n để tránh treo máy, n² của 100.000 là 10 tỷ phép tính
                int limit = (n > 5000) ? 5000 : n;
                for (int i = 0; i < limit; ++i)
                    for (int j = 0; j < limit; ++j) sum += (i + j);

                // Tính toán bù trừ thời gian cho n thực tế
                if (n > 5000) {
                    auto end = high_resolution_clock::now();
                    double base_ms = duration<double, std::milli>(end - start).count() / ITERATIONS;
                    return base_ms * pow((double)n / limit, 2);
                }
            }
        }

        auto end = high_resolution_clock::now();
        duration<double, std::milli> diff = end - start;
        return diff.count() / ITERATIONS; // Trả về thời gian trung bình
    }

    string formatTime(double ms) {
        stringstream ss;
        if (ms < 0.0001) return " <0.001ms";
        ss << fixed << setprecision(3) << ms << "ms";
        return ss.str();
    }
    S
public:
    void run() {
        vector<string> algos = { "O(1)", "O(log n)", "O(n)", "O(n²)" };
        ofstream outFile("benchmark.txt");

        auto printLine = [&](ostream& os, char left, char mid, char right, char fill) {
            os << left << string(14, fill) << mid << string(11, fill)
                << mid << string(11, fill) << mid << string(11, fill) << right << endl;
            };

        auto renderTable = [&](ostream& os) {
            printLine(os, char(201), char(203), char(187), char(205)); // ╔═══╦═══╗
            os << "║ Thuật toán   ║ n=1000    ║ n=10000   ║ n=100000  ║" << endl;

            for (const auto& algo : algos) {
                printLine(os, char(204), char(206), char(185), char(205)); // ╠═══╬═══╣
                os << "║ " << left << setw(12) << algo;
                for (int n : sizes) {
                    os << " ║ " << left << setw(9) << formatTime(measure(algo, n));
                }
                os << " ║" << endl;
            }
            printLine(os, char(200), char(202), char(188), char(205)); // ╚═══╩═══╝
            };

        renderTable(cout);
        renderTable(outFile);

        cout << "\n[!] Da luu ket qua vao file benchmark.txt" << endl;
        outFile.close();
    }
};

int main() {
    BenchmarkTool tool;
    tool.run();
    return 0;
}
---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
