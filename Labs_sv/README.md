# 🎮 Maze Game (C++ CLI Project)

## 📝 Giới thiệu
Chương trình mô phỏng trò chơi mê cung trên Terminal (CLI) được viết bằng ngôn ngữ C++. Ứng dụng cho phép tạo mê cung ngẫu nhiên và cung cấp các công cụ giải mê cung tự động dựa trên các thuật toán tìm kiếm phổ biến.

---

## 🛠 Cấu trúc dữ liệu sử dụng
Dự án áp dụng các cấu trúc dữ liệu cốt lõi sau để tối ưu hóa hiệu suất:
* **Stack (Ngăn xếp):** Sử dụng trong thuật toán DFS để tạo mê cung và tìm đường theo chiều sâu.
* **Queue (Hàng đợi):** Sử dụng trong thuật toán BFS để tìm kiếm đường đi ngắn nhất giữa hai điểm.
* **Mảng 2 chiều (2D Array):** Được dùng để quản lý và lưu trữ bản đồ mê cung dưới dạng lưới tọa độ.

---

## 🚀 Thuật toán triển khai
1. **DFS (Recursive Backtracker):** - Dùng để khởi tạo mê cung ngẫu nhiên, đảm bảo mọi vị trí đều có thể kết nối.
   - Dùng để giải mê cung (không cam kết đường ngắn nhất).
2. **BFS (Breadth-First Search):** - Tìm kiếm theo chiều rộng để tìm ra **đường đi ngắn nhất** từ điểm bắt đầu đến đích.

---

## 💻 Hướng dẫn Biên dịch và Chạy
Sử dụng trình biên dịch g++ hỗ trợ chuẩn C++17 trở lên:

```bash
# Biên dịch chương trình
g++ -std=c++17 src/main.cpp src/maze.cpp src/player.cpp src/solver.cpp -o maze_game

# Chạy ứng dụng
./maze_game

## ✨ Chức năng chính
- [x] **Menu điều hướng:** Giao diện Terminal trực quan, dễ sử dụng.
- [x] **Tạo mê cung ngẫu nhiên:** Sử dụng thuật toán DFS đảm bảo luôn có lối thoát.
- [x] **Chế độ Manual:** Người chơi tự do khám phá và di chuyển bằng phím W/A/S/D.
- [x] **Giải thuật tự động:** Tích hợp BFS và DFS để tìm đường về đích.
- [x] **Phân tích thuật toán:** So sánh độ dài đường đi và hiệu quả giữa BFS & DFS.

## 🧪 Test cases (Kịch bản kiểm thử)
* **Kiểm tra Khởi tạo:**
    * Mê cung sinh ra không có vùng bị cô lập.
    * Kích thước mê cung thay đổi đúng theo input của người dùng.
* **Kiểm tra Logic Game:**
    * Người chơi không thể đi xuyên qua các bức tường (`#`).
    * Trò chơi kết thúc chính xác khi tọa độ người chơi trùng với đích (`E`).
* **Kiểm tra Thuật toán:**
    * **BFS:** Phải luôn trả về con đường có số bước di chuyển ít nhất.
    * **DFS:** Phải tìm được đường ra ngay cả trong mê cung có nhiều ngõ cụt.
* **Kiểm tra Ngoại lệ:**
    * Xử lý khi người dùng nhập sai phím điều khiển hoặc kích thước âm.


Cấu Trúc thư mục: 
/
├── src/
│   ├── main.cpp       - Menu chính và điều khiển luồng game
│   ├── maze.cpp/h     - Xử lý logic khởi tạo và vẽ mê cung
│   ├── player.cpp/h   - Xử lý tọa độ và bước đi của người chơi
│   └── solver.cpp/h   - Cài đặt thuật toán BFS và DFS
├── tests/
│   └── test_cases.cpp - Các kịch bản kiểm thử chức năng
└── README.md          - Tài liệu hướng dẫn dự án

