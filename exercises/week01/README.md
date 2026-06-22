# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.

### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Hàm mô phỏng O(log n)
void test_O_logn(long long n) {
    volatile long long sum = 0;
    for (long long i = 1; i < n; i *= 2) {
        sum += i;
    }
}

// Hàm mô phỏng O(n)
void test_O_n(long long n) {
    volatile long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        sum += i;
    }
}

// Hàm mô phỏng O(n^2)
void test_O_n2(long long n) {
    volatile long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            sum += j;
        }
    }
}

// Hàm đo thời gian thực thi
template <typename Func>
double measure_time(Func func, long long n) {
    auto start = high_resolution_clock::now();
    func(n);
    auto end = high_resolution_clock::now();
    
    // Trả về thời gian tính bằng microgiây (microseconds)
    return duration_cast<microseconds>(end - start).count();
}

int main() {
    // Các giá trị của n cần kiểm tra
    vector<long long> n_values = {1000, 5000, 10000, 50000, 100000};

    // In tiêu đề bảng
    cout << left << setw(15) << "n" 
         << setw(20) << "O(log n) [us]" 
         << setw(20) << "O(n) [us]" 
         << setw(20) << "O(n^2) [us]" << "\n";
    cout << string(70, '-') << "\n";

    // Đo và in kết quả
    for (long long n : n_values) {
        double time_logn = measure_time(test_O_logn, n);
        double time_n = measure_time(test_O_n, n);
        double time_n2 = measure_time(test_O_n2, n);

        cout << left << setw(15) << n 
             << setw(20) << time_logn 
             << setw(20) << time_n 
             << setw(20) << time_n2 << "\n";
    }

    return 0;
}
### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.
#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_set>
#include <algorithm>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// ================= BÀI 1: TWO SUM =================
bool twoSum_On2(const vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] + arr[j] == target) return true;
        }
    }
    return false;
}

bool twoSum_On(const vector<int>& arr, int target) {
    unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(target - num)) return true;
        seen.insert(num);
    }
    return false;
}

// ================= BÀI 2: MAXIMUM SUBARRAY =================
long long maxSubArray_On2(const vector<int>& arr) {
    int n = arr.size();
    long long maxSum = arr[0];
    for (int i = 0; i < n; ++i) {
        long long currentSum = 0;
        for (int j = i; j < n; ++j) {
            currentSum += arr[j];
            if (currentSum > maxSum) maxSum = currentSum;
        }
    }
    return maxSum;
}

long long maxSubArray_On(const vector<int>& arr) {
    long long maxSum = arr[0];
    long long currentSum = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        currentSum = max((long long)arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

// ================= BÀI 3: CONTAINS DUPLICATE =================
bool containsDuplicate_On2(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) return true;
        }
    }
    return false;
}

bool containsDuplicate_Onlogn(vector<int> arr) { // Pass by value để copy mảng
    sort(arr.begin(), arr.end());
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] == arr[i - 1]) return true;
    }
    return false;
}

// ================= HÀM ĐO THỜI GIAN =================
template <typename Func, typename... Args>
double measure_time(Func func, Args&&... args) {
    auto start = high_resolution_clock::now();
    volatile auto result = func(std::forward<Args>(args)...); // volatile để tránh optimize bỏ hàm
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count() / 1000.0; // Trả về milliseconds (ms)
}

int main() {
    int N = 50000; // Số lượng phần tử
    cout << "Do luong voi N = " << N << " phan tu (Worst-case)\n";
    cout << string(60, '-') << "\n";

    // Sinh dữ liệu worst-case (không có đáp án để ép vòng lặp chạy đến cùng)
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) arr[i] = i; 

    // Đo Bài 1
    cout << "[1] Two Sum (Target = -1)\n";
    cout << " - O(n^2)    : " << measure_time(twoSum_On2, arr, -1) << " ms\n";
    cout << " - O(n)      : " << measure_time(twoSum_On, arr, -1) << " ms\n\n";

    // Sinh dữ liệu mảng toàn số âm cho Bài 2
    vector<int> arr_negative(N);
    for (int i = 0; i < N; ++i) arr_negative[i] = -1;

    // Đo Bài 2
    cout << "[2] Maximum Subarray (Mang toan so am)\n";
    cout << " - O(n^2)    : " << measure_time(maxSubArray_On2, arr_negative) << " ms\n";
    cout << " - O(n)      : " << measure_time(maxSubArray_On, arr_negative) << " ms\n\n";

    // Đo Bài 3
    cout << "[3] Contains Duplicate (Mang khong trung lap)\n";
    cout << " - O(n^2)    : " << measure_time(containsDuplicate_On2, arr) << " ms\n";
    cout << " - O(n log n): " << measure_time(containsDuplicate_Onlogn, arr) << " ms\n";

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
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

