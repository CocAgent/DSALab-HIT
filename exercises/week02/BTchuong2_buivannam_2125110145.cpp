#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

// ============================================================
// BÀI 1: MẢNG CƠ BẢN (Không dùng STL)
// ============================================================
void Bai1_MangCoBan() {
    int n;
    cout << "\n--- BAI 1: MANG CO BAN ---\n";
    cout << "Nhap so luong phan tu n = "; cin >> n;
    if (n <= 0) { cout << "N khong hop le!\n"; return; }

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int min_val = a[0], max_val = a[0];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
        sum += a[i];
    }

    cout << "\nKet qua:\n";
    cout << " - Tong      : " << sum << "\n";
    cout << " - Trung binh: " << (double)sum / n << "\n";
    cout << " - Nho nhat  : " << min_val << "\n";
    cout << " - Lon nhat  : " << max_val << "\n";

    delete[] a;
}

// ============================================================
// BÀI 2: MẢNG 2D (Nhân ma trận & Định thức 3x3)
// ============================================================
int** CapPhatMaTran(int n) {
    int** mt = new int* [n];
    for (int i = 0; i < n; i++) mt[i] = new int[n];
    return mt;
}

void GiaiPhongMaTran(int** mt, int n) {
    for (int i = 0; i < n; i++) delete[] mt[i];
    delete[] mt;
}

void NhapMaTran(int** mt, int n, char ten) {
    cout << "Nhap ma tran " << ten << ":\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << ten << "[" << i << "][" << j << "] = ";
            cin >> mt[i][j];
        }
}

void XuatMaTran(int** mt, int n) {
    for (int i = 0; i < n; i++) {
        cout << "  |";
        for (int j = 0; j < n; j++) cout << setw(5) << mt[i][j];
        cout << "  |\n";
    }
}

void Bai2_MaTran() {
    int n;
    cout << "\n--- BAI 2: MA TRAN ---\n";
    cout << "Nhap cap ma tran vuong n = "; cin >> n;
    if (n <= 0) return;

    int** A = CapPhatMaTran(n);
    int** B = CapPhatMaTran(n);
    int** C = CapPhatMaTran(n);

    NhapMaTran(A, n, 'A'); NhapMaTran(B, n, 'B');

    // Nhan ma tran C = A * B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
        }
    }

    cout << "\nMa tran A x B:\n";
    XuatMaTran(C, n);

    if (n == 3) {
        long long detA = A[0][0] * A[1][1] * A[2][2] + A[0][1] * A[1][2] * A[2][0] + A[0][2] * A[1][0] * A[2][1]
            - A[0][2] * A[1][1] * A[2][0] - A[0][0] * A[1][2] * A[2][1] - A[0][1] * A[1][0] * A[2][2];
        cout << "\nDinh thuc |A| (3x3) = " << detA << "\n";
    }

    GiaiPhongMaTran(A, n); GiaiPhongMaTran(B, n); GiaiPhongMaTran(C, n);
}

// ============================================================
// BÀI 3: MẢNG ĐỘNG TỰ RESIZE (MY VECTOR)
// ============================================================
class MyVector {
private:
    int* data;
    size_t _size, _capacity;
    void resize() {
        _capacity = (_capacity == 0) ? 1 : _capacity * 2;
        int* newData = new int[_capacity];
        for (size_t i = 0; i < _size; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }
public:
    MyVector() : data(nullptr), _size(0), _capacity(0) {}
    ~MyVector() { delete[] data; }
    void push_back(int val) {
        if (_size == _capacity) resize();
        data[_size++] = val;
    }
    void pop_back() { if (_size > 0) _size--; }
    int& at(size_t index) {
        if (index >= _size) throw out_of_range("Index out of range!");
        return data[index];
    }
    size_t size() { return _size; }
};

void Bai3_MangDong() {
    cout << "\n--- BAI 3: MANG DONG TU RESIZE ---\n";
    MyVector v;
    cout << "Them: 10, 20, 30...\n";
    v.push_back(10); v.push_back(20); v.push_back(30);
    cout << "Phan tu at(1): " << v.at(1) << "\n";
    v.pop_back();
    cout << "Kich thuoc sau khi pop_back: " << v.size() << "\n";
}

// ============================================================
// BÀI 4: QUẢN LÝ SINH VIÊN
// ============================================================
struct SinhVien {
    string mssv;
    string ten;
    float diem;
};

class QuanLySinhVien {
private:
    SinhVien* ds;
    int soLuong, sucChua;

    void moRong() {
        sucChua = (sucChua == 0) ? 2 : sucChua * 2;
        SinhVien* moi = new SinhVien[sucChua];
        for (int i = 0; i < soLuong; i++) moi[i] = ds[i];
        delete[] ds;
        ds = moi;
    }

public:
    QuanLySinhVien() : ds(nullptr), soLuong(0), sucChua(0) {}
    ~QuanLySinhVien() { delete[] ds; }

    void ThemMoi() {
        if (soLuong == sucChua) moRong();
        cout << "Nhap MSSV: "; cin >> ds[soLuong].mssv;
        cin.ignore();
        cout << "Nhap Ten : "; getline(cin, ds[soLuong].ten);
        cout << "Nhap Diem: "; cin >> ds[soLuong].diem;
        soLuong++;
        cout << "-> Them thanh cong!\n";
    }

