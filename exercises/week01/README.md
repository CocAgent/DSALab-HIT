### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.

//1. Vòng lặp đơn
   for (int i = 0; i < n; i++) {
    cout << i << endl;
}
//giai thich:O(n) — Vòng lặp chạy đúng n lần, mỗi lần thực hiện O(1) công việc. Tổng: n × O(1) = O(n).
//2.Vòng lặp lồng nhau
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        sum += i * j;
    }
}
//giai thich:O(n²) — Hai vòng lặp lồng nhau, mỗi vòng chạy n lần. Tổng số bước: n × n = n².
//3.Tìm kiếm nhị phân
int lo = 0, hi = n - 1;
while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) lo = mid + 1;
    else hi = mid - 1;
}
//giai thich:O(log n) — Mỗi vòng lặp chia đôi không gian tìm kiếm. Sau k bước, còn n/2ᵏ phần tử → tối đa log₂n bước.
//4. Ba vòng lặp lồng nhau
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            result += arr[i][j][k];
//giai thich: O(n³) — Ba vòng lặp lồng nhau, mỗi vòng n lần. Tổng: n × n × n = n³ phép tính.
//5. Bước nhảy gấp đôi
for (int i = 1; i < n; i *= 2) {
    cout << i << endl;
}
//giai thich: O(log n) — Biến i tăng gấp đôi sau mỗi bước (1, 2, 4, 8, ...). Số bước = log₂n vì 2ᵏ ≥ n khi k = log₂n.
//6. Vòng ngoài n, vòng trong log n
for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j *= 2) {
        cout << i + j;
    }
}
//giai thich: O(n log n) — Vòng ngoài chạy n lần, vòng trong chạy log n lần (j tăng gấp đôi). Tổng: n × log n.
//7. Thao tác hằng số
int a = arr[0];
int b = arr[n/2];
int c = arr[n-1];
cout << a + b + c;
//giai thich: O(1) — Chỉ có 3 phép truy cập mảng và 1 phép cộng, không phụ thuộc vào n. Luôn là hằng số.
//8. Đệ quy Fibonacci ngây thơ
   int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
//giai thich: O(2ⁿ) — Mỗi lời gọi sinh ra 2 lời gọi đệ quy, tạo thành cây nhị phân sâu n tầng. Số nút ≈ 2ⁿ.
//9. Vòng lặp j phụ thuộc i
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        cout << i + j;
    }
}
//giai thich: O(n²) — Vòng trong chạy 0+1+2+...+(n−1) = n(n−1)/2 lần. Bỏ hằng số và hệ số → O(n²).
//10. Merge Sort đệ quy
    void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r); // O(n)
}
//giai thich: O(n log n) — Mỗi tầng đệ quy chia đôi mảng (log n tầng), mỗi tầng merge tổng n phần tử. T(n) = 2T(n/2) + O(n) → O(n log n) theo Master Theorem.
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
//cachchay: g++ -O0 -std=c++17 -o benchmark benchmark.cpp && ./benchmark

//bangketqua
+----------+----------------+--------------+--------------+
|        n |  O(log n) (ns) |   O(n) (us)  |  O(n^2) (ms) |
+----------+----------------+--------------+--------------+
|     1000 |           12.6 |         0.61 |         0.63 |
|     5000 |           17.9 |         2.92 |        15.30 |
|    10000 |           20.1 |         5.58 |        61.60 |
|    25000 |           23.6 |        11.77 |       385.08 |
|    50000 |           24.5 |        21.49 |      1546.48 |
|    75000 |           25.3 |        31.25 |      3467.40 |
|   100000 |           25.3 |        41.07 |      6158.03 |
+----------+----------------+--------------+--------------+
### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.

//Hàm 1: Tìm cặp số có tổng bằng K (Two Sum)


pythonimport time
import random

def two_sum_slow(arr, target):
    n = len(arr)
    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] + arr[j] == target:
                return (arr[i], arr[j])
    return None

def two_sum_fast(arr, target):
    seen = set()
    for num in arr:
        complement = target - num
        if complement in seen:
            return (complement, num)
        seen.add(num)
    return None

//Hàm 2: Tìm phần tử trùng lặp đầu tiên (First Duplicate)

