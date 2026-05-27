# Tuần 2: Mảng & Con Trỏ — Bài tập

## 🎯 Mục tiêu tuần này
Thành thạo mảng 1D/2D, con trỏ, cấp phát động trong C++.

---

### Bài 1: Mảng cơ bản ⭐
Nhập mảng n phần tử. Tính min, max, trung bình, tổng. Không dùng STL.
void runBai1() {
    cout << "\n--- BAI 1: MANG CO BAN ---\n";
    int n;
    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Kich thuoc mang khong hop le!\n";
        return;
    }

    int* arr = new int[n];
    int sum = 0;

    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int min_val = arr[0], max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }

    cout << "-> Min: " << min_val << " | Max: " << max_val << "\n";
    cout << "-> Tong: " << sum << " | Trung binh: " << (double)sum / n << "\n";

    delete[] arr;
}

### Bài 2: Mảng 2D ⭐⭐
Nhân 2 ma trận n×n. Tính định thức ma trận 3×3. Hiển thị đẹp.
int determinant3x3(int mat[3][3]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
        - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
        + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

void runBai2() {
    cout << "\n--- BAI 2: MANG 2D ---\n";
    cout << "1. Tinh dinh thuc ma tran 3x3 mac dinh\n";
    int mat3x3[3][3] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };
    cout << "Ma tran 3x3:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << setw(3) << mat3x3[i][j];
        cout << endl;
    }
    cout << "-> Dinh thuc: " << determinant3x3(mat3x3) << "\n";
}
### Bài 3: Con trỏ & cấp phát động ⭐⭐
Cài đặt mảng động tự resize (như `std::vector` đơn giản). Hỗ trợ push_back, pop_back, at(i).
class MyVector {
private:
    int* data;
    int capacity;
    int current_size;

public:
    MyVector() : capacity(1), current_size(0) {
        data = new int[capacity];
    }
    ~MyVector() { delete[] data; }

    void push_back(int value) {
        if (current_size == capacity) {
            int* temp = new int[capacity * 2];
            for (int i = 0; i < capacity; i++) temp[i] = data[i];
            delete[] data;
            capacity *= 2;
            data = temp;
        }
        data[current_size++] = value;
    }

    void pop_back() { if (current_size > 0) current_size--; }
    int size() { return current_size; }
    int getCapacity() { return capacity; }

    void print() {
        cout << "[ ";
        for (int i = 0; i < current_size; i++) cout << data[i] << " ";
        cout << "]\n";
    }
};

void runBai3() {
    cout << "\n--- BAI 3: VECTOR TU TAO ---\n";
    MyVector vec;
    cout << "Push 10, 20, 30 vao vector...\n";
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.print();
    cout << "Size: " << vec.size() << ", Capacity: " << vec.getCapacity() << "\n";

    cout << "Pop 1 phan tu...\n";
    vec.pop_back();
    vec.print();
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
struct Student {
    string id, name;
    float score;
};

class StudentManager {
private:
    Student* list;
    int capacity, size;

    void resize() {
        capacity *= 2;
        Student* temp = new Student[capacity];
        for (int i = 0; i < size; i++) temp[i] = list[i];
        delete[] list;
        list = temp;
    }

public:
    StudentManager() : capacity(2), size(0) { list = new Student[capacity]; }
    ~StudentManager() { delete[] list; }

    void addStudent() {
        if (size == capacity) resize();
        cout << "Nhap MSSV: "; cin >> list[size].id;
        cin.ignore();
        cout << "Nhap Ten: "; getline(cin, list[size].name);
        cout << "Nhap Diem: "; cin >> list[size].score;
        size++;
        cout << "-> Them thanh cong!\n";
    }

    void sortStudents() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (list[j].score < list[j + 1].score) swap(list[j], list[j + 1]);
            }
        }
        cout << "-> Da xep hang lop (Giam dan theo diem).\n";
    }

    void exportToFile() {
        ofstream outFile("diem_sinhvien.txt");
        if (outFile.is_open()) {
            outFile << "=== DANH SACH SINH VIEN ===\n";
            for (int i = 0; i < size; i++) {
                outFile << list[i].id << " | " << list[i].name << " | " << list[i].score << "\n";
            }
            outFile.close();
            cout << "-> Xuat file diem_sinhvien.txt thanh cong!\n";
        }
    }
};

void runBai4() {
    StudentManager sm;
    int choice;
    do {
        cout << "\n=== QUAN LY DIEM SINH VIEN ===\n";
        cout << "1. Them sinh vien\n2. Xep hang lop\n3. Xuat bao cao\n0. Thoat Bai 4\n";
        cout << "Chon: "; cin >> choice;
        switch (choice) {
        case 1: sm.addStudent(); break;
        case 2: sm.sortStudents(); break;
        case 3: sm.exportToFile(); break;
        case 0: cout << "Thoat quan ly sinh vien.\n"; break;
        default: cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);
}
---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`
