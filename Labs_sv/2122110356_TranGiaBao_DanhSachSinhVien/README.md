#  Hệ Thống Quản Lý Sinh Viên (PHP + MySQL)

##  Giới thiệu

Đây là hệ thống **Quản Lý Sinh Viên** được xây dựng bằng:

* HTML
* CSS
* JavaScript
* PHP
* MySQL (XAMPP)

Hệ thống cho phép quản lý danh sách sinh viên thông qua các chức năng thêm, sửa, xóa, tìm kiếm và xuất dữ liệu ra file.

---

##  Chức năng chính

Hệ thống bao gồm các chức năng:

* ➕ Thêm sinh viên mới
* ✏️ Sửa thông tin sinh viên
* ❌ Xóa sinh viên
* 📋 Hiển thị danh sách sinh viên
* 🔍 Tìm kiếm sinh viên
* 🚫 Kiểm tra trùng MSSV khi thêm
* 🚫 Kiểm tra trùng MSSV khi sửa
* 📄 Xuất danh sách sinh viên ra file `.txt`
* 🔄 Dữ liệu được lưu trong MySQL Database

---

##  Cấu trúc thư mục project

```text
2122110356_TranGiaBao_DanhSachSinhVien/
│
├── index.html      # Giao diện chính
├── style.css       # Thiết kế giao diện
├── script.js       # Xử lý chức năng JavaScript
│
├── db.php          # Kết nối database MySQL
├── get.php         # Lấy danh sách sinh viên từ database
├── them.php        # Thêm sinh viên
├── sua.php         # Sửa sinh viên
├── xoa.php         # Xóa sinh viên
│
└── README.md       # File mô tả project
```

---

##  Cấu trúc Database

Tên database:

```sql
quanly_sinhvien
```

Tên bảng:

```sql
dssinhvien
```

Cấu trúc bảng:

```sql
CREATE TABLE dssinhvien (
    id INT AUTO_INCREMENT PRIMARY KEY,
    mssv VARCHAR(20) UNIQUE,
    ten VARCHAR(100),
    diem FLOAT
);
```

Trong đó:

* `id`: Khóa chính tự tăng
* `mssv`: Mã số sinh viên (không trùng)
* `ten`: Tên sinh viên
* `diem`: Điểm trung bình

---

##  Hướng dẫn cài đặt (XAMPP)

### Bước 1: Mở XAMPP

Start:

* Apache
* MySQL

---

### Bước 2: Copy project vào htdocs

Copy folder project vào:

```bash
C:\xampp\htdocs\
```

Ví dụ:

```bash
C:\xampp\htdocs\2122110356_TranGiaBao_DanhSachSinhVien
```

---

### Bước 3: Tạo database

Mở trình duyệt:

```text
http://localhost/phpmyadmin
```

Tạo database:

```text
quanly_sinhvien
```

---

### Bước 4: Tạo bảng

Chạy câu lệnh:

```quanly_sinhvien
CREATE TABLE dssinhvien (
    id INT AUTO_INCREMENT PRIMARY KEY,
    mssv VARCHAR(20) UNIQUE,
    ten VARCHAR(100),
    diem FLOAT
);
```

---

### Bước 5: Chạy project

Mở trình duyệt:

```text
http://localhost/2122110356_TranGiaBao_DanhSachSinhVien/
```

---

## 🧪 Test Cases

Các trường hợp kiểm thử:

1. Thêm sinh viên mới
2. Thêm sinh viên trùng MSSV → hiển thị thông báo lỗi
3. Sửa thông tin sinh viên
4. Sửa MSSV trùng → hiển thị thông báo lỗi
5. Xóa sinh viên
6. Tìm kiếm sinh viên theo MSSV hoặc tên
7. Xuất danh sách sinh viên ra file `.txt`
8. Tìm kiếm sinh viên không tồn tại

---

## 🧩 Công nghệ sử dụng

* HTML
* CSS
* JavaScript
* PHP
* MySQL
* XAMPP

---

## 📌 Ghi chú

* MSSV được đặt **UNIQUE** để tránh trùng lặp
* Khi thêm hoặc sửa MSSV trùng, hệ thống sẽ hiển thị thông báo
* Dữ liệu được lưu trực tiếp trong database MySQL

---

## 👨‍💻 Thông tin sinh viên

Họ và tên: **Trần Gia Bảo**
MSSV: **2122110356**

Môn học: **Cấu trúc dữ liệu và giải thuật **

---
