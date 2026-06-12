#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

// ================= TIEN ICH =================
void HoanVi(int& a, int& b) {
    int t = a; a = b; b = t;
}

void XuatMang(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

void SaoChepMang(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) b[i] = a[i];
}

// ================ RANDOM ====================
void SinhMangNgauNhien(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
}

// ============== STEP SORT ===================
void BubbleSortDemo(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << "Buoc " << i + 1 << ": ";
        XuatMang(a, n);

        for (int j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
                HoanVi(a[j], a[j - 1]);
    }
    cout << "Ket qua: ";
    XuatMang(a, n);
}

// ============== QUICK SORT ==================
void QuickSort(int a[], int l, int r) {
    int i = l, j = r;
    int x = a[(l + r) / 2];

    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            HoanVi(a[i], a[j]);
            i++; j--;
        }
    }
    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}

// ============ TIM KIEM DEMO =================
int TimTuyenTinhDemo(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        cout << "So sanh " << a[i] << " voi " << x << endl;
        if (a[i] == x) return i;
    }
    return -1;
}

// ============ DO THOI GIAN ==================
void SoSanhThoiGian(int a[], int n) {
    int b[10000], c[10000];
    SaoChepMang(a, b, n);
    SaoChepMang(a, c, n);

    // Bubble
    clock_t t1 = clock();
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (b[j] < b[j - 1])
                HoanVi(b[j], b[j - 1]);
    clock_t t2 = clock();

    // Quick
    clock_t t3 = clock();
    QuickSort(c, 0, n - 1);
    clock_t t4 = clock();

    cout << "Bubble Sort: "
        << (double)(t2 - t1) / CLOCKS_PER_SEC << " s\n";
    cout << "Quick Sort : "
        << (double)(t4 - t3) / CLOCKS_PER_SEC << " s\n";
}

// ================== MENU ====================
void Menu() {
    cout << "\n========= MENU =========\n";
    cout << "1. Sinh mang ngau nhien\n";
    cout << "2. Bubble Sort (Step-by-step)\n";
    cout << "3. Quick Sort\n";
    cout << "4. Tim kiem tuyen tinh\n";
    cout << "5. So sanh thoi gian\n";
    cout << "0. Thoat\n";
    cout << "========================\n";
}

// ================== MAIN ====================
int main() {
    srand(time(0));

    int a[10000], n = 0;
    int choice;

    do {
        Menu();
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap so phan tu: ";
            cin >> n;
            SinhMangNgauNhien(a, n);
            cout << "Mang vua tao:\n";
            XuatMang(a, n);
            break;

        case 2: {
            int b[10000];
            SaoChepMang(a, b, n);
            BubbleSortDemo(b, n);
            break;
        }

        case 3: {
            int b[10000];
            SaoChepMang(a, b, n);

            clock_t start = clock();
            QuickSort(b, 0, n - 1);
            clock_t end = clock();

            cout << "Mang sau Quick Sort:\n";
            XuatMang(b, n);

            cout << "Thoi gian: "
                << (double)(end - start) / CLOCKS_PER_SEC
                << " s\n";
            break;
        }

        case 4: {
            int x;
            cout << "Nhap gia tri can tim: ";
            cin >> x;
            int vt = TimTuyenTinhDemo(a, n, x);
            if (vt == -1)
                cout << "Khong tim thay\n";
            else
                cout << "Tim thay tai vi tri " << vt << endl;
            break;
        }

        case 5:
            SoSanhThoiGian(a, n);
            break;

        case 0:
            cout << "Thoat...\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}