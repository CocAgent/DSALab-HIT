# 📕 Chương 4: Cấu Trúc Dữ Liệu Cây

> **Mục tiêu:** Hiểu cây nhị phân, 3 phương pháp duyệt, và BST.

---

## 1. Các Khái Niệm Cơ Bản

### 1.1 Cây Tổng Quát

```
            [A]          ← gốc (root)
           / | \
         [B][C][D]       ← mức 1
         /|     \
       [E][F]   [G]      ← mức 2
```

### 1.2 Thuật Ngữ Quan Trọng

| Thuật Ngữ | Định Nghĩa | Ví Dụ |
|-----------|-----------|-------|
| **Root** | Nút gốc — không có cha | A |
| **Leaf** | Nút lá — không có con | E, F, C, G |
| **Parent** | Nút cha | A là cha của B, C, D |
| **Child** | Nút con | B, C, D là con của A |
| **Height** | Chiều cao = số mức tối đa | 3 (trong ví dụ) |
| **Degree** | Bậc = số con | deg(A)=3, deg(B)=2 |
| **Depth** | Độ sâu của nút | depth(E) = 2 |

---

## 2. Cây Nhị Phân (Binary Tree)

### 2.1 Định Nghĩa

> Cây nhị phân: mỗi nút có **tối đa 2 con** (trái và phải).

```cpp
struct TreeNode {
    int data;
    TreeNode *left;    // con trái
    TreeNode *right;   // con phải
};
```

### 2.2 Lưu Trữ Bằng Mảng

```
Cây:       [1]
          /    \
        [2]    [3]
        / \    /
      [4] [5][6]

Mảng: index  0  1  2  3  4  5  6
              1  2  3  4  5  6  -

Quy tắc: con trái của a[i] = a[2i+1]
          con phải của a[i] = a[2i+2]
          cha của a[i]       = a[(i-1)/2]
```

---

## 3. Các Phương Pháp Duyệt Cây

### 3.1 Pre-order (NLR — Gốc Trước)

```
Thứ tự: Gốc → Trái → Phải

       [1]
      /   \
    [2]   [3]
    / \
  [4] [5]

NLR: 1 → 2 → 4 → 5 → 3
Ứng dụng: Copy cây, in biểu thức prefix
```

### 3.2 In-order (LNR — Gốc Giữa)

```
Thứ tự: Trái → Gốc → Phải

LNR: 4 → 2 → 5 → 1 → 3
Ứng dụng: In BST theo thứ tự tăng dần ✅
```

### 3.3 Post-order (LRN — Gốc Sau)

```
Thứ tự: Trái → Phải → Gốc

LRN: 4 → 5 → 2 → 3 → 1
Ứng dụng: Xóa cây (xóa con trước cha), tính biểu thức postfix
```

### 3.4 Level-order (BFS)

```
Duyệt theo từng mức (dùng Queue):
Mức 0: 1
Mức 1: 2, 3
Mức 2: 4, 5

Kết quả: 1 → 2 → 3 → 4 → 5
Ứng dụng: In cây theo hình thức cây thực
```

---

## 4. Cây Nhị Phân Tìm Kiếm (BST)

### 4.1 Tính Chất BST

```
Với mọi nút N:
  - Tất cả nút trong cây con TRÁI có giá trị < N
  - Tất cả nút trong cây con PHẢI có giá trị > N

Ví dụ BST hợp lệ:
           [8]
          /   \
        [3]   [10]
        / \      \
      [1] [6]    [14]
          / \    /
        [4] [7][13]
```

### 4.2 Độ Phức Tạp BST

| Thao tác | BST cân bằng | BST lệch (worst) |
|----------|-------------|-----------------|
| Tìm kiếm | O(log N) | O(N) |
| Chèn | O(log N) | O(N) |
| Xóa | O(log N) | O(N) |

> **Lưu ý:** BST có thể suy biến thành danh sách liên kết nếu chèn theo thứ tự sắp xếp!

### 4.3 Thao Tác Xóa (3 Trường Hợp)

```
TH1: Nút lá → xóa trực tiếp
TH2: Có 1 con → thay bằng con đó
TH3: Có 2 con → thay bằng phần tử nhỏ nhất cây con phải
                 (hoặc lớn nhất cây con trái)

Ví dụ xóa nút 3 (có 2 con):
  Trước:  [8]         Sau:   [8]
           / \                / \
         [3] [10]    →      [4] [10]
         / \                / \     \
       [1] [6]           [1] [6]   [14]
           / \                 \
         [4] [7]               [7]
  successor(3) = 4 (nhỏ nhất cây con phải của 3)
```

---

## 5. Bài Tập Tự Luyện

### Cơ Bản
1. Vẽ BST sau khi chèn: `10, 5, 15, 3, 7, 12, 20`
2. Duyệt cây trên theo In-order, Pre-order, Post-order.
3. Đếm số lá của cây.

### Nâng Cao
4. Kiểm tra 2 cây nhị phân có giống nhau không.
5. Tìm LCA (Lowest Common Ancestor) của 2 nút.
6. Chuyển BST thành danh sách liên kết sắp xếp.

---

*📌 File code: [`src/Chapter4_Tree/Chapter4_Tree.cpp`](../src/Chapter4_Tree/Chapter4_Tree.cpp)*
