# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

Nguyen Ngoc Duy
MSSV: 2125110166

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.

Đoạn code 1: Vòng lặp tuyến tính cơ bảnC++void code1(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
    }
}
Độ phức tạp: $O(n)$Giải thích: Vòng lặp chạy chính xác $n$ lần. Phép toán count++ tốn thời gian hằng số $O(1)$. Tổng số bước chạy là $n \times O(1) = O(n)$.Đoạn code 2: Vòng lặp tăng bước nhảy theo cấp số nhânC++void code2(int n) {
    int count = 0;
    for (int i = 1; i < n; i = i * 2) {
        count++;
    }
}
Độ phức tạp: $O(\log n)$Giải thích: Biến i không tăng lên 1 đơn vị mà nhân đôi sau mỗi vòng lặp ($1, 2, 4, 8, 16,...$). Vòng lặp dừng lại khi $2^k \ge n \Rightarrow k \ge \log_2 n$. Do đó số lần lặp tỉ lệ thuận với $\log_2 n$.Đoạn code 3: Hai vòng lặp độc lập (Quy tắc cộng)C++void code3(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
    }
    for (int j = 0; j < n; j++) {
        count++;
    }
}
Độ phức tạp: $O(n)$Giải thích: Vòng lặp thứ nhất tốn $O(n)$, vòng lặp thứ hai tốn $O(n)$. Hai vòng lặp này nằm nối tiếp nhau nên ta áp dụng quy tắc cộng: $O(n) + O(n) = O(2n)$. Theo quy tắc Big-O, ta bỏ qua hằng số số 2, kết quả là $O(n)$.Đoạn code 4: Vòng lặp lồng nhau (Quy tắc nhân)C++void code4(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count++;
        }
    }
}
Độ phức tạp: $O(n^2)$Giải thích: Hai vòng lặp lồng vào nhau. Với mỗi lượt chạy của vòng ngoài (chạy $n$ lần), vòng bên trong lại chạy $n$ lần. Tổng số lần phép toán count++ thực thi là $n \times n = n^2$.Đoạn code 5: Vòng lặp lồng nhau dạng ma trận tam giácC++void code5(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            count++;
        }
    }
}
Độ phức tạp: $O(n^2)$Giải thích:Khi $i = 0$, vòng trong chạy $n - 1$ lần.Khi $i = 1$, vòng trong chạy $n - 2$ lần....Khi $i = n-1$, vòng trong chạy $0$ lần.Tổng số lần lặp là: $(n - 1) + (n - 2) + ... + 1 + 0 = \frac{n(n - 1)}{2} = \frac{1}{2}n^2 - \frac{1}{2}n$. Khi $n$ tiến ra vô cùng, số hạng bậc cao nhất quyết định độ phức tạp, ta lược bỏ hằng số và số hạng bậc thấp, giữ lại $O(n^2)$.Đoạn code 6: Vòng lặp phụ thuộc vào hằng số cố định (Cạm bẫy)C++void code6(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1000; j++) {
            count++;
        }
    }
}
Độ phức tạp: $O(n)$Giải thích: Vòng lặp bên ngoài chạy $n$ lần. Vòng lặp bên trong luôn luôn chạy đúng $1000$ lần, không phụ thuộc vào kích thước dữ liệu đầu vào $n$. Số phép tính là $1000 \times n$. Vì $1000$ là hằng số nên độ phức tạp cuối cùng vẫn là $O(n)$.Đoạn code 7: Vòng lặp tăng tiến bình phươngC++void code7(int n) {
    int count = 0;
    for (int i = 0; i * i < n; i++) {
        count++;
    }
}
Độ phức tạp: $O(\sqrt{n})$Giải thích: Điều kiện dừng của vòng lặp là $i^2 \ge n$, tương đương với $i \ge \sqrt{n}$. Vì i tăng tuyến tính mỗi lần 1 đơn vị, vòng lặp sẽ chạy chính xác $\approx \sqrt{n}$ lần trước khi dừng lại.Đoạn code 8: Vòng lặp nhân đôi lồng nhauC++void code8(int n) {
    int count = 0;
    for (int i = 1; i < n; i = i * 2) {
        for (int j = 0; j < n; j++) {
            count++;
        }
    }
}
Độ phức tạp: $O(n \log n)$Giải thích: Vòng lặp ngoài chạy theo cấp số nhân nhân đôi nên tốn $O(\log n)$ lần (giống Đoạn code 2). Vòng lặp bên trong chạy tuyến tính độc lập tốn $O(n)$ lần. Vì hai vòng lặp lồng nhau, ta nhân độ phức tạp của chúng lại: $O(\log n) \times O(n) = O(n \log n)$.Đoạn code 9: Hàm đệ quy tuyến tínhC++int code9(int n) {
    if (n <= 1) return 1;
    return code9(n - 1) + code9(n - 2); // Lưu ý: Đây là cấu trúc tính số Fibonacci đệ quy
}
Độ phức tạp: $O(2^n)$ — chính xác hơn là $O(1.618^n)$ theo tỷ lệ vàng, nhưng thường được khái quát là hàm mũ $O(2^n)$.Giải thích: Mỗi một lời gọi hàm code9(n) sẽ sinh ra 2 lời gọi hàm con là code9(n-1) và code9(n-2). Cấu trúc này tạo thành một cây đệ quy nhị phân có chiều sâu tối đa là $n$. Số lượng nút trên cây này tăng gấp đôi sau mỗi tầng, dẫn đến tổng số lời gọi hàm có dạng lũy thừa mũ $2^n$.Đoạn code 10: Thuật toán tìm kiếm nhị phân (Binary Search)C++int code10(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
Độ phức tạp: $O(\log n)$ (với $n = \text{right} - \text{left} + 1$)Giải thích: Ở mỗi bước lặp của vòng while, ta tính toán phần tử ở giữa (mid) và so sánh. Dù đi theo nhánh left = mid + 1 hay right = mid - 1, kích thước của không gian tìm kiếm (đoạn từ left đến right) đều bị giảm đi một nửa ($\frac{n}{2}$). Việc liên tục chia đôi không gian tìm kiếm này dẫn đến số bước thực thi tối đa trong trường hợp tệ nhất là $\log_2 n$.

### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.

#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <cmath>

// 1. Thuật toán O(log n) - Mô phỏng tìm kiếm nhị phân
long long run_log_n(int n) {
    long long count = 0;
    for (int i = 1; i < n; i *= 2) {
        count++; // Thực hiện phép toán hằng số
    }
    return count;
}

// 2. Thuật toán O(n) - Vòng lặp tuyến tính
long long run_n(int n) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        count++; // Thực hiện phép toán hằng số
    }
    return count;
}

