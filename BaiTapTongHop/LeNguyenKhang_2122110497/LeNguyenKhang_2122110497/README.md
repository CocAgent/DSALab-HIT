# Đồ án: Hệ thống Quản lý Shop Cosplay - LeNguyenKhang_2122110497

## 📝 Giới thiệu
Dự án xây dựng hệ thống Backend cho cửa hàng bán trang phục và phụ kiện Cosplay. Hệ thống cho phép quản lý danh mục sản phẩm, theo dõi đơn hàng và cung cấp API cho các nền tảng frontend.

## 🚀 Công nghệ sử dụng
- **Framework:** .NET 10 (C#)
- **Database:** SQL Server (sử dụng Entity Framework Core)
- **Công cụ hỗ trợ:** Swagger UI (OpenAPI), Git/GitHub
- **Kiến trúc:** Model-View-Controller (MVC) cho Web API
- **Frontend:** Cozastore Template (HTML5, CSS3, JS)

## 🛠 Hướng dẫn cài đặt & Chạy dự án
1. Clone dự án từ GitHub.
2. Cấu hình chuỗi kết nối Database trong file `appsettings.json`.
3. Mở **Package Manager Console** và chạy lệnh: `Update-Database` (nếu cần).
4. Nhấn **F5** để chạy dự án.
5. Truy cập đường dẫn: `https://localhost:7064/swagger` để kiểm tra API.

## 📌 Các chức năng chính (API)
- **Sản phẩm (Product):** Xem danh sách, chi tiết sản phẩm cosplay.
- **Đơn hàng (Order):** Tạo mới đơn hàng và lưu thông tin chi tiết.
- **Danh mục (Category):** Phân loại theo nhân vật hoặc loại trang phục.
