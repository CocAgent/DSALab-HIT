# 🎟️ HỆ THỐNG ĐẶT VÉ (C++ CLI)

## 📌 Giới thiệu

Đây là ứng dụng mô phỏng hệ thống đặt vé rạp chiếu phim chạy trên terminal (CLI), được xây dựng bằng C++.

Ứng dụng cho phép:
- Quản lý ghế ngồi
- Đặt vé / hủy vé
- Undo thao tác
- Quản lý hàng chờ ưu tiên (VIP)
- Lưu và đọc dữ liệu từ file

---

## 🧠 Cấu trúc dữ liệu sử dụng

### 1. Mảng 2 chiều (2D Array)
- Dùng để lưu sơ đồ ghế
- Truy cập trực tiếp theo tọa độ (row, col)
- Độ phức tạp: **O(1)**

---

### 2. Stack
- Dùng để lưu lịch sử thao tác (đặt / hủy)
- Hỗ trợ chức năng **Undo**
- Nguyên lý: **LIFO (Last In First Out)**

---

### 3. Priority Queue (Hàng đợi ưu tiên)
- Dùng cho danh sách chờ khi hết ghế
- Khách VIP sẽ được ưu tiên trước
- Độ phức tạp:
  - Thêm: O(log n)
  - Lấy phần tử: O(log n)

---

## ⚙️ Chức năng chính

#### 1.Hiển thị sơ đồ ghế
#### 2.Đặt vé
#### 3.Hủy vé
#### 4.Undo thao tác
#### 5.Thống kê ghế
#### 6.Lưu dữ liệu ra file
#### 7.Đọc dữ liệu từ file
#### 8.Thoát

---

## 🖥️ Giao diện (CLI)

- `[O]` → Ghế trống  
- `[X]` → Ghế đã được đặt  

Ví dụ:
```
0 1 2 3 4
0 [O][O][X][O][O]
1 [O][X][O][O][O]
2 [O][O][O][X][O]
```

---

## ▶️ Cách compile & chạy

### 🔹 Cách 1: Dùng g++ (đúng yêu cầu đề)

```bash
g++ -std=c++17 src/main.cpp src/functions.cpp -o app
./app
```
### 🔹Cách 2: Visual Studio
- Mở project
- Nhấn Ctrl + F5 để chạy
## 🧪 Test Cases
### ✔ Test 1: Đặt ghế thành công
- Input: (1,1)
- Expected: PASS
----------
### ✔ Test 2: Đặt trùng ghế
- Input: đặt 2 lần (1,1)
- Expected: báo lỗi
----------
### ✔ Test 3: Hủy ghế
- Input: hủy ghế đã đặt
- Expected: thành công
----------
### ✔ Test 4: Undo
- Thực hiện đặt ghế → undo
- Expected: ghế trở lại trạng thái ban đầu
----------
### ✔ Test 5: Priority Queue
- Thêm VIP và thường
- Expected: VIP được xử lý trước
----------
## 📂 Cấu trúc project
```
project/
│
├── src/
│   ├── main.cpp
│   ├── functions.cpp
│   └── structures.h
│
├── tests/
│   └── test_cases.cpp
│
└── README.md
```
## 📊 Độ phức tạp (Big-O)
| Chức năng      | Độ phức tạp |
| -------------- | ----------- |
| Đặt ghế        | O(1)        |
| Hủy ghế        | O(1)        |
| Undo           | O(1)        |
| Priority Queue | O(log n)    |
## 💾 Lưu & đọc file
- File: seats.txt
- Lưu trạng thái ghế (đã đặt / chưa)
- Khi mở lại chương trình → có thể load lại dữ liệu
## ⚠️ Hạn chế
- Chưa hỗ trợ nhiều người dùng cùng lúc
- Chưa có giao diện đồ họa (GUI)
- Dữ liệu lưu dạng file đơn giản, chưa dùng database
## 🚀 Hướng phát triển
- Thêm đăng nhập người dùng
- Kết nối database (MySQL / SQLite)
- Xây dựng giao diện GUI
- Triển khai hệ thống online
## 👨‍💻 Tác giả
- Sinh viên: HUỲNH KHIÊM
- Môn học: Cấu trúc dữ liệu & giải thuật
- Giảng viên: TVS