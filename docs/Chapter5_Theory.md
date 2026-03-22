# 📊 Chương 5: Đồ Thị (Graph)

> **Mục tiêu:** Nắm vững biểu diễn đồ thị, BFS, DFS, Dijkstra và cây khung nhỏ nhất.

---

## 1. Khái Niệm Cơ Bản

### 1.1 Định Nghĩa

> **Đồ thị** G = (V, E) gồm tập đỉnh V (Vertex) và tập cạnh E (Edge).  
> Mỗi cạnh nối 2 đỉnh, có thể có trọng số (weighted).

### 1.2 Phân Loại

```
Đồ Thị
│
├── Theo hướng cạnh
│   ├── Vô hướng (Undirected): A — B (đi được 2 chiều)
│   └── Có hướng (Directed):   A → B (chỉ đi 1 chiều)
│
├── Theo trọng số
│   ├── Không trọng số: chỉ cần biết nối hay không
│   └── Có trọng số:    mỗi cạnh có chi phí (khoảng cách, thời gian...)
│
└── Theo cấu trúc
    ├── Đồ thị liên thông: mọi đỉnh đều có thể đến nhau
    ├── Đồ thị có chu trình (Cyclic)
    └── Đồ thị không chu trình có hướng (DAG)
```

### 1.3 Ví Dụ Thực Tế

| Ứng Dụng | Đỉnh | Cạnh |
|----------|------|------|
| Mạng xã hội | Người dùng | Kết bạn |
| Google Maps | Ngã tư | Đường đi (có trọng số) |
| Internet | Server | Kết nối mạng |
| Bản đồ môn học | Môn học | Môn tiên quyết |

---

## 2. Biểu Diễn Đồ Thị

### 2.1 Ma Trận Kề (Adjacency Matrix)

```
Đồ thị:     0
           /|\
          1 | 2
          | | |
          3   4

Ma trận adj[V][V]:
     0  1  2  3  4
  0 [0, 1, 1, 0, 0]
  1 [1, 0, 0, 1, 0]
  2 [1, 0, 0, 0, 1]
  3 [0, 1, 0, 0, 0]
  4 [0, 0, 1, 0, 0]

adj[u][v] = 1 nếu có cạnh u—v
adj[u][v] = w nếu cạnh có trọng số w
```

**Độ phức tạp:** Không gian O(V²) — tốt cho đồ thị dày (Dense Graph)

### 2.2 Danh Sách Kề (Adjacency List)

```
adj[0]: → 1 → 2
adj[1]: → 0 → 3
adj[2]: → 0 → 4
adj[3]: → 1
adj[4]: → 2
```

**Độ phức tạp:** Không gian O(V + E) — tốt cho đồ thị thưa (Sparse Graph)

### 2.3 So Sánh

| Tiêu Chí | Ma Trận Kề | Danh Sách Kề |
|----------|-----------|-------------|
| Không gian | O(V²) | O(V + E) |
| Kiểm tra u—v | O(1) | O(degree(u)) |
| Duyệt tất cả kề | O(V) | O(degree(u)) |
| Tốt cho | Dense graph | Sparse graph |

---

## 3. BFS — Breadth-First Search

### 3.1 Ý Tưởng

> Duyệt theo từng **mức** (giống duyệt cây theo mức). Dùng **Queue**.

```
Đồ thị:  0 — 1 — 3
         |   |
         2 — 4

BFS từ đỉnh 0:
  Bước 1: Queue=[0], visited={0}
  Bước 2: Dequeue 0 → thêm {1,2} → Queue=[1,2], kết quả: 0
  Bước 3: Dequeue 1 → thêm {3,4} → Queue=[2,3,4], kết quả: 0 1
  Bước 4: Dequeue 2 → (4 đã thăm) → Queue=[3,4], kết quả: 0 1 2
  Bước 5: Dequeue 3 → Queue=[4], kết quả: 0 1 2 3
  Bước 6: Dequeue 4 → Queue=[], kết quả: 0 1 2 3 4 ✅
```

**Độ phức tạp:** O(V + E)

**Ứng dụng:**
- Tìm đường đi ngắn nhất (không trọng số)
- Kiểm tra đồ thị liên thông
- Level-order traversal của cây

---

## 4. DFS — Depth-First Search

### 4.1 Ý Tưởng

> Đi càng sâu càng tốt trước khi quay lui. Dùng **Stack** (hoặc đệ quy).

