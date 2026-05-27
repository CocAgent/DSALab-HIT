# Tuần 3: Tìm Kiếm — Bài tập

## 🎯 Mục tiêu tuần này
Cài đặt và so sánh Linear Search, Binary Search và các biến thể.

---

### Bài 1: Linear Search ⭐
Tìm kiếm tuyến tính trên mảng số nguyên và mảng chuỗi. Đếm số bước so sánh.
GIẢI:
// ===========================================
// BAI 1: LINEAR SEARCH
// Tim kiem tuyen tinh tren:
// + Mang so nguyen
// + Mang chuoi
// Dem so buoc so sanh
// ===========================================

#include <iostream>
#include <string>

using namespace std;

// ===========================================
// TIM KIEM TUYEN TINH SO NGUYEN
// ===========================================

int LinearSearchInt(int a[], int n, int x, int &steps) {

    steps = 0;

    for (int i = 0; i < n; i++) {

        steps++;

        if (a[i] == x)
            return i;
    }

    return -1;
}

// ===========================================
// TIM KIEM TUYEN TINH CHUOI
// ===========================================

int LinearSearchString(string a[], int n, string x, int &steps) {

    steps = 0;

    for (int i = 0; i < n; i++) {

        steps++;

        if (a[i] == x)
            return i;
    }

    return -1;
}

// ===========================================
// MAIN
// ===========================================

int main() {

    // ==========================
    // MANG SO NGUYEN
    // ==========================

    int a[] = {10, 25, 30, 45, 50, 70};

    int n = 6;

    int x;

    cout << "Nhap so can tim: ";
    cin >> x;

    int stepsInt;

    int vt = LinearSearchInt(a, n, x, stepsInt);

    if (vt != -1) {

        cout << "\nTim thay " << x
             << " tai vi tri " << vt << endl;
    }
    else {

        cout << "\nKhong tim thay!\n";
    }

    cout << "So buoc so sanh = "
         << stepsInt << endl;

    // ==========================
    // MANG CHUOI
    // ==========================

    string ds[] = {
        "An",
        "Binh",
        "Cuong",
        "Dung",
        "Hanh"
    };

    int m = 5;

    string ten;

    cin.ignore();

    cout << "\nNhap ten can tim: ";
    getline(cin, ten);

    int stepsString;

    int pos = LinearSearchString(
        ds,
        m,
        ten,
        stepsString
    );

    if (pos != -1) {

        cout << "\nTim thay "
             << ten
             << " tai vi tri "
             << pos
             << endl;
    }
    else {

        cout << "\nKhong tim thay!\n";
    }

    cout << "So buoc so sanh = "
         << stepsString
         << endl;

    return 0;
}

### Bài 2: Binary Search ⭐⭐
Cài đặt Binary Search iterative + recursive. Tìm vị trí đầu tiên và cuối cùng của phần tử trùng.
Giải:


#include <iostream>

using namespace std;



int BinarySearchIterative(int a[], int n, int x) {

    int left = 0;
    int right = n - 1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (a[mid] == x)
            return mid;

        if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int BinarySearchRecursive(
    int a[],
    int left,
    int right,
    int x
) {

    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (a[mid] == x)
        return mid;

    if (a[mid] < x)
        return BinarySearchRecursive(
            a,
            mid + 1,
            right,
            x
        );

    return BinarySearchRecursive(
        a,
        left,
        mid - 1,
        x
    );
}


int FirstPosition(int a[], int n, int x) {

    int left = 0;
    int right = n - 1;

    int result = -1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (a[mid] == x) {

            result = mid;

            right = mid - 1;
        }
        else if (a[mid] < x) {

            left = mid + 1;
        }
        else {

            right = mid - 1;
        }
    }

    return result;
}



int LastPosition(int a[], int n, int x) {

    int left = 0;
    int right = n - 1;

    int result = -1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (a[mid] == x) {

            result = mid;

            left = mid + 1;
        }
        else if (a[mid] < x) {

            left = mid + 1;
        }
        else {

            right = mid - 1;
        }
    }

    return result;
}