// 3. Thuật toán O(n^2) - Vòng lặp lồng nhau
long long run_n_squared(int n) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count++; // Thực hiện phép toán hằng số
        }
    }
    return count;
}

int main() {
    // Cấu hình danh sách các kích thước n cần test
    std::vector<int> test_sizes = {1000, 5000, 10000, 30000, 50000, 100000};

    // In tiêu đề bảng kết quả
    std::cout << std::left << std::setw(12) << "N" 
              << std::setw(18) << "O(log n) (ms)" 
              << std::setw(15) << "O(n) (ms)" 
              << std::setw(15) << "O(n^2) (ms)" << std::endl;
    std::cout << std::string(60, '-') << std::endl;

    for (int n : test_sizes) {
        // --- Đo O(log n) ---
        auto start = std::chrono::high_resolution_clock::now();
        run_log_n(n);
        auto end = std::chrono::high_resolution_clock::now();
        // Dùng duration<double, std::milli> để tự động đổi sang mili-giây dạng số thực
        std::chrono::duration<double, std::milli> time_log_n = end - start;

        // --- Đo O(n) ---
        start = std::chrono::high_resolution_clock::now();
        run_n(n);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_n = end - start;

        // --- Đo O(n^2) ---
        start = std::chrono::high_resolution_clock::now();
        run_n_squared(n);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_n_squared = end - start;

        // In dòng kết quả (định dạng 6 chữ số sau dấu phẩy)
        std::cout << std::left << std::setw(12) << n 
                  << std::fixed << std::setprecision(6)
                  << std::setw(18) << time_log_n.count()
                  << std::setw(15) << time_n.count()
                  << std::setw(15) << time_n_squared.count() << std::endl;
    }

    return 0;
}
### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ... Chèn các hàm O(n^2), O(n), O(n log n) ở phía trên vào đây ...

int main() {
    int n = 50000; // Đủ lớn để thấy sự khác biệt rõ rệt
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Khởi tạo mảng tăng dần cho Bài toán 1 (Two Sum)
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2;
    }
    int K = (n - 2) * 2 + (n - 1) * 2; // Tổng của 2 phần tử cuối cùng (trường hợp tệ nhất)

    printf("=== DO THOI GIAN BAI TOAN 1 (TWO SUM) con n = %d ===\n", n);
    
    clock_t start = clock();
    int res1 = hasSumPair_O2(arr, n, K);
    clock_t end = clock();
    double time_O2 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Thoi gian O(n^2): %f giay (Ket qua: %d)\n", time_O2, res1);

    start = clock();
    int res2 = hasSumPair_On(arr, n, K);
    end = clock();
    double time_On = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Thoi gian O(n):   %f giay (Ket qua: %d)\n", time_On, res2);

    free(arr);
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
#include <iomanip>
#include <string>
#include <sstream>

// Định nghĩa các hàm mô phỏng thuật toán để đo thời gian
// Sử dụng volatile hoặc ép trả về giá trị để tránh compiler tối ưu xóa vòng lặp