```
DFS từ đỉnh 0 (đệ quy):
  visit(0) → visit(1) → visit(3) [leaf, quay lui]
           → visit(4) → visit(2) [quay lui]
           [quay lui]
  
Thứ tự: 0 → 1 → 3 → 4 → 2
```

**Độ phức tạp:** O(V + E)

**Ứng dụng:**
- Phát hiện chu trình
- Sắp xếp topo (DAG)
- Tìm thành phần liên thông mạnh

---

## 5. Dijkstra — Đường Đi Ngắn Nhất

### 5.1 Ý Tưởng

> Tìm đường đi ngắn nhất từ đỉnh nguồn đến **tất cả** đỉnh còn lại.  
> Yêu cầu: **trọng số không âm**.

```
Đồ thị có trọng số:
    0 ──4── 1
    |       |
    2       3
    └──1──2─┘

dist[] ban đầu: [0, ∞, ∞, ∞]
visited[]:      [F, F, F, F]

Bước 1: chọn u=0 (dist nhỏ nhất chưa thăm)
  dist[1] = min(∞, 0+4) = 4
  dist[2] = min(∞, 0+2) = 2
  dist[3] = min(∞, 0+∞) = ∞

Bước 2: chọn u=2 (dist=2, nhỏ nhất)
  dist[3] = min(∞, 2+1) = 3

Bước 3: chọn u=3 (dist=3)
  dist[1] = min(4, 3+3) = 4 (không cải thiện)

Kết quả: dist = [0, 4, 2, 3] ✅
```

**Độ phức tạp:**
- Ma trận kề: O(V²)
- Priority queue + danh sách kề: O((V+E) log V)

---

## 6. Cây Khung Nhỏ Nhất (MST)

### 6.1 Bài Toán

> Cho đồ thị vô hướng có trọng số. Tìm cây khung (spanning tree) có tổng trọng số **nhỏ nhất**.  
> Ứng dụng: thiết kế mạng lưới điện, viễn thông, đường ống.

### 6.2 Kruskal's Algorithm

```
Ý tưởng: Sắp xếp tất cả cạnh theo trọng số tăng dần.
          Lần lượt thêm cạnh nhỏ nhất nếu không tạo chu trình.
          (Dùng Union-Find để kiểm tra chu trình)

Cạnh sắp xếp: (1,2,1), (2,3,2), (0,3,3), (0,1,4), (1,3,5)
Thêm (1,2,1): OK → MST: {(1,2)}
Thêm (2,3,2): OK → MST: {(1,2),(2,3)}
Thêm (0,3,3): OK → MST: {(1,2),(2,3),(0,3)} ✅ (V-1=3 cạnh)

Tổng trọng số MST = 1+2+3 = 6
```

**Độ phức tạp:** O(E log E)

### 6.3 Prim's Algorithm

```
Ý tưởng: Bắt đầu từ một đỉnh, liên tục thêm cạnh
          nhỏ nhất nối vào cây đang xây.

Tương tự Dijkstra nhưng key[u] = trọng số cạnh nhỏ nhất nối vào MST.
Độ phức tạp: O(V²) hoặc O(E log V) với priority queue.
```

---

## 7. Tổng Kết

| Thuật Toán | Mục Đích | Độ Phức Tạp |
|-----------|---------|------------|
| BFS | Duyệt + đường ngắn nhất (không trọng số) | O(V+E) |
| DFS | Duyệt + phát hiện chu trình | O(V+E) |
| Dijkstra | Đường ngắn nhất (trọng số ≥ 0) | O((V+E)logV) |
| Bellman-Ford | Đường ngắn nhất (trọng số âm) | O(VE) |
| Kruskal | Cây khung nhỏ nhất | O(E log E) |
| Prim | Cây khung nhỏ nhất | O(E log V) |

---

## 8. Bài Tập Tự Luyện

### Cơ Bản
1. Biểu diễn đồ thị 5 đỉnh, 7 cạnh bằng ma trận kề và danh sách kề.
2. BFS từ đỉnh 0, tìm khoảng cách đến tất cả đỉnh.
3. Kiểm tra đồ thị có liên thông không bằng DFS.

### Nâng Cao
4. Phát hiện chu trình trong đồ thị có hướng (dùng DFS + màu sắc).
5. Sắp xếp topo của DAG (Topological Sort).
6. Tìm thành phần liên thông mạnh (Kosaraju's Algorithm).

---

*📌 File code: [`src/Chapter5_Graph/Chapter5_Graph.cpp`](../src/Chapter5_Graph/Chapter5_Graph.cpp)*
