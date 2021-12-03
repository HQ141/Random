#include<iostream>
using namespace std;
template <class T>
class Node {
public:
	T data;
	int priority;
	Node* next;
	Node(T d, int p) :data(d), priority(p),next(NULL){}

};
template <class T>
class PQueue {
private:
	Node<T>* front;
	Node<T>* rear;
public:
	void Push(T data, int p) {
		if (front == NULL) {
			front = new Node<T>(data, p);
			rear = front;
			return;
		}
		Node<T>* temp = front;
		while (temp->priority > p) {
			temp = temp->next;
		}
		Node<T>* n = new Node<T>(data, p);
		n->next = temp->next;
		temp->next = n;
	}
	void Pop() {
		if (front == NULL)
			return;
		Node<T>* temp = front;
		if (front == rear) {
			rear = NULL;
			front = NULL;
			delete temp;
			return;
		}
		front = front->next;
		delete temp;
	}
	bool isEmpty() {
		if (front == NULL)
			return true;
		return false;
	}
	int size() {
		int a;
		Node<T>* temp = front;
		while (temp) {
			a++;
			temp = temp->next;
		}
		return a;
	}
	T top() {
		if (front)
			return front->data;
		return NULL;
	}
	void Emplace(T data) {
		if(front)
		Node<T>* temp = new Node(data, front->priority + 1);
		else
		Node<T>* temp = new Node(data, 1);
		temp->next = front;
		front = temp;
	}
	void Swap(PQueue<T>& a) {
		Node<T>* temp = front;
		front = a.front;
		a.front = temp;
		temp = rear;
		rear = a.rear;
		a.rear = temp;
	}
};