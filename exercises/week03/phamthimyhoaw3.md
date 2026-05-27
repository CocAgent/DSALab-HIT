#include <iostream>
#include <chrono> // Dùng để đo thời gian ở Bài 3 & Bài 4
#include <cmath>

using namespace std;

// ============================================================================
// CÁC HÀM HỖ TRỢ XỬ LÝ CHUỖI TỰ CHẾ (THAY THẾ STL)
// ============================================================================
int strLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void strCopy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// So sánh 2 chuỗi theo thứ tự từ điển (Trả về <0, 0, >0)
int strCompare(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];
}

// Kiểm tra chuỗi con (Tìm kiếm mờ)
bool strContains(const char* haystack, const char* needle) {
    int hLen = strLength(haystack);
    int nLen = strLength(needle);
    if (nLen > hLen) return false;
    for (int i = 0; i <= hLen - nLen; i++) {
        bool found = true;
        for (int j = 0; j < nLen; j++) {
            if (haystack[i + j] != needle[j]) {
                found = false;
                break;
            }
        }
        if (found) return true;
    }
    return false;
}


// ============================================================================
// BÀI 1: LINEAR SEARCH (Đếm số bước so sánh)
// ============================================================================
int linearSearchInt(int arr[], int n, int target, int &steps) {
    steps = 0;
    for (int i = 0; i < n; i++) {
        steps++;
        if (arr[i] == target) return i;
    }
    return -1;
}

int linearSearchString(char arr[][50], int n, const char* target, int &steps) {
    steps = 0;
    for (int i = 0; i < n; i++) {
        steps++;
        if (strCompare(arr[i], target) == 0) return i;
    }
    return -1;
}

void Thucthi_Bai1() {
    cout << "\n--- KET QUA BAI 1: LINEAR SEARCH ---\n";
    int steps = 0;
    
    // 1. Tìm trên mảng số nguyên
    int arrInt[] = {12, 45, 67, 89, 34, 23, 90};
    int nInt = sizeof(arrInt) / sizeof(arrInt[0]);
    int targetInt = 34;
    int posInt = linearSearchInt(arrInt, nInt, targetInt, steps);
    cout << "Mang int: {12, 45, 67, 89, 34, 23, 90}\n";
    cout << "-> Tim kiem so " << targetInt << ": Vi tri = " << posInt << " (So buoc so sanh: " << steps << ")\n";

    // 2. Tìm trên mảng chuỗi
    char arrStr[5][50] = {"An", "Binh", "Chinh", "Dong", "Giang"};
    const char* targetStr = "Dong";
    int posStr = linearSearchString(arrStr, 5, targetStr, steps);
    cout << "\nMang chuoi: {\"An\", \"Binh\", \"Chinh\", \"Dong\", \"Giang\"}\n";
    cout << "-> Tim kiem \"" << targetStr << "\": Vi tri = " << posStr << " (So buoc so sanh: " << steps << ")\n";
}


// ============================================================================
// BÀI 2: BINARY SEARCH (Vòng lặp + Đệ quy & Tìm biên trùng)
// ============================================================================
// Bản vòng lặp (Iterative)
int binarySearchIterative(int arr[], int n, int target, int &steps) {
    int left = 0, right = n - 1;
    steps = 0;
    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Bản đệ quy trợ lý (Recursive Helper)
int binarySearchRecursiveHelper(int arr[], int left, int right, int target, int &steps) {
    if (left > right) return -1;
    steps++;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearchRecursiveHelper(arr, mid + 1, right, target, steps);
    return binarySearchRecursiveHelper(arr, left, mid - 1, target, steps);
}

int binarySearchRecursive(int arr[], int n, int target, int &steps) {
    steps = 0;
    return binarySearchRecursiveHelper(arr, 0, n - 1, target, steps);
}

// Tìm vị trí đầu tiên và cuối cùng của phần tử trùng nhau
void findFirstAndLast(int arr[], int n, int target) {
    int first = -1, last = -1;
    
    // Tìm biên đầu tiên
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            first = mid;
            right = mid - 1; // Tiếp tục ép sang trái xem còn phần tử nào trùng không
        } else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    // Tìm biên cuối cùng
    left = 0; right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            last = mid;
            left = mid + 1; // Tiếp tục ép sang phải
        } else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    cout << "-> Phan tu " << target << " xuat hien tu vi tri " << first << " den " << last << "\n";
}

