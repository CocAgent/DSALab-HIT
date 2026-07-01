# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.
// 1. O(1): Truy xuất mảng
int x = arr[5]; 

// 2. O(n):
for(int i = 0; i < n; i++) sum++; 

// 3. O(n):
for(int i = 0; i < n; i += 2) sum++; 

// 4. O(n):
for(int i = 0; i < n; i++) sum++;
for(int j = 0; j < n; j++) sum++;

// 5. O(n²)
for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) sum++;

// 6. O(n²):
for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++) sum++;

// 7. O(log n):
for(int i = 1; i < n; i *= 2) sum++;

// 8. O(n log n):
for(int i = 0; i < n; i++)
    for(int j = 1; j < n; j *= 2) sum++;

// 9. O(n³):
for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++) sum++;

// 10. O(2^n)
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
//Vòng lặp độc lập (nối tiếp): Lấy vòng lặp có Big-O to nhất, bỏ vòng nhỏ.
//Vòng lặp lồng nhau: Nhân Big-O của vòng ngoài với Big-O của vòng trong.
### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.
#include <iostream>
#include <chrono>

void measureTime(int n) {
    auto start = std::chrono::high_resolution_clock::now();

    volatile long long sum = 0; // Dùng volatile để compiler không tối ưu hóa bỏ vòng lặp
    for(int i = 0; i < n; i++) sum++; // Ví dụ O(n)

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = end - start;
    
    std::cout << "n = " << n << " mat " << ms_double.count() << " ms\n";
}
### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <chrono>

using namespace std;

bool containsDuplicate_Slow(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++)
        for (size_t j = i + 1; j < arr.size(); j++)
            if (arr[i] == arr[j]) return true;
    return false;
}

bool containsDuplicate_Fast(const vector<int>& arr) {
    unordered_set<int> seen;
    for (int x : arr) {
        if (seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}

bool twoSum_Slow(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++)
        for (size_t j = i + 1; j < arr.size(); j++)
            if (arr[i] + arr[j] == target) return true;
    return false;
}

bool twoSum_Fast(const vector<int>& arr, int target) {
    unordered_map<int, int> map;
    for (size_t i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (map.count(complement)) return true;
        map[arr[i]] = i;
    }
    return false;
}

int maxSubArray_Slow(const vector<int>& arr) {
    int max_sum = arr[0];
    for (size_t i = 0; i < arr.size(); i++) {
        int current_sum = 0;
        for (size_t j = i; j < arr.size(); j++) {
            current_sum += arr[j];
            if (current_sum > max_sum) max_sum = current_sum;
        }
    }
    return max_sum;
}

int maxSubArray_Fast(const vector<int>& arr) {
    int current_max = arr[0], global_max = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        current_max = max(arr[i], current_max + arr[i]);
        global_max = max(global_max, current_max);
    }
    return global_max;
}

void run_benchmark(const vector<int>& data) {
    auto start = chrono::high_resolution_clock::now();
    containsDuplicate_Slow(data);
    auto end = chrono::high_resolution_clock::now();
    cout << "Contains Duplicate O(n^2) mat: " 
         << chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    start = chrono::high_resolution_clock::now();
    containsDuplicate_Fast(data);
    end = chrono::high_resolution_clock::now();
    cout << "Contains Duplicate O(n) mat  : " 
         << chrono::duration<double, std::milli>(end - start).count() << " ms\n";
}

int main() {
    vector<int> test_data(15000);
    for (int i = 0; i < 15000; i++) test_data[i] = i;

    cout << "--- KET QUA DO THOI GIAN MAU (N = 15000) ---\n";
    run_benchmark(test_data);
    
    return 0;
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
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void func_O1(int n) {
    volatile int x = n; 
}

void func_OlogN(int n) {
    volatile int sum = 0;
    for (int i = 1; i < n; i *= 2) sum++;
}

void func_ON(int n) {
    volatile int sum = 0;
    for (int i = 0; i < n; i++) sum++;
}

void func_ON2(int n) {
    volatile int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum++;
        }
    }
}

double measure(void (*func)(int), int n) {
    auto start = chrono::high_resolution_clock::now();
    func(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    vector<int> sizes = {1000, 10000, 100000};
    
    vector<pair<string, void(*)(int)>> algorithms = {
        {"O(1)", func_O1},
        {"O(log n)", func_OlogN},
        {"O(n)", func_ON},
        {"O(n^2)", func_ON2}
    };

    ofstream outFile("benchmark.txt");
    
    auto print = [&](const string& text) {
        cout << text;
        outFile << text;
    };

    print("╔══════════════╦═════════════╦═════════════╦═════════════╗\n");
    print("║  Thuật toán  ║   n=1000    ║   n=10000   ║  n=100000   ║\n");
    print("╠══════════════╬═════════════╬═════════════╬═════════════╣\n");

    for (const auto& algo : algorithms) {
        cout << "║ " << left << setw(12) << algo.first << " ║";
        outFile << "║ " << left << setw(12) << algo.first << " ║";

        for (int n : sizes) {
            double ms = measure(algo.second, n);
            
            char buffer[20];
            snprintf(buffer, sizeof(buffer), "%.3fms", ms);
            
            cout << " " << left << setw(11) << buffer << " ║";
            outFile << " " << left << setw(11) << buffer << " ║";
        }
        print("\n");
    }

    // Vẽ Footer của bảng ASCII
    print("╚══════════════╩═════════════╩═════════════╩═════════════╝\n");

    cout << "\n[!] Da hoan thanh benchmark. Ket qua duoc luu tai 'benchmark.txt'.\n";
    outFile.close();

    return 0;
}
**Yêu cầu:** dùng `std::chrono`, hiển thị bảng căn chỉnh đẹp, xuất ra file `benchmark.txt`..

---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
