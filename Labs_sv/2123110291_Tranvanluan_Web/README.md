#  HỆ THỐNG QUẢN LÝ NHÀ HÀNG (ĐẶT BÀN & GỌI MÓN)

##  Giới thiệu

Đây là ứng dụng web fullstack mô phỏng hệ thống quản lý nhà hàng.
Hệ thống cho phép quản lý bàn, gọi món, thanh toán và quản lý thực đơn.

Dự án được xây dựng nhằm thực hành phát triển ứng dụng web với frontend (ReactJS) và backend (ASP.NET Core API).

---

##  Công nghệ sử dụng

###  Frontend

* ReactJS
* Vite
* TailwindCSS

###  Backend

* ASP.NET Core Web API
* Entity Framework Core
* PostgreSQL
* Xử lý logic đặt bàn, gọi món và thanh toán
* Hỗ trợ truy cập menu thông qua QR Code theo từng bàn
* Khi khách quét QR, hệ thống tự động xác định bàn và tạo hoặc lấy lại order hiện tại
* Cho phép tiếp tục gọi món ngay cả khi tải lại trang hoặc quét lại QR 
* Không yêu cầu đăng nhập, tối ưu trải nghiệm nhanh và đơn giản  
---

##  Chức năng chính

###  Người dùng / Nhân viên

- Xem danh sách bàn (trống / đang sử dụng)  
- Chọn bàn và nhập tên khách hàng  
- Xác nhận thông tin để tạo order  
- Quét QR Code của bàn để truy cập menu  
- Gọi món trực tiếp từ menu  
- Tăng / giảm / xóa món trong order  
- Thanh toán hóa đơn  
- Có thể quét lại QR hoặc reload để tiếp tục order mà không mất dữ liệu  

###  Quản lý (Admin)

* Xem tổng quan hệ thống (số bàn, trạng thái bàn)
* Theo dõi báo cáo hoạt động (số đơn, doanh thu, công suất bàn)
* Quản lý danh sách bàn (thêm / sửa / xóa)
* Quản lý thực đơn (menu) và danh mục món
* Xem và quản lý các order
* Thống kê khách hàng (lượt đến, tổng chi tiêu, phân loại khách)


##  Cách hoạt động hệ thống

### 1. Khởi tạo bàn
- Nhân viên xem danh sách bàn  
- Bắt buộc chọn bàn trước khi thực hiện gọi món  
- Nhập tên khách hàng  
- Xác nhận để tạo order ban đầu  
- Hệ thống liên kết order với bàn (Table) và lưu thông tin khách hàng (tên người đặt), giúp quản lý order theo từng bàn mà không cần đăng nhập
---
### 2. Truy cập bằng QR
- Mỗi bàn có một mã QR riêng  
- Khách quét QR để truy cập vào menu của bàn  
- Hệ thống xác định bàn và lấy order hiện tại  
- Khi reload trang, cần quét lại QR để tiếp tục gọi món
- Có thể truy cập lại bằng QR khi reload mà không mất dữ liệu
- Không yêu cầu đăng nhập, thao tác nhanh và đơn giản  
---
###  3. Gọi món
- Khách chọn món trực tiếp từ menu  
- Hệ thống thêm món vào order hiện tại của bàn (OrderDetails)  
- Có thể xóa món khỏi order  
- Dữ liệu được cập nhật ngay sau mỗi thao tác  
---
###  4. Thanh toán
- Hệ thống tính tổng tiền dựa trên các món đã gọi
- Cập nhật trạng thái order = Closed
- Lưu thời gian thanh toán
- Reset bàn về trạng thái trống (Empty)
---
### 5. Quản lý & thống kê (Admin)
- Theo dõi số lượng đơn hàng và doanh thu  
- Xem trạng thái bàn (trống / đang sử dụng)  
- Quản lý danh sách bàn (thêm / sửa / xóa)  
- Quản lý menu và danh mục món  
- Xem và quản lý các order  
- Thống kê khách hàng (lượt đến, tổng chi tiêu) 

##  Cấu trúc backend (API)

- `CategoryController`: quản lý danh mục món  
- `MenuItemController`: quản lý món ăn và hình ảnh  
- `TableController`: quản lý bàn và order theo từng bàn  
- `OrderController`: xử lý gọi món, thanh toán và quản lý order  
- `UserController`: quản lý tài khoản admin và nhân viên  
- `RoleController`: phân quyền người dùng (Admin, User)  
- `AuthController`: hỗ trợ lưu thông tin người dùng khi thao tác hệ thống  

## 🔗 Source Code

* Frontend: https://github.com/banhluanbeo-debug/frontendASP
* Backend: https://github.com/banhluanbeo-debug/2123110291_Tranvanluan

---

##  Live Demo

- Frontend: https://frontend-asp-delta.vercel.app/
- Backend API (Swagger): https://two123110291-tranvanluan.onrender.com/swagger/index.html
---

##  Ghi chú

- Dự án được thiết kế theo mô hình tách frontend và backend (client - server)  
- Backend cung cấp API, frontend chịu trách nhiệm hiển thị giao diện  
- Tập trung vào việc xây dựng luồng xử lý thực tế trong nhà hàng (đặt bàn, gọi món, thanh toán)  




