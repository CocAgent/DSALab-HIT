# Tuần 2: Mảng & Con Trỏ — Bài tập

## 🎯 Mục tiêu tuần này
Thành thạo mảng 1D/2D, con trỏ, cấp phát động trong C++.

---

### Bài 1: Mảng cơ bản ⭐
Nhập mảng n phần tử. Tính min, max, trung bình, tổng. Không dùng STL.
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    // Kiem tra dieu kien dau vao hop le
    if (n <= 0) {
        cout << "So luong phan tu khong hop le!\n";
        return 1;
    }

    // Cap phat dong mot mang n phan tu tren vung nho Heap (Khong dung STL vector)
    int* arr = new int[n];

    // Nhap du lieu cho mang
    cout << "Nhap " << n << " so nguyen:\n";
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    // --- THUẬT TOÁN TÍNH TOÁN ---
    
    // Khoi tao gia tri ban dau bang phan tu dau tien cua mang
    int min_val = arr[0];
    int max_val = arr[0];
    long long tong = 0; // Dung long long de tranh tran so (integer overflow) khi n lon

    for (int i = 0; i < n; i++) {
        // 1. Tim Min
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        
        // 2. Tim Max
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        
        // 3. Tich luy tong
        tong += arr[i];
    }

    // Tinh trung binh (ep kieu double de co phan thap phan chinh xac)
    double trung_binh = static_cast<double>(tong) / n;

    // --- IN KẾT QUẢ ---
    cout << "\n================ KET QUA ================\n";
    cout << "Tong:        " << tong << "\n";
    cout << "Trung binh:  " << trung_binh << "\n";
    cout << "Min:         " << min_val << "\n";
    cout << "Max:         " << max_val << "\n";
    cout << "=========================================\n";

    // Giai phong vung nho dynamic array de tranh ro ri bo nho (Memory Leak)
    delete[] arr;
    arr = nullptr; // Xoa con tro troi dac

    return 0;
}
### Bài 2: Mảng 2D ⭐⭐
Nhân 2 ma trận n×n. Tính định thức ma trận 3×3. Hiển thị đẹp.
#include <iostream>
#include <iomanip>

using namespace std;

// --- 1. HÀM HIỂN THỊ MA TRẬN ĐẸP ---
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        cout << "  [ ";
        for (int j = 0; j < n; j++) {
            cout << setw(6) << matrix[i][j] << " "; // Căn lề mỗi ô số rộng 6 ký tự
        }
        cout << "]\n";
    }
}

// --- 2. HÀM NHÂN HAI MA TRẬN n x n ---
int** multiplyMatrices(int** A, int** B, int n) {
    // Cấp phát động ma trận kết quả C kích thước n x n
    int** C = new int*[n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n]{0}; // Khởi tạo tất cả phần tử bằng 0
    }

    // Thuật toán nhân ma trận cốt lõi
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// --- 3. HÀM TÍNH ĐỊNH THỨC MA TRẬN 3x3 (Quy tắc Sarrus)
int determinant3x3(int** M) {
    // Công thức triển khai: 
    // det = a(ei - fh) - b(di - fg) + c(dh - eg)
    int positive_diagonal = M[0][0]*M[1][1]*M[2][2] + M[0][1]*M[1][2]*M[2][0] + M[0][2]*M[1][0]*M[2][1];
    int negative_diagonal = M[0][2]*M[1][1]*M[2][0] + M[0][0]*M[1][2]*M[2][1] + M[0][1]*M[1][0]*M[2][2];
    
    return positive_diagonal - negative_diagonal;
}

// --- HÀM GIẢI PHÓNG BỘ NHỚ ---
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int n;
    cout << "Nhap kich thuoc ma trien vuong n: ";
    cin >> n;

    if (n <= 0) return 1;

    // Cấp phát động cho Ma trận A và Ma trận B
    int** A = new int*[n];
    int** B = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
    }

    // Nhập dữ liệu ma trận A
    cout << "\n--- Nhap Ma Tran A ---\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    // Nhập dữ liệu ma trận B
    cout << "\n--- Nhap Ma Tran B ---\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    // Thực hiện phép nhân
    int** C = multiplyMatrices(A, B, n);

    // Hiển thị kết quả dạng bảng đẹp
    cout << "\n--> Ma Tran A:\n"; printMatrix(A, n);
    cout << "\n--> Ma Tran B:\n"; printMatrix(B, n);
    cout << "\n======= KET QUA PHEP NHAN (A x B) =======\n";
    printMatrix(C, n);
    cout << "=========================================\n";

    // Xử lý riêng bài toán tính Định thức nếu người dùng nhập n = 3
    if (n == 3) {
        cout << "\n[Phan Mo Rong]: Vi n = 3, He thong tu dong tinh dinh thuc:\n";
        cout << "> Det(A) = " << determinant3x3(A) << "\n";
        cout << "> Det(B) = " << determinant3x3(B) << "\n";
    } else {
        cout << "\n[Luu y]: Tinh nang tinh dinh thuc chi kich hoat khi n = 3.\n";
    }

    // Thu dọn bộ nhớ tránh rò rỉ (Memory Leak)
    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}
