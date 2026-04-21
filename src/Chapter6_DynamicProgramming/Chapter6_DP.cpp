// ============================================================
//  Chapter6_DP.cpp
//  Quy Hoach Dong: Fibonacci, LCS, Knapsack, LIS, Coin Change,...
//  DSALab — CD Cong Thuong TP.HCM · 2025
// ============================================================
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

// ============================================================
//  PHAN 1: FIBONACCI — O(N), Space O(1)
// ============================================================
/*
 * Bai toan: Tinh F(n) = F(n-1) + F(n-2), F(0)=0, F(1)=1
 * So sanh 3 phuong phap: de quy, memoization, tabulation
 */

// 1a. De quy thuan — O(2^N) — CHAM
long long FibRecursive(int n) {
    if (n <= 1) return n;
    return FibRecursive(n-1) + FibRecursive(n-2);
}

// 1b. Top-down (Memoization) — O(N)
long long FibMemo(int n, vector<long long> &memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = FibMemo(n-1, memo) + FibMemo(n-2, memo);
}

// 1c. Bottom-up (Tabulation) — O(N), Space O(1)
long long FibDP(int n) {
    if (n <= 1) return n;
    long long prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        long long cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

// ============================================================
//  PHAN 2: LEO CAU THANG — O(N)
// ============================================================
/*
 * Bai toan: Leo N bac, moi lan leo 1 hoac 2 bac.
 * Hoi co bao nhieu cach?
 * Cong thuc: ways[n] = ways[n-1] + ways[n-2]
 */
long long ClimbStairs(int n) {
    if (n <= 2) return n;
    long long a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        long long c = a + b;
        a = b; b = c;
    }
    return b;
}

// Mo rong: leo 1, 2, hoac 3 bac
long long ClimbStairs3(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    long long a=1, b=2, c=4;
    for (int i = 4; i <= n; i++) {
        long long d = a + b + c;
        a = b; b = c; c = d;
    }
    return c;
}

// ============================================================
//  PHAN 3: LCS — Xau Con Chung Dai Nhat — O(M*N)
// ============================================================
/*
 * Longest Common Subsequence
 * Bai toan: Tim do dai xau con chung dai nhat cua s1 va s2
 * dp[i][j] = LCS cua s1[0..i-1] va s2[0..j-1]
 */
int LCS(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    return dp[m][n];
}

// Lay lai xau LCS
string GetLCS(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    // Truy vet
    string result;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            result += s1[i-1];
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(result.begin(), result.end());
    return result;
}

// ============================================================
//  PHAN 4: 0/1 KNAPSACK — Ba Lo — O(N*W)
// ============================================================
/*
 * Bai toan: N vat, tui suc chua W. Toi da hoa gia tri.
 * dp[i][j] = gia tri max dung i vat dau, suc chua j
 */
struct Item { int weight, value; string name; };

int Knapsack01(const vector<Item> &items, int W) {
    int n = items.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i-1][j];  // khong chon vat i
            if (items[i-1].weight <= j)
                dp[i][j] = max(dp[i][j],
                               items[i-1].value + dp[i-1][j - items[i-1].weight]);
        }
    }
    return dp[n][W];
}

// Lay ra cac vat duoc chon
vector<string> GetSelectedItems(const vector<Item> &items, int W) {
    int n = items.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i-1][j];
            if (items[i-1].weight <= j)
                dp[i][j] = max(dp[i][j],
                               items[i-1].value + dp[i-1][j - items[i-1].weight]);
        }

    vector<string> chosen;
    int j = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][j] != dp[i-1][j]) {
            chosen.push_back(items[i-1].name);
            j -= items[i-1].weight;
        }
    }
    return chosen;
}

// Toi uu space — chi dung O(W)
int Knapsack01_Optimized(const vector<Item> &items, int W) {
    vector<int> dp(W+1, 0);
    for (auto &item : items)
        for (int j = W; j >= item.weight; j--)
            dp[j] = max(dp[j], item.value + dp[j - item.weight]);
    return dp[W];
}

// ============================================================
//  PHAN 5: LIS — Day Con Tang Dai Nhat — O(N^2)
// ============================================================
/*
 * Longest Increasing Subsequence
 * dp[i] = do dai LIS ket thuc tai vi tri i
 */
int LIS(const vector<int> &a) {
    int n = a.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);

    return *max_element(dp.begin(), dp.end());
}

