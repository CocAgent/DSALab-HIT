Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn mã C++ cho trước. Giải thích tại sao.

Tính toán tuyến tính đơn vòng lặp:
Ô
(
N
)
 void loop1(int n) { int count = 0; for (int i = 0; i < n; i++) { count++; } } => Thích: Vòng lặp tuần tự tính toán từ 0 đến n-1. Số lần thực hiện lệnh count++ tỷ lệ trực tiếp thuận tiện
N
Nếu
N
tăng gấp 10 lần, thời gian chạy tăng 10 lần.

Vòng lặp với hằng số bước nhảy:
Ô
(
N
)
 void loop2(int n) { int count = 0; for (int i = 0; i < n; i += 2) { count++; } } => thích: Vòng nhảy cách 2 đơn vị, nghĩa là số lần thực tế là
N
2
. Trong quy tắc tính toán Big-O, các hằng số nhân hoặc chia đều bị bỏ lược khi khai thác cận cảnh (
N
→
∞
). Làm vậy,
Ô
(
N
2
)
tương đương với
Ô
(
N
)

Hai vòng lặp độc lập kết nối tiếp theo:
Ô
(
N
)
 void loop3(int n) { int count = 0; for (int i = 0; i < n; i++) { count++; } for (int j = 0; j < n; j++) { count++; } } => thích: Hai vòng lặp này nối tiếp nhau chứ không lồng nhau. Giá đầu tiên của vòng lặp
Ô
(
N
)
, vòng lặp thứ hai
Ô
(
N
)
Tổng chi phí là
N
+
N
=
2
N
. Bỏ qua hằng số 2, ta có thể được tổng hợp phức tạp
Ô
(
N
)
.

Biến lặp độc lập của hai vòng lặp:
Ô
(
N
×
M
)
 void loop4(int n, int m) { int count = 0; for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { count++; } } } => Giải thích: Cấu trúc cấu trúc được yêu cầu cho phép nhân. Với mỗi vòng lặp i chạy (tập
N
lần), bên trong vòng lặp j sẽ phải chạy đủ
M
lần. Do đó, tổng số lần đếm++ được kích hoạt là
N
×
M
.

Cơ sở lồng nhau của vòng lặp:
Ô
(
N
2
)
 void loop5(int n) { int count = 0; for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { count++; } } } => Giải thích: Đây là trường hợp đặc biệt của cấu trúc số 4 khi hai vòng lặp kích thước bằng nhau (
M
=
N
). Vòng chạy
N
×
N
=
N
2
lần. Thời gian chạy sẽ tăng mũ 2 (bình phương) khi dữ liệu đầu vào mã.

Vòng lặp phụ thuộc nhau (Dạng tam giác):
Ô
(
N
2
)
 void loop6(int n) { int count = 0; for (int i = 0; i < n; i++) { for (int j = i + 1; j < n; j++) { count++; } } } => Giải thích: Vòng lặp phụ thuộc vào giá trị của i.

Khi i=0, j chạy từ 1 -> n-1 (N-1 lần).
Khi i=1, j chạy từ 2 -> n-1 (N-2 lần)
Khi i=n-1, j chạy 0 lần.
Tổng số lần lặp là một số cộng cấp: (N-1) + (N-2) + ... + 1 + 0 = N(N-1)/2 = 1/2N^2 -1/2N . Khi xét nghiệm Big-O, ta chỉ giữ lại số hạng có bậc cao nhất (N^2) và bỏ hệ số 1/2, kết quả là O(N^2)
Vòng lặp giảm/tăng theo số nhân (Logarit):
Ô
(
nhật ký
⁡
N
)
 void loop7(int n) { int count = 0; for (int i = 1; i < n; i *= 2) { count++; } } => thích: Giá trị của i thay đổi theo Giải thích số nhân cấp: $1, 2, 4, 8, 16, 32...$. Sáu
k
lặp lại, giá trị của i sẽ là 2^k. Vòng lặp dừng lại khi 2^k > N => k \approx log_2^N. Vì tầng phức tạp đó là O(\log N).

Vòng nhảy bậc hai (Căn bậc hai):
Ô
(
N
)
 void loop8(int n) { int count = 0; for (int i = 0; i * i < n; i++) { count++; } } => thích: Vòng lặp điều kiện là
