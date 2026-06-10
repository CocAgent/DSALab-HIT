// B1

//head
#include <iostream>
using namespace std;
int TinhMin(const int a[], int n);
int TinhMax(const int a[], int n);
long long TinhTong(const int a[], int n);


//function
#include "h.h"
int TinhMin(const int a[], int n) {
    int mn = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < mn) mn = a[i];
    return mn;
}

int TinhMax(const int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx) mx = a[i];
    return mx;
}

long long TinhTong(const int a[], int n) {
    long long tong = 0;
    for (int i = 0; i < n; i++)
        tong += a[i];
    return tong;
}


//main
#include "h.h"

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "Min: " << TinhMin(a, n) << endl;
    cout << "Max: " << TinhMax(a, n) << endl;
    cout << "Tong: " << TinhTong(a, n) << endl;
    cout << "Trung binh: " << (double)TinhTong(a, n) / n << endl;
}

//B2

//head
#include <iostream>
using namespace std;
//D
void NhapMaTran(int a[][10], int n);
void HienThiMaTran(const int a[][10], int n);
void NhanMaTran(const int a[][10], const int b[][10], int c[][10], int n);
int DinhThuc3x3(const int a[][3]);


//function
#include "h.h"
//c
void NhapMaTran(int a[][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
}

void HienThiMaTran(const int a[][10], int n) {
    for (int i = 0; i < n; i++) {
        cout << "| ";
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << "|" << endl;
    }
}

void NhanMaTran(const int a[][10], const int b[][10], int c[][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

int DinhThuc3x3(const int a[][3]) {
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
        - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
        + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}


//main
#include "h.h"
//c
int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int a[10][10], b[10][10], c[10][10];

    cout << "\nNhap ma tran A" << endl;
    NhapMaTran(a, n);

    cout << "\nNhap ma tran B" << endl;
    NhapMaTran(b, n);

    NhanMaTran(a, b, c, n);

    cout << "\nMa tran A" << endl;
    HienThiMaTran(a, n);

    cout << "\nMa tran B" << endl;
    HienThiMaTran(b, n);

    cout << "\nA x B" << endl;
    HienThiMaTran(c, n);

    if (n == 3) {
        cout << "\nDinh thuc A" << endl;
        cout << "det(A) = " << DinhThuc3x3((const int(*)[3])a) << endl;
    }
    else {
        cout << "\n(Tinh dinh thuc cho ma tran 3x3)" << endl;
    }

    return 0;
}
//B3

//head
#include <iostream>
using namespace std;
//D
struct vec{
    int* data;
    int size;
    int capacity;

    vec();
    ~vec();
    void resize();
    void push_back(int x);
    void pop_back();
    int at(int i);
    void print();
};

//function
#include "h.h"
//c
vec::vec() {
    size = 0;
    data = nullptr;
}

vec::~vec() {
    delete[] data;
}

void vec::push_back(int x) {
    int* newData = new int[size + 1];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];
    newData[size] = x;
    delete[] data;
    data = newData;
    size++;
}

void vec::pop_back() {
    if (size == 0) return;
    int* newData = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    size--;
}

int vec::at(int i) {
    if (i < 0 || i >= size) {
        cout << "Chi so nam ngoai pham vi\n";
        return -1;
    }
    return data[i];
}

void vec::print() {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << "] size=" << size << "\n";
}

//main
#include "h.h"
//c
int main() {
    vec v;

    v.push_back(1); v.print();
    v.push_back(2); v.print();
    v.push_back(3); v.print();

    cout << "at(2) = " << v.at(2) << "\n";
    cout << "at(9) = " << v.at(9) << "\n";

    v.pop_back(); v.print();
    v.pop_back(); v.print();
}
