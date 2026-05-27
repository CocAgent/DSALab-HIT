#include <iostream>
#define MAX 100
using namespace std;

void NhapMang(int a[], int &n){
    cout << "Nhap so phan tu: ";
    cin >> n;
    while (n < 1 || n > MAX){
        cout << "So phan tu khong hop le. Nhap lai: ";
        cin >> n;
    }
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void XuatMang(int a[], int n){
    cout << "Mang vua nhap: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int min(int a[], int n){
    int min_f = a[0];
    for (int i = 0; i < n; i++){
        if(a[i] < min_f){
            min_f = a[i];
        }
    }
    return min_f;
}

int max(int a[], int n){
    int max_f = a[0];
    for (int i = 0; i < n; i++){
        if(a[i] > max_f){
            max_f = a[i];
        }
    }
    return max_f;
}

double avg(int a[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
    }
    return (double)sum / n;
}

int Sum(int a[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
    }
    return sum;
}

int main(){
    int a[MAX];
    int n;
    NhapMang(a, n);
    XuatMang(a, n);
    cout << "Gia tri nho nhat trong mang la: " << min(a, n) << endl;
    cout << "Gia tri lon nhat trong mang la: " << max(a, n) << endl;
    cout << "Trung binh cong cua mang la: " << avg(a, n) << endl;
    cout << "Tong cua mang la: " << Sum(a, n) << endl;
    return 0;
}
