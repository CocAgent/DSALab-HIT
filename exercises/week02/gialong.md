// ============================================================

//  TONG HOP BAI TAP C++ - CTDL & GIAI THUAT

//  Hoan chinh + Sua loi + Chay on dinh

// ============================================================

 

#include <iostream>

#include <iomanip>

#include <string>

#include <fstream>

#include <cstdlib>

 

using namespace std;

 

// ============================================================

//  BAI 1: MANG CO BAN

// ============================================================

 

void Bai1() {

 

    cout << "\n====================================\n";

    cout << "        BAI 1: MANG CO BAN\n";

    cout << "====================================\n";

 

    int n;

 

    cout << "Nhap so phan tu n = ";

    cin >> n;

 

    if (n <= 0 || n > 100) {

        cout << "So luong khong hop le!\n";

        return;

    }

 

    int a[100];

 

    for (int i = 0; i < n; i++) {

        cout << "a[" << i << "] = ";

        cin >> a[i];

    }

 

    int tong = 0;

    int max = a[0];

    int min = a[0];

 

    for (int i = 0; i < n; i++) {

 

        tong += a[i];

 

        if (a[i] > max)

            max = a[i];

 

        if (a[i] < min)

            min = a[i];

    }

 

    float tb = (float)tong / n;

 

    cout << "\nMang vua nhap: ";

 

    for (int i = 0; i < n; i++)

        cout << a[i] << " ";

 

    cout << "\nTong = " << tong;

    cout << "\nMax = " << max;

    cout << "\nMin = " << min;

    cout << "\nTrung binh = " << tb << endl;

}

 

// ============================================================

//  BAI 2: MA TRAN

// ============================================================

 

void NhapMaTran(int a[][10], int n) {

 

    for (int i = 0; i < n; i++) {

 

        for (int j = 0; j < n; j++) {

 

            cout << "a[" << i << "][" << j << "] = ";

            cin >> a[i][j];

        }

    }

}

 

void XuatMaTran(int a[][10], int n) {

 

    for (int i = 0; i < n; i++) {

 

        for (int j = 0; j < n; j++) {

 

            cout << setw(6) << a[i][j];

        }

 

        cout << endl;

    }

}

 

void NhanMaTran(int A[][10], int B[][10], int C[][10], int n) {

 

    for (int i = 0; i < n; i++) {

 

        for (int j = 0; j < n; j++) {

 

            C[i][j] = 0;

 

            for (int k = 0; k < n; k++) {

 

                C[i][j] += A[i][k] * B[k][j];

            }

        }

    }

}

 

int DinhThuc3x3(int a[][10]) {

 

    return

        a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])

        - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])

        + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

}

 

void Bai2() {

 

    cout << "\n====================================\n";

    cout << "         BAI 2: MA TRAN\n";

    cout << "====================================\n";

 

    int n;

 

    cout << "Nhap cap ma tran n = ";

    cin >> n;

 

    if (n <= 0 || n > 10) {

        cout << "Kich thuoc khong hop le!\n";

        return;

    }

 

    int A[10][10];

    int B[10][10];

    int C[10][10];

 

    cout << "\nNhap ma tran A:\n";

    NhapMaTran(A, n);

 

    cout << "\nNhap ma tran B:\n";

    NhapMaTran(B, n);

 

    NhanMaTran(A, B, C, n);

 

    cout << "\nMa tran A:\n";

    XuatMaTran(A, n);

 

    cout << "\nMa tran B:\n";

    XuatMaTran(B, n);

 

    cout << "\nMa tran A x B:\n";

    XuatMaTran(C, n);

 

    if (n == 3) {

 

        cout << "\nDinh thuc ma tran A = "

            << DinhThuc3x3(A) << endl;

    }

}

 

// ============================================================

//  BAI 3: VECTOR DON GIAN

// ============================================================

 

class MyVector {

 

private:

 

