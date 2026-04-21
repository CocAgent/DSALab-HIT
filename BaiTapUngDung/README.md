# 🎯 Bài Tập Ứng Dụng — 5 Dự Án Mini Thực Tế

> Kết hợp kiến thức toàn khóa học vào các dự án có thật ngoài đời

---

## Dự Án 1: Quản Lý Sinh Viên 📋
**Cấu trúc:** Mảng động + Selection Sort + Linear/Binary Search
**Độ khó:** ⭐⭐

Hệ thống quản lý danh sách sinh viên và điểm số:
- CRUD sinh viên (thêm/sửa/xóa)
- Sắp xếp theo tên, MSSV, hoặc điểm
- Tìm kiếm theo tên hoặc MSSV
- Xuất danh sách ra file `diem_sinhvien.txt`
- Thống kê: điểm cao nhất, thấp nhất, trung bình, phân loại học lực

📁 File: `DuAn1_QuanLySinhVien.cpp`

---

## Dự Án 2: Lịch Sử Trình Duyệt 🌐
**Cấu trúc:** Singly Linked List + Stack
**Độ khó:** ⭐⭐

Mô phỏng lịch sử duyệt web:
- Lưu lịch sử tối đa 50 trang (Linked List)
- Back / Forward bằng 2 Stack (trang đã qua / trang đã tiến)
- Hiển thị breadcrumb: `google.com > youtube.com > [hiện tại]`
- Xóa toàn bộ lịch sử
- Lưu lịch sử ra file và khôi phục

📁 File: `DuAn2_LichSuTrinhDuyet.cpp`

---

## Dự Án 3: Máy Tính Biểu Thức 🧮
**Cấu trúc:** Stack (2 stack: toán tử + toán hạng)
**Độ khó:** ⭐⭐⭐
> Cảm hứng: [Pilha_Expressão_A — DanielSantDev](https://github.com/DanielSantDev/Projects-with-Cpp)

Máy tính tính biểu thức toán học phức tạp:
- Hỗ trợ: +, -, *, /, ^, %, ngoặc đơn, số thập phân
- Hiển thị từng bước chuyển đổi Infix → Postfix
- Hiển thị từng bước tính toán trên Stack
- Phát hiện lỗi: chia cho 0, ngoặc không khớp, ký tự lạ
- Lưu lịch sử 10 phép tính gần nhất

📁 File: `DuAn3_MayTinhBieuThuc.cpp`

---

## Dự Án 4: Hàng Chờ Bệnh Viện 🏥
**Cấu trúc:** Priority Queue + Queue thường
**Độ khó:** ⭐⭐⭐
> Cảm hứng: [Fila de Hospital — DanielSantDev](https://github.com/DanielSantDev/Projects-with-Cpp)

Hệ thống hàng chờ bệnh viện với phân cấp ưu tiên:
- 3 mức ưu tiên: 🔴 Cấp cứu > 🟡 Khẩn cấp > 🟢 Thông thường
- Cấp cứu luôn được chen lên đầu hàng
- Theo dõi thời gian chờ của từng bệnh nhân
- Báo cáo cuối ca: tổng bệnh nhân, thời gian chờ trung bình theo từng mức
- Mô phỏng 1 ca làm việc 8 tiếng (dùng random)

📁 File: `DuAn4_HangChoBeinhVien.cpp`

---

## Dự Án 5: Hệ Thống Rạp Chiếu Phim 🎭
**Cấu trúc:** BST + Queue + Stack + 2D Array
**Độ khó:** ⭐⭐⭐
> Cảm hứng: [Teatro — DanielSantDev](https://github.com/DanielSantDev/Projects-with-Cpp)

Hệ thống quản lý rạp chiếu phim hoàn chỉnh:
- Quản lý phim: thêm/xóa/tìm kiếm bằng BST (O log n)
- Sơ đồ ghế ngồi dạng 2D: đặt vé, hủy vé, đổi ghế
- Hàng chờ hoàn vé bằng Queue (FIFO)
- Undo thao tác đặt vé bằng Stack (tối đa 5 lần undo)
- Thống kê doanh thu theo ngày, theo phim
- Xuất báo cáo ra file

📁 File: `DuAn5_RapChieuPhim.cpp`

---

## 📊 Tổng Hợp Cấu Trúc Dữ Liệu Đã Học

| Cấu trúc | Tuần | Ứng dụng thực tế |
|----------|------|-----------------|
| Mảng động | 2 | Quản lý sinh viên |
| Linked List đơn | 6 | Lịch sử trình duyệt |
| Linked List đôi/vòng | 7 | Music playlist |
| Stack | 8 | Máy tính biểu thức |
| Queue | 9 | Hàng chờ bệnh viện |
| Binary Tree | 10 | Visualizer |
| BST | 11 | Từ điển Anh-Việt |
| Backtracking | 12 | N-Queens |
| Graph + BFS | 13 | Tìm đường mê cung |
| Dynamic Programming | 14 | Knapsack |
| Kết hợp tất cả | 15 | Rạp chiếu phim |