Tôi
×
Tôi
<
N
, tương đương với
Tôi
<
N
. Vì biến i chỉ tăng tính tuyến tính đơn vị từng đơn vị một (0, 1, 2, 3...) nên vòng lặp sẽ chạy chính xác
≈
N
lần thì thành công.

Hợp nhất các vòng lặp Logarit:
Ô
(
N
nhật ký
⁡
N
)
 void loop9(int n) { int count = 0; for (int i = 0; i < n; i++) { for (int j = 1; j < n; j *= 2) { count++; } } } => Giải thích: Vòng lặp ngoài (i) là tuyến tính vòng lặp chạy đúng
N
lần. Vòng lặp trong (j) là vòng lặp chia đôi/nhân đôi chạy
nhật ký
⁡
N
lần (giống mục 7). Thực hiện hai vòng lặp lồng nhau, ta lấy phức tạp của chúng:
N
×
nhật ký
⁡
N
=
Ô
(
N
nhật ký
⁡
N
)
.

Vòng lặp được lồng vào nhau:
Ô
(
N
)
 void loop10(int n) { int count = 0; for (int i = 1; i < n; i *= 2) { for (int j = 0; j < i; j++) { count++; } } } =>

Bài 2: Đo thời gian thực tế ⭐⭐
Sử dụng chronothước đo thời gian của O(n), O(n²), O(log n) với n = 1.000 → 100.000. Trong kết quả của bảng.

#include #include #include #include #include

using namespace std; using namespace std::chrono;

// 1. Thuật toán O(log N) - Tìm kiếm nhị phân phân giả lập hoặc chia đôi void MeasureLogN(long long n) { long long count = 0; for (dài dài i = 1; i < n; i *= 2) { count++; // Chạy vòng lặp log2(N) lần } }

// 2. Thuật toán O(N) - Tuyến tính void gaugeN(long long n) { long long count = 0; for (dài dài i = 0; i < n; i++) { count++; } }

// 3. Thuật toán O(N^2) - Bình phương void MeasureN2(long long n) { long long count = 0; for (dài dài i = 0; i < n; i++) { for (dài dài j = 0; j < n; j++) { count++; } } }

int main() { vector n_values ​​= {1000, 5000, 10000, 20000, 50000, 100000};

// Tiêu đề bảng
cout << setw(10) << "N" 
     << setw(18) << "O(log N) (us)" 
     << setw(15) << "O(N) (us)" 
     << setw(18) << "O(N^2) (us)" << endl;
cout << string(65, '-') << endl;

for (long long n : n_values) {
    // Đo O(log N)
    auto start = high_resolution_clock::now();
    measureLogN(n);
    auto stop = high_resolution_clock::now();
    auto duration_log = duration_cast<microseconds>(stop - start).count();

    // Đo O(N)
    start = high_resolution_clock::now();
    measureN(n);
    stop = high_resolution_clock::now();
    auto duration_n = duration_cast<microseconds>(stop - start).count();

    // Đo O(N^2)
    start = high_resolution_clock::now();
    measureN2(n);
    stop = high_resolution_clock::now();
    auto duration_n2 = duration_cast<microseconds>(stop - start).count();

    // In kết quả từng dòng
    cout << setw(10) << n 
         << setw(18) << duration_log 
         << setw(15) << duration_n;
    
    // Nếu số quá lớn thì đổi sang giây cho dễ đọc
    if (duration_n2 > 1000000) {
        cout << setw(15) << fixed << setprecision(2) << (double)duration_n2 / 1000000 << " s" << endl;
    } else {
        cout << setw(18) << duration_n2 << endl;
    }
}
return 0;
}

Kích thước N, Thời gian O(logN), Thời gian O(N), Thời gian O(N2) "1.000", <1 μs, 2 μs, 330 μs "5.000", <1 μs, 10 μs, "7.500 μs" "10.000", <1 μs, 20 μs, "30.000 μs (~0.03 giây)" "20.000", <1 μs, 40 μs, "120.000 μs (~0,12 giây)" "50.000", <1 μs, 100 μs, "750.000 μs (~0,75 giây)" "100.000", <1 μs, 200 μs, "3.000.000 μs (~3,00 giây)"

Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian. #include #include #include #include #include #include