    int* data;

    int size;

    int capacity;

 

    void resize() {

 

        capacity *= 2;

 

        int* newData = new int[capacity];

 

        for (int i = 0; i < size; i++) {

 

            newData[i] = data[i];

        }

 

        delete[] data;

 

        data = newData;

    }

 

public:

 

    MyVector() {

 

        size = 0;

        capacity = 2;

 

        data = new int[capacity];

    }

 

    ~MyVector() {

 

        delete[] data;

    }

 

    void push_back(int value) {

 

        if (size == capacity)

            resize();

 

        data[size] = value;

 

        size++;

    }

 

    void pop_back() {

 

        if (size > 0)

            size--;

    }

 

    int at(int index) {

 

        if (index < 0 || index >= size) {

 

            cout << "Index khong hop le!\n";

            return -1;

        }

 

        return data[index];

    }

 

    void display() {

 

        cout << "[ ";

 

        for (int i = 0; i < size; i++) {

 

            cout << data[i] << " ";

        }

 

        cout << "]\n";

    }

};

 

void Bai3() {

 

    cout << "\n====================================\n";

    cout << "     BAI 3: VECTOR DON GIAN\n";

    cout << "====================================\n";

 

    MyVector v;

 

    v.push_back(10);

    v.push_back(20);

    v.push_back(30);

    v.push_back(40);

 

    cout << "\nSau push_back:\n";

    v.display();

 

    v.pop_back();

 

    cout << "\nSau pop_back:\n";

    v.display();

 

    cout << "\nGia tri tai index 1 = "

        << v.at(1) << endl;

}

 

// ============================================================

//  BAI 4: QUAN LY DIEM SINH VIEN

// ============================================================

 

struct SinhVien {

 

    string ten;

    string mssv;

    float diem;

};

 

SinhVien ds[100];

int nSV = 0;

 

void ThemSinhVien() {

 

    if (nSV >= 100) {

 

        cout << "Danh sach day!\n";

        return;

    }

 

    cin.ignore(1000, '\n');

 

    cout << "\nNhap ten sinh vien: ";

    getline(cin, ds[nSV].ten);

 

    cout << "Nhap MSSV: ";

    getline(cin, ds[nSV].mssv);

 

    cout << "Nhap diem: ";

    cin >> ds[nSV].diem;

 

    nSV++;

 

    cout << "Them thanh cong!\n";

}

 

void XuatDanhSach() {

 

    if (nSV == 0) {

 

        cout << "Danh sach rong!\n";

        return;

    }

 

    cout << "\n=================================================\n";

    cout << left

        << setw(25) << "TEN"

        << setw(15) << "MSSV"

        << setw(10) << "DIEM"

        << endl;

 

    cout << "=================================================\n";

 

    for (int i = 0; i < nSV; i++) {

 

        cout << left

            << setw(25) << ds[i].ten

            << setw(15) << ds[i].mssv

            << setw(10) << ds[i].diem

            << endl;

    }

}

 

void XoaSinhVien() {

 

    if (nSV == 0) {

 

        cout << "Danh sach rong!\n";

        return;

    }

 

    string mssv;

 

    cin.ignore(1000, '\n');

 

    cout << "Nhap MSSV can xoa: ";

    getline(cin, mssv);

 

    int vt = -1;

 

    for (int i = 0; i < nSV; i++) {

 

        if (ds[i].mssv == mssv) {

 

            vt = i;

            break;

        }

    }

 

    if (vt == -1) {

 

        cout << "Khong tim thay sinh vien!\n";

        return;

    }

 

    for (int i = vt; i < nSV - 1; i++) {

 

        ds[i] = ds[i + 1];

    }

 

    nSV--;

 

    cout << "Da xoa sinh vien!\n";

}

 

