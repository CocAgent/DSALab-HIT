#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace chrono;

// ============================================================
//  TIỆN ÍCH
// ============================================================

void printArr(const vector<int>& arr, int highlight = -1, int pivot = -1) {
    cout << "[ ";
    for (int i = 0; i < (int)arr.size(); i++) {
        if (i == highlight) cout << "\033[32m[" << arr[i] << "]\033[0m ";
        else if (i == pivot) cout << "\033[33m(" << arr[i] << ")\033[0m ";
        else cout << arr[i] << " ";
    }
    cout << "]\n";
}

void printLine(char c = '-', int n = 55) {
    cout << string(n, c) << "\n";
}

// ============================================================
//  BÀI 1: LINEAR SEARCH
// ============================================================

// Tìm trên mảng số nguyên — trả về index, đếm bước
int linearSearch(const vector<int>& arr, int target, int& steps) {
    steps = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        steps++;
        cout << "  Buoc " << steps << ": arr[" << i << "] = " << arr[i];
        if (arr[i] == target) {
            cout << " == " << target << " -> TIM THAY!\n";
            return i;
        }
        cout << " != " << target << "\n";
    }
    return -1;
}

// Tìm TẤT CẢ vị trí (phần tử trùng)
vector<int> linearSearchAll(const vector<int>& arr, int target, int& steps) {
    steps = 0;
    vector<int> result;
    for (int i = 0; i < (int)arr.size(); i++) {
        steps++;
        if (arr[i] == target) result.push_back(i);
    }
    return result;
}

// Tìm chuỗi con (case-insensitive)
vector<int> linearSearchString(const vector<string>& arr, const string& query, int& steps) {
    steps = 0;
    vector<int> result;
    string q = query;
    transform(q.begin(), q.end(), q.begin(), ::tolower);
    for (int i = 0; i < (int)arr.size(); i++) {
        steps++;
        string s = arr[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s.find(q) != string::npos) result.push_back(i);
    }
    return result;
}

void bai1() {
    printLine('=');
    cout << "BÀI 1: LINEAR SEARCH\n";
    printLine('=');

    // --- Mảng số nguyên ---
    vector<int> arr = {15, 42, 7, 38, 22, 91, 5, 63, 17, 42, 80, 34};
    int target = 42;
    int steps = 0;

    cout << "\nMang so nguyen:\n";
    printArr(arr);
    cout << "Tim kiem: " << target << "\n\n";

    int idx = linearSearch(arr, target, steps);
    cout << "\nKet qua: ";
    if (idx != -1) cout << "Tim thay tai vi tri " << idx;
    else           cout << "Khong tim thay";
    cout << " | So buoc: " << steps << " / " << arr.size()
         << " (" << fixed << setprecision(1) << (100.0*steps/arr.size()) << "%)\n";

    // --- Tìm tất cả vị trí ---
    cout << "\nTim TAT CA vi tri cua " << target << ":\n";
    vector<int> all = linearSearchAll(arr, target, steps);
    cout << "  Vi tri: ";
    for (int i : all) cout << i << " ";
    cout << "| So buoc: " << steps << "\n";

    // --- Mảng chuỗi ---
    cout << "\n--- Tim kiem chuoi con ---\n";
    vector<string> names = {
        "Nguyen Van An", "Tran Thi Bich", "Hoang Minh Khoa",
        "Nguyen Thi Minh", "Tran Thi Minh Anh", "Le Minh Tuan",
        "Pham Van Dat", "Vu Minh Chau", "Nguyen Van Minh",
        "Do Minh Quang", "Tran Minh Ha", "Hoang Minh Phuc"
    };
    string query = "Minh";
    cout << "Tim chuoi: \"" << query << "\"\n";
    vector<int> strResult = linearSearchString(names, query, steps);
    cout << "Tim thay " << strResult.size() << " ket qua (" << steps << " buoc):\n";
    for (int i : strResult)
        cout << "  [" << i << "] " << names[i] << "\n";
}

// ============================================================
//  BÀI 2: BINARY SEARCH
// ============================================================

// Iterative
int binarySearchIter(const vector<int>& arr, int target, int& steps) {
    steps = 0;
    int L = 0, R = (int)arr.size() - 1;
    while (L <= R) {
        steps++;
        int mid = L + (R - L) / 2;
        cout << "  Buoc " << steps << ": L=" << L << " R=" << R
             << " mid=" << mid << " arr[mid]=" << arr[mid];
        if (arr[mid] == target) { cout << " -> TIM THAY!\n"; return mid; }
        else if (arr[mid] < target) { cout << " < " << target << ", L->" << mid+1 << "\n"; L = mid + 1; }
        else                        { cout << " > " << target << ", R->" << mid-1 << "\n"; R = mid - 1; }
    }
    cout << "  -> KHONG TIM THAY\n";
    return -1;
}

