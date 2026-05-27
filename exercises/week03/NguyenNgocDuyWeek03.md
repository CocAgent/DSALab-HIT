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
//1. Phần Nhập Dữ Liệu & Test Bài 1 (Tìm kiếm tuyến tính)
//Khi chương trình bắt đầu, hệ thống yêu cầu bạn nhập vào một mảng số nguyên với kích thước n và một giá trị x cần tìm.

//Cách hoạt động của LinearSearch:

//Hàm bắt đầu từ vị trí đầu tiên (i = 0) và đi lần lượt qua từng phần tử của mảng.

//Tại mỗi bước, biến soBuoc sẽ tăng lên 1 và chương trình kiểm tra xem a[i] có bằng x hay không.

//Nếu tìm thấy, hàm trả về vị trí (chỉ số i) ngay lập tức và dừng lại. Nếu đi hết mảng mà không thấy, hàm trả về -1.

//Đặc điểm: Không cần mảng phải sắp xếp trước, nhưng nếu phần tử ở cuối mảng hoặc không tồn tại, nó phải duyệt qua toàn bộ dữ liệu.

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
//Trước khi chạy Bài 2, chương trình sử dụng lệnh sort(mangNhap, mangNhap + n) để sắp xếp mảng vừa nhập thành thứ tự tăng dần. Đây là điều kiện bắt buộc của Tìm kiếm nhị phân.

//Hàm này hoạt động theo nguyên lý "chặt đôi": luôn kiểm tra phần tử ở giữa (m). Nếu x nhỏ hơn phần tử ở giữa, ta bỏ nửa bên phải; nếu x lớn hơn, ta bỏ nửa bên trái.

//Tuy nhiên, bài toán yêu cầu tìm vị trí đầu tiên và cuối cùng trong trường hợp có nhiều số giống nhau (ví dụ mảng [1, 2, 2, 2, 3] và tìm x = 2):

//Vị trí đầu tiên (BinarySearchFirst - Dùng vòng lặp):

//Khi tìm thấy a[m] == x, thay vì dừng lại ngay, hàm sẽ ghi nhớ vị trí này vào biến res.

//Vì muốn tìm vị trí đầu tiên (nằm xa hơn về bên trái), hàm tiếp tục thu hẹp phạm vi tìm kiếm sang nửa bên trái (r = m - 1) xem còn số 2 nào khác không.

//Vị trí cuối cùng (BinarySearchLast - Dùng đệ quy):

//Tương tự, khi tìm thấy a[m] == x, hàm ghi nhớ vị trí m vào res.

//Vì muốn tìm vị trí cuối cùng (nằm xa hơn về bên phải), hàm tự gọi lại chính nó (đệ quy) nhưng thu hẹp phạm vi sang nửa bên phải (l = m + 1).

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
//Hàm này hoạt động hoàn toàn tự động bằng cách tạo ra 3 mảng giả lập với kích thước tăng dần: 10.000, 100.000, và 1.000.000 phần tử.Chương trình đặt giá trị cần tìm x ở cuối mảng (trường hợp tệ nhất).Thư viện <chrono> được sử dụng giống như một chiếc đồng hồ bấm giờ: lấy thời điểm trước khi chạy thuật toán trừ đi thời điểm sau khi chạy để ra số mili-giây (ms).Kết quả in ra dạng bảng: Bạn sẽ thấy rõ khi dữ liệu lên tới 1 triệu phần tử, Linear Search mất vài mili-giây để duyệt qua 1 triệu lần, trong khi Binary Search chỉ mất khoảng $0.000...$ ms vì chỉ tốn tối đa khoảng 20 bước chia đôi.

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
//Hệ thống cung cấp một menu cho bạn chọn 1 trong 2 cách tìm kiếm dựa trên cấu trúc dữ liệu DanhBa (gồm Tên và SĐT):

//Lựa chọn 1 - Tìm theo Tên (Tìm kiếm mờ):

//Sử dụng vòng lặp duyệt tuyến tính từ đầu đến cuối danh bạ.

//Tại mỗi phần tử, lệnh db[i].ten.find(kw) != string::npos sẽ kiểm tra xem từ khóa bạn nhập có nằm bên trong tên của danh bạ hay không (ví dụ nhập "Minh" sẽ khớp với cả "Nguyễn Văn Minh" và "Lê Minh Tuấn").

//Nếu không tìm thấy bất kỳ ai, một vòng lặp nhỏ sẽ tự động in ra 3 người đầu tiên trong danh sách để làm "gợi ý".

//Lựa chọn 2 - Tìm theo SĐT:

//Hệ thống tự động sắp xếp danh bạ theo thứ tự tăng dần của Số điện thoại trước bằng hàm sort kết hợp với hàm bổ trợ soSanhSDT.

//Sau đó, thuật toán Tìm kiếm nhị phân (Binary Search) được áp dụng để tìm ra chính xác người sở hữu số điện thoại đó với tốc độ cực nhanh.
