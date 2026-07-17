# 🚀 C++ Advanced File Explorer & Manager (V10.0)

Công cụ quản lý tập tin mạnh mẽ trên môi trường Console, tích hợp sâu với Windows API để thực hiện các tác vụ tìm kiếm và xử lý file toàn diện.

## ✨ Tính năng chính
- **🔍 Deep Search:** Tự động nhận diện và quét tất cả các ổ đĩa có sẵn trên hệ thống (C:, D:, USB...).
- **📂 Thao tác đa dạng:** - Đọc nội dung file text trực tiếp trên Console.
  - Mở file bằng ứng dụng mặc định của Windows (ShellExecute).
  - Xóa file đơn lẻ hoặc xóa thư mục (bao gồm cả thư mục con).
- **🛡️ Force Delete:** Sử dụng `SHFileOperationA` để xử lý các file bị khóa hoặc thư mục cứng đầu.
- **🎨 UI/UX Optimized:** Giao diện phân màu, menu điều hướng thông minh và tự động dọn dẹp màn hình.

## 🛠 Hướng dẫn cài đặt
1. Mở file `.cpp` bằng **Dev-C++** hoặc **Visual Studio**.
2. Đảm bảo đã include các thư viện hệ thống: `windows.h`, `cstdio`, `shellapi.h`.
3. Nhấn `F11` để biên dịch và chạy.

## 📖 Cách sử dụng
1. **Nhập từ khóa:** Nhập tên file hoặc định dạng (ví dụ: `.txt`, `test.cpp`).
2. **Chọn hành động:** - Nhấn `1` để xem nội dung.
   - Nhấn `2` để mở file bằng Windows.
   - Nhấn `3` để xóa 1 file được chọn.
   - Nhấn `4` để xóa toàn bộ danh sách tìm thấy.
3. **Thoát:** Nhập `EXIT` tại màn hình tìm kiếm.

## ⚠️ Lưu ý quan trọng
Công cụ này có khả năng xóa vĩnh viễn dữ liệu (không qua Thùng rác). Vui lòng kiểm tra kỹ đường dẫn trước khi xác nhận xóa.

---
*Phát triển bởi: Thinh3len | Học phần: Cấu trúc dữ liệu và Giải thuật*
