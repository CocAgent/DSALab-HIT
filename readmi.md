# 🧩 Maze Game CLI (C++)

Chào mừng bạn đến với **Maze Game**, một trò chơi mê cung đơn giản chạy trên giao diện dòng lệnh (CLI) được viết bằng ngôn ngữ C++. Dự án này giúp làm quen với mảng 2 chiều và cơ chế xử lý sự kiện bàn phím.

## 🕹️ Cách chơi
- Sử dụng các phím **W, A, S, D** để di chuyển nhân vật `P`.
- **W**: Lên trên
- **S**: Xuống dưới
- **A**: Sang trái
- **D**: Sang phải
- Mục tiêu: Tìm đường đến vị trí đích `E` để giành chiến thắng.
- Nhấn phím **Q** để thoát trò chơi bất cứ lúc nào.

## 🛠️ Yêu cầu hệ thống
- Hệ điều hành: Windows (Sử dụng thư viện `<conio.h>`).
- Trình biên dịch: MSVC (Visual Studio) hoặc MinGW.

## 📁 Cấu trúc Project
- `Source.cpp`: Chứa logic chính của trò chơi (Vẽ bản đồ, xử lý di chuyển).

## 🚀 Hướng dẫn cài đặt và chạy
1. Mở Project trong **Visual Studio**.
2. Đảm bảo file `.cpp` đã được thêm vào mục **Source Files** trong Solution Explorer.
3. Nhấn `Ctrl + F5` để biên dịch và chạy.

## 📈 Kế hoạch phát triển (To-do)
- [ ] Tích hợp thuật toán **Recursive Backtracker** để tạo mê cung ngẫu nhiên.
- [ ] Thêm tính năng **Tự động giải** bằng thuật toán BFS (Tìm đường ngắn nhất).
- [ ] Thêm màu sắc cho tường và người chơi bằng `system("color")`.

---
*Dự án được thực hiện bởi phamminhthanh*
