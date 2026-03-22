// ============================================================
//  Chuong1_TongQuan.cpp
//  Noi dung: Kieu du lieu, CTDL, Giai thuat va BigO
//  Giao trinh: Cau truc du lieu & Giai thuat - CDCTTP.HCM
// ============================================================
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ============================================================
//  BAI 1: Kieu du lieu - Tinh tong chu so cua n
// ============================================================
/*
 * Bai toan: Cho so nguyen n trong [1, 10^9].
 * Tinh tong cac chu so cua n.
 * Vi du: n=12345 -> s = 1+2+3+4+5 = 15
 * Kieu du lieu chon: n -> unsigned int (4 byte)
 *                    s -> unsigned short (2 byte, du lon)
 * Do phuc tap: O(log10(n))
 */
unsigned short TinhTongChuSo(unsigned int n) {
    unsigned short s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

// ============================================================
//  BAI 2: Minh hoa CTDL - Bang diem Sinh Vien
// ============================================================
#define SOMH 3
#define MAX_SV 100

struct SinhVien {
    int masv;
    char hoten[51];
    bool gtinh;     // true = Nam, false = Nu
    char lop[9];
    float dtb;
};

// Phương án 02: Mảng 2 chiều (giao trinh de xuat)
void XuatBangDiem_2D(float a[][SOMH], int m) {
    cout << "\n--- Bang diem (2D array) ---\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < SOMH; j++)
            cout << "  Sinh vien " << i+1
                 << " hoc mon " << j+1
                 << " diem: " << a[i][j] << "\n";
}

int TimMH_SVK_2D(float a[][SOMH], int n, int k) {
    int mh = 0;
    for (int i = 1; i < n; i++)
        if (a[k-1][mh] < a[k-1][i])
            mh = i;
    return mh + 1;
}

// ============================================================
//  BAI 3: Do phuc tap BigO - Dem vong lap
// ============================================================
/*
 * Cac phan lop do phuc tap:
 *  O(K)       - hang so
 *  O(log N)   - logarit
 *  O(N)       - tuyen tinh
 *  O(N log N) - n-log-n
 *  O(N^2)     - binh phuong
 *  O(N^3)     - lap phuong
 *  O(2^N)     - mu
 */
void MinhHoaBigO() {
    int N = 8;
    long long dem = 0;

    cout << "\n--- O(N): dem vong lap don ---\n";
    dem = 0;
    for (int i = 0; i < N; i++) dem++;
    cout << "  N=" << N << ", so buoc: " << dem << "\n";

    cout << "--- O(N^2): dem 2 vong long ---\n";
    dem = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) dem++;
    cout << "  N=" << N << ", so buoc: " << dem << "\n";

    cout << "--- O(log2 N): dem chia doi ---\n";
    dem = 0;
    for (int i = 1; i < N; i *= 2) dem++;
    cout << "  N=" << N << ", so buoc: " << dem << "\n";

    cout << "--- O(N^3): dem 3 vong long ---\n";
    dem = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) dem++;
    cout << "  N=" << N << ", so buoc: " << dem << "\n";
}

// ============================================================
//  BAI 4: Phuong trinh bac nhat (O(K))
// ============================================================
void GiaiPhuongTrinhBacNhat() {
    int a, b;
    cout << "\n--- Giai phuong trinh bac nhat: ax + b = 0 ---\n";
    cout << "  Nhap a: "; cin >> a;
    cout << "  Nhap b: "; cin >> b;
    if (a == 0) {
        if (b == 0) cout << "  => Phuong trinh vo so nghiem\n";
        else        cout << "  => Phuong trinh vo nghiem\n";
    } else {
        cout << "  => x = " << (double)-b/a << "\n";
    }
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "============================================================\n";
    cout << "  CHUONG 1: TONG QUAN VE CTDL VA GIAI THUAT\n";
    cout << "============================================================\n";

    // Bai 1
    cout << "\n[BAI 1] Tinh tong chu so\n";
    unsigned int n = 12345;
    cout << "  n = " << n << "  =>  Tong chu so = " << TinhTongChuSo(n) << "\n";
    n = 987654321;
    cout << "  n = " << n << "  =>  Tong chu so = " << TinhTongChuSo(n) << "\n";

    // Bai 2
    cout << "\n[BAI 2] Bang diem sinh vien (CTDL mang 2 chieu)\n";
    float bangDiem[4][SOMH] = {
        {6, 6.5, 9},
        {7, 8,   5},
        {8, 4.5, 8},
        {5, 4,   7}
    };
    XuatBangDiem_2D(bangDiem, 4);
    int k = 2;
    cout << "\n  Mon hoc diem cao nhat cua SV thu " << k
         << " la mon: " << TimMH_SVK_2D(bangDiem, SOMH, k) << "\n";

    // Bai 3
    cout << "\n[BAI 3] Minh hoa cac phan lop BigO\n";
    MinhHoaBigO();

    // Bai 4
    cout << "\n[BAI 4] Phuong trinh bac nhat (O(K))\n";
    GiaiPhuongTrinhBacNhat();

    cout << "\n============================================================\n";
    return 0;
}
