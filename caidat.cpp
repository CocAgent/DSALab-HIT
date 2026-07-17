#include "header.h"

void khoiTaoDSLK(list& l)
{
	l.head = l.tail = nullptr;
}

node* TaoNode(int x)
{
	node* p = new node;
	p->data = x;
	p->next = nullptr;
	return p;
}

bool DsRong(const list& l)
{
	return l.head == nullptr;
}

void ThemDau(list& l, int x)
{
	node* p = TaoNode(x);
	if (DsRong(l))
	{
		l.head = l.tail = p;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
}

void ThemCuoi(list& l, int x)
{
	node* p = TaoNode(x);
	if (DsRong(l)) 
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void ThemSau(list& l, node* q, int x)
{
	if (q == nullptr)
		return;

	node* p = TaoNode(x);
	p->next = q->next;
	q->next = p;
	if (q == l.tail)l.tail = p;
}

void ThemTruoc(list& l, node* q, int x)
{
	if (q == nullptr)
		return;
	if (q == l.head)
	{
		ThemDau(l, x);
		return;
	}
	node* p = TaoNode(x);
	node* cur = l.head;
	while (cur->next != q)
		cur = cur->next;
	p->next = q;
	cur->next = p;
}

void XoaDau(list& l)
{
	if (DsRong(l))
		return;
	node* p = l.head;
	l.head = l.head->next;
	if (l.head == nullptr)
		l.tail = nullptr;
	delete p;
}

void XoaCuoi(list& l)
{
	if (DsRong(l))
		return;
	if (l.head == l.tail)
	{
		delete l.head;
		l.head = l.tail = nullptr;
			return;
	}
	node* cur = l.head;
	while (cur->next != l.tail)
		cur = cur->next;
	delete l.tail;
	l.tail = cur;
	l.tail->next = nullptr;
}

bool XoaGiaTri(list& l, int x)
{
	if (DsRong(l))
		return false;
	node* cur = l.head, * prev = nullptr;
	while (cur != nullptr && cur->data != x)
	{
		prev = cur; cur = cur->next;
	}
	if(cur==nullptr)
		return false;
	if (prev == nullptr)
		XoaDau(l);
	else 
	{
		prev->next = cur -> next;
		if (cur == l.tail)
			l.tail = prev;
		delete cur;
	}
	return true;
}

void XoaDS(list& l)
{
	while (!DsRong(l))
		XoaDau(l);
}

void InDS(const list& l)
{
	if (DsRong(l))
	{
		cout << "\n[Danh sach rong]";
		return;
	}
	cout << " HEAD -> ";
	node* cur = l.head;
	while (cur != nullptr)
	{
		cout << cur->data;
		if (cur->next) cout << "->";
		cur = cur->next;
	}
	cout << "\n-> NULL";
}


int TimMax(const list& l)
{
	if (DsRong(l))
		return -1;
	int mx = l.head->data;
	node* cur = l.head->next;
	while (cur != nullptr)
	{
		if (cur->data > mx)mx = cur->data;
		cur = cur->next;
	}
	return mx;
}

int TimChanDau(const list& l)
{
	node* cur = l.head;
	while (cur != nullptr)
	{
		if (cur->data % 2 == 0)
			return cur->data;
		cur = cur->next;
	}
	return -1;
}

void LietKeAm(const list& l)
{
	cout << "\nCac phan tu am: ";
	node* cur = l.head;
	bool co = false;
	while (cur != nullptr)
	{
		if (cur->data < 0)
		{
			cout << cur->data << " ";
			co = true;
		}
		cur = cur->next;
	}
	if (!co) cout << "\n(khong co)";
	cout << "\n";
}

long long TongDuong(const list& l)
{
	long long s = 0;
	node* cur = l.head;
	while (cur != nullptr)
	{
		if (cur->data > 0) s += cur->data;
		cur = cur->next;
	}
	return s;
}

int DemAm(const list& l)
{
	int dem = 0;
	node* cur = l.head;
	while (cur != nullptr)
	{
		if (cur->data < 0) dem++;
		cur = cur->next;
	}
	return dem;
}

bool KTCP(int n)
{
	if (n < 0) return false;
	int s = (int)sqrt((double)n);
	return s * s == n;
}

bool CSCP(const list& l)
{
	node* cur = l.head;
	while (cur != nullptr)
	{
		if (KTCP(cur->data))
			return true;
		cur = cur->next;
	}
	return false;
}

int DemCucDai(const list& l)
{
	if (DsRong(l))
		return 0;
	int mx = TimMax(l), dem = 0;
	node* cur = l.head;
	while (cur != nullptr)
	{
		if (cur->data == mx)
			dem++;
		cur = cur->next;
	}
	return dem;
}

void ChonTrucTiep(list& l)
{
	for (node* i = l.head;i != nullptr && i->next != nullptr; i = i->next)
		for (node* j = i->next;j != nullptr;j = j->next)
			if (i->data > j->data)
			{
				int t = i->data; i->data = j->data = t;
			}
}

void NoiDS(list& l1, list& l2)
{
	if (DsRong(l1))
		return;
	if (DsRong(l1))
	{
		l1 = l2;
	}
	else { l1.tail->next = l2.head;l1.tail = l2.tail;}
	l2.head = l2.tail = nullptr;
}

void TachChanLe(list& l, list& l_chan, list& l_le)
{
	khoiTaoDSLK(l_chan);
	khoiTaoDSLK(l_le);
	node* cur = l.head;
	while (cur != nullptr)
	{
		if (cur->data % 2 == 0)
			ThemCuoi(l_chan, cur->data);
		else ThemCuoi(l_le, cur->data);
		cur = cur->next;
	}
}



void KhoiTaoStack(stack& s)
{
	s.top == nullptr;
}

bool StackRong(const stack& s)
{
	return s.top == nullptr;
}

void Push(stack& s, int x)
{
	node* p = TaoNode(x);
	p->next = s.top;
	s.top = p;
}

int pop(stack& s)
{
	if (StackRong(s))
	{
		cout << "\nstack rong!";
		return -1;
	}

	int val = s.top->data;
	node* p = s.top;
	s.top = s.top->next;
	delete p;
	return val;
}

int peekstack(const stack& s)
{
	if (StackRong(s))
		return -1;
	return s.top->data;
}

void Instack(const stack& s)
{
	cout << "stack(TOP->BOT): ";
	node* cur = s.top;
	while (cur)
	{
		cout << cur->data << " "; cur=cur->next;
	}
	cout << "\n";
}

bool KTNgoac(const string& s) 
{
	stack S; KhoiTaoStack(S);
	for (char c : s) {
		if (c == '(' || c == '[' || c == '{') Push(S, c);
		else if (c == ')' || c == ']' || c == '}') {
			if (StackRong(S)) return false;
			int top = pop(S);
			if ((c == ')' && top != '(') ||
				(c == ']' && top != '[') ||
				(c == '}' && top != '{')) return false;
		}
	}
	return StackRong(S);
}


void KhoiTaoQueue(queue& q)
{
	q.front = q.rear = nullptr;
}

bool QueueRong(const queue& q)
{
	return q.front == nullptr;
}

void enqueue(queue& q, int x)
{
	node* p = TaoNode(x);
	if (QueueRong(q)) q.front = q.rear = p;
	else
	{
		q.rear->next = p;q.rear = p;
	}
}


int Dequeue(queue& q)
{
	if (QueueRong(q))
	{
		cout << "\nqueue rong!";
		return -1;
	}

	int val = q.front->data;
	node* p = q.front;
	q.front = q.front->next;
	if (q.front == nullptr) q.rear = nullptr;
	delete p;
	return val;
}

void InQueue(const queue& q)
{
	cout << "queue (front ->rear): ";
	node* cur = q.front;
	while (cur)
	{
		cout << cur->data << " ";cur - cur->next;
	}

	cout << "\n";
}