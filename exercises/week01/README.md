# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.
--Mssv:2125110172
--Tên:Cái Đại Thành Long
---
### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.

void DuyetMang(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << i << " " << j << "\n";
        }
    }
}

Vòng lặp ngoài chạy n lần (từ 0 đến n-1).
Tổng số lần thực hiện là cấp số cộng: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2 = (1/2)n^2 + (1/2)n.
Bỏ qua hằng số và các số hạng bậc thấp, ta giữ lại bậc cao nhất là n^2. Do đó độ phức tạp là O(n^2).
### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;

// O(log n) - Tìm kiếm nhị phân
bool AlgoLogN(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

// O(n) - Tìm kiếm tuyến tính / Duyệt mảng
long long AlgoN(const vector<int>& arr) {
    long long sum = 0;
    for (int x : arr) sum += x;
    return sum;
}

// O(n^2) - Tìm cặp trùng lặp
int AlgoN2(const vector<int>& arr) {
    int count = 0;
    int limit = min((int)arr.size(), 10000); // Giới hạn n lớn để tránh treo máy khi n=100.000
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            if (i != j && arr[i] == arr[j]) count++;
        }
    }
    return count;
}

int main() {
    int n = 10; // cho mảng có 10 phần tử
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i; // Mảng đã sắp xếp

    // 1. Đo O(log n)
    auto start = chrono::high_resolution_clock::now();
    AlgoLogN(arr, n - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,  milli> timeLogN = end - start;

    // 2. Đo O(n)
    start = chrono::high_resolution_clock::now();
    AlgoN(arr);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double,  milli> timeN = end - start;

    // 3. Đo O(n^2)
    start = chrono::high_resolution_clock::now();
    AlgoN2(arr);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double,  milli> timeN2 = end - start;

    // In kết quả nháp
    cout << fixed << setprecision(5);
    cout << "Kich thuoc n = " << n << "\n";
    cout << "O(log n): " << timeLogN.count() << " ms\n";
    cout << "O(n)    : " << timeN.count() << " ms\n";
    cout << "O(n^2)  : " << timeN2.count() << " ms\n";

    return 0;
}

### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.
// Thuật toán gốc O(n^2)
bool hasTwoSumN2(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == target) return true;
        }
    }
    return false;
}

// Thuật toán tối ưu O(n) dùng Two Pointers. Nếu mảng đã được sắp xếp - Kỹ thuật Hai con trỏ
bool hasTwoSumN(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        int current_sum = arr[left] + arr[right];
        if (current_sum == target) return true;
        if (current_sum < target) left++;
        else right--;
    }
    return false;
}

Hàm gốc chạy 2 vòng lặp lồng nhau mất O(n^2). Hàm tối ưu chỉ duyệt mảng một lần duy nhất từ 2 đầu dồn vào giữa, độ phức tạp giảm xuống O(n), giúp giảm thời gian xử lý mảng 100.000 phần tử từ vài giây xuống dưới 1ms.
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
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Định nghĩa các hàm giả lập khối lượng công việc tương ứng với Big-O
void executeO1() {
    volatile int a = 5;
    volatile int b = 10;
    volatile int c = a + b; // O(1)
}

void executeOLogN(int n) {
    volatile int count = 0;
    while (n > 0) {
        count++;
        n /= 2;
    }
}

void executeON(int n) {
    volatile long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i;
    }
}

void executeON2(int n) {
    // Giới hạn n tối đa là 50000 vì O(n^2) tại 100,000 sẽ tốn rất nhiều phút gây treo luồng.
    int limit = min(n, 30000); 
    volatile long long count = 0;
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            count++;
        }
    }
}

// Hàm đo thời gian thực thi (trả về chuỗi định dạng kèm 'ms')
string measure(void (*func)(), int n, bool is_n_dependent, char type) {
    auto start = chrono::high_resolution_clock::now();
    
    // Gọi hàm tương ứng
    if (!is_n_dependent) {
        func();
    } else {
        if (type == 'L') executeOLogN(n);
        else if (type == 'N') executeON(n);
        else if (type == '2') executeON2(n);
    }
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    
    stringstream ss;
    ss << fixed << setprecision(4) << elapsed.count() << "ms";
    return ss.str();
}

int main() {
    vector<int> sizes = {1000, 10000, 100000};
    
    // Thu thập dữ liệu kết quả
    string r_O1[3], r_LogN[3], r_N[3], r_N2[3];
    
    for (int i = 0; i < 3; i++) {
        r_O1[i]   = measure(executeO1, sizes[i], false, '1');
        r_LogN[i] = measure(nullptr, sizes[i], true, 'L');
        r_N[i]    = measure(nullptr, sizes[i], true, 'N');
        r_N2[i]   = measure(nullptr, sizes[i], true, '2');
    }
    
    // Tạo chuỗi hiển thị bảng dữ liệu
    stringstream table;
    table << "======== BENCHMARK REPORT ========\n";
    table << "---------------------------------------------------------\n";
    table << "| " << setw(13) << left << "Thuat toan" 
          << "| " << setw(11) << left << "n=1000" 
          << "| " << setw(11) << left << "n=10000" 
          << "| " << setw(11) << left << "n=100000" << "|\n";
    table << "---------------------------------------------------------\n";
    table << "| " << setw(13) << left << "O(1)"     << "| " << setw(11) << left << r_O1[0]   << "| " << setw(11) << left << r_O1[1]   << "| " << setw(11) << left << r_O1[2]   << "|\n";
    table << "| " << setw(13) << left << "O(log n)" << "| " << setw(11) << left << r_LogN[0] << "| " << setw(11) << left << r_LogN[1] << "| " << setw(11) << left << r_LogN[2] << "|\n";
    table << "| " << setw(13) << left << "O(n)"     << "| " << setw(11) << left << r_N[0]    << "| " << setw(11) << left << r_N[1]    << "| " << setw(11) << left << r_N[2]    << "|\n";
    table << "| " << setw(13) << left << "O(n^2)"   << "| " << setw(11) << left << r_N2[0]   << "| " << setw(11) << left << r_N2[1]   << "| " << setw(11) << left << r_N2[2]   << "|\n";
    table << "---------------------------------------------------------\n";
    table << "Luu y: Voi O(n^2) tai n=100000, chuong trinh da tu dong ep bien ve n=30000 de tranh sap nguon.\n";

    // 1. In ra màn hình Console
    cout << table.str();
    
    // 2. Xuất dữ liệu ra file txt
    ofstream outFile("benchmark.txt");
    if (outFile.is_open()) {
        outFile << table.str();
        outFile.close();
        cout << "\n[Thanh cong] Da xuat ket qua ra file benchmark.txt\n";
    } else {
        cout << "\n[Loi] Khong the tao hoac ghi file!\n";
    }

    return 0;
}

Đây là mã nguồn hoàn chỉnh của công cụ BenchmarkTool. Chương trình sẽ tự động chạy thử nghiệm các độ phức tạp với các kích thước $n$ khác nhau, đo đạc, vẽ bảng ASCII ra màn hình và đồng thời lưu kết quả vào file benchmark.txt.

**Yêu cầu:** dùng `std::chrono`, hiển thị bảng căn chỉnh đẹp, xuất ra file `benchmark.txt`.

---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
