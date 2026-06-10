# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.

int getFirst(int arr[], int n) {
    return arr[0];
}
# O(1), truy cập trực tiếp phần tử mà không phụ thuộc vào n

int tinhTong(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
# O(n), chạy vòng lặp n lần, tỉ lệ thuận với n

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}
# O(n^2), 2 vòng lặp lồng nhau, 1 vòng = nxn

int binarySearch(int arr[], int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
# O(logn), mỗi bước chia 1/2 bảng và sau log2(n) bước thì tìm xong

void nhanMaTran(int A[][N], int B[][N], int C[][N], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
}
# O(n^3), 3 vòng lặp lồng nhau, 1 vòng = nxnxn

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
# O(2^n), 1 lần tạo = 2 lần gọi

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
# O(sqrt(n)), kiểm tra đến sqrt(n) thay vì n, tiết kiệm nửa thời gian

void inHai(int a[], int n, int b[], int m) {
    for (int i = 0; i < n; i++) cout << a[i];
    for (int i = 0; i < m; i++) cout << b[i];
}
# O(n+m), 2 vòng lặp độc lập cộng lại với nhau

void hoanVi(string s, int l, int r) {
    if (l == r) { cout << s << "\n"; return; }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        hoanVi(s, l + 1, r);
        swap(s[l], s[i]);
    }
}
# O(n!), tạo hoán vị n chuỗi ký tự
### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace chrono;
 
double measure(function<void()> fn) {
    auto s = high_resolution_clock::now();
    fn();
    return duration<double, milli>(high_resolution_clock::now() - s).count();
}
 
int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};
 
    printf("%-10s %-15s %-15s %-15s\n", "n", "O(logn) ms", "O(n) ms", "O(n^2) ms");
    printf("%s\n", string(55, '-').c_str());
 
    for (int n : sizes) {
        vector<int> a(n); iota(a.begin(), a.end(), 0);
 
        // O(log n)
        int lo, hi, mid;
        double t1 = measure([&]() {
            for (int r = 0; r < 10000; r++) {
                lo = 0; hi = n - 1;
                while (lo <= hi) { mid = (lo+hi)/2; if (a[mid]==n/2) break; else if (a[mid]<n/2) lo=mid+1; else hi=mid-1; }
            }
        }) / 10000.0;
 
        // O(n)
        double t2 = measure([&]() { long long s=0; for (int x:a) s+=x; });
 
        // O(n^2)
        if (n <= 10000) {
            double t3 = measure([&]() { vector<int> b=a; for(int i=0;i<n;i++) for(int j=0;j<n-i-1;j++) if(b[j]>b[j+1]) swap(b[j],b[j+1]); });
            printf("%-10d %-15.6f %-15.6f %-15.6f\n", n, t1, t2, t3);
        } else {
            printf("%-10d %-15.6f %-15.6f %-15s\n", n, t1, t2, "too slow");
        }
    }
    return 0;
}
### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.

#include <iostream>
#include <chrono>
#include <iomanip>
#include <functional>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;
using namespace chrono;
 
double measure(function<void()> fn) {
    auto start = high_resolution_clock::now();
    fn();
    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}
 
// ===================== BAI 1: TIM CAP SO CO TONG = TARGET =====================
// O(n²)
pair<int,int> timCap_slow(vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] + arr[j] == target)
                return {arr[i], arr[j]};
    return {-1, -1};
}
// O(n) - dung hash map
pair<int,int> timCap_fast(vector<int>& arr, int target) {
    unordered_map<int,int> seen;
    for (int x : arr) {
        int need = target - x;
        if (seen.count(need)) return {need, x};
        seen[x] = 1;
    }
    return {-1, -1};
}
 
// ===================== BAI 2: KIEM TRA PHAN TU TRUNG =====================
// O(n²)
bool coTrung_slow(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] == arr[j]) return true;
    return false;
}
// O(n log n) - sort truoc roi check canh nhau
bool coTrung_fast(vector<int> arr) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < (int)arr.size()-1; i++)
        if (arr[i] == arr[i+1]) return true;
    return false;
}
 
