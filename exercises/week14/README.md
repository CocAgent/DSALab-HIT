# Tuần 14: Dynamic Programming — Bài tập

## 🎯 Mục tiêu tuần này
Tư duy DP: overlapping subproblems + optimal substructure, top-down và bottom-up.

---

### Bài 1: DP 1 chiều ⭐⭐
Fibonacci với memoization, Climbing Stairs, House Robber. So sánh đệ quy naive vs DP.

### Bài 2: DP 2 chiều ⭐⭐⭐
Longest Common Subsequence (LCS) và Edit Distance. In bảng DP và truy vết kết quả.

### Bài 3: Coin Change ⭐⭐⭐
Đếm số cách đổi tiền và tìm số đồng xu ít nhất. Truy vết các đồng xu đã dùng.

### Bài 4: 🔥 Dự Án Mini — Bài Toán Cái Túi (0/1 Knapsack) ⭐⭐⭐
> **Cảm hứng:** [Dynamic Programming — algorithm-visualizer.org](https://algorithm-visualizer.org/dynamic-programming/knapsack-problem)

Giải bài toán Knapsack với trực quan hóa bảng DP:
```
=== 🎒 BÀI TOÁN CÁI TÚI ===
Sức chứa túi: 10kg

Danh sách đồ vật:
  #  Tên          Trọng lượng  Giá trị
  1  Laptop       3kg          2000$
  2  Camera       1kg          500$
  3  Sách         2kg          300$
  4  Quần áo      4kg          600$
  5  Giày         2kg          400$

Bảng DP (capacity 0→10):
     0    1    2    3    4    5    6    7    8    9   10
  0  0    0    0    0    0    0    0    0    0    0    0
  1  0    0    0 2000 2000 2000 2000 2000 2000 2000 2000
  2  0  500  500 2000 2500 2500 2500 2500 2500 2500 2500
  ...

✅ Giá trị tối đa: 3300$
   Chọn: Laptop (3kg) + Camera (1kg) + Giày (2kg) + Quần áo (4kg) = 10kg
```

---
📁 Tham khảo: Kiến thức mới — tạo file `DynamicProg/Knapsack.cpp`
