#pragma once
#include <iostream>
#include <cmath>
using namespace std;

struct node
{
	int data;
	node* next;
};

struct list
{
	node* head;
	node* tail;
};

void khoiTaoDSLK(list& l);
node* TaoNode(int x);
bool DsRong(const list& l);
//them
void ThemDau(list& l, int x);
void ThemCuoi(list& l, int x);
void ThemSau(list& l, node* q, int x);
void ThemTruoc(list& l, node* q, int x);
//xoa
void XoaDau(list& l);
void XoaCuoi(list& l);
bool XoaGiaTri(list& l, int x);
void XoaDS(list& l);

void InDS(const list& l);
int TimMax(const list& l);
int TimChanDau(const list& l);
void LietKeAm(const list& l);
long long TongDuong(const list& l);
int DemAm(const list& l);
bool KTCP(int n);
bool CSCP(const list& l);

int DemCucDai(const list& l);
void ChonTrucTiep(list& l);
void NoiDS(list& l1, list& l2);
void TachChanLe(list& l, list& l_chan, list& l_le);

//stack

struct stack
{
	node* top;
};

void KhoiTaoStack(stack& s);
bool StackRong(const stack& s);
void Push(stack& s, int x);
int pop(stack& s);
int peekstack(const stack& s);
void Instack(const stack& s);

bool KTNgoac(const string& s);
//queue

struct queue
{
	node* front;
	node* rear;
};

void KhoiTaoQueue(queue& q);
bool QueueRong(const queue& q);
void enqueue(queue& q, int x);
int Dequeue(queue& q);
void InQueue(const queue& q);


