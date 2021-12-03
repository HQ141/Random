#ifndef STACK_H
#define STACK_H
#define MAX 10
#include<iostream>
using namespace std;
class Astack {
	int top = -1;
	char arr[10];
public:
	bool push(char a) {
		if (top == MAX - 1) {
			cout << "Overflow" << endl;
			return false;
		}
		arr[++top] = a;
		return true;
	}
	bool display() {
		 int a = top;
		if (isEmpty())
			return 0;
		while (a != -1)
			cout << arr[a--]<<endl;
		return true;
	}
	int pop() {
		if (top ==- 1) {
			cout << "Underflow" << endl;
			return false;
		}
		return arr[top--];
	}
	int peek() {
		if (top == -1) {
			cout << "Underflow" << endl;
			return false;
		}
		return arr[top];
	}
	bool isEmpty() {
		if (top == -1)
			return true;
		return false;
	}
};
template<class T>
class Node {
public:
	T data;
	Node* next = NULL;
	Node(T a) :data(a){}
	bool print() {
		if (next == NULL) {
			cout << data << "->";
			return 0;
		}
		next->print();
		cout << data << "->";
		return 0;
	}
};
template <class T>
class LStack {
private:
	int size;
	Node<T>* top=NULL;
public:
	bool push(T a) {
		Node<T>* temp =new  Node<T>(a);
		if (top == NULL) {
			top = temp;
			return 0;
		}
		temp->next = top;
		top = temp;
		return 1;
	}
	T pop() {
		if (top == NULL) {
			cout << "Stack Underflow" << endl;
			return 0;
		}
		T a = top->data;
		Node<T>* temp = top;
		top = top->next;
		delete []temp;
		return a;
	}
	bool isEmpty() {
		if (top == NULL)
			return 1;
		return 0;
	}
	T peek() {
		if (top == NULL) {
			cout << "Stack Underflow" << endl;
			return 0;
		}
		return top->data;
	}
	void DWDisplay() {
		Node<T>* temp = top;
		while (temp) {
			cout << temp->data << "->";
			temp = temp->next;
		}
	}
	void UPDisplay() {
		top->print();
	}
};
int getpres(char a) {
	if (a == '(')
		return 4;
	if (a == '^')
		return 3;
	if(a=='*'||a=='/')
		return 2;
	if (a == '+' || a == '-')
		return 1;
}
void infixtoprefix(string a) {
	int size = a.size();
	int ppres = 0, cpres = 0;
	Astack ss;
	for (int i = 0; i < size; i++) {
		if (a[i] >= 97 && a[i] <= 122)
			cout << a[i];
		else {
			if (ss.isEmpty()) {
				ss.push(a[i]);
			}
			else {
				if (a[i] == ')') {
					while (ss.peek() != '(')
						cout << (char)ss.pop();
					ss.pop();
				}
				else {
					ppres = getpres(ss.peek());
					cpres = getpres(a[i]);
					while (cpres <= ppres) {
						if (ss.peek() == '(')
							break;
						cout << (char)ss.pop();
						if (ss.isEmpty())
							break;
						ppres = getpres(ss.peek());
						cpres = getpres(a[i]);
					}
					ss.push(a[i]);
				}
			}
		}
	}
	while (!ss.isEmpty())
		cout <<(char)ss.pop();
}
#endif