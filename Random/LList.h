#ifndef LLIST_H
#define LLIST_H
#include<iostream>
using namespace std;
template<class T>
class Node {
public:
	T data;
	Node* next;
	Node(T a):data(a),next(NULL){}
	void InsertM(Node<T>* add,T a) {
		if (this == add) {
			Node<T>* New = new Node<T>(a);
			New->next = next;
			next = New;
			return;
		}
		next->InsertM(add,a);
	}
	void loop(Node<T>* add) {
		if (next == NULL) {
			next = add;
			return;
		}
		next->loop(add);
	}
	void Insert(Node* a) {
		if (next == NULL) {
			next = a;
			return;
		}
		next->Insert(a);

	}
	void correct() {
		Node<T>* temp = next;
		bool p = false;
		for (int i = 0; i < 69; i++) {
			if(temp!=NULL)
			if (temp->next== this) {
				temp->next = NULL;
				p = true;
			}
			if (temp == NULL)
				return;
			temp = temp->next;
		}
		if (!p)
			next->correct();
	}
	void Reverse(Node<T>* add) {
		if (next == NULL) {
			next = add;
			return;
		}
		next->Reverse(this);
		next = add;
		return;
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
	void ss() {
		Node<T>* althead = new Node<T>(0);
		althead->next = header;
		Node<T>* trav1 = althead;
		Node<T>* trav2;
		while (trav1 && trav1->next) {
			trav2 = trav1->next;
			while (trav2 && trav2->next) {
				if (trav1->next->data > trav2->next->data) {
					if (trav1->next == trav2) {
						Node<T>* temp = trav1->next;
						trav1->next = trav1->next->next;
						temp->next = trav1->next->next;
						trav1->next->next = temp;
					}
					else {
						Node<T>* temp = trav1->next->next;
						trav1->next->next = trav2->next->next;
						trav2->next->next = temp;
						temp = trav1->next;
						trav1->next = trav2->next;
						trav2->next = temp;
					}
					header=althead->next;
				}
				trav2 = trav2->next;
			}
			trav1 = trav1->next;
		}
		delete[]althead;
	}
	bool revcheck(Node<T>*prev,Node<T>* cur, Node<T>* des) {
		if (cur == des||cur->next==NULL)
			return true;
		if (!revcheck(cur, cur->next, des))
			return 0;
		if (cur->data <= cur->next->data)
			return 0;
		if (prev) {
			prev->next = cur->next;
			cur->next = prev->next->next;
			prev->next->next = cur;
		}
		else {
			header = cur->next;
			cur->next = header->next->next;
			header->next->next = cur;
		}
		return 1;
	}
	void is() {
		Node<T>* trav = header->next;
		while (trav) {
			revcheck(NULL,header, trav);
			trav = trav->next;
		}
	}
	void bs() {
		Node<T>* althead = new Node<T>(0);
		althead->next = header;
		int count=0;
		Node<T>* trav =althead;
		while (trav->next) {
			trav = trav->next;
			count++;
		}
		while (count != 0) {
			trav = althead;
			while (trav->next && trav->next->next) {
				if (trav->next->data > trav->next->next->data) {
					if (trav->next == header)
						header = trav->next->next;
					Node<T>* temp = trav->next;
					trav->next = trav->next->next;
					temp->next = trav->next->next;
					trav->next->next = temp;
				}
				trav = trav->next;
			}
			count--;
		}
		delete[]althead;
	}
	void EbO() {
		Node<T>* t1 = header;
		Node<T>* l1 = NULL;
		Node<T>* t2 = header;
		Node<T>* l2 = NULL;
		while (t1!=NULL) {
			if (t1->data % 2 == 1) {
				t2 = t1->next;
				l2 = t1;
				while (t2!=NULL) {
					if (t2->data % 2 == 0) {
						if (header == t1)
							header = t2;
						else 
							l1->next = t2;
						Node<T>* temp = t2->next;
						if (t1->next != t2) {
							t2->next = t1->next;
							t1->next = temp;
							l2->next = t1;
							break;
						}
						t2->next = t1;
						t1->next = temp;
						break;
					}
					l2 = t2;
					t2 = t2->next;
				}
				if (t2==NULL)
					return;
				else {
					l1 = l2;
					t1 = t2;
				}
			}
			l1 = t1;
			t1 = t1->next;
		}
	}

	Node<T>* outfirst() {
		Node <T>*temp = header;
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


	void InsertS(T a) {
		Node<T>* temp = new Node<T>(a);
		temp->next = header;
		header = temp;
		size++;
	}
	void InsertM(Node<T>* add, T a) {
		header->InsertM(add, a);
		size++;
	}
	T firstdata() {
		return header->data;
	}
	Node<T>* gethead() { return header; }
	void Reverse() {
		Node<T>* temp = header;
		while (header->next!=NULL)
		{
			header = header->next;
		}
		temp->Reverse(NULL);
	}
	void Update(T a) {
		Node<T>* temp = header;
		while (temp != NULL) {
			if (temp->data == a) {
				temp->data = a*10;
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
		while (temp->next!= NULL) {
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
	void LoopCheck() {
		header->correct();
	}
};
template<class T>
void merge(sList <T>& temp, sList<T>& a, sList<T>& b) {
	while (a.getsize() != 0 && b.getsize() != 0)
	{
		if (a.firstdata() < b.firstdata())
			temp.insert(a.outfirst());
		else temp.insert(b.outfirst());
	}
	while (a.getsize() != 0) {
		temp.insert(a.outfirst());
	}
	while (b.getsize() != 0) {
		temp.insert(b.outfirst());
	}
}
template<class T>
void mergesort(sList<T>& list) {
	if (list.getsize() == 1)
		return;
	int size = list.getsize();
	int mid = list.getsize() / 2;
	sList<T>a;
	sList<T>b;
	for (int i = 0; i < mid; i++)
		a.insert(list.outfirst());
	for (int i = mid; i < size; i++)
		b.insert(list.outfirst());
	mergesort(a);
	mergesort(b);
	merge(list, a, b);
}

#endif
