Con trỏ dùng để:
Lưu địa chỉ
Sửa dữ liệu trực tiếp
Quản lý bộ nhớ động
Con trỏ là nền tảng của DSLK
CTDL (mảng, DSLK…) ảnh hưởng mạnh đến giải thuật


#include <iostream>
#include <string>

using namespace std;

// 1. Kiểm tra bộ nhớ (Ứng dụng con trỏ kiểm tra địa chỉ liên tiếp của mảng)
void kiemTraDiaChiMang() {
    double diem[] = {8.5, 9.0, 7.5};
    double* ptr = diem;

    cout << "--- Phan tich o nho cua kieu Double (8 bytes) ---" << endl;
    for (int i = 0; i < 3; i++) {
        // (ptr + i) se nhay 8 bytes moi lan tang i
        cout << "Diem[" << i << "] tai dia chi: " << (ptr + i) 
             << " | Gia tri: " << *(ptr + i) << endl;
    }
}

// 2. Ham dung con tro de tim gia tri nho nhat (Thay vi Swap)
void timMin(int* arr, int n, int* minVal) {
    *minVal = *arr; // Gan gia tri dau tien la Min
    for (int i = 1; i < n; i++) {
        if (*(arr + i) < *minVal) {
            *minVal = *(arr + i);
        }
    }
}

// 3. Cap phat dong mang 2 chieu (Con tro cap 2)
// Dung de luu mot danh sach cac chuoi ky tu
void quanLyDanhSachTen() {
    int soLuong;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong;
    cin.ignore(); // Xoa bo nho dem

    // Con tro cap 2: Mang cac con tro kieu string
    string** dsTen = new string*[soLuong];

    for (int i = 0; i < soLuong; i++) {
        dsTen[i] = new string; // Cap phat cho tung cai ten
        cout << "Nhap ten sinh vien thu " << i + 1 << ": ";
        getline(cin, *dsTen[i]);
    }

    cout << "\nDanh sach vua nhap:\n";
    for (int i = 0; i < soLuong; i++) {
        cout << i + 1 << ". " << *dsTen[i] << " (Luu tai: " << dsTen[i] << ")" << endl;
    }

    // Giai phong bo nho cap 2
    for (int i = 0; i < soLuong; i++) {
        delete dsTen[i];
    }
    delete[] dsTen;
    cout << "Da giai phong bo nho danh sach.\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== HE THONG QUAN LY (POINTER ADVANCED) =====\n";
        cout << "1. Phan tich dia chi o nho (Array Pointer)\n";
        cout << "2. Tim gia tri nho nhat (Pass by Pointer)\n";
        cout << "3. Quan ly danh sach ten (Double Pointer)\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                kiemTraDiaChiMang();
                break;
            case 2: {
                int n = 4;
                int thuTu[] = {10, 2, 85, 4};
                int minResult;
                timMin(thuTu, n, &minResult);
                cout << "So nho nhat trong mang {10, 2, 85, 4} la: " << minResult << endl;
                break;
            }
            case 3:
                quanLyDanhSachTen();
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}


===== HE THONG QUAN LY (POINTER ADVANCED) =====

Phan tich dia chi o nho (Array Pointer)

Tim gia tri nho nhat (Pass by Pointer)

Quan ly danh sach ten (Double Pointer)

Thoat
Chon chuc nang: 1
--- Phan tich dia chi o nho cua kieu Double (8 bytes) ---
Diem[0] tai dia chi: 0x61ff00 | Gia tri: 8.5
Diem[1] tai dia chi: 0x61ff08 | Gia tri: 9
Diem[2] tai dia chi: 0x61ff10 | Gia tri: 7.5
(Lưu ý: Địa chỉ 0x... sẽ thay đổi tùy theo máy tính của bạn, nhưng chúng luôn cách nhau đúng 8 đơn vị)

===== HE THONG QUAN LY (POINTER ADVANCED) =====

Phan tich dia chi o nho (Array Pointer)

Tim gia tri nho nhat (Pass by Pointer)

Quan ly danh sach ten (Double Pointer)

Thoat
Chon chuc nang: 2
So nho nhat trong mang {10, 2, 85, 4} la: 2

===== HE THONG QUAN LY (POINTER ADVANCED) =====

Phan tich dia chi o nho (Array Pointer)

Tim gia tri nho nhat (Pass by Pointer)

Quan ly danh sach ten (Double Pointer)

Thoat
Chon chuc nang: 3
Nhap so luong sinh vien: 2
Nhap ten sinh vien thu 1: Nguyen Van A
Nhap ten sinh vien thu 2: Tran Thi B

Danh sach vua nhap:

Nguyen Van A (Luu tai: 0x7b1230)

Tran Thi B (Luu tai: 0x7b1250)
Da giai phong bo nho danh sach.

===== HE THONG QUAN LY (POINTER ADVANCED) =====

Phan tich dia chi o nho (Array Pointer)

Tim gia tri nho nhat (Pass by Pointer)

Quan ly danh sach ten (Double Pointer)

Thoat
Chon chuc nang: 0
Tam biet!
