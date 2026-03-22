# 📙 Chương 3: Danh Sách Liên Kết & Ứng Dụng

> **Mục tiêu:** Hiểu con trỏ, DSLK đơn, và ứng dụng Stack/Queue.

---

## 1. Con Trỏ (Pointer)

### 1.1 Khái Niệm

> **Biến con trỏ** là biến lưu **địa chỉ** của một ô nhớ khác trong RAM.

```
Bộ nhớ RAM:
┌────────┬─────────┐
│ Địa chỉ│  Giá trị│
├────────┼─────────┤
│ 0x1000 │   42    │  ← int x = 42
│ 0x1004 │ 0x1000  │  ← int *p = &x  (p lưu địa chỉ của x)
└────────┴─────────┘

p  → trỏ đến địa chỉ 0x1000
*p → lấy giá trị tại địa chỉ đó = 42
```

### 1.2 Phân Biệt 3 Loại Biến

| Loại | Khai báo | Bộ nhớ | Giải phóng |
|------|----------|--------|-----------|
| Biến thường | `int x = 5;` | Stack, cố định | Tự động |
| Biến con trỏ | `int *p;` | Stack (lưu địa chỉ) | Tự động |
| Biến động | `p = new int(5);` | Heap, linh hoạt | **Thủ công** (`delete`) |

### 1.3 Các Phép Toán Con Trỏ

```cpp
int x = 10;
int *p = &x;     // p trỏ đến x

*p = 20;         // thay đổi x qua p → x = 20
p = nullptr;     // con trỏ null — không trỏ vào đâu

// Cấp phát động
int *arr = new int[5];   // cấp phát 5 int trên Heap
delete[] arr;            // bắt buộc giải phóng!
```

---

## 2. Danh Sách Liên Kết (Linked List)

### 2.1 Tại Sao Cần DSLK?

| Tiêu Chí | Mảng | DSLK |
|----------|------|------|
| Kích thước | Cố định (khai báo trước) | Linh hoạt, tăng giảm động |
| Truy cập index | O(1) ⚡ | O(N) |
| Chèn/Xóa đầu | O(N) — phải dịch chuyển | O(1) ⚡ |
| Chèn/Xóa giữa | O(N) | O(N) — tìm vị trí |
| Bộ nhớ | Liên tục | Phân tán (qua con trỏ) |

### 2.2 Cấu Trúc Node DSLK Đơn

```
┌──────────┬──────────┐     ┌──────────┬──────────┐     ┌──────────┬──────┐
│  data=10 │  next ───┼────▶│  data=20 │  next ───┼────▶│  data=30 │ NULL │
└──────────┴──────────┘     └──────────┴──────────┘     └──────────┴──────┘
    Node 1                       Node 2                       Node 3
       ▲
     head
```

### 2.3 Các Hình Thức DSLK

| Loại | Đặc Điểm | Khi Dùng |
|------|----------|---------|
| **DSLK Đơn** | Mỗi node có 1 con trỏ `next` | Đơn giản, tiết kiệm |
| **DSLK Kép** | Có cả `prev` và `next` | Cần duyệt 2 chiều |
| **DSLK Vòng** | Node cuối trỏ về đầu | Round-robin, music playlist |

---

## 3. Các Thao Tác DSLK Đơn

### 3.1 Thêm Đầu — O(1)
```
Trước: HEAD → [20] → [30] → NULL
       p = new Node(10)
Sau:   HEAD → [10] → [20] → [30] → NULL
```

### 3.2 Thêm Cuối — O(1) nếu có tail
```
Trước: HEAD → [10] → [20] → NULL, TAIL = [20]
       p = new Node(30)
Sau:   HEAD → [10] → [20] → [30] → NULL, TAIL = [30]
```

### 3.3 Xóa Đầu — O(1)
```
Trước: HEAD → [10] → [20] → [30] → NULL
       p = head; head = head→next; delete p;
Sau:   HEAD → [20] → [30] → NULL
```

### 3.4 Độ Phức Tạp Tổng Kết

| Thao tác | DSLK đơn | Ghi chú |
|----------|---------|---------|
| Thêm đầu | O(1) | |
| Thêm cuối | O(1) | Cần biến `tail` |
| Thêm sau q | O(1) | Đã có node q |
| Xóa đầu | O(1) | |
| Xóa cuối | O(N) | Cần tìm node trước tail |
| Tìm kiếm | O(N) | |
| Sắp xếp | O(N²) | Selection sort trên DSLK |

---

## 4. Stack (Ngăn Xếp)

### 4.1 Nguyên Tắc LIFO

```
LIFO = Last In, First Out (Vào sau — Ra trước)

Push(10): [10]
Push(20): [20] ← TOP
          [10]
Push(30): [30] ← TOP
          [20]
          [10]
Pop():    lấy 30 ra → [20] ← TOP
                       [10]
```

### 4.2 Ứng Dụng Stack

| Ứng Dụng | Mô Tả |
|----------|-------|
| **Undo/Redo** | Lưu lịch sử thao tác |
| **Duyệt DFS** | Đồ thị, cây |
| **Kiểm tra ngoặc** | `{[()]}` hợp lệ? |
| **Gọi hàm** | Call stack của CPU |
| **Đổi cơ số** | Dec → Bin |
| **Tính biểu thức** | Postfix calculator |

---

## 5. Queue (Hàng Đợi)

### 5.1 Nguyên Tắc FIFO

```
FIFO = First In, First Out (Vào trước — Ra trước)

Enqueue(1): FRONT→[1]←REAR
Enqueue(2): FRONT→[1]→[2]←REAR
Enqueue(3): FRONT→[1]→[2]→[3]←REAR
Dequeue():  lấy 1 ra → FRONT→[2]→[3]←REAR
```

### 5.2 Ứng Dụng Queue

| Ứng Dụng | Mô Tả |
|----------|-------|
| **Hàng chờ in** | Máy in xử lý theo thứ tự |
| **BFS đồ thị** | Duyệt theo mức |
| **Hàng đợi CPU** | Lịch sử tiến trình OS |
| **Cache** | LRU Cache |
| **Streaming** | Buffer video/audio |

---

## 6. Bài Tập Tự Luyện

### Cơ Bản
1. Tạo DSLK đơn chứa 5 số nguyên, in ra theo chiều ngược lại.
2. Cài đặt hàm đếm số phần tử chẵn trong DSLK.
3. Dùng Stack kiểm tra xâu `s` có phải palindrome không.

### Nâng Cao
4. Nối 2 DSLK không dùng thêm node mới.
5. Cài đặt Queue chỉ dùng 2 Stack.
6. Tìm và xóa tất cả phần tử trùng trong DSLK.

---

*📌 File code: [`src/Chapter3_LinkedList/Chapter3_LinkedList.cpp`](../src/Chapter3_LinkedList/Chapter3_LinkedList.cpp)*
