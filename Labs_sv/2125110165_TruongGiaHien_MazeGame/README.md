## Tên ứng dụng
**Maze Game Pathfinding** - Đồ án cuối kỳ Cấu trúc Dữ liệu & Giải thuật.
Trò chơi tạo mê cung ngẫu nhiên và so sánh trực quan hiệu năng của các thuật toán tìm đường (BFS, DFS, A*).

## Cấu trúc dữ liệu sử dụng
- **2D Array / Graph:** Dùng để lưu trữ bản đồ mê cung (lưới tọa độ). Cho phép truy xuất nhanh các ô xung quanh (O(1)).
- **Stack:** Dùng để sinh mê cung (DFS Recursive Backtracker) và giải mê cung (DFS Pathfinding) vì tính chất LIFO hỗ trợ cơ chế Quay lui (Backtracking).
- **Queue:** Dùng để tìm đường ngắn nhất (BFS) vì tính chất FIFO giúp thuật toán loang đều ra mọi hướng cùng một lúc.
- **Priority Queue (Min-Heap):** Dùng cho thuật toán tìm đường A*. Sắp xếp ưu tiên các Node có tổng chi phí dự đoán thấp nhất lên đầu để duyệt trước, giúp tìm đường tối ưu bộ nhớ hơn BFS.

## Compile và chạy
**Chạy ứng dụng chính:**
g++ -std=c++17 src/main.cpp src/functions.cpp -o app && ./app

**Chạy file Kiểm thử (Unit Tests):**
g++ -std=c++17 tests/test_cases.cpp src/functions.cpp -o test_app && ./test_app

## Chức năng
1. Hiển thị Mê cung trực quan trên Terminal.
2. Sinh mê cung ngẫu nhiên không có vòng lặp (Perfect Maze).
3. Người chơi tự giải bằng phím W/A/S/D.
4. Tự động tìm đường ngắn nhất bằng BFS.
5. Tự động tìm đường bằng DFS (thể hiện sự vòng vèo do backtracking).
6. Tự động tìm đường bằng A* (Dùng Priority Queue và Heuristic Manhattan).
7. So sánh hiệu năng (số bước đi) giữa BFS và DFS.
8. Bẫy lỗi nhập sai trên Menu và điều chỉnh kích thước tùy ý.

## Test cases
Đã triển khai 5 test case chính sử dụng `<cassert>`:
1. `test_khoi_tao_me_cung`: Đảm bảo mê cung sinh ra luôn hợp lệ và có đường đi.
2. `test_bfs_tim_duong_luon_co_loi_giai`: Test khả năng chạy trên ma trận lớn (51x51).
3. `test_so_sanh_bfs_va_dfs`: Đảm bảo chiều dài đường đi BFS <= DFS.
4. `test_a_star_toi_uu`: Đảm bảo A* tìm ra kết quả chính xác bằng với BFS.
5. `test_edge_case_kich_thuoc_nho`: Test nhập kích thước chẵn và nhỏ (4x4), hệ thống tự fix thành (5x5) và không crash.

## Cấu trúc file
src/
   main.cpp         - Menu, điều khiển vòng lặp và bẫy lỗi input
   structures.h     - Khai báo struct (Point, AStarNode) và nguyên mẫu class Maze
   functions.cpp    - Cài đặt chi tiết các thuật toán DFS, BFS, A*
tests/
   test_cases.cpp   - Chứa 5 kịch bản kiểm thử tự động
README.md           - Tài liệu báo cáo project