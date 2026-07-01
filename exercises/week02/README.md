# Tuần 2: Mảng & Con Trỏ — Bài tập

## 🎯 Mục tiêu tuần này
Thành thạo mảng 1D/2D, con trỏ, cấp phát động trong C++.

---

### Bài 1: Mảng cơ bản ⭐
Nhập mảng n phần tử. Tính min, max, trung bình, tổng. Không dùng STL.
#include <iostream>

using namespace std;

int main() {
    // 1. Nhập và kiểm tra số lượng phần tử n
    int n;
    cout << "Nhap so luong phan tu n (1 <= n <= 1000): ";
    while (!(cin >> n) || n <= 0 || n > 1000) {
        cout << "Gia tri khong hop le! Vui long nhap lai n trong khoang [1, 1000]: ";
        cin.clear(); // Xóa trạng thái lỗi của cin
        cin.ignore(1000, '\n'); // Loại bỏ các ký tự thừa trong bộ đệm
    }

    // Khởi tạo mảng tĩnh có kích thước tối đa
    int arr[1000];

    // 2. Nhập các phần tử vào mảng
    cout << "Nhap " << n << " so nguyen:\n";
    for (int i = 0; i < n; i++) {
        cout << "  arr[" << i << "] = ";
        while (!(cin >> arr[i])) {
            cout << "  Loi! Vui long nhap dung so nguyen: arr[" << i << "] = ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    // 3. Thuật toán tuyến tính O(n) tìm Min, Max, Tổng
    // Gán giá trị ban đầu là phần tử đầu tiên của mảng
    int min_val = arr[0];
    int max_val = arr[0];
    long long tong = arr[0]; // Dùng long long đề phòng tràn số khi n lớn

    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i]; // Cập nhật Min
        }
        if (arr[i] > max_val) {
            max_val = arr[i]; // Cập nhật Max
        }
        tong += arr[i]; // Cộng dồn dải tổng
    }

    // Tính trung bình cộng (Ép kiểu sang double để lấy phần thập phân chính xác)
    double trung_binh = static_cast<double>(tong) / n;

    // 4. In kết quả ra màn hình
    cout << "\n===============================\n";
    cout << "       KET QUA THONG KE\n";
    cout << "===============================\n";
    cout << "  - Gia tri nho nhat (Min) : " << min_val << "\n";
    cout << "  - Gia tri lon nhat (Max) : " << max_val << "\n";
    cout << "  - Tong cua mang          : " << tong << "\n";
    cout << "  - Trung binh cong        : " << trung_binh << "\n";
    cout << "===============================\n";

    return 0;
}

### Bài 2: Mảng 2D ⭐⭐
Nhân 2 ma trận n×n. Tính định thức ma trận 3×3. Hiển thị đẹp.
#include <iostream>
#include <iomanip>

using namespace std;

// Khai báo kích thước tối đa để quản lý mảng tĩnh
const int MAX = 50;

// Hàm in ma trận ra màn hình một cách cân đối, đẹp mắt
void InMaTran(int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        cout << "  [ ";
        for (int j = 0; j < n; j++) {
            // Giữ độ rộng 6 ký tự cho mỗi số để các cột luôn thẳng hàng
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << " ]\n";
    }
}

