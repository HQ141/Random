#ifndef QUEUE_H
#define QUEUE_H
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
class Queue{
private:
	Node<T>* front;
	Node<T>* rear;
public:
	Queue():front(NULL),rear(NULL){}
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
	T & DeQueue() {
		Node<T>* temp = front;
		front = front->next;
		T a = temp->data;
		delete[] temp;
		return a;
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
		if(front)
		return front->data;
	}
	
};
string getinput(int& c, int& d) {
	string temp;
	string t;
	char a = 10;
	int i = 1;
	c = 0;
	d = 0;
	while (a < 48) {
		a = cin.get();
	}
	while (a != EOF) {
		if (a == '\n')
			break;
		if (a == ' ') {
			i++;
			a = cin.get();
		}
		if (i == 1) {
			t += a;
		}
		if (i == 2) {
			c = c * 10;
			c += a - 48;

		}
		if (i == 3) {
			d = d * 10;
			d += a - 48;
		}
		a = cin.get();
	}
	return t;
}

#endif