void Thucthi_Bai2() {
    cout << "\n--- KET QUA BAI 2: BINARY SEARCH ---\n";
    int arr[] = {10, 20, 30, 30, 30, 40, 50, 60}; // Mảng đã sort sẵn
    int n = sizeof(arr) / sizeof(arr[0]);
    int steps = 0;

    cout << "Mang: {10, 20, 30, 30, 30, 40, 50, 60}\n";
    int idxIter = binarySearchIterative(arr, n, 40, steps);
    cout << "-> Vong lap (Tìm 40): Vi tri = " << idxIter << " | So buoc: " << steps << "\n";

    int idxRec = binarySearchRecursive(arr, n, 40, steps);
    cout << "-> De quy   (Tìm 40): Vi tri = " << idxRec << " | So buoc: " << steps << "\n";

    // Tìm kiếm phần tử trùng lặp
    findFirstAndLast(arr, n, 30);
}


// ============================================================================
// BÀI 3: SO SÁNH HIỆU NĂNG (Bảng dữ liệu lớn)
// ============================================================================
void runBenchmark(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = i; // Khởi tạo mảng tăng dần liên tục

    int target = n - 2; // Chọn phần tử gần cuối để Linear Search chịu mức tệ nhất
    int stepsLinear = 0, stepsBinary = 0;

    // Đo Linear Search
    auto start = chrono::high_resolution_clock::now();
    linearSearchInt(arr, n, target, stepsLinear);
    auto end = chrono::high_resolution_clock::now();
    double timeLinear = chrono::duration<double, milli>(end - start).count();

    // Đo Binary Search
    start = chrono::high_resolution_clock::now();
    binarySearchIterative(arr, n, target, stepsBinary);
    end = chrono::high_resolution_clock::now();
    double timeBinary = chrono::duration<double, milli>(end - start).count();

    // In dòng kết quả cho bảng
    cout << n << "\t| " 
         << stepsLinear << "\t\t| " << timeLinear << " ms\t| "
         << stepsBinary << "\t\t| " << timeBinary << " ms\n";

    delete[] arr;
}

void Thucthi_Bai3() {
    cout << "\n--- KET QUA BAI 3: SO SANH HIEU NANG TIEU CHUAN ---\n";
    cout << "Kich thuoc\t| Buoc Linear\t| Thoi gian LS\t| Buoc Binary\t| Thoi gian BS\n";
    cout << "------------------------------------------------------------------------------------\n";
    runBenchmark(10000);
    runBenchmark(100000);
    runBenchmark(1000000);
}


// ============================================================================
// BÀI 4: DỰ ÁN MINI — SMART SEARCH ENGINE (Quản lý & tìm kiếm danh bạ thông minh)
// ============================================================================
struct ThongTinLienHe {
    char hoTen[50];
    char sdt[20];
};

