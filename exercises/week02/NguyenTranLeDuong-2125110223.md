#include <iostream>

using namespace std;

int main() {
    int n;

    // Nhập số lượng phần tử của mảng
    cout << "Nhap so phan tu n: ";
    cin >> n;

    // Kiểm tra điều kiện số lượng phần tử hợp lệ
    if (n <= 0) {
        cout << "So phan tu khong hop le!" << endl;
        return 1;
    }

    // Khai báo mảng tĩnh với kích thước n
    double* a = new double[n];

    // Nhập các phần tử vào mảng
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    // Khởi tạo các giá trị ban đầu để tính toán
    double min_val = a[0];
    double max_val = a[0];
    double tong = 0;

    // Vòng lặp để tìm min, max và tính tổng
    for (int i = 0; i < n; i++) {
        // Tìm min
        if (a[i] < min_val) {
            min_val = a[i];
        }
        // Tìm max
        if (a[i] > max_val) {
            max_val = a[i];
        }
        // Cộng dồn vào tổng
        tong += a[i];
    }

    // Tính trung bình cộng
    double trung_binh = tong / n;

    // --- Hiển thị kết quả ra màn hình ---
    cout << "\n--- KET QUA ---" << endl;
    cout << "Cac phan tu ban da nhap la:" << endl;
    for (int i = 0; i < n; i++) 
        cout << a[i] << endl;
    cout << "Gia tri nho nhat (Min): " << min_val << endl;
    cout << "Gia tri lon nhat (Max): " << max_val << endl;
    cout << "Tong cac phan tu: " << tong << endl;
    cout << "Trung binh cong: " << trung_binh << endl;
    delete[]a;
    a = nullptr; 
    return 0;
}
