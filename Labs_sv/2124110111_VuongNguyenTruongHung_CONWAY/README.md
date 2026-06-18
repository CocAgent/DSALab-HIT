# Conway: Game of Life

## Thông tin sinh viên

- Họ tên: Vương Nguyễn Trường Hùng
- MSSV: 2124110111
- Đề tài: Conway: Game of Life

Đây là ứng dụng C++ CLI mô phỏng trò chơi tế bào Conway's Game of Life trên ma trận 2 chiều. Người dùng có thể tạo bàn cờ, gieo tế bào sống, nạp pattern có sẵn, chạy mô phỏng theo từng thế hệ, hoàn tác và xem lịch sử biến đổi.

## Mục tiêu bài toán

- Mô phỏng luật sống chết kinh điển của Conway:
  - Ô sống sống tiếp nếu có 2 hoặc 3 hàng xóm sống.
  - Ô chết sẽ được sinh ra nếu có đúng 3 hàng xóm sống.
- Cho phép thử nghiệm các pattern kinh điển như `block`, `blinker`, `glider`, `beacon`, `toad`, `gosper`.
- Trình bày bằng menu để phù hợp yêu cầu bài nộp môn học.

## Cấu trúc dữ liệu sử dụng

- `Linked List`:
  Dùng trong `AliveCellList` để lưu danh sách các ô đang sống trên bàn cờ hiện tại.
- `Queue`:
  Dùng trong `HistoryQueue` để lưu lịch sử các thế hệ gần đây, gồm số ô sống, số ô mới sinh và số ô chết.
- `Stack`:
  Dùng trong `SnapshotStack` để hỗ trợ thao tác `undo`, quay lại trạng thái trước đó của bàn cờ.
- `BST`:
  Dùng trong `PatternBST` để lưu và tìm kiếm pattern có sẵn theo tên.

## Chức năng

1. Hiển thị bàn cờ hiện tại.
2. Thay đổi kích thước bàn cờ.
3. Bật hoặc tắt một ô thủ công.
4. Gieo ngẫu nhiên theo mật độ phần trăm.
5. Nạp pattern Conway từ cây BST.
6. Chạy 1 thế hệ.
7. Chạy N thế hệ liên tiếp.
8. Hoàn tác 1 bước.
9. Xem lịch sử mô phỏng.
10. Liệt kê pattern có sẵn.
11. Xóa bàn cờ.

## Thiết kế file

```text
src/
  main.cpp       - Menu và điều khiển chương trình
  structures.h   - Khai báo cấu trúc dữ liệu và prototype
  functions.cpp  - Cài đặt Conway và các cấu trúc dữ liệu
tests/
  test_cases.cpp - Bộ test các chức năng chính
docs/
  .gitkeep
README.md        - Mô tả bài toán và hướng dẫn chạy
```

## Compile và chạy

Build chương trình chính:

```bash
g++ -std=c++17 src/main.cpp src/functions.cpp -o app
./app
```

Build bộ test:

```bash
g++ -std=c++17 tests/test_cases.cpp src/functions.cpp -o test_app
./test_app
```

## Test case chính

1. `block` là still life nên không đổi sau 1 thế hệ.
2. `blinker` dao động đúng chu kỳ 2.
3. BST chứa và liệt kê được pattern `glider`, `gosper`.
4. Nạp pattern `glider` đúng số lượng tế bào sống.
5. `undo` khôi phục đúng trạng thái trước khi step.
6. `HistoryQueue` ghi nhận đúng thông tin thế hệ.

## Đánh giá thiết kế

- Ưu điểm:
  - Menu rõ ràng, dễ demo trên terminal.
  - Dùng nhiều cấu trúc dữ liệu có ý nghĩa với bài toán.
  - Dễ mở rộng thêm pattern mới hoặc chế độ wrap board.
- Hạn chế:
  - Bàn cờ hiện tại sử dụng ma trận trong RAM nên không tối ưu cho kích thước rất lớn.
  - Hiển thị là dạng text, chưa có giao diện đồ họa.