// --- CÁC HÀM MÔ PHỎNG ĐỘ PHỨC TẠP ---

// O(1) - Thời gian hằng số
void test_O1(long long n) {
    volatile int a = 5;
    volatile int b = 10;
    volatile int c = a + b;
}

// O(log n) - Thời gian logarit
void test_O_logn(long long n) {
    volatile long long sum = 0;
    for (long long i = 1; i < n; i *= 2) {
        sum += i;
    }
}

// O(n) - Thời gian tuyến tính
void test_O_n(long long n) {
    volatile long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        sum += i;
    }
}

// O(n²) - Thời gian bậc hai
void test_O_n2(long long n) {
    volatile long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            sum += j;
        }
    }
}

// --- HÀM ĐO THỜI GIAN CHÍNH XÁC ---
double measure_time_ms(void (*func)(long long), long long n) {
    // Đo nhiều lần lấy trung bình đối với các hàm quá nhanh như O(1), O(log n)
    int repetitions = (n <= 10000) ? 100 : 1;
    
    auto start = high_resolution_clock::now();
    for (int r = 0; r < repetitions; ++r) {
        func(n);
    }
    auto end = high_resolution_clock::now();
    
    double duration = duration_cast<nanoseconds>(end - start).count();
    return (duration / repetitions) / 1000000.0; // Đổi từ nanoseconds sang milliseconds
}

// Hàm định dạng số double thành chuỗi kèm đơn vị "ms"
string format_time(double ms) {
    stringstream ss;
    if (ms < 0.001) {
        ss << fixed << setprecision(4) << ms << "ms";
    } else if (ms < 1.0) {
        ss << fixed << setprecision(3) << ms << "ms";
    } else {
        ss << fixed << setprecision(2) << ms << "ms";
    }
    return ss.str();
}

int main() {
    vector<long long> n_values = {1000, 10000, 100000};
    
    // Tạo luồng lưu trữ chuỗi để xuất ra cả console và file
    stringstream table;
    
    table << "╔══════════════╦══════════════╦══════════════╦══════════════╗\n";
    table << "║   Thuật toán ║    n=1000    ║   n=10000    ║   n=100000   ║\n";
    table << "╠══════════════╬══════════════╬══════════════╬══════════════╣\n";

    // Danh sách các độ phức tạp cần đo
    vector<pair<string, void(*)(long long)>> algorithms = {
        {"O(1)", test_O1},
        {"O(log n)", test_O_logn},
        {"O(n)", test_O_n},
        {"O(n²)", test_O_n2}
    };

    cout << "Đang chạy benchmark (Vui lòng đợi, O(n²) với n=100000 sẽ mất vài giây)..." << endl;

    for (const auto& alg : algorithms) {
        table << "║  " << left << setw(12) << alg.first;
        
        for (long long n : n_values) {
            // Đối với O(n^2) ở n=100000, nếu chạy quá lâu có thể giả lập hoặc chạy thật tùy cấu hình máy.
            // Ở đây chương trình sẽ chạy thật để đo chính xác.
            double t = measure_time_ms(alg.second, n);
            table << "║  " << left << setw(12) << format_time(t);
        }
        table << "║\n";
    }
    
    table << "╚══════════════╩══════════════╩══════════════╩══════════════╝\n";

    // 1. In ra màn hình Console
    cout << "\nKẾT QUẢ BENCHMARK:\n";
    cout << table.str();

    // 2. Ghi vào file benchmark.txt
    ofstream outFile("benchmark.txt");
    if (outFile.is_open()) {
        outFile << table.str();
        outFile.close();
        cout << "\n[Thành công] Đã xuất kết quả ra file 'benchmark.txt'!" << endl;
    } else {
        cerr << "\n[Lỗi] Không thể tạo hoặc ghi file 'benchmark.txt'!" << endl;
    }

    return 0;
}
---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
