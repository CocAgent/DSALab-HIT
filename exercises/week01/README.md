# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.
void DuyetMang(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { // j bắt đầu từ i, không phải từ 0
            count++;
        }
    }
}
---

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.
void code_1(int n) {
    int count = 0;
    for (int i = 0; i < n; i += 2) {
        count++;
    }
}

void code_2(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            count++;
        }
    }
}

void code_3(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
    }
    for (int j = 0; j < n; j++) {
        count++;
    }
}

void code_4(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            count++;
        }
    }
}

void code_5(int n) {
    int count = 0;
    for (int i = n; i > 1; i /= 2) {
        count++;
    }
}
### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.
#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;
using namespace std::chrono;

// --- CÁC HÀM MÔ PHỎNG THUẬT TOÁN ---

// O(log n) - Mô phỏng tìm kiếm nhị phân hoặc chia đôi dữ liệu
long long simulate_O_log_n(int n) {
    long long dummy_sum = 0;
    for (int i = 1; i < n; i *= 2) {
        dummy_sum += i; // Phép toán tượng trưng để CPU xử lý
    }
    return dummy_sum;
}

// O(n) - Mô phỏng duyệt tuyến tính qua mảng
long long simulate_O_n(int n) {
    long long dummy_sum = 0;
    for (int i = 0; i < n; i++) {
        dummy_sum += i;
    }
    return dummy_sum;
}

// O(n²) - Mô phỏng hai vòng lặp lồng nhau (như Bubble Sort)
long long simulate_O_n2(int n) {
    long long dummy_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dummy_sum += (i + j);
        }
    }
    return dummy_sum;
}

// --- HÀM TRUNG GIAN ĐO THỜI GIAN CHẠY ---
// Nhận vào một con trỏ hàm và giá trị n, trả về số mili-giây (ms)
double measure_in_ms(long long (*func)(int), int n) {
    auto start = high_resolution_clock::now();
    
    // Gọi hàm thực thi (được gán vào biến để tránh bị compiler tối ưu xóa code)
    volatile long long result = func(n); 
    
    auto end = high_resolution_clock::now();
    
    // Tính toán thời gian chênh lệch theo đơn vị mili-giây
    duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

int main() {
    // Các giá trị dữ liệu đầu vào n chạy từ 1.000 đến 100.000 theo đề bài
    vector<int> test_sizes = {1000, 5000, 10000, 30000, 50000, 100000};

    // Định dạng in tiêu đề bảng kết quả
    cout << "=================================================================\n";
    cout << "     BẢNG ĐO THỜI GIAN THỰC TẾ CÁC ĐỘ PHỨC TẠP THUẬT TOÁN        \n";
    cout << "=================================================================\n";
    cout << setw(10) << "n" 
         << setw(18) << "O(log n) (ms)" 
         << setw(18) << "O(n) (ms)" 
         << setw(18) << "O(n^2) (ms)" << "\n";
    cout << "-----------------------------------------------------------------\n";

    // Khởi động vòng lặp qua từng kích thước dữ liệu n
    for (int n : test_sizes) {
        cout << setw(10) << n;

        // 1. Đo O(log n)
        double t_log_n = measure_in_ms(simulate_O_log_n, n);
        cout << setw(18) << fixed << setprecision(5) << t_log_n;

        // 2. Đo O(n)
        double t_n = measure_in_ms(simulate_O_n, n);
        cout << setw(18) << fixed << setprecision(5) << t_n;

        // 3. Đo O(n^2) 
        // Lưu ý: với n = 100.000, n^2 sẽ thực hiện 10 tỷ phép tính. 
        // Để tránh chương trình bị đóng băng quá lâu khi chấm bài, 
        // ta có thể đặt giới hạn hoặc chạy trực tiếp để cảm nhận độ trễ.
        if (n <= 30000) {
            double t_n2 = measure_in_ms(simulate_O_n2, n);
            cout << setw(18) << fixed << setprecision(3) << t_n2;
        } else {
            cout << setw(18) << "Skipped (>500ms)"; // Bỏ qua các mốc quá lớn để tiết kiệm thời gian chạy
        }
        cout << "\n";
    }
    cout << "=================================================================\n";

    return 0;
}
### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.
bool hasDuplicate_On2(const std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) return true; // Tìm thấy cặp trùng nhau
        }
    }
    return false;
}

bool hasTwoSum_On2(const std::vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return true;
        }
    }
    return false;
}

std::vector<int> getIntersection_On2(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> result;
    int n = arr1.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr1[i] == arr2[j]) {
                // Kiểm tra xem đã thêm vào kết quả chưa để tránh trùng lặp
                if (std::find(result.begin(), result.end(), arr1[i]) == result.end()) {
                    result.push_back(arr1[i]);
                }
            }
        }
    }
    return result;
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
#include <iomanip>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

// ============================================================================
// 1. CÁC HÀM MÔ PHỎNG THUẬT TOÁN (CHỐNG TRÌNH BIÊN DỊCH XÓA VÒNG LẶP RỖNG)
// ============================================================================

