# 🧠 DSALab — Cấu Trúc Dữ Liệu & Giải Thuật (C++)

<div align="center">

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge)
![Chapters](https://img.shields.io/badge/Chapters-6-blueviolet?style=for-the-badge)

**Dự án học liệu C++ toàn diện về Cấu trúc Dữ liệu và Giải thuật**  
*Dựa trên giáo trình — Cao đẳng Công Thương TP.HCM · 2025*

[📖 Lý thuyết](#-nội-dung-từng-chương) · [💻 Cài đặt](#️-cài-đặt--chạy) · [🗂 Cấu trúc](#-cấu-trúc-dự-án) · [🤝 Đóng góp](#-đóng-góp)

</div>

---

## 📌 Giới Thiệu

**DSALab** là kho học liệu mã nguồn mở về **Cấu trúc Dữ liệu và Giải thuật (DSA)** viết bằng C++17, gồm:

- ✅ **6 chương** với lý thuyết chi tiết + code mẫu đầy đủ comment
- ✅ **Bài tập có lời giải** từ cơ bản đến nâng cao
- ✅ **5 ứng dụng thực tế** minh họa cách dùng DSA
- ✅ Chuẩn GitHub: cấu trúc rõ ràng, Makefile, README đầy đủ

---

## 🗂 Cấu Trúc Dự Án

```
DSALab/
│
├── 📁 src/
│   ├── Utils/                         # Hàm tiện ích dùng chung
│   ├── Chapter1_Overview/             # Tổng quan CTDL & GT
│   ├── Chapter2_SearchSort/           # Tìm kiếm & Sắp xếp
│   ├── Chapter3_LinkedList/           # Danh sách liên kết, Stack, Queue
│   ├── Chapter4_Tree/                 # Cây nhị phân, BST
│   ├── Chapter5_Graph/                # Đồ thị (BFS, DFS, Dijkstra, ...)
│   └── Chapter6_DynamicProgramming/   # Quy hoạch động
│
├── 📁 docs/                           # Tài liệu lý thuyết Markdown
│   ├── Chapter1_Theory.md
│   ├── Chapter2_Theory.md
│   ├── Chapter3_Theory.md
│   ├── Chapter4_Theory.md
│   ├── Chapter5_Theory.md
│   └── Chapter6_Theory.md
│
├── 📁 tests/                          # Test cases
├── 📁 assets/                         # Hình ảnh, diagram
├── Makefile
└── README.md
```

---

## 📖 Nội Dung Từng Chương

| # | Chương | Nội Dung Chính | Độ Phức Tạp |
|---|--------|----------------|-------------|
| 1 | [Tổng Quan](docs/Chapter1_Theory.md) | Kiểu dữ liệu, CTDL, BigO | O(1) → O(2ᴺ) |
| 2 | [Tìm Kiếm & Sắp Xếp](docs/Chapter2_Theory.md) | Linear/Binary Search, 5 Sort | O(N) → O(N log N) |
| 3 | [Danh Sách Liên Kết](docs/Chapter3_Theory.md) | DSLK đơn, Stack, Queue | O(1) → O(N) |
| 4 | [Cấu Trúc Cây](docs/Chapter4_Theory.md) | Binary Tree, BST, Traversal | O(log N) → O(N) |
| 5 | [Đồ Thị](docs/Chapter5_Theory.md) | BFS, DFS, Dijkstra, MST | O(V+E) → O(V²) |
| 6 | [Quy Hoạch Động](docs/Chapter6_Theory.md) | Memoization, Tabulation | O(N) → O(N²) |

---

## ⚙️ Cài Đặt & Chạy

### Yêu cầu
- **Compiler:** g++ 9+ (C++17) hoặc MSVC / Clang
- **OS:** Linux, macOS, Windows (MinGW/WSL)
- **IDE gợi ý:** VS Code, CLion, Dev-C++, Code::Blocks

### Clone dự án
```bash
git clone https://github.com/CocAgent/DSALab.git
cd DSALab
```

### Biên dịch bằng Makefile
```bash
make all        # Biên dịch tất cả chương
make ch1        # Biên dịch chương 1
make ch2        # Biên dịch chương 2
make ch3        # Biên dịch chương 3
make ch4        # Biên dịch chương 4
make ch5        # Biên dịch chương 5
make ch6        # Biên dịch chương 6
make apps       # Biên dịch ứng dụng tổng hợp
make clean      # Xóa file binary
make test       # Chạy tất cả
```

### Biên dịch thủ công
```bash
# Ví dụ biên dịch chương 5
g++ -std=c++17 -Wall src/Chapter5_Graph/Chapter5_Graph.cpp -o bin/ch5
./bin/ch5
```

### Dùng IDE
1. Mở từng file `.cpp` trong IDE
2. Nhấn **Build & Run** (F9 / F5 / Ctrl+F5)

---

## 🚀 Nhanh Bắt Đầu

```bash
# Chạy thử demo tất cả
make test

# Hoặc từng chương
./bin/ch1    # Tổng quan CTDL & GT
./bin/ch2    # Tìm kiếm & Sắp xếp  
./bin/ch3    # Danh sách liên kết
./bin/ch4    # Cây nhị phân & BST
./bin/ch5    # Đồ thị
./bin/ch6    # Quy hoạch động
./bin/apps   # Ứng dụng tổng hợp
```

---

## 🧩 Tóm Tắt Giải Thuật

### ⏱ Bảng So Sánh Độ Phức Tạp

| Giải Thuật | Best | Average | Worst | Space |
|------------|------|---------|-------|-------|
| Linear Search | O(1) | O(N) | O(N) | O(1) |
| Binary Search | O(1) | O(log N) | O(log N) | O(1) |
| Bubble Sort | O(N) | O(N²) | O(N²) | O(1) |
| Selection Sort | O(N²) | O(N²) | O(N²) | O(1) |
| Insertion Sort | O(N) | O(N²) | O(N²) | O(1) |
| Quick Sort | O(N log N) | O(N log N) | O(N²) | O(log N) |
| Heap Sort | O(N log N) | O(N log N) | O(N log N) | O(1) |
| BFS / DFS | — | O(V+E) | O(V+E) | O(V) |
| Dijkstra | — | O((V+E) log V) | O(V²) | O(V) |
| DP Fibonacci | — | O(N) | O(N) | O(N) |
| DP Knapsack | — | O(N·W) | O(N·W) | O(N·W) |

---

## 🤝 Đóng Góp

Mọi đóng góp đều được chào đón!

1. Fork dự án
2. Tạo branch mới: `git checkout -b feature/ten-tinh-nang`
3. Commit: `git commit -m "feat: thêm tính năng X"`
4. Push: `git push origin feature/ten-tinh-nang`
5. Tạo Pull Request

### Convention đặt tên
- **Branch:** `feature/`, `fix/`, `docs/`
- **Commit:** `feat:`, `fix:`, `docs:`, `refactor:`
- **Hàm C++:** PascalCase — `TimKiemNhiPhan()`
- **Biến:** camelCase — `soNut`, `chieuCao`

---

## 📚 Tài Liệu Tham Khảo

- 📘 *Introduction to Algorithms* — CLRS (Cormen et al.)
- 📗 *Data Structures and Algorithm Analysis* — Mark Allen Weiss  
- 📙 *Competitive Programmer's Handbook* — Antti Laaksonen  
- 📕 Giáo trình *Cấu trúc Dữ liệu & Giải thuật* — ThS. Trần Anh Khoa, ThS. Hồ Diên Lợi

---

## 📄 Giấy Phép

Dự án sử dụng **[MIT License](LICENSE)** — Tự do sử dụng, chia sẻ và chỉnh sửa với điều kiện giữ nguyên thông tin tác giả.

---

<div align="center">

Made with ❤️ · DSALab · 2025

*"Bad programmers worry about the code. Good programmers worry about data structures."*  
— Linus Torvalds

</div>
