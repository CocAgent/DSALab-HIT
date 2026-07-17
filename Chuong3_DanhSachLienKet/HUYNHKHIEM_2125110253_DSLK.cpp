#include <iostream>

using namespace std;



// Hàm hoán đổi dùng con trỏ

void swapTrucTiep(int* x, int* y) {

    int temp = *x; // Lấy giá trị tại địa chỉ x cất vào biến tạm

    *x = *y;       // Lấy giá trị tại địa chỉ y ghi đè vào địa chỉ x

    *y = temp;     // Ghi giá trị tạm vào địa chỉ y

}



int main() {

    int a = 3, b = 9;



    cout << "Truoc khi doi: a = " << a << ", b = " << b << endl;



    // Truyền "địa chỉ" của a và b vào hàm (dùng dấu &)

    swapTrucTiep(&a, &b);



    cout << "Sau khi doi:  a = " << a << ", b = " << b << endl;



    return 0;

}
//Truoc khi doi: a = 3, b = 9
//Sau khi doi : a = 9, b = 3

