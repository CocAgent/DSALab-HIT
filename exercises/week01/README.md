
# Tuần 1: Tổng Quan C++ & Big-O — Bài tập

## 🎯 Mục tiêu tuần này
Hiểu Big-O, phân tích độ phức tạp, ôn tập C++ cơ bản.

---

### Bài 1: Phân tích Big-O ⭐ 2125110152 nguyễn trí công
Xác định Big-O của 10 đoạn code C++ cho trước. Giải thích tại sao.
int getElement(int arr[], int i) {
    return arr[i]; // truy cập trực tiếp
}
//Tại sao O(1)? Truy cập phần tử mảng theo chỉ số là phép tính địa chỉ bộ nhớ trực tiếp: địa_chỉ = base + i × sizeof(int). Không có vòng lặp, không phụ thuộc vào kích thước mảng n. Số bước thực hiện luôn là hằng số.

int binarySearch(int arr[], int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
//Tại sao O(log n)? Mỗi lần lặp, không gian tìm kiếm bị chia đôi. Với n = 1.000.000 phần tử, chỉ cần tối đa ~20 bước (log₂ 1.000.000 ≈ 20). Số lần lặp = log₂(n).

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {  // duyệt 1 lần
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}
//Tại sao O(n)? Vòng lặp duyệt qua mỗi phần tử đúng một lần. Số phép so sánh = n − 1. Khi n tăng gấp đôi, thời gian chạy cũng tăng gấp đôi — tỉ lệ tuyến tính.

void printPairs(int arr[], int n) {
    for (int i = 0; i < n; i++)        // n lần
        for (int j = 0; j < n; j++)    // n lần
            cout << arr[i] << "," << arr[j] << "
";
}
//Tại sao O(n²)? Vòng lặp ngoài chạy n lần, vòng lặp trong cũng chạy n lần → tổng số lần thực thi phần thân = n × n = n². Đây là dấu hiệu điển hình của 2 vòng lặp lồng nhau duyệt cùng tập dữ liệu.

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}
//Tại sao O(n²)? Tổng số lần so sánh = (n−1) + (n−2) + … + 1 = n(n−1)/2. Bỏ hệ số và hằng số, ta còn O(n²). Dù vòng trong ngắn dần, bậc tăng trưởng vẫn là bậc hai.

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);    // chia đôi: log n tầng
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);     // merge: O(n) mỗi tầng
}
//Tại sao O(n log n)? Cây đệ quy có log n tầng (mỗi tầng chia đôi mảng). Tại mỗi tầng, hàm merge() xử lý tổng cộng n phần tử. Tổng = n × log n.

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);  // 2 nhánh đệ quy
}
//Tại sao O(2ⁿ)? Mỗi lời gọi sinh ra 2 lời gọi con. Cây đệ quy có độ sâu n và gần như đầy đủ → tổng số node ≈ 2ⁿ. Đây là độ phức tạp cực kỳ tệ — fib(50) cần ~1.000 tỷ phép tính!

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)  // chỉ đến √n
        if (n % i == 0) return false;
    return true;
}
//Tại sao O(√n)? Nếu n có ước số d > √n thì n/d < √n đã được kiểm tra rồi — không cần kiểm tra tiếp. Do đó vòng lặp chỉ chạy đến √n, tức khoảng √n lần lặp.

bool hasCommon(int A[], int a, int B[], int b) {
    for (int i = 0; i < a; i++)    // a lần
        for (int j = 0; j < b; j++)  // b lần
            if (A[i] == B[j]) return true;
    return false;
}
//Tại sao O(a × b) chứ không phải O(n²)? Hai mảng có kích thước khác nhau (a và b). Không thể gộp làm một biến n. Nếu a ≈ b thì O(a×b) ≈ O(n²), nhưng phải giữ nguyên hai biến để chính xác.

int countBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);  // xóa bit 1 thấp nhất
        count++;
    }
    return count;
}
//Tại sao O(log n)? Số n có tối đa ⌊log₂ n⌋ + 1 bit nhị phân. Mỗi lần lặp, phép n & (n−1) xóa đúng một bit 1 → số lần lặp = số bit 1 ≤ tổng số bit = O(log n).

