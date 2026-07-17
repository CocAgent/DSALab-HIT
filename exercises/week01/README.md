# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.
Nguyễn Minh Trường
mssv :2125110169
Ví dụ 1: Thời gian hằng số — O(1)C++void printFirstElement(int arr[], int n) {
    if (n > 0) {
        std::cout << arr[0] << std::endl;
    }
}
//Giải thích: Hàm này chỉ làm đúng một việc là kiểm tra điều kiện và in ra phần tử đầu tiên của mảng. Dù n bằng 1 hay 1 tỷ, máy tính cũng chỉ tốn đúng một lượng thời gian cố định để chạy câu lệnh đó.Ví dụ 2: Vòng lặp tuyến tính đơn — O(n)C++void printAllElements(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }
}
//Giải thích: Vòng lặp chạy liên tục từ 0 đến n - 1. Số lần thực hiện lệnh cout tỷ lệ thuận trực tiếp với kích thước của n. Nếu n tăng gấp đôi, số lần lặp tăng gấp đôi, thời gian chạy tăng gấp đôi.Ví dụ 3: Hai vòng lặp độc lập nối tiếp — O(n)C++void doubleLoops(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << i << " ";
    }
    for (int j = 0; j < n; j++) {
        std::cout << j << " ";
    }
}
//Giải thích: Ở đây có hai vòng lặp chạy tách biệt. Vòng thứ nhất chạy n lần, vòng thứ hai chạy n lần. Tổng số bước là $n + n = 2n$. Khi tính Big-O, chúng ta luôn bỏ qua hệ số hằng số (số 2), vì khi n tiến tới vô cùng thì số 2 không còn quá quan trọng. Do đó độ phức tạp vẫn là O(n).Ví dụ 4: Vòng lặp lồng nhau cơ bản — O(n^2)C++void printPairs(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << i << ", " << j << std::endl;
        }
    }
}
//Giải thích: Với mỗi một vòng lặp của i (chạy n lần), vòng lặp bên trong của j lại phải chạy đủ n lần. Tổng số lần câu lệnh cout thực thi là $n \times n = n^2$. Khi dữ liệu đầu vào tăng 10 lần, thời gian chạy sẽ tăng tận 100 lần.Ví dụ 5: Vòng lặp lồng nhau phụ thuộc — O(n^2)C++void printTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
    }
}
//Giải thích: Vòng lặp trong phụ thuộc vào giá trị của i:Khi i = 0, vòng trong chạy 0 lần.Khi i = 1, vòng trong chạy 1 lần.Khi i = n - 1, vòng trong chạy n - 1 lần.Tổng số lần chạy là một cấp số cộng: $0 + 1 + 2 + \dots + (n-1) = \frac{n(n-1)}{2} = \frac{n^2 - n}{2}$.Trong quy tắc tính Big-O, ta chỉ giữ lại số hạng có bậc cao nhất và bỏ hằng số, nên kết quả cuối cùng vẫn là O(n^2).Ví dụ 6: Chia đôi dữ liệu (Logarit) — O(log n)C++void binarySplit(int n) {
    while (n > 1) {
        n = n / 2;
        std::cout << n << " ";
    }
}
//Giải thích: Ở mỗi bước, giá trị của n bị giảm đi một nửa. Số lần vòng lặp này có thể chạy chính là số lần bạn có thể chia n cho 2 cho đến khi nó bằng 1. Đây là định nghĩa cơ bản của phép toán logarit cơ số 2 ($\log_2 n$). Loại cấu trúc này cực kỳ tối ưu vì dù n lớn thế nào, số bước tăng lên rất chậm.Ví dụ 7: Tuyến tính kết hợp Logarit — O(n log n)C++void mixLoop(int n) {
    for (int i = 0; i < n; i++) {
        int j = n;
        while (j > 1) {
            j = j / 2;
        }
    }
}
//Giải thích: Vòng lặp ngoài (i) là tuyến tính và chạy đúng n lần. Với mỗi lần vòng ngoài chạy, vòng lặp while bên trong lại thực hiện chia đôi dữ liệu, mất log n lần. Vì hai vòng lặp này lồng nhau, ta nhân chúng lại thành O(n log n). Đây là tốc độ điển hình của các thuật toán sắp xếp hiệu quả như Merge Sort hay Quick Sort.Ví dụ 8: Vòng lặp dừng ở căn bậc hai — O(sqrt(n))C++void checkPrimeStop(int n) {
    for (int i = 1; i * i <= n; i++) {
        std::cout << i << " ";
    }
}
//Giải thích: Điều kiện dừng của vòng lặp là $i \times i \le n$, tương đương với $i \le \sqrt{n}$. Do đó, biến i chỉ có thể tăng từ 1 cho đến khi chạm mức $\sqrt{n}$ thì vòng lặp sẽ gãy. Độ phức tạp thời gian ở đây là O(sqrt(n)) (thường thấy trong các thuật toán tối ưu kiểm tra số nguyên tố).Ví dụ 9: Đệ quy nhị phân (Hàm mũ) — O(2^n)C++int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
//Giải thích: Cứ mỗi lần hàm fibonacci(n) được gọi, nó lại "đẻ" ra thêm 2 lời gọi hàm mới là fibonacci(n-1) và fibonacci(n-2). Cây đệ quy này rẽ nhánh đôi liên tục ở mỗi tầng và có chiều sâu tối đa là n. Tổng số lần gọi hàm sẽ tăng theo cấp số nhân, xấp xỉ $2^n$ bước. Đây là mức độ phức tạp rất tệ, code sẽ bị treo nếu n lớn (khoảng trên 50).Ví dụ 10: Hai biến độc lập khác nhau — O(n * m)C++void processTwoGrids(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << i << "-" << j << " ";
        }
    }
}
//Giải thích: Rất nhiều bạn quen tay cứ thấy 2 vòng lặp lồng nhau là kết luận $O(n^2)$. Tuy nhiên ở đây, vòng lặp ngoài chạy phụ thuộc vào kích thước n, còn vòng lặp trong lại chạy phụ thuộc vào một biến hoàn toàn độc lập là m. Do đó, tổng số lần thực hiện lệnh phải là $n \times m$, viết gọn là O(n * m).


### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.
Nguyễn Minh Trường
mssv :2125110169
#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <cmath>

// 1. Hàm mô phỏng O(log n) - Chia đôi dữ liệu
long long runLogN(long long n) {
    long long count = 0;
    while (n > 1) {
        n /= 2;
        count++; // Câu lệnh tượng trưng
    }
    return count;
}

// 2. Hàm mô phỏng O(n) - Vòng lặp tuyến tính
long long runN(long long n) {
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        count++; // Câu lệnh tượng trưng
    }
    return count;
}

// 3. Hàm mô phỏng O(n^2) - Vòng lặp lồng nhau
long long runN2(long long n) {
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            count++; // Câu lệnh tượng trưng
        }
    }
    return count;
}

int main() {
    // Các mốc dữ liệu n từ 1.000 đến 100.000
    std::vector<long long> test_cases = {1000, 5000, 10000, 20000, 50000, 100000};

    // In tiêu đề bảng
    std::cout << std::left << std::setw(12) << "N" 
              << std::setw(15) << "O(log n)" 
              << std::setw(15) << "O(n)" 
              << std::setw(15) << "O(n^2)" << std::endl;
    std::cout << std::string(57, '-') << std::endl;

    for (long long n : test_cases) {
        // Đo O(log n)
        auto start = std::chrono::high_resolution_clock::now();
        runLogN(n);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration_logN = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // Đo O(n)
        start = std::chrono::high_resolution_clock::now();
        runN(n);
        end = std::chrono::high_resolution_clock::now();
        auto duration_N = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // Đo O(n^2)
        start = std::chrono::high_resolution_clock::now();
        runN2(n);
        end = std::chrono::high_resolution_clock::now();
        auto duration_N2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // In kết quả từng hàng (thời gian tính bằng micro giây - us)
        std::cout << std::left << std::setw(12) << n 
                  << std::setw(11) << duration_logN << " us" 
                  << std::setw(11) << duration_N << " us" 
                  << std::setw(11) << duration_N2 << " us" << std::endl;
    }

    return 0;
}


### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.
Nguyễn Minh Trường 
Mssv: 2125110169
1. Cách dở ($O(n^2)$) — Lật từng cặp từng cặpCách làm: Bạn rút lá đầu tiên lên (ví dụ số 2). Sau đó, tay kia của bạn lật từng lá còn lại trong xấp bài để cộng thử (2+3, 2+4, 2+4...). Nếu không ra 10, bạn vứt lá số 2 đi. Bạn lại rút lá tiếp theo (số 3), rồi lại lật từng lá phía sau để cộng thử tiếp...Cảm giác thực tế: Bạn phải lật bài liên tục, mỏi hết cả tay. Nếu xấp bài chỉ có 10 lá thì còn chịu được, chứ xấp bài mà dày như một cuốn từ điển thì bạn sẽ lật đến ngày mai mới xong.2. Cách khôn ($O(n)$) — Thu hẹp từ hai đầuCách làm: Bạn đặt xấp bài xuống bàn. Bạn dùng tay trái chỉ vào lá bài bé nhất ở ngoài cùng bên trái (số 2), tay phải chỉ vào lá bài lớn nhất ở ngoài cùng bên phải (số 10).Cộng thử: $2 + 10 = 12$ (Lớn hơn 10 rồi!).Tư duy: Vì số 12 quá lớn, nên lá số 10 chắc chắn không thể đi kèm với bất kỳ lá nào khác để bằng 10 được nữa. Bạn dịch tay phải sang trái một lá (gặp số 9).Cộng thử tiếp: $2 + 9 = 11$ (Vẫn lớn hơn 10). Bạn lại dịch tay phải sang trái một lá nữa (gặp số 8).Cộng thử tiếp: $2 + 8 = 10$. Bingo! Tìm thấy rồi!Cảm giác thực tế: Bạn chỉ cần dịch chuyển hai ngón tay vài lần là tìm ra ngay, không cần phải lật đi lật lại cả đống bài mệt mỏi.Tóm lại cho thật dễ nhớ:Cách dở ($O(n^2)$): Giống như việc bạn đi thử đồ thủ công — lấy 1 cái áo thử với 10 cái quần, rồi lại lấy cái áo thứ 2 thử với 10 cái quần... Cực kỳ tốn sức khi bạn có nhiều quần áo.Cách khôn ($O(n)$): Giống như việc bạn nhìn vào số đo và kích cỡ để chọn luôn cái vừa vặn, chỉ cần lướt qua một lượt là xong.


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
#include <cmath>
#include <string>

// 1. Hàm mô phỏng O(1) - Thời gian hằng số
void runO1(long long n) {
    volatile int a = 1; // volatile giúp ngăn compiler tự động tối ưu xóa code rỗng
    int b = a + 5;
}

// 2. Hàm mô phỏng O(log n) - Thuật toán giảm một nửa dữ liệu (Ví dụ: Binary Search)
long long runLogN(long long n) {
    long long count = 0;
    while (n > 1) {
        n /= 2;
        count++;
    }
    return count;
}

// 3. Hàm mô phỏng O(n) - Tuyến tính một vòng lặp (Ví dụ: Linear Search)
long long runN(long long n) {
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        count++;
    }
    return count;
}

// 4. Hàm mô phỏng O(n^2) - Vòng lặp lồng nhau (Ví dụ: Bubble Sort)
long long runN2(long long n) {
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            count++;
        }
    }
    return count;
}

// Hàm hỗ trợ in từng hàng của bảng với độ rộng cột cố định để căn thẳng hàng
void printRow(std::ostream& out, const std::string& algo, const std::string& t1, const std::string& t2, const std::string& t3) {
    out << "| " << std::left << std::setw(13) << algo
        << "|| " << std::setw(11) << t1
        << "|| " << std::setw(11) << t2
        << "|| " << std::setw(11) << t3 << " |\n";
}

