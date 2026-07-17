# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---

### Bài 1: Phân tích Big-O ⭐
1.Truy cập phần tử đầu
int getFirst(int arr[], int n) {
  return arr[0];
}
giải thích:Không có vòng lặp. Chỉ truy cập một phần tử cố định — luôn tốn đúng 1 bước dù n lớn đến đâu. → O(1)
2.Binary search
int binarySearch(int arr[], int n, int x) {
  int lo = 0, hi = n - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (arr[mid] == x) return mid;
    else if (arr[mid] < x) lo = mid + 1;
    else hi = mid - 1;
  }
  return -1;
}
giải thích:Mỗi lần lặp, khoảng tìm kiếm giảm một nửa. Với n phần tử, cần tối đa log₂(n) bước. → O(log n)
3.Tính tổng mảng
int sumArray(int arr[], int n) {
  int total = 0;
  for (int i = 0; i < n; i++)
    total += arr[i];
  return total;
}
giải thích:Một vòng lặp duyệt qua đúng n phần tử, mỗi bước làm một phép cộng O(1). Tổng = n bước. → O(n)
4.
void printReverse(int arr[], int n) {
  for (int i = n - 1; i >= 0; i--)
    cout << arr[i] << " ";
}
giải thích;Vòng lặp chạy đúng n lần (từ n-1 về 0), mỗi lần in một phần tử. → O(n)
5.
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 1; j++)
      if (arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
}
giải thích:Hai vòng lặp lồng nhau, mỗi cái chạy ~n lần. Tổng phép so sánh ≈ n × n = n². → O(n²)
6.Tìm phần tử trùng
bool hasDuplicate(int arr[], int n) {
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (arr[i] == arr[j]) return true;
  return false;
}
giải thích:So sánh mọi cặp (i, j). Số cặp = n(n−1)/2, bỏ hệ số → O(n²)
7.Merge sort
void mergeSort(int arr[], int l, int r) {
  if (l >= r) return;
  int m = (l + r) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m+1, r);
  merge(arr, l, m, r);
}
giải thích:Chia đôi mảng log₂(n) lần (chiều sâu đệ quy). Mỗi tầng merge tốn O(n) tổng. → O(n log n)
8.Nhân ma trận
void matMul(int A[][N], int B[][N], int C[][N], int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        C[i][j] += A[i][k] * B[k][j];
}
giải thích;Ba vòng lặp lồng nhau, mỗi cái chạy n lần. Tổng phép nhân = n³. → O(n³)
9.Sàng Eratosthenes
void sieve(bool p[], int n) {
  fill(p, p+n+1, true);
  for (int i = 2; i*i <= n; i++)
    if (p[i])
      for (int j = i*i; j <= n; j += i)
        p[j] = false;
}
10.Fibonacci đệ quy
int fib(int n) {
  if (n <= 1) return n;
  return fib(n-1) + fib(n-2);
}
giải thích:Sàng Eratosthenes: tổng thao tác ≈ n/2 + n/3 + n/5 + ... (chuỗi điều hòa theo số nguyên tố) = O(n log log n)
### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.
#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <cmath>

using namespace std;
using namespace std::chrono;

// ── O(log n): binary search ───────────────────────────────
int binarySearch(const vector<int>& arr, int target) {
    int lo = 0, hi = (int)arr.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// ── O(n): tính tổng mảng ─────────────────────────────────
long long sumArray(const vector<int>& arr) {
    long long total = 0;
    for (int x : arr) total += x;
    return total;
}

// ── O(n²): bubble sort (trên bản sao) ────────────────────
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

// ── Đo thời gian, chạy `reps` lần lấy trung bình ─────────
template<typename Func>
double measure_ms(Func f, int reps = 3) {
    f(); // warm-up
    double total = 0;
    for (int i = 0; i < reps; i++) {
        auto t0 = high_resolution_clock::now();
        f();
        auto t1 = high_resolution_clock::now();
        total += duration_cast<microseconds>(t1 - t0).count() / 1000.0;
    }
    return total / reps;
}

string fmt(double ms) {
    if (ms < 0.01) return "< 0.01 ms";
    ostringstream o;
    o << fixed << setprecision(2) << ms << " ms";
    return o.str();
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    cout << "\n";
    cout << string(62, '=') << "\n";
    cout << "  Benchmark: O(log n) vs O(n) vs O(n²)\n";
    cout << string(62, '=') << "\n\n";
    cout << left
         << setw(12) << "n"
         << setw(16) << "O(log n)"
         << setw(16) << "O(n)"
         << setw(16) << "O(n²)"
         << "\n";
    cout << string(58, '-') << "\n";

    for (int n : sizes) {
        // mảng đã sắp xếp cho binary search
        vector<int> sorted(n);
        iota(sorted.begin(), sorted.end(), 0);

        // mảng ngẫu nhiên cho sum & bubble sort
        vector<int> rnd(n);
        for (int i = 0; i < n; i++) rnd[i] = rand() % 100000;

        int target = sorted[n / 2];

        double t_logn = measure_ms([&]{ binarySearch(sorted, target); }, 1000);
        double t_n    = measure_ms([&]{ sumArray(rnd); }, 20);
        double t_n2   = (n <= 10000)
                        ? measure_ms([&]{ bubbleSort(rnd); }, 3)
                        : -1;

        cout << left
             << setw(12) << n
             << setw(16) << fmt(t_logn)
             << setw(16) << fmt(t_n)
             << setw(16) << (t_n2 < 0 ? "(quá chậm)" : fmt(t_n2))
             << "\n";
    }

    cout << string(58, '-') << "\n\n";
    cout << "Hàm đo:\n";
    cout << "  O(log n)  binary search trên mảng đã sắp xếp\n";
    cout << "  O(n)      tính tổng toàn bộ mảng\n";
    cout << "  O(n²)     bubble sort (bỏ qua khi n > 10.000)\n\n";

    return 0;
}
Cách chạy:g++ -O0 -std=c++17 -o benchmark benchmark.cpp && ./benchmark
### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.
Hàm 1 — Tìm cặp số có tổng = k
pair<int,int> twoSum(const vector<int>& a, int k) {
    int n = a.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] + a[j] == k)
                return {a[i], a[j]};
    return {-1, -1};
}
Hàm 2 — Mảng con có tổng lớn nhất
long long maxSubarray(const vector<int>& a) {
    int n = a.size();
    long long best = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            best = max(best, sum);
        }
    }
    return best;
}
Hàm 3 — Đếm số cặp nghịch thế
long long countInversions(const vector<int>& a) {
    int n = a.size();
    long long cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) cnt++;
    return cnt;
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
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <string>