### Bài 3: Con trỏ & cấp phát động ⭐⭐
Cài đặt mảng động tự resize (như `std::vector` đơn giản). Hỗ trợ push_back, pop_back, at(i).
#include <iostream>
#include <stdexcept> // Dùng cho std::out_of_range khi kiểm tra lỗi chỉ mục

using namespace std;

struct MyVector {
    int* data;          // Con trỏ quản lý mảng vùng nhớ Heap
    int current_size;   // Số lượng phần tử hiện tại đang chứa
    int max_capacity;   // Sức chứa tối đa hiện tại của vùng nhớ đã cấp phát

    // 1. Khởi tạo cấu trúc dữ liệu ban đầu
    void init(int initial_capacity = 4) {
        max_capacity = initial_capacity;
        current_size = 0;
        data = new int[max_capacity]; // Cấp phát vùng nhớ ban đầu
    }

    // 2. Hàm cốt lõi: Tự động nhân đôi sức chứa khi bộ nhớ đầy
    void resize() {
        max_capacity *= 2; // Nhân đôi sức chứa (Chiến lược tăng trưởng của std::vector)
        int* new_data = new int[max_capacity];

        // Sao chép toàn bộ dữ liệu cũ sang vùng nhớ mới rộng hơn
        for (int i = 0; i < current_size; i++) {
            new_data[i] = data[i];
        }

        // Giải phóng vùng nhớ cũ để tránh rò rỉ bộ nhớ (Memory Leak)
        delete[] data;

        // Trỏ con trỏ quản lý sang vùng nhớ mới
        data = new_data;
    }

    // 3. Thêm phần tử vào cuối mảng
    void push_back(int value) {
        // Nếu số lượng phần tử đạt đến giới hạn sức chứa, tiến hành cấp phát lại
        if (current_size == max_capacity) {
            resize();
        }
        data[current_size] = value;
        current_size++;
    }

    // 4. Xóa phần tử cuối cùng
    void pop_back() {
        if (current_size > 0) {
            current_size--; // Chỉ cần giảm size, phần tử cũ sẽ bị ghi đè ở lần push_back sau
        }
    }

    // 5. Truy cập phần tử có kiểm tra an toàn biên mảng
    int at(int index) {
        if (index < 0 || index >= current_size) {
            throw out_of_range("Chi muc nam ngoai pham vi cua mang (Index out of bounds)!");
        }
        return data[index];
    }

    // 6. Giải phóng toàn bộ bộ nhớ khi không còn sử dụng
    void free() {
        delete[] data;
        data = nullptr;
        current_size = 0;
        max_capacity = 0;
    }
};

int main() {
    MyVector vec;
    vec.init(2); // Khởi tạo mảng động với sức chứa ban đầu rất nhỏ (= 2) để test resize

    cout << "--- Thêm phần tử và quan sát cơ chế mở rộng bộ nhớ ---\n";
    for (int i = 1; i <= 5; i++) {
        vec.push_back(i * 10);
        cout << "Da push " << i * 10 
             << " | Size: " << vec.current_size 
             << " | Capacity: " << vec.max_capacity << "\n";
    }

    cout << "\n--- Truy cập phần tử qua hàm at(i) ---\n";
    for (int i = 0; i < vec.current_size; i++) {
        cout << "vec.at(" << i << ") = " << vec.at(i) << "\n";
    }

    cout << "\n--- Thử nghiệm hàm pop_back() ---\n";
    vec.pop_back();
    cout << "Sau khi pop_back, kích thước mới: " << vec.current_size << "\n";
    cout << "Phần tử cuối hiện tại: " << vec.at(vec.current_size - 1) << "\n";

    // Thử nghiệm bẫy lỗi biên (Kích hoạt exception)
    try {
        cout << vec.at(10); // Chỉ mục 10 không tồn tại
    } catch (const out_of_range& e) {
        cout << "\n[Bắt lỗi an toàn]: " << e.what() << "\n";
    }

    // Dọn dẹp bộ nhớ trước khi thoát chương trình
    vec.free();
    return 0;
}
### Bài 4: 🔥 Dự Án Mini — Student Score Manager ⭐⭐⭐
> **Cảm hứng:** BaiTapTongHop — Quản lý sinh viên (DSALab)

