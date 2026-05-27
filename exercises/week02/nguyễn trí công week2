Bài 1: Mảng cơ bản ⭐
Nhập mảng n phần tử. Tính min, max, trung bình, tổng. Không dùng STL.
#include <iostream>
using namespace std;

void nhapMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

void inMang(int arr[], int n) {
    cout << "Mang: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
}

int timMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int timMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

long long tinhTong(int arr[], int n) {
    long long tong = 0;
    for (int i = 0; i < n; i++)
        tong += arr[i];
    return tong;
}

double tinhTrungBinh(int arr[], int n) {
    return (double)tinhTong(arr, n) / n;
}

int main() {
    int n;
    cout << "Nhap so phan tu n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n phai lon hon 0!" << endl;
        return 1;
    }

    int arr[1000]; // mảng tĩnh, tối đa 1000 phần tử
    nhapMang(arr, n);

    inMang(arr, n);

    cout << "Min     : " << timMin(arr, n)       << endl;
    cout << "Max     : " << timMax(arr, n)       << endl;
    cout << "Tong    : " << tinhTong(arr, n)     << endl;
    cout << "Trung binh: " << tinhTrungBinh(arr, n) << endl;

    return 0;
}


Bài 2: Mảng 2D ⭐⭐
Nhân 2 ma trận n×n. Tính định thức ma trận 3×3. Hiển thị đẹp.
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 10;

void inMaTran(int a[][MAX], int n, const char* ten) {
    cout << "\n  " << ten << ":\n  +";
    for (int j = 0; j < n; j++) cout << "------+";
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << "  |";
        for (int j = 0; j < n; j++) cout << setw(5) << a[i][j] << " |";
        cout << "\n  +";
        for (int j = 0; j < n; j++) cout << "------+";
        cout << "\n";
    }
}

