// ============================================================
// ch2_sort.cpp  —  Chapter 2: Search & Sort
// Compile: g++ -std=c++17 ch2_sort.cpp -o ch2 && ./ch2
// ============================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <functional>
using namespace std;
using Clock = chrono::high_resolution_clock;

// ── Helpers ──────────────────────────────────────────────────
void print_arr(vector<int>& a, string lbl=""){
    if(!lbl.empty()) cout << lbl << ": ";
    cout << "[";
    for(int i=0;i<(int)a.size();i++){ cout<<a[i]; if(i+1<(int)a.size()) cout<<","; }
    cout << "]\n";
}
bool is_sorted_asc(vector<int>& a){
    for(int i=1;i<(int)a.size();i++) if(a[i]<a[i-1]) return false; return true;
}
double bench_ms(function<void()> fn){
    auto t=Clock::now(); fn();
    return chrono::duration<double,milli>(Clock::now()-t).count();
}

// ════════════════════════════════════════════════════════════
// SEARCHING
// ════════════════════════════════════════════════════════════

// Linear Search — O(n)
int linear_search(vector<int>& a, int t){
    for(int i=0;i<(int)a.size();i++) if(a[i]==t) return i;
    return -1;
}

// Binary Search — O(log n), cần mảng sorted
int binary_search_it(vector<int>& a, int t){
    int lo=0, hi=a.size()-1;
    int step=0;
    while(lo<=hi){
        ++step;
        int m = lo+(hi-lo)/2;
        cout << "  step " << step << ": lo=" << lo << " hi=" << hi
             << " mid=" << m << " a[mid]=" << a[m] << "\n";
        if(a[m]==t){ cout << "  FOUND at " << m << "\n"; return m; }
        a[m]<t ? lo=m+1 : hi=m-1;
    }
    cout << "  NOT FOUND\n"; return -1;
}

// ════════════════════════════════════════════════════════════
// SORTING
// ════════════════════════════════════════════════════════════

// Bubble Sort — O(n²)  stable
void bubble_sort(vector<int>& a, bool verbose=false){
    int n=a.size(), swaps=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]); ++swaps;
                if(verbose){ print_arr(a,"  swap"); }
            }
        }
    }
    if(verbose) cout << "  Total swaps: " << swaps << "\n";
}

// Selection Sort — O(n²)  not stable
void selection_sort(vector<int>& a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int mi=i;
        for(int j=i+1;j<n;j++) if(a[j]<a[mi]) mi=j;
        swap(a[i],a[mi]);
    }
}

// Insertion Sort — O(n²) worst, O(n) best (nearly-sorted)
void insertion_sort(vector<int>& a){
    int n=a.size();
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){ a[j+1]=a[j]; --j; }
        a[j+1]=key;
    }
}

// Quick Sort — O(n log n) avg, O(n²) worst
void quick_sort(vector<int>& a, int lo, int hi, bool verbose=false){
    if(lo>=hi) return;
    int pivot=a[hi], i=lo-1;
    for(int j=lo;j<hi;j++) if(a[j]<=pivot) swap(a[++i],a[j]);
    swap(a[i+1],a[hi]); int p=i+1;
    if(verbose) cout << "  pivot=" << pivot << " at index=" << p << "\n";
    quick_sort(a,lo,p-1,verbose);
    quick_sort(a,p+1,hi,verbose);
}

// Merge Sort — O(n log n)  stable
void merge_sort(vector<int>& a, int l, int r){
    if(l>=r) return;
    int m=l+(r-l)/2;
    merge_sort(a,l,m); merge_sort(a,m+1,r);
    vector<int> t; int i=l,j=m+1;
    while(i<=m&&j<=r) t.push_back(a[i]<=a[j]?a[i++]:a[j++]);
    while(i<=m) t.push_back(a[i++]);
    while(j<=r) t.push_back(a[j++]);
    for(int k=l;k<=r;k++) a[k]=t[k-l];
}

