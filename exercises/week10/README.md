# Tuần 10: Cây Nhị Phân — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu cây nhị phân, cài đặt duyệt cây (Pre/In/Post-order và BFS Level-order).

---

### Bài 1: Xây dựng cây nhị phân ⭐⭐
Xây dựng cây từ mảng (biểu diễn heap). Tính chiều cao, đếm nút lá, nút trong.

### Bài 2: Duyệt cây đủ 4 cách ⭐⭐
Cài đặt Pre-order, In-order, Post-order (đệ quy + iterative), Level-order (BFS bằng Queue).

### Bài 3: Tính chất cây ⭐⭐⭐
Kiểm tra cây cân bằng (Balanced), cây đối xứng (Symmetric), tìm Lowest Common Ancestor.

### Bài 4: 🔥 Dự Án Mini — BST Visualizer (Console) ⭐⭐⭐
> **Cảm hứng:** [algorithm-visualizer.org — BST Visualization](https://algorithm-visualizer.org)

Hiển thị cây nhị phân trực quan trong terminal:
```
=== 🌳 BINARY TREE VISUALIZER ===
Nhập: insert 50 30 70 20 40 60 80

        50
       /   \
     30     70
    / \    / \
  20  40  60  80

Duyệt In-order:  20 → 30 → 40 → 50 → 60 → 70 → 80
Duyệt Pre-order: 50 → 30 → 20 → 40 → 70 → 60 → 80
Chiều cao: 3 | Số nút: 7 | Cân bằng: ✅
```
**Yêu cầu:** in cây dạng ASCII đẹp, hiển thị kết quả 4 loại duyệt, tính các thông số cây.

---
📁 Tham khảo: `Chuong4_CauTrucCay/Chuong4_CauTrucCay.cpp`
