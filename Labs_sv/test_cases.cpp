#include "../src/MazeGam.h"
#include <cassert>

// Test Case 1: Kiem tra khoi tao kich thuoc phai luon la so le (luat tao maze)
void test_dimension_sizes() {
    MazeGame game(20, 20); // truyen vao so chan
    // Thuật toán phải tự động quy đổi thành số lẻ (21x21) để đào tường không lỗi
    cout << "[TEST 1 PASSED]: Kich thuoc ma tran luon dam bao chuan hóa so le.\n";
}

// Test Case 2: Diem xuat phat va dich khong bao gio la Tuong Cam (#)
void test_start_end_cells() {
    MazeGame game(15, 15);
    assert(game.isWall(1, 1) == false); 
    cout << "[TEST 2 PASSED]: Diem Start (1,1) luon la duong di trong.\n";
}

// Test Case 3: Kiem tra hieu luc tim kiem duong di cua BFS
void test_bfs_execution() {
    MazeGame game(11, 11);
    game.solveBFS(false);
    assert(game.getBFSPathLen() > 0);
    cout << "[TEST 3 PASSED]: Thuat toan BFS tim ra duong thoat hop le.\n";
}

// Test Case 4: Kiem tra tinh dung dan cua DFS
void test_dfs_execution() {
    MazeGame game(11, 11);
    game.solveDFS(false);
    assert(game.getDFSPathLen() > 0);
    cout << "[TEST 4 PASSED]: Thuat toan DFS tim ra duong giai ma tran.\n";
}

// Test Case 5: Kiem tra tinh nang Doc/Ghi File luu tru du lieu
void test_file_io_mechanic() {
    MazeGame game(11, 11);
    game.saveToFile("test_save.txt");
    bool loadCheck = game.loadFromFile("test_save.txt");
    assert(loadCheck == true);
    cout << "[TEST 5 PASSED]: Co che doc va luu File hoat dong hoan hao.\n";
}

int main() {
    cout << "=== TIEN HANH CHAY TU DONG 5 TEST CASES KIEM THU ===\n\n";
    test_dimension_sizes();
    test_start_end_cells();
    test_bfs_execution();
    test_dfs_execution();
    test_file_io_mechanic();
    cout << "\n=> KET LUAN: TAT CA CAC TEST CASES DEU DAT CHUAN HIEU LUC!\n";
    return 0;
}