// Recursive
int binarySearchRec(const vector<int>& arr, int target, int L, int R, int& steps) {
    if (L > R) return -1;
    steps++;
    int mid = L + (R - L) / 2;
    cout << "  Buoc " << steps << ": goi de quy [" << L << ".." << R
         << "] mid=" << mid << " arr[mid]=" << arr[mid] << "\n";
    if (arr[mid] == target) return mid;
    if (arr[mid] < target)  return binarySearchRec(arr, target, mid + 1, R, steps);
    return binarySearchRec(arr, target, L, mid - 1, steps);
}

// Vị trí đầu tiên
int binarySearchFirst(const vector<int>& arr, int target, int& steps) {
    steps = 0;
    int L = 0, R = (int)arr.size() - 1, result = -1;
    while (L <= R) {
        steps++;
        int mid = L + (R - L) / 2;
        if (arr[mid] == target) { result = mid; R = mid - 1; } // tiếp tục tìm trái
        else if (arr[mid] < target) L = mid + 1;
        else R = mid - 1;
    }
    return result;
}

// Vị trí cuối cùng
int binarySearchLast(const vector<int>& arr, int target, int& steps) {
    steps = 0;
    int L = 0, R = (int)arr.size() - 1, result = -1;
    while (L <= R) {
        steps++;
        int mid = L + (R - L) / 2;
        if (arr[mid] == target) { result = mid; L = mid + 1; } // tiếp tục tìm phải
        else if (arr[mid] < target) L = mid + 1;
        else R = mid - 1;
    }
    return result;
}

void bai2() {
    printLine('=');
    cout << "BÀI 2: BINARY SEARCH\n";
    printLine('=');

    vector<int> arr = {3, 7, 9, 11, 17, 17, 19, 23, 23, 23, 29, 31, 37, 45, 45, 51};
    cout << "\nMang da sap xep:\n";
    printArr(arr);

    // --- Iterative ---
    {
        int target = 23, steps = 0;
        cout << "\n[Iterative] Tim: " << target << "\n";
        int idx = binarySearchIter(arr, target, steps);
        cout << "Ket qua: vi tri " << idx << " | So buoc: " << steps << "\n";
    }

    // --- Recursive ---
    {
        int target = 17, steps = 0;
        cout << "\n[Recursive] Tim: " << target << "\n";
        int idx = binarySearchRec(arr, target, 0, arr.size()-1, steps);
        cout << "Ket qua: vi tri " << idx << " | So buoc: " << steps << "\n";
    }

    // --- Vị trí đầu tiên / cuối cùng ---
    {
        int target = 23, s1 = 0, s2 = 0;
        int first = binarySearchFirst(arr, target, s1);
        int last  = binarySearchLast(arr, target, s2);
        cout << "\n[First/Last] Tim: " << target << "\n";
        cout << "  Vi tri dau tien : " << first << " (" << s1 << " buoc)\n";
        cout << "  Vi tri cuoi cung: " << last  << " (" << s2 << " buoc)\n";
        cout << "  So lan xuat hien: " << (last - first + 1) << "\n";
    }
}

// ============================================================
//  BÀI 3: SO SÁNH HIỆU NĂNG
// ============================================================

long long measureLinear(int n, int target) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i * 2 + 1; // mảng lẻ tăng dần
    long long steps = 0;
    for (int i = 0; i < n; i++) { steps++; if (arr[i] == target) break; }
    return steps;
}

long long measureBinary(int n, int target) {
    // arr[i] = i*2+1, target = (idx*2+1)
    long long steps = 0;
    int L = 0, R = n - 1;
    while (L <= R) {
        steps++;
        int mid = L + (R - L) / 2;
        int val = mid * 2 + 1;
        if (val == target) break;
        else if (val < target) L = mid + 1;
        else R = mid - 1;
    }
    return steps;
}

