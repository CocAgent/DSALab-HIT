# 🗺️ Campus Map Management System

## 📌 Giới thiệu

Đây là chương trình mô phỏng **hệ thống bản đồ trong trường học (Campus Map)** được viết bằng C++.
Chương trình giúp người dùng:

* Quản lý các địa điểm trong trường
* Quản lý đường đi giữa các địa điểm
* Tìm đường đi ngắn nhất
* Kiểm tra tính liên thông của bản đồ

---

## 🚀 Công nghệ sử dụng

* Ngôn ngữ: **C++**
* Cấu trúc dữ liệu:

  * Binary Search Tree (BST)
  * Graph (Adjacency List)
* Thuật toán:

  * Dijkstra (tìm đường ngắn nhất)
  * BFS (kiểm tra liên thông)

---

## 📂 Cấu trúc thư mục

```
project/
│
├── src/
│   ├── main.cpp
│   ├── structures.h
│   └── functions.cpp
│
├── tests/
│   └── test_cases.cpp
│
└── README.md
```

---

## ⚙️ Cách chạy chương trình

### 🔹 Compile

```
g++ src/main.cpp src/functions.cpp -o main
```

### 🔹 Run

```
./main
```

---

## 🧪 Chạy test

```
g++ src/functions.cpp tests/test_cases.cpp -o test
./test
```

---

## 🎯 Chức năng chính

### 1. Quản lý địa điểm

* Thêm địa điểm
* Xóa địa điểm
* Tìm kiếm theo ID
* Hiển thị danh sách

### 2. Quản lý đường đi

* Thêm đường đi
* Xóa đường đi
* Xem các địa điểm kề

### 3. Tìm đường

* Tìm đường đi ngắn nhất giữa 2 địa điểm (Dijkstra)

### 4. Kiểm tra bản đồ

* Kiểm tra liên thông (BFS)

---



## 👤 Thông tin sinh viên

* Họ tên: Phan Thị Hồng Phấn
* MSSV: 2125110263
* Lớp: CCQ2511G

---

## 📌 Ghi chú

* Chương trình chạy trên môi trường console
* Sử dụng encoding UTF-8 để hiển thị tiếng Việt

---

## 💡 Hướng phát triển

* Thêm giao diện đồ họa (GUI)
* Lưu dữ liệu vào file
* Hiển thị bản đồ trực quan

---