int main() {

    int a[] = {
        1, 2, 2, 2, 3, 4, 5, 5, 6, 7
    };

    int n = 10;

    int x;

    cout << "Nhap gia tri can tim: ";
    cin >> x;

   

    int vt1 = BinarySearchIterative(a, n, x);

    if (vt1 != -1) {

        cout << "\n[Iterative] Tim thay tai vi tri "
            << vt1 << endl;
    }
    else {

        cout << "\n[Iterative] Khong tim thay!\n";
    }

   

    int vt2 = BinarySearchRecursive(
        a,
        0,
        n - 1,
        x
    );

    if (vt2 != -1) {

        cout << "[Recursive] Tim thay tai vi tri "
            << vt2 << endl;
    }
    else {

        cout << "[Recursive] Khong tim thay!\n";
    }

   

    int first = FirstPosition(a, n, x);

    if (first != -1) {

        cout << "Vi tri dau tien = "
            << first << endl;
    }


    int last = LastPosition(a, n, x);

    if (last != -1) {

        cout << "Vi tri cuoi cung = "
            << last << endl;
    }

    return 0;
}

### Bài 3: So sánh hiệu năng ⭐⭐
Đo thời gian tìm kiếm với n = 10.000, 100.000, 1.000.000 phần tử. Vẽ bảng so sánh.
Giải:


#include <iostream>
#include <ctime>

using namespace std;


int LinearSearch(int a[], int n, int x) {

    for (int i = 0; i < n; i++) {

        if (a[i] == x)
            return i;
    }

    return -1;
}



int BinarySearch(int a[], int n, int x) {

    int left = 0;
    int right = n - 1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (a[mid] == x)
            return mid;

        if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}



void Test(int n) {

    int* a = new int[n];


    for (int i = 0; i < n; i++) {

        a[i] = i;
    }

    int x = n - 1;

 

    clock_t start1 = clock();

    LinearSearch(a, n, x);

    clock_t end1 = clock();

    double timeLinear =
        (double)(end1 - start1)
        / CLOCKS_PER_SEC;

  

    clock_t start2 = clock();

    BinarySearch(a, n, x);

    clock_t end2 = clock();

    double timeBinary =
        (double)(end2 - start2)
        / CLOCKS_PER_SEC;


    cout << n << "\t\t"
        << timeLinear << " s\t\t"
        << timeBinary << " s"
        << endl;

    delete[] a;
}



int main() {

    cout << "==============================================\n";
    cout << "SO SANH HIEU NANG TIM KIEM\n";
    cout << "==============================================\n";

    cout << "So phan tu\tLinear\t\t\tBinary\n";

    cout << "----------------------------------------------\n";

    Test(10000);

    Test(100000);

    Test(1000000);

    return 0;
}

