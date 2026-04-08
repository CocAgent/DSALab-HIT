#include "bt.h"

void KhoiTaoDS(List& l)
{
	l.pHead = l.pTial = NULL;
}
void HuyDS(List& l)
{
	Node* p;
	while (l.pHead)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		p->pNext = NULL;
		delete (p);
	}
}
Node* TaoNut(int x)
{
	Node* p;
	p = new Node;
	if (p == NULL)
	{
		cout << "Khong cap phat duoc vung nho, ket thuc";
		system("pause");
		exit(1);
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void TaoDS(List& l)
{
	int x;
	Node* p;
	do {
		cout << ("\n Nhap gia tri vao DS(Nhap 0 ket thuc) : ");
		cin >> x;
		if (x == 0)
			break;
		p = TaoNut(x);
		if (l.pHead == NULL)
			l.pHead = l.pTial = p;
		else {
			l.pTial->pNext = p;
			l.pTial = p;
		}
	} while (1); //s? m?t (1)
}
void XuatDS(List l)
{
	Node* p = l.pHead;
	while (p)
	{
		cout << p->data << " ->";
		p = p->pNext;
	}
	cout << "NULL";
}
void ThemDau(List& l, Node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTial = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void ThemCuoi(List& l, Node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTial = p;
	else
	{
		l.pTial->pNext = p;
		l.pTial = p;
	}
}
Node* TimPT(List l, int k)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data == k)
			return p;
		p = p->pNext;
	}
	return NULL;
}
void ThemPSauQ(List& l, Node* p, Node* q)
{
	if (q == l.pTial)
	{
		q->pNext = p;
		l.pTial = p;
	}
	else
	{
		p->pNext = q->pNext;
		q->pNext = p;
	}
}
void ThemPTruocQ(List& l, Node* p, Node* q)
{
	if (q == l.pHead)
		ThemDau(l, p);
	else
	{
		p->pNext = q;
		Node* k = l.pHead;
		while (k->pNext != q)
			k = k->pNext;
		k->pNext = p;
	}
}
void XoaDau(List& l)
{
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete(p);
	if (l.pHead == NULL)
		l.pTial = NULL;
}
void XoaCuoi(List& l)
{
	Node* p = l.pTial;
	if (l.pHead->pNext == NULL)
		l.pHead = l.pTial = NULL;
	else
	{
		Node* k = l.pHead;
		while (k->pNext != l.pTial)
			k = k->pNext;
		l.pTial = k;
		k->pNext = NULL;
	}
	delete(p);
}
void XoaPT(List& l, Node* p)
{
	if (p == l.pHead)
		XoaDau(l);
	else
		if (p == l.pTial)
			XoaCuoi(l);
		else
		{
			Node* k = l.pHead;
			while (k->pNext != p)
				k = k->pNext;
			k->pNext = p->pNext;
			delete(p);
		}
}
void XoaMin(List& l)
{
	if (l.pHead == NULL)
		return;
	Node* pmin = l.pHead;
	Node* p = l.pHead->pNext;
	while (p != NULL)
	{
		if (p->data < pmin->data)
			pmin = p;
		p = p->pNext;
	}
	XoaPT(l, pmin);
}
void XoaTruocQ(List& l, Node* q)
{
	if (q == l.pHead)
		cout << "/nKhong ton tai pt truoc q de xoa: ";
	else
	{
		Node* k = l.pHead;
		while (k->pNext != q)
			k = k->pNext;
		XoaPT(l, k);
	}
}
void XoaSauQ(List& l, Node* q)
{
	if (q == NULL || q->pNext == NULL)
		return;
	Node* p = q->pNext;
	q->pNext = p->pNext;
	if (p == l.pTial)
		l.pTial = q;
	delete p;
}
int TimMax(const List& l)
{
	int pmax = l.pHead->data;
	Node* p = l.pHead->pNext;
	while (p != NULL)
	{
		if (p->data > pmax)
			pmax = p->data;
		p = p->pNext;
	}
	return pmax;
}
Node* TimX(const List& l, int x)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data == x)
			return p;
		p = p->pNext;
	}
	return NULL;
}
int TimChanDau(const List& l)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data % 2 == 0)
			return p->data;
		p = p->pNext;
	}
	return -1;
}
int TimChanCuoi(const List& l)
{
	int chanCuoi = -1;
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data % 2 == 0)
			chanCuoi = p->data;
		p = p->pNext;
	}
	return chanCuoi;
}

void ThemSauLeCuoi(List& l, int x)
{
	Node* p = TaoNut(x);
	Node* q = TimLeCuoi(l);
	p = TimLeCuoi(l);
	if (q == NULL) {
		ThemCuoi(l, p);
	}
	else {
		if (q == l.pTial) {
			l.pTial->pNext = p;
			l.pTial = p;
		}
		else
		{
			p->pNext = q->pNext;
			q->pNext = p;
		}
	}
}
Node* TimLeCuoi(List& l)
{
	Node* q = NULL;
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data % 2 != 0)
			q = p;
		p = p->pNext;
	}
	return q;
}
void LietKeAm(const List& l)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data < 0)
			cout << p->data << " -> ";
		p = p->pNext;
	}
	cout << "NULL";
}
long long TongDuong(const List& l)
{
	long long sum = 0;
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data > 0)
			sum += p->data;
		p = p->pNext;
	}
	return sum;
}
int DemAm(const List& l)
{
	int count = 0;
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data < 0)
			count++;
		p = p->pNext;
	}
	return count;
}
bool LaChinhPhuong(int n)
{
	if(n<0)
		return false;
	int s = (int)sqrt((double)n);
	return s * s == n;
}
bool CoSoChinhPhuong(const List& l)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (LaChinhPhuong(p->data))
			return true;
		p = p->pNext;
	}
	return false;
}
int DemCucDai(const List& l)
{
	int max = TimMax(l), dem = 0;
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data == max)
			dem++;
		p = p->pNext;
	}
	return dem;
}