// LIS va lay ra day con
vector<int> GetLIS(const vector<int> &a) {
    int n = a.size();
    vector<int> dp(n, 1), parent(n, -1);

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
                parent[i] = j;
            }

    // Tim vi tri ket thuc
    int maxLen = *max_element(dp.begin(), dp.end());
    int idx = max_element(dp.begin(), dp.end()) - dp.begin();

    // Truy vet
    vector<int> lis;
    while (idx != -1) {
        lis.push_back(a[idx]);
        idx = parent[idx];
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

// ============================================================
//  PHAN 6: COIN CHANGE — Doi Tien Xu — O(Amount * N)
// ============================================================
/*
 * Bai toan: Doi Amount tien bang cac menh gia cho.
 * Tim so xu it nhat.
 * dp[j] = so xu it nhat de doi j dong
 */
int CoinChange(const vector<int> &coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;

    for (int j = 1; j <= amount; j++)
        for (int c : coins)
            if (c <= j && dp[j-c] != INT_MAX)
                dp[j] = min(dp[j], dp[j-c] + 1);

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Dem so cach doi tien (khac bai tren — dem cach)
long long CoinWays(const vector<int> &coins, int amount) {
    vector<long long> dp(amount+1, 0);
    dp[0] = 1;
    for (int c : coins)
        for (int j = c; j <= amount; j++)
            dp[j] += dp[j-c];
    return dp[amount];
}

// ============================================================
//  PHAN 7: DUONG DI TREN LUOI — O(M*N)
// ============================================================
/*
 * Bai toan: Luoi M×N, xuat phat (0,0), den (M-1,N-1).
 * Chi di phai hoac xuong. Dem so duong di.
 */
long long GridPaths(int m, int n) {
    vector<vector<long long>> dp(m, vector<long long>(n, 1));
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[m-1][n-1];
}

// Luoi co cac o bi chan (obstacle=1)
long long GridPathsWithObstacles(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] == 1) return 0;
    vector<vector<long long>> dp(m, vector<long long>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < m; i++)
        dp[i][0] = (grid[i][0] == 0) ? dp[i-1][0] : 0;
    for (int j = 1; j < n; j++)
        dp[0][j] = (grid[0][j] == 0) ? dp[0][j-1] : 0;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = (grid[i][j] == 1) ? 0 : dp[i-1][j] + dp[i][j-1];
    return dp[m-1][n-1];
}

// ============================================================
//  PHAN 8: XAU CON PALINDROME DAI NHAT (LPS) — O(N^2)
// ============================================================
/*
 * Longest Palindromic Subsequence
 * dp[i][j] = do dai palindrome dai nhat trong s[i..j]
 */
int LPS(const string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) dp[i][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n-len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && len == 2) dp[i][j] = 2;
            else if (s[i] == s[j])        dp[i][j] = dp[i+1][j-1] + 2;
            else                           dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

// ============================================================
//  PHAN 9: EDIT DISTANCE (Levenshtein) — O(M*N)
// ============================================================
/*
 * Bai toan: So buoc chinh sua it nhat de bien s1 thanh s2
 * (them, xoa, thay the 1 ky tu)
 */
int EditDistance(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({dp[i-1][j],   // xoa
                                    dp[i][j-1],   // them
                                    dp[i-1][j-1]});// thay the
        }
    return dp[m][n];
}

// ============================================================
//  IN TIEU DE
// ============================================================
void Header(const string &s) {
    cout << "\n" << string(60, '=') << "\n"
         << "  " << s << "\n"
         << string(60, '=') << "\n";
}

// ============================================================
//  DEMO
// ============================================================
void DemoFibonacci() {
    Header("BAI 1: FIBONACCI");
    cout << "  n   Fib(n)\n  " << string(20, '-') << "\n";
    for (int n : {0,1,2,5,10,20,30,40,50}) {
        vector<long long> memo(n+2, -1);
        cout << "  " << setw(3) << n << "   " << FibDP(n) << "\n";
    }
}

void DemoClimbStairs() {
    Header("BAI 2: LEO CAU THANG");
    cout << "  N   Cach(1-2 bac)   Cach(1-2-3 bac)\n";
    cout << "  " << string(42, '-') << "\n";
    for (int n = 1; n <= 10; n++)
        cout << "  " << setw(2) << n << "       "
             << setw(8) << ClimbStairs(n) << "           "
             << setw(8) << ClimbStairs3(n) << "\n";
}

void DemoLCS() {
    Header("BAI 3: XAU CON CHUNG DAI NHAT (LCS)");
    vector<pair<string,string>> tests = {
        {"ABCBDAB", "BDCAB"},
        {"AGGTAB",  "GXTXAYB"},
        {"hello",   "hallo"},
    };
    for (auto &[s1, s2] : tests) {
        cout << "  s1 = \"" << s1 << "\"\n";
        cout << "  s2 = \"" << s2 << "\"\n";
        cout << "  LCS = \"" << GetLCS(s1, s2) << "\" (do dai = " << LCS(s1, s2) << ")\n\n";
    }
}

void DemoKnapsack() {
    Header("BAI 4: BAI TOAN BA LO (0/1 Knapsack)");
    vector<Item> items = {
        {2, 6,  "Laptop"},
        {2, 10, "Camera"},
        {3, 12, "Sach"},
        {1, 3,  "But"},
        {4, 8,  "Tablet"}
    };
    int W = 6;

    cout << "  Danh sach vat:\n";
    cout << "  " << string(40, '-') << "\n";
    cout << "  " << setw(12) << "Ten" << setw(10) << "Can nang" << setw(10) << "Gia tri\n";
    cout << "  " << string(40, '-') << "\n";
    for (auto &item : items)
        cout << "  " << setw(12) << item.name
             << setw(10) << item.weight
             << setw(10) << item.value << "\n";

    cout << "\n  Suc chua tui: " << W << " kg\n";
    cout << "  Gia tri toi da: " << Knapsack01(items, W) << "\n";

    auto chosen = GetSelectedItems(items, W);
    cout << "  Cac vat duoc chon: ";
    for (auto &s : chosen) cout << s << " ";
    cout << "\n";
}