void nhapMaTran(int a[][MAX], int n, const char* ten) {
    cout << "\n  Nhap " << ten << " (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "    [" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
}

void nhanMaTran(int a[][MAX], int b[][MAX], int c[][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

int dinhThuc3x3(int a[][MAX]) {
    return a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
          -a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
          +a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
}

int main() {
    int n, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    // --- Nhân ma trận ---
    cout << "Nhap n: "; cin >> n;
    nhapMaTran(A, n, "A"); nhapMaTran(B, n, "B");
    nhanMaTran(A, B, C, n);
    inMaTran(A, n, "A"); inMaTran(B, n, "B"); inMaTran(C, n, "C = A x B");

    // --- Định thức 3x3 ---
    int M[MAX][MAX];
    nhapMaTran(M, 3, "M (3x3)");
    inMaTran(M, 3, "M");
    int det = dinhThuc3x3(M);
    cout << "\n  det(M) = " << det
         << (det == 0 ? "  => SUY BIEN\n" : "  => KHA NGHICH\n");

    return 0;
}

Bài 3: Con trỏ & cấp phát động ⭐⭐
Cài đặt mảng động tự resize (như std::vector đơn giản). Hỗ trợ push_back, pop_back, at(i).
#include <iostream>
using namespace std;

struct MyVector {
    int* data;
    int  size, capacity;
};

void init(MyVector& v) {
    v.size = 0; v.capacity = 2;
    v.data = new int[2];
}

void destroy(MyVector& v) {
    delete[] v.data;
    v.data = nullptr; v.size = v.capacity = 0;
}

void resize(MyVector& v) {
    v.capacity *= 2;
    int* t = new int[v.capacity];
    for (int i = 0; i < v.size; i++) t[i] = v.data[i];
    delete[] v.data;
    v.data = t;
    cout << "  [resize -> cap=" << v.capacity << "]\n";
}

void push_back(MyVector& v, int x) {
    if (v.size == v.capacity) resize(v);
    v.data[v.size++] = x;
}

void pop_back(MyVector& v) {
    if (v.size == 0) cout << "  [!] Rong!\n";
    else v.size--;
}

int at(MyVector& v, int i) {
    if (i < 0 || i >= v.size) { cout << "  [!] Out of range!\n"; return -1; }
    return v.data[i];
}

void print(MyVector& v) {
    cout << "  [size=" << v.size << " cap=" << v.capacity << "]: [";
    for (int i = 0; i < v.size; i++) cout << v.data[i] << (i<v.size-1?", ":"");
    cout << "]\n";
}

int main() {
    MyVector v; init(v);

    cout << "\n=== PUSH_BACK ===\n";
    for (int x : {10, 20, 30, 40, 50}) { push_back(v, x); print(v); }

    cout << "\n=== AT ===\n";
    cout << "  at(0)=" << at(v,0) << "  at(2)=" << at(v,2) << "\n";
    at(v, 9); // out of range

    cout << "\n=== POP_BACK ===\n";
    pop_back(v); print(v);
    pop_back(v); print(v);

    destroy(v);
    cout << "\n  [destroy OK]\n";
}

Bài 4: 🔥 Dự Án Mini — Student Score Manager ⭐⭐⭐
Cảm hứng: BaiTapTongHop — Quản lý sinh viên (DSALab)

Xây dựng hệ thống quản lý điểm sinh viên bằng mảng động:

Thêm / xóa / sửa sinh viên (tên, MSSV, điểm)
Sắp xếp theo điểm (dùng Selection Sort hoặc Bubble Sort)
Tìm kiếm theo tên hoặc MSSV (Linear Search)
Thống kê: điểm cao nhất, thấp nhất, trung bình lớp
Xuất danh sách ra file diem_sinhvien.txt
=== QUẢN LÝ ĐIỂM SINH VIÊN ===
1. Thêm sinh viên
2. Xóa sinh viên
3. Tìm kiếm
4. Xếp hạng lớp
5. Xuất báo cáo
0. Thoát

   #include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct SV { char mssv[12], ten[50]; float diem; };
struct DS { SV* ds; int size, cap; };

void init(DS& d)    { d.size=0; d.cap=4; d.ds=new SV[4]; }
void destroy(DS& d) { delete[] d.ds; d.ds=nullptr; d.size=d.cap=0; }
void resize(DS& d)  { SV* t=new SV[d.cap*=2]; for(int i=0;i<d.size;i++) t[i]=d.ds[i]; delete[] d.ds; d.ds=t; }

const char* xepLoai(float x) {
    if(x>=9) return "Xuat sac"; if(x>=8) return "Gioi";
    if(x>=6.5) return "Kha";    if(x>=5) return "TB"; return "Yeu";
}

void ke() { cout<<"  +"<<setfill('-')<<setw(13)<<"+"<<setw(32)<<"+"<<setw(8)<<"+"<<setw(12)<<"+"<<setfill(' ')<<"\n"; }

void inDS(DS& d) {
    if(!d.size) { cout<<"  [!] Danh sach trong.\n"; return; }
    ke();
    cout<<"  | "<<left<<setw(10)<<"MSSV"<<" | "<<setw(29)<<"Ho Ten"<<" | "<<setw(5)<<"Diem"<<" | "<<setw(9)<<"Xep loai"<<" |\n";
    ke();
    for(int i=0;i<d.size;i++)
        cout<<"  | "<<left<<setw(10)<<d.ds[i].mssv<<" | "<<setw(29)<<d.ds[i].ten
            <<" | "<<right<<fixed<<setprecision(1)<<setw(5)<<d.ds[i].diem<<" | "<<left<<setw(9)<<xepLoai(d.ds[i].diem)<<" |\n";
    ke(); cout<<"  Tong: "<<d.size<<" SV\n";
}

void them(DS& d) {
    if(d.size==d.cap) resize(d);
    SV& s=d.ds[d.size];
    cout<<"  MSSV: "; cin>>s.mssv; cin.ignore();
    cout<<"  Ten : "; cin.getline(s.ten,50);
    cout<<"  Diem: "; cin>>s.diem;
    if(s.diem<0||s.diem>10) { cout<<"  [!] Diem khong hop le!\n"; return; }
    d.size++; cout<<"  [+] Da them.\n";
}

void xoa(DS& d) {
    char ms[12]; cout<<"  MSSV can xoa: "; cin>>ms;
    for(int i=0;i<d.size;i++) if(!strcmp(d.ds[i].mssv,ms)) {
        for(int j=i;j<d.size-1;j++) d.ds[j]=d.ds[j+1];
        d.size--; cout<<"  [-] Da xoa.\n"; return;
    }
    cout<<"  [!] Khong thay.\n";
}

void sua(DS& d) {
    char ms[12]; cout<<"  MSSV can sua: "; cin>>ms;
    for(int i=0;i<d.size;i++) if(!strcmp(d.ds[i].mssv,ms)) {
        cin.ignore();
        cout<<"  Ten moi : "; cin.getline(d.ds[i].ten,50);
        cout<<"  Diem moi: "; cin>>d.ds[i].diem;
        cout<<"  [*] Da cap nhat.\n"; return;
    }
    cout<<"  [!] Khong thay.\n";
}

void tim(DS& d) {
    int ch; char kw[50];
    cout<<"  (1)MSSV (2)Ten: "; cin>>ch; cin.ignore();
    cout<<"  Tu khoa: "; cin.getline(kw,50);
    ke(); bool found=false;
    for(int i=0;i<d.size;i++) {
        bool ok=(ch==1)?!strcmp(d.ds[i].mssv,kw):strstr(d.ds[i].ten,kw)!=nullptr;
        if(ok) { cout<<"  | "<<left<<setw(10)<<d.ds[i].mssv<<" | "<<setw(29)<<d.ds[i].ten<<" | "<<right<<fixed<<setprecision(1)<<setw(5)<<d.ds[i].diem<<" |\n"; found=true; }
    }
    ke(); if(!found) cout<<"  [!] Khong tim thay.\n";
}

void sapXep(DS& d) {
    for(int i=0;i<d.size-1;i++) { int mx=i;
        for(int j=i+1;j<d.size;j++) if(d.ds[j].diem>d.ds[mx].diem) mx=j;
        if(mx!=i) swap(d.ds[i],d.ds[mx]);
    }
    cout<<"  [OK] Da sap xep.\n"; inDS(d);
}

void thongKe(DS& d) {
    if(!d.size) { cout<<"  [!] Trong.\n"; return; }
    float mn=d.ds[0].diem, mx=d.ds[0].diem, tong=0; int iMn=0,iMx=0;
    for(int i=0;i<d.size;i++) {
        tong+=d.ds[i].diem;
        if(d.ds[i].diem<mn){mn=d.ds[i].diem;iMn=i;}
        if(d.ds[i].diem>mx){mx=d.ds[i].diem;iMx=i;}
    }
    cout<<fixed<<setprecision(2)
        <<"\n  TB      : "<<tong/d.size
        <<"\n  Cao nhat: "<<mx<<" ("<<d.ds[iMx].ten<<")"
        <<"\n  Thap nht: "<<mn<<" ("<<d.ds[iMn].ten<<")\n";
}

void xuatFile(DS& d) {
    ofstream f("diem_sinhvien.txt");
    f<<left<<setw(12)<<"MSSV"<<setw(30)<<"Ho Ten"<<setw(8)<<"Diem"<<"Xep loai\n"<<string(60,'-')<<"\n";
    for(int i=0;i<d.size;i++)
        f<<left<<setw(12)<<d.ds[i].mssv<<setw(30)<<d.ds[i].ten
         <<fixed<<setprecision(1)<<setw(8)<<d.ds[i].diem<<xepLoai(d.ds[i].diem)<<"\n";
    f.close(); cout<<"  [OK] Xuat 'diem_sinhvien.txt'.\n";
}

void menu() {
    cout<<"\n  ╔══════════════════════════════╗\n"
          "  ║  QUAN LY DIEM SINH VIEN     ║\n"
          "  ╠══════════════════════════════╣\n"
          "  ║ 1.Them  2.Xoa   3.Sua       ║\n"
          "  ║ 4.Hien  5.Tim   6.SapXep    ║\n"
          "  ║ 7.ThongKe       8.XuatFile  ║\n"
          "  ║ 0.Thoat                     ║\n"
          "  ╚══════════════════════════════╝\n"
          "  Chon: ";
}

int main() {
    DS d; init(d); int ch;
    do {
        menu(); cin>>ch;
        switch(ch) {
            case 1:them(d);    break; case 2:xoa(d);     break;
            case 3:sua(d);     break; case 4:inDS(d);    break;
            case 5:tim(d);     break; case 6:sapXep(d);  break;
            case 7:thongKe(d); break; case 8:xuatFile(d);break;
            case 0:cout<<"  Tam biet!\n"; break;
            default:cout<<"  [!] Sai lua chon.\n";
        }
    } while(ch!=0);
    destroy(d);
}