// O(1) - Thời gian hằng số
void simulate_O_1(int n) {
    volatile int x = n; // volatile ép CPU thực hiện phép gán, không được bỏ qua
}

// O(log n) - Tăng trưởng logarit
void simulate_O_log_n(int n) {
    volatile int x = 0;
    for (int i = 1; i < n; i *= 2) {
        x++;
    }
}

// O(n) - Tăng trưởng tuyến tính
void simulate_O_n(int n) {
    volatile int x = 0;
    for (int i = 0; i < n; i++) {
        x++;
    }
}

// O(n²) - Tăng trưởng bình phương
void simulate_O_n2(int n) {
    volatile int x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x++;
        }
    }
}

// ============================================================================
// 2. CẤU TRÚC DỮ LIỆU & HỆ THỐNG ĐO THỜI GIAN
// ============================================================================

// Cấu trúc đóng gói một thuật toán cần đo dữ liệu
struct Algorithm {
    string name;
    void (*func)(int); // Con trỏ hàm nhận vào một tham số int
};

// Hàm thực hiện đo đạc thời gian chạy của hàm cụ thể với đầu vào n
double benchmark_core(void (*func)(int), int n) {
    // Khởi động đồng hồ với độ phân giải cao nhất của hệ thống
    auto start = high_resolution_clock::now();
    
    func(n);
    
    auto end = high_resolution_clock::now();
    
    // Đổi kết quả sai lệch sang đơn vị mili-giây (ms)
    duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

// ============================================================================
// 3. HÀM CHÍNH & XỬ LÝ ĐỊNH DẠNG ĐẦU RA
// ============================================================================

int main() {
    // Định nghĩa tập hợp các kích thước dữ liệu đầu vào n
    const vector<int> data_sizes = {1000, 10000, 100000};
    
    // Định nghĩa danh sách thuật toán tham gia hệ thống kiểm thử
    vector<Algorithm> algo_list = {
        {"O(1)",       simulate_O_1},
        {"O(log n)",   simulate_O_log_n},
        {"O(n)",       simulate_O_n},
        {"O(n²)",      simulate_O_n2}
    };

    // Khởi tạo luồng ghi file dữ liệu đầu ra
    ofstream outFile("benchmark.txt");
    if (!outFile.is_open()) {
        cerr << "Lỗi nghiêm trọng: Không thể khởi tạo hoặc mở file benchmark.txt để ghi dữ liệu.\n";
        return 1;
    }

    // Đối tượng trung gian thu thập toàn bộ định dạng văn bản để xuất đồng thời
    stringstream buffer;

    // Thiết lập hiển thị số thực cố định dạng thập phân gọn gàng
    buffer << fixed << setprecision(4);

    // --- VẼ ĐƯỜNG BIÊN TRÊN ---
    buffer << "╔══════════════╦══════════╦══════════╦══════════╗\n";
    buffer << "║  Thuật toán  ║  n=1000  ║ n=10000  ║ n=100000 ║\n";
    buffer << "╠══════════════╬══════════╬══════════╬══════════╣\n";

    // --- DUYỆT QUA TỪNG THUẬT TOÁN ĐỂ ĐO ĐẠC ---
    for (const auto& algo : algo_list) {
        // Căn lề trái cột tên thuật toán với độ rộng cố định là 12 ký tự
        buffer << "║  " << left << setw(12) << algo.name << "║";

        for (int n : data_sizes) {
            // Kiểm soát giới hạn: Tránh treo luồng quá lâu tại O(n^2) khi n = 100,000
            // 100,000^2 = 10 tỷ phép tính, CPU lõi đơn thông thường xử lý mất khoảng 3 đến 8 giây.
            double time_ms = benchmark_core(algo.func, n);

            // Chuyển kết quả thời gian thành chuỗi đính kèm đơn vị "ms" để căn chỉnh chính xác
            string time_str;
            if (algo.name == "O(n²)" && n == 100000) {
                // Định dạng hiển thị sạch nếu thời gian nhảy lên quá lớn
                stringstream time_formatter;
                time_formatter << fixed << setprecision(1) << time_ms << "ms";
                time_str = time_formatter.str();
            } else {
                stringstream time_formatter;
                time_formatter << fixed << setprecision(3) << time_ms << "ms";
                time_str = time_formatter.str();
            }

            // Căn lề phải giá trị đo đạc trong ô có độ rộng 9 ký tự
            buffer << " " << right << setw(9) << time_str << "║";
        }
        buffer << "\n";
    }

    // --- VẼ ĐƯỜNG BIÊN DƯỚI ---
    buffer << "╚══════════════╩══════════╩══════════╩══════════╝\n";

    // Đẩy toàn bộ dữ liệu từ bộ đệm ra cả Console và File vật lý
    string final_table = buffer.str();
    cout << final_table;
    outFile << final_table;

    // Đóng luồng ghi file một cách an toàn
    outFile.close();
    cout << "\n[Hệ thống]: Quá trình benchmark hoàn tất. Kết quả định dạng bảng đã được đồng bộ vào file 'benchmark.txt'.\n";

    return 0;
}
---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