// ===================== BAI 3: TIM DAY CON CO TONG LON NHAT =====================
// O(n²)
int maxSubarray_slow(vector<int>& arr) {
    int n = arr.size(), best = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            best = max(best, sum);
        }
    }
    return best;
}
// O(n) - Kadane's algorithm
int maxSubarray_fast(vector<int>& arr) {
    int best = INT_MIN;
    int cur = 0;
    for (int x : arr) {
        cur = max(x, cur + x);
        best = max(best, cur);
    }
    return best;
}
 
void printRow(string label, int n, double slow_ms, double fast_ms) {
    cout << "| " << left << setw(12) << label
         << "| " << setw(9) << n
         << "| " << setw(14) << fixed << setprecision(4) << slow_ms
         << "| " << setw(14) << fast_ms
         << "| " << setw(7) << fixed << setprecision(1) << (slow_ms / max(fast_ms, 0.0001))
         << "x |\n";
}
 
void printHeader(string col3) {
    cout << "+" << string(14,'-') << "+" << string(11,'-') << "+" << string(16,'-') << "+" << string(16,'-') << "+" << string(10,'-') << "+\n";
    cout << "| " << left << setw(13) << "Bai"
         << "| " << setw(10) << "n"
         << "| " << setw(15) << "O(n^2) ms"
         << "| " << setw(15) << col3
         << "| " << setw(9)  << "Nhanh hon" << "|\n";
    cout << "+" << string(14,'-') << "+" << string(11,'-') << "+" << string(16,'-') << "+" << string(16,'-') << "+" << string(10,'-') << "+\n";
}
 
void printSep() {
    cout << "+" << string(14,'-') << "+" << string(11,'-') << "+" << string(16,'-') << "+" << string(16,'-') << "+" << string(10,'-') << "+\n";
}
 
int main() {
    vector<int> sizes = {1000, 5000, 10000, 30000};
 
    // ---- BAI 1 ----
    cout << "\n=== BAI 1: Tim cap so co tong = target ===\n";
    cout << "  O(n^2): 2 vong lap long nhau\n";
    cout << "  O(n)  : Hash map - tra cuu O(1) moi phan tu\n\n";
    printHeader("O(n) ms");
    for (int n : sizes) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = i;
        int target = n + n/2;
        double s = measure([&](){ timCap_slow(arr, target); });
        double f = measure([&](){ timCap_fast(arr, target); });
        printRow("Tim cap", n, s, f);
    }
    printSep();
 
    // ---- BAI 2 ----
    cout << "\n=== BAI 2: Kiem tra phan tu trung ===\n";
    cout << "  O(n^2)  : 2 vong lap long nhau\n";
    cout << "  O(nlogn): Sort + check ke nhau\n\n";
    printHeader("O(nlogn) ms");
    for (int n : sizes) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = i;
        double s = measure([&](){ coTrung_slow(arr); });
        double f = measure([&](){ coTrung_fast(arr); });
        printRow("Co trung", n, s, f);
    }
    printSep();
 
    // ---- BAI 3 ----
    cout << "\n=== BAI 3: Day con co tong lon nhat (Kadane) ===\n";
    cout << "  O(n^2): Kiem tra moi cap (i,j)\n";
    cout << "  O(n)  : Kadane's algorithm\n\n";
    printHeader("O(n) ms");
    for (int n : sizes) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = (i%2==0) ? i : -i;
        double s = measure([&](){ maxSubarray_slow(arr); });
        double f = measure([&](){ maxSubarray_fast(arr); });
        printRow("Kadane", n, s, f);
    }
    printSep();
 
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
#include <chrono>
#include <fstream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
using namespace chrono;
 
// ============================================================
// DO THOI GIAN
// ============================================================
double measure(function<void()> fn) {
    auto s = high_resolution_clock::now();
    fn();
    return duration<double, milli>(high_resolution_clock::now() - s).count();
}
 
// ============================================================
// CAC THUAT TOAN
// ============================================================
 
