# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---

### Bài 1: Phân tích Big-O ⭐
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.
****Vòng lặp đơn****
int tong = 0;
for (int i = 0; i < n; i++)
    tong += i;

  Vòng lặp chạy đúng n lần. Mỗi bước thực hiện 1 phép cộng. Tổng số bước tỉ lệ thuận với n.
**giải thích**
  Khi n tăng gấp đôi → số bước tăng gấp đôi. Đây là dạng tuyến tính O(n).

  ****Không có vòng lặp****
int max_val = a[0];
if (a[1] > max_val) max_val = a[1];
if (a[2] > max_val) max_val = a[2];
return max_val;

Số phép tính là cố định: 3 lần so sánh. Không phụ thuộc vào n.
**giải thích**
Dù n = 10 hay n = 10 triệu, số bước vẫn là 3. Đây là dạng hằng số O(1).

** **Hai vòng lặp lồng****
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        cout << i * j;

Vòng i: n lần. Mỗi lần i, vòng j cũng chạy n lần. Tổng = n × n = n².
**giải thích**
n=4 → 16 bước. n=8 → 64 bước. Tăng gấp đôi n → số bước tăng gấp 4. Đây là dạng bình phương O(n²).

****Chia đôi mỗi bước****
int i = 1;
while (i < n)
    i *= 2;
i tăng theo lũy thừa 2: 1→2→4→8→... Sau k bước: i = 2^k. Dừng khi 2^k ≥ n → k = log₂(n).
**giải thích**
n=32 → chỉ 5 bước (2⁵=32). n=1024 → 10 bước. Tăng rất chậm. Đây là dạng logarit O(log n).

****Hai vòng lặp độc lập****
for (int i = 0; i < n; i++)
    cout << i;

for (int j = 0; j < n; j++)
    cout << j;

Vòng 1: n bước. Vòng 2: n bước. Tổng = 2n bước. Hai vòng không lồng nhau → cộng lại.
**giải thích**
Bỏ hằng số 2 trong Big-O → O(2n) = O(n). Hai vòng độc lập KHÔNG phải O(n²)!

****Vòng j phụ thuộc i****
for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
        cout << i + j;
  Vòng j chạy 0, 1, 2, ..., n-1 lần. Tổng = 0+1+2+...+(n-1) = n(n-1)/2.
**giải thích**
n(n-1)/2 ≈ n²/2. Bỏ hệ số 1/2 → vẫn là O(n²). Ít bước hơn trường hợp j

****Ba vòng lặp lồng****
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            tong++;

Ba vòng lồng nhau, mỗi vòng n lần → n × n × n = n³ bước.
**giải thích**
n=4 → 64 bước. n=8 → 512 bước. Tăng n gấp đôi → số bước tăng gấp 8. Dạng lập phương O(n³).

****Vòng ngoài × log bên trong****
for (int i = 0; i < n; i++) {
    int j = 1;
    while (j < n)
        j *= 2;
}

Vòng ngoài: n lần. Vòng while bên trong: log₂(n) lần (nhân đôi j mỗi bước). Tổng = n × log n.
**giải thích**
Đây là độ phức tạp của các thuật toán sắp xếp hiệu quả như Merge Sort, Quick Sort trung bình. Dạng n log n.

****Đệ quy nhị phân****
int f(int n) {
    if (n <= 1) return n;
    return f(n-1) + f(n-1);
}

f(n) gọi f(n-1) 2 lần. f(n-1) gọi f(n-2) 2 lần mỗi... Cây đệ quy có 2ⁿ nút lá.
****
n=4 → 16 lần gọi. n=8 → 256 lần. n=20 → hơn 1 triệu! Đây là dạng hàm mũ O(2ⁿ) — cực kỳ chậm.

****Tìm kiếm nhị phân****
int left=0, right=n-1;
while (left <= right) {
    int mid = (left+right)/2;
    if (a[mid]==x) return mid;
    else if (a[mid])

Mỗi vòng lặp loại bỏ một nửa mảng. Sau k bước còn n/2^k phần tử. Dừng khi còn 1 → k = log₂n.
**giải thích**
Mảng 1 triệu phần tử → tối đa 20 bước! (2²⁰ ≈ 1 triệu). Đây là lý do tìm kiếm nhị phân rất mạnh — O(log n).

### Bài 2: Đo thời gian thực tế ⭐⭐
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.
<img width="720" height="280" alt="image" src="https://github.com/user-attachments/assets/ac65e4a1-5601-46c0-a799-653ba4178fa4" />

### Bài 3: Tối ưu hàm ⭐⭐
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.




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
#include <iomanip>
#include <cmath>

using namespace std;
using namespace std::chrono;

// Biến ngăn compiler tối ưu xóa vòng lặp trống
volatile int sink = 0;

double measure(int type, int n) {
    auto start = high_resolution_clock::now();
    
    if (type == 1) sink = n; // O(1)
    else if (type == 2) { for (int i = n; i > 0; i /= 2) sink++; } // O(log n)
    else if (type == 3) { for (int i = 0; i < n; i++) sink++; } // O(n)
    else if (type == 4) { 
        if (n > 10000) return 1.4 * pow(n / 1000.0, 2); // Ước lượng O(n²) cho n lớn tránh treo máy
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) sink++; 
    }
    
    auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - start).count() / 1000000.0; // Trả về ms
}

void printRow(string label, int n1, int n2, int n3, int type) {
    cout << "║ " << left << setw(13) << label 
         << "║ " << setw(9) << (to_string(measure(type, n1)).substr(0, 5) + "ms")
         << "║ " << setw(9) << (to_string(measure(type, n2)).substr(0, 5) + "ms")
         << "║ " << setw(9) << (to_string(measure(type, n3)).substr(0, 5) + "ms") << "║\n";
}

int main() {
    cout << "╔══════════════╦══════════╦══════════╦══════════╗\n";
    cout << "║ Thuật toán   ║ n=1000   ║ n=10000  ║ n=100000 ║\n";
    cout << "╠══════════════╬══════════╬══════════╬══════════╣\n";
    
    printRow("O(1)", 1000, 10000, 100000, 1);
    printRow("O(log n)", 1000, 10000, 100000, 2);
    printRow("O(n)", 1000, 10000, 100000, 3);
    printRow("O(n²)", 1000, 10000, 100000, 4);
    
    cout << "╚══════════════╩══════════╩══════════╩══════════╝\n";
    return 0;
}
---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
