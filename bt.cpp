#include "header.h"

void XuatMang(int a[], int n)
{
	for (int i = 0;i < n; i++)
	{
		cout << a[i] << " ";
	}
}


void SelectionSort(int a[], int n)
{
	int vt;
	for (int i = 0;i < n-1;i++)
	{
		vt = i;
		for (int j = vt + 1;j < n;j++)
			if (a[j] < a[vt])
				vt = j;
		swap(a[i], a[vt]);
	}
}

void InsertionSort(int a[], int n)
{
	int pos, x;
	for (int i = 1;i < n;i++)
	{
		pos = i;
		x = a[i];
		while (pos > 0 && a[pos - 1] > x)
		{
			a[pos] = a[pos - 1];
			pos--;
		}
		a[pos] = x;
	}
}

void BubbleSort(int a[], int n)
{
	for(int i=0;i<n;i++)
	for(int j=n-1;j>i;j--)
		if (a[j] < a[j - 1])
		{
			swap(a[j], a[j - 1]);
		}
}

void QuickSort(int a[], int l, int r)
{
	int i = l, j = r, x;
	x = a[(l + r) / 2];
	do
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j) QuickSort(a, l, j);
	if (i < r) QuickSort(a, i, r);
}


void Heapify(int a[], int n, int i)
{
	int largest = i, l = 2 * i + 1, r = 2 * i + 2;
	if (l<n && a[l]>a[largest]) largest = l;
	if (r<n && a[r]>a[largest]) largest = r;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		Heapify(a, n, largest);
	}
}

void Heapsort(int a[], int n)
{
	for (int i = n / 2 - 1;i >= 0;i--)
		Heapify(a, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		Heapify(a, i, 0);
	}

}
