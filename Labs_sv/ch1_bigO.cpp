// ============================================================
// ch1_bigO.cpp  —  Chapter 1: Big-O & Recursion
// Compile: g++ -std=c++17 ch1_bigO.cpp -o ch1 && ./ch1
// ============================================================
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using Clock = chrono::high_resolution_clock;

double elapsed_ms(Clock::time_point t0){
    return chrono::duration<double,milli>(Clock::now()-t0).count();
}

// ── O(1): không quan tâm n ───────────────────────────────────
int  get_first(vector<int>& a){ return a[0]; }

// ── O(log n): chia đôi mỗi bước ─────────────────────────────
int bin_search(vector<int>& a, int t){
    int lo=0, hi=a.size()-1;
    while(lo<=hi){
        int m = lo+(hi-lo)/2;
        if(a[m]==t) return m;
        a[m]<t ? lo=m+1 : hi=m-1;
    }
    return -1;
}

// ── O(n): duyệt toàn bộ ─────────────────────────────────────
long linear_sum(vector<int>& a){ long s=0; for(int x:a) s+=x; return s; }

// ── O(n²): hai vòng lồng ────────────────────────────────────
void bubble_sort(vector<int> a){
    int n=a.size();
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
}

// ── O(2^n): Fibonacci ngây thơ — CHỈ dùng với n nhỏ! ────────
long fib_calls = 0;
long fib_naive(int n){ ++fib_calls; return n<=1 ? n : fib_naive(n-1)+fib_naive(n-2); }

// ── O(n): Fibonacci memoization ─────────────────────────────
long fib_memo(int n, vector<long>& dp){
    if(n<=1) return n;
    if(dp[n]) return dp[n];
    return dp[n] = fib_memo(n-1,dp) + fib_memo(n-2,dp);
}

// ── Bảng lý thuyết ───────────────────────────────────────────
void print_theory(int n){
    cout << "\n=== Big-O Theory (n=" << n << ") ===\n";
    cout << left << setw(14) << "Notation"
         << setw(14) << "Operations"
         << "Example\n";
    cout << string(45,'-') << "\n";
    auto row = [&](string name, long ops, string ex){
        cout << setw(14) << name << setw(14) << ops << ex << "\n";
    };
    row("O(1)",           1,                  "Array index");
    row("O(log n)",       (long)log2(n),      "Binary search");
    row("O(n)",           n,                  "Linear scan");
    row("O(n log n)",     (long)(n*log2(n)),  "Merge sort");
    row("O(n^2)",         (long)n*n,          "Bubble sort");
    row("O(2^n)",         n<25?(1L<<n):-1,    "Fib naive (n<25 only)");
}

// ── Demo đệ quy: call tree factorial ─────────────────────────
long factorial(int n, int depth=0){
    cout << string(depth*2,' ') << "factorial(" << n << ")";
    if(n<=1){ cout << " = 1  [base case]\n"; return 1; }
    cout << "\n";
    long r = n * factorial(n-1, depth+1);
    cout << string(depth*2,' ') << "= " << r << "\n";
    return r;
}

int main(){
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║  Chapter 1: Big-O & Recursion        ║\n";
    cout << "╚══════════════════════════════════════╝\n";

    // Bảng lý thuyết
    print_theory(1000);

    // Benchmark thực tế
    cout << "\n=== Benchmark thực tế ===\n";
    vector<int> data(10000);
    iota(data.begin(), data.end(), 0);       // sorted cho bin_search

    auto t = Clock::now();
    get_first(data);
    cout << "O(1)  get_first:   " << fixed << setprecision(4) << elapsed_ms(t) << " ms\n";

    t = Clock::now();
    for(int i=0;i<1000;i++) bin_search(data, 5000);
    cout << "O(log n) x1000:    " << elapsed_ms(t) << " ms\n";

    t = Clock::now();
    linear_sum(data);
    cout << "O(n)  linear_sum:  " << elapsed_ms(t) << " ms\n";

    t = Clock::now();
    bubble_sort(data);
    cout << "O(n²) bubble:      " << elapsed_ms(t) << " ms  (WARNING: slow!)\n";

    // Fibonacci so sánh
    cout << "\n=== Fibonacci: naive vs memo ===\n";
    cout << left << setw(6) << "n"
         << setw(14) << "naive calls"
         << "memo calls\n";
    cout << string(35,'-') << "\n";
    for(int n : {5,10,15,20,25,30}){
        fib_calls = 0;
        long r = fib_naive(n);
        long nc = fib_calls;
        vector<long> dp(n+1,0);
        cout << setw(6) << n << setw(14) << nc << "~" << n << "\n";
        (void)r;
    }

    // Call tree factorial
    cout << "\n=== Factorial call tree (n=4) ===\n";
    factorial(4);

    cout << "\n=== Bài tập ===\n"
         << "Easy  : Viết ham dem so chu so cua n (de quy)\n"
         << "Medium: Tinh x^n bang de quy O(log n) thay vi O(n)\n"
         << "Hard  : Sinh tat ca hoan vi cua mang {1,2,3}\n";
    return 0;
}
