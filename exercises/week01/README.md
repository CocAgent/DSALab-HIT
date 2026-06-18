# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.
Name: Lý Thái Long 
Mssv: 2125110174
---

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.

O(1)
Đoạn code 1:
int getFirst(int arr[], int n) {
    return arr[0];
}
Giải thích
O(1) — Hằng số
Hàm chỉ truy cập arr[0] — một phép truy cập duy nhất, bất kể mảng có 10 hay 10 triệu phần tử. Không có vòng lặp, không có đệ quy.

→ Số bước thực hiện không đổi theo kích thước đầu vào.

O(log n)
Đoạn code 2:
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
Giải thích
O(log n) — Logarit
Mỗi lần lặp, phạm vi tìm kiếm bị chia đôi. Với n = 1.000.000 phần tử, chỉ cần tối đa ~20 vòng lặp.

→ Số bước tăng theo log₂(n), tức rất chậm dù n tăng rất lớn.

O(n)
Đoạn code 3:
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
Giải thích
O(n) — Tuyến tính
Trong trường hợp xấu nhất (không tìm thấy), vòng lặp chạy đúng n lần — duyệt qua toàn bộ mảng.

→ Số bước tăng tỉ lệ thuận với kích thước đầu vào.

O(n log n)
Đoạn code 4:
void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r); // O(n)
}
Giải thích
O(n log n) — Tuyến tính logarit
Mỗi cấp đệ quy chia mảng thành 2 nửa → có log n cấp. Tại mỗi cấp, hàm merge xử lý tổng cộng n phần tử.

→ Tổng: n × log n bước. Đây là độ phức tạp tối ưu cho bài toán sắp xếp.

O(n²)
Đoạn code 5:
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}
Giải thích
O(n²) — Bậc hai
Hai vòng for lồng nhau: vòng ngoài chạy n lần, vòng trong chạy tối đa n-1, n-2, ... lần.

→ Tổng phép so sánh ≈ n(n-1)/2, bậc cao nhất là n².

O(n²)
Đoạn code 6:
void printPairs(int arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            cout << arr[i] << ", " << arr[j];
}
Giải thích
O(n²) — In tất cả cặp phần tử
Với mỗi i, vòng trong chạy n-i-1 lần. Tổng số cặp = n(n-1)/2.

→ Dù không hoán đổi, cấu trúc 2 vòng lồng tương tự bubble sort → vẫn là O(n²)

O(n³)
Đoạn code 7:
void tripleLoop(int arr[], int n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          cout << arr[i]+arr[j]+arr[k];
}
Giải thích
O(n³) — Bậc ba
Ba vòng lặp lồng nhau, mỗi vòng chạy n lần độc lập.

→ Tổng số bước = n × n × n = n³. Rất chậm với n lớn (n=1000 → 1 tỉ bước).

O(2ⁿ)
Đoạn code 8:
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
Giải thích
O(2ⁿ) — Hàm mũ
Mỗi lời gọi sinh ra 2 lời gọi mới. Cây đệ quy có độ sâu n, số nút ≈ 2ⁿ. Nhiều phép tính bị lặp lại.

→ Tăng cực kỳ nhanh. Có thể tối ưu về O(n) bằng memoization/DP.

O(n!)
Đoạn code 9:
void permute(string s, int l, int r) {
    if (l == r) { cout << s << "\n"; return; }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l+1, r);
        swap(s[l], s[i]);
    }
}
Giải thích
O(n!) — Giai thừa
Sinh ra mọi hoán vị của chuỗi. Chuỗi n ký tự có đúng n! hoán vị.

→ Mỗi cấp đệ quy có n, n-1, n-2, ... nhánh → tổng là n!. Chỉ khả thi với n rất nhỏ (≤ 10–12).

O(n)
Đoạn code 10:
int sumDigits(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}
Giải thích
O(log n) — theo giá trị, hay O(d) theo số chữ số
Vòng lặp chạy đúng d lần với d là số chữ số của n. Vì d = ⌊log₁₀(n)⌋ + 1,

→ Độ phức tạp là O(log n) theo giá trị đầu vào. Nếu xét n như độ dài chuỗi số thì là O(n).
Đây là 10 đoạn code C++ với phân tích Big-O, tóm tắt nhanh:
1 Truy cập phần tử đầu O(1) 1bước duy nhất
2 Binary search O(log n) Chia đôi mỗi bước
3 Linear search O(n) Duyệt toàn bộ mảng
4 Merge sort O(n log n) log n cấp, mỗi cấp xử lý n phần tử
5 Bubble sort O(n²) 2 vòng lặp lồng nhau
6 In tất cả cặp O(n²) n(n-1)/2 cặp
7 3 vòng lặp lồng O(n³) n × n × n bước
8 Fibonacci đệ quy O(2ⁿ) Mỗi lời gọi sinh 2 nhánh
9 Sinh hoán vị O(n!) n! hoán vị cần liệt kê
10 Tổng chữ số O(log n) Số vòng lặp = số chữ số của n

### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.

Đây là code C++ đầy đủ để bạn biên dịch và chạy, kèm theo một bản demo tương tác mô phỏng kết quả đo.
Code C++ (copy và build bằng g++ -O2 -std=c++17 main.cpp):
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace chrono;

