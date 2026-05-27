/*
=============================================================
  TUẦN 2: MẢNG & CON TRỎ — TẤT CẢ BÀI TẬP
  Bài 1: Mảng cơ bản
  Bài 2: Ma trận 2D
  Bài 3: Mảng động (vector đơn giản)
  Bài 4: Quản lý điểm sinh viên (Mini Project)
=============================================================
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

// ============================================================
//  BÀI 1: MẢNG CƠ BẢN
// ============================================================

void bai1_mangCoBan() {
    cout << "\n========== BAI 1: MANG CO BAN ==========\n";

    int n;
    cout << "Nhap so phan tu n: ";
    cin >> n;

    int* a = new int[n];
    cout << "Nhap " << n << " phan tu:\n";
    for (int i = 0; i < n; i++) {
        cout << "  a[" << i << "] = ";
        cin >> a[i];
    }

    int minVal = a[0], maxVal = a[0];
    long long tong = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < minVal) minVal = a[i];
        if (a[i] > maxVal) maxVal = a[i];
        tong += a[i];
    }

    double trungBinh = (double)tong / n;

    cout << "\n--- KET QUA ---\n";
    cout << "  Min     : " << minVal << "\n";
    cout << "  Max     : " << maxVal << "\n";
    cout << "  Tong    : " << tong << "\n";
    cout << "  TB      : " << trungBinh << "\n";

    delete[] a;
}
 
//  BÀI 2: MẢNG 2D — NHÂN MA TRẬN & ĐỊNH THỨC 3×3
// ============================================================

void inMaTran(int** m, int n) {
    for (int i = 0; i < n; i++) {
        cout << "  | ";
        for (int j = 0; j < n; j++) {
            // in số chiếm 6 ký tự cho thẳng hàng
            int val = m[i][j];
            if (val >= 0) cout << " ";
            cout << val;
            // pad thủ công (tối đa 5 chữ số)
            int w = (val == 0) ? 1 : (int)log10(abs(val)) + 1 + (val < 0 ? 1 : 0);
            for (int s = w; s < 6; s++) cout << " ";
        }
        cout << "|\n";
    }
}

double dinhThuc3x3(int a[3][3]) {
    return  a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
        - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
        + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

void bai2_maTran2D() {
    cout << "\n========== BAI 2: MA TRAN 2D ==========\n";

    int n;
    cout << "Nhap kich thuoc n (ma tran n x n): ";
    cin >> n;

    // Cấp phát động 2 ma trận A, B và kết quả C
    int** A = new int* [n];
    int** B = new int* [n];
    int** C = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n]();
        B[i] = new int[n]();
        C[i] = new int[n]();
    }

    cout << "Nhap ma tran A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "  A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    cout << "Nhap ma tran B (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "  B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }

    // Nhân ma trận C = A * B
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];

    cout << "\n--- Ma tran A ---\n"; inMaTran(A, n);
    cout << "\n--- Ma tran B ---\n"; inMaTran(B, n);
    cout << "\n--- C = A x B  ---\n"; inMaTran(C, n);

    // Định thức 3×3 nếu n == 3
    if (n == 3) {
        int a3[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                a3[i][j] = A[i][j];
        cout << "\n--- Dinh thuc det(A) = " << dinhThuc3x3(a3) << " ---\n";
    }
    else {
        cout << "\n(Chi tinh dinh thuc cho ma tran 3x3)\n";
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++) {
        delete[] A[i]; delete[] B[i]; delete[] C[i];
    }
    delete[] A; delete[] B; delete[] C;
}

// ============================================================
//  BÀI 3: MẢNG ĐỘNG TỰ RESIZE (mini vector<int>)
// ============================================================

struct MyVector {
    int* data;
    int  size;
    int  capacity;

    MyVector() : data(nullptr), size(0), capacity(0) {}

    ~MyVector() { delete[] data; }

    void reserve(int newCap) {
        if (newCap <= capacity) return;
        int* tmp = new int[newCap];
        for (int i = 0; i < size; i++) tmp[i] = data[i];
        delete[] data;
        data = tmp;
        capacity = newCap;
    }

    void push_back(int val) {
        if (size == capacity)
            reserve(capacity == 0 ? 1 : capacity * 2);
        data[size++] = val;
    }

    void pop_back() {
        if (size > 0) size--;
    }

    int& at(int i) {
        if (i < 0 || i >= size) {
            cout << "[LOI] Chi so ngoai pham vi!\n";
            // Trả về phần tử cuối để tránh crash demo
            return data[0];
        }
        return data[i];
    }

    void print() const {
        cout << "  MyVector [size=" << size
            << ", capacity=" << capacity << "]: [ ";
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << "]\n";
    }
};

void bai3_mangDong() {
    cout << "\n========== BAI 3: MANG DONG (mini vector) ==========\n";

    MyVector v;
    cout << "push_back 1..5:\n";
    for (int i = 1; i <= 5; i++) { v.push_back(i); v.print(); }

    cout << "pop_back x2:\n";
    v.pop_back(); v.print();
    v.pop_back(); v.print();

    cout << "at(0) = " << v.at(0) << "\n";
    cout << "at(1) = " << v.at(1) << "\n";
    cout << "at(99): ";
    v.at(99); // sẽ in thông báo lỗi
}

// ============================================================
//  BÀI 4: QUẢN LÝ ĐIỂM SINH VIÊN (Mini Project)
// ============================================================

struct SinhVien {
    char ten[50];
    char mssv[15];
    float diem;
};

// --- Mảng động sinh viên ---
SinhVien* dsSV = nullptr;
int       soSV = 0;
int       capSV = 0;

void svReserve(int newCap) {
    if (newCap <= capSV) return;
    SinhVien* tmp = new SinhVien[newCap];
    for (int i = 0; i < soSV; i++) tmp[i] = dsSV[i];
    delete[] dsSV;
    dsSV = tmp;
    capSV = newCap;
}

// ---- Helpers ----
void inDanhSach() {
    if (soSV == 0) { cout << "  (Chua co sinh vien nao)\n"; return; }
    cout << "\n  +-----+------------+----------------------+-------+\n";
    cout << "  | STT |   MSSV     |         Ten          | Diem  |\n";
    cout << "  +-----+------------+----------------------+-------+\n";
    for (int i = 0; i < soSV; i++) {
        // STT
        cout << "  | ";
        if (i + 1 < 10) cout << " ";
        cout << i + 1 << "  | ";
        // MSSV (10 ký tự)
        int lenM = strlen(dsSV[i].mssv);
        cout << dsSV[i].mssv;
        for (int s = lenM; s < 10; s++) cout << " ";
        cout << " | ";
        // Tên (20 ký tự)
        int lenT = strlen(dsSV[i].ten);
        cout << dsSV[i].ten;
        for (int s = lenT; s < 20; s++) cout << " ";
        cout << " | ";
        // Điểm
        float d = dsSV[i].diem;
        if (d < 10.0f) cout << " ";
        // In 1 chữ số thập phân thủ công
        int phanNguyen = (int)d;
        int phanLe = (int)((d - phanNguyen) * 10 + 0.5f);
        if (phanNguyen < 10) cout << " ";
        cout << phanNguyen << "." << phanLe << " |\n";
    }
    cout << "  +-----+------------+----------------------+-------+\n";
}

void themSV() {
    cout << "\n-- THEM SINH VIEN --\n";
    if (soSV == capSV) svReserve(capSV == 0 ? 4 : capSV * 2);
    SinhVien& sv = dsSV[soSV];
    cin.ignore();
    cout << "  Ten    : "; cin.getline(sv.ten, 50);
    cout << "  MSSV   : "; cin.getline(sv.mssv, 15);
    cout << "  Diem   : "; cin >> sv.diem;
    if (sv.diem < 0) sv.diem = 0;
    if (sv.diem > 10) sv.diem = 10;
    soSV++;
    cout << "  >> Da them sinh vien.\n";
}

void xoaSV() {
    cout << "\n-- XOA SINH VIEN --\n";
    inDanhSach();
    if (soSV == 0) return;
    int stt;
    cout << "  Nhap STT can xoa: "; cin >> stt;
    if (stt < 1 || stt > soSV) { cout << "  STT khong hop le.\n"; return; }
    for (int i = stt - 1; i < soSV - 1; i++) dsSV[i] = dsSV[i + 1];
    soSV--;
    cout << "  >> Da xoa.\n";
}

void suaSV() {
    cout << "\n-- SUA SINH VIEN --\n";
    inDanhSach();
    if (soSV == 0) return;
    int stt;
    cout << "  Nhap STT can sua: "; cin >> stt;
    if (stt < 1 || stt > soSV) { cout << "  STT khong hop le.\n"; return; }
    SinhVien& sv = dsSV[stt - 1];
    cin.ignore();
    cout << "  Ten moi  (hien tai: " << sv.ten << "): "; cin.getline(sv.ten, 50);
    cout << "  MSSV moi (hien tai: " << sv.mssv << "): "; cin.getline(sv.mssv, 15);
    cout << "  Diem moi (hien tai: " << sv.diem << "): "; cin >> sv.diem;
    cout << "  >> Da cap nhat.\n";
}

// Linear Search theo tên hoặc MSSV (so sánh không phân biệt hoa thường)
bool chuoiContain(const char* haystack, const char* needle) {
    // Tìm needle trong haystack (case-insensitive substring)
    int hn = strlen(haystack), nn = strlen(needle);
    for (int i = 0; i <= hn - nn; i++) {
        bool match = true;
        for (int j = 0; j < nn; j++) {
            char a = haystack[i + j], b = needle[j];
            if (a >= 'A' && a <= 'Z') a += 32;
            if (b >= 'A' && b <= 'Z') b += 32;
            if (a != b) { match = false; break; }
        }
        if (match) return true;
    }
    return false;
}

void timKiem() {
    cout << "\n-- TIM KIEM --\n";
    char tu[50];
    cin.ignore();
    cout << "  Nhap tu khoa (ten hoac MSSV): "; cin.getline(tu, 50);
    bool found = false;
    cout << "\n  Ket qua tim kiem:\n";
    for (int i = 0; i < soSV; i++) {
        if (chuoiContain(dsSV[i].ten, tu) || chuoiContain(dsSV[i].mssv, tu)) {
            // In 1 dòng kết quả
            cout << "  [" << i + 1 << "] " << dsSV[i].ten
                << " | " << dsSV[i].mssv
                << " | Diem: " << dsSV[i].diem << "\n";
            found = true;
        }
    }
    if (!found) cout << "  Khong tim thay.\n";
}

// Selection Sort giảm dần theo điểm
void sapXep() {
    for (int i = 0; i < soSV - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < soSV; j++)
            if (dsSV[j].diem > dsSV[maxIdx].diem)
                maxIdx = j;
        if (maxIdx != i) {
            SinhVien tmp = dsSV[i];
            dsSV[i] = dsSV[maxIdx];
            dsSV[maxIdx] = tmp;
        }
    }
}

void xepHang() {
    cout << "\n-- XEP HANG LOP (giam dan theo diem) --\n";
    if (soSV == 0) { cout << "  Chua co sinh vien.\n"; return; }
    sapXep();
    inDanhSach();
}

void thongKe() {
    cout << "\n-- THONG KE --\n";
    if (soSV == 0) { cout << "  Chua co sinh vien.\n"; return; }
    float minD = dsSV[0].diem, maxD = dsSV[0].diem;
    float tong = 0;
    int   idxMin = 0, idxMax = 0;
    for (int i = 0; i < soSV; i++) {
        if (dsSV[i].diem < minD) { minD = dsSV[i].diem; idxMin = i; }
        if (dsSV[i].diem > maxD) { maxD = dsSV[i].diem; idxMax = i; }
        tong += dsSV[i].diem;
    }
    float tb = tong / soSV;
    cout << "  So sinh vien : " << soSV << "\n";
    cout << "  Diem cao nhat: " << maxD << " (" << dsSV[idxMax].ten << ")\n";
    cout << "  Diem thap nhat: " << minD << " (" << dsSV[idxMin].ten << ")\n";
    cout << "  Diem trung binh lop: " << tb << "\n";
}

void xuatFile() {
    cout << "\n-- XUAT BAO CAO RA FILE --\n";
    sapXep();
    ofstream f("diem_sinhvien.txt");
    if (!f.is_open()) { cout << "  Khong mo duoc file!\n"; return; }

    f << "=== BANG DIEM SINH VIEN ===\n";
    f << "+-----+------------+----------------------+-------+\n";
    f << "| STT |   MSSV     |         Ten          | Diem  |\n";
    f << "+-----+------------+----------------------+-------+\n";

    float tong = 0;
    float minD = dsSV[0].diem, maxD = dsSV[0].diem;
    for (int i = 0; i < soSV; i++) {
        SinhVien& sv = dsSV[i];
        tong += sv.diem;
        if (sv.diem < minD) minD = sv.diem;
        if (sv.diem > maxD) maxD = sv.diem;

        // Ghi dòng (đơn giản, không căn chỉnh pixel-perfect trong file text)
        f << "| ";
        if (i + 1 < 10) f << " ";
        f << i + 1 << "  | ";
        int lm = strlen(sv.mssv);
        f << sv.mssv;
        for (int s = lm;s < 10;s++) f << " ";
        f << " | ";
        int lt = strlen(sv.ten);
        f << sv.ten;
        for (int s = lt;s < 20;s++) f << " ";
        f << " | ";
        int pN = (int)sv.diem;
        int pL = (int)((sv.diem - pN) * 10 + 0.5f);
        if (pN < 10) f << " ";
        f << pN << "." << pL << " |\n";
    }
    f << "+-----+------------+----------------------+-------+\n";
    f << "\nThong ke:\n";
    f << "  So sinh vien : " << soSV << "\n";
    f << "  Diem cao nhat: " << maxD << "\n";
    f << "  Diem thap nhat: " << minD << "\n";
    f << "  Diem trung binh: " << tong / soSV << "\n";
    f.close();

    cout << "  >> Da xuat ra file 'diem_sinhvien.txt'\n";
}

void bai4_quanLySinhVien() {
    cout << "\n========== BAI 4: QUAN LY DIEM SINH VIEN ==========\n";
    int choice;
    do {
        cout << "\n=== QUAN LY DIEM SINH VIEN ===\n";
        cout << "  1. Them sinh vien\n";
        cout << "  2. Xoa sinh vien\n";
        cout << "  3. Sua sinh vien\n";
        cout << "  4. Xem danh sach\n";
        cout << "  5. Tim kiem\n";
        cout << "  6. Xep hang lop\n";
        cout << "  7. Thong ke\n";
        cout << "  8. Xuat bao cao ra file\n";
        cout << "  0. Quay lai menu chinh\n";
        cout << "Lua chon: "; cin >> choice;
        switch (choice) {
        case 1: themSV();   break;
        case 2: xoaSV();    break;
        case 3: suaSV();    break;
        case 4: inDanhSach(); break;
        case 5: timKiem();  break;
        case 6: xepHang();  break;
        case 7: thongKe();  break;
        case 8: xuatFile(); break;
        case 0: break;
        default: cout << "  Lua chon khong hop le.\n";
        }
    } while (choice != 0);

    delete[] dsSV;
    dsSV = nullptr; soSV = 0; capSV = 0;
}

// ============================================================
//  MAIN — MENU TỔNG
// ============================================================

int main() {
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "   TUAN 2: MANG & CON TRO — BAI TAP\n";
        cout << "========================================\n";
        cout << "  1. Bai 1: Mang co ban (min/max/tb/tong)\n";
        cout << "  2. Bai 2: Ma tran 2D (nhan ma tran + dinh thuc)\n";
        cout << "  3. Bai 3: Mang dong (mini vector)\n";
        cout << "  4. Bai 4: Quan ly diem sinh vien (mini project)\n";
        cout << "  0. Thoat\n";
        cout << "Lua chon: "; cin >> choice;
        switch (choice) {
        case 1: bai1_mangCoBan();      break;
        case 2: bai2_maTran2D();       break;
        case 3: bai3_mangDong();       break;
        case 4: bai4_quanLySinhVien(); break;
        case 0: cout << "Tam biet!\n"; break;
        default: cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);

    return 0;
}
