#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// i) Hàm đọc tập tin
void DocFile(char tenfile[], int a[], int &n) {
    ifstream fileIn(tenfile);
    if (fileIn.is_open()) {
        fileIn >> n; // Dòng 1 chứa n
        for (int i = 0; i < n; i++) {
            fileIn >> a[i]; // Dòng 2 chứa mảng
        }
        fileIn.close();
    } else {
        cout << "Khong the mo file doc!" << endl;
    }
}

// ii) Hàm xuất mảng ra màn hình
void XuatMang(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// iii) Tìm tuyến tính
int TimTuyenTinh(const int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return i;
    }
    return -1;
}

// iv) Tìm nhị phân
int TNPTang(const int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Hàm bổ trợ để ghi file theo định dạng yêu cầu
void GhiFile(char tenfile[], const int a[], int n, int x, int vt) {
    ofstream fileOut(tenfile);
    if (fileOut.is_open()) {
        // Dòng 1: ghi mảng a cách nhau dấu tab
        for (int i = 0; i < n; i++) {
            fileOut << a[i] << (i == n - 1 ? "" : "\t");
        }
        fileOut << endl;
        // Dòng 2: ghi x và vị trí cách nhau dấu tab
        fileOut << x << "\t" << vt;
        fileOut.close();
    }
}

int main() {
    int a[1000]; // Khai báo mảng tối đa 1000 phần tử
    int n = 0, x, vt;
    char fileDoc[] = "data001.in";
    char fileTT[] = "tt001.out";
    char fileNP[] = "npt001.out";

    // 1. Đọc file
    DocFile(fileDoc, a, n);

    // 2. Xuất mảng xem kết quả
    cout << "Mang da doc tu file: " << endl;
    XuatMang(a, n);

    // 3. Tìm tuyến tính
    cout << "\nNhap x can tim (Tuyen tinh): ";
    cin >> x;
    vt = TimTuyenTinh(a, n, x);
    GhiFile(fileTT, a, n, x, vt);
    cout << "Da ghi ket qua vao " << fileTT << " (vt = " << vt << ")" << endl;

    // 4. Tìm nhị phân
    cout << "\nNhap x can tim (Nhi phan): ";
    cin >> x;
    vt = TNPTang(a, n, x);
    GhiFile(fileNP, a, n, x, vt);
    cout << "Da ghi ket qua vao " << fileNP << " (vt = " << vt << ")" << endl;

    return 0;
}