void bai3() {
    printLine('=');
    cout << "BÀI 3: SO SÁNH HIỆU NĂNG\n";
    printLine('=');

    vector<int> sizes = {10000, 100000, 1000000};

    cout << "\n" << left
         << setw(12) << "n"
         << setw(18) << "Linear (buoc)"
         << setw(18) << "Binary (buoc)"
         << setw(14) << "Nhanh hon"
         << setw(16) << "Linear (ms)"
         << setw(16) << "Binary (ms)"
         << "\n";
    printLine('-', 90);

    for (int n : sizes) {
        // target ở giữa mảng (worst case gần trung bình cho linear)
        int targetIdx = n / 2;
        int target    = targetIdx * 2 + 1;

        // đo bước
        long long linSteps = measureLinear(n, target);
        long long binSteps = measureBinary(n, target);

        // đo thời gian
        auto t0 = high_resolution_clock::now();
        measureLinear(n, target);
        auto t1 = high_resolution_clock::now();
        measureBinary(n, target);
        auto t2 = high_resolution_clock::now();

        double linMs = duration<double, milli>(t1 - t0).count();
        double binMs = duration<double, milli>(t2 - t1).count();
        double ratio = (double)linSteps / binSteps;

        cout << left
             << setw(12) << n
             << setw(18) << linSteps
             << setw(18) << binSteps
             << setw(14) << (to_string((int)ratio) + "x")
             << setw(16) << fixed << setprecision(3) << linMs
             << setw(16) << binMs
             << "\n";
    }

    cout << "\nNhan xet:\n";
    cout << "  - Linear : O(n)    — n=1.000.000 can ~500.000 buoc trung binh\n";
    cout << "  - Binary : O(log n) — n=1.000.000 can chi ~20 buoc\n";
    cout << "  - log2(1.000.000) = " << fixed << setprecision(1) << log2(1000000) << " buoc\n";
}

// ============================================================
//  BÀI 4: SMART SEARCH ENGINE — DANH BẠ
// ============================================================

struct Contact {
    string name;
    string phone;
};

