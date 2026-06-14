# 🎮 Maze Game CLI — Cấu Trúc Dữ Liệu & Giải Thuật

## 📌 Giới thiệu

Maze Game là ứng dụng chạy trên terminal (CLI) cho phép người chơi di chuyển trong mê cung để tìm đường từ điểm bắt đầu (`S`) đến điểm kết thúc (`E`).

Ứng dụng được xây dựng bằng C++ và áp dụng các cấu trúc dữ liệu đã học trong môn **Cấu Trúc Dữ Liệu & Giải Thuật**.

---

## 🎯 Mục tiêu

* Di chuyển nhân vật (`P`) từ `S` đến `E`
* Tránh tường (`#`)
* Tìm đường tối ưu trong mê cung

---

## 🧠 Cấu trúc dữ liệu sử dụng

| Cấu trúc | Vai trò                                         |
| -------- | ----------------------------------------------- |
| 2D Array | Lưu trữ mê cung                                 |
| Queue    | BFS tìm đường ngắn nhất                         |
| Stack    | DFS (có thể dùng để tạo mê cung / backtracking) |

---

## ⚙️ Chức năng chính

* Hiển thị mê cung ASCII trên terminal
* Điều khiển người chơi bằng bàn phím
* Kiểm tra va chạm tường
* Xác định khi người chơi đến đích
* (Có thể mở rộng) BFS tự động tìm đường
* (Có thể mở rộng) Random mê cung

---

## 🎮 Hướng dẫn chơi

### Ký hiệu:

* `#` : Tường
* `.` : Đường đi
* `S` : Điểm bắt đầu
* `E` : Điểm kết thúc
* `P` : Người chơi

### Điều khiển:

* `W` : Lên
* `S` : Xuống
* `A` : Trái
* `D` : Phải

👉 Mục tiêu: Di chuyển từ `S` đến `E`

---

## ▶️ Cách compile và chạy

### Bước 1: Compile

```bash
g++ -std=c++17 main.cpp -o game
```

### Bước 2: Chạy

```bash
./game
```

---

## 📂 Cấu trúc project

```
MazeGame/
├── src/
│   └── main.cpp
├── README.md
```

---

## 🧪 Test cases

1. Di chuyển bình thường trong mê cung
2. Đụng tường → không đi được
3. Đi đến `E` → game kết thúc
4. Nhập ký tự không hợp lệ
5. Test với nhiều đường đi khác nhau

---

## 🚀 Hướng phát triển thêm

* Tạo mê cung ngẫu nhiên (DFS)
* Giải mê cung bằng BFS (auto solve)
* So sánh BFS và DFS
* Thêm level khó dễ
* Đếm số bước đi

---

## 📊 Độ phức tạp

* Duyệt mê cung: **O(n × m)**
* BFS tìm đường: **O(n × m)**

---

## 👨‍💻 Tác giả

* Họ tên: Nguyễn Ngô Huy Thịnh
* MSSV: 2125110264
* Môn học: Cấu Trúc Dữ Liệu & Giải Thuật

---

## 📌 Ghi chú

* Chương trình chạy trên môi trường CLI (Windows/Linux)
* Không sử dụng thư viện ngoài

---
