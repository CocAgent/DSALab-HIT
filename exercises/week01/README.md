# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---Nguyễn ngọc hải 2125110162

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.

### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace std::chrono;

// Hàm giả lập O(log n)
void test_log_n(long long n) {
    long long count = 0;
    for (long long i = 1; i < n; i *= 2) {
        count++;
    }
}

// Hàm giả lập O(n)
void test_n(long long n) {
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        count++;
    }
}

// Hàm giả lập O(n^2)
void test_n_squared(long long n) {
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            count++;
        }
    }
}

int main() {
    // Mảng các giá trị n cần kiểm tra
    long long sizes[] = {1000, 5000, 10000, 50000, 100000};
    
    // In tiêu đề bảng
    cout << "+" << string(12, '-') << "+" << string(14, '-') << "+" << string(14, '-') << "+" << string(14, '-') << "+\n";
    cout << "| " << setw(10) << "n" 
         << " | " << setw(12) << "O(log n)" 
         << " | " << setw(12) << "O(n)" 
         << " | " << setw(12) << "O(n^2)" << " |\n";
    cout << "+" << string(12, '-') << "+" << string(14, '-') << "+" << string(14, '-') << "+" << string(14, '-') << "+\n";

    for (long long n : sizes) {
        // 1. Đo O(log n)
        auto start = high_resolution_clock::now();
        test_log_n(n);
        auto end = high_resolution_clock::now();
        double time_log_n = duration_cast<nanoseconds>(end - start).count() / 1e6; // Đổi sang ms

        // 2. Đo O(n)
        start = high_resolution_clock::now();
        test_n(n);
        end = high_resolution_clock::now();
        double time_n = duration_cast<nanoseconds>(end - start).count() / 1e6;

        // 3. Đo O(n^2)
        start = high_resolution_clock::now();
        test_n_squared(n);
        end = high_resolution_clock::now();
        double time_n_squared = duration_cast<nanoseconds>(end - start).count() / 1e6;

        // In dòng kết quả cho mỗi n
        cout << "| " << setw(10) << n 
             << " | " << setw(10) << fixed << setprecision(4) << time_log_n << " ms"
             << " | " << setw(10) << fixed << setprecision(4) << time_n << " ms"
             << " | " << setw(10) << fixed << setprecision(2) << time_n_squared << " ms" << " |\n";
    }
    
    cout << "+" << string(12, '-') << "+" << string(14, '-') << "+" << string(14, '-') << "+" << string(14, '-') << "+\n";
    return 0;
}
### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// =================================================================
// BÀI TOÁN 1: TWO SUM (Tìm xem có cặp số nào tổng bằng K không)
// =================================================================
bool twoSum_Slow(const vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return true;
        }
    }
    return false;
}

bool twoSum_Fast(vector<int> arr, int target) { // O(n log n) do có sắp xếp
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}

// =================================================================
// BÀI TOÁN 2: FIND DUPLICATE (Kiểm tra mảng có phần tử trùng không)
// =================================================================
bool hasDuplicate_Slow(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) return true;
        }
    }
    return false;
}

bool hasDuplicate_Fast(const vector<int>& arr) { // O(n) sử dụng mảng đánh dấu
    int max_val = 0;
    for (int x : arr) max_val = max(max_val, x);
    
    vector<bool> visited(max_val + 1, false);
    for (int x : arr) {
        if (visited[x]) return true;
        visited[x] = true;
    }
    return false;
}

// =================================================================
// BÀI TOÁN 3: PREFIX SUM (Tính tổng tất cả các phần tử liên tiếp)
// =================================================================
long long totalSubarraySum_Slow(const vector<int>& arr) {
    long long total = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            total += current_sum;
        }
    }
    return total;
}

long long totalSubarraySum_Fast(const vector<int>& arr) { // O(n) bằng toán học/cộng dồn
    long long total = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        // Phần tử arr[i] xuất hiện trong (i + 1) * (n - i) dãy con
        total += (long long)arr[i] * (i + 1) * (n - i);
    }
    return total;
}

// =================================================================
// HÀM MAIN: ĐO THỜI GIAN VÀ IN BẢNG CHỨNG MINH
// =================================================================
int main() {
    int n = 10000; // Kích thước dữ liệu thử nghiệm mẫu
    cout << "Dang khoi tao du lieu voi n = " << n << "...\n\n";
    
    // Khởi tạo dữ liệu ngẫu nhiên
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = i + 1; // Mảng tăng dần từ 1 đến n
    }
    int target = n * 2; // Target không tưởng để ép chạy hết vòng lặp

    // Format Bảng kết quả
    cout << "+" << string(25, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+\n";
    cout << "| " << setw(23) << left << " Bai toan (n = 10,000)" 
         << " | " << setw(13) << "Thoi gian O(n2)" 
         << " | " << setw(13) << "Thoi gian Toi uu" << " |\n";
    cout << "+" << string(25, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+\n";

    // --- Đo Bài 1 ---
    auto start = high_resolution_clock::now();
    twoSum_Slow(data, target);
    auto end = high_resolution_clock::now();
    double t1_slow = duration_cast<nanoseconds>(end - start).count() / 1e6;

    start = high_resolution_clock::now();
    twoSum_Fast(data, target);
    end = high_resolution_clock::now();
    double t1_fast = duration_cast<nanoseconds>(end - start).count() / 1e6;

    cout << "| " << setw(23) << left << "1. Two Sum" 
         << " | " << setw(10) << fixed << setprecision(2) << t1_slow << " ms"
         << " | " << setw(10) << fixed << setprecision(2) << t1_fast << " ms" << " |\n";

    // --- Đo Bài 2 ---
    start = high_resolution_clock::now();
    hasDuplicate_Slow(data);
    end = high_resolution_clock::now();
    double t2_slow = duration_cast<nanoseconds>(end - start).count() / 1e6;

    start = high_resolution_clock::now();
    hasDuplicate_Fast(data);
    end = high_resolution_clock::now();
    double t2_fast = duration_cast<nanoseconds>(end - start).count() / 1e6;

    cout << "| " << setw(23) << left << "2. Find Duplicate" 
         << " | " << setw(10) << fixed << setprecision(2) << t2_slow << " ms"
         << " | " << setw(10) << fixed << setprecision(2) << t2_fast << " ms" << " |\n";

    // --- Đo Bài 3 ---
    start = high_resolution_clock::now();
    totalSubarraySum_Slow(data);
    end = high_resolution_clock::now();
    double t3_slow = duration_cast<nanoseconds>(end - start).count() / 1e6;

    start = high_resolution_clock::now();
    totalSubarraySum_Fast(data);
    end = high_resolution_clock::now();
    double t3_fast = duration_cast<nanoseconds>(end - start).count() / 1e6;

    cout << "| " << setw(23) << left << "3. Subarray Sum" 
         << " | " << setw(10) << fixed << setprecision(2) << t3_slow << " ms"
         << " | " << setw(10) << fixed << setprecision(2) << t3_fast << " ms" << " |\n";

    cout << "+" << string(25, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+\n";

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

**Yêu cầu:** dùng `std::chrono`, hiển thị bảng căn chỉnh đẹp, xuất ra file `benchmark.txt`.

---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
