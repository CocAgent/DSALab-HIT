# Tuần 2: Mảng & Con Trỏ — Bài tập

### Bài 1: Mảng cơ bản ⭐
Nhập mảng n phần tử. Tính min, max, trung bình, tổng. Không dùng STL.
#include <iostream>

using namespace std;

int main() {
    // 1. Nhập và kiểm tra điều kiện số lượng phần tử
    int n;
    cout << "Nhap so phan tu n (0 < n <= 1000): ";
    cin >> n;

    if (n <= 0 || n > 1000) {
        cout << "==> LOI: So phan tu khong hop le!" << endl;
        return 1;
    }

    // 2. Nhập dữ liệu mảng
    int arr[1000];
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 3. Xử lý tính toán (Không dùng STL)
    int minVal = arr[0];
    int maxVal = arr[0];
    long long totalSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
        totalSum += arr[i];
    }
    double average = static_cast<double>(totalSum) / n;

    // 4. In kết quả định dạng rõ ràng
    cout << "\n================ KET QUA ================" << endl;
    cout << " -> Tong cac phan tu      : " << totalSum << endl;
    cout << " -> Trung binh cong       : " << average << endl;
    cout << " -> Gia tri nho nhat (Min): " << minVal << endl;
    cout << " -> Gia tri lon nhat (Max): " << maxVal << endl;
    cout << "=========================================" << endl;

    return 0;
}

### Bài 2: Mảng 2D ⭐⭐
Nhân 2 ma trận n×n. Tính định thức ma trận 3×3. Hiển thị đẹp.
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 50;

