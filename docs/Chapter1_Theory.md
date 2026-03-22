# 📘 Chương 1: Tổng Quan về Cấu Trúc Dữ Liệu & Giải Thuật

> **Mục tiêu:** Hiểu bản chất của CTDL, GT và cách đánh giá chúng qua ký hiệu Big-O.

---

## 1. Kiểu Dữ Liệu (Data Type)

### 1.1 Định Nghĩa

> **Kiểu dữ liệu** là một định danh mà ngôn ngữ lập trình đặt ra để mô tả bản chất của các đối tượng dữ liệu trong bài toán.

Khi làm việc với một KDL cần quan tâm **4 yếu tố**:

| Yếu Tố | Ý Nghĩa | Ví Dụ (`short`) |
|--------|---------|-----------------|
| **Tên KDL** | Từ khóa trong NNLT | `short` |
| **Kích thước** | Số byte bộ nhớ chiếm | 2 byte |
| **Miền giá trị** | Giá trị hợp lệ | `[-32768, 32767]` |
| **Phép toán** | Các phép tính được hỗ trợ | `+`, `-`, `*`, `/`, `%` |

### 1.2 Phân Loại KDL trong C/C++

```
KDL C/C++
│
├── KDL Cơ Sở (Primitive)
│   ├── Ký tự:      char            (1 byte)
│   ├── Số nguyên:  short / int / long / long long
│   ├── Số thực:    float / double / long double
│   └── Luận lý:    bool            (C++ only, 1 byte)
│
└── KDL Cấu Trúc (Derived)
    ├── Mảng (Array)
    ├── Chuỗi (String)
    ├── Con trỏ (Pointer)
    ├── Struct / Union
    └── Class (OOP)
```

### 1.3 Bảng KDL Số Nguyên C++

| Kiểu | Kích thước | Miền giá trị |
|------|-----------|--------------|
| `char` | 1 byte | [-128, 127] |
| `unsigned char` | 1 byte | [0, 255] |
| `short` | 2 byte | [-32,768, 32,767] |
| `unsigned short` | 2 byte | [0, 65,535] |
| `int` | 4 byte | [-2.1B, 2.1B] |
| `unsigned int` | 4 byte | [0, 4.3B] |
| `long long` | 8 byte | [-9.2×10¹⁸, 9.2×10¹⁸] |

### 1.4 Nguyên Tắc Chọn KDL

```
📌 Nguyên tắc:
  - Input  → chọn theo ràng buộc bài toán
  - Output → xem thêm ràng buộc của input
  - Ưu tiên: tiết kiệm bộ nhớ nhưng đủ lớn
```

**Ví dụ:** Tính tổng chữ số của n ∈ [1, 10⁹]
- n → `unsigned int` (4 byte, đủ chứa 10⁹)
- s → `unsigned short` (n có tối đa 10 chữ số, s ≤ 90)

---

## 2. Cấu Trúc Dữ Liệu (Data Structure)

### 2.1 Định Nghĩa

> **Cấu trúc dữ liệu** là cách tổ chức và quản lý các kiểu dữ liệu để phù hợp với từng đối tượng trong bài toán.

### 2.2 Các CTDL Phổ Biến

```
CTDL
│
├── Tuyến tính (Linear)
│   ├── Mảng (Array)          — truy cập O(1), chèn xóa O(N)
│   ├── Danh sách liên kết    — chèn xóa O(1), truy cập O(N)
│   ├── Stack (Ngăn xếp)      — LIFO
│   └── Queue (Hàng đợi)      — FIFO
│
└── Phi tuyến (Non-Linear)
    ├── Cây (Tree)            — phân cấp
    ├── Đồ thị (Graph)        — quan hệ nhiều-nhiều
    └── Bảng băm (Hash Table) — tìm kiếm O(1) trung bình
```

### 2.3 Tiêu Chí Đánh Giá CTDL

1. **Phản ánh đúng thực tế** — điểm số phải là `float`, không phải `int`
2. **Tiết kiệm tài nguyên** — dùng chuỗi động thay vì chuỗi tĩnh khi có thể
3. **Phù hợp với giải thuật** — CTDL tốt → GT đơn giản hơn

---

## 3. Giải Thuật (Algorithm)

### 3.1 Định Nghĩa

> **Giải thuật** là tập hợp hữu hạn các bước, mà sau khi thực hiện cho ra kết quả đúng trong thời gian chấp nhận được.