void DemoLIS() {
    Header("BAI 5: DAY CON TANG DAI NHAT (LIS)");
    vector<vector<int>> tests = {
        {10, 9, 2, 5, 3, 7, 101, 18},
        {0, 1, 0, 3, 2, 3},
        {3, 10, 2, 1, 20, 5, 4, 23, 3, 11}
    };
    for (auto &a : tests) {
        cout << "  Day: [ ";
        for (int x : a) cout << x << " ";
        cout << "]\n";
        auto lis = GetLIS(a);
        cout << "  LIS: [ ";
        for (int x : lis) cout << x << " ";
        cout << "] (do dai = " << lis.size() << ")\n\n";
    }
}

void DemoCoinChange() {
    Header("BAI 6: DOI TIEN XU");
    vector<int> coins = {1, 2, 5, 10};
    vector<int> amounts = {0, 3, 11, 27, 100};

    cout << "  Menh gia: 1, 2, 5, 10 dong\n\n";
    cout << "  " << setw(10) << "Amount" << setw(12) << "So xu it nhat" << setw(12) << "So cach doi\n";
    cout << "  " << string(40, '-') << "\n";
    for (int a : amounts)
        cout << "  " << setw(10) << a
             << setw(12) << CoinChange(coins, a)
             << setw(12) << CoinWays(coins, a) << "\n";
}

void DemoGrid() {
    Header("BAI 7: DUONG DI TREN LUOI");
    cout << "  So duong di tu (0,0) den (M-1,N-1) chi di phai/xuong:\n\n";
    cout << "  " << setw(6) << "M\\N";
    for (int n = 1; n <= 7; n++) cout << setw(8) << n;
    cout << "\n  " << string(64, '-') << "\n";
    for (int m = 1; m <= 7; m++) {
        cout << "  " << setw(4) << m << "  ";
        for (int n = 1; n <= 7; n++)
            cout << setw(8) << GridPaths(m, n);
        cout << "\n";
    }
}

void DemoLPS_EditDist() {
    Header("BAI 8 & 9: LPS + EDIT DISTANCE");

    string s = "GEEKSFORGEEKS";
    cout << "  Xau: \"" << s << "\"\n";
    cout << "  Palindrome dai nhat: " << LPS(s) << " ky tu\n\n";

    vector<pair<string,string>> pairs = {
        {"kitten", "sitting"},
        {"sunday", "saturday"},
        {"abc", "abc"},
        {"", "hello"}
    };
    cout << "  Edit Distance (Levenshtein):\n";
    cout << "  " << string(45, '-') << "\n";
    for (auto &[s1, s2] : pairs)
        cout << "  \"" << setw(10) << s1 << "\" -> \""
             << setw(10) << s2 << "\": "
             << EditDistance(s1, s2) << " buoc\n";
}

void DemoBaiTapTongHop() {
    Header("BAI TAP TONG HOP — LICH TRINH HOC (DP)");
    /*
     * Bai toan: Co N bai hoc, moi bai co thoi gian t[i] va diem u[i].
     * Tong thoi gian <= T. Tim lich trinh dat diem cao nhat.
     * (Day la bai Knapsack bien the)
     */
    struct Lesson { string name; int time, score; };
    vector<Lesson> lessons = {
        {"Chuong 1",  1, 5},
        {"Chuong 2",  2, 8},
        {"Chuong 3",  3, 12},
        {"Chuong 4",  3, 10},
        {"Chuong 5",  4, 15},
        {"Chuong 6",  3, 11},
    };
    int T = 8;  // tong thoi gian cho phep

    vector<Item> items;
    for (auto &l : lessons)
        items.push_back({l.time, l.score, l.name});

    cout << "  Tong thoi gian cho phep: " << T << " gio\n";
    cout << "  Diem toi da dat duoc: " << Knapsack01(items, T) << "\n";

    auto chosen = GetSelectedItems(items, T);
    cout << "  Cac bai nen hoc: ";
    for (auto &s : chosen) cout << "[" << s << "] ";
    cout << "\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "============================================================\n";
    cout << "  CHUONG 6: QUY HOACH DONG (DYNAMIC PROGRAMMING)\n";
    cout << "  Fibonacci | LCS | Knapsack | LIS | Coin | Grid | DP...\n";
    cout << "============================================================\n";

    DemoFibonacci();
    DemoClimbStairs();
    DemoLCS();
    DemoKnapsack();
    DemoLIS();
    DemoCoinChange();
    DemoGrid();
    DemoLPS_EditDist();
    DemoBaiTapTongHop();

    cout << "\n============================================================\n";
    cout << "  HOAN THANH CHUONG 6!\n";
    cout << "============================================================\n";
    return 0;
}
