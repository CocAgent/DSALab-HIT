# Tuần 3: Tìm Kiếm — Bài tập

## 🎯 Mục tiêu tuần này
Cài đặt và so sánh Linear Search, Binary Search và các biến thể.

---

### Bài 1: Linear Search ⭐
Tìm kiếm tuyến tính trên mảng số nguyên và mảng chuỗi. Đếm số bước so sánh.

### Bài 2: Binary Search ⭐⭐
Cài đặt Binary Search iterative + recursive. Tìm vị trí đầu tiên và cuối cùng của phần tử trùng.

### Bài 3: So sánh hiệu năng ⭐⭐
Đo thời gian tìm kiếm với n = 10.000, 100.000, 1.000.000 phần tử. Vẽ bảng so sánh.

### Bài 4: 🔥 Dự Án Mini — Smart Search Engine ⭐⭐⭐
> **Cảm hứng:** [Brute Force Search — algorithm-visualizer](https://algorithm-visualizer.org)

Xây dựng hệ thống tìm kiếm danh bạ điện thoại:
- **Tìm theo tên:** Linear Search (hỗ trợ tìm kiếm mờ — chứa chuỗi con)
- **Tìm theo số điện thoại:** Binary Search (sau khi sort theo SĐT)
- **Thống kê:** hiển thị số bước so sánh, thời gian tìm kiếm
- **Gợi ý:** nếu không tìm thấy, gợi ý 3 tên gần giống nhất

```
Nhập tên cần tìm: "Minh"
→ Tìm thấy 3 kết quả:
   1. Nguyễn Văn Minh   - 0901234567
   2. Trần Thị Minh Anh - 0912345678
   3. Lê Minh Tuấn      - 0923456789
   (Đã so sánh 15/50 phần tử — 0.002ms)
```

---
📁 Tham khảo: `Chuong2_TimKiem_SapXep/Chuong2_TimKiem_SapXep.cpp`