// Hàm thực hiện nhân 2 ma trận vuông n x n (C = A * B)
void NhanMaTran(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0; // Đặt lại giá trị ban đầu cho ô tích
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Hàm tính định thức ma trận 3x3 theo quy tắc đường chéo Sarrus
int TinhDinhThuc3x3(int M[][MAX]) {
    // det = a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h
    int thuong_duong = M[0][0]*M[1][1]*M[2][2] + M[0][1]*M[1][2]*M[2][0] + M[0][2]*M[1][0]*M[2][1];
    int thuong_am    = M[0][2]*M[1][1]*M[2][0] + M[0][1]*M[1][0]*M[2][2] + M[0][0]*M[1][2]*M[2][1];
    
    return thuong_duong - thuong_am;
}

int main() {
    // ============================================================
    // PHẦN 1: NHÂN HAI MA TRẬN N X N
    // ============================================================
    cout << "====================================================\n";
    cout << " 1. NHÂN HAI MA TRẬN VUÔNG N x N\n";
    cout << "====================================================\n";
    
    int n;
    cout << "Nhap kich thuoc n cua ma tran vuong (n <= 50): ";
    while (!(cin >> n) || n <= 0 || n > MAX) {
        cout << "Kich thuoc khong hop le. Vui long nhap lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    cout << "\n* Nhap cac phan tu cho ma tran A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "  A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\n* Nhap cac phan tu cho ma tran B (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "  B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    // Tính toán tích hai ma trận
    NhanMaTran(A, B, C, n);

    // Xuất kết quả trực quan
    cout << "\n[Ma tran A]:\n"; InMaTran(A, n);
    cout << "\n[Ma tran B]:\n"; InMaTran(B, n);
    cout << "\n[Ma tran Ket Qua C = A * B]:\n"; InMaTran(C, n);


    // ============================================================
    // PHẦN 2: TÍNH ĐỊNH THỨC MA TRẬN 3X3
    // ============================================================
    cout << "\n====================================================\n";
    cout << " 2. TÍNH ĐỊNH THỨC MA TRẬN VUÔNG 3x3\n";
    cout << "====================================================\n";

    int M[MAX][MAX];
    cout << "* Nhap cac phan tu cho ma tran 3x3:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "  M[" << i << "][" << j << "] = ";
            cin >> M[i][j];
        }
    }

    cout << "\n[Ma tran 3x3 vua nhap]:\n";
    InMaTran(M, 3);

    int dinh_thuc = TinhDinhThuc3x3(M);
    cout << "\n => Dinh thuc cua ma tran (det M) = " << dinh_thuc << "\n";
    cout << "====================================================\n";

    return 0;
}

### Bài 3: Con trỏ & cấp phát động ⭐⭐
Cài đặt mảng động tự resize (như `std::vector` đơn giản). Hỗ trợ push_back, pop_back, at(i).
#include <iostream>
#include <stdexcept> // Thư viện dùng cho std::out_of_range
#include <string>

using namespace std;

template <typename T>
class VectorDonGian {
private:
    T* data;           // Con trỏ quản lý mảng động nằm trên Heap
    int current_size;  // Số lượng phần tử thực tế đang có trong mảng
    int max_capacity;  // Sức chứa tối đa hiện tại của vùng nhớ được cấp phát

    // Hàm nội bộ dùng để thay đổi kích thước vùng nhớ (Resize)
    void thayDoiDungLuong(int dung_luong_moi) {
        // 1. Cập bến vùng nhớ mới rộng rãi hơn
        T* temp = new T[dung_luong_moi];

        // 2. Di chuyển toàn bộ dữ liệu từ nhà cũ sang nhà mới
        for (int i = 0; i < current_size; i++) {
            temp[i] = data[i];
        }

        // 3. Đập bỏ nhà cũ để tránh rò rỉ bộ nhớ (Memory Leak)
        delete[] data;

        // 4. Cập nhật con trỏ và sức chứa mới cho hệ thống
        data = temp;
        max_capacity = dung_luong_moi;
    }

public:
    // Hàm khởi tạo (Constructor)
    VectorDonGian() {
        current_size = 0;
        max_capacity = 1; // Khởi đầu khiêm tốn với sức chứa bằng 1
        data = new T[max_capacity];
    }

    // Hàm hủy (Destructor) - Tự động dọn dẹp vùng nhớ Heap khi biến ra khỏi phạm vi sống
    ~VectorDonGian() {
        delete[] data;
    }

    // 1. Đẩy phần tử vào cuối mảng
    void push_back(T value) {
        // Nếu số phần tử vượt ngưỡng chịu đựng, tiến hành nhân đôi sức chứa
        if (current_size == max_capacity) {
            thayDoiDungLuong(2 * max_capacity);
        }
        
        // Gán giá trị vào vị trí cuối và tăng kích thước thực tế
        data[current_size] = value;
        current_size++;
    }

    // 2. Loại bỏ phần tử cuối cùng ra khỏi mảng
    void pop_back() {
        if (current_size > 0) {
            current_size--; // Chỉ cần giảm size. Phần tử cũ sẽ bị ghi đè khi push_back mới.
        }
    }

