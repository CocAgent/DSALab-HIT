#include"baitap1.h"



void xuatmang(int a[], int n)
{
	for( int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void selectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		swap(a[i], a[minIndex]);
	}
}
void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		bool swapped = false;
		for(int j=0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}
int partition(int a[], int l, int r)
{
	int pivot = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
void QuickSort(int a[], int  l, int r)
{
	if (l >= r)
		return;
	int p = partition(a, l, r);
	QuickSort(a, l, p - 1);
	QuickSort(a, p + 1, r);
}
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void heapSort(int a[], int n)
{
	//xay dung MAX HEAP
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	//trich max lien tuc
	for(int i= n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}