// Thuật toán Quick Sort tự viết để sắp xếp danh bạ theo Số điện thoại phục vụ Binary Search
void quickSortSDT(ThongTinLienHe arr[], int low, int high) {
    if (low < high) {
        ThongTinLienHe pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (strCompare(arr[j].sdt, pivot.sdt) < 0) {
                i++;
                ThongTinLienHe temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        ThongTinLienHe temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        int pi = i + 1;
        quickSortSDT(arr, low, pi - 1);
        quickSortSDT(arr, pi + 1, high);
    }
}

class SmartSearchEngine {
private:
    ThongTinLienHe danhBa[50];
    int size;

public:
    SmartSearchEngine() {
        // Khởi tạo cứng dữ liệu danh bạ mẫu ban đầu
        size = 5;
        strCopy(danhBa[0].hoTen, "Nguyen Van Minh");   strCopy(danhBa[0].sdt, "0901234567");
        strCopy(danhBa[1].hoTen, "Tran Thi Minh Anh"); strCopy(danhBa[1].sdt, "0912345678");
        strCopy(danhBa[2].hoTen, "Le Minh Tuan");      strCopy(danhBa[2].sdt, "0923456789");
        strCopy(danhBa[3].hoTen, "Pham Hoang Long");   strCopy(danhBa[3].sdt, "0988888888");
        strCopy(danhBa[4].hoTen, "Vuong Dac Luc");     strCopy(danhBa[4].sdt, "0977777777");
        
        // Luôn sắp xếp theo SĐT trước để sẵn sàng dùng Binary Search
        quickSortSDT(danhBa, 0, size - 1);
    }

    // Tìm kiếm mờ theo tên (Linear Search)
    void timKiemTheoTen() {
        char tuKhoa[50];
        cout << "Nhap TEN can tim (ho tro tim kiem mo): ";
        cin.getline(tuKhoa, 50);

        int steps = 0;
        bool found = false;

        auto start = chrono::high_resolution_clock::now();
        cout << "\n-> Ket qua tim kiem:\n";
        for (int i = 0; i < size; i++) {
            steps++;
            if (strContains(danhBa[i].hoTen, tuKhoa)) {
                cout << "   - " << danhBa[i].hoTen << " - " << danhBa[i].sdt << "\n";
                found = true;
            }
        }
        auto end = chrono::high_resolution_clock::now();
        double duration = chrono::duration<double, milli>(end - start).count();

        cout << "  (Da so sanh " << steps << "/" << size << " phan tu — " << duration << " ms)\n";

        // Gợi ý 3 liên hệ ngẫu nhiên nếu không tìm thấy bất kỳ ai
        if (!found) {
            cout << "\n=> Khong tim thay chuoi phu hop! Goi y danh ba danh cho ban:\n";
            int goiY = (size < 3) ? size : 3;
            for (int i = 0; i < goiY; i++) {
                cout << "   * " << danhBa[i].hoTen << " - " << danhBa[i].sdt << "\n";
            }
        }
    }

    // Tìm kiếm chính xác theo Số Điện Thoại (Binary Search)
    void timKiemTheoSDT() {
        char sdtCanTim[20];
        cout << "Nhap CHINH XAC So Dien Thoai can tim: ";
        cin.getline(sdtCanTim, 20);

        int steps = 0;
        int left = 0, right = size - 1;
        int foundIdx = -1;

        auto start = chrono::high_resolution_clock::now();
        while (left <= right) {
            steps++;
            int mid = left + (right - left) / 2;
            int comp = strCompare(danhBa[mid].sdt, sdtCanTim);
            
            if (comp == 0) {
                foundIdx = mid;
                break;
            } else if (comp < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        auto end = chrono::high_resolution_clock::now();
        double duration = chrono::duration<double, milli>(end - start).count();

        if (foundIdx != -1) {
            cout << "\n-> Tim thay ket qua:\n";
            cout << "   - " << danhBa[foundIdx].hoTen << " - " << danhBa[foundIdx].sdt << "\n";
        } else {
            cout << "\n=> Khong tim thay So Dien Thoai nay trong danh ba.\n";
        }
        cout << "  (Thong ke: So buoc so sanh nhi phan: " << steps << " — " << duration << " ms)\n";
    }
};

void Thucthi_Bai4_Menu() {
    SmartSearchEngine engine;
    int luaChon;
    do {
        cout << "\n=== SMART SEARCH ENGINE MENU ===\n";
        cout << "1. Tim kiem theo Ten (Linear Search - Tim mo)\n";
        cout << "2. Tim kiem theo So Dien Thoai (Binary Search)\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore(); // Xóa bộ đệm chống trôi lệnh nhập chuỗi sau đó

        if (luaChon == 1) engine.timKiemTheoTen();
        else if (luaChon == 2) engine.timKiemTheoSDT();
    } while (luaChon != 0);
}


// ============================================================================
// HÀM MAIN ĐIỀU HƯỚNG TỔNG
// ============================================================================
int main() {
    int chonBai;
    do {
        cout << "\n============================================\n";
        cout << "CHON BAI TAP VE THUAT TOAN TIM KIEM:\n";
        cout << "1. Bai 1: Linear Search chuoi va so (Dem buoc)\n";
        cout << "2. Bai 2: Binary Search (Iterative, Recursive, Trung bien)\n";
        cout << "3. Bai 3: Bang so sanh hieu nang thoi gian\n";
        cout << "4. Bai 4: [Mini Project] Smart Search Engine Danh Ba\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "============================================\n";
        cout << "Nhap lua chon (0 -> 4): ";
        cin >> chonBai;
        cin.ignore(); // Tránh trôi lệnh

        switch (chonBai) {
            case 1: Thucthi_Bai1(); break;
            case 2: Thucthi_Bai2(); break;
            case 3: Thucthi_Bai3(); break;
            case 4: Thucthi_Bai4_Menu(); break;
            case 0: cout << "Tam biet!\n"; break;
            default: cout << "Lua chon khong hop le.\n";
        }
    } while (chonBai != 0);

    return 0;
}
