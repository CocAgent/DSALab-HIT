# 🎬 HỆ THỐNG ĐẶT VÉ RẠP PHIM (MOVIE BOOKING SYSTEM)

## 📌 Giới thiệu đề tài

Hệ thống đặt vé rạp phim là một ứng dụng mô phỏng thực tế việc đặt vé xem phim tại rạp.

Người dùng có thể:
- Xem danh sách phim
- Chọn ghế ngồi trong rạp
- Đặt vé xem phim
- Hủy vé (Undo thao tác)
- Tìm kiếm phim theo ID

---

## 🎯 Mục tiêu của dự án

- Áp dụng các cấu trúc dữ liệu đã học vào bài toán thực tế
- Hiểu cách tổ chức dữ liệu trong hệ thống
- Xây dựng tư duy giải quyết bài toán

---

## 🧠 Cấu trúc dữ liệu sử dụng

| Cấu trúc dữ liệu | Ứng dụng |
|------------------|----------|
| Mảng 2 chiều (Array 2D) | Quản lý sơ đồ ghế ngồi |
| Vector | Lưu danh sách phim |
| Hash Map (unordered_map) | Tìm kiếm phim nhanh |
| Stack | Hủy (Undo) thao tác đặt vé |
| Queue | Mô phỏng hàng đợi đặt vé |

---

## ⚙️ Chức năng chính

### 🎬 Quản lý phim
- Thêm phim mới
- Hiển thị danh sách phim

### 🪑 Quản lý ghế
- Hiển thị sơ đồ ghế rạp phim
- Ghế trống và ghế đã đặt

### 🎟️ Đặt vé
- Chọn ghế theo hàng và cột
- Kiểm tra trạng thái ghế

### ↩️ Hủy vé
- Sử dụng Stack để undo thao tác đặt gần nhất

### 🔎 Tìm kiếm phim
- Tìm phim theo ID bằng Hash Map

---

## 🧾 Cách chạy chương trình

### 💻 C++
```bash
g++ main.cpp -o app
./app