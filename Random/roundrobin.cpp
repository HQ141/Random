#include<iostream>
using namespace std;
template<class T>
class Node {
public:
	T data;
	Node* next;
	Node(T& a) {
		data = a;
		next = NULL;
	}
	void Clear() {
		if (!next) {
			delete this;
			return;
		}
		next->Clear();
		delete this;
		return;
	}
};
template<class T>
class Queue {
private:
	Node<T>* front;
	Node<T>* rear;
public:
	Queue() :front(NULL), rear(NULL) {}
	void EnQueue(T a) {
		if (!front) {
			front = new Node<T>(a);
			rear = front;
			return;
		}
		rear->next = new Node<T>(a);
		rear = rear->next;
		return;
	}
	void EnQueue(Node<T>* a) {
		if (!front) {
			front = a;
			rear = a;
			a->next = NULL;
			return;
		}
		rear->next = a;
		a->next = NULL;
		rear = rear->next;
		return;
	}
	void DeQueue(T &a) {
		Node<T>* temp = front;
		front = front->next;
		a = temp->data;
		delete[] temp;
	}
	void Clear() {
		front->Clear();
	}
	bool isEmpty() {
		if (!front)
			return true;
		return false;
	}
	T firstEl() {
		if (front)
			return front->data;
	}

};
class Task {
public:
	string name;
	int total;
	int qouta;
	Task() {}
	Task(string a, int t, int q) :name(a), total(t), qouta(q) {}
	Task(Task& a) {
		name = a.name;
		total = a.total;
		qouta = a.qouta;
	}
	void set(string a, int t, int q) {
		name = a;
		total = t;
		qouta = q;
	}
	bool Nz() {
		if (total > 0)
			return false;
		return true;
	}
};
string getinput(int& c, int& d) {
	string temp;
	string t;
	char a = 10;
	cin.get();
	while (a < 48) {
		a = cin.get();
	}
	while (a != ' ') {
		t += a;
		a = cin.get();
	}
	c = 0;
	a = cin.get();
	while (a >= '0' && a <= '9') {
		c = c * 10;
		c += a - 48;
		a = cin.get();
	}
	a = cin.get();
	d = 0;
	d += a - 48;
	return t;
}

int main() {
	int c;
	int t; int q; string na;
	cin >> c;
	Queue<Task*> qu;
	for (int i = 0; i < c; i++) {
		na = getinput(t, q);
		qu.EnQueue(new Task(na, t, q));
	}
	Task* temp;
	while (!qu.isEmpty()) {
		qu.DeQueue(temp);
		if (temp->total - temp->qouta > 0) {
			temp->total -= temp->qouta;
			qu.EnQueue(temp);
		}
		cout << temp->name << endl;
	}
	getchar();
}