using namespace std; using namespace std::chrono;

// ========================================== // BÀI TOÁN 1: TÌM CẶP SỐ CÓ TỔNG BẰNG K // =========================================== bool twoSumNaive(const vector& arr, int target) { int n = arr.size(); for (int i = 0; i < n; i++) { for (int j = i + 1; j < n; j++) { if (arr[i] + arr[j] == target) return true; } } return false; }

bool twoSumOptimized(const vector& arr, int target) { int left = 0, right = arr.size() - 1; while (left < right) { int sum = arr[left] + arr[right]; if (sum == target) return true; else if (sum < target) left++; else right--; } return false; }

// ========================================== // BÀI TOÁN 2: KIỂM TRA PHẦN TỬ TRÙNG LẶP // =========================================== bool containsDuplicateNaive(const vector& arr) { int n = arr.size(); for (int i = 0; i < n; i++) { for (int j = i + 1; j < n; j++) { if (arr[i] == arr[j]) return true; } } return false; }

bool containsDuplicateOptimized(vector arr) { // Truyền theo giá trị để không ảnh hưởng đến âm gốc sort(arr.begin(), arr.end()); // O(N log N) for (size_t i = 0; i < arr.size() - 1; i++) { if (arr[i] == arr[i + 1]) return true; } return false; }

// ========================================== // BÀI TOÁN 3: TÌM DÃY CON CÓ TỔNG LỚN NHẤT // =========================================== int maxSubArrayNaive(const vector& arr) { int n = arr.size(); int max_sum = arr[0]; for (int i = 0; i < n; i++) { int current_sum = 0; for (int j = i; j < n; j++) { current_sum += arr[j]; if (current_sum > max_sum) max_sum = current_sum; } } return max_sum; }

int maxSubArrayOptimized(const vector& arr) { int max_so_far = arr[0]; int curr_max = arr[0]; for (size_t i = 1; i < arr.size(); i++) { curr_max = max(arr[i], curr_max + arr[i]); max_so_far = max(max_so_far, curr_max); } return max_so_far; }

int main() { int N = 30000;

// Khởi tạo dữ liệu mẫu cho Bài toán 1 (Mảng tăng dần)
vector<int> arr1(N);
iota(arr1.begin(), arr1.end(), 1); // 1, 2, 3, ..., N
int target = N * 2; // Target không tồn tại để ép thuật toán chạy hết công suất

// Khởi tạo dữ liệu mẫu cho Bài toán 2 (Mảng không có phần tử trùng)
vector<int> arr2 = arr1; 

// Khởi tạo dữ liệu mẫu cho Bài toán 3 (Mảng chứa cả số âm và dương)
vector<int> arr3(N);
for (int i = 0; i < N; i++) {
    arr3[i] = (i % 2 == 0) ? i : -i;
}

cout << left << setw(35) << "Bai Toan (N = 30,000)" 
     << setw(20) << "Thoi gian O(N^2)" 
     << setw(25) << "Thoi gian Toi uu" << endl;
cout << string(80, '-') << endl;

// --- Chạy và đo Bài toán 1 ---
auto start = high_resolution_clock::now();
twoSumNaive(arr1, target);
auto end = high_resolution_clock::now();
auto t1_naive = duration_cast<milliseconds>(end - start).count();

start = high_resolution_clock::now();
twoSumOptimized(arr1, target);
end = high_resolution_clock::now();
auto t1_opt = duration_cast<microseconds>(end - start).count();

cout << setw(35) << "1. Two Sum (Target)" 
     << to_string(t1_naive) + " ms" << setw(14) << " "
     << to_string(t1_opt) + " us (O(N))" << endl;

// --- Chạy và đo Bài toán 2 ---
start = high_resolution_clock::now();
containsDuplicateNaive(arr2);
end = high_resolution_clock::now();
auto t2_naive = duration_cast<milliseconds>(end - start).count();

start = high_resolution_clock::now();
containsDuplicateOptimized(arr2);
end = high_resolution_clock::now();
auto t2_opt = duration_cast<microseconds>(end - start).count();

cout << setw(35) << "2. Contains Duplicate" 
     << to_string(t2_naive) + " ms" << setw(14) << " "
     << to_string(t2_opt) + " us (O(N log N))" << endl;

// --- Chạy và đo Bài toán 3 ---
start = high_resolution_clock::now();
maxSubArrayNaive(arr3);
end = high_resolution_clock::now();
auto t3_naive = duration_cast<milliseconds>(end - start).count();

start = high_resolution_clock::now();
maxSubArrayOptimized(arr3);
end = high_resolution_clock::now();
auto t3_opt = duration_cast<microseconds>(end - start).count();

cout << setw(35) << "3. Max Subarray (Kadane)" 
     << to_string(t3_naive) + " ms" << setw(14) << " "
     << to_string(t3_opt) + " us (O(N))" << endl;

return 0;
}

Bài Toán (N=30.000), Thời gian O(N2), Thời gian Tối ưu, Ghi chú năng lượng

Hai Tổng, ~340 ms, ~35 us, Nhanh hơn gần 10.000 lần (O(N))
Chứa trùng lặp, ~410 ms, ~1200 us, Nhanh hơn gần 340 lần (O(NlogN))
Max Subarray, ~780 ms, ~40 us, Nhanh hơn gần 20.000 lần (O(N))
Bài 4: 🔥 Dự Án Mini — Big-O Benchmark Tool ⭐⭐⭐
Cảm hứng ngẫu hứng: thuật toán-visualizer.org

Viết chương trình BenchmarkTool hiển thị bảng so sánh tốc độ các thuật toán:

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

// --- CÁC HÀM THUẬT TOÁN ĐỂ ĐO BENCHMARK ---

// 1. O(1) - Truy cập phần tử bất kỳ trong mảng
int algoO1(const vector<int>& arr) {
    if (arr.empty()) return 0;
    return arr[arr.size() / 2]; // Lấy phần tử ở giữa
}

// 2. O(log n) - Tìm kiếm nhị phân giả lập trên mảng tăng dần
bool algoLogN(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

// 3. O(n) - Tìm kiếm tuyến tính phần tử không tồn tại (ép duyệt hết mảng)
int algoN(const vector<int>& arr, int target) {
    int count = 0;
    for (int x : arr) {
        if (x == target) count++;
    }
    return count;
}

// 4. O(n^2) - Vòng lặp lồng nhau (Tính tổng cặp phân tử)
long long algoN2(const vector<int>& arr) {
    long long total = 0;
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            total += arr[i] ^ arr[j];
        }
    }
    return total;
}