    void XoaSinhVien() {
        string ma;
        cout << "Nhap MSSV can xoa: "; cin >> ma;
        for (int i = 0; i < soLuong; i++) {
            if (ds[i].mssv == ma) {
                for (int j = i; j < soLuong - 1; j++) ds[j] = ds[j + 1];
                soLuong--;
                cout << "-> Xoa thanh cong!\n";
                return;
            }
        }
        cout << "-> Khong tim thay MSSV!\n";
    }

    void TimKiem() {
        string keyword;
        cin.ignore();
        cout << "Nhap Ten hoac MSSV: "; getline(cin, keyword);
        bool thay = false;
        for (int i = 0; i < soLuong; i++) {
            if (ds[i].ten == keyword || ds[i].mssv == keyword) {
                cout << "- MSSV: " << ds[i].mssv << " | Ten: " << ds[i].ten << " | Diem: " << ds[i].diem << "\n";
                thay = true;
            }
        }
        if (!thay) cout << "-> Khong tim thay!\n";
    }

    void XepHang() {
        // Selection Sort theo diem giam dan
        for (int i = 0; i < soLuong - 1; i++) {
            int max_idx = i;
            for (int j = i + 1; j < soLuong; j++) {
                if (ds[j].diem > ds[max_idx].diem) max_idx = j;
            }
            // Swap tay do khong dung STL
            SinhVien temp = ds[i];
            ds[i] = ds[max_idx];
            ds[max_idx] = temp;
        }
        cout << "\n--- BANG XEP HANG LOP ---\n";
        for (int i = 0; i < soLuong; i++) {
            cout << i + 1 << ". " << ds[i].ten << " (" << ds[i].diem << " diem)\n";
        }
    }

    void XuatBaoCao() {
        if (soLuong == 0) { cout << "Lop chua co sinh vien!\n"; return; }

        float tong = 0, caoNhat = ds[0].diem, thapNhat = ds[0].diem;
        for (int i = 0; i < soLuong; i++) {
            tong += ds[i].diem;
            if (ds[i].diem > caoNhat) caoNhat = ds[i].diem;
            if (ds[i].diem < thapNhat) thapNhat = ds[i].diem;
        }

        ofstream file("diem_sinhvien.txt");
        if (!file) { cout << "Loi mo file!\n"; return; }

        file << "=== BAO CAO LOP HOC ===\n";
        file << "Tong so SV: " << soLuong << "\n";
        file << "Diem Cao Nhat: " << caoNhat << "\n";
        file << "Diem Thap Nhat: " << thapNhat << "\n";
        file << "Diem Trung Binh: " << fixed << setprecision(2) << (tong / soLuong) << "\n";
        file << "-----------------------\n";
        for (int i = 0; i < soLuong; i++) {
            file << ds[i].mssv << " - " << ds[i].ten << " - " << ds[i].diem << "\n";
        }
        file.close();
        cout << "-> Da xuat bao cao ra file 'diem_sinhvien.txt' va thong ke thanh cong!\n";
    }
};

void Bai4_QuanLySinhVien() {
    QuanLySinhVien ql;
    int chon;
    do {
        cout << "\n=== QUAN LY DIEM SINH VIEN ===\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xoa sinh vien\n";
        cout << "3. Tim kiem\n";
        cout << "4. Xep hang lop\n";
        cout << "5. Xuat bao cao thong ke\n";
        cout << "0. Thoat (Ve Menu Chinh)\n";
        cout << "Chon chuc nang: "; cin >> chon;

        switch (chon) {
        case 1: ql.ThemMoi(); break;
        case 2: ql.XoaSinhVien(); break;
        case 3: ql.TimKiem(); break;
        case 4: ql.XepHang(); break;
        case 5: ql.XuatBaoCao(); break;
        case 0: cout << "Dang thoat Quan ly Sinh Vien...\n"; break;
        default: cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 0);
}

// ============================================================
// HÀM MAIN - MENU CHÍNH
// ============================================================
int main() {
    int choice;
    do {
        cout << "\n========== MENU CHUNG ==========\n";
        cout << "1. Bai 1: Mang co ban (Min, Max, Avg, Sum)\n";
        cout << "2. Bai 2: Ma tran 2D (Nhan MT, Dinh thuc)\n";
        cout << "3. Bai 3: Mang dong tu resize (MyVector)\n";
        cout << "4. Bai 4: Du An Mini (Quan Ly Sinh Vien)\n";
        cout << "0. Thoat Chuong Trinh\n";
        cout << "================================\n";
        cout << "Chon bai tap (0-4): "; cin >> choice;

        switch (choice) {
        case 1: Bai1_MangCoBan(); break;
        case 2: Bai2_MaTran(); break;
        case 3: Bai3_MangDong(); break;
        case 4: Bai4_QuanLySinhVien(); break;
        case 0: cout << "Cam on ban da su dung chuong trinh!\n"; break;
        default: cout << "Lua chon khong hop le, vui long thu lai.\n";
        }
    } while (choice != 0);

    return 0;
}
