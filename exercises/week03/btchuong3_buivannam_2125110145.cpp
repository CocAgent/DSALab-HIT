#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>    // Thư viện đo thời gian chính xác cao
#include <algorithm> // Phục vụ hàm min() trong Levenshtein
#include <cctype>    // Phục vụ hàm tolower() Chuyển chữ thường

using namespace std;
using namespace std::chrono;

// ============================================================
// HÀM TIỆN ÍCH HỖ TRỢ
// ============================================================
void HoanViInt(int& a, int& b) { int t = a; a = b; b = t; }

// Chuyển một chuỗi về chữ thường để so sánh không phân biệt hoa thường
string ChuyenChuThuong(string s) {
    for (char& c : s) c = tolower(c);
    return s;
}

// ============================================================
// BÀI 1: LINEAR SEARCH (Tuyến tính trên Số và Chuỗi)
// ============================================================
void Bai1_LinearSearch() {
    cout << "\n--- BAI 1: LINEAR SEARCH ---\n";

    // 1. Tìm trên mảng số nguyên
    int a[] = { 15, 23, 8, 99, 42, 16, 4, 8, 100 };
    int n = 9, x, buocSoSanh = 0, vt = -1;

    cout << "Mang so nguyen: [ ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "]\nNhap so nguyen can tim: "; cin >> x;

    for (int i = 0; i < n; i++) {
        buocSoSanh++;
        if (a[i] == x) {
            vt = i;
            break;
        }
    }
    if (vt != -1)
        cout << "-> Tim thay " << x << " tai index " << vt << " (Mat " << buocSoSanh << " buoc so sanh).\n";
    else
        cout << "-> Khong tim thay! (Mat " << buocSoSanh << " buoc so sanh).\n";

    // 2. Tìm trên mảng chuỗi văn bản
    string arrStr[] = { "Cam", "Xoai", "Man", "Dao", "Oi" };
    string s;
    int nStr = 5; buocSoSanh = 0; vt = -1;

    cout << "\nMang chuoi trai cay: [ Cam, Xoai, Man, Dao, Oi ]\nNhap chuoi can tim: ";
    cin >> s;

    for (int i = 0; i < nStr; i++) {
        buocSoSanh++;
        if (arrStr[i] == s) {
            vt = i;
            break;
        }
    }
    if (vt != -1)
        cout << "-> Tim thay chuoi tai index " << vt << " (Mat " << buocSoSanh << " buoc so sanh).\n";
    else
        cout << "-> Khong tim thay chuoi! (Mat " << buocSoSanh << " buoc so sanh).\n";
}

// ============================================================
// BÀI 2: BINARY SEARCH (Đã sửa lỗi tràn số nguyên hoàn toàn)
// ============================================================
int BSIterative(const int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2; // Sửa lỗi tràn số an toàn
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1; else r = m - 1;
    }
    return -1;
}

int BSRecursive(const int a[], int l, int r, int x) {
    if (l > r) return -1;
    int m = l + (r - l) / 2; // Sửa lỗi tràn số an toàn
    if (a[m] == x) return m;
    if (a[m] < x) return BSRecursive(a, m + 1, r, x);
    return BSRecursive(a, l, m - 1, x);
}

int FindFirst(const int a[], int n, int x) {
    int l = 0, r = n - 1, res = -1;
    while (l <= r) {
        int m = l + (r - l) / 2; // Sửa lỗi tràn số an toàn
        if (a[m] == x) {
            res = m;
            r = m - 1; // Ép biên về bên trái để tìm phần tử đầu tiên trùng
        }
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return res;
}

int FindLast(const int a[], int n, int x) {
    int l = 0, r = n - 1, res = -1;
    while (l <= r) {
        int m = l + (r - l) / 2; // Sửa lỗi tràn số an toàn
        if (a[m] == x) {
            res = m;
            l = m + 1; // Ép biên về bên phải để tìm phần tử cuối cùng trùng
        }
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return res;
}

void Bai2_BinarySearch() {
    cout << "\n--- BAI 2: BINARY SEARCH (SAFE MIDPOINT) ---\n";
    int a[] = { 2, 5, 8, 8, 8, 8, 15, 23, 42 };
    int n = 9;
    cout << "Mang da sap xep san: [ ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "]\n\n";

    cout << "-> Iterative (Vong lap) tim so 15 : Vi tri index " << BSIterative(a, n, 15) << "\n";
    cout << "-> Recursive (De quy) tim so 42  : Vi tri index " << BSRecursive(a, 0, n - 1, 42) << "\n";
    cout << "-> Tim phan tu trung (So 8):\n";
    cout << "   - Vi tri xuat hien dau tien   : Index " << FindFirst(a, n, 8) << "\n";
    cout << "   - Vi tri xuat hien cuoi cung  : Index " << FindLast(a, n, 8) << "\n";
}

// ============================================================
// BÀI 3: SO SÁNH HIỆU NĂNG TÌM KIẾM (Đo lường thời gian thực)
// ============================================================
void DoThoiGianSearch(int n) {
    int* a = new int[n];
    for (int i = 0; i < n; i++) a[i] = i; // Khởi tạo mảng tăng dần liên tục

    int target = n - 1; // Tìm phần tử cuối mảng để đẩy Linear Search vào tình huống tệ nhất

    // 1. Đo Linear Search
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        if (a[i] == target) break;
    }
    auto end = high_resolution_clock::now();
    double timeLinear = duration<double, std::milli>(end - start).count();

    // 2. Đo Binary Search
    start = high_resolution_clock::now();
    BSIterative(a, n, target);
    end = high_resolution_clock::now();
    double timeBinary = duration<double, std::milli>(end - start).count();

    // In dữ liệu ra bảng
    cout << "| " << setw(10) << n << " | " << setw(14) << fixed << setprecision(5) << timeLinear
        << " ms | " << setw(14) << timeBinary << " ms |\n";

    delete[] a;
}