### 3.2 Đặc Tính Của Giải Thuật

| Đặc Tính | Mô Tả |
|----------|-------|
| **Xác định** | Mỗi bước phải rõ ràng, không mơ hồ |
| **Hữu hạn** | Phải kết thúc sau hữu hạn bước |
| **Đúng đắn** | Cho kết quả đúng với mọi input hợp lệ |
| **Hiệu quả** | Tốn ít tài nguyên (thời gian, bộ nhớ) |
| **Tổng quát** | Áp dụng được cho nhiều bài toán cùng loại |

### 3.3 Mối Liên Hệ CTDL ↔ Giải Thuật

```
CTDL + Giải Thuật = Chương Trình
(Niklaus Wirth — tác giả Pascal)
```

**Kết luận quan trọng:**
> Khi bạn thay đổi CTDL, giải thuật sẽ thay đổi theo. CTDL tốt → GT đơn giản → Code dễ đọc hơn.

---

## 4. Độ Phức Tạp Thuật Toán (Big-O Notation)

### 4.1 Tại Sao Cần Big-O?

Đo lường hiệu quả GT theo **lý thuyết** (độc lập với phần cứng và dữ liệu thử nghiệm).

### 4.2 Các Phân Lớp Độ Phức Tạp

| Ký Hiệu | Tên Gọi | N=10 | N=100 | N=1000 |
|---------|---------|------|-------|--------|
| O(1) | Hằng số | 1 | 1 | 1 |
| O(log N) | Logarit | 3 | 7 | 10 |
| O(N) | Tuyến tính | 10 | 100 | 1,000 |
| O(N log N) | N-log-N | 33 | 664 | 9,966 |
| O(N²) | Bình phương | 100 | 10,000 | 1,000,000 |
| O(N³) | Lập phương | 1,000 | 1,000,000 | 10⁹ |
| O(2ᴺ) | Hàm mũ | 1,024 | 10³⁰ | 10³⁰¹ |

### 4.3 Biểu Đồ Tăng Trưởng

```
Tốc độ tăng (từ chậm đến nhanh):
O(1) < O(log N) < O(N) < O(N log N) < O(N²) < O(N³) < O(2ᴺ)
 ✅✅✅       ✅✅✅        ✅✅          ✅✅          ⚠️          ❌          ❌❌
```

### 4.4 Ví Dụ Minh Họa

```cpp
// O(1) — Truy cập mảng
int x = a[5];

// O(log N) — Tìm kiếm nhị phân
// Mỗi bước chia đôi không gian tìm kiếm

// O(N) — Duyệt mảng
for (int i = 0; i < n; i++) { ... }

// O(N log N) — Merge Sort / Quick Sort

// O(N²) — 2 vòng lặp lồng nhau
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) { ... }

// O(2ᴺ) — Đệ quy Fibonacci ngây thơ
int fib(int n) { return fib(n-1) + fib(n-2); }
```

---

## 5. Bài Tập Tự Luyện

### Mức Cơ Bản
1. Cho n ∈ [1, 10⁹], tính tổng các chữ số — đánh giá KDL và độ phức tạp.
2. Viết hàm đếm số lần xuất hiện của phần tử x trong mảng.
3. Chứng minh tìm kiếm tuần tự có O(N/2) trung bình.

### Mức Nâng Cao
4. So sánh 2 đoạn code và chỉ ra đoạn nào có độ phức tạp tốt hơn.
5. Thiết kế CTDL lưu thông tin sinh viên, đảm bảo 3 tiêu chí đánh giá.
6. Tại sao O(N!) không thực tế? Tính N! với N=12.

---

## 6. Câu Hỏi Trắc Nghiệm

1. KDL nào phù hợp lưu điểm môn học (0.0 → 10.0)?  
   A. `int` | B. `float` ✅ | C. `char` | D. `bool`

2. Giải thuật có vòng lặp lồng 3 tầng có độ phức tạp?  
   A. O(N) | B. O(N²) | C. O(N³) ✅ | D. O(log N)

3. Câu nào SAI về giải thuật?  
   A. Phải hữu hạn | B. Phải đúng | C. Có thể vô hạn bước ✅ | D. Phải hiệu quả

---

*📌 File code: [`src/Chapter1_Overview/Chapter1_Overview.cpp`](../src/Chapter1_Overview/Chapter1_Overview.cpp)*