def find_duplicate_slow(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, i):
            if arr[i] == arr[j]:
                return arr[i]
    return None

def find_duplicate_fast(arr):
    seen = set()
    for num in arr:
        if num in seen:
            return num
        seen.add(num)
    return None
//Hàm 3: Tìm cặp số có khoảng cách nhỏ nhất (Closest Pair)
def closest_pair_slow(arr):
    n = len(arr)
    if n < 2: return None
    min_diff = float('inf')
    pair = None
    for i in range(n):
        for j in range(i + 1, n):
            diff = abs(arr[i] - arr[j])
            if diff < min_diff:
                min_diff = diff
                pair = (arr[i], arr[j])
    return pair
def closest_pair_fast(arr):
    n = len(arr)
    if n < 2: return None
    arr_sorted = sorted(arr) # O(n log n)
    min_diff = float('inf')
    pair = None
    for i in range(n - 1): # O(n)
        diff = arr_sorted[i+1] - arr_sorted[i]
        if diff < min_diff:
            min_diff = diff
            pair = (arr_sorted[i], arr_sorted[i+1])
    return pair
//Đoạn code chứng minh và đo thời gian thực tế
def benchmark():
    # Khởi tạo dữ liệu thử nghiệm kích thước n = 10,000
    n = 10000
    print(f"--- ĐANG CHẠY ĐO THỜI GIAN VỚI N = {n:,} PHẦN TỬ ---\n")
   
    # 1. Đo Two Sum
    arr1 = list(range(n))
    random.shuffle(arr1)
    target = n * 2 # Cố tình chọn target không tồn tại để ép chạy hết mảng (worst case)
   
    start = time.time()
    two_sum_slow(arr1, target)
    t_slow = time.time() - start
   
    start = time.time()
    two_sum_fast(arr1, target)
    t_fast = time.time() - start
    print(f"Bài 1 (Two Sum):\n  - O(n²): {t_slow:.4f} giây\n  - O(n) : {t_fast:.4f} giây (Nhanh gấp {t_slow/max(t_fast, 1e-6):.1f} lần)\n")

    # 2. Đo Tìm trùng lặp
    arr2 = list(range(n)) + [n-1] # Trùng lặp ở cuối cùng
    random.shuffle(arr2)
   
    start = time.time()
    find_duplicate_slow(arr2)
    t_slow = time.time() - start
   
    start = time.time()
    find_duplicate_fast(arr2)
    t_fast = time.time() - start
    print(f"Bài 2 (Duplicate):\n  - O(n²): {t_slow:.4f} giây\n  - O(n) : {t_fast:.4f} giây (Nhanh gấp {t_slow/max(t_fast, 1e-6):.1f} lần)\n")

    # 3. Đo Cặp số gần nhất
    arr3 = [random.randint(0, 10000000) for _ in range(n)]
   
    start = time.time()
    closest_pair_slow(arr3)
    t_slow = time.time() - start
   
    start = time.time()
    closest_pair_fast(arr3)
    t_fast = time.time() - start
    print(f"Bài 3 (Closest Pair):\n  - O(n²): {t_slow:.4f} giây\n  - O(n log n): {t_fast:.4f} giây (Nhanh gấp {t_slow/max(t_fast, 1e-6):.1f} lần)\n")

if __name__ == "__main__":
    benchmark()
### Bài 4: 🔥 Dự Án Mini — Big-O Benchmark Tool ⭐⭐⭐
> **Cảm hứng:** [algorithm-visualizer.org](https://algorithm-visualizer.org)

║    O(n²)     ║  8ms     ║  800ms   ║  80000ms ║
╚══════════════╩══════════╩══════════╩══════════╝
```
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
**Yêu cầu:** dùng `std::chrono`, hiển thị bảng căn chỉnh đẹp, xuất ra file `benchmark.txt`.

---
 std::ofstream outfile("benchmark.txt");
    if (outfile.is_open()) {
        outfile << buffer.str();
        outfile.close();
        std::cout << "\n Da xuat file bieu do thanh cong vao 'benchmark.txt'!\n";
    } else {
        std::cerr << "\n Loi: Khong the tao hoặc ghi file 'benchmark.txt'.\n";
    }
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