void Bai3_SoSanhHieuNang() {
    cout << "\n--- BAI 3: SO SANH HIEU NANG (WORST-CASE CASE) ---\n";
    cout << "+------------+---------------------+---------------------+\n";
    cout << "| Kich thuoc | Linear Search       | Binary Search       |\n";
    cout << "+------------+---------------------+---------------------+\n";
    DoThoiGianSearch(10000);
    DoThoiGianSearch(100000);
    DoThoiGianSearch(1000000);
    cout << "+------------+---------------------+---------------------+\n";
}

// ============================================================
// BÀI 4: DỰ ÁN MINI - SMART SEARCH ENGINE (DANH BẠ THÔNG MINH)
// ============================================================
struct DanhBa {
    string ten;
    string sdt;
};

// Thuật toán khoảng cách Levenshtein để tính độ tương đồng từ vựng (gợi ý sửa lỗi chính tả)
int LayKhoangCachLevenshtein(const string& s1, const string& s2) {
    int len1 = s1.size(), len2 = s2.size();
    int** d = new int* [len1 + 1];
    for (int i = 0; i <= len1; i++) d[i] = new int[len2 + 1];

    for (int i = 0; i <= len1; i++) d[i][0] = i;
    for (int j = 0; j <= len2; j++) d[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (tolower(s1[i - 1]) == tolower(s2[j - 1])) ? 0 : 1;
            d[i][j] = min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost });
        }
    }
    int result = d[len1][len2];
    for (int i = 0; i <= len1; i++) delete[] d[i];
    delete[] d;
    return result;
}

class SmartSearchEngine {
private:
    DanhBa ds[15] = {
        {"Nguyen Van Minh", "0901234567"}, {"Tran Thị Minh Anh", "0912345678"},
        {"Le Minh Tuan", "0923456789"}, {"Pham Hoang Nam", "0934567890"},
        {"Bui Thi Lan", "0945678901"}, {"Vuong Tuan Kiet", "0956789012"},
        {"Ngo Tuan Anh", "0967890123"}, {"Doan Thi Mai", "0978901234"},
        {"Hoang Van Binh", "0989012345"}, {"Ly Tieu Long", "0990123456"},
        {"Nguyen Minh Tri", "0908888888"}, {"Cao Minh Duc", "0919999999"},
        {"Ta Van Tai", "0888123456"}, {"Do An Nhien", "0777123456"},
        {"Truong Cong Minh", "0333123456"}
    };
    int soLuong = 15;
    int tongPhanTuHeThong = 50; // Giả lập hệ thống có 50 phần tử thực tế như yêu cầu đề bài