int main(){
    cout << "╔══════════════════════════════════════╗\n"
         << "║  Chapter 2: Search & Sort            ║\n"
         << "╚══════════════════════════════════════╝\n\n";

    // ── Demo Binary Search step-by-step ──────────────────────
    cout << "=== Binary Search (step-by-step) ===\n";
    vector<int> sv = {1,3,5,7,9,11,13,15,17};
    print_arr(sv,"Array");
    cout << "Tim 11:\n"; binary_search_it(sv,11);
    cout << "Tim 6:\n";  binary_search_it(sv,6);

    // ── Demo Bubble Sort step-by-step ────────────────────────
    cout << "\n=== Bubble Sort (step-by-step) ===\n";
    vector<int> bv = {5,2,8,1,9};
    print_arr(bv,"Before");
    bubble_sort(bv, true);
    print_arr(bv,"After ");

    // ── Demo Quick Sort ───────────────────────────────────────
    cout << "\n=== Quick Sort (steps) ===\n";
    vector<int> qv = {64,25,12,22,11,90};
    print_arr(qv,"Before");
    quick_sort(qv,0,qv.size()-1,true);
    print_arr(qv,"After ");

    // ── Benchmark: tất cả thuật toán ─────────────────────────
    cout << "\n=== Benchmark (n=8000) ===\n";
    vector<int> data(8000);
    generate(data.begin(),data.end(),[]{ return rand()%100000; });
    cout << left;

    auto run = [&](string name, function<void(vector<int>)> fn){
        double ms = bench_ms([&]{ fn(data); });
        cout << setw(18) << name << setprecision(2) << fixed << ms << " ms"
             << (ms>100?" (slow!)":"") << "\n";
    };
    run("Bubble Sort",    [](vector<int> a){ int n=a.size(); for(int i=0;i<n-1;i++) for(int j=0;j<n-i-1;j++) if(a[j]>a[j+1]) swap(a[j],a[j+1]); });
    run("Selection Sort", [](vector<int> a){ int n=a.size(); for(int i=0;i<n-1;i++){int mi=i;for(int j=i+1;j<n;j++) if(a[j]<a[mi]) mi=j;swap(a[i],a[mi]);} });
    run("Insertion Sort", [](vector<int> a){ int n=a.size();for(int i=1;i<n;i++){int k=a[i],j=i-1;while(j>=0&&a[j]>k){a[j+1]=a[j];j--;}a[j+1]=k;} });
    run("Merge Sort",     [](vector<int> a){ function<void(vector<int>&,int,int)> ms=[&](auto& v,int l,int r){if(l>=r)return;int m=l+(r-l)/2;ms(v,l,m);ms(v,m+1,r);vector<int>t;int i=l,j=m+1;while(i<=m&&j<=r)t.push_back(v[i]<=v[j]?v[i++]:v[j++]);while(i<=m)t.push_back(v[i++]);while(j<=r)t.push_back(v[j++]);for(int k=l;k<=r;k++)v[k]=t[k-l];};ms(a,0,a.size()-1); });
    run("Quick Sort",     [](vector<int> a){ function<void(vector<int>&,int,int)> qs=[&](auto& v,int lo,int hi){if(lo>=hi)return;int p=v[hi],i=lo-1;for(int j=lo;j<hi;j++)if(v[j]<=p)swap(v[++i],v[j]);swap(v[i+1],v[hi]);int pi=i+1;qs(v,lo,pi-1);qs(v,pi+1,hi);};qs(a,0,a.size()-1); });
    run("std::sort",      [](vector<int> a){ sort(a.begin(),a.end()); });

    // ── Correctness check ─────────────────────────────────────
    cout << "\n=== Correctness check ===\n";
    auto test = data;
    auto expected = test; sort(expected.begin(),expected.end());
    vector<int> qs_arr=test, ms_arr=test;
    quick_sort(qs_arr,0,qs_arr.size()-1);
    merge_sort(ms_arr,0,ms_arr.size()-1);
    cout << "QuickSort correct: " << (qs_arr==expected?"YES":"NO") << "\n";
    cout << "MergeSort correct: " << (ms_arr==expected?"YES":"NO") << "\n";

    cout << "\n=== Bài tập ===\n"
         << "Easy  : Implement binary search recursive\n"
         << "Medium: Sap xep mang chi chua 0,1,2 (Dutch National Flag)\n"
         << "Hard  : Tim Kth largest bang QuickSelect O(n) avg\n";
    return 0;
}