void algo_O1(int n) {
    volatile int a = 0;
    a = 1 + 1;
}

long long algo_OlogN(int n) {
    long long count = 0;
    for (int i = 1; i < n; i *= 2) {
        count++;
    }
    return count;
}

long long algo_On(int n) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        count++;
    }
    return count;
}

long long algo_On2(int n) {
    long long count = 0;
    // Đối với n = 100,000, O(n^2) tốn 10 tỷ phép tính (chạy mất vài chục giây)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count++;
        }
    }
    return count;
}

// Hàm đo thời gian và định dạng chuỗi kết quả (ví dụ: "0.123ms")
std::string measure_time(void (*func)(int), int n) {
    auto start = std::chrono::high_resolution_clock::now();
    func(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3) << duration.count() << "ms";
    return ss.str();
}

std::string measure_time_ll(long long (*func)(int), int n) {
    auto start = std::chrono::high_resolution_clock::now();
    func(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    std::stringstream ss;
    if (duration.count() < 0.001) {
        ss << std::fixed << std::setprecision(4) << duration.count() << "ms";
    } else {
        ss << std::fixed << std::setprecision(3) << duration.count() << "ms";
    }
    return ss.str();
}

int main() {
    // Kích thước các tập dữ liệu test
    std::vector<int> sizes = {1000, 10000, 100000};
    
    // Tên các thuật toán tương ứng
    std::vector<std::string> algo_names = {"O(1)", "O(log n)", "O(n)", "O(n²)"};
    
    // Ma trận lưu kết quả chuỗi thời gian hiển thị [Hàng = Thuật toán][Cột = Kích thước n]
    std::vector<std::vector<std::string>> grid(4, std::vector<std::string>(3));

    std::cout << "Dang chay Benchmark... Vui long doi trong giay lat (vong lap O(n^2) voi n=100000 se ton thoi gian)..." << std::endl;

    // Đo đạc dữ liệu cho từng ô
    for (size_t i = 0; i < sizes.size(); i++) {
        grid[0][i] = measure_time(algo_O1, sizes[i]);
        grid[1][i] = measure_time_ll(algo_OlogN, sizes[i]);
        grid[2][i] = measure_time_ll(algo_On, sizes[i]);
        grid[3][i] = measure_time_ll(algo_On2, sizes[i]);
    }

    // Thiết lập độ rộng cố định cho các cột để căn chỉnh đẹp mắt
    int col0_width = 16; // Cột Thuật toán
    int col_width = 12;  // Các cột n=...

    // Xây dựng chuỗi nội dung bảng
    std::stringstream table;
    
    // 1. Dòng cạnh trên cùng
    table << "╔" << std::string(col0_width, '═') << "╦" << std::string(col_width, '═') << "╦" << std::string(col_width, '═') << "╦" << std::string(col_width, '═') << "╗\n";
    
    // 2. Dòng tiêu đề cột
    table << "║ " << std::left << std::setw(col0_width - 1) << "Thuật toán"
          << "║ " << std::setw(col_width - 1) << "n=1000"
          << "║ " << std::setw(col_width - 1) << "n=10000"
          << "║ " << std::setw(col_width - 1) << "n=100000" << "║\n";
          
    // 3. Dòng ngăn cách giữa tiêu đề và nội dung
    table << "╠" << std::string(col0_width, '═') << "╬" << std::string(col_width, '═') << "╬" << std::string(col_width, '═') << "╬" << std::string(col_width, '═') << "╣\n";
    
    // 4. Các dòng nội dung kết quả dữ liệu
    for (int i = 0; i < 4; i++) {
        table << "║ " << std::left << std::setw(col0_width - 1) << algo_names[i]
              << "║ " << std::setw(col_width - 1) << grid[i][0]
              << "║ " << std::setw(col_width - 1) << grid[i][1]
              << "║ " << std::setw(col_width - 1) << grid[i][2] << "║\n";
    }
    
    // 5. Dòng cạnh dưới cùng
    table << "╚" << std::string(col0_width, '═') << "╩" << std::string(col_width, '═') << "╩" << std::string(col_width, '═') << "╩" << std::string(col_width, '═') << "╝\n";

    // In kết quả trực tiếp ra màn hình Console
    std::cout << "\n" << table.str();

    // Xuất kết quả ra file dữ liệu benchmark.txt
    std::ofstream outFile("benchmark.txt");
    if (outFile.is_open()) {
        outFile << table.str();
        outFile.close();
        std::cout << "\n[Thanh cong] Da xuat ket qua ra file 'benchmark.txt'!" << std::endl;
    } else {
        std::cerr << "\n[Loi] Khong the tao hoac ghi file 'benchmark.txt'." << std::endl;
    }

    return 0;
}
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
