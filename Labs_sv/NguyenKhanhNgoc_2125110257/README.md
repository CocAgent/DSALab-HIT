# 📚 Library Mini System (C++ CLI)

## 📌 Mô tả
Ứng dụng quản lý sách đơn giản chạy trên terminal.
Cho phép thêm, tìm kiếm, hiển thị sách và mô phỏng mượn sách.

---

## 🧠 Cấu trúc dữ liệu sử dụng

### 1. BST (Binary Search Tree)
- Lưu danh sách sách
- Tìm kiếm nhanh theo ID
- Độ phức tạp: O(log n)

### 2. Queue
- Lưu danh sách người chờ mượn sách
- Hoạt động FIFO

### 3. Stack
- Lưu lịch sử thao tác
- Dùng để Undo

---

## ⚙️ Compile & Run

```bash
g++ -std=c++17 main.cpp -o app
./app
```

---

## 📋 Chức năng

1. Thêm sách
2. Tìm sách theo ID
3. Hiển thị danh sách sách
4. Mượn sách (vào Queue)
5. Undo thao tác

---

## 🧪 Test Cases

- Thêm và hiển thị sách
- Tìm kiếm sách tồn tại / không tồn tại
- Mượn sách → Queue hoạt động
- Undo thao tác

---

## 📁 Cấu trúc file

main.cpp  
README.md

---

## 🎯 Ghi chú

Phiên bản đơn giản phục vụ học tập DSA.
