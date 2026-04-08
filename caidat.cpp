#include"bt2.h"
void swapNumbers(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int sumArray(int* arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}
int MaxArray(int* arr, int n) {
	if (n <= 0) {
		return -1;
	}
	int maxVal = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}
	return maxVal;
}