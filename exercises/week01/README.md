Lê Minh Đạt - 2125110157
# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.
╔═════╦════════════════════════════╦════════════╦═══════════════════════════════════════════════╗
║ STT ║        Mẫu Code C++        ║   Big-O    ║                  Giải thích                   ║
╠═════╬════════════════════════════╬════════════╬═══════════════════════════════════════════════╣
║  1  ║ int x = arr[0];            ║ O(1)       ║ Truy xuất mảng qua index diễn ra tức thì.     ║
║  2  ║ for(int i=0; i<n; i++)     ║ O(n)       ║ Lặp đúng n lần, tuyến tính với n.             ║
║  3  ║ for(..n){} for(..n){}      ║ O(n)       ║ 2 vòng lặp rời nhau: 2n bước -> O(n).         ║
║  4  ║ for(..n){ for(..n){} }     ║ O(n^2)     ║ 2 vòng lặp lồng nhau: n * n = n^2.            ║
║  5  ║ for(i=0..n){ for(j=i..n) } ║ O(n^2)     ║ Lặp tam giác: n(n-1)/2 bước -> O(n^2).        ║
║  6  ║ for(int i=n; i>0; i/=2)    ║ O(log n)   ║ Biến i bị chia đôi sau mỗi lần lặp.           ║
║  7  ║ for(..n){ for(j=1; j*=2) } ║ O(n log n) ║ Vòng ngoài n lần, vòng trong log(n) lần.      ║
║  8  ║ for(..n){ for(..m){} }     ║ O(n * m)   ║ Lặp lồng nhau với 2 đầu vào độc lập n và m.   ║
║  9  ║ f(n-1) + f(n-2)            ║ O(2^n)     ║ Đệ quy rẽ 2 nhánh, cây tăng theo lũy thừa 2.  ║
║ 10  ║ for(i=2; i*i<=n; i++)      ║ O(sqrt(n)) ║ Lặp đến khi i^2 <= n, tức là căn bậc hai n.   ║
╚═════╩════════════════════════════╩════════════╩═══════════════════════════════════════════════╝
### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.
#include <iostream>
#include <chrono> // Bắt buộc phải có thư viện này

using namespace std;
using namespace std::chrono; // Tiết kiệm công gõ std::chrono::

void algo_O_n2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            volatile int x = i + j; 
        }
    }
}

int main() {
    int n = 10000;
    cout << "Đang đo thời gian với n = " << n << "...\n";

    // BƯỚC 1: Bấm đồng hồ (Lấy thời gian hiện tại)
    auto start = high_resolution_clock::now();

    // BƯỚC 2: Chạy thuật toán
    algo_O_n2(n);

    // BƯỚC 3: Dừng đồng hồ và tính toán
    auto stop = high_resolution_clock::now();
    
    // Ép kiểu khoảng thời gian chênh lệch ra Micro giây (1 giây = 1.000.000 micro giây)
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Thời gian chạy: " << duration.count() / 1000.0 << " mili-giây (ms)\n";

    return 0;
}
### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.
Cách 1: Brute Force ($O(n^2)$)
Dùng 2 vòng lặp lồng nhau duyệt mọi cặp số. Chạy với $n = 100,000$ sẽ tốn vài giây đến vài chục giây.
bool hasPairSum(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] + arr[j] == target) return true;
        }
    }
    return false;
}
Cách 2: Tối ưu bằng Hash Map (O(n))
bool hasPairSumOptimized(const vector<int>& arr, int target) {
    unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(target - num)) return true;
        seen.insert(num);
    }
    return false;
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
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

// --- CÁC HÀM MÔ PHỎNG ĐỘ PHỨC TẠP ---

void algo_O1(int n) {
    volatile int x = n; // volatile ngăn compiler tối ưu hóa (optimize out)
}

void algo_O_log_n(int n) {
    for (int i = 1; i < n; i *= 2) {
        volatile int x = i;
    }
}

void algo_O_n(int n) {
    for (int i = 0; i < n; i++) {
        volatile int x = i;
    }
}

void algo_O_n2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            volatile int x = i + j;
        }
    }
}

// --- HÀM ĐO THỜI GIAN ---
// Trả về thời gian chạy tính bằng milliseconds
double measureTime(void (*func)(int), int n) {
    auto start = high_resolution_clock::now();
    func(n);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000.0; // Đổi micro giây sang mili giây
}

int main() {
    vector<int> test_cases = {1000, 10000, 100000};
    
    // Mở file để xuất kết quả
    ofstream outFile("benchmark.txt");

    // Helper macro để in ra cả Console lẫn File
    #define PRINT(stream) \
        stream << "╔════════════════╦══════════════╦══════════════╦══════════════╗\n" \
               << "║   Thuật toán   ║    n=1000    ║   n=10000    ║   n=100000   ║\n" \
               << "╠════════════════╬══════════════╬══════════════╬══════════════╣\n"
               
    PRINT(cout);
    PRINT(outFile);

    struct Algorithm {
        string name;
        void (*func)(int);
    };

    vector<Algorithm> algos = {
        {"O(1)", algo_O1},
        {"O(log n)", algo_O_log_n},
        {"O(n)", algo_O_n},
        {"O(n^2)", algo_O_n2}
    };

    for (const auto& algo : algos) {
        // Căn lề tên thuật toán
        cout << "║ " << setw(14) << left << algo.name;
        outFile << "║ " << setw(14) << left << algo.name;

        for (int n : test_cases) {
            double time_ms = measureTime(algo.func, n);
            
            // Format số để in ra dạng 0.xxx ms
            string result = to_string(time_ms);
            result.erase(result.find_last_not_of('0') + 1, std::string::npos); 
            if (result.back() == '.') result += "0";
            result += "ms";

            cout << " ║ " << setw(12) << left << result;
            outFile << " ║ " << setw(12) << left << result;
        }
        cout << " ║\n";
        outFile << " ║\n";
    }

    #define PRINT_FOOTER(stream) \
        stream << "╚════════════════╩══════════════╩══════════════╩══════════════╝\n"

    PRINT_FOOTER(cout);
    PRINT_FOOTER(outFile);

    outFile.close();
    cout << "\n[!] Đã xuất kết quả ra file benchmark.txt\n";

    return 0;
}
---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
