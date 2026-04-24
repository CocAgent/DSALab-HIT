# Tuần 15: Dự Án Tổng Kết — Bài tập

## 🎯 Mục tiêu tuần này
Kết hợp tất cả kiến thức 14 tuần vào 1 dự án lớn hoàn chỉnh.

---

### Bài 1: Ôn tập tổng hợp ⭐⭐
Giải 5 bài từ BaiTapTongHop. Phân tích Big-O của từng bài. Viết nhận xét.

### Bài 2: Refactor code ⭐⭐
Chọn 1 bài tập tuần 1–14, refactor lại sạch hơn, có comment, tách hàm, viết test case.

### Bài 3: Peer review ⭐⭐
Review Pull Request của 2 bạn khác trong lớp. Nhận xét về Big-O, code style, edge cases.

### Bài 4: 🔥 Dự Án Lớn — Theater Management System ⭐⭐⭐
> **Cảm hứng:** [Teatro — DanielSantDev/Projects-with-Cpp](https://github.com/DanielSantDev/Projects-with-Cpp)

Xây dựng hệ thống quản lý rạp chiếu phim hoàn chỉnh:

```
=== 🎭 RẠP CHIẾU PHIM STAR CINEMA ===

Phim đang chiếu:
  [1] Avengers: Endgame  — 19:00 — Phòng 1 (còn 45/100 ghế)
  [2] Spider-Man NWH     — 20:30 — Phòng 2 (còn 12/80 ghế)
  [3] Top Gun: Maverick  — 21:00 — Phòng 3 (còn 0/60 ghế — HẾT VÉ)

--- Đặt vé ---
Phim: [1] | Số ghế: 3
Ghế còn trống: A1 A2 A3 B5 B6 C10...
Chọn ghế: A1, A2, A3
Tổng: 3 × 120,000đ = 360,000đ

--- Hàng chờ hoàn vé ---
Dùng Queue: 5 người đang chờ xử lý

--- Thống kê hôm nay ---
Doanh thu: 45,600,000đ | Khách: 380 người | Ghế trống TB: 23%
```

**Cấu trúc dữ liệu sử dụng:**
- `BST` — tìm kiếm phim theo tên (O log n)
- `Queue` — hàng chờ hoàn vé / check-in
- `Stack` — undo thao tác đặt vé
- `2D Array` — sơ đồ ghế ngồi
- `Linked List` — danh sách suất chiếu

**Yêu cầu tối thiểu:** đặt vé, hủy vé, xem sơ đồ ghế, thống kê doanh thu.

---
📁 Tham khảo: `BaiTapUngDung/` và toàn bộ kiến thức 14 tuần
