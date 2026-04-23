# 🎓 HỆ THỐNG QUẢN LÝ SINH VIÊN (PHP + MySQL)

## 📌 Giới thiệu

Đây là hệ thống web quản lý sinh viên được xây dựng bằng **PHP, MySQL và HTML/CSS (Bootstrap)**.
Hệ thống hỗ trợ quản lý thông tin sinh viên với đầy đủ chức năng CRUD, xác thực đăng nhập và các tính năng nâng cao.

---

## 🚀 Chức năng chính

### 🔐 Xác thực

* Đăng nhập (Login)
* Đăng xuất (Logout)
* Sử dụng Session để quản lý người dùng

### 📋 Quản lý sinh viên (CRUD)

* ➕ Thêm sinh viên
* 📄 Xem danh sách sinh viên
* ✏️ Sửa thông tin sinh viên
* ❌ Xóa sinh viên

### 🔍 Tìm kiếm

* Tìm theo:

  * Tên
  * MSSV
  * Lớp

### 📄 Phân trang

* Hiển thị danh sách theo từng trang
* Giúp tối ưu khi dữ liệu lớn

### 🖼️ Upload ảnh

* Upload ảnh đại diện sinh viên
* Lưu ảnh trong thư mục `uploads/`

### 📊 Thống kê

* Hiển thị tổng số sinh viên

### 📥 Xuất Excel

* Xuất danh sách sinh viên ra file `.xls`

---

## 🏗️ Công nghệ sử dụng

* **Backend:** PHP
* **Frontend:** HTML, CSS, Bootstrap
* **Database:** MySQL
* **Server:** XAMPP

---

## 📁 Cấu trúc thư mục

```
webquanlysinhvien/
│
├── config/
│   └── database.php
│
├── uploads/
│
├── index.php
├── add.php
├── edit.php
├── delete.php
├── login.php
├── logout.php
├── export.php
│
└── README.md
```

---

## 🧩 Cơ sở dữ liệu

### Database: `qlsv`

#### Bảng `users`

| Trường   | Kiểu dữ liệu |
| -------- | ------------ |
| id       | INT          |
| username | VARCHAR      |
| password | VARCHAR      |

#### Bảng `sinhvien`

| Trường   | Kiểu dữ liệu |
| -------- | ------------ |
| id       | INT          |
| mssv     | VARCHAR      |
| name     | VARCHAR      |
| lop      | VARCHAR      |
| ngaysinh | DATE         |
| avatar   | VARCHAR      |

---

## ⚙️ Hướng dẫn cài đặt

### Bước 1: Clone hoặc copy project

```
C:\xampp\htdocs\webquanlysinhvien
```

### Bước 2: Tạo database

* Mở `phpMyAdmin`
* Import file `database.sql`

### Bước 3: Tạo thư mục upload

```
uploads/
```

### Bước 4: Chạy project

Mở trình duyệt:

```
http://localhost/webquanlysinhvien
```

---

## 🔑 Tài khoản đăng nhập

* Username: `admin`
* Password: `123`

---

## 🔒 Bảo mật

* Sử dụng `password_hash()` để mã hóa mật khẩu
* Sử dụng `password_verify()` để xác thực
* Sử dụng Prepared Statement để chống SQL Injection
* Session quản lý đăng nhập

---

## 🎯 Mục tiêu hệ thống

* Quản lý thông tin sinh viên hiệu quả
* Áp dụng kiến thức PHP + MySQL vào thực tế
* Xây dựng hệ thống CRUD hoàn chỉnh

---

## 💡 Hướng phát triển

* Thêm phân quyền (Admin/User)
* Giao diện Dashboard nâng cao
* Thêm API REST
* Xuất PDF
* Thống kê biểu đồ

---

## 👨‍💻 Tác giả

* Sinh viên: *(Điền tên bạn vào đây)*
* Môn học: Lập trình Web

---

## 📌 Ghi chú

Đây là project phục vụ mục đích học tập và nghiên cứu.

---
