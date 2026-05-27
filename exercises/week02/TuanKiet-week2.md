#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

// =========================================================================
// BÀI 1: MẢNG CƠ BẢN ⭐
// =========================================================================
void bai1_MangCoBan() {
    cout << "\n--- [BAI 1] MANG CO BAN ---\n";
    int n;
    cout << "Nhap so phan tu n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So phan tu khong hop le!\n";
        return;
    }

    int arr[1000];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    int min = arr[0], max = arr[0];
    long long tong = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
        tong += arr[i];
    }

    cout << "\n>> KET QUA BAI 1:\n";
    cout << "+ Min: " << min << "\n";
    cout << "+ Max: " << max << "\n";
    cout << "+ Tong: " << tong << "\n";
    cout << "+ Trung binh: " << (double)tong / n << "\n";
}

// =========================================================================
// BÀI 2: MẢNG 2D ⭐⭐
// =========================================================================
void bai2_Mang2D() {
    cout << "\n--- [BAI 2] MANG 2D (NHAN MA TRAN & DINH THUC 3X3) ---\n";

    // Part 1: Nhân ma trận n x n
    int n;
    cout << "Nhap kich thuoc ma tran n x n de nhan: ";
    cin >> n;

    int A[50][50], B[50][50], C[50][50] = { 0 };

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> A[i][j];

    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> B[i][j];

    // Thuật toán nhân
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\n>> Ma tran ket qua C = A * B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(6) << C[i][j] << " ";
        }
        cout << "\n";
    }

    // Part 2: Định thức 3x3
    int M[3][3];
    cout << "\nNhap tiep ma tran 3x3 de tinh dinh thuc:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> M[i][j];

    int det = M[0][0] * M[1][1] * M[2][2] + M[0][1] * M[1][2] * M[2][0] + M[0][2] * M[1][0] * M[2][1]
        - M[0][2] * M[1][1] * M[2][0] - M[0][0] * M[1][2] * M[2][1] - M[0][1] * M[1][0] * M[2][2];

    cout << ">> Dinh thuc (Determinant) 3x3 la: " << det << "\n";
}

// =========================================================================
// BÀI 3: CON TRỎ & CẤP PHÁT ĐỘNG ⭐⭐
// =========================================================================
struct VectorDonGian {
    int* data;
    int dungLuong;
    int kichThuoc;

    void khoiTao(int initCapacity = 2) {
        dungLuong = initCapacity;
        kichThuoc = 0;
        data = new int[dungLuong];
    }