Xây dựng hệ thống quản lý điểm sinh viên bằng **mảng động**:
- Thêm / xóa / sửa sinh viên (tên, MSSV, điểm)
- Sắp xếp theo điểm (dùng Selection Sort hoặc Bubble Sort)
- Tìm kiếm theo tên hoặc MSSV (Linear Search)
- Thống kê: điểm cao nhất, thấp nhất, trung bình lớp
- Xuất danh sách ra file `diem_sinhvien.txt`

```
=== QUẢN LÝ ĐIỂM SINH VIÊN ===
1. Thêm sinh viên
2. Xóa sinh viên
3. Tìm kiếm
4. Xếp hạng lớp
5. Xuất báo cáo
0. Thoát
```
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

// Cấu trúc dữ liệu đại diện cho một Sinh viên
struct SinhVien {
    string mssv;
    string ho_ten;
    double diem;
};

// Hệ thống quản lý danh sách bằng mảng động tự chế
struct StudentManager {
    SinhVien* list;
    int size;
    int capacity;

    void init(int initial_capacity = 4) {
        capacity = initial_capacity;
        size = 0;
        list = new SinhVien[capacity];
    }

    // Tự động mở rộng bộ nhớ khi danh sách đầy
    void resize() {
        capacity *= 2;
        SinhVien* new_list = new SinhVien[capacity];
        for (int i = 0; i < size; i++) {
            new_list[i] = list[i];
        }
        delete[] list;
        list = new_list;
    }

    // 1. Thêm sinh viên (O(1) khấu hao)
    void addStudent(string mssv, string ho_ten, double diem) {
        if (size == capacity) {
            resize();
        }
        list[size] = {mssv, ho_ten, diem};
        size++;
        cout << "=> Đã thêm sinh viên thành công!\n";
    }

    // 2. Xóa sinh viên theo MSSV (O(n))
    void deleteStudent(string mssv) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (list[i].mssv == mssv) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "=> Không tìm thấy sinh viên có MSSV: " << mssv << "\n";
            return;
        }

        // Dịch chuyển các phần tử phía sau lên trước để lấp chỗ trống
        for (int i = index; i < size - 1; i++) {
            list[i] = list[i + 1];
        }
        size--;
        cout << "=> Đã xóa sinh viên thành công!\n";
    }

    // 3. Tìm kiếm theo MSSV hoặc Tên (Linear Search - O(n))
    void searchStudent(string keyword) {
        bool found = false;
        cout << "\n+------------+---------------------------+------+\n";
        cout << "|   MSSV     |          Họ Tên           | Điểm |\n";
        cout << "+------------+---------------------------+------+\n";
        for (int i = 0; i < size; i++) {
            // Kiểm tra khớp MSSV hoặc chuỗi con của Họ Tên
            if (list[i].mssv == keyword || list[i].ho_ten.find(keyword) != string::npos) {
                cout << "| " << left << setw(10) << list[i].mssv 
                     << " | " << setw(25) << list[i].ho_ten 
                     << " | " << right << setw(4) << fixed << setprecision(1) << list[i].diem << " |\n";
                found = true;
            }
        }
        cout << "+------------+---------------------------+------+\n";
        if (!found) cout << "=> Không tìm thấy kết quả phù hợp.\n";
    }

    // 4. Sắp xếp danh sách giảm dần theo điểm (Selection Sort - O(n²))
    void sortByScore() {
        for (int i = 0; i < size - 1; i++) {
            int max_idx = i;
            for (int j = i + 1; j < size; j++) {
                if (list[j].diem > list[max_idx].diem) {
                    max_idx = j;
                }
            }
            // Hoán vị cấu trúc
            if (max_idx != i) {
                SinhVien temp = list[i];
                list[i] = list[max_idx];
                list[max_idx] = temp;
            }
        }
        cout << "=> Đã xếp hạng danh sách lớp giảm dần theo điểm!\n";
    }

    // 5. Thống kê số liệu lớp (O(n))
    void printStatistics(stringstream& out) {
        if (size == 0) {
            out << "Danh sách trống. Không có dữ liệu thống kê.\n";
            return;
        }
        double min_d = list[0].diem;
        double max_d = list[0].diem;
        double sum = 0;

        for (int i = 0; i < size; i++) {
            if (list[i].diem < min_d) min_d = list[i].diem;
            if (list[i].diem > max_d) max_d = list[i].diem;
            sum += list[i].diem;
        }
        
        out << "\n[THỐNG KÊ LỚP HỌC]\n";
        out << "- Tổng số sinh viên: " << size << "\n";
        out << "- Điểm cao nhất:     " << fixed << setprecision(1) << max_d << "\n";
        out << "- Điểm thấp nhất:    " << min_d << "\n";
        out << "- Điểm trung bình:   " << (sum / size) << "\n";
    }

    // 6. Kết xuất bảng danh sách ra chuỗi định dạng
    void exportTable(stringstream& out) {
        out << "+------------+---------------------------+------+\n";
        out << "|   MSSV     |          Họ Tên           | Điểm |\n";
        out << "+------------+---------------------------+------+\n";
        for (int i = 0; i < size; i++) {
            out << "| " << left << setw(10) << list[i].mssv 
                << " | " << setw(25) << list[i].ho_ten 
                << " | " << right << setw(4) << fixed << setprecision(1) << list[i].diem << " |\n";
        }
        out << "+------------+---------------------------+------+\n";
    }

    // Giải phóng bộ nhớ
    void free() {
        delete[] list;
        list = nullptr;
        size = 0;
        capacity = 0;
    }
};