### Bài 2: Đo thời gian thực tế ⭐⭐2125110152 nguyễn trí công
Dùng `chrono` đo thời gian chạy của O(n), O(n²), O(log n) với n = 1.000 → 100.000. In bảng kết quả.

#include <chrono>
using namespace std::chrono;

auto t0 = high_resolution_clock::now();
// ... code cần đo ...
auto t1 = high_resolution_clock::now();

auto elapsed = duration_cast<microseconds>(t1 - t0).count();

### Bài 3: Tối ưu hàm ⭐⭐ 2125110152 nguyễn trí công
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian.
Cho 3 hàm O(n²) — tối ưu xuống O(n) hoặc O(n log n). Chứng minh bằng cách đo thời gian. Trước — O(n²) int subSum_slow(vector& a, int k) { int cnt = 0, n = a.size(); for (int i = 0; i < n; i++) { int s = 0; for (int j = i; j < n; j++) { s += a[j]; if (s == k) cnt++; } } return cnt; } Sau — O(n) dùng prefix sum + hash map int subSum_fast(vector& a, int k) { unordered_map<int,int> freq; freq[0] = 1; int cnt = 0, prefix = 0; for (int x : a) { prefix += x; cnt += freq[prefix - k]; freq[prefix]++; } return cnt; }



