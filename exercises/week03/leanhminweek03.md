#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

// Cấu trúc dữ liệu cho Bài 4
struct DanhBa {
    string ten;
    string sdt;
};

// ==========================================
// BÀI 1: LINEAR SEARCH
// ==========================================
int LinearSearch(int a[], int n, int x, int& soBuoc) {
    soBuoc = 0;
    for (int i = 0; i < n; i++) {
        soBuoc++;
        if (a[i] == x) return i;
    }
    return -1;
}

// ==========================================
// BÀI 2: BINARY SEARCH (Tìm vị trí đầu/cuối)
// ==========================================
// Iterative (Vòng lặp) - Tìm vị trí đầu tiên
int BinarySearchFirst(int a[], int n, int x, int& soBuoc) {
    int l = 0, r = n - 1, res = -1;
    soBuoc = 0;
    while (l <= r) {
        soBuoc++;
        int m = l + (r - l) / 2;
        if (a[m] == x) {
            res = m;
            r = m - 1; // Tiếp tục tìm bên trái xem có phần tử trùng nào sớm hơn không
        }
        else if (a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return res;
}

// Recursive (Đệ quy) - Tìm vị trí cuối cùng
int BinarySearchLast(int a[], int l, int r, int x, int& soBuoc, int res = -1) {
    if (l > r) return res;
    soBuoc++;
    int m = l + (r - l) / 2;
    if (a[m] == x) {
        return BinarySearchLast(a, m + 1, r, x, soBuoc, m); // Tiếp tục tìm bên phải
    }
    if (a[m] > x) return BinarySearchLast(a, l, m - 1, x, soBuoc, res);
    return BinarySearchLast(a, m + 1, r, x, soBuoc, res);
}

// ==========================================
// BÀI 3: SO SÁNH HIỆU NĂNG
// ==========================================
void Bai3_SoSanhHieuNang() {
    cout << "\n=== BAI 3: SO SANH HIEU NANG ===\n";
    int sizes[] = { 10000, 100000, 1000000 };
    cout << "| Size        | Linear Search | Binary Search |\n";
    cout << "|-------------|---------------|---------------|\n";

    for (int n : sizes) {
        int* arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = i;

        int x = n - 1;
        int steps = 0;

        auto start = chrono::high_resolution_clock::now();
        LinearSearch(arr, n, x, steps);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> timeLinear = end - start;

        start = chrono::high_resolution_clock::now();
        BinarySearchFirst(arr, n, x, steps);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> timeBinary = end - start;

        cout << "| " << n << "\t| " << timeLinear.count() << " ms\t| " << timeBinary.count() << " ms\t|\n";
        delete[] arr;
    }
}

// ==========================================
// BÀI 4: SMART SEARCH ENGINE
// ==========================================
bool soSanhSDT(DanhBa a, DanhBa b) { return a.sdt < b.sdt; }

void Bai4_SmartSearch() {
    cout << "\n=== BAI 4: SMART SEARCH ENGINE ===\n";
    const int N = 5;
    DanhBa db[N] = {
        {"Nguyen Van Minh", "0901234567"},
        {"Tran Thi Minh Anh", "0912345678"},
        {"Le Minh Tuan", "0923456789"},
        {"Hoang Nguyen", "0934567890"},
        {"Pham Quoc Bao", "0945678901"}
    };

    int chon;
    cout << "1. Tim theo Ten (Linear Search - Tim kiem mo)\n";
    cout << "2. Tim theo SDT (Binary Search - Da sap xep)\n";
    cout << "Nhap lua chon: "; cin >> chon;
    cin.ignore();

    if (chon == 1) {
        string kw; cout << "Nhap ten can tim: "; getline(cin, kw);
        int soBuoc = 0, demKq = 0;
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < N; i++) {
            soBuoc++;
            if (db[i].ten.find(kw) != string::npos) {
                demKq++;
                cout << "   " << demKq << ". " << db[i].ten << " - " << db[i].sdt << "\n";
            }
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> time = end - start;

        if (demKq == 0) {
            cout << "-> Khong tim thay! Goi y 3 ten: \n";
            for (int i = 0; i < 3; i++) cout << "   " << db[i].ten << "\n";
        }
        else {
            cout << "   (Da so sanh " << soBuoc << "/" << N << " phan tu - " << time.count() << "ms)\n";
        }
    }
    else if (chon == 2) {
        sort(db, db + N, soSanhSDT);
        string sdtCanTim; cout << "Nhap SDT can tim: "; getline(cin, sdtCanTim);
        int l = 0, r = N - 1, vt = -1, soBuoc = 0;

        auto start = chrono::high_resolution_clock::now();
        while (l <= r) {
            soBuoc++;
            int m = (l + r) / 2;
            if (db[m].sdt == sdtCanTim) { vt = m; break; }
            else if (db[m].sdt > sdtCanTim) r = m - 1;
            else l = m + 1;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> time = end - start;

        if (vt != -1) {
            cout << "-> Tim thay: " << db[vt].ten << " - " << db[vt].sdt << "\n";
            cout << "   (Da so sanh " << soBuoc << "/" << N << " phan tu - " << time.count() << "ms)\n";
        }
        else {
            cout << "-> Khong tim thay so dien thoai nay!\n";
        }
    }
}

// ==========================================
// HÀM MAIN: ĐÃ SỬA ĐỂ TỰ NHẬP MẢNG
// ==========================================
int main() {
    int n, x;
    cout << "=== NHAP DU LIEU TEST BAI 1 & BAI 2 ===\n";
    cout << "Nhap so luong phan tu cua mang: "; cin >> n;

    if (n <= 0) {
        cout << "Mang khong hop le.\n";
        return 0;
    }

    int* mangNhap = new int[n];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu [" << i << "]: ";
        cin >> mangNhap[i];
    }

    cout << "Nhap gia tri can tim (x): "; cin >> x;

    // --- TEST BÀI 1 ---
    int soBuocLinear = 0;
    int vtLinear = LinearSearch(mangNhap, n, x, soBuocLinear);
    cout << "\n[Bai 1 - Linear Search]:\n";
    if (vtLinear != -1)
        cout << "-> Tim thay " << x << " tai vi tri: " << vtLinear << " (So buoc so sanh: " << soBuocLinear << ")\n";
    else
        cout << "-> Khong tim thay " << x << " trong mang (So buoc so sanh: " << soBuocLinear << ")\n";


    // --- TEST BÀI 2 ---
    // Vì Binary Search bắt buộc mảng phải tăng dần, ta tiến hành sắp xếp lại mảng vừa nhập
    sort(mangNhap, mangNhap + n);
    cout << "\n[Yeu cau Bai 2] Da tu dong sap xep lai mang tang dan de chay Binary Search: [ ";
    for (int i = 0; i < n; i++) cout << mangNhap[i] << " ";
    cout << "]\n";

    int soBuocFirst = 0, soBuocLast = 0;
    int vtDau = BinarySearchFirst(mangNhap, n, x, soBuocFirst);
    int vtCuoi = BinarySearchLast(mangNhap, 0, n - 1, x, soBuocLast);

    cout << "[Bai 2 - Binary Search]:\n";
    if (vtDau != -1) {
        cout << "-> Vi tri dau tien cua " << x << " (Vong lap): " << vtDau << " (So buoc: " << soBuocFirst << ")\n";
        cout << "-> Vi tri cuoi cung cua " << x << " (De quy) : " << vtCuoi << " (So buoc: " << soBuocLast << ")\n";
    }
    else {
        cout << "-> Khong tim thay " << x << " bang Binary Search.\n";
    }

    // Giải phóng bộ nhớ mảng động vừa nhập
    delete[] mangNhap;

    // Chạy tiếp bài 3 và bài 4 như cũ
    Bai3_SoSanhHieuNang();
    Bai4_SmartSearch();

    return 0;
}
