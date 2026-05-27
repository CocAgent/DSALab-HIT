#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/*
========================================================
            BAI 1 - MANG CO BAN
========================================================
Nhap mang n phan tu
Tinh:
- Min
- Max
- Tong
- Trung binh
========================================================
*/

void bai1() {
    int n;
    int a[100];

    cout << "\n===== BAI 1: MANG CO BAN =====\n";

    cout << "Nhap so phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int min = a[0];
    int max = a[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {

        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];

        sum += a[i];
    }

    float avg = (float)sum / n;

    cout << "\nMin = " << min;
    cout << "\nMax = " << max;
    cout << "\nTong = " << sum;
    cout << "\nTrung binh = " << avg << endl;
}

/*
========================================================
            BAI 2 - MANG 2 CHIEU
========================================================
Nhan 2 ma tran n x n
Tinh dinh thuc ma tran 3x3
========================================================
*/

void bai2() {

    int n;

    cout << "\n===== BAI 2: MA TRAN =====\n";

    cout << "Nhap kich thuoc ma tran n = ";
    cin >> n;

    int A[10][10];
    int B[10][10];
    int C[10][10];

    cout << "\nNhap ma tran A:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nNhap ma tran B:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    // Nhan ma tran
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            C[i][j] = 0;

            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMa tran ket qua:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cout << C[i][j] << "\t";
        }

        cout << endl;
    }

    // Dinh thuc 3x3
    int M[3][3];

    cout << "\nNhap ma tran 3x3 de tinh dinh thuc:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> M[i][j];
        }
    }

    int det =
        M[0][0] * (M[1][1]*M[2][2] - M[1][2]*M[2][1])
      - M[0][1] * (M[1][0]*M[2][2] - M[1][2]*M[2][0])
      + M[0][2] * (M[1][0]*M[2][1] - M[1][1]*M[2][0]);

    cout << "\nDinh thuc = " << det << endl;
}

/*
========================================================
      BAI 3 - CON TRO VA CAP PHAT DONG
========================================================
Mo phong Dynamic Array nhu vector
========================================================
*/

class DynamicArray {

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

    DynamicArray() {

        size = 0;
        capacity = 2;

        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(int value) {

        if (size == capacity) {
            resize();
        }

        data[size] = value;
        size++;
    }

    void pop_back() {

        if (size > 0) {
            size--;
        }
    }

    int at(int index) {

        if (index < 0 || index >= size) {
            return -1;
        }

        return data[index];
    }

    void print() {

        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }

        cout << endl;
    }
};

void bai3() {

    cout << "\n===== BAI 3: DYNAMIC ARRAY =====\n";

    DynamicArray arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    cout << "Mang sau push_back:\n";
    arr.print();

    arr.pop_back();

    cout << "Mang sau pop_back:\n";
    arr.print();

    cout << "Phan tu tai vi tri 1 = ";
    cout << arr.at(1) << endl;
}

/*
========================================================
      BAI 4 - QUAN LY DIEM SINH VIEN
========================================================
Them
Xoa
Tim kiem
Sap xep
Thong ke
Xuat file
========================================================
*/

struct Student {

    char name[50];
    char id[20];
    float score;
};

class StudentManager {

private:

    Student list[100];
    int size;

public:

    StudentManager() {
        size = 0;
    }

    void addStudent() {

        cin.ignore();

        cout << "Ten: ";
        cin.getline(list[size].name, 50);

        cout << "MSSV: ";
        cin.getline(list[size].id, 20);

        cout << "Diem: ";
        cin >> list[size].score;

        size++;

        cout << "Them thanh cong!\n";
    }

    void showStudents() {

        cout << "\n===== DANH SACH SINH VIEN =====\n";

        for (int i = 0; i < size; i++) {

            cout << i + 1 << ". ";

            cout << list[i].name << " | ";
            cout << list[i].id << " | ";
            cout << list[i].score << endl;
        }
    }

