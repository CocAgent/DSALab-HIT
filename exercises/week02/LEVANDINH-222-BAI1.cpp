#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Nhap so phan tu: ";
    cin >> n;

    int a[1000];

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int min = a[0];
    int max = a[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];

        sum += a[i];
    }

    double avg = (double)sum / n;

    cout << "\nMin = " << min;
    cout << "\nMax = " << max;
    cout << "\nTong = " << sum;
    cout << "\nTrung binh = " << avg;

    return 0;
}