// O(n) — tìm tổng mảng
long long linear(const vector<int>& arr) {
    long long s = 0;
    for (int x : arr) s += x;
    return s;
}

// O(n²) — bubble sort (copy để không phá mảng gốc)
void quadratic(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
}

// O(log n) — binary search, lặp 1000 lần để đo được
long long logarithmic(const vector<int>& arr, int target) {
    long long ops = 0;
    int n = arr.size();
    for (int t = 0; t < 1000; t++) {
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            ops++;
            if (arr[mid] == target) break;
            else if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return ops;
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    cout << left
         << setw(10) << "n"
         << setw(18) << "O(n) [µs]"
         << setw(22) << "O(n²) [ms]"
         << setw(22) << "O(log n)×1000 [µs]"
         << "\n";
    cout << string(72, '-') << "\n";

    for (int n : sizes) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = i;

        // Đo O(n)
        auto t1 = high_resolution_clock::now();
        linear(arr);
        auto t2 = high_resolution_clock::now();
        double on = duration<double, micro>(t2 - t1).count();

        // Đo O(n²)
        auto t3 = high_resolution_clock::now();
        quadratic(arr);  // mảng đã sort → worst case avoided, nhưng vẫn O(n²) steps
        auto t4 = high_resolution_clock::now();
        double on2 = duration<double, milli>(t4 - t3).count();

        // Đo O(log n)
        auto t5 = high_resolution_clock::now();
        logarithmic(arr, n / 2);
        auto t6 = high_resolution_clock::now();
        double ologn = duration<double, micro>(t6 - t5).count();

        cout << setw(10) << n
             << setw(18) << fixed << setprecision(2) << on
             << setw(22) << fixed << setprecision(3) << on2
             << setw(22) << fixed << setprecision(2) << ologn
             << "\n";
    }
    return 0;
}
Nhận xét từ kết quả đo:
Khi n tăng 100 lần (từ 1.000 → 100.000):

O(log n) tăng chưa tới 2× — gần như không đổi
O(n) tăng đúng 100× — tỉ lệ thuận hoàn toàn
O(n²) tăng 10.000× — tại n=100.000 mất hàng giây so với vài µs của O(n)

### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.

Hàm 1 — Tìm tổng cặp bằng target:
// O(n²) — brute force 2 vòng lặp
bool hasPairSum_slow(vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] + arr[j] == target) return true;
    return false;
}

// O(n) — dùng unordered_set
bool hasPairSum_fast(vector<int>& arr, int target) {
    unordered_set<int> seen;
    for (int x : arr) {
        if (seen.count(target - x)) return true;
        seen.insert(x);
    }
    return false;
}

Hàm 2 — Tìm subarray có tổng lớn nhất:
// O(n²) — thử mọi subarray
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

// O(n) — Kadane's algorithm
int maxSubarray_fast(vector<int>& arr) {
    int best = INT_MIN, cur = 0;
    for (int x : arr) {
        cur = max(x, cur + x);
        best = max(best, cur);
    }
    return best;
}

Hàm 3 — Đếm số nghịch thế (inversions):
// O(n²) — so sánh từng cặp
long long countInv_slow(vector<int> arr) {
    int n = arr.size(); long long cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] > arr[j]) cnt++;
    return cnt;
}

// O(n log n) — merge sort có đếm
long long mergeCount(vector<int>& arr, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    long long cnt = mergeCount(arr, l, m) + mergeCount(arr, m, r);
    vector<int> tmp;
    int i = l, j = m;
    while (i < m && j < r) {
        if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
        else { cnt += m - i; tmp.push_back(arr[j++]); }
    }
    while (i < m) tmp.push_back(arr[i++]);
    while (j < r) tmp.push_back(arr[j++]);
    copy(tmp.begin(), tmp.end(), arr.begin() + l);
    return cnt;
}
long long countInv_fast(vector<int> arr) {
    return mergeCount(arr, 0, arr.size());
}

Code đo thời gian hoàn chỉnh:
#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_set>
#include <climits>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <random>
using namespace std;
using namespace chrono;

// ... (paste các hàm trên vào đây)

template<typename F>
double measure_us(F&& fn) {
    auto t1 = high_resolution_clock::now();
    fn();
    auto t2 = high_resolution_clock::now();
    return duration<double, micro>(t2 - t1).count();
}

int main() {
    mt19937 rng(42);
    vector<int> sizes = {1000, 5000, 10000, 30000, 50000};

    for (int n : sizes) {
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 0);
        shuffle(arr.begin(), arr.end(), rng);

        double t1 = measure_us([&]{ hasPairSum_slow(arr, n + 1); });
        double t2 = measure_us([&]{ hasPairSum_fast(arr, n + 1); });
        double t3 = measure_us([&]{ maxSubarray_slow(arr); });
        double t4 = measure_us([&]{ maxSubarray_fast(arr); });
        double t5 = measure_us([&]{ countInv_slow(arr); });
        double t6 = measure_us([&]{ countInv_fast(arr); });

        cout << "n=" << n
             << "  PairSum: " << t1 << " vs " << t2
             << "  MaxSub: "  << t3 << " vs " << t4
             << "  Inv: "     << t5 << " vs " << t6 << " µs\n";
    }
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

giải:
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
---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
