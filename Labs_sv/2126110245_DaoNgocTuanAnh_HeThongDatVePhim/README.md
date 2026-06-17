# 🎬 HỆ THỐNG QUẢN LÝ ĐẶT VÉ RẠP CHIẾU PHIM (CLI)

## 💡 1. Khái quát ý tưởng (Concept)
Hệ thống được thiết kế nhằm mô phỏng quy trình nghiệp vụ thực tế của một rạp chiếu phim, tối ưu hóa việc quản lý tài nguyên và trải nghiệm khách hàng thông qua sự phối hợp của nhiều cấu trúc dữ liệu:
* **Mô hình hóa không gian:** Sử dụng lưới tọa độ để quản lý vị trí vật lý của các ghế ngồi trong rạp.
* **Cơ chế ưu tiên thông minh:** Giải quyết bài toán quá tải (hết ghế) bằng hàng chờ có trọng số, đảm bảo quyền lợi cho khách hàng VIP.
* **Cơ chế phục hồi (Fault Tolerance):** Cho phép hoàn tác (Undo) các sai sót trong quá trình thao tác dữ liệu, đảm bảo tính nhất quán của hệ thống.
* **Quản lý dữ liệu tập trung:** Lưu trữ thông tin khách hàng vào cấu trúc cây để tối ưu hóa tốc độ tìm kiếm và quản lý ID.

## 🛠 2. Cấu trúc dữ liệu & Giải thuật chi tiết

| Chức năng | Cấu trúc dữ liệu | Giải thích lựa chọn | Độ phức tạp (Big-O) |
| :--- | :--- | :--- | :--- |
| **Quản lý sơ đồ ghế** | **2D Array (Mảng 2 chiều)** | Ánh xạ trực tiếp tọa độ thực của rạp. | Truy xuất/Cập nhật: $O(1)$ |
| **Hàng chờ ưu tiên** | **Priority Queue (Heap)** | Tự động sắp xếp khách VIP lên đầu hàng chờ. | Thêm/Xóa: $O(\log n)$ |
| **Lịch sử & Hoàn tác** | **Stack (Ngăn xếp)** | Lưu vết giao dịch theo cơ chế LIFO (Vào sau ra trước). | Push/Pop: $O(1)$ |
| **Tra cứu khách hàng** | **BST (Cây nhị phân tìm kiếm)** | Duyệt dữ liệu theo phân nhánh, nhanh hơn danh sách liên kết. | Trung bình: $O(\log n)$ |



## 📥 3. Đặc tả Input/Output

### A. Dữ liệu đầu vào (Input)
* **Dữ liệu định danh:**
    * `ID`: Số nguyên (Integer) - Mã duy nhất cho mỗi khách hàng.
    * `Họ tên`: Chuỗi ký tự (String) - Tên khách hàng đặt vé.
    * `Hạng thành viên`: Boolean (1: VIP - Ưu tiên cao, 0: Thường).
* **Dữ liệu vị trí:**
    * `Tọa độ`: Cặp số nguyên (Hàng, Cột) trong phạm vi từ 0 đến 4.
* **Dữ liệu điều khiển:** Các lựa chọn số (0-5) từ Menu hệ thống.

### B. Dữ liệu đầu ra (Output)
* **Visual Map:** Sơ đồ 5x5 trực quan. Ghế trống hiển thị `[ ]`, ghế đã đặt hiển thị `[X]`.
* **Trạng thái giao dịch:**
    * Thông báo xác nhận: *"Đặt vé thành công"*, *"Hủy vé thành công"*.
    * Thông báo hệ thống: *"Đang đưa vào hàng chờ ưu tiên"* (khi ghế đã có người).
* **Xử lý tự động:** Ngay khi một ghế được giải phóng (Cancel), hệ thống tự động in thông báo: *"Ưu tiên cấp ghế cho khách hàng [Tên] từ hàng chờ"*.
* **Thông tin tra cứu:** Kết quả tìm kiếm khách hàng từ cây BST bao gồm Tên và Hạng thành viên.

## 🚀 Hướng dẫn biên dịch và chạy
Chương trình yêu cầu trình biên dịch g++ hỗ trợ chuẩn **C++17** trở lên:
```bash
# Biên dịch
g++ -std=c++17 main.cpp -o cinema

# Chạy chương trình
./cinema
