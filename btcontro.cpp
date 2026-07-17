#include"bt2.h"
int main() {
	int a = 5, b = 10;
	cout << "Before swapping: a = " << a << ", b = " << b << endl;
	swapNumbers(&a, &b);
	cout << "After swapping: a = " << a << ", b = " << b << endl;
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Sum of array: " << sumArray(arr, n) << endl;
	cout << "Max of array: " << MaxArray(arr, n) << endl;
	return 0;
}