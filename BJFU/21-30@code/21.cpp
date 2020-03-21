#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

typedef struct PNode
{
	double a;
	int x;
	struct PNode* next;
}*Polynomial, PNode;

void CreatePolynomial(Polynomial& L, int n)
{
	L = new PNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		PNode* s = new PNode;
		cin >> s->a >> s->x;
		PNode* pre = L;
		PNode* cur = L->next;
		while (cur && s->x < cur->x)
		{
			pre = cur;
			cur = cur->next;
		}
		s->next = cur;
		pre->next = s;
	}
}

void OutputPolynomial(Polynomial L)
{
	if (!L || !L->next) {
		cout << 0 << endl;
		return;
	}
	PNode* p = L->next;
	while (p)
	{
		if (p == L->next) {
			if (p->x != 0)
				cout << p->a << "x^" << p->x;
			else
				cout << p->a;
		}
		else {
			if (p->a > 0)cout << "+";
			if (p->x != 0)
				cout << p->a << "x^" << p->x;
			else
				cout << p->a;
		}
		p = p->next;	
	}
	cout << endl;
}

Polynomial Add(Polynomial L1, Polynomial L2)
{
	PNode* p1 = L1->next;
	PNode* p2 = L2->next;
	PNode* r = NULL;
	Polynomial L3;
	CreatePolynomial(L3, 0);
	PNode* p3 = L3;
	while (p1 && p2)
	{
		if (p1->x == p2->x) {
			int sum = p1->a + p2->a;
			if (sum) {
				p1->a = sum;
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;
				p2 = p2->next; 
			}
			else {
				 p1 = p1->next;
				 p2 = p2->next;
			}
			
		}
		else if (p1->x > p2->x) {
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else {
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
		
	}
	p3->next = p1 ? p1 : p2;
	return L3;
}

void Minus(Polynomial L1, Polynomial L2)
{
	PNode* p = L2->next;
	while (p)
	{
		p->a *= -1;
		p = p->next;
	}
	OutputPolynomial(Add(L1, L2));
}

void Mul(Polynomial L1, Polynomial L2)
{
	PNode* p1 = L1->next;
	PNode* p2 = L2->next;	
	Polynomial L3;
	CreatePolynomial(L3, 0);
	Polynomial temp;
	CreatePolynomial(temp, 0);
	while (p1)
	{
		while (p2)
		{	
			PNode* t = new PNode;
			t->next = NULL;
			t->a = p1->a * p2->a;
			t->x = p1->x + p2->x;
			temp->next = t;
			L3 = Add(L3, temp);
			p2 = p2->next;
		}		
		p2 = L2->next;
		p1 = p1->next;
	}
	OutputPolynomial(L3);
}

void Diff(Polynomial L)
{
	PNode* p = L->next;
	PNode* r = NULL;
	while (p)
	{
		p->a *= p->x;
		p->x--;
		if (p->x < 0) {
			r = p;
			p = p->next;
			delete r;
		}
		else {
			p = p->next;
		}
	}
	OutputPolynomial(L);
}

int main()
{
	int T; cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		Polynomial L1, L2;
		CreatePolynomial(L1, a);
		CreatePolynomial(L2, b);
		string s; cin >> s;
		if (s == "+")OutputPolynomial(Add(L1, L2));
		if (s == "-")Minus(L1, L2);
		if (s == "*")Mul(L1, L2);
		if (s == "'") {
			Diff(L1);
			Diff(L2);
		}
	}
}
