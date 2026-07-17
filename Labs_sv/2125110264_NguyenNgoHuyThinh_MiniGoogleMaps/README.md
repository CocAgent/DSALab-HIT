# Mini Google Maps — Shortest Path Finder

**Môn:** Cấu Trúc Dữ Liệu & Giải Thuật  
**Sinh viên:** Nguyễn Ngô Huy Thịnh — MSSV: 2125110264  
**Ngôn ngữ:** C++ (g++ -std=c++17)

---

## Mô tả đề tài

Chương trình mô phỏng bản đồ đơn giản dạng đồ thị vô hướng có trọng số. Người dùng có thể thêm địa điểm, thêm đường đi, và tìm đường ngắn nhất giữa hai địa điểm bằng nhiều thuật toán khác nhau.

---

## Cấu trúc thư mục

```
src/
├── structures.h      ← Khai báo biến global, extern, nguyên mẫu hàm
├── functions.cpp     ← Cài đặt toàn bộ logic: Dijkstra, BFS, DFS
└── main.cpp          ← Menu điều khiển chương trình

tests/
└── test_cases.cpp    ← 5 test case kiểm tra tính đúng đắn
```

---

## Cấu trúc dữ liệu sử dụng

| Cấu trúc | Mục đích |
|---|---|
| `vector<vector<pair<int,int>>>` | Adjacency List biểu diễn đồ thị |
| `priority_queue` (min-heap) | Dijkstra — luôn xử lý node gần nhất trước |
| `queue` | BFS — duyệt theo tầng |
| `stack` | In lại đường đi từ mảng parent[] |
| `vector<int> parent[]` | Lưu node cha để truy vết đường đi |

---

## Tính năng

1. Thêm địa điểm (node)
2. Thêm đường đi (cạnh có trọng số)
3. Hiển thị bản đồ
4. Tìm đường ngắn nhất — **Dijkstra** `O((V+E) log V)`
5. Tìm đường ít điểm nhất — **BFS** `O(V+E)`
6. Khám phá các điểm có thể đến — **DFS** `O(V+E)`

---

## Compile & Chạy

```bash
# Compile
g++ -std=c++17 main.cpp functions.cpp -o maps

# Chạy chương trình
./maps

# Chạy test cases
g++ -std=c++17 tests/test_cases.cpp -o test
./test
```

---

## Ví dụ sử dụng

```
Them dia diem: HaNoi
Them dia diem: HueCit
Them dia diem: HCM
Them duong: HaNoi -> HueCit (600 km)
Them duong: HueCit -> HCM (900 km)
Them duong: HaNoi -> HCM (1700 km)

Dijkstra HaNoi -> HCM:
  Khoang cach: 1500 km
  Duong di: HaNoi -> HueCit -> HCM
```

---

## Giải thích thuật toán

**Dijkstra:** Khởi tạo khoảng cách nguồn = 0, còn lại = INF. Dùng min-heap để luôn xử lý node gần nhất. Cập nhật dist[v] nếu tìm được đường ngắn hơn qua u.

**BFS:** Duyệt theo tầng, đảm bảo đường đi tìm được có số node trung gian ít nhất.

**DFS:** Đệ quy từ node nguồn, đánh dấu visited để tránh lặp vô hạn.

**Truy vết đường đi:** Mảng `parent[]` lưu node cha. Đi ngược từ đích về nguồn, đẩy vào Stack rồi pop ra để in đúng thứ tự.