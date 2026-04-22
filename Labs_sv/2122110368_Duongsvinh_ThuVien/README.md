# Hệ Thống Quản Lý Thư Viện

> **Final Project — Cấu Trúc Dữ Liệu & Giải Thuật**  
> Ngôn ngữ: C++17 | CLI Application

---

## Mô tả

Ứng dụng quản lý sách, độc giả và lịch sử mượn/trả sách tại thư viện.  
Dữ liệu được lưu tự động vào file `.txt` khi có thay đổi.

---

## Cấu trúc dữ liệu sử dụng

| Cấu trúc | Dùng ở đâu | Lý do chọn |
|----------|-----------|------------|
| **BST** (Binary Search Tree) | Lưu danh sách sách | Tìm kiếm theo mã O(log n), tự sắp xếp theo mã |
| **Linked List** | Danh sách độc giả | Thêm/xóa O(1) đầu danh sách, không cần kích thước cố định |
| **Queue** | Danh sách chờ mượn sách | FIFO — ai đến trước được phục vụ trước |
| **Stack** | Lịch sử thao tác (Undo) | LIFO — hoàn tác thao tác gần nhất trước |

---

## Compile và chạy

```bash
# Compile chương trình chính
g++ -std=c++17 src/main.cpp src/functions.cpp -o library
./library

# Compile và chạy test
g++ -std=c++17 tests/test_cases.cpp src/functions.cpp -o test_runner
./test_runner
```

---

## Chức năng

### Quản lý Sách (BST)
1. Thêm sách mới (BST insert)
2. Xóa sách (BST delete — chỉ xóa được khi không ai đang mượn)
3. Xem tất cả sách — in theo thứ tự mã (BST in-order traversal)
4. Tìm sách theo Mã — O(log n)
5. Tìm sách theo Tên — tìm kiếm chuỗi con

### Quản lý Độc Giả (Linked List)
1. Thêm độc giả mới
2. Xóa độc giả
3. Xem danh sách tất cả độc giả
4. Tìm độc giả theo Mã

### Mượn / Trả Sách
1. **Mượn sách** — nếu hết sách → tự động vào Queue chờ
2. **Trả sách** — tự động cấp cho người đầu Queue nếu có
3. Xem danh sách chờ (Queue)
4. Xem lịch sử thao tác (Stack)
5. **Undo** — hoàn tác thao tác mượn/trả vừa thực hiện

### Thống kê
- Tổng số đầu sách, độc giả
- Sách được mượn nhiều nhất
- Số người đang chờ trong Queue

---

## Cấu trúc file

```
library/
├── src/
│   ├── main.cpp         # Menu và điều khiển luồng
│   ├── structures.h     # Khai báo struct + prototype hàm
│   └── functions.cpp    # Cài đặt chi tiết tất cả hàm
├── tests/
│   └── test_cases.cpp   # 5 test case chính
├── data/                # Tự tạo khi chạy lần đầu
│   ├── books.txt
│   └── readers.txt
└── README.md
```

---

## Test Cases

| # | Test | Mô tả |
|---|------|-------|
| 1 | BST Insert & Search | Thêm 3 sách, tìm theo mã và tên |
| 2 | BST Delete | Xóa nút giữa, kiểm tra cây vẫn đúng |
| 3 | Queue FIFO | Enqueue 2 phần tử, dequeue ra đúng thứ tự |
| 4 | Stack LIFO | Push 2 thao tác, pop ra đúng thứ tự ngược |
| 5 | Linked List | Thêm/xóa độc giả, kiểm tra trùng ID |

---

## Big-O tóm tắt

| Thao tác | Độ phức tạp | Lý do |
|----------|-------------|-------|
| Tìm sách theo mã (BST) | O(log n) | Mỗi bước loại nửa cây |
| Thêm/xóa sách (BST) | O(log n) | Tương tự tìm kiếm |
| Thêm/xóa độc giả (LL) | O(1) / O(n) | Thêm đầu O(1), xóa cần duyệt |
| Enqueue / Dequeue | O(1) | Có pointer đến cả front và rear |
| Push / Pop Stack | O(1) | Chỉ thao tác tại đỉnh |
