#include "../src/structures.h"
#include <iostream>
#include <cassert>

using namespace std;

// Test 1: Khởi tạo mê cung thành công
void test_khoi_tao_me_cung() {
    cout << "Running test_khoi_tao_me_cung... ";
    Maze maze(21, 21);
    // Nếu khởi tạo không bị crash và BFS tìm được đường (> 0) thì maze hợp lệ
    int steps = maze.solveBFS(true);
    assert(steps > 0);
    cout << "PASSED\n";
}

// Test 2: Đảm bảo thuật toán luôn có lối giải (Perfect Maze)
void test_bfs_tim_duong_luon_co_loi_giai() {
    cout << "Running test_bfs_tim_duong_luon_co_loi_giai... ";
    Maze maze(51, 51); // Thử với mê cung lớn
    int steps = maze.solveBFS(true);
    assert(steps > 0); 
    cout << "PASSED\n";
}

// Test 3: So sánh tính tối ưu giữa BFS và DFS
void test_so_sanh_bfs_va_dfs() {
    cout << "Running test_so_sanh_bfs_va_dfs... ";
    Maze maze(25, 25);
    int bfs_steps = maze.solveBFS(true);
    int dfs_steps = maze.solveDFS(true);
    // Độ dài đường đi của BFS (ngắn nhất) luôn phải <= DFS
    assert(bfs_steps <= dfs_steps);
    cout << "PASSED\n";
}

// Test 4: Kiểm tra thuật toán A* (Priority Queue) có chính xác không
void test_a_star_toi_uu() {
    cout << "Running test_a_star_toi_uu... ";
    Maze maze(35, 35);
    int bfs_steps = maze.solveBFS(true);
    int a_star_steps = maze.solveAStar(true);
    // A* và BFS đều tìm đường ngắn nhất, nên số bước đi phải bằng nhau chính xác
    assert(bfs_steps == a_star_steps);
    cout << "PASSED\n";
}

// Test 5: Edge Case - Người dùng nhập kích thước chẵn và quá nhỏ
void test_edge_case_kich_thuoc_nho() {
    cout << "Running test_edge_case_kich_thuoc_nho... ";
    // Đưa vào kích thước lỗi (4x4)
    Maze maze(4, 4);
    // Thuật toán của chúng ta phải tự làm tròn lên số lẻ (5x5) và chạy bình thường không crash
    int steps = maze.solveBFS(true);
    assert(steps > 0);
    cout << "PASSED\n";
}

int main() {
    cout << "=== BAT DAU CHAY KIEM THU (UNIT TESTS) ===\n";
    test_khoi_tao_me_cung();
    test_bfs_tim_duong_luon_co_loi_giai();
    test_so_sanh_bfs_va_dfs();
    test_a_star_toi_uu();
    test_edge_case_kich_thuoc_nho();
    cout << "=== TAT CA 5 TEST CASES DEU PASS! ===\n";
    return 0;
}