// --- CÁC HÀM MÔ PHỎNG THUẬT TOÁN ---

// O(1) - Thời gian hằng số
volatile int dummy_val = 0;
void algorithm_O1(long long n) {
    dummy_val = 42;
}

// O(log n) - Thời gian lôgarit
void algorithm_O_log_n(long long n) {
    long long count = 0;
    while (n > 0) {
        count++;
        n /= 2;
    }
    dummy_val = count;
}

// O(n) - Thời gian tuyến tính
void algorithm_On(long long n) {
    long long count = 0;
    for (long long i = 0; i < n; ++i) {
        count++;
    }
    dummy_val = count;
}

// O(n^2) - Thời gian bậc hai
void algorithm_On2(long long n) {
    long long count = 0;
    // Giới hạn n cho O(n^2) để tránh treo chương trình quá lâu ở n = 100,000
    // (100,000^2 = 10 tỷ phép tính, mất khoảng vài giây tới vài chục giây)
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            count++;
        }
    }
    dummy_val = count;
}

// --- HÀM TRỢ GIÚP ĐO THỜI GIAN VÀ ĐỊNH DẠNG ---

// Đo thời gian chạy của hàm và trả về chuỗi định dạng (ms)
std::string measure_time(void (*func)(long long), long long n) {
    auto start = std::chrono::high_resolution_clock::now();
    func(n);
    auto end = std::chrono::high_resolution_clock::now();
   
    std::chrono::duration<double, std::milli> duration = end - start;
   
    // Định dạng chuỗi hiển thị số thập phân gọn gàng
    std::stringstream ss;
    ss << std::fixed << std::setprecision(4) << duration.count() << "ms";
    return ss.str();
}

// In dòng kẻ ngang của bảng
void print_divider(std::ostream& os) {
    os << "=========================================================\n";
}

int main() {
    std::vector<long long> sizes = {1000, 10000, 100000};
   
    // Tạo cấu trúc lưu trữ kết quả để in ra 2 nơi (Console & File)
    std::stringstream buffer;
   
    print_divider(buffer);
    buffer << "| " << std::left << std::setw(12) << "Thuat toan"
           << " | " << std::setw(11) << "n=1000"
           << " | " << std::setw(11) << "n=10000"
           << " | " << std::setw(11) << "n=100000" << " |\n";
    print_divider(buffer);

    // Đo O(1)
    buffer << "| " << std::left << std::setw(12) << "O(1)"
           << " | " << std::setw(11) << measure_time(algorithm_O1, 1000)
           << " | " << std::setw(11) << measure_time(algorithm_O1, 10000)
           << " | " << std::setw(11) << measure_time(algorithm_O1, 100000) << " |\n";

    // Đo O(log n)
    buffer << "| " << std::left << std::setw(12) << "O(log n)"
           << " | " << std::setw(11) << measure_time(algorithm_O_log_n, 1000)
           << " | " << std::setw(11) << measure_time(algorithm_O_log_n, 10000)
           << " | " << std::setw(11) << measure_time(algorithm_O_log_n, 100000) << " |\n";

    // Đo O(n)
    buffer << "| " << std::left << std::setw(12) << "O(n)"
           << " | " << std::setw(11) << measure_time(algorithm_On, 1000)
           << " | " << std::setw(11) << measure_time(algorithm_On, 10000)
           << " | " << std::setw(11) << measure_time(algorithm_On, 100000) << " |\n";

    // Đo O(n^2)
    std::cout << "Dang chay luong tinh toan Benchmark (Vui long cho trong giay lat)..." << std::endl;
    buffer << "| " << std::left << std::setw(12) << "O(n^2)"
           << " | " << std::setw(11) << measure_time(algorithm_On2, 1000)
           << " | " << std::setw(11) << measure_time(algorithm_On2, 10000)
           << " | " << std::setw(11) << measure_time(algorithm_On2, 100000) << " |\n";

    print_divider(buffer);
    std::cout << "\n" << buffer.str();
    return 0;
}

