//Trinh Hoang Dat 2125110180

#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
//week 02
//Bai 1 Nhập mảng n phần tử. Tính min, max, trung bình, tổng. Không dùng STL.
void NhapMang(int a[], int soPhanTu)
{
    for (int i = 0; i < soPhanTu; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void TinhMinMaxTrungBinhTong(int a[],int soPhanTu)
{
    int min = a[0];
    for (int i = 0;i < soPhanTu;i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    cout << "Min = " << min << endl;
    int max = a[0];
    for (int i = 0;i < soPhanTu;i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    cout << "Max = " << max << endl;
    int tong = 0;
    for (int i = 0;i < soPhanTu;i++)
    {
        tong += a[i];
    }
    cout << "Tong = " << tong << endl;
    cout << "Trung binh cong = " << (float)tong / soPhanTu << endl;
}
//Bai 02 Nhân 2 ma trận n×n. Tính định thức ma trận 3×3. Hiển thị đẹp.

void nhanMaTran(int A[50][50], int B[50][50], int C[50][50], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;

            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void inMaTran(int X[50][50], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
}
//Bai 03 Cài đặt mảng động tự resize (như std::vector đơn giản). Hỗ trợ push_back, pop_back, at(i).
template <typename T>
class MyVector {
private:
    T* data;
    size_t sz;
    size_t cap;

    void resize() {
        size_t new_cap = (cap == 0) ? 1 : cap * 2;
        T* new_data = new T[new_cap];         

        for (size_t i = 0; i < sz; i++)     
            new_data[i] = data[i];

        delete[] data;                       
        data = new_data;
        cap = new_cap;
    }

public:
    MyVector() : data(nullptr), sz(0), cap(0) {}
    ~MyVector() { delete[] data; }k

    void push_back(const T& val) {
        if (sz == cap) resize();
        data[sz++] = val;
    }

    void pop_back() {
        if (sz == 0)
            throw std::underflow_error("pop_back on empty vector");
        --sz;

    }
    T& at(size_t i) {
        if (i >= sz)
            throw std::out_of_range("index out of range");
        return data[i];
    }

    const T& at(size_t i) const {
        if (i >= sz)
            throw std::out_of_range("index out of range");
        return data[i];
    }


    size_t size()     const { return sz; }
    size_t capacity() const { return cap; }
    bool   empty()    const { return sz == 0; }
}
//Bai 04
#include <iostream>
#include <fstream>
#include <string>S
#include <iomanip>
#include <algorithm>
using namespace std;

// ═══════════════════════════════════════════════
//  Cấu trúc sinh viên
// ═══════════════════════════════════════════════
struct Student {
    string mssv;
    string name;
    float  score;
};

// ═══════════════════════════════════════════════
//  Mảng động tự resize (như Bài 3)
// ═══════════════════════════════════════════════
class StudentManager {
private:
    Student* data;
    int      sz;
    int      cap;

    void resize() {
        int newCap = (cap == 0) ? 2 : cap * 2;
        Student* tmp = new Student[newCap];
        for (int i = 0; i < sz; i++) tmp[i] = data[i];
        delete[] data;
        data = tmp;
        cap = newCap;
    }

    string xepLoai(float s) const {
        if (s >= 8.5f) return "A (Gioi)";
        if (s >= 7.0f) return "B (Kha)";
        if (s >= 5.5f) return "C (TB)";
        if (s >= 4.0f) return "D (Yeu)";
        return "F (Kem)";
    }

    // ── Selection Sort theo điểm giảm dần ──────
    void selectionSort() {
        for (int i = 0; i < sz - 1; i++) {
            int maxIdx = i;
            for (int j = i + 1; j < sz; j++)
                if (data[j].score > data[maxIdx].score)
                    maxIdx = j;
            if (maxIdx != i) swap(data[i], data[maxIdx]);
        }
    }

    // ── Linear Search theo tên hoặc MSSV ───────
    int linearSearch(const string& key) const {
        for (int i = 0; i < sz; i++) {
            if (data[i].mssv == key || data[i].name == key)
                return i;
        }
        return -1;
    }

    void printHeader() const {
        cout << string(60, '=') << "\n";
        cout << left
            << setw(8) << "STT"
            << setw(10) << "MSSV"
            << setw(24) << "Ho ten"
            << setw(8) << "Diem"
            << "Xep loai\n";
        cout << string(60, '-') << "\n";
    }

    void printRow(int stt, const Student& s) const {
        cout << left
            << setw(8) << stt
            << setw(10) << s.mssv
            << setw(24) << s.name
            << setw(8) << fixed << setprecision(1) << s.score
            << xepLoai(s.score) << "\n";
    }

public:
    StudentManager() : data(nullptr), sz(0), cap(0) {}
    ~StudentManager() { delete[] data; }

    // ── Thêm sinh viên ─────────────────────────
    void addStudent() {
        if (sz == cap) resize();
        Student s;
        cout << "MSSV     : ";
    }

//week03
//Bai 1 Tìm kiếm tuyến tính trên mảng số nguyên và mảng chuỗi. Đếm số bước so sánh.
//Linear Search -- Tim kiem tuyen tinh
int LinearSearch(const int a[], int soPhanTu, int soCanTim)
{
    int i = 0, dem = 0;
    while (a[i] != soCanTim && i < soPhanTu)
    {
        dem++;
        i++;
    }
    if (i < soPhanTu) return dem+1;//dem+1 so dem ca so lan so sanh dung
    return -1;
}

//Bai 2 Cài đặt Binary Search iterative + recursive. Tìm vị trí đầu tiên và cuối cùng của phần tử trùng.
//mang a input phai duoc sap xep tang dan
int BinarySearchIterativeFindFirstChild(const int a[], int soPhanTu, int soCanTim)
{
    int left = 0, right = soPhanTu - 1, mid,kq=-1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == soCanTim)
        {
            kq = mid;
            right = mid - 1; //tiep tuc tim ben trai
        }
        else if (a[mid] < soCanTim)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return kq;
}
int BinarySearchIterativeFindLastChild(const int a[], int soPhanTu, int soCanTim)
{
    int left = 0, right = soPhanTu - 1, mid, kq = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == soCanTim)
        {
            kq = mid;
            right = mid - 1; //tiep tuc tim ben phai
        }
        else if (a[mid] < soCanTim)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return kq;
}

int BinarySearchRecursive(const int a[], int left,int right, int soCanTim)
{
    if (left > right) return -1;

    int m = (left + right) / 2;

    if (a[m] == soCanTim) return m;
    if (a[m] < soCanTim)
        return BinarySearchRecursive(a, m + 1, right, soCanTim);

    return BinarySearchRecursive(a, left, m - 1, soCanTim);
}
//Bai 3 Đo thời gian tìm kiếm với n = 10.000, 100.000, 1.000.000 phần tử. Vẽ bảng so sánh.
//| n           | Bước Binary Search    | Bước Linear Search|
//|             |                       |                   |
//| 10.000      | ≤ 14 bước             | ≤ 10.000 bước     |
//| 100.000     | ≤ 17 bước             | ≤ 100.000 bước    |
//| 1.000.000   | ≤ 20 bước             | ≤ 1.000.000 bước  |

//Bai 4
struct Contact {
    string name;
    string phone;
};

// ---------- LOWERCASE HELPER ----------
string toLower(string s) {
    for (char& c : s) c = tolower(c);
    return s;
}

// ---------- LINEAR SEARCH BY NAME ----------
vector<Contact> searchByName(vector<Contact>& contacts,
    string keyword,
    int& comparisons,
    double& timeTaken) {
    auto start = chrono::high_resolution_clock::now();

    vector<Contact> result;
    comparisons = 0;

    keyword = toLower(keyword);

    for (auto& c : contacts) {
        comparisons++;
        if (toLower(c.name).find(keyword) != string::npos) {
            result.push_back(c);
        }
    }

    auto end = chrono::high_resolution_clock::now();
    timeTaken = chrono::duration<double, milli>(end - start).count();

    return result;
}

// ---------- BINARY SEARCH BY PHONE ----------
pair<Contact, bool> searchByPhone(vector<Contact> contacts,
    string phone,
    int& comparisons,
    double& timeTaken) {
    auto start = chrono::high_resolution_clock::now();

    comparisons = 0;

    sort(contacts.begin(), contacts.end(),
        [](Contact a, Contact b) {
            return a.phone < b.phone;
        });

    int l = 0, r = contacts.size() - 1;

    while (l <= r) {
        comparisons++;
        int mid = (l + r) / 2;

        if (contacts[mid].phone == phone) {
            auto end = chrono::high_resolution_clock::now();
            timeTaken = chrono::duration<double, milli>(end - start).count();
            return { contacts[mid], true };
        }
        else if (contacts[mid].phone < phone) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    timeTaken = chrono::duration<double, milli>(end - start).count();

    return { {}, false };
}

// ---------- SIMPLE SIMILARITY ----------
int similarity(const string& a, const string& b) {
    string A = toLower(a), B = toLower(b);
    int count = 0;

    for (char c : A)
        if (B.find(c) != string::npos)
            count++;

    return count;
}

// ---------- SUGGEST TOP 3 ----------
vector<Contact> suggest(vector<Contact>& contacts, string keyword) {
    vector<pair<int, Contact>> scored;

    for (auto& c : contacts) {
        int score = similarity(keyword, c.name);
        scored.push_back({ score, c });
    }

    sort(scored.begin(), scored.end(),
        [](auto& a, auto& b) {
            return a.first > b.first;
        });

    vector<Contact> res;
    for (int i = 0; i < min(3, (int)scored.size()); i++) {
        res.push_back(scored[i].second);
    }

    return res;
}

// ---------- MAIN DEMO ----------
int main() {
    vector<Contact> contacts = {
        {"Nguyen Van Minh", "0901234567"},
        {"Tran Thi Minh Anh", "0912345678"},
        {"Le Minh Tuan", "0923456789"},
        {"Pham Hoang Nam", "0934567890"},
        {"Dang Minh Khoi", "0945678901"}
    };

    // ===== NAME SEARCH =====
    string keyword = "Minh";
    int comp1;
    double time1;

    auto result = searchByName(contacts, keyword, comp1, time1);

    cout << "\n🔎 Tim ten: " << keyword << "\n";

    if (!result.empty()) {
        cout << "→ Tim thay " << result.size() << " ket qua:\n";
        for (int i = 0; i < result.size(); i++) {
            cout << "   " << i + 1 << ". "
                << setw(20) << left << result[i].name
                << " - " << result[i].phone << "\n";
        }
        cout << "   (So sanh " << comp1 << "/" << contacts.size()
            << " - " << time1 << " ms)\n";
    }
    else {
        cout << "❌ Khong tim thay!\n";
        cout << "💡 Goi y:\n";
        auto s = suggest(contacts, keyword);
        for (auto& c : s)
            cout << "   - " << c.name << " - " << c.phone << "\n";
    }

    // ===== PHONE SEARCH =====
    string phone = "0912345678";
    int comp2;
    double time2;

    auto [found, ok] = searchByPhone(contacts, phone, comp2, time2);

    cout << "\n📞 Tim so: " << phone << "\n";

    if (ok) {
        cout << "→ " << found.name << " - " << found.phone << "\n";
    }
    else {
        cout << "❌ Khong tim thay so!\n";
    }

    cout << "(So sanh " << comp2 << " lan - " << time2 << " ms)\n";

    return 0;
}
int main()
{
    int a[100], n;
    do
    {
        cout << "Nhap n: " << endl;
        cin >> n;
    } while (n <= 0);
    NhapMang(a,n);
    TinhMinMaxTrungBinhTong(a, n);
    return 0;
}