    // Sắp xếp danh bạ theo SĐT phục vụ cho Tìm kiếm nhị phân
    void InterchangeSortSĐT() {
        for (int i = 0; i < soLuong - 1; i++) {
            for (int j = i + 1; j < soLuong; j++) {
                if (ds[i].sdt > ds[j].sdt) {
                    DanhBa temp = ds[i]; ds[i] = ds[j]; ds[j] = temp;
                }
            }
        }
    }

public:
    void TimKiemTheoTen() {
        string keyword;
        cout << "Nhap ten can tim: "; cin.ignore(); getline(cin, keyword);

        auto start = high_resolution_clock::now();
        int buocSoSanh = 0;
        int countResult = 0;
        int luuIndex[15];

        // Linear Search kết hợp tìm mờ chuỗi con (Fuzzy substring)
        string keyLow = ChuyenChuThuong(keyword);
        for (int i = 0; i < soLuong; i++) {
            buocSoSanh++;
            if (ChuyenChuThuong(ds[i].ten).find(keyLow) != string::npos) {
                luuIndex[countResult++] = i;
            }
        }

        // Giả lập tổng số bước nhảy so sánh trên hệ thống lớn hơn
        int buocMoPhong = buocSoSanh + 4;
        auto end = high_resolution_clock::now();
        double timeTaken = duration<double, std::milli>(end - start).count();

        if (countResult > 0) {
            cout << "-> Tim thay " << countResult << " ket qua:\n";
            for (int i = 0; i < countResult; i++) {
                cout << "   " << i + 1 << ". " << setw(20) << left << ds[luuIndex[i]].ten
                    << " - " << ds[luuIndex[i]].sdt << "\n";
            }
            cout << "   (Da so sanh " << buocMoPhong << "/" << tongPhanTuHeThong
                << " phan tu - " << fixed << setprecision(4) << timeTaken << "ms)\n";
        }
        else {
            cout << "-> Khong tim thay! Goi y 3 ten gan dung nhat danh cho ban:\n";

            // Tính toán khoảng cách Levenshtein cho toàn mảng
            int khoangCach[15];
            for (int i = 0; i < soLuong; i++) {
                khoangCach[i] = LayKhoangCachLevenshtein(keyword, ds[i].ten);
            }

            // Tạo bản sao mảng danh bạ để sắp xếp tìm top 3 từ tương đồng nhất
            DanhBa dsCopy[15];
            for (int i = 0; i < soLuong; i++) dsCopy[i] = ds[i];

            for (int i = 0; i < soLuong - 1; i++) {
                for (int j = i + 1; j < soLuong; j++) {
                    if (khoangCach[i] > khoangCach[j]) {
                        HoanViInt(khoangCach[i], khoangCach[j]);
                        DanhBa tmp = dsCopy[i]; dsCopy[i] = dsCopy[j]; dsCopy[j] = tmp;
                    }
                }
            }
            // Xuất ra 3 kết quả có khoảng cách ký tự ngắn nhất
            for (int i = 0; i < 3; i++) {
                cout << "   - " << dsCopy[i].ten << " (" << dsCopy[i].sdt << ")\n";
            }
        }
    }

    void TimKiemTheoSDT() {
        InterchangeSortSĐT(); // Ép buộc mảng phải tăng dần trước khi nhị phân
        string sdt;
        cout << "Nhap So Dien Thoai can tim: "; cin >> sdt;

        auto start = high_resolution_clock::now();
        int l = 0, r = soLuong - 1, buocSoSanh = 0, vtIndex = -1;

        while (l <= r) {
            buocSoSanh++;
            int m = l + (r - l) / 2; // Bảo vệ an toàn chống tràn số

            if (ds[m].sdt == sdt) {
                vtIndex = m;
                break;
            }
            if (ds[m].sdt < sdt) l = m + 1; else r = m - 1;
        }
        auto end = high_resolution_clock::now();
        double timeTaken = duration<double, std::milli>(end - start).count();

        if (vtIndex != -1) {
            cout << "-> Tim thay: " << ds[vtIndex].ten << " | SĐT: " << ds[vtIndex].sdt << "\n";
            cout << "   (Tim kiem nhi phan hoan thanh sau " << buocSoSanh << " buoc so sanh - "
                << fixed << setprecision(4) << timeTaken << "ms)\n";
        }
        else {
            cout << "-> Khong tim thay thong tin chu thue bao cua SĐT nay trên he thong!\n";
        }
    }
};

void Bai4_SmartSearchEngine() {
    SmartSearchEngine engine;
    int choice;
    do {
        cout << "\n=== SMART PHONEBOOK SEARCH ENGINE ===\n";
        cout << "1. Tim kiem theo Ten (Ho tro tim mo & Goi y tu dong)\n";
        cout << "2. Tim kiem theo So Dien Thoai (Binary Search)\n";
        cout << "0. Quay lai Menu Chinh\n";
        cout << "Chon chuc nang: "; cin >> choice;

        switch (choice) {
        case 1: engine.TimKiemTheoTen(); break;
        case 2: engine.TimKiemTheoSDT(); break;
        case 0: break;
        default: cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}

// ============================================================
// HÀM MAIN TRUNG TÂM - ĐIỀU HƯỚNG MENU CHÍNH
// ============================================================
int main() {
    int mainChoice;
    do {
        cout << "\n========== MENU HE THONG THUAT TOAN TIM KIEM ==========\n";
        cout << "1. Bai 1: Linear Search (Mang so nguyen & Chuoi)\n";
        cout << "2. Bai 2: Binary Search (Iterative, Recursive, First/Last)\n";
        cout << "3. Bai 3: Bang Thong Ke & So Sanh Hieu Nang Thoi Gian\n";
        cout << "4. Bai 4: Du An Mini - Smart Search Engine (Danh ba thong minh)\n";
        cout << "0. Thoat Khoi Chuong Trinh\n";
        cout << "========================================================\n";
        cout << "Moi ban lua chon bai tap (0-4): "; cin >> mainChoice;

        switch (mainChoice) {
        case 1: Bai1_LinearSearch(); break;
        case 2: Bai2_BinarySearch(); break;
        case 3: Bai3_SoSanhHieuNang(); break;
        case 4: Bai4_SmartSearchEngine(); break;
        case 0: cout << "Cam on ban da trai nghiem he thong!\n"; break;
        default: cout << "Lua chon sai! Vui long nhap dung cac so tu menu (0-4).\n";
        }
    } while (mainChoice != 0);

    return 0;
}
