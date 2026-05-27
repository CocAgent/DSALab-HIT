#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// ==========================================
// BÀI 1: LINEAR SEARCH
// ==========================================
void runBai1() {
    cout << "\n--- BAI 1: LINEAR SEARCH ---\n";
    vector<int> intArr = {4, 2, 7, 1, 9, 5, 8, 3};
    vector<string> strArr = {"apple", "banana", "cherry", "date", "elderberry"};
    
    int targetInt = 9;
    string targetStr = "cherry";
    
    // Tìm trên mảng số nguyên
    int stepsInt = 0, posInt = -1;
    for (size_t i = 0; i < intArr.size(); i++) {
        stepsInt++;
        if (intArr[i] == targetInt) {
            posInt = i;
            break;
        }
    }
    cout << "Tim so " << targetInt << " trong mang so nguyen:\n";
    if (posInt != -1) cout << "-> Thay tai vi tri " << posInt << " (So buoc: " << stepsInt << ")\n";
    else cout << "-> Khong tim thay (So buoc: " << stepsInt << ")\n";

    // Tìm trên mảng chuỗi
    int stepsStr = 0, posStr = -1;
    for (size_t i = 0; i < strArr.size(); i++) {
        stepsStr++;
        if (strArr[i] == targetStr) {
            posStr = i;
            break;
        }
    }
    cout << "Tim chuoi '" << targetStr << "' trong mang chuoi:\n";
    if (posStr != -1) cout << "-> Thay tai vi tri " << posStr << " (So buoc: " << stepsStr << ")\n";
    else cout << "-> Khong tim thay (So buoc: " << stepsStr << ")\n";
}

// ==========================================
// BÀI 2: BINARY SEARCH
// ==========================================
// Đệ quy
int binarySearchRecursive(const vector<int>& arr, int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearchRecursive(arr, left, mid - 1, x);
        return binarySearchRecursive(arr, mid + 1, right, x);
    }
    return -1;
}

// Tìm vị trí đầu tiên
int findFirstOccurrence(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Tiếp tục tìm bên trái
        } else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return result;
}

// Tìm vị trí cuối cùng
int findLastOccurrence(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; // Tiếp tục tìm bên phải
        } else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return result;
}

void runBai2() {
    cout << "\n--- BAI 2: BINARY SEARCH ---\n";
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5, 5, 6, 8};
    cout << "Mang da sap xep: ";
    for (int x : arr) cout << x << " "; cout << "\n";
    
    int target = 2;
    cout << "Tim x = " << target << "\n";
    cout << "-> Vi tri dau tien: " << findFirstOccurrence(arr, target) << "\n";
    cout << "-> Vi tri cuoi cung: " << findLastOccurrence(arr, target) << "\n";
    cout << "-> Tim bang de quy (1 vi tri bat ky): " << binarySearchRecursive(arr, 0, arr.size() - 1, target) << "\n";
}

// ==========================================
// BÀI 3: SO SÁNH HIỆU NĂNG
// ==========================================
void measureSearchTime(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i; // Tạo mảng đã sắp xếp
    
    int target = n - 1; // Tìm phần tử cuối để Linear Search tốn nhiều thời gian nhất
    
    // Linear Search
    auto startLS = high_resolution_clock::now();
    for (int i = 0; i < n; i++) { if (arr[i] == target) break; }
    auto endLS = high_resolution_clock::now();
    auto durationLS = duration_cast<nanoseconds>(endLS - startLS).count();

    // Binary Search
    auto startBS = high_resolution_clock::now();
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) break;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    auto endBS = high_resolution_clock::now();
    auto durationBS = duration_cast<nanoseconds>(endBS - startBS).count();

    cout << left << setw(15) << n << setw(20) << durationLS << " ns" << setw(20) << durationBS << " ns\n";
}

void runBai3() {
    cout << "\n--- BAI 3: SO SANH HIEU NANG ---\n";
    cout << left << setw(15) << "So phan tu (n)" << setw(23) << "Linear Search (Tệ nhất)" << setw(20) << "Binary Search\n";
    cout << string(60, '-') << "\n";
    measureSearchTime(10000);
    measureSearchTime(100000);
    measureSearchTime(1000000);
}

// ==========================================
// BÀI 4: SMART SEARCH ENGINE
// ==========================================
struct Contact {
    string name;
    string phone;
};

// Hàm tính khoảng cách Levenshtein (Dùng để tìm tên gần giống nhất)
int levenshtein(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
    return dp[m][n];
}

