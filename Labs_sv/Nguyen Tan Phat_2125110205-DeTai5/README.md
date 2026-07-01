# 🎮 PROJECT: MAZE GAME (C++17)
> **Môn:** Cấu Trúc Dữ Liệu & Giải Thuật | **GV:** TVS

## 📌 Các tính năng chính
* **Sinh mê cung:** Tự động tạo mê cung ngẫu nhiên không bao giờ kẹt đường (Recursive Backtracker).
* **Play Mode:** Di chuyển `P` bằng `W-A-S-D`, bấm `Q` để thoát (`<conio.h>`).
* **Auto Solve:** Tự giải bằng BFS (ký hiệu `.`) và DFS (ký hiệu `*`).
* **Analytics:** So sánh số bước di chuyển (chi phí) giữa BFS và DFS.

---

## 🛠 Cấu trúc dữ liệu áp dụng (Thỏa mãn >= 3)
1. **Mảng 2 chiều (`vector<vector<char>>`)**: Lưu ma trận lưới mê cung (Tường `#`, đường trống).
2. **Hàng đợi (`std::queue`)**: Phục vụ thuật toán **BFS** tìm đường ngắn nhất.
3. **Ngăn xếp (`std::stack`)**: Phục vụ thuật toán **DFS** tìm đường tự động.

---

## 💻 Cách biên dịch và Chạy (Windows)
```bash
# Biên dịch
g++ -std=c++17 main.cpp functions.cpp -o MazeGame.exe

# Chạy game
./MazeGame.exe