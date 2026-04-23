#include <iostream>
#include <fstream>

using namespace std;

// i) Hàm đọc tập tin data002.in
void DocFile(char tenfile[], int a[], int &n) {
    ifstream fileIn(tenfile);
    if (fileIn.is_open()) {
        fileIn >> n;
        for (int i = 0; i < n; i++) {
            fileIn >> a[i];
        }
        fileIn.close();
    } else {
        cout << "Khong the mo file data002.in!" << endl;
    }
}

// ii) Hàm xuất mảng
void XuatMang(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// iii) Tìm tuyến tính có tính số lần so sánh (ss)
int TimTuyenTinh(const int a[], int n, int x, long long &ss) {
    ss = 0;
    for (int i = 0; i < n; i++) {
        ss++; // So sánh i < n (hoặc có thể tính là so sánh a[i] == x)
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

// iv) Tìm nhị phân có tính số lần so sánh (ss)
int TNPTang(const int a[], int n, int x, long long &ss) {
    ss = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        ss++; // So sánh điều kiện vòng lặp hoặc so sánh giá trị
        int mid = left + (right - left) / 2;
        
        ss++; // So sánh a[mid] == x
        if (a[mid] == x) return mid;
        
        ss++; // So sánh a[mid] < x
        if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Hàm bổ trợ ghi file theo định dạng mới (3 thông số ở dòng 2)
void GhiFile(char tenfile[], const int a[], int n, int x, int vt, long long ss) {
    ofstream fileOut(tenfile);
    if (fileOut.is_open()) {
        // Dòng 1: ghi mảng a cách nhau dấu tab
        for (int i = 0; i < n; i++) {
            fileOut << a[i] << (i == n - 1 ? "" : "\t");
        }
        fileOut << endl;
        // Dòng 2: ghi x, vị trí, và số lần so sánh cách nhau dấu tab
        fileOut << x << "\t" << vt << "\t" << ss;
        fileOut.close();
    }
}

int main() {
    int a[1000];
    int n = 0, x, vt;
    long long ss; // Biến lưu số lần so sánh
    
    char fileDoc[] = "data002.in";
    char fileTT[] = "tt002.out";
    char fileNP[] = "npt002.out";

    // 1. Đọc file
    DocFile(fileDoc, a, n);
    if (n == 0) return 0;

    // 2. Xuất mảng
    cout << "Mang doc tu data002.in: " << endl;
    XuatMang(a, n);

    // 3. Tìm tuyến tính
    cout << "\n[Tim tuyen tinh] Nhap x: ";
    cin >> x;
    vt = TimTuyenTinh(a, n, x, ss);
    GhiFile(fileTT, a, n, x, vt, ss);
    cout << "Ket qua: vt = " << vt << ", so lan so sanh = " << ss << endl;

    // 4. Tìm nhị phân tăng
    cout << "\n[Tim nhi phan tang] Nhap x: ";
    cin >> x;
    vt = TNPTang(a, n, x, ss);
    GhiFile(fileNP, a, n, x, vt, ss);
    cout << "Ket qua: vt = " << vt << ", so lan so sanh = " << ss << endl;

    return 0;
}
