# Tuần 2: Mảng & Con Trỏ — Bài tập

## 🎯 Mục tiêu tuần này.
Thành thạo mảng 1D/2D, con trỏ, cấp phát động trong C++.

---

### Bài 1: Mảng cơ bản ⭐
Nhập mảng n phần tử. Tính min, max, trung bình, tổng. Không dùng STL.
#include <iostream>

int main() {
    int n;
    std::cout << "Nhap n: "; std::cin >> n;
    int* arr = new int[n];

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        std::cout << "arr[" << i << "] = "; std::cin >> arr[i];
        sum += arr[i];
    }

    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    std::cout << "Min: " << min << "\nMax: " << max 
              << "\nTong: " << sum << "\nTB: " << (double)sum / n << "\n";
    
    delete[] arr;
    return 0;
}

### Bài 2: Mảng 2D ⭐⭐
Nhân 2 ma trận n×n. Tính định thức ma trận 3×3. Hiển thị đẹp.
#include <stdio.h>

#define MAX 100

void nhap(int a[MAX][MAX], int n) {
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            scanf_s("%d", &a[i][j]);
}

void xuat(int a[MAX][MAX], int n) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}

void nhan(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++) {
            C[i][j] = 0;
            for (int k = 0;k < n;k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int det3x3(int a[MAX][MAX]) {
    return
        a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
        - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
        + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

int main() {
    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Nhap n: ");
    scanf_s("%d", &n);

    printf("Nhap A:\n");
    nhap(A, n);

    printf("Nhap B:\n");
    nhap(B, n);

    nhan(A, B, C, n);

    printf("\nMa tran C:\n");
    xuat(C, n);

    if (n == 3)
        printf("\nDinh thuc A = %d", det3x3(A));

    return 0;
}

### Bài 3: Con trỏ & cấp phát động ⭐⭐
Cài đặt mảng động tự resize (như `std::vector` đơn giản). Hỗ trợ push_back, pop_back, at(i).
#include <iostream>
#include <stdexcept>

class Vector {
private:
    int* data;
    int capacity;
    int size;

    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Vector() : data(nullptr), capacity(0), size(0) {}

    ~Vector() { 
        delete[] data; 
    }

    Vector(const Vector& other) {
        size = other.size;
        capacity = other.capacity;
        if (capacity > 0) {
            data = new int[capacity];
            for (int i = 0; i < size; i++) data[i] = other.data[i];
        } else {
            data = nullptr;
        }
    }
    Vector& operator=(const Vector& other) {
        if (this != &other) { // Tránh tự gán chính mình
            delete[] data;    // Xóa dữ liệu cũ
            
            size = other.size;
            capacity = other.capacity;
            if (capacity > 0) {
                data = new int[capacity];
                for (int i = 0; i < size; i++) data[i] = other.data[i];
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    void push_back(int val) {
        if (size == capacity) resize();
        data[size++] = val;
    }

    void pop_back() {
        if (size > 0) size--;
    }

    int at(int i) const {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[i];
    }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
};

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

---
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

struct Student {
    std::string mssv;
    std::string name;
    double score;
};

class StudentManager {
private:
    Student* list;
    int capacity;
    int size;

    void resize() {
        capacity = (capacity == 0) ? 2 : capacity * 2;
        Student* newList = new Student[capacity];
        for (int i = 0; i < size; i++) newList[i] = list[i];
        delete[] list;
        list = newList;
    }

public:
    StudentManager() : list(nullptr), capacity(0), size(0) {}
    ~StudentManager() { delete[] list; }

    void addStudent() {
        if (size == capacity) resize();
        std::cout << "Nhap MSSV: "; std::cin >> list[size].mssv;
        std::cin.ignore();
        std::cout << "Nhap Ten: "; std::getline(std::cin, list[size].name);
        std::cout << "Nhap Diem: "; std::cin >> list[size].score;
        size++;
        std::cout << "=> Them thanh cong!\n";
    }

    void deleteStudent() {
        std::string id;
        std::cout << "Nhap MSSV can xoa: "; std::cin >> id;
        int idx = -1;
        for (int i = 0; i < size; i++) {
            if (list[i].mssv == id) { idx = i; break; }
        }
        if (idx == -1) {
            std::cout << "=> Khong tim thay sinh vien!\n";
            return;
        }
        for (int i = idx; i < size - 1; i++) list[i] = list[i + 1];
        size--;
        std::cout << "=> Xoa thanh cong!\n";
    }

    void searchStudent() {
        std::string keyword;
        std::cout << "Nhap MSSV hoac Ten can tim: ";
        std::cin.ignore(); std::getline(std::cin, keyword);
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (list[i].mssv == keyword || list[i].name.find(keyword) != std::string::npos) {
                std::cout << "[Tim Thay] MSSV: " << list[i].mssv 
                          << " | Ten: " << list[i].name << " | Diem: " << list[i].score << "\n";
                found = true;
            }
        }
        if (!found) std::cout << "=> Khong tim thay thong tin!\n";
    }

    void sortAndDisplay() {
        // Bubble Sort giam dan theo diem
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (list[j].score < list[j + 1].score) {
                    Student temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
        std::cout << "\n--- BXH DIEM SINH VIEN ---\n";
        for (int i = 0; i < size; i++) {
            std::cout << i+1 << ". [" << list[i].mssv << "] " 
                      << std::setw(20) << std::left << list[i].name << " : " << list[i].score << "\n";
        }
    }

    void exportReport() {
        if (size == 0) { std::cout << "Danh sach trong!\n"; return; }
        
        double maxS = list[0].score, minS = list[0].score, sum = 0;
        for (int i = 0; i < size; i++) {
            if (list[i].score > maxS) maxS = list[i].score;
            if (list[i].score < minS) minS = list[i].score;
            sum += list[i].score;
        }

        std::ofstream f("diem_sinhvien.txt");
        f << "=== BAO CAO THONG KE DIEM ===\n";
        f << "Tong so sinh vien: " << size << "\n";
        f << "Diem cao nhat: " << maxS << "\n";
        f << "Diem thap nhat: " << minS << "\n";
        f << "Diem trung binh: " << std::fixed << std::setprecision(2) << sum / size << "\n\n";
        f << "STT\tMSSV\t\tHo va Ten\t\tDiem\n";
        for (int i = 0; i < size; i++) {
            f << i + 1 << "\t" << list[i].mssv << "\t\t" << list[i].name << "\t\t" << list[i].score << "\n";
        }
        f.close();
        std::cout << "=> Da xuat bao cao ra file 'diem_sinhvien.txt'!\n";
    }
};

int main() {
    StudentManager sm;
    int choice;
    do {
        std::cout << "\n=== QUAN LY DIEM SINH VIEN ===\n";
        std::cout << "1. Them sinh vien\n2. Xoa sinh vien\n3. Tim kiem\n4. Xep hang lop\n5. Xuat bao cao\n0. Thoat\n";
        std::cout << "Lua chon cua ban: "; std::cin >> choice;
        switch (choice) {
            case 1: sm.addStudent(); break;
            case 2: sm.deleteStudent(); break;
            case 3: sm.searchStudent(); break;
            case 4: sm.sortAndDisplay(); break;
            case 5: sm.exportReport(); break;
        }
    } while (choice != 0);
    return 0;
}
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