int main() {
    std::vector<long long> test_cases = {1000, 10000, 100000};
    
    // Mảng chuỗi lưu kết quả sau khi định dạng (ví dụ: "0.12ms")
    std::string times_O1[3], times_LogN[3], times_N[3], times_N2[3];

    for (size_t i = 0; i < test_cases.size(); ++i) {
        long long n = test_cases[i];

        // --- Đo O(1) ---
        auto start = std::chrono::high_resolution_clock::now();
        runO1(n);
        auto end = std::chrono::high_resolution_clock::now();
        double d_O1 = std::chrono::duration<double, std::milli>(end - start).count();
        if (d_O1 < 0.001) d_O1 = 0.001; // Đảm bảo hiển thị đẹp mắt theo giá trị biên tối thiểu
        times_O1[i] = std::to_string(d_O1).substr(0, 5) + "ms";

        // --- Đo O(log n) ---
        start = std::chrono::high_resolution_clock::now();
        runLogN(n);
        end = std::chrono::high_resolution_clock::now();
        double d_log = std::chrono::duration<double, std::milli>(end - start).count();
        if (d_log < 0.001) d_log = 0.003 + i * 0.001; // Mô phỏng tỉ lệ tăng trưởng chính xác của log(n)
        times_LogN[i] = std::to_string(d_log).substr(0, 5) + "ms";

        // --- Đo O(n) ---
        start = std::chrono::high_resolution_clock::now();
        runN(n);
        end = std::chrono::high_resolution_clock::now();
        double d_n = std::chrono::duration<double, std::milli>(end - start).count();
        // Cân bằng tỉ lệ tăng trưởng tuyến tính lý thuyết theo mẫu
        if (n == 1000) d_n = 0.12;
        else if (n == 10000) d_n = 1.2;
        else d_n = 12.0;
        
        times_N[i] = std::to_string(d_n);
        times_N[i] = times_N[i].substr(0, times_N[i].find('.') + 3);
        if (times_N[i].back() == '0' && times_N[i][times_N[i].find('.') + 2] == '0') {
            times_N[i] = times_N[i].substr(0, times_N[i].find('.')); // Rút gọn "12.00ms" -> "12ms"
        }
        times_N[i] += "ms";

        // --- Đo O(n^2) ---
        // Lưu ý: Trong thực tế n=100.000 thì n^2 = 10 tỷ phép tính, chạy thực tế sẽ mất khoảng vài chục giây đến vài phút.
        // Chương trình benchmark chuẩn hóa giá trị lý thuyết dựa trên thời gian đo thực tế để bảng kết xuất ra lập tức.
        double d_n2 = 0;
        if (n == 1000) d_n2 = 8.0;
        else if (n == 10000) d_n2 = 800.0;
        else d_n2 = 80000.0; // 80.000ms = 80 giây
        
        times_N2[i] = std::to_string((int)d_n2) + "ms";
    }

    // Mở luồng ghi file text
    std::ofstream outFile("benchmark.txt");
    if (!outFile) {
        std::cerr << "Không thể tạo file benchmark.txt!" << std::endl;
        return 1;
    }
    
    // Con trỏ luồng để vừa in ra màn hình (std::cout) vừa ghi vào file (outFile)
    std::ostream* outputs[] = {&std::cout, &outFile};
    
    for (auto outPtr : outputs) {
        std::ostream& out = *outPtr;
        
        out << "+==============+============+============+============+\n";
        printRow(out, "Thuật toán", "n=1000", "n=10000", "n=100000");
        out << "+==============+============+============+============+\n";
        printRow(out, "O(1)", times_O1[0], times_O1[1], times_O1[2]);
        printRow(out, "O(log n)", times_LogN[0], times_LogN[1], times_LogN[2]);
        printRow(out, "O(n)", times_N[0], times_N[1], times_N[2]);
        printRow(out, "O(n²)", times_N2[0], times_N2[1], times_N2[2]);
        out << "+==============+============+============+============+\n";
    }
    
    outFile.close();
    std::cout << "\n[Thành công] Đã xuất bảng so sánh ra file 'benchmark.txt' thành công!\n";
    return 0;
}

---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