// Levenshtein distance (gợi ý tên gần giống)
int levenshtein(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> d(m+1, vector<int>(n+1));
    for (int i = 0; i <= m; i++) d[i][0] = i;
    for (int j = 0; j <= n; j++) d[0][j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = (a[i-1] == b[j-1])
                ? d[i-1][j-1]
                : 1 + min({d[i-1][j], d[i][j-1], d[i-1][j-1]});
    return d[m][n];
}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Tìm theo tên: Linear Search + fuzzy (chuỗi con)
vector<int> searchByName(const vector<Contact>& book, const string& query, int& steps) {
    steps = 0;
    vector<int> result;
    string q = toLower(query);
    for (int i = 0; i < (int)book.size(); i++) {
        steps++;
        if (toLower(book[i].name).find(q) != string::npos)
            result.push_back(i);
    }
    return result;
}

// Tìm theo SĐT: Binary Search (danh bạ đã sort theo phone)
int searchByPhone(const vector<Contact>& book, const string& phone, int& steps) {
    steps = 0;
    int L = 0, R = (int)book.size() - 1;
    while (L <= R) {
        steps++;
        int mid = L + (R - L) / 2;
        int cmp = book[mid].phone.compare(phone);
        if (cmp == 0) return mid;
        else if (cmp < 0) L = mid + 1;
        else R = mid - 1;
    }
    return -1;
}

// Gợi ý 3 tên gần nhất
vector<int> suggest(const vector<Contact>& book, const string& query, int topK = 3) {
    string q = toLower(query);
    vector<pair<int,int>> dist; // {distance, index}
    for (int i = 0; i < (int)book.size(); i++)
        dist.push_back({levenshtein(toLower(book[i].name), q), i});
    sort(dist.begin(), dist.end());
    vector<int> result;
    for (int i = 0; i < topK && i < (int)dist.size(); i++)
        result.push_back(dist[i].second);
    return result;
}

void bai4() {
    printLine('=');
    cout << "BÀI 4: SMART SEARCH ENGINE — DANH BẠ\n";
    printLine('=');

    vector<Contact> phonebook = {
        {"Bui Quang Hai",     "0356781234"},
        {"Bui Thi Mai",       "0378901234"},
        {"Bui Van Nam",       "0389012345"},
        {"Dang Quoc Bao",     "0701234567"},
        {"Dang Thi Bao",      "0712345678"},
        {"Dang Van Long",     "0723456789"},
        {"Do Minh Quang",     "0756789012"},
        {"Do Thi Hoa",        "0767890123"},
        {"Do Thi Linh",       "0778901234"},
        {"Hoang Minh Khoa",   "0801234567"},
        {"Hoang Minh Phuc",   "0812345678"},
        {"Hoang Thi Dieu",    "0823456789"},
        {"Hoang Thi Kim",     "0834567890"},
        {"Hoang Thi Lan",     "0845678901"},
        {"Hoang Thi Thuy",    "0856789012"},
        {"Hoang Van Dung",    "0867890123"},
        {"Le Minh Tuan",      "0878901234"},
        {"Le Thi Huong",      "0889012345"},
        {"Le Thi Ngoc",       "0890123456"},
        {"Le Thi Thanh",      "0901234567"},
        {"Le Van Hung",       "0912345678"},
        {"Le Van Tuan",       "0923456789"},
        {"Nguyen Huu Tai",    "0934567890"},
        {"Nguyen Minh Tam",   "0945678901"},
        {"Nguyen Quynh Anh",  "0956789012"},
        {"Nguyen Thi Minh",   "0967890123"},
        {"Nguyen Van An",     "0978901234"},
        {"Nguyen Van Minh",   "0901234568"},
        {"Nguyen Van Tu",     "0989012345"},
        {"Pham Hong Son",     "0990123456"},
        {"Pham Minh Duc",     "0991234567"},
        {"Pham Minh Hieu",    "0992345678"},
        {"Pham Thi Thu",      "0993456789"},
        {"Pham Thi Yen",      "0994567890"},
        {"Pham Van Dat",      "0995678901"},
        {"Pham Van Hung",     "0996789012"},
        {"Tran Duc Anh",      "0997890123"},
        {"Tran Minh Ha",      "0798901234"},
        {"Tran Quang Vinh",   "0809012345"},
        {"Tran Thi Bich",     "0820123456"},
        {"Tran Thi Minh Anh", "0831234567"},
        {"Tran Thi Xuan",     "0842345678"},
        {"Tran Van Manh",     "0853456789"},
        {"Vu Duc Thinh",      "0864567890"},
        {"Vu Minh Chau",      "0875678901"},
        {"Vu Ngoc Diep",      "0886789012"},
        {"Vu Quoc Hung",      "0897890123"},
        {"Vu Thi Hanh",       "0808901234"},
        {"Vu Thi Phuong",     "0819012345"},
        {"Vu Thi Thuy",       "0830123456"},
    };
    // Đã sort sẵn theo phone (vì Binary Search yêu cầu)

    cout << "\nDanh ba: " << phonebook.size() << " lien he (da sort theo SDT)\n";

    // --- Tìm theo tên ---
    {
        string query = "Minh";
        int steps = 0;
        auto t0 = high_resolution_clock::now();
        vector<int> res = searchByName(phonebook, query, steps);
        double ms = duration<double, milli>(high_resolution_clock::now() - t0).count();

        cout << "\n[TIM THEO TEN] \"" << query << "\"\n";
        cout << "Thuat toan: Linear Search (tim chuoi con)\n";
        cout << "Tim thay " << res.size() << " ket qua | "
             << steps << "/" << phonebook.size() << " buoc | "
             << fixed << setprecision(4) << ms << "ms\n\n";
        for (int i : res)
            cout << "  " << left << setw(25) << phonebook[i].name
                 << " - " << phonebook[i].phone << "\n";
    }

    // --- Tìm theo SĐT ---
    {
        string phone = "0901234567";
        int steps = 0;
        auto t0 = high_resolution_clock::now();
        int idx = searchByPhone(phonebook, phone, steps);
        double ms = duration<double, milli>(high_resolution_clock::now() - t0).count();

        cout << "\n[TIM THEO SDT] \"" << phone << "\"\n";
        cout << "Thuat toan: Binary Search\n";
        cout << steps << " buoc | " << fixed << setprecision(4) << ms << "ms\n";
        if (idx != -1)
            cout << "Tim thay: " << phonebook[idx].name << " - " << phonebook[idx].phone << "\n";
        else
            cout << "Khong tim thay!\n";
    }

    // --- Không tìm thấy → gợi ý ---
    {
        string query = "Ngueyn"; // cố tình sai
        int steps = 0;
        vector<int> res = searchByName(phonebook, query, steps);

        cout << "\n[TIM THEO TEN] \"" << query << "\" (co y viet sai)\n";
        if (res.empty()) {
            cout << "Khong tim thay! Goi y 3 ten gan giong nhat:\n";
            vector<int> sug = suggest(phonebook, query);
            for (int i = 0; i < (int)sug.size(); i++)
                cout << "  " << (i+1) << ". " << phonebook[sug[i]].name
                     << "  - " << phonebook[sug[i]].phone << "\n";
        }
    }
}

// ============================================================
//  MAIN
// ============================================================

int main() {
    bai1();
    cout << "\n";
    bai2();
    cout << "\n";
    bai3();
    cout << "\n";
    bai4();

    cout << "\n";
    printLine('=');
    cout << "HOAN THANH TUAN 3: TIM KIEM\n";
    printLine('=');
    return 0;
}
