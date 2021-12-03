#include<iostream>
using namespace std;
class Poly {
public:
	int co;
	char var;
	int exp;
	Poly() {}
	Poly(int c,char v,int e):co(c),var(v),exp(e){}
	friend ostream& operator<<(ostream& out, const Poly & a) {
		out << a.co << ' ' << a.var << " " << a.exp << endl;
		return out;
	}
};
class Node {
public:
	Poly data;
	Node* next;
	Node(){}
	Node(Poly a):data(a),next(NULL){}
};
int order(const Poly& a, const Poly& b) {
	if (a.exp == b.exp)
		if (a.var > b.var)
			return 1;
		else if (b.var > a.var)
			return -1;
		else
			return 0;
	if (a.exp > b.exp)
		return 1;
	else return -1;
}
int polycmp(const Poly& a, const Poly& b) {
	if (a.var == b.var)
		if (a.exp > b.exp)
			return 1;
		else if (b.exp > a.exp)
			return -1;
		else
			return 0;
	if (a.var > b.var)
		return 1;
	else return -1;
}
class Llist {
	Node* header;
	int size=0;
public:
	Llist():header(NULL){}
	void Insert(const Poly a) {
		size++;
		Node* althead = new Node();
		althead->next = header;
		Node* temp = althead;
		if (!header) {
			header = new Node(a);
			return;
		}
		while (temp && temp->next && (order(temp->next->data, a) <= 0)) {
			if (order(temp->next->data, a) == 0) {
				temp->next->data.co += a.co;
				return;
			}
			temp = temp->next;
		}
		if (!temp->next) {
			temp->next = new Node(a);
		}
		else {
			Node* t = new Node(a);
			t->next = temp->next;
			temp->next = t;
		}
		header = althead->next;
		delete althead;
	}
	void Display() {
		Node* temp = header;
		cout<<size<<endl;
		if (temp)
			while (temp) {
				cout << temp->data;
				temp = temp->next;
			}
	}
	friend Llist & add(Llist & a,Llist & b,Llist &c) {
		Node* atrav = a.header;
		Node* btrav = b.header;
		while (atrav != NULL && btrav != NULL) {
			if (polycmp(atrav->data, btrav->data) == -1) {
				Poly ap = atrav->data;
				c.Insert(ap);
				atrav = atrav->next;
			}
			else if (polycmp(atrav->data, btrav->data) == 1) {
				Poly ap = btrav->data;
				c.Insert(ap);
				btrav = btrav->next;
			}
			else {
				Poly ap = btrav->data;
				ap.co += atrav->data.co;
				c.Insert(ap);
				btrav = btrav->next;
				atrav = atrav->next;
			}
		}
		while (atrav!=NULL) {
			Poly ap = atrav->data;
			c.Insert(ap);
			atrav = atrav->next;
		}
		while (btrav != NULL) {
			Poly ap = btrav->data;
			c.Insert(ap);
			btrav = btrav->next;
		}
		return c;
	}
};

void getinput(int &c,char &v,int &e) {
	char a;
	a = getchar();
	while (a < 48)
		a = getchar();
	c = 0;
	while (a >= '0' && a <= '9') {
		c *= 10;
		c += a - 48;
		a = getchar();
	}
	a = getchar();
	v = a;
	a = getchar();
	a = getchar();
	e = 0;
	while (a >= '0' && a <= '9') {
		e *= 10;
		e += a - 48;
		a = getchar();
	}
}
int main() {
	int j;
	cin >> j;
	Llist a;
	int co;
	char var;
	int exp;
	for (int i = 0; i < j; i++) {
		getinput(co, var, exp);
		Poly ap(co, var, exp);
		a.Insert(ap);
	}
	cin >> j;
	Llist b;
	for (int i = 0; i < j; i++) {
		getinput(co, var, exp);
		Poly ap(co, var, exp);
		b.Insert(ap);
	}
	Llist c ;
	add(a,b,c);
	c.Display();
	getchar();
}