int main() {
    StudentManager sm;
    sm.init(2); // Sức chứa ban đầu nhỏ để test tính năng tự động resize

    // Thêm sẵn vài dữ liệu mẫu để tiện chạy kiểm thử ban đầu
    sm.addStudent("231101", "Nguyen Van An", 8.5);
    sm.addStudent("231102", "Tran Thi Binh", 9.2);
    sm.addStudent("231103", "Le Minh Cuong", 6.8);

    int choice;
    do {
        cout << "\n=== QUẢN LÝ ĐIỂM SINH VIÊN ===\n";
        cout << "1. Thêm sinh viên\n";
        cout << "2. Xóa sinh viên\n";
        cout << "3. Tìm kiếm (Tên/MSSV)\n";
        cout << "4. Xếp hạng lớp (Điểm giảm dần)\n";
        cout << "5. Xuất báo cáo (In ra màn hình & Xuất file)\n";
        cout << "0. Thoát\n";
        cout << "Lựa chọn của bạn: ";
        cin >> choice;

        // Xử lý trôi lệnh sau khi đọc số
        cin.ignore();

        if (choice == 1) {
            string mssv, ho_ten;
            double diem;
            cout << "Nhập MSSV: "; getline(cin, mssv);
            cout << "Nhập Họ Tên: "; getline(cin, ho_ten);
            cout << "Nhập Điểm: "; cin >> diem;
            sm.addStudent(mssv, ho_ten, diem);
        } 
        else if (choice == 2) {
            string mssv;
            cout << "Nhập MSSV cần xóa: "; getline(cin, mssv);
            sm.deleteStudent(mssv);
        } 
        else if (choice == 3) {
            string keyword;
            cout << "Nhập MSSV hoặc Tên cần tìm: "; getline(cin, keyword);
            sm.searchStudent(keyword);
        } 
        else if (choice == 4) {
            sm.sortByScore();
        } 
        else if (choice == 5) {
            stringstream ss;
            ss << "\n================= BÁO CÁO KẾT QUẢ HỌC TẬP =================\n";
            sm.exportTable(ss);
            sm.printStatistics(ss);
            ss << "===========================================================\n";

            // In trực tiếp ra console
            string report = ss.str();
            cout << report;

            // Xuất đồng thời ra file văn bản vật lý
            ofstream file("diem_sinhvien.txt");
            if (file.is_open()) {
                file << report;
                file.close();
                cout << "\n[Hệ thống]: Báo cáo đã được xuất thành công ra file 'diem_sinhvien.txt'!\n";
            } else {
                cout << "\n[Lỗi]: Không thể tạo file ghi dữ liệu.\n";
            }
        }
    } while (choice != 0);

    sm.free(); // Thu hồi vùng nhớ Heap trước khi đóng ứng dụng
    cout << "Tạm biệt!\n";
    return 0;
}
---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
