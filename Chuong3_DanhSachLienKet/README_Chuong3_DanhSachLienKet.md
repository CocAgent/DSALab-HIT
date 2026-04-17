# Chương 3: Danh Sách Liên Kết và Ứng Dụng

Tệp nguồn chính: `Chuong3_DanhSachLienKet_refined.cpp`

## Mục đích

Tài liệu này mô tả chương trình minh họa các nội dung cơ bản của Chương 3:

- Con trỏ
- Danh sách liên kết đơn
- Stack
- Queue
- Một số bài toán xử lý dữ liệu trên danh sách liên kết

Phiên bản `refined` giữ cách viết gần với giáo trình nhưng được chỉnh lại để dễ đọc hơn và an toàn hơn khi thao tác với bộ nhớ.

## Nội dung chính của chương trình

### 1. Danh sách liên kết đơn

Chương trình định nghĩa:

- `Node`: nút của danh sách, gồm `data` và `next`
- `List`: danh sách gồm `head` và `tail`

Các thao tác đã cài đặt:

- Khởi tạo danh sách
- Kiểm tra danh sách rỗng
- Tạo node mới
- Thêm đầu
- Thêm cuối
- Thêm sau một node
- Thêm trước một node
- Xóa đầu
- Xóa cuối
- Xóa node có giá trị `x`
- Xóa toàn bộ danh sách
- In danh sách

### 2. Các bài toán xử lý trên danh sách

Chương trình có các hàm minh họa:

- Tìm phần tử lớn nhất
- Tìm node có giá trị `x`
- Tìm số chẵn đầu tiên
- Tìm số chẵn cuối cùng
- Liệt kê các phần tử âm
- Tính tổng các phần tử dương
- Đếm số phần tử âm
- Kiểm tra số chính phương
- Kiểm tra danh sách có chứa số chính phương hay không
- Đếm số lần xuất hiện của phần tử lớn nhất
- Sắp xếp danh sách tăng dần
- Nối hai danh sách
- Tách danh sách thành danh sách chẵn và danh sách lẻ

### 3. Stack

Stack được cài bằng danh sách liên kết đơn, hỗ trợ:

- Khởi tạo stack
- Kiểm tra stack rỗng
- `Push`
- `Pop`
- Xem phần tử ở đỉnh
- In stack
- Giải phóng stack

Ứng dụng minh họa:

- Kiểm tra dấu ngoặc hợp lệ
- Đổi số thập phân sang nhị phân

### 4. Queue

Queue cũng được cài bằng danh sách liên kết đơn, hỗ trợ:

- Khởi tạo queue
- Kiểm tra queue rỗng
- `Enqueue`
- `Dequeue`
- In queue
- Giải phóng queue

## Điểm chỉnh sửa trong bản refined

So với bản viết nhanh ban đầu, bản này có một số thay đổi đáng chú ý:

- Trả kết quả thành công/thất bại bằng `bool` ở nhiều hàm thay vì dùng giá trị đặc biệt như `-1`
- Kiểm tra kỹ hơn khi thêm trước hoặc thêm sau một node
- Bổ sung hàm giải phóng cho stack và queue
- Hạn chế lỗi thao tác với node không thuộc danh sách
- Tách phần demo rõ ràng hơn

## Các phần demo trong chương trình

Chương trình gồm 4 phần chạy thử:

- `DemoDSLK()`: minh họa các thao tác trên danh sách liên kết
- `DemoStack()`: minh họa stack và các ứng dụng của stack
- `DemoQueue()`: minh họa queue
- `DemoBaiTap()`: chạy một số bài tập tổng hợp theo kiểu giáo trình

## Biên dịch và chạy

### Cách 1: dùng g++

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o chuong3 Chuong3_DanhSachLienKet_refined.cpp
./chuong3
```

### Cách 2: dùng clang++

```bash
clang++ -std=c++17 -O2 -Wall -Wextra -o chuong3 Chuong3_DanhSachLienKet_refined.cpp
./chuong3
```

### Cách 3: dùng MSVC trên Windows

```powershell
cl /EHsc /std:c++17 Chuong3_DanhSachLienKet_refined.cpp
.\Chuong3_DanhSachLienKet_refined.exe
```

## Kết quả mong đợi

Khi chạy chương trình, màn hình sẽ lần lượt hiển thị:

- Phần demo danh sách liên kết đơn
- Phần demo stack
- Phần demo queue
- Phần bài tập tổng hợp

Mỗi phần đều in ra trạng thái dữ liệu trước và sau khi thao tác để tiện theo dõi.

## Gợi ý mở rộng

Nếu muốn mở rộng tiếp, có thể bổ sung:

- Danh sách liên kết kép
- Danh sách liên kết vòng
- Sắp xếp nổi bọt, chèn, đổi chỗ trực tiếp
- Đảo ngược danh sách
- Tìm kiếm theo nhiều điều kiện
- Cài đặt stack và queue bằng class

## Ghi chú

Tệp này phù hợp để học các thao tác cơ bản với cấu trúc dữ liệu động trước khi chuyển sang các phiên bản hiện đại hơn dùng `class`, constructor, destructor hoặc STL.