// O(1) - truy cap phan tu dau tien
double run_O1(int n) {
    vector<int> arr(n, 42);
    return measure([&]() {
        volatile int x = arr[0];
        (void)x;
    });
}
 
// O(log n) - binary search
double run_Ologn(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i;
    return measure([&]() {
        for (int r = 0; r < 10000; r++) {
            int lo = 0, hi = n - 1, mid;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if      (arr[mid] == n/2) break;
                else if (arr[mid] <  n/2) lo = mid + 1;
                else                      hi = mid - 1;
            }
        }
    }) / 10000.0;
}
 
// O(n) - tinh tong
double run_On(int n) {
    vector<int> arr(n, 1);
    return measure([&]() {
        long long s = 0;
        for (int x : arr) s += x;
    });
}
 
// O(n^2) - bubble sort (chi chay voi n <= 10000)
double run_On2(int n) {
    if (n > 10000) return -1;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = n - i;
    return measure([&]() {
        vector<int> b = arr;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n-i-1; j++)
                if (b[j] > b[j+1]) swap(b[j], b[j+1]);
    });
}
 
// ============================================================
// DINH DANG THOI GIAN
// ============================================================
string fmtTime(double ms) {
    if (ms < 0) return "too slow";
    ostringstream oss;
    if (ms < 0.001)
        oss << fixed << setprecision(4) << ms << "ms";
    else
        oss << fixed << setprecision(3) << ms << "ms";
    return oss.str();
}
 
// ============================================================
// IN BANG
// ============================================================
void printTable(ostream& out, vector<int>& sizes, vector<vector<string>>& rows) {
    vector<int> widths = {12};
    for (int i = 0; i < (int)sizes.size(); i++)
        widths.push_back(12);
 
    auto sep = [&](ostream& o) {
        o << "+";
        for (int w : widths) o << string(w, '-') << "+";
        o << "\n";
    };
 
    sep(out);
    out << "| " << left << setw(widths[0]-2) << "Thuat toan" << " |";
    for (int i = 0; i < (int)sizes.size(); i++)
        out << " " << left << setw(widths[i+1]-2) << ("n="+to_string(sizes[i])) << " |";
    out << "\n";
    sep(out);
 
    for (auto& row : rows) {
        out << "| " << left << setw(widths[0]-2) << row[0] << " |";
        for (int i = 1; i < (int)row.size(); i++)
            out << " " << left << setw(widths[i]-2) << row[i] << " |";
        out << "\n";
    }
    sep(out);
}
 
// ============================================================
// MAIN
// ============================================================
int main() {
    vector<int> sizes = {1000, 10000, 100000};
    vector<string> labels = {"O(1)", "O(log n)", "O(n)", "O(n^2)"};
 
    cout << "\n  Do thoi gian chay cac thuat toan...\n\n";
 
    // thu thap ket qua
    vector<vector<string>> rows;
    for (int algo = 0; algo < 4; algo++) {
        vector<string> row;
        row.push_back(labels[algo]);
        for (int n : sizes) {
            double t;
            if      (algo == 0) t = run_O1(n);
            else if (algo == 1) t = run_Ologn(n);
            else if (algo == 2) t = run_On(n);
            else                t = run_On2(n);
            row.push_back(fmtTime(t));
        }
        rows.push_back(row);
    }
 
    // in ra man hinh
    printTable(cout, sizes, rows);
 
    // xuat ra file benchmark.txt
    ofstream fout("benchmark.txt");
    fout << "Big-O Benchmark Tool\n";
    fout << "====================\n\n";
    printTable(fout, sizes, rows);
    fout << "\nGhi chu:\n";
    fout << "  O(1)     : Truy cap phan tu dau tien\n";
    fout << "  O(log n) : Binary Search\n";
    fout << "  O(n)     : Tinh tong mang\n";
    fout << "  O(n^2)   : Bubble Sort (n>10000: too slow)\n";
    fout.close();
 
    cout << "\n  Ket qua da xuat ra file: benchmark.txt\n\n";
    return 0;
}

---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
