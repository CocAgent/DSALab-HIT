#include"baitap1.h"

int a[MAX] = { 3,-12,14,9,11,-50,-100 };
int n = 7;
int menu()
{
	cout << "1. Xuat mang" << endl;
	cout << "2. Sap xep mang bang Selection Sort" << endl;
	cout << "3. Sap xep mang bang Bubble Sort" << endl;
	cout << "4. Sap xep mang bang Insertion Sort" << endl;
	cout << "5. Sap xep mang bang Quick Sort" << endl;
	cout << "6. Sap xep mang bang Heap Sort" << endl;
	cout << "0. Thoat" << endl;
	int choice;
	cout << "Nhap lua chon: ";
	cin >> choice;
	return choice;
}
int main()
{
	int choice;
	do
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			cout << "Mang hien tai: ";
			xuatmang(a, n);
			cout << endl;
			break;
		case 2:
			selectionSort(a, n);
			cout << "Mang sau khi sap xep bang Selection Sort: ";
			xuatmang(a, n);
			cout << endl;
			break;
		case 3:
			bubbleSort(a, n);
			cout << "Mang sau khi sap xep bang Bubble Sort: ";
			xuatmang(a, n);
			cout << endl;
			break;
		case 4:
			insertionSort(a, n);
			cout << "Mang sau khi sap xep bang Insertion Sort: ";
			xuatmang(a, n);
			cout << endl;
			break;
		case 5:
			QuickSort(a, 0, n - 1);
			cout << "Mang sau khi sap xep bang Quick Sort: ";
			xuatmang(a, n);
			cout << endl;
			break;
		case 6:
			heapSort(a, n);
			cout << "Mang sau khi sap xep bang Heap Sort: ";
			xuatmang(a, n);
			cout << endl;
			break;
		case 0:
			cout << "Thoat chuong trinh." << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long chon lai." << endl;
		}
	} while (choice != 0);
	return 0;
}