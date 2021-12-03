#include<iostream>
using namespace std;
class Poly {
public:
	char variable;
	int coeffient;
	int exp;
};
template <class T>
class Node {
public:
	T data;
	Node* next;
	Node(T a) :data(a), next(NULL) {}
	void Insert(Node* a) {
		if (next == NULL) {
			next = a;
			return;
		}
		next->Insert(a);

	}
};
template<class T>
class sList {
private:
	int size = 0;
	Node<T>* header = NULL;
public:
	sList() {}
	void InsertE(T a) {
		Node<T>* New = new Node<T>(a);
		Node<T>* temp = header;
		if (header == NULL) {
			header = New;
			size++;
			return;
		}
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = New;
		size++;
	}
	void print() {
		Node<T>* temp = header;
		int count = 0;
		while (temp != NULL && count < 20) {
			cout << temp->data << "->";
			temp = temp->next;
			count++;
		}
		cout << "NULL";
		cout << endl;
	}
	Node<T>* outfirst() {
		Node <T>* temp = header;
		header = header->next;
		temp->next = NULL;
		size--;
		return temp;
	}
	void insert(Node<T>* a) {
		if (header == NULL) {
			header = a;
			size++;
			return;
		}
		header->Insert(a);
		size++;
	}
	T firstdata() {
		return header->data;
	}
	Node<T>* gethead() { return header; }
	void Update(T a) {
		Node<T>* temp = header;
		while (temp != NULL) {
			if (temp->data == a) {
				temp->data = a * 10;
				return;
			}
			temp = temp->next;
		}
	}
	void Del(T a) {
		Node<T>* temp = header;
		if (header->data == a) {
			temp = header;
			header = header->next;
			delete[]temp;
			size--;
			return;
		}
		while (temp->next != NULL) {
			if (temp->next->data == a) {
				Node<T>* temp1 = temp->next;
				temp->next = temp->next->next;
				delete[]temp1;
				size--;
				return;
			}
			temp = temp->next;
		}
	}
	int getsize() { return size; }
	void createLoop() {
		header->loop(header->next->next);
	}
};