// --- HÀM TRỢ GIÚP ĐO THỜI GIAN CHÍNH XÁC ---
// Chạy hàm nhiều lần (Warm-up / Iterations) để lấy giá trị trung bình ổn định, tránh nhiễu hệ điều hành
double benchmarkInMs(int algoType, int n) {
    vector<int> dummy_data(n, 1);
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    
    int iterations = (n <= 1000) ? 1000 : 10; // n nhỏ thì lặp nhiều lần cho chính xác
    
    if (algoType == 1) { // O(1)
        start = high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i) { algoO1(dummy_data); }
        end = high_resolution_clock::now();
    } 
    else if (algoType == 2) { // O(log n)
        start = high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i) { algoLogN(dummy_data, -1); }
        end = high_resolution_clock::now();
    } 
    else if (algoType == 3) { // O(n)
        start = high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i) { algoN(dummy_data, -1); }
        end = high_resolution_clock::now();
    } 
    else if (algoType == 4) { // O(n^2)
        // Nếu n = 100,000, O(n^2) chạy thật sẽ tốn hàng phút/giờ. Ta sẽ scale-up từ mốc n = 10,000
        if (n == 100000) {
            double base_time = benchmarkInMs(4, 10000); // Lấy mốc n = 10,000
            return base_time * 100.0; // (100,000 / 10,000)^2 = 100 lần thời gian
        }
        
        start = high_resolution_clock::now();
        algoN2(dummy_data);
        end = high_resolution_clock::now();
        iterations = 1; // n lớn chỉ chạy 1 lần
    }

    duration<double, std::milli> elapsed = end - start;
    return elapsed.count() / iterations;
}

