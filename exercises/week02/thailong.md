# Tuần 2: Mảng & Con Trỏ — Bài tập

## 🎯 Mục tiêu tuần này
Thành thạo mảng 1D/2D, con trỏ, cấp phát động trong C++.
MSSV: 2125110174
---

### Bài 1: Mảng cơ bản ⭐
Nhập mảng n phần tử. Tính min, max, trung bình, tổng. Không dùng STL.
Giải bài tập:
#include <iostream>

using namespace std;

void Bai1() {

    int n;

    cout << "Nhap n = ";
    cin >> n;

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

    cout << "\nTong = " << tong;
    cout << "\nMax = " << max;
    cout << "\nMin = " << min;
    cout << "\nTrung binh = " << tb;
}

int main() {

    Bai1();

    return 0;
}



### Bài 2: Mảng 2D ⭐⭐
Nhân 2 ma trận n×n. Tính định thức ma trận 3×3. Hiển thị đẹp.
Giải bài tập:
#include <iostream>
#include <iomanip>

using namespace std;

void NhapMaTran(int a[][10], int n) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

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

int main() {

    int n;

    cout << "Nhap n = ";
    cin >> n;

    int A[10][10];
    int B[10][10];
    int C[10][10];

    cout << "\nNhap ma tran A:\n";
    NhapMaTran(A, n);

    cout << "\nNhap ma tran B:\n";
    NhapMaTran(B, n);

    NhanMaTran(A, B, C, n);

    cout << "\nMa tran ket qua:\n";
    XuatMaTran(C, n);

    if (n == 3) {

        cout << "\nDinh thuc A = "
             << DinhThuc3x3(A);
    }

    return 0;
}


### Bài 3: Con trỏ & cấp phát động ⭐⭐
Cài đặt mảng động tự resize (như `std::vector` đơn giản). Hỗ trợ push_back, pop_back, at(i).
Giải bài:
#include <iostream>

using namespace std;

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

        if (index < 0 || index >= size)
            return -1;

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

int main() {

    MyVector v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.display();

    v.pop_back();

    v.display();

    cout << "Phan tu index 1 = "
         << v.at(1);

    return 0;
}


### Bài 4: 🔥 Dự Án Mini — Student Score Manager ⭐⭐⭐
> **Cảm hứng:** BaiTapTongHop — Quản lý sinh viên (DSALab)
> Giải bài:
> #include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct SinhVien {

    string ten;
    string mssv;
    float diem;
};

SinhVien ds[100];

int nSV = 0;

void ThemSinhVien() {

    cin.ignore(1000, '\n');

    cout << "Nhap ten: ";
    getline(cin, ds[nSV].ten);

    cout << "Nhap MSSV: ";
    getline(cin, ds[nSV].mssv);

    cout << "Nhap diem: ";
    cin >> ds[nSV].diem;

    nSV++;
}

void XuatDanhSach() {

    cout << "\n====================================\n";

    cout << left
         << setw(25) << "TEN"
         << setw(15) << "MSSV"
         << setw(10) << "DIEM"
         << endl;

    for (int i = 0; i < nSV; i++) {

        cout << left
             << setw(25) << ds[i].ten
             << setw(15) << ds[i].mssv
             << setw(10) << ds[i].diem
             << endl;
    }
}

void SapXepTheoDiem() {

    for (int i = 0; i < nSV - 1; i++) {

        for (int j = nSV - 1; j > i; j--) {

            if (ds[j].diem > ds[j - 1].diem) {

                SinhVien temp = ds[j];

                ds[j] = ds[j - 1];

                ds[j - 1] = temp;
            }
        }
    }
}

void TimKiemSinhVien() {

    string key;

    cin.ignore(1000, '\n');

    cout << "Nhap ten hoac MSSV: ";
    getline(cin, key);

    for (int i = 0; i < nSV; i++) {

        if (ds[i].ten == key ||
            ds[i].mssv == key) {

            cout << "\nTim thay:\n";

            cout << ds[i].ten
                 << " - "
                 << ds[i].mssv
                 << " - "
                 << ds[i].diem
                 << endl;
        }
    }
}

void XuatFile() {

    ofstream file("diem_sinhvien.txt");

    for (int i = 0; i < nSV; i++) {

        file << ds[i].ten << " | "
             << ds[i].mssv << " | "
             << ds[i].diem << endl;
    }

    file.close();
}

int main() {

    int chon;

    do {

        cout << "\n========== MENU ==========\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xuat danh sach\n";
        cout << "3. Tim kiem\n";
        cout << "4. Sap xep diem\n";
        cout << "5. Xuat file\n";
        cout << "0. Thoat\n";

        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {

        case 1:
            ThemSinhVien();
            break;

        case 2:
            XuatDanhSach();
            break;

        case 3:
            TimKiemSinhVien();
            break;

        case 4:
            SapXepTheoDiem();
            break;

        case 5:
            XuatFile();
            break;
        }

    } while (chon != 0);

    return 0;
}