### Bài 4: 🔥 Dự Án Mini — Smart Search Engine ⭐⭐⭐
> **Cảm hứng:** [Brute Force Search — algorithm-visualizer](https://algorithm-visualizer.org)

Xây dựng hệ thống tìm kiếm danh bạ điện thoại:
- **Tìm theo tên:** Linear Search (hỗ trợ tìm kiếm mờ — chứa chuỗi con)
- **Tìm theo số điện thoại:** Binary Search (sau khi sort theo SĐT)
- **Thống kê:** hiển thị số bước so sánh, thời gian tìm kiếm
- **Gợi ý:** nếu không tìm thấy, gợi ý 3 tên gần giống nhất

```
Nhập tên cần tìm: "Minh"
→ Tìm thấy 3 kết quả:
   1. Nguyễn Văn Minh   - 0901234567
   2. Trần Thị Minh Anh - 0912345678
   3. Lê Minh Tuấn      - 0923456789
   (Đã so sánh 15/50 phần tử — 0.002ms)
```Giải:


#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;


struct Contact {

    string ten;
    string sdt;
};



Contact ds[] = {

    {"Nguyen Van Minh", "0901234567"},
    {"Tran Thi Minh Anh", "0912345678"},
    {"Le Minh Tuan", "0923456789"},
    {"Pham Gia Bao", "0934567891"},
    {"Nguyen Hoang Long", "0945678912"},
    {"Tran Quoc Khanh", "0956789123"},
    {"Vo Minh Quan", "0967891234"},
    {"Do Thi Lan", "0978912345"},
    {"Nguyen Minh Duc", "0989123456"},
    {"Le Anh Tuan", "0991234567"}
};

int n = 10;



string ToLower(string s) {

    for (int i = 0; i < s.length(); i++) {

        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }

    return s;
}




void SearchByName(string key) {

    int steps = 0;

    bool found = false;

    clock_t start = clock();

    string lowerKey = ToLower(key);

    cout << "\nKet qua tim kiem:\n\n";

    for (int i = 0; i < n; i++) {

        steps++;

        string tenThuong =
            ToLower(ds[i].ten);

   
        if (tenThuong.find(lowerKey)
            != string::npos) {

            found = true;

            cout << setw(2)
                << i + 1
                << ". "
                << ds[i].ten
                << " - "
                << ds[i].sdt
                << endl;
        }
    }

    clock_t end = clock();

    double time =
        (double)(end - start)
        / CLOCKS_PER_SEC * 1000;

    if (!found) {

        cout << "Khong tim thay!\n";

      
        cout << "\nGoi y:\n";

        int dem = 0;

        for (int i = 0; i < n && dem < 3; i++) {

            string tenThuong =
                ToLower(ds[i].ten);

            if (tenThuong[0]
                == lowerKey[0]) {

                cout << "- "
                    << ds[i].ten
                    << endl;

                dem++;
            }
        }
    }

    cout << "\nDa so sanh "
        << steps
        << "/"
        << n
        << " phan tu";

    cout << " - "
        << time
        << " ms\n";
}


void SortByPhone() {

    for (int i = 0; i < n - 1; i++) {

        for (int j = n - 1; j > i; j--) {

            if (ds[j].sdt
                < ds[j - 1].sdt) {

                Contact temp = ds[j];

                ds[j] = ds[j - 1];

                ds[j - 1] = temp;
            }
        }
    }
}


int BinarySearchPhone(
    string key,
    int& steps
) {

    int left = 0;
    int right = n - 1;

    steps = 0;

    while (left <= right) {

        steps++;

        int mid =
            (left + right) / 2;

        if (ds[mid].sdt == key)
            return mid;

        if (ds[mid].sdt < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}



void XuatDanhBa() {

    cout << "\n=============================\n";

    cout << left
        << setw(25) << "TEN"
        << setw(15) << "SDT"
        << endl;

    cout << "=============================\n";

    for (int i = 0; i < n; i++) {

        cout << left
            << setw(25)
            << ds[i].ten
            << setw(15)
            << ds[i].sdt
            << endl;
    }
}



int main() {

    int chon;

    SortByPhone();

    do {

        cout << "\n====================================\n";
        cout << "       SMART SEARCH ENGINE\n";
        cout << "====================================\n";

        cout << "1. Xuat danh ba\n";
        cout << "2. Tim theo ten\n";
        cout << "3. Tim theo SDT\n";
        cout << "0. Thoat\n";

        cout << "====================================\n";

        cout << "Nhap lua chon: ";
        cin >> chon;

        cin.ignore();

        switch (chon) {

      

        case 1: {

            XuatDanhBa();

            break;
        }

           

        case 2: {

            string key;

            cout << "Nhap ten can tim: ";
            getline(cin, key);

            SearchByName(key);

            break;
        }

          

        case 3: {

            string sdt;

            cout << "Nhap SDT can tim: ";
            getline(cin, sdt);

            int steps;

            clock_t start = clock();

            int vt =
                BinarySearchPhone(
                    sdt,
                    steps
                );

            clock_t end = clock();

            double time =
                (double)(end - start)
                / CLOCKS_PER_SEC * 1000;

            if (vt != -1) {

                cout << "\nTim thay:\n";

                cout << ds[vt].ten
                    << " - "
                    << ds[vt].sdt
                    << endl;
            }
            else {

                cout << "\nKhong tim thay!\n";
            }

            cout << "\nSo buoc so sanh: "
                << steps;

            cout << "\nThoi gian tim: "
                << time
                << " ms\n";

            break;
        }

        case 0:

            cout << "Thoat chuong trinh!\n";

            break;

        default:

            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);

    return 0;
}


---
📁 Tham khảo: `Chuong2_TimKiem_SapXep/Chuong2_TimKiem_SapXep.cpp`
