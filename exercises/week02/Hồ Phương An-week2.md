# Tuần 2: Mảng & Con Trỏ — Bài tập

//Bài 1:Các loại cơ bản ⭐
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    if (n <= 0) {
        cout << "Mang khong hop le!" << endl;
        return 0;
    }

    int* arr = new int[n];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    // Tinh toan
    int minVal = arr[0];
    int maxVal = arr[0];
    long long tong = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
        tong += arr[i];
    }
    double trungBinh = (double)tong / n;

    // In ket qua
    cout << "\n--- KET QUA ---" << endl;
    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;
    cout << "Tong: " << tong << endl;
    cout << "Trung binh: " << trungBinh << endl;

    delete[] arr; // Giai phong bo nho
    return 0;
}

//Bài 2: Mảng 2D ⭐⭐
#include <iostream>
#include <iomanip> // Dung de format hien thi dep
using namespace std;

const int MAX = 3; // Dinh nghia san 3x3 theo de bai

void nhapMaTran(int mat[MAX][MAX], char ten) {
    cout << "Nhap ma tran " << ten << " (3x3):\n";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << ten << "[" << i << "][" << j << "] = ";
            cin >> mat[i][j];
        }
    }
}

void xuatMaTran(int mat[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << setw(6) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = { 0 };

    nhapMaTran(A, 'A');
    nhapMaTran(B, 'B');

    // Tich hai ma tran C = A * B
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            C[i][j] = 0;
            for (int k = 0; k < MAX; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMa tran A:\n"; xuatMaTran(A);
    cout << "\nMa tran B:\n"; xuatMaTran(B);
    cout << "\nMa tran ket qua C (A * B):\n"; xuatMaTran(C);

    return 0;
}
//Bài 3: Con trỏ & cấp phát ⭐⭐
#include <iostream>
using namespace std;

struct VectorDonGian {
    int* data;
    int size;       // So luong phan tu hien tai
    int capacity;   // Suc chua toi da truoc khi phai cap phat lai

    // Khoi tao vector
    void init() {
        size = 0;
        capacity = 2; // Khoi dau voi suc chua = 2
        data = new int[capacity];
    }

    // Tu dong nhan doi kich thuoc khi day
    void thayDoiKichThuoc() {
        capacity *= 2;
        int* temp = new int[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }

    void push_back(int value) {
        if (size >= capacity) {
            thayDoiKichThuoc();
        }
        data[size] = value;
        size++;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
        else {
            cout << "Mang rong, khong the pop!" << endl;
        }
    }

    int at(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        cout << "Loi: Vuot qua chi so mang! Giu tri mac dinh: ";
        return -1;
    }

    void hienThi() {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "] (Size: " << size << ", Capacity: " << capacity << ")\n";
    }

    // Giai phong bo nho khi xong xuat hien
    void clear() {
        delete[] data;
    }
};

int main() {
    VectorDonGian v;
    v.init();

    cout << "--- Them phan tu vao vector ---\n";
    v.push_back(10); v.hienThi();
    v.push_back(20); v.hienThi();
    v.push_back(30); v.hienThi(); // Luc nay capacity tu dong tang len 4

    cout << "\nPhan tu tai index 1: " << v.at(1) << endl;

    cout << "\n--- Xoa phan tu cuoi (pop_back) ---\n";
    v.pop_back(); v.hienThi();

    v.clear();
    return 0;
}
//Bài 4: 🔥 Dự Án Mini — Quản lý điểm học sinh ⭐⭐⭐
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

struct SinhVien {
    char mssv[20];
    char ten[50];
    double diem;
};

struct DanhSachSinhVien {
    SinhVien* ds;
    int size;
    int capacity;

    void init() {
        size = 0;
        capacity = 5;
        ds = new SinhVien[capacity];
    }

    void tangKichThuoc() {
        capacity += 5;
        SinhVien* temp = new SinhVien[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = ds[i];
        }
        delete[] ds;
        ds = temp;
    }

    // 1. Them sinh vien
    void themSinhVien() {
        if (size >= capacity) tangKichThuoc();

        cin.ignore();
        cout << "Nhap MSSV: "; cin.getline(ds[size].mssv, 20);
        cout << "Nhap Ho va Ten: "; cin.getline(ds[size].ten, 50);
        cout << "Nhap Diem: "; cin >> ds[size].diem;

        size++;
        cout << "-> Them sinh vien thanh cong!\n";
    }

    // In danh sach hien tai ra man hinh
    void hienThiDanhSach() {
        if (size == 0) {
            cout << "Danh sach trong!\n";
            return;
        }
        cout << "\n" << setfill('=') << setw(65) << "=" << setfill(' ') << endl;
        cout << setw(10) << left << "STT" << setw(15) << left << "MSSV" << setw(30) << left << "HO TEN" << setw(10) << left << "DIEM" << endl;
        cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;
        for (int i = 0; i < size; i++) {
            cout << setw(10) << left << i + 1
                << setw(15) << left << ds[i].mssv
                << setw(30) << left << ds[i].ten
                << setw(10) << left << fixed << setprecision(2) << ds[i].diem << endl;
        }
        cout << setfill('=') << setw(65) << "=" << setfill(' ') << endl;
    }

    // 2. Xoa hoac Sua sinh vien
    void xoaSuaSinhVien() {
        if (size == 0) {
            cout << "Danh sach trong, khong the xoa/sua!\n";
            return;
        }
        cout << "1. Xoa sinh vien\n2. Sua sinh vien\nChon lua chon: ";
        int luachon; cin >> luachon;
        cin.ignore();

        char target[20];
        cout << "Nhap MSSV can thuc hien: "; cin.getline(target, 20);

        int index = -1;
        for (int i = 0; i < size; i++) {
            if (strcmp(ds[i].mssv, target) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Khong tim thay MSSV nay!\n";
            return;
        }

        if (luachon == 1) { // Xoa sinh vien
            for (int i = index; i < size - 1; i++) {
                ds[i] = ds[i + 1];
            }
            size--;
            cout << "-> Da xoa sinh vien.\n";
        }
        else if (luachon == 2) { // Sua sinh vien
            cout << "Nhap Ten moi: "; cin.getline(ds[index].ten, 50);
            cout << "Nhap Diem moi: "; cin >> ds[index].diem;
            cout << "-> Da cap nhat thong tin sinh vien.\n";
        }
    }

    // 3. Tim kiem (Linear Search) theo ten hoac MSSV
    void timKiem() {
        cin.ignore();
        cout << "Nhap MSSV hoac Ten can tim kiem: ";
        char key[50]; cin.getline(key, 50);
        bool found = false;

        for (int i = 0; i < size; i++) {
            if (strcmp(ds[i].mssv, key) == 0 || strstr(ds[i].ten, key) != NULL) {
                if (!found) {
                    cout << "\nKet qua tim kiem:\n";
                    found = true;
                }
                cout << "MSSV: " << ds[i].mssv << " | Ten: " << ds[i].ten << " | Diem: " << ds[i].diem << endl;
            }
        }
        if (!found) cout << "Khong tim thay ket qua trung khop.\n";
    }

    // 4. Sap xep theo diem dung Bubble Sort
    void sapXepBubbleSort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (ds[j].diem > ds[j + 1].diem) {
                    // Swap
                    SinhVien temp = ds[j];
                    ds[j] = ds[j + 1];
                    ds[j + 1] = temp;
                }
            }
        }
        cout << "-> Da sap xep danh sach tang dan theo diem (Bubble Sort)!\n";
        hienThiDanhSach();
    }

    // 5. Thong ke va Xuat file
    void xuatBaoCaoFile() {
        if (size == 0) {
            cout << "Danh sach trong, khong co gi de xuat!\n";
            return;
        }

        double maxDiem = ds[0].diem, minDiem = ds[0].diem, tongDiem = 0;
        for (int i = 0; i < size; i++) {
            if (ds[i].diem > maxDiem) maxDiem = ds[i].diem;
            if (ds[i].diem < minDiem) minDiem = ds[i].diem;
            tongDiem += ds[i].diem;
        }
        double trungBinh = tongDiem / size;

        // Xuat ra man hinh console truoc
        cout << "\n--- THONG KE THONG TIN LOP HOC ---" << endl;
        cout << "Diem cao nhat: " << maxDiem << endl;
        cout << "Diem thap nhat: " << minDiem << endl;
        cout << "Diem trung binh lop: " << fixed << setprecision(2) << trungBinh << endl;

        // Ghi vao file diem_sinhvien.txt
        ofstream outFile("diem_sinhvien.txt");
        if (!outFile) {
            cout << "Loi: Khong the tao hay mo file de ghi!\n";
            return;
        }

        outFile << "=== DANH SACH DIEM SINH VIEN ===\n";
        for (int i = 0; i < size; i++) {
            outFile << "MSSV: " << ds[i].mssv << " | Ho Ten: " << ds[i].ten << " | Diem: " << ds[i].diem << "\n";
        }
        outFile << "\n--- THONG KE LOP ---\n";
        outFile << "Diem cao nhat: " << maxDiem << "\n";
        outFile << "Diem thap nhat: " << minDiem << "\n";
        outFile << "Diem trung binh: " << trungBinh << "\n";

        outFile.close();
        cout << "-> Da xuat du lieu va thong ke vao file 'diem_sinhvien.txt' thanh cong!\n";
    }

    void clear() {
        delete[] ds;
    }
};

int main() {
    DanhSachSinhVien qlsv;
    qlsv.init();
    int choice;

    do {
        cout << "\n=== QUAN LY DIEM SINH VIEN ===\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xoa / Sua sinh vien\n";
        cout << "3. Tim kiem (Linear Search)\n";
        cout << "4. Xep hang lop (Bubble Sort Diem)\n";
        cout << "5. Xuat bao cao va luu file text\n";
        cout << "6. Hien thi toan bo danh sach\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1: qlsv.themSinhVien(); break;
        case 2: qlsv.xoaSuaSinhVien(); break;
        case 3: qlsv.timKiem(); break;
        case 4: qlsv.sapXepBubbleSort(); break;
        case 5: qlsv.xuatBaoCaoFile(); break;
        case 6: qlsv.hienThiDanhSach(); break;
        case 0: cout << "Tam biet!\n"; break;
        default: cout << "Lua chon sai, vui long chon lai.\n";
        }
    } while (choice != 0);

    qlsv.clear();
    return 0;
} 