    void resize() {
        dungLuong *= 2;
        int* temp = new int[dungLuong];
        for (int i = 0; i < kichThuoc; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }

    void push_back(int value) {
        if (kichThuoc == dungLuong) resize();
        data[kichThuoc++] = value;
    }

    void pop_back() {
        if (kichThuoc > 0) kichThuoc--;
    }

    int at(int index) {
        if (index >= 0 && index < kichThuoc) return data[index];
        return -1;
    }

    void giaiPhong() {
        delete[] data;
    }
};

void bai3_ConTroCapPhatDong() {
    cout << "\n--- [BAI 3] CON TRO & MANG DONG TU RESIZE ---\n";
    VectorDonGian v;
    v.khoiTao(2); // Thử nghiệm sức chứa ban đầu bằng 2

    cout << "Ghi chu: Push_back 3 phan tu (10, 20, 30) de tu kich hoat resize...\n";
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << ">> Cac phan tu hien tai: ";
    for (int i = 0; i < v.kichThuoc; i++) cout << v.at(i) << " ";
    cout << "\n+ Kich thuoc thuc te: " << v.kichThuoc << "\n+ Dung luong sau khi tu resize: " << v.dungLuong << "\n";

    v.pop_back();
    cout << ">> Sau khi pop_back (xoa cuoi), phan tu cuoi hien tai la: " << v.at(v.kichThuoc - 1) << "\n";

    v.giaiPhong();
}

// =========================================================================
// BÀI 4: DỰ ÁN MINI — STUDENT SCORE MANAGER ⭐⭐⭐
// =========================================================================
#define MAX_SV 100
struct Student {
    char name[50];
    char mssv[15];
    float score;
};

Student ds[MAX_SV];    // Mảng tĩnh quản lý SV
int nSV = 0;           // Số lượng SV hiện tại

void addStudent() {
    if (nSV >= MAX_SV) { cout << "Danh sach da day!\n"; return; }
    cout << "Nhap Ten: "; cin.getline(ds[nSV].name, 50);
    cout << "Nhap MSSV: "; cin.getline(ds[nSV].mssv, 15);
    cout << "Nhap Diem: "; cin >> ds[nSV].score;
    cin.ignore(); // Xóa dấu thừa '\n'
    nSV++;
    cout << ">> Them sinh vien thanh cong!\n";
}

void deleteStudent() {
    char mssvXoa[15];
    cout << "Nhap MSSV can xoa: "; cin.getline(mssvXoa, 15);
    int idx = -1;
    for (int i = 0; i < nSV; i++) {
        if (strcmp(ds[i].mssv, mssvXoa) == 0) { idx = i; break; }
    }
    if (idx == -1) { cout << ">> Khong tim thay MSSV nay!\n"; return; }

    for (int i = idx; i < nSV - 1; i++) ds[i] = ds[i + 1];
    nSV--;
    cout << ">> Da xoa sinh vien khoi danh sach!\n";
}

void searchStudent() {
    char key[50];
    cout << "Nhap Ten hoac MSSV can tim: "; cin.getline(key, 50);
    bool found = false;
    cout << "\n--- KET QUA TIM KIEM ---\n";
    for (int i = 0; i < nSV; i++) {
        if (strstr(ds[i].name, key) || strcmp(ds[i].mssv, key) == 0) {
            cout << ds[i].name << " | " << ds[i].mssv << " | Diem: " << ds[i].score << "\n";
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay sinh vien nao giong tu khoa.\n";
}

void sortByScore() {
    for (int i = 0; i < nSV - 1; i++) {
        for (int j = 0; j < nSV - i - 1; j++) {
            if (ds[j].score < ds[j + 1].score) {
                Student tmp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = tmp;
            }
        }
    }
    cout << ">> Da sap xep thu tu giam dan theo diem!\n";
}

void exportFile() {
    ofstream f("diem_sinhvien.txt");
    if (!f.is_open()) { cout << "Loi mo file!\n"; return; }

    f << "STT | Ten          | MSSV   | Diem\n";
    f << "----+---------------+--------+-----\n";
    float maxS = ds[0].score, minS = ds[0].score, sumS = 0;

    for (int i = 0; i < nSV; i++) {
        f << i + 1 << "   | " << ds[i].name << " | " << ds[i].mssv << " | " << ds[i].score << "\n";
        if (ds[i].score > maxS) maxS = ds[i].score;
        if (ds[i].score < minS) minS = ds[i].score;
        sumS += ds[i].score;
    }

    if (nSV > 0) {
        f << "\n--- THONG KE LOP ---\n";
        f << "Cao nhat: " << maxS << "\nThap nhat: " << minS << "\nTrung binh: " << sumS / nSV << "\n";
    }
    f.close();
    cout << "Da xuat bao cao vao file diem_sinhvien.txt\n";
}

void printList() {
    if (nSV == 0) { cout << "Danh sach trong!\n"; return; }
    cout << "\n--- DANH SACH SINH VIEN HIEN TAI ---\n";
    for (int i = 0; i < nSV; i++) {
        cout << i + 1 << ". " << ds[i].name << " | MSSV: " << ds[i].mssv << " | Diem: " << ds[i].score << "\n";
    }
}

// =========================================================================
// HÀM MAIN - QUẢN LÝ MENU TỔNG HỢP
// =========================================================================
int main() {
    int choice;
    do {
        cout << "\n=========================================\n";
        cout << "        MENU CHUONG TRINH TONG HOP       \n";
        cout << "=========================================\n";
        cout << "1. Chay [Bai 1: Mang co ban]\n";
        cout << "2. Chay [Bai 2: Mang 2D (Ma tran)]\n";
        cout << "3. Chay [Bai 3: Con tro & Mang dong]\n";
        cout << "-----------------------------------------\n";
        cout << "CHUC NANG [BAI 4: QUAN LY DIEM SINH VIEN]\n";
        cout << "4. Them sinh vien\n";
        cout << "5. Xoa sinh vien\n";
        cout << "6. Tim kiem sinh vien\n";
        cout << "7. Xep hang lop (Sap xep diem)\n";
        cout << "8. Xuat bao cao ra FILE (.txt)\n";
        cout << "9. Xem danh sach sinh vien hien tai\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "=========================================\n";
        cout << "Nhap lua chon cua ban (0-9): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Loi: Vui long chi nhap so tu 0 den 9!\n";
            continue;
        }

        cin.ignore(); // Xóa ký tự '\n' sau khi nhập số lựa chọn để tránh trôi lệnh chuỗi

        switch (choice) {
        case 1: bai1_MangCoBan(); break;
        case 2: bai2_Mang2D(); break;
        case 3: bai3_ConTroCapPhatDong(); break;
        case 4: addStudent(); break;
        case 5: deleteStudent(); break;
        case 6: searchStudent(); break;
        case 7: sortByScore(); printList(); break;
        case 8: exportFile(); break;
        case 9: printList(); break;
        case 0: cout << "Da thoat chuong trinh. Tam biet!\n"; break;
        default: cout << "Lua chon khong hop le, vui long chon lai!\n";
        }
    } while (choice != 0);

    return 0;
}
