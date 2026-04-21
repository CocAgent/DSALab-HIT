# Tuần 8: Stack & Ứng Dụng — Bài tập

## 🎯 Mục tiêu tuần này
Cài đặt Stack bằng mảng và Linked List. Ứng dụng Stack trong bài toán thực tế.

---

### Bài 1: Cài đặt Stack ⭐⭐
Cài đặt Stack bằng mảng (array-based) và bằng Linked List. So sánh ưu nhược điểm.

### Bài 2: Kiểm tra ngoặc hợp lệ ⭐⭐
Kiểm tra chuỗi có đóng mở ngoặc `()`, `[]`, `{}` hợp lệ không. Xử lý cả chuỗi code thực tế.

### Bài 3: Chuyển đổi biểu thức ⭐⭐⭐
Chuyển biểu thức Infix → Postfix → Prefix. In từng bước.

### Bài 4: 🔥 Dự Án Mini — Máy Tính Biểu Thức ⭐⭐⭐
> **Cảm hứng:** [Pilha_Expressão_A — DanielSantDev/Projects-with-Cpp](https://github.com/DanielSantDev/Projects-with-Cpp)

Xây dựng máy tính tính biểu thức toán học bằng Stack:
```
=== 🧮 MÁY TÍNH BIỂU THỨC ===
Nhập biểu thức: (3 + 4) * 2 - 8 / 4

Bước 1 — Chuyển sang Postfix: 3 4 + 2 * 8 4 / -
Bước 2 — Tính toán:
  Push 3 → Stack: [3]
  Push 4 → Stack: [3, 4]
  '+' → Pop 4, Pop 3 → Push 7 → Stack: [7]
  Push 2 → Stack: [7, 2]
  '*' → Pop 2, Pop 7 → Push 14 → Stack: [14]
  ...

✅ Kết quả: (3 + 4) * 2 - 8 / 4 = 12
```
**Yêu cầu:** hỗ trợ +, -, *, /, ^, ngoặc đơn, số thập phân, hiển thị từng bước stack.

---
📁 Tham khảo: `Chuong3_DanhSachLienKet/Chuong3_DanhSachLienKet.cpp`