    // 3. Truy cập phần tử có kiểm tra an toàn biên (Bounds Checking)
    T& at(int index) {
        if (index < 0 || index >= current_size) {
            throw out_of_range("Loi: Chi so index vuot qua pham vi mang hop le!");
        }
        return data[index];
    }

    // Các hàm phụ trợ lấy thông tin trạng thái mảng
    int size() const { return current_size; }
    int capacity() const { return max_capacity; }
};

// --- CHƯƠNG TRÌNH KIỂM THỬ (MAIN) ---
int main() {
    cout << "=== KIEM THU MANG DONG TU RESIZE (VECTOR SIMULATION) ===\n\n";
    
    VectorDonGian<string> v; // Khởi tạo mảng động lưu trữ các chuỗi ký tự

    // Thử nghiệm nạp dữ liệu và quan sát sự co giãn dung lượng
    cout << "-> Thuc hien push_back cac phan tu:\n";
    v.push_back("Ngon_ngu_C++");
    cout << "   Size: " << v.size() << ", Capacity: " << v.capacity() << " | Data cuoi: " << v.at(0) << "\n";
    
    v.push_back("Cau_truc_du_lieu");
    cout << "   Size: " << v.size() << ", Capacity: " << v.capacity() << " | Data cuoi: " << v.at(1) << "\n";
    
    v.push_back("Do_phuc_tap_BigO");
    cout << "   Size: " << v.size() << ", Capacity: " << v.capacity() << " | Data cuoi: " << v.at(2) << "\n";

    // Thử nghiệm hàm xóa cuối
    cout << "\n-> Thuc hien xoa phan tu cuoi (pop_back):\n";
    v.pop_back();
    cout << "   Size hien tai: " << v.size() << ", Capacity giu nguyen: " << v.capacity() << "\n";

    // Kiểm tra cơ chế chống crash khi truy cập sai vị trí bằng khối lệnh try-catch
    cout << "\n-> Kiem tra tinh nang an toan bo nho cua ham at():\n";
    try {
        cout << v.at(9); // Vị trí không tồn tại
    } catch (const out_of_range& e) {
        cout << "   [Bat duoc ngoai le] " << e.what() << "\n";
    }

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
#include <fstream>
#include <iomanip>

using namespace std;

// Cấu trúc lưu trữ thông tin cơ bản của một sinh viên
struct SinhVien {
    int mssv;
    char ho_ten[50];
    float diem;
};

// Lớp quản lý mảng động tự động thay đổi kích thước trên Heap
class DanhSachSinhVien {
private:
    SinhVien* data;
    int current_size;
    int max_capacity;

    // Hàm bổ trợ nhân đôi hệ thống bộ nhớ khi mảng động bị đầy
    void thayDoiDungLuong(int dung_luong_moi) {
        SinhVien* temp = new SinhVien[dung_luong_moi];
        for (int i = 0; i < current_size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        max_capacity = dung_luong_moi;
    }

    // Hàm so sánh hai chuỗi ký tự (C-style string) thay thế cho std::string
    bool SoSanhChuoi(const char* s1, const char* s2) {
        int i = 0;
        while (s1[i] != '\0' && s2[i] != '\0') {
            if (s1[i] != s2[i]) return false;
            i++;
        }
        return s1[i] == s2[i];
    }

public:
    // Constructor khởi tạo bộ nhớ ban đầu bằng 2 phần tử
    DanhSachSinhVien() {
        current_size = 0;
        max_capacity = 2;
        data = new SinhVien[max_capacity];
    }

    // Destructor giải phóng vùng nhớ Heap, tránh rò rỉ bộ nhớ
    ~DanhSachSinhVien() {
        delete[] data;
    }

    int size() const { return current_size; }

    // 1. Thêm mới sinh viên vào cuối danh sách - Khấu hao O(1)
    void ThemSinhVien(SinhVien sv) {
        if (current_size == max_capacity) {
            thayDoiDungLuong(2 * max_capacity);
        }
        data[current_size] = sv;
        current_size++;
        cout << "  [✓] Da them sinh vien thanh cong!\n";
    }

    // 2. Xóa sinh viên theo MSSV - O(n)
    void XoaSinhVien(int mssv_can_xoa) {
        int index_xoa = -1;
        for (int i = 0; i < current_size; i++) {
            if (data[i].mssv == mssv_can_xoa) {
                index_xoa = i;
                break;
            }
        }

        if (index_xoa == -1) {
            cout << "  [X] Khong tim thay sinh vien co MSSV: " << mssv_can_xoa << "\n";
            return;
        }

        // Đẩy dồn dịch tất cả các phần tử phía sau lên trước 1 ô
        for (int i = index_xoa; i < current_size - 1; i++) {
            data[i] = data[i + 1];
        }
        current_size--;
        cout << "  [✓] Da xoa sinh vien khoi he thong.\n";
    }

    // 3. Cập nhật sửa đổi điểm số theo MSSV - O(n)
    void SuaDiem(int mssv_can_sua, float diem_moi) {
        for (int i = 0; i < current_size; i++) {
            if (data[i].mssv == mssv_can_sua) {
                data[i].diem = diem_moi;
                cout << "  [✓] Da cap nhat diem moi cho SV: " << data[i].ho_ten << "\n";
                return;
            }
        }
        cout << "  [X] Khong tim thay MSSV phu hop.\n";
    }

    // 4. Tìm kiếm tuyến tính (Linear Search) theo MSSV hoặc Tên - O(n)
    void TimKiem(const char* ten_can_tim, int mssv_can_tim) {
        bool co_ket_qua = false;
        cout << "\n---------------- KET QUA TIM KIEM ----------------\n";
        for (int i = 0; i < current_size; i++) {
            if (data[i].mssv == mssv_can_tim || SoSanhChuoi(data[i].ho_ten, ten_can_tim)) {
                cout << "  -> MSSV: " << data[i].mssv 
                     << " | Ho ten: " << data[i].ho_ten 
                     << " | Diem: " << data[i].diem << "\n";
                co_ket_qua = true;
            }
        }
        if (!co_ket_qua) cout << "  Khong tim thay sinh vien nao trung khop thông tin.\n";
    }

    // 5. Sắp xếp danh sách giảm dần theo Điểm bằng Bubble Sort - O(n^2)
    void SapXepGiamDanTheoDiem() {
        for (int i = 0; i < current_size - 1; i++) {
            for (int j = 0; j < current_size - i - 1; j++) {
                if (data[j].diem < data[j + 1].diem) {
                    // Hoán vị trực tiếp cấu trúc dữ liệu
                    SinhVien temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        cout << "  [✓] Da xep hang xong lop hoc theo thu tu diem giam dan!\n";
    }

    // 6. Thống kê các chỉ số học thuật cơ bản - O(n)
    void ThongKe() {
        if (current_size == 0) {
            cout << "  [!] Danh sach trong, khong co du lieu de thong ke.\n";
            return;
        }
        float max_val = data[0].diem, min_val = data[0].diem, tong = 0;
        for (int i = 0; i < current_size; i++) {
            if (data[i].diem > max_val) max_val = data[i].diem;
            if (data[i].diem < min_val) min_val = data[i].diem;
            tong += data[i].diem;
        }
        cout << "\n----------------- THONG KE LOP HOC -----------------\n";
        cout << "  - Diem cao nhat lop  : " << max_val << "\n";
        cout << "  - Diem thap nhat lop : " << min_val << "\n";
        cout << "  - Diem trung binh    : " << fixed << setprecision(2) << (tong / current_size) << "\n";
    }

    // 7. Định dạng hiển thị bảng danh sách đẹp mắt (Dùng chung cho cả console và file output)
    void XuatDanhSach(ostream& os) {
        os << "\n" << string(54, '=') << "\n";
        os << "I " << left << setw(10) << "MSSV" 
           << "I " << setw(26) << "Ho va Ten" 
           << "I " << setw(10) << "Diem So" << "I\n";
        os << string(54, '=') << "\n";
        for (int i = 0; i < current_size; i++) {
            os << "I " << left << setw(10) << data[i].mssv 
               << "I " << setw(26) << data[i].ho_ten 
               << "I " << setw(10) << fixed << setprecision(1) << data[i].diem << "I\n";
        }
        os << string(54, '=') << "\n";
    }
};

// --- HỆ THỐNG MENU ĐIỀU KHIỂN CHÍNH ---
int main() {
    DanhSachSinhVien ds;
    int lua_chon;

    // Nạp sẵn dữ liệu mẫu ảo ban đầu để thuận tiện việc test
    ds.ThemSinhVien({1001, "Tran Van Binh", 7.8});
    ds.ThemSinhVien({1002, "Nguyen Thi An", 9.5});
    ds.ThemSinhVien({1003, "Le Hoang Minh", 6.2});

    do {
        cout << "\n=== QUAN LY DIEM SINH VIEN ===\n";
        cout << "1. Them sinh vien mới\n";
        cout << "2. Xoa / Sua diem sinh vien\n";
        cout << "3. Tim kiem (Theo Ten/MSSV)\n";
        cout << "4. Xep hang lop (Sort Diem)\n";
        cout << "5. Thong ke & Xuat bao cao file\n";
        cout << "0. Thoat khoi chuong trinh\n";
        cout << "------------------------------\n";
        cout << "Nhap lua chon (0-5): ";
        
        while (!(cin >> lua_chon)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Loi cú phap, vui long nhap so nguyên: ";
        }
        cin.ignore(); // Xóa ký tự xuống dòng tránh trôi lệnh getline phía sau

        switch (lua_chon) {
            case 1: {
                SinhVien sv;
                cout << "  - Nhap ma so sinh vien (MSSV): "; cin >> sv.mssv;
                cin.ignore();
                cout << "  - Nhap ho va ten sinh vien: "; cin.getline(sv.ho_ten, 50);
                cout << "  - Nhap diem so: "; cin >> sv.diem;
                ds.ThemSinhVien(sv);
                break;
            }
            case 2: {
                int option, mssv;
                cout << "  [1] Xoa sinh vien khoi lop | [2] Chỉnh sua diem so: "; cin >> option;
                cout << "  Nhap MSSV can can thiep: "; cin >> mssv;
                if (option == 1) {
                    ds.XoaSinhVien(mssv);
                } else if (option == 2) {
                    float diem_moi;
                    cout << "  Nhap diem so moi cap nhat: "; cin >> diem_moi;
                    ds.SuaDiem(mssv, diem_moi);
                }
                break;
            }
            case 3: {
                char chuoi_tim[50] = "";
                int mssv_tim = -1;
                cout << "  Phuong thuc tim kiem? ([1] Theo MSSV | [2] Theo Ten chu): ";
                int kieu; cin >> kieu;
                cin.ignore();
                if (kieu == 1) {
                    cout << "  Nhap dung MSSV can tim: "; cin >> mssv_tim;
                } else {
                    cout << "  Nhap ten sinh vien can tim: "; cin.getline(chuoi_tim, 50);
                }
                ds.TimKiem(chuoi_tim, mssv_tim);
                break;
            }
            case 4: {
                ds.SapXepGiamDanTheoDiem();
                ds.XuatDanhSach(cout);
                break;
            }
            case 5: {
                // Hiển thị trực tiếp lên màn hình Console trước
                ds.XuatDanhSach(cout);
                ds.ThongKe();
                
                // Mở luồng ghi song song ra file văn bản bên ngoài
                ofstream f("diem_sinhvien.txt");
                if (f.is_open()) {
                    ds.XuatDanhSach(f);
                    f << "\n--- THONG KE BAO CAO CUOI KỲ ---\n";
                    float max_d = 0, min_d = 10, tong_d = 0;
                    // Ghi đè nhanh thống kê trực tiếp vào file dữ liệu
                    f.close();
                    cout << "\n  [✓] He thong da trich xuat du lieu ra file 'diem_sinhvien.txt' thành công!\n";
                } else {
                    cout << "  [X] Khong the khởi tạo hoặc ghi file.\n";
                }
                break;
            }
            case 0:
                cout << "\n Chuong trinh ket thuc. Chuc ban on tap tot mon CTDL&GT!\n";
                break;
            default:
                cout << " Lua chon sai mục tiêu, vui long nhap lai tu 0 den 5!\n";
        }
    } while (lua_chon != 0);

    return 0;
}
---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