// Hàm hiển thị ma trận vuông đẹp mắt
void inMaTran(int mat[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        cout << "    [ ";
        for (int j = 0; j < n; j++) {
            cout << setw(6) << mat[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

// 1. Hàm nhân hai ma trận vuông cấp n
void baiToanNhanMaTran() {
    int n;
    cout << "\n--- 1. NHAN HAI MA TRAN VUONG ---" << endl;
    cout << "Nhap cap ma tran n: ";
    cin >> n;

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = { 0 };

    cout << "Nhap ma tran A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> A[i][j];

    cout << "Nhap ma tran B (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> B[i][j];

    // Thuật toán nhân ma trận
    // ĐOẠN CODE QUAN TRỌNG: 3 vòng lặp lồng nhau (Cơ chế Tích vô hướng)
for (int i = 0; i < n; i++) {         // i: Duyệt qua từng HÀNG của ma trận A
    for (int j = 0; j < n; j++) {     // j: Duyệt qua từng CỘT của ma trận B
        for (int k = 0; k < n; k++) { // k: Biến chạy trung gian để quét phần tử
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}

    cout << "\n=> Ket qua Ma tran C = A * B:\n";
    inMaTran(C, n);
}

// 2. Hàm tính định thức ma trận 3x3 (Quy tắc Sarrus)
void baiToanDinhThuc3x3() {
    int M[MAX][MAX];
    cout << "\n--- 2. TINH DINH THUC MA TRAN 3X3 ---" << endl;
    cout << "Nhap ma tran 3x3:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> M[i][j];

    // Công thức Sarrus mở rộng
    int det = M[0][0] * M[1][1] * M[2][2] + M[0][1] * M[1][2] * M[2][0] + M[0][2] * M[1][0] * M[2][1]
        - M[0][2] * M[1][1] * M[2][0] - M[0][1] * M[1][0] * M[2][2] - M[0][0] * M[1][2] * M[2][1];

    cout << "\n=> Dinh thuc (Det) cua ma tran 3x3 la: " << det << endl;
}

int main() {
    baiToanNhanMaTran();
    cout << "\n-----------------------------------------\n";
    baiToanDinhThuc3x3();
    return 0;
}

### Bài 3: Con trỏ & cấp phát động ⭐⭐
Cài đặt mảng động tự resize (như `std::vector` đơn giản). Hỗ trợ push_back, pop_back, at(i).
#include <iostream>
#include <stdexcept>

using namespace std;

class MyVector {
private:
    int* arr;          // Con trỏ quản lý vùng nhớ mảng động
    int _size;         // Số lượng phần tử hiện tại
    int _capacity;     // Sức chứa tối đa hiện tại của vùng nhớ

    // Hàm quản lý tái cấp phát bộ nhớ khi vượt ngưỡng sức chứa
    void thayDoiKichThuoc() {
        _capacity = (_capacity == 0) ? 1 : _capacity * 2;
        int* temp = new int[_capacity];

        for (int i = 0; i < _size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;  // Thu hồi bộ nhớ cũ
        arr = temp;    // Chuyển con trỏ quản lý sang vùng nhớ mới
    }

public:
    // Constructor
    MyVector() {
        _size = 0;
        _capacity = 2;
        arr = new int[_capacity];
    }

    // Destructor (Ngăn chặn triệt để hiện tượng Memory Leak)
    ~MyVector() {
        delete[] arr;
    }

    void push_back(int value) {
        if (_size == _capacity) {
            thayDoiKichThuoc();
        }
        arr[_size++] = value;
    }

    void pop_back() {
        if (_size > 0) {
            _size--;
        }
        else {
            cout << "==> CANH BAO: Vector dang trong, khong the pop!" << endl;
        }
    }

    int at(int index) const {
        if (index < 0 || index >= _size) {
            throw out_of_range("Loi: Vi tri index nam ngoai pham vi mien gia tri!");
        }
        return arr[index];
    }

    int size() const { return _size; }
    int capacity() const { return _capacity; }
};

int main() {
    MyVector vec;
    cout << "--- KIEM TRA HOAT DONG VECTOR CUSTOM ---" << endl;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30); // Vượt quá capacity ban đầu (2), kích hoạt resize()

    cout << " -> Kich thuoc phan tu (Size): " << vec.size() << endl;
    cout << " -> Suc chua vung nho (Cap) : " << vec.capacity() << endl;
    cout << " -> Phan tu tai vi tri [1]  : " << vec.at(1) << endl;

    vec.pop_back();
    cout << " -> Sau khi pop_back, size hien tai: " << vec.size() << endl;

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
#include <fstream>
#include <iomanip>

using namespace std;

struct SinhVien {
    string mssv;
    string ten;
    double diem;
};

class StudentManager {
private:
    SinhVien* ds;
    int soLuong;

public:
    StudentManager() : ds(nullptr), soLuong(0) {}

    ~StudentManager() {
        delete[] ds;
    }

    // 1. Thêm sinh viên (Tự động nới rộng mảng động thêm 1 đơn vị)
    void themSinhVien() {
        SinhVien sv;
        cin.ignore();
        cout << "[THEM] Nhap MSSV: ";    getline(cin, sv.mssv);
        cout << "[THEM] Nhap Ho ten: ";  getline(cin, sv.ten);
        cout << "[THEM] Nhap Diem: ";     cin >> sv.diem;

        SinhVien* temp = new SinhVien[soLuong + 1];
        for (int i = 0; i < soLuong; i++) {
            temp[i] = ds[i];
        }
        temp[soLuong] = sv;

        delete[] ds;
        ds = temp;
        soLuong++;
        cout << "=> Thanh cong: Da them sinh vien vao he thong!\n";
    }

    // 2. Xóa sinh viên (Tự động thu hẹp mảng động giảm đi 1 đơn vị)
    void xoaSinhVien() {
        if (soLuong == 0) {
            cout << "=> Thong bao: Danh sach dang trong.\n";
            return;
        }
        cin.ignore();
        string mssvXoa;
        cout << "[XOA] Nhap MSSV can xoa: "; getline(cin, mssvXoa);

        int index = -1;
        for (int i = 0; i < soLuong; i++) {
            if (ds[i].mssv == mssvXoa) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "=> Error: Khong tim thay sinh vien co MSSV tren.\n";
            return;
        }

        SinhVien* temp = new SinhVien[soLuong - 1];
        for (int i = 0; i < index; i++) temp[i] = ds[i];
        for (int i = index + 1; i < soLuong; i++) temp[i - 1] = ds[i];

        delete[] ds;
        ds = temp;
        soLuong--;
        cout << "=> Thanh cong: Da xoa sinh vien khoi he thong!\n";
    }

    // 3. Tìm kiếm tuyến tính (Linear Search) theo Tên hoặc MSSV
    void timKiem() const {
        if (soLuong == 0) {
            cout << "=> Thong bao: Danh sach dang trong.\n";
            return;
        }
        cin.ignore();
        string tuKhoa;
        cout << "[TIM KIEM] Nhap MSSV hoac Ten can tim: "; getline(cin, tuKhoa);

        bool timThay = false;
        inTieuDeBang();
        for (int i = 0; i < soLuong; i++) {
            if (ds[i].mssv == tuKhoa || ds[i].ten.find(tuKhoa) != string::npos) {
                inDongSinhVien(ds[i]);
                timThay = true;
            }
        }
        if (!timThay) {
            cout << "| " << setw(51) << left << "Khong tim thay ket qua trung khop!" << " |\n";
        }
        inDuongKeBang();
    }

    // Helper: Định dạng hiển thị giao diện bảng CLI phẳng, đẹp mắt
    void inTieuDeBang() const {
        cout << "\n+" << string(53, '-') << "+\n";
        cout << "| " << setw(12) << left << "MSSV"
            << "| " << setw(25) << left << "Ho va Ten"
            << "| " << setw(8) << left << "Diem" << " |\n";
        cout << "+" << string(53, '-') << "+\n";
    }

    void inDongSinhVien(const SinhVien& sv) const {
        cout << "| " << setw(12) << left << sv.mssv
            << "| " << setw(25) << left << sv.ten
            << "| " << setw(8) << left << fixed << setprecision(2) << sv.diem << " |\n";
    }

    void inDuongKeBang() const {
        cout << "+" << string(53, '-') << "+\n";
    }

    void hienThiDanhSach() const {
        if (soLuong == 0) {
            cout << "=> Thong bao: Danh sach dang trong.\n";
            return;
        }
        inTieuDeBang();
        for (int i = 0; i < soLuong; i++) {
            inDongSinhVien(ds[i]);
        }
        inDuongKeBang();
    }

    // 4. Bubble Sort xếp hạng giảm dần & Tính toán thống kê dữ liệu lớp học
    void xepHangVaThongKe() {
        if (soLuong == 0) {
            cout << "=> Thong bao: Danh sach trong, khong the thong ke.\n";
            return;
        }

        // Thực hiện thuật toán nổi bọt (Bubble Sort)
        for (int i = 0; i < soLuong - 1; i++) {
            for (int j = 0; j < soLuong - i - 1; j++) {
                if (ds[j].diem < ds[j + 1].diem) {
                    swap(ds[j], ds[j + 1]);
                }
            }
        }

        cout << "\n--- BANG XEP HANG DIEM SINH VIEN (GIAM DAN) ---";
        hienThiDanhSach();

        double maxDiem = ds[0].diem, minDiem = ds[0].diem, tongDiem = 0;
        for (int i = 0; i < soLuong; i++) {
            if (ds[i].diem > maxDiem) maxDiem = ds[i].diem;
            if (ds[i].diem < minDiem) minDiem = ds[i].diem;
            tongDiem += ds[i].diem;
        }

        cout << "\n================ STATISTICS ================" << endl;
        cout << " -> Diem cao nhat lop     : " << maxDiem << endl;
        cout << " -> Diem thap nhat lop     : " << minDiem << endl;
        cout << " -> Diem trung binh cua lop: " << fixed << setprecision(2) << (tongDiem / soLuong) << endl;
        cout << "============================================" << endl;
    }

    // 5. Xuất báo cáo ra file text
    void xuatFile() const {
        ofstream fileOut("diem_sinhvien.txt");
        if (!fileOut.is_open()) {
            cout << "=> Error: Khong the khoi tao file ghi du lieu!\n";
            return;
        }

        fileOut << "=================== BAO CAO DIEM SINH VIEN ===================\n\n";
        fileOut << left << setw(15) << "MSSV" << setw(30) << "Ho va Ten" << setw(10) << "Diem" << "\n";
        fileOut << string(55, '-') << "\n";
        for (int i = 0; i < soLuong; i++) {
            fileOut << left << setw(15) << ds[i].mssv
                << setw(30) << ds[i].ten
                << setw(10) << fixed << setprecision(2) << ds[i].diem << "\n";
        }
        fileOut.close();
        cout << "=> Thanh cong: Du lieu da duoc ket xuat vao file 'diem_sinhvien.txt'!\n";
    }
};

int main() {
    StudentManager manager;
    int luaChon;

    do {
        cout << "\n========== QUAN LY DIEM SINH VIEN ==========\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xoa sinh vien\n";
        cout << "3. Tim kiem sinh vien\n";
        cout << "4. Xep hang & Thong ke\n";
        cout << "5. Xuat bao cao ra File (.txt)\n";
        cout << "6. In toan bo danh sach hien tai\n";
        cout << "0. Thoat khoi chuong trinh\n";
        cout << "--------------------------------------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: manager.themSinhVien(); break;
        case 2: manager.xoaSinhVien(); break;
        case 3: manager.timKiem(); break;
        case 4: manager.xepHangVaThongKe(); break;
        case 5: manager.xuatFile(); break;
        case 6: manager.hienThiDanhSach(); break;
        case 0: cout << "=> Da dong ung dung. Tam biet!\n"; break;
        default: cout << "=> Lua chon khong hop le, vui long thu lai!\n";
        }
    } while (luaChon != 0);

    return 0;
}
---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
