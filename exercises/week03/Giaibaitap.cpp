#include <iostream>
#include <cstring>
#include <chrono>

using namespace std;
using namespace chrono;

/*
========================================================
                BAI 1 - LINEAR SEARCH
========================================================
- Tim kiem tuyen tinh tren mang so nguyen
- Tim kiem tren mang chuoi
- Dem so buoc so sanh
========================================================
*/

void linearSearchNumber() {

    int a[100];
    int n, x;

    cout << "\n===== LINEAR SEARCH SO NGUYEN =====\n";

    cout << "Nhap so phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "Nhap gia tri can tim: ";
    cin >> x;

    int step = 0;
    int pos = -1;

    for (int i = 0; i < n; i++) {

        step++;

        if (a[i] == x) {
            pos = i;
            break;
        }
    }

    if (pos != -1)
        cout << "Tim thay tai vi tri " << pos << endl;
    else
        cout << "Khong tim thay!\n";

    cout << "So buoc so sanh: " << step << endl;
}

void linearSearchString() {

    char names[5][50] = {
        "Minh",
        "An",
        "Tuan",
        "Hoa",
        "Linh"
    };

    char keyword[50];

    cout << "\n===== LINEAR SEARCH CHUOI =====\n";

    cin.ignore();

    cout << "Nhap ten can tim: ";
    cin.getline(keyword, 50);

    int step = 0;
    bool found = false;

    for (int i = 0; i < 5; i++) {

        step++;

        if (strcmp(names[i], keyword) == 0) {

            cout << "Tim thay: " << names[i] << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Khong tim thay!\n";

    cout << "So buoc so sanh: " << step << endl;
}

/*
========================================================
                BAI 2 - BINARY SEARCH
========================================================
- Iterative
- Recursive
- Tim vi tri dau tien va cuoi cung
========================================================
*/

int binarySearchIterative(int a[], int n, int x) {

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

int binarySearchRecursive(int a[], int left, int right, int x) {

    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (a[mid] == x)
        return mid;

    if (a[mid] < x)
        return binarySearchRecursive(a, mid + 1, right, x);

    return binarySearchRecursive(a, left, mid - 1, x);
}

int firstPosition(int a[], int n, int x) {

    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (a[mid] == x) {
            result = mid;
            right = mid - 1;
        }
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return result;
}

int lastPosition(int a[], int n, int x) {

    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (a[mid] == x) {
            result = mid;
            left = mid + 1;
        }
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return result;
}

void bai2() {

    cout << "\n===== BINARY SEARCH =====\n";

    int a[] = {1,2,2,2,3,4,5,6,7};
    int n = 9;
    int x = 2;

    int pos1 = binarySearchIterative(a, n, x);
    int pos2 = binarySearchRecursive(a, 0, n - 1, x);

    cout << "Iterative position: " << pos1 << endl;
    cout << "Recursive position: " << pos2 << endl;

    cout << "First position: ";
    cout << firstPosition(a, n, x) << endl;

    cout << "Last position: ";
    cout << lastPosition(a, n, x) << endl;
}

/*
========================================================
            BAI 3 - SO SANH HIEU NANG
========================================================
- Do thoi gian tim kiem
- n = 10.000 / 100.000 / 1.000.000
========================================================
*/

void performanceTest(int n) {

    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        a[i] = i;
    }

    int x = n - 1;

    // Linear Search
    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        if (a[i] == x)
            break;
    }

    auto end1 = high_resolution_clock::now();

    // Binary Search
    auto start2 = high_resolution_clock::now();

    binarySearchIterative(a, n, x);

    auto end2 = high_resolution_clock::now();

    auto linearTime =
        duration_cast<microseconds>(end1 - start1);

    auto binaryTime =
        duration_cast<microseconds>(end2 - start2);

    cout << "\nN = " << n << endl;

    cout << "Linear Search: ";
    cout << linearTime.count() << " microseconds\n";

    cout << "Binary Search: ";
    cout << binaryTime.count() << " microseconds\n";

    delete[] a;
}

void bai3() {

    cout << "\n===== SO SANH HIEU NANG =====\n";

    performanceTest(10000);
    performanceTest(100000);
    performanceTest(1000000);

    cout << "\nBang so sanh:\n";

    cout << "----------------------------------\n";
    cout << "N\tLinear\tBinary\n";
    cout << "10000\tCham\tRat nhanh\n";
    cout << "100000\tRat cham\tNhanh\n";
    cout << "1000000\tCuc cham\tGan nhu tuc thi\n";
    cout << "----------------------------------\n";
}

/*
========================================================
        BAI 4 - SMART SEARCH ENGINE
========================================================
- Tim theo ten: Linear Search
- Tim theo SDT: Binary Search
- Goi y ten gan dung
- Dem buoc va thoi gian
========================================================
*/

struct Contact {

    char name[50];
    char phone[20];
};

class SmartSearchEngine {

private:

    Contact list[100];
    int size;

public:

    SmartSearchEngine() {

        size = 5;

        strcpy(list[0].name, "Nguyen Van Minh");
        strcpy(list[0].phone, "0901234567");

        strcpy(list[1].name, "Tran Thi Minh Anh");
        strcpy(list[1].phone, "0912345678");

        strcpy(list[2].name, "Le Minh Tuan");
        strcpy(list[2].phone, "0923456789");

        strcpy(list[3].name, "Pham Gia Bao");
        strcpy(list[3].phone, "0934567890");

        strcpy(list[4].name, "Hoang Linh");
        strcpy(list[4].phone, "0945678901");
    }

    void searchByName() {

        char keyword[50];

        cin.ignore();

        cout << "\nNhap ten can tim: ";
        cin.getline(keyword, 50);

        int step = 0;
        int found = 0;

        auto start = high_resolution_clock::now();

        for (int i = 0; i < size; i++) {

            step++;

            if (strstr(list[i].name, keyword)) {

                found++;

                cout << found << ". ";
                cout << list[i].name << " - ";
                cout << list[i].phone << endl;
            }
        }

        auto end = high_resolution_clock::now();

        auto time =
            duration_cast<microseconds>(end - start);

        if (found == 0) {

            cout << "\nKhong tim thay!\n";

            cout << "Goi y:\n";

            for (int i = 0; i < 3 && i < size; i++) {

                cout << "- " << list[i].name << endl;
            }
        }

        cout << "\nDa so sanh ";
        cout << step << "/" << size;
        cout << " phan tu - ";

        cout << time.count();
        cout << " microseconds\n";
    }

    void sortByPhone() {

        for (int i = 0; i < size - 1; i++) {

            for (int j = i + 1; j < size; j++) {

                if (strcmp(list[i].phone,
                           list[j].phone) > 0) {

                    Contact temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    }

    void searchByPhone() {

        sortByPhone();

        char phone[20];

        cin.ignore();

        cout << "\nNhap SDT can tim: ";
        cin.getline(phone, 20);

        int left = 0;
        int right = size - 1;
        int step = 0;

        auto start = high_resolution_clock::now();

        while (left <= right) {

            step++;

            int mid = (left + right) / 2;

            int cmp = strcmp(list[mid].phone, phone);

            if (cmp == 0) {

                auto end = high_resolution_clock::now();

                auto time =
                    duration_cast<microseconds>(end - start);

                cout << "\nTim thay:\n";

                cout << list[mid].name << " - ";
                cout << list[mid].phone << endl;

                cout << "So buoc: " << step << endl;

                cout << "Thoi gian: ";
                cout << time.count();
                cout << " microseconds\n";

                return;
            }

            if (cmp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }

        cout << "Khong tim thay!\n";
    }
};

void bai4() {

    SmartSearchEngine engine;

    int choice;

    do {

        cout << "\n===== SMART SEARCH ENGINE =====\n";

        cout << "1. Tim theo ten\n";
        cout << "2. Tim theo SDT\n";
        cout << "0. Thoat\n";

        cout << "Chon: ";
        cin >> choice;

        switch (choice) {

        case 1:
            engine.searchByName();
            break;

        case 2:
            engine.searchByPhone();
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

        cout << "1. Bai 1 - Linear Search\n";
        cout << "2. Bai 2 - Binary Search\n";
        cout << "3. Bai 3 - So sanh hieu nang\n";
        cout << "4. Bai 4 - Smart Search Engine\n";
        cout << "0. Thoat\n";

        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {

        case 1:
            linearSearchNumber();
            linearSearchString();
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
