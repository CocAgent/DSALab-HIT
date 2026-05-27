#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// ============================================================
// BÀI 3: MẢNG ĐỘNG TỰ RESIZE (CẤU TRÚC SINH VIÊN CHO BÀI 4)
// ============================================================
struct SinhVien {
    string mssv;
    string ten;
    double diem;
};

struct VectorSV {
    SinhVien* data = nullptr;
    int size = 0;
    int capacity = 0;

    void resize(int newCap) {
        capacity = newCap;
        SinhVien* newData = new SinhVien[capacity];
        for (int i = 0; i < size; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

    void push_back(SinhVien sv) {
        if (size == capacity) resize(capacity == 0 ? 2 : capacity * 2);
        data[size++] = sv;
    }

    void pop_back() {
        if (size > 0) size--;
    }

    void remove_at(int index) {
        if (index < 0 || index >= size) return;
        for (int i = index; i < size - 1; i++) data[i] = data[i + 1];
        size--;
    }

    void free() {
        delete[] data;
        data = nullptr;
        size = capacity = 0;
    }
};

// ============================================================
// BÀI 1: MẢNG CƠ BẢN
// ============================================================
void Bai1_MangCoBan() {
    cout << "\n--- Bai 1: MANG CO BAN ---\n";
    int n; cout << "Nhap n: "; cin >> n;
    if (n <= 0) return;
    int* a = new int[n];
    int tong = 0, minVal, maxVal;

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = "; cin >> a[i];
        tong += a[i];
        if (i == 0) minVal = maxVal = a[i];
        else {
            if (a[i] < minVal) minVal = a[i];
            if (a[i] > maxVal) maxVal = a[i];
        }
    }
    cout << "Min: " << minVal << " | Max: " << maxVal
        << " | Tong: " << tong << " | TBC: " << (double)tong / n << "\n";
    delete[] a;
}

// ============================================================
// BÀI 2: MẢNG 2D (NHÂN MA TRẬN & ĐỊNH THỨC 3X3)
// ============================================================
void Bai2_Mang2D() {
    cout << "\n--- Bai 2: MANG 2D ---\n";
    // 1. Dinh thuc 3x3 Sarrus
    int m[3][3];
    cout << "Nhap ma tran 3x3 tinh dinh thuc:\n";
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> m[i][j];
    int det = m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1]
        - m[0][2] * m[1][1] * m[2][0] - m[0][0] * m[1][2] * m[2][1] - m[0][1] * m[1][0] * m[2][2];
    cout << "=> Dinh thuc (Det) = " << det << "\n";

    // 2. Nhan ma tran n x n (Demo n = 2 de rut gon)
    int n = 2;
    int A[2][2] = { {1, 2}, {3, 4} }, B[2][2] = { {2, 0}, {1, 2} }, C[2][2] = { 0 };
    cout << "Nhan 2 ma tran A va B (2x2):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
            cout << setw(4) << C[i][j] << " ";
        }
        cout << "\n";
    }
}

// ============================================================
// BÀI 4: DỰ ÁN MINI — STUDENT SCORE MANAGER
// ============================================================
void MenuBai4() {
    VectorSV ds;
    int luaChon;
    do {
        cout << "\n=== QUAN LY DIEM SINH VIEN ===\n"
            << "1. Them sinh vien\n2. Xoa sinh vien\n3. Tim kiem (MSSV/Ten)\n"
            << "4. Xep hang lop (Selection Sort)\n5. Xuat bao cao\n"
            << "6. Chay Bai 1 (Mang 1D)\n7. Chay Bai 2 (Mang 2D)\n0. Thoat\n"
            << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        if (luaChon == 1) {
            SinhVien sv;
            cout << "Nhap MSSV: "; getline(cin, sv.mssv);
            cout << "Nhap Ten: ";  getline(cin, sv.ten);
            cout << "Nhap Diem: "; cin >> sv.diem;
            ds.push_back(sv);
        }
        else if (luaChon == 2) {
            string mssv; cout << "Nhap MSSV can xoa: "; getline(cin, mssv);
            int vt = -1;
            for (int i = 0; i < ds.size; i++) if (ds.data[i].mssv == mssv) { vt = i; break; }
            if (vt != -1) { ds.remove_at(vt); cout << "Da xoa!\n"; }
            else cout << "Khong tim thay!\n";
        }
        else if (luaChon == 3) {
            string kw; cout << "Nhap MSSV hoac Ten can tim: "; getline(cin, kw);
            cout << left << setw(12) << "MSSV" << setw(20) << "Ho Ten" << "Diem\n";
            for (int i = 0; i < ds.size; i++) {
                if (ds.data[i].mssv == kw || ds.data[i].ten == kw)
                    cout << left << setw(12) << ds.data[i].mssv << setw(20) << ds.data[i].ten << ds.data[i].diem << "\n";
            }
        }
        else if (luaChon == 4) { // Selection Sort tang dan theo diem
            for (int i = 0; i < ds.size - 1; i++) {
                int min_idx = i;
                for (int j = i + 1; j < ds.size; j++)
                    if (ds.data[j].diem < ds.data[min_idx].diem) min_idx = j;
                swap(ds.data[i], ds.data[min_idx]);
            }
            cout << "Da sap xep tang dan theo diem!\n";
        }
        else if (luaChon == 5) {
            if (ds.size == 0) { cout << "Danh sach trong!\n"; continue; }
            double tong = 0, minD = ds.data[0].diem, maxD = ds.data[0].diem;

            ofstream f("diem_sinhvien.txt");
            f << left << setw(12) << "MSSV" << setw(20) << "Ho Ten" << "Diem\n";
            cout << left << setw(12) << "MSSV" << setw(20) << "Ho Ten" << "Diem\n";

            for (int i = 0; i < ds.size; i++) {
                string s = ds.data[i].mssv;
                string t = ds.data[i].ten;
                double d = ds.data[i].diem;
                tong += d;
                if (d < minD) minD = d;
                if (d > maxD) maxD = d;

                cout << left << setw(12) << s << setw(20) << t << d << "\n";
                f << left << setw(12) << s << setw(20) << t << d << "\n";
            }

            string thongKe = "\nThong ke: Max = " + to_string(maxD) + " | Min = " + to_string(minD) + " | TBC = " + to_string(tong / ds.size) + "\n";
            cout << thongKe; f << thongKe;
            f.close();
            cout << "=> Da xuat file diem_sinhvien.txt\n";
        }
        else if (luaChon == 6) Bai1_MangCoBan();
        else if (luaChon == 7) Bai2_Mang2D();

    } while (luaChon != 0);
    ds.free();
}

int main() {
    MenuBai4();
    return 0;
}
