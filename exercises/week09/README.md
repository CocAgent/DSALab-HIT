# Tuần 9: Queue & Ứng Dụng — Bài tập

## 🎯 Mục tiêu tuần này
Cài đặt Queue và Priority Queue. Ứng dụng trong bài toán hàng chờ thực tế.

---

### Bài 1: Cài đặt Queue ⭐⭐
Cài đặt Queue bằng mảng vòng (circular array) và Linked List. Hỗ trợ enqueue, dequeue, peek, is_full, is_empty.

### Bài 2: Deque (Double-ended Queue) ⭐⭐
Cài đặt Deque — thêm/xóa cả 2 đầu. Ứng dụng: kiểm tra palindrome.

### Bài 3: Priority Queue ⭐⭐⭐
Cài đặt Priority Queue bằng mảng. Phần tử ưu tiên cao nhất được lấy ra trước. Ứng dụng: hàng chờ bệnh viện có phân cấp ưu tiên.

### Bài 4: 🔥 Dự Án Mini — Hệ Thống Hàng Chờ Bệnh Viện ⭐⭐⭐
> **Cảm hứng:** [Fila de Hospital — DanielSantDev/Projects-with-Cpp](https://github.com/DanielSantDev/Projects-with-Cpp)

Mô phỏng hệ thống hàng chờ bệnh viện với **Priority Queue**:
```
=== 🏥 HỆ THỐNG HÀNG CHỜ BỆNH VIỆN ===
Mức ưu tiên: 🔴 Cấp cứu > 🟡 Khẩn > 🟢 Thường

Bệnh nhân mới: Nguyễn Văn A — 🔴 Cấp cứu
→ Chèn lên đầu hàng chờ!

Bệnh nhân mới: Trần Thị B — 🟢 Thường
→ Xếp vào cuối hàng

Gọi tiếp theo...
✅ Mời: Nguyễn Văn A (🔴 Cấp cứu) — Phòng khám 3

Hàng chờ hiện tại (5 người):
🟡 [1] Lê Văn C  — Khẩn   — Chờ: 8 phút
🟡 [2] Phạm D    — Khẩn   — Chờ: 3 phút
🟢 [3] Hoàng E   — Thường — Chờ: 15 phút
```
**Yêu cầu:** 3 mức ưu tiên, hiển thị thời gian chờ, thống kê cuối ca (tổng bệnh nhân, thời gian chờ TB).

---
📁 Tham khảo: `Chuong3_DanhSachLienKet/Chuong3_DanhSachLienKet.cpp`
