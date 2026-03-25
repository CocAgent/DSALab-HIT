#pragma once
#include <iostream>
#include<string>
using namespace std;
#define MAX 100

void xuatmang(int a[], int n);
void swap(int& a, int& b);
void selectionSort(int a[], int n);
void bubbleSort(int a[], int n);
void insertionSort(int a[], int n);
void QuickSort(int a[], int l, int r);
int partition(int a[], int l, int r);
void heapify(int a[], int n, int i);
void heapSort(int a[], int n);