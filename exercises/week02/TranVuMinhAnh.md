#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;
void xuLyMangMotChieu() {
    int n;
    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong phan tu khong hop le!" << endl;
        return;
    }
    int* arr = new int[n];

    cout << "Nhap " << n << " phan tu:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    int min_val = arr[0];
    int max_val = arr[0];
    long long tong = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        tong += arr[i];
    }
    double trung_binh = (double)tong / n;

    cout << "\n--- KET QUA MANG 1 CHIEU ---" << endl;
    cout << "Gia tri lon nhat (Max): " << max_val << endl;
    cout << "Gia tri nho nhat (Min): " << min_val << endl;
    cout << "Tong cac phan tu: " << tong << endl;
    cout << "Trung binh cong: " << trung_binh << endl;

    
    delete[] arr;
}
void nhapMaTran(vector<vector<int>>& mat, int n, string ten) {
    cout << "Nhap cac phan tu cua ma tran " << ten << " (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ten << "[" << i << "][" << j << "] = ";
            cin >> mat[i][j];
        }
    }
}
void inMaTran(const vector<vector<int>>& mat, int n) {
    for (int i = 0; i < n; i++) {
        cout << "  [ ";
        for (int j = 0; j < n; j++) {
            cout << setw(6) << mat[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << endl;
}
vector<vector<int>> nhanMaTran(const vector<vector<int>>& A, const vector<vector<int>>& B, int n) {
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
int tinhDinhThuc3x3(const vector<vector<int>>& mat) {
    int a = mat[0][0], b = mat[0][1], c = mat[0][2];
    int d = mat[1][0], e = mat[1][1], f = mat[1][2];
    int g = mat[2][0], h = mat[2][1], i = mat[2][2];
    return (a * e * i + b * f * g + c * d * h) - (c * e * g + a * f * h + b * d * i);
}
int main() {
    int luaChon;
    cout << "==================== MENU CHINH ====================\n";
    cout << "1. Bai 1: Thao tac voi Mang 1 chieu (Tim Min, Max, Tong, TB)\n";
    cout << "2. Bai 2: Thao tac voi Ma tran (Nhan / Tinh Dinh Thuc)\n";
    cout << "Lua chon cua ban (1-2): ";
    cin >> luaChon;
    cout << "----------------------------------------------------\n";

    if (luaChon == 1) {
       
        xuLyMangMotChieu();
    }
    else if (luaChon == 2) {
        
        int luaChonMaTran;
        cout << "=== MENU MA TRAN ===\n";
        cout << "1. Nhan hai ma tran n x n\n";
        cout << "2. Tinh dinh thuc ma tran 3 x 3\n";
        cout << "Lua chon cua ban (1-2): ";
        cin >> luaChonMaTran;
        cout << "----------------------------------------------\n";

        if (luaChonMaTran == 1) {
            int n;
            cout << "Nhap kich thuoc n cua ma tran: ";
            cin >> n;

            vector<vector<int>> A(n, vector<int>(n));
            vector<vector<int>> B(n, vector<int>(n));

            nhapMaTran(A, n, "A");
            nhapMaTran(B, n, "B");

            cout << "\n--- Ma tran A ---\n";
            inMaTran(A, n);

            cout << "--- Ma tran B ---\n";
            inMaTran(B, n);

            vector<vector<int>> C = nhanMaTran(A, B, n);
            cout << "--- Ma tran Ket qua (A * B) ---\n";
            inMaTran(C, n);

        }
        else if (luaChonMaTran == 2) {
            int n = 3;
            vector<vector<int>> M(n, vector<int>(n));

            nhapMaTran(M, n, "M");

            cout << "\n--- Ma tran M (3x3) ---\n";
            inMaTran(M, n);

            int det = tinhDinhThuc3x3(M);
            cout << ">>> Dinh thuc (Determinant) cua ma tran M la: " << det << endl;
        }
        else {
            cout << "Lua chon ma tran khong hop le!\n";
        }
    }
    else {
        cout << "Lua chon menu chinh khong hop le!\n";
    }

    return 0;
}