### Bài 4: 🔥 Dự Án Mini — Big-O Benchmark Tool ⭐⭐⭐ 2125110152 nguyễn trí công
> **Cảm hứng:** [algorithm-visualizer.org](https://algorithm-visualiSzer.org)

Viết chương trình **BenchmarkTool** hiển thị bảng so sánh tốc độ các thuật toán:
```
╔══════════════╦══════════╦══════════╦══════════╗
║   Thuật toán ║  n=1000  ║  n=10000 ║ n=100000 ║
╠══════════════╬══════════╬══════════╬══════════╣
║    O(1)      ║  0.001ms ║  0.001ms ║  0.001ms ║
║    O(log n)  ║  0.003ms ║  0.004ms ║  0.005ms ║
║    O(n)      ║  0.12ms  ║  1.2ms   ║  12ms    ║
║    O(n²)     ║  8ms     ║  800ms   ║  80000ms ║
╚══════════════╩══════════╩══════════╩══════════╝
```

**Yêu cầu:** dùng `std::chrono`, hiển thị bảng căn chỉnh đẹp, xuất ra file `benchmark.txt`.

---
📁 Tham khảo: `Chuong1_TongQuan/Chuong1_TongQuan.cpp`


#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace chrono;

volatile int sink;

void algo_O1(const vector<int>& a)     { sink = a[0]; }

void algo_OlogN(const vector<int>& a) {
    int lo=0, hi=(int)a.size()-1, target=a[a.size()/2];
    while(lo<=hi){ int mid=(lo+hi)/2;
        if(a[mid]==target){sink=mid;break;}
        else if(a[mid]<target) lo=mid+1; else hi=mid-1; }
}

void algo_ON(const vector<int>& a) {
    int mx=a[0]; for(int x:a) if(x>mx) mx=x; sink=mx;
}

void algo_ONlogN(vector<int> a) { sort(a.begin(),a.end()); sink=a[0]; }

void algo_ON2(vector<int> a) {
    int n=a.size();
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
    sink=a[0];
}

double measure_us(function<void()> fn, int repeat) {
    fn();
    double total=0;
    for(int r=0;r<repeat;r++){
        auto t0=high_resolution_clock::now();
        fn();
        auto t1=high_resolution_clock::now();
        total+=duration<double,micro>(t1-t0).count();
    }
    return total/repeat;
}

string fmt_time(double us) {
    ostringstream oss;
    if     (us < 1.0)    oss<<fixed<<setprecision(3)<<us*1000<<" ns";
    else if(us < 1000.0) oss<<fixed<<setprecision(3)<<us<<" us";
    else                 oss<<fixed<<setprecision(3)<<us/1000.0<<" ms";
    return oss.str();
}

// Safe center: pads with spaces, works with pure ASCII strings only
string center(const string& s, int w) {
    int len=(int)s.size();
    if(len>=w) return s.substr(0,w);
    int lp=(w-len)/2, rp=w-len-lp;
    return string(lp,' ')+s+string(rp,' ');
}

void print_table(ostream& out, const vector<int>& ns,
                 const vector<string>& labels,
                 const vector<vector<double>>& times) {
    const int W0=12, WN=14;
    // hline
    auto hline=[&](char c){
        out<<'+'; out<<string(W0+2,c);
        for(int i=0;i<(int)ns.size();i++){ out<<'+'; out<<string(WN+2,c); }
        out<<"+\n";
    };

    hline('=');
    out<<"| "<<center("Algorithm",W0)<<" ";
    for(int n:ns) out<<"| "<<center("n="+to_string(n),WN)<<" ";
    out<<"|\n";
    hline('=');

    for(int i=0;i<(int)labels.size();i++){
        out<<"| "<<center(labels[i],W0)<<" ";
        for(int j=0;j<(int)ns.size();j++){
            string t=(times[i][j]<0)?"too slow*":fmt_time(times[i][j]);
            out<<"| "<<center(t,WN)<<" ";
        }
        out<<"|\n";
        if(i+1<(int)labels.size()) hline('-');
    }
    hline('=');
}

int main(){
    srand(42);
    vector<int> ns={1000,10000,100000};
    vector<string> labels={"O(1)","O(log n)","O(n)","O(n log n)","O(n^2)"};
    vector<vector<double>> times(5,vector<double>(3,-1.0));

    for(int j=0;j<(int)ns.size();j++){
        int n=ns[j];
        vector<int> sarr(n), rarr(n);
        for(int i=0;i<n;i++) sarr[i]=i*2;
        for(int i=0;i<n;i++) rarr[i]=rand()%1000000;

        times[0][j]=measure_us([&](){ algo_O1(rarr);      }, 500);
        times[1][j]=measure_us([&](){ algo_OlogN(sarr);   }, 500);
        times[2][j]=measure_us([&](){ algo_ON(rarr);       },  30);
        times[3][j]=measure_us([&](){ algo_ONlogN(rarr);  },  20);
        if(n<=10000)
            times[4][j]=measure_us([&](){ algo_ON2(rarr); },   5);
    }

    // Print to stdout
    cout<<"\n";
    cout<<"+----------------------------------------------------------+\n";
    cout<<"|       Big-O Benchmark Tool  --  std::chrono             |\n";
    cout<<"|  Compiler: g++ -O0  |  Averaged over multiple runs      |\n";
    cout<<"+----------------------------------------------------------+\n\n";
    print_table(cout, ns, labels, times);
    cout<<"\n";
    cout<<"Notes:\n";
    cout<<"  O(1)      : array access (a[0])\n";
    cout<<"  O(log n)  : binary search on sorted array\n";
    cout<<"  O(n)      : linear scan for max element\n";
    cout<<"  O(n log n): std::sort (introsort)\n";
    cout<<"  O(n^2)    : bubble sort  [n=100000 est. > 1 hour]\n\n";

    // Write to file
    ofstream fout("/home/claude/benchmark.txt");
    fout<<"+----------------------------------------------------------+\n";
    fout<<"|       Big-O Benchmark Tool  --  std::chrono             |\n";
    fout<<"|  Compiler: g++ -O0  |  Averaged over multiple runs      |\n";
    fout<<"+----------------------------------------------------------+\n\n";
    print_table(fout, ns, labels, times);
    fout<<"\nNotes:\n";
    fout<<"  O(1)      : array access (a[0])\n";
    fout<<"  O(log n)  : binary search on sorted array\n";
    fout<<"  O(n)      : linear scan for max element\n";
    fout<<"  O(n log n): std::sort (introsort)\n";
    fout<<"  O(n^2)    : bubble sort  [n=100000 est. > 1 hour]\n";
    fout.close();

    cout<<"=> Output saved to: benchmark.txt\n\n";
    return 0;
}
