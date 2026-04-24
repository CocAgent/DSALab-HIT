# Tuần 13: Graph Cơ Bản — Bài tập

## 🎯 Mục tiêu tuần này
Biểu diễn graph, cài đặt BFS và DFS, ứng dụng tìm đường đi.

---

### Bài 1: Biểu diễn Graph ⭐⭐
Cài đặt Graph bằng Adjacency List và Adjacency Matrix. Chuyển đổi giữa 2 dạng. In ra màn hình.

### Bài 2: BFS & DFS ⭐⭐
Cài đặt BFS (dùng Queue) và DFS (dùng Stack + đệ quy). Duyệt từ đỉnh cho trước, in thứ tự duyệt.

### Bài 3: Phát hiện chu trình ⭐⭐⭐
Phát hiện chu trình trong graph có hướng và vô hướng. Tìm các thành phần liên thông.

### Bài 4: 🔥 Dự Án Mini — Tìm Đường Ngắn Nhất (BFS) ⭐⭐⭐
> **Cảm hứng:** [BFS — algorithm-visualizer.org](https://algorithm-visualizer.org/simple-recursive/breadth-first-search)

Tìm đường đi ngắn nhất trong mê cung bằng BFS:
```
=== 🗺️ TÌM ĐƯỜNG TRONG MÊ CUNG (BFS) ===
Bản đồ (S=Xuất phát, E=Đích, #=Tường):

  S . . # . . .
  # # . # . # .
  . . . . . # .
  . # # # . . .
  . . . . # . E

Đang tìm đường... ✅ Tìm thấy!
Đường ngắn nhất: S → (0,1) → (0,2) → (1,2) → ... → E
Độ dài: 12 bước

Hiển thị đường đi:
  S ★ ★ # . . .
  # # ★ # . # .
  . . ★ ★ ★ # .
  . # # # ★ ★ .
  . . . . # ★ E
```

---
📁 Tham khảo: Kiến thức mới — tạo file `Graph/Graph.cpp`
