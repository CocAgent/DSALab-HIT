# 📱 QUẢN LÝ DANH BẠ BẰNG CÂY BST

## 👤 Thông tin sinh viên

* **Họ tên:** Nguyễn Tuấn Kiệt
* **MSSV:** 2125110240
* **Lớp:** CCQ2511G

---

## 🎯 Mô tả đề tài

Ứng dụng **quản lý danh bạ** sử dụng **cây nhị phân tìm kiếm (BST)** để lưu trữ và sắp xếp các liên hệ theo tên.

Hệ thống hỗ trợ:

* Thêm / Xóa / Tìm kiếm liên hệ
* Gợi ý tìm kiếm (Autocomplete)
* Undo thao tác xóa
* Lưu lịch sử tìm kiếm
* Thùng rác (khôi phục / xóa vĩnh viễn)
* Tự động xóa dữ liệu sau 30 ngày
* Lưu và đọc dữ liệu từ file

---

## 🧠 Cấu trúc dữ liệu sử dụng

| Cấu trúc                     | Mục đích                      |
| ---------------------------- | ----------------------------- |
| **BST (Binary Search Tree)** | Lưu danh bạ, sắp xếp theo tên |
| **Stack**                    | Undo thao tác xóa             |
| **Queue**                    | Lưu lịch sử tìm kiếm          |
| **Vector**                   | Quản lý thùng rác             |
| **File (.txt)**              | Lưu trữ dữ liệu               |

---

## ⚙️ Chức năng chính

### 1. Thêm liên hệ

* Nhập tên và số điện thoại
* Kiểm tra hợp lệ (chỉ chứa số)

### 2. Xem danh bạ

* Hiển thị dạng bảng
* Sắp xếp A → Z tự động

### 3. Tìm kiếm

* Tìm theo tên
* Hỗ trợ gợi ý (prefix search)

### 4. Xóa liên hệ

* Chọn theo STT
* Có xác nhận trước khi xóa
* Lưu vào thùng rác

### 5. Undo xóa

* Khôi phục liên hệ vừa xóa

### 6. Lịch sử tìm kiếm

* Lưu lại các từ khóa đã tìm

### 7. Lưu file

* Lưu danh bạ vào `contacts.txt`

### 8. Thùng rác

* Hiển thị danh sách đã xóa
* Khôi phục liên hệ
* Xóa vĩnh viễn
* Hiển thị số ngày còn lại
* Tự động xóa sau 30 ngày

---

## 💾 Cách hoạt động lưu trữ

### 📂 File danh bạ: `contacts.txt`

```
Ten|SoDienThoai
```

### 🗑 File thùng rác: `trash.txt`

```
Ten|SoDienThoai|Timestamp
```

---

## ▶️ Cách chạy chương trình

### 🔹 Yêu cầu:

* Compiler: **g++ (C++17)** hoặc **Visual Studio 2022**

### 🔹 Compile (g++):

```bash
g++ -std=c++17 main.cpp BST.cpp -o app
```

### 🔹 Chạy:

```bash
./app
```

---

## 🧪 Test case mẫu

### ✅ Test 1: Thêm liên hệ

* Input: "Kiet", "0123456789"
* Expected: Xuất hiện trong danh sách

### ✅ Test 2: Tìm kiếm

* Input: "An"
* Expected: Hiển thị các tên bắt đầu bằng "An"

### ✅ Test 3: Xóa

* Xóa 1 liên hệ
* Expected: Biến mất khỏi danh bạ, xuất hiện trong thùng rác

### ✅ Test 4: Undo

* Sau khi xóa → undo
* Expected: Liên hệ quay lại danh bạ

### ✅ Test 5: Thùng rác

* Khôi phục / xóa vĩnh viễn
* Expected: Dữ liệu thay đổi đúng

---

## 🎨 Giao diện

* Menu dạng bảng
* Hiển thị danh sách rõ ràng
* Có pause màn hình
* UX thân thiện người dùng

---

## 🚀 Hướng phát triển

* Thêm tìm kiếm nâng cao
* Xuất file CSV / Excel
* Giao diện GUI
* Sắp xếp theo nhiều tiêu chí

---

## 🎤 Kết luận

Đề tài đã áp dụng thành công nhiều cấu trúc dữ liệu (BST, Stack, Queue, Vector) và xây dựng một hệ thống quản lý danh bạ hoàn chỉnh, có khả năng lưu trữ và xử lý dữ liệu hiệu quả.

---

⭐ **Đánh giá:** Hoàn thành đầy đủ yêu cầu và mở rộng thêm nhiều tính năng nâng cao.