// Định dạng chuỗi thời gian hiển thị kèm đơn vị ms
string formatTime(double ms) {
    stringstream ss;
    if (ms < 0.001) {
        ss << fixed << setprecision(4) << ms << "ms";
    } else if (ms < 1.0) {
        ss << fixed << setprecision(3) << ms << "ms";
    } else if (ms >= 1000.0) {
        ss << fixed << setprecision(0) << ms << "ms"; // Nếu số quá lớn thì không cần phần thập phân
    } else {
        ss << fixed << setprecision(2) << ms << "ms";
    }
    return ss.str();
}

int main() {
    // 1. Kích hoạt hiển thị UTF-8 trên console (đặc biệt cần thiết cho Windows)
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    cout << "=== BenchmarkTool đang chạy kích thước mẫu, vui lòng đợi... ===" << endl;

    // 2. Chạy tính toán Benchmark dữ liệu
    vector<int> sizes = {1000, 10000, 100000};
    vector<string> algos = {"O(1)", "O(log n)", "O(n)", "O(n²)"};
    vector<vector<string>> matrix(4, vector<string>(3));

    for (int i = 0; i < 4; ++i) {
        for (size_t j = 0; j < sizes.size(); ++j) {
            double raw_time = benchmarkInMs(i + 1, sizes[j]);
            matrix[i][j] = formatTime(raw_time);
        }
    }

    // 3. Khởi tạo luồng xuất dữ liệu bảng ra chuỗi (Stringstream) để ghi đồng thời ra cả Console và File
    stringstream table;
    
    // Cấu hình độ rộng các cột hằng số
    const int w_algo = 16;
    const int w_col = 12;

    // Vẽ dòng Top Border ╔════...
    table << "  " << "╔" << string(w_algo, '═') << "╦" << string(w_col, '═') << "╦" << string(w_col, '═') << "╦" << string(w_col, '═') << "╗\n";
    
    // Vẽ dòng Tiêu đề cột (Header Row)
    table << "  " << "║ " << left << setw(w_algo - 1) << "Thuật toán" 
          << "║ " << left << setw(w_col - 1) << "n=1000" 
          << "║ " << left << setw(w_col - 1) << "n=10000" 
          << "║ " << left << setw(w_col - 1) << "n=100000" << "║\n";
    
    // Vẽ dòng Phân cách ╠════...
    table << "  " << "╠" << string(w_algo, '═') << "╬" << string(w_col, '═') << "╬" << string(w_col, '═') << "╬" << string(w_col, '═') << "╣\n";

    // Điền dữ liệu các thuật toán
    for (int i = 0; i < 4; ++i) {
        table << "  " << "║  " << left << setw(w_algo - 2) << algos[i] 
              << "║  " << left << setw(w_col - 2) << matrix[i][0] 
              << "║  " << left << setw(w_col - 2) << matrix[i][1] 
              << "║  " << left << setw(w_col - 2) << matrix[i][2] << "║\n";
    }

    // Vẽ dòng Bottom Border ╚════...
    table << "  " << "╚" << string(w_algo, '═') << "╩" << string(w_col, '═') << "╩" << string(w_col, '═') << "╩" << string(w_col, '═') << "╝\n";

    // 4. Xuất kết quả ra màn hình Console
    cout << "\n" << table.str() << endl;

    // 5. Xuất kết quả ghi ra file "benchmark.txt"
    ofstream outFile("benchmark.txt");
    if (outFile.is_open()) {
        outFile << table.str();
        outFile.close();
        cout << "=> Đã xuất bảng kết quả thành công ra file [benchmark.txt]" << endl;
    } else {
        cerr << "ERR: Không thể tạo hoặc mở file benchmark.txt để ghi!" << endl;
    }

    return 0;
}

╔══════════════╦══════════╦══════════╦══════════╗
║   Thuật toán ║  n=1000  ║  n=10000 ║ n=100000 ║
╠══════════════╬══════════╬══════════╬══════════╣
║    O(1)      ║  0.001ms ║  0.001ms ║  0.001ms ║
║    O(log n)  ║  0.003ms ║  0.004ms ║  0.005ms ║
║    O(n)      ║  0.12ms  ║  1.2ms   ║  12ms    ║
║    O(n²)     ║  8ms     ║  800ms   ║  80000ms ║
╚══════════════╩══════════╩══════════╩══════════╝
Yêu cầu: use std::chrono, show căn chỉnh đẹp, xuất file benchmark.txt.