class PhoneBook {
private:
    vector<Contact> contacts;

public:
    PhoneBook() {
        contacts = {
            {"Nguyen Van Minh", "0901234567"},
            {"Tran Thi Minh Anh", "0912345678"},
            {"Le Minh Tuan", "0923456789"},
            {"Pham Hai Dang", "0987654321"},
            {"Vo Hoang Yen", "0933333333"}
        };
    }

    void searchByName(const string& query) {
        vector<Contact> results;
        int steps = 0;
        
        auto start = high_resolution_clock::now();
        for (const auto& c : contacts) {
            steps++;
            // Tìm kiếm mờ: Nếu tên chứa chuỗi query (không phân biệt hoa thường có thể làm thêm sau)
            if (c.name.find(query) != string::npos) {
                results.push_back(c);
            }
        }
        auto end = high_resolution_clock::now();
        double time_ms = duration<double, std::milli>(end - start).count();

        if (!results.empty()) {
            cout << "-> Tim thay " << results.size() << " ket qua:\n";
            for (size_t i = 0; i < results.size(); i++) {
                cout << "   " << i + 1 << ". " << left << setw(20) << results[i].name << "- " << results[i].phone << "\n";
            }
            cout << "   (Da so sanh " << steps << "/" << contacts.size() << " phan tu - " << fixed << setprecision(4) << time_ms << "ms)\n";
        } else {
            cout << "Khong tim thay ket qua chinh xac. Goi y cac ten gan giong:\n";
            // Sắp xếp danh bạ theo độ đo khoảng cách Levenshtein
            vector<pair<int, Contact>> suggestions;
            for (const auto& c : contacts) {
                suggestions.push_back({levenshtein(query, c.name), c});
            }
            sort(suggestions.begin(), suggestions.end(), [](const pair<int, Contact>& a, const pair<int, Contact>& b) {
                return a.first < b.first;
            });
            
            for (int i = 0; i < min(3, (int)suggestions.size()); i++) {
                cout << "   - " << suggestions[i].second.name << " (" << suggestions[i].second.phone << ")\n";
            }
        }
    }
    
    // Yêu cầu mảng đã được sort theo SDT. Để đơn giản, ta sẽ sort lại mảng ở đây.
    void searchByPhone(const string& phoneQuery) {
        vector<Contact> sortedContacts = contacts;
        sort(sortedContacts.begin(), sortedContacts.end(), [](const Contact& a, const Contact& b) {
            return a.phone < b.phone;
        });

        int left = 0, right = sortedContacts.size() - 1;
        int steps = 0;
        bool found = false;

        auto start = high_resolution_clock::now();
        while (left <= right) {
            steps++;
            int mid = left + (right - left) / 2;
            if (sortedContacts[mid].phone == phoneQuery) {
                auto end = high_resolution_clock::now();
                double time_ms = duration<double, std::milli>(end - start).count();
                cout << "-> Tim thay: " << sortedContacts[mid].name << " - " << sortedContacts[mid].phone << "\n";
                cout << "   (Da so sanh " << steps << " buoc bang Binary Search - " << fixed << setprecision(4) << time_ms << "ms)\n";
                found = true;
                break;
            } else if (sortedContacts[mid].phone < phoneQuery) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (!found) cout << "Khong tim thay so dien thoai nay.\n";
    }
};

void runBai4() {
    PhoneBook pb;
    cout << "\n--- BAI 4: SMART SEARCH ENGINE ---\n";
    string query;
    cout << "Nhap ten can tim (VD: Minh): ";
    cin.ignore();
    getline(cin, query);
    pb.searchByName(query);
    
    cout << "\nNhap so dien thoai can tim (VD: 0987654321): ";
    getline(cin, query);
    pb.searchByPhone(query);
}

// ==========================================
// HÀM MAIN - MENU TỔNG HỢP
// ==========================================
int main() {
    int mainChoice;
    do {
        cout << "\n=================================\n";
        cout << "    MENU TONG HOP TUAN 3\n";
        cout << "=================================\n";
        cout << "1. Bai 1: Linear Search\n";
        cout << "2. Bai 2: Binary Search\n";
        cout << "3. Bai 3: So sanh hieu nang\n";
        cout << "4. Bai 4: Du an Mini - Smart Search Engine\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Moi ban chon (0-4): ";
        cin >> mainChoice;

        switch(mainChoice) {
            case 1: runBai1(); break;
            case 2: runBai2(); break;
            case 3: runBai3(); break;
            case 4: runBai4(); break;
            case 0: cout << "Tam biet!\n"; break;
            default: cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }
    } while (mainChoice != 0);

    return 0;
}