    void deleteStudent() {

        char id[20];

        cin.ignore();

        cout << "Nhap MSSV can xoa: ";
        cin.getline(id, 20);

        int pos = -1;

        for (int i = 0; i < size; i++) {

            if (strcmp(list[i].id, id) == 0) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {

            cout << "Khong tim thay!\n";
            return;
        }

        for (int i = pos; i < size - 1; i++) {
            list[i] = list[i + 1];
        }

        size--;

        cout << "Da xoa!\n";
    }

    void searchStudent() {

        char keyword[50];

        cin.ignore();

        cout << "Nhap ten hoac MSSV: ";
        cin.getline(keyword, 50);

        bool found = false;

        for (int i = 0; i < size; i++) {

            if (strcmp(list[i].name, keyword) == 0 ||
                strcmp(list[i].id, keyword) == 0) {

                cout << "\nTim thay:\n";

                cout << list[i].name << " | ";
                cout << list[i].id << " | ";
                cout << list[i].score << endl;

                found = true;
            }
        }

        if (!found) {
            cout << "Khong tim thay!\n";
        }
    }

    void sortByScore() {

        for (int i = 0; i < size - 1; i++) {

            int maxIndex = i;

            for (int j = i + 1; j < size; j++) {

                if (list[j].score > list[maxIndex].score) {
                    maxIndex = j;
                }
            }

            Student temp = list[i];
            list[i] = list[maxIndex];
            list[maxIndex] = temp;
        }

        cout << "Da sap xep!\n";
    }

    void statistics() {

        if (size == 0)
            return;

        float max = list[0].score;
        float min = list[0].score;
        float sum = 0;

        for (int i = 0; i < size; i++) {

            if (list[i].score > max)
                max = list[i].score;

            if (list[i].score < min)
                min = list[i].score;

            sum += list[i].score;
        }

        cout << "\n===== THONG KE =====\n";
        cout << "Diem cao nhat: " << max << endl;
        cout << "Diem thap nhat: " << min << endl;
        cout << "Diem trung binh: " << sum / size << endl;
    }

    void exportFile() {

        ofstream file("diem_sinhvien.txt");

        for (int i = 0; i < size; i++) {

            file << list[i].name << " | ";
            file << list[i].id << " | ";
            file << list[i].score << endl;
        }

        file.close();

        cout << "Da xuat file!\n";
    }
};

void bai4() {

    StudentManager sm;

    int choice;

    do {

        cout << "\n=== QUAN LY DIEM SINH VIEN ===\n";

        cout << "1. Them sinh vien\n";
        cout << "2. Xoa sinh vien\n";
        cout << "3. Tim kiem\n";
        cout << "4. Xep hang lop\n";
        cout << "5. Hien thi danh sach\n";
        cout << "6. Thong ke\n";
        cout << "7. Xuat bao cao\n";
        cout << "0. Thoat\n";

        cout << "Chon: ";
        cin >> choice;

        switch (choice) {

        case 1:
            sm.addStudent();
            break;

        case 2:
            sm.deleteStudent();
            break;

        case 3:
            sm.searchStudent();
            break;

        case 4:
            sm.sortByScore();
            break;

        case 5:
            sm.showStudents();
            break;

        case 6:
            sm.statistics();
            break;

        case 7:
            sm.exportFile();
            break;

        case 0:
            cout << "Tam biet!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}

/*
========================================================
                        MAIN
========================================================
*/

int main() {

    int choice;

    do {

        cout << "\n========== MENU ==========\n";

        cout << "1. Bai 1 - Mang co ban\n";
        cout << "2. Bai 2 - Ma tran\n";
        cout << "3. Bai 3 - Dynamic Array\n";
        cout << "4. Bai 4 - Quan ly sinh vien\n";
        cout << "0. Thoat\n";

        cout << "Chon bai: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bai1();
            break;

        case 2:
            bai2();
            break;

        case 3:
            bai3();
            break;

        case 4:
            bai4();
            break;

        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}
