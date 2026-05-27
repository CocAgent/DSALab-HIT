#include <iostream>
using namespace std;

void bai1() 
{
    cout << "\n--- BAI 1 ---\n";
    int n;
    do {
        cout << "Nhap so phan tu cua mang n (n > 0) = ";
        cin >> n;
        if (n <= 0) {
            cout << "Loi: So phan tu phai lon hon 0. Vui long nhap lai!\n\n";
        }
    } while (n <= 0);

    int a[100];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int Tong = 0;
    int NhoNhat = a[0];
    int LonNhat = a[0];

    for (int i = 0; i < n; i++) 
    {
        Tong += a[i];
        if (a[i] < NhoNhat) NhoNhat = a[i];
        if (a[i] > LonNhat) LonNhat = a[i];
    }

    float avg = (float)Tong / n;

    cout << "\n--- KET QUA BAI 1 ---\n";
    cout << "Tong: " << Tong << "\n";
    cout << "Trung binh: " << avg << "\n";
    cout << "Min: " << NhoNhat << "\n";
    cout << "Max: " << LonNhat << "\n";
    cout << "---------------------------\n";
}

void bai2() 
{
    cout << "\n--- BAI 2 ---\n";

    // --- Phần 1: Nhân ma trận ---
    int n;
    cout << "Nhap kich thuoc ma tran n = ";
    cin >> n;

    int A[50][50], B[50][50], C[50][50];

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nNhap ma tran B:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) 
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    cout << "\nNhan hai ma tran A va B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << C[i][j] << "\t";
        cout << "\n";
    }

    // --- Phần 2: Định thức 3x3 ---
    cout << "\n--- TINH DINH THUC MA TRAN 3x3 ---\n";
    int M[3][3];
    cout << "Nhap ma tran 3x3:\n";
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << "M[" << i << "][" << j << "] = ";
            cin >> M[i][j];
        }
    }

    int det = M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])
        - M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0])
        + M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);

    cout << "\nDinh thuc cua ma tran la: " << det << "\n";
    cout << "---------------------------\n";
}

int main() {
    int lua_chon;

    while (true) 
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Bai 1: Mang co ban\n";
        cout << "2. Bai 2: Mang 2D\n";
        cout << "0. Thoat\n";
        cout << "==========================\n";
        cout << "Nhap lua chon cua ban (0, 1 hoac 2): ";
        cin >> lua_chon;

        switch (lua_chon) 
        {
            case 1:
                bai1();
                break;
            case 2:
                bai2();
                break;
            case 0:
                cout << "Chuong trinh ket thuc.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le! Vui long nhap lai.\n";
                break;
        }
    }

    return 0;
}