void TimKiemSinhVien() {

 

    if (nSV == 0) {

 

        cout << "Danh sach rong!\n";

        return;

    }

 

    string key;

 

    cin.ignore(1000, '\n');

 

    cout << "Nhap ten hoac MSSV: ";

    getline(cin, key);

 

    bool found = false;

 

    for (int i = 0; i < nSV; i++) {

 

        if (ds[i].ten == key ||

            ds[i].mssv == key) {

 

            cout << "\nTim thay:\n";

 

            cout << "Ten  : " << ds[i].ten << endl;

            cout << "MSSV : " << ds[i].mssv << endl;

            cout << "Diem : " << ds[i].diem << endl;

 

            found = true;

        }

    }

 

    if (!found)

        cout << "Khong tim thay!\n";

}

 

void SapXepTheoDiem() {

 

    if (nSV == 0) {

 

        cout << "Danh sach rong!\n";

        return;

    }

 

    for (int i = 0; i < nSV - 1; i++) {

 

        for (int j = nSV - 1; j > i; j--) {

 

            if (ds[j].diem > ds[j - 1].diem) {

 

                SinhVien temp = ds[j];

                ds[j] = ds[j - 1];

                ds[j - 1] = temp;

            }

        }

    }

 

    cout << "Da sap xep giam dan theo diem!\n";

}

 

void ThongKe() {

 

    if (nSV == 0) {

 

        cout << "Danh sach rong!\n";

        return;

    }

 

    float max = ds[0].diem;

    float min = ds[0].diem;

    float tong = 0;

 

    for (int i = 0; i < nSV; i++) {

 

        tong += ds[i].diem;

 

        if (ds[i].diem > max)

            max = ds[i].diem;

 

        if (ds[i].diem < min)

            min = ds[i].diem;

    }

 

    cout << "\nDiem cao nhat : " << max;

    cout << "\nDiem thap nhat: " << min;

    cout << "\nDiem trung binh lop: "

        << tong / nSV << endl;

}

 

void XuatFile() {

 

    ofstream file("diem_sinhvien.txt");

 

    if (!file) {

 

        cout << "Khong mo duoc file!\n";

        return;

    }

 

    file << "DANH SACH SINH VIEN\n\n";

 

    for (int i = 0; i < nSV; i++) {

 

        file << ds[i].ten << " | "

            << ds[i].mssv << " | "

            << ds[i].diem << endl;

    }

 

    file.close();

 

    cout << "Da xuat file diem_sinhvien.txt\n";

}

 

void Bai4() {

 

    int chon;

 

    do {

 

        cout << "\n====================================\n";

        cout << "     QUAN LY DIEM SINH VIEN\n";

        cout << "====================================\n";

        cout << "1. Them sinh vien\n";

        cout << "2. Xoa sinh vien\n";

        cout << "3. Tim kiem sinh vien\n";

        cout << "4. Sap xep theo diem\n";

        cout << "5. Thong ke lop\n";

        cout << "6. Xuat danh sach\n";

        cout << "7. Xuat file\n";

        cout << "0. Thoat\n";

        cout << "====================================\n";

        cout << "Nhap lua chon: ";

        cin >> chon;

 

        switch (chon) {

 

        case 1:

            ThemSinhVien();

            break;

 

        case 2:

            XoaSinhVien();

            break;

 

        case 3:

            TimKiemSinhVien();

            break;

 

        case 4:

            SapXepTheoDiem();

            break;

 

        case 5:

            ThongKe();

            break;

 

        case 6:

            XuatDanhSach();

            break;

 

        case 7:

            XuatFile();

            break;

 

        case 0:

            cout << "Thoat chuong trinh!\n";

            break;

 

        default:

            cout << "Lua chon khong hop le!\n";

        }

 

    } while (chon != 0);

}

 

// ============================================================

//  MAIN



// ============================================================

 

int main() {

 

    system("chcp 65001");

 

    Bai1();

 

    Bai2();

 

    Bai3();

 

    Bai4();

 

    return 0;

}

