#ifndef GGRAPH_H
#define GGRAPH_H
#include<iostream>
using namespace std;
template<class T>
class Lnode {
public:
	T data;
	Lnode<T>* next;
	Lnode(T a):data(a),next(NULL) {
	}
};
template<class T>
class Stack {
private:
	Lnode<T>* front;
public:
	Stack() :front(NULL) {}
	void Enqueue(T a) {
		Lnode<T>* temp = new Lnode<T>(a);
		temp->next = front;
		front = temp;
	}
	T Front() { return front->data; }
	void DeQueue() {
		Lnode<T>* temp = front;
		front = front->next;
		delete temp;
	}
	bool Empty() { return !front; }
};
template<class T>
class Queue {
private:
	Lnode<T>* front;
public:
	Queue():front(NULL){}
	void Enqueue(T a) {
		if (!front)
			front = new Lnode<T>(a);
		else {
			Lnode<T>* trav = front;
			while (trav->next) {
				trav = trav->next;
			}
			trav->next = new Lnode<T>(a);
		}
	}
	T Front() { return front->data; }
	void DeQueue() {
		Lnode<T>* temp = front;
		front = front->next;
		delete temp;
	}
	bool Empty() { return !front; }
};
template<class T>
class LList {
private:
	Lnode<T>* It;
	Lnode<T>* root;
public:
	template <class A>
	T Contains(A a) {
		if (!root) {
			return NULL;
		}
		Lnode<T>* temp = root;
		while (temp) {
			if (a == temp->data->getdata())
				return temp->data;
			temp = temp->next;
		}
		return NULL;
	}
	void reset() {
		Lnode<T>* temp = root;
		while (temp) {
			temp->data->reset();
			temp = temp->next;
		}
		return;
	}
	bool Empty() {
		if (root)
			return true;
		return false;
	}
	LList():root(NULL){}
	void PushVertice(T a) {
		if (!root) {
			root = new Lnode<T>(a);
			It = root;
			return;
		}
		Lnode<T>* temp = root;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new Lnode<T>(a);
		It = root;
	}
	void DisplayVer() {
		Lnode<T>* temp = root;
		while (temp != NULL) {
			temp->data->display();
			cout << endl;
			temp = temp->next;
		}
	}
	void DisplayEdg() {
		Lnode<T>* temp = root;
		while (temp != NULL) {
			temp->data->display();
			temp = temp->next;
		}
	}
	void PushEdge(T a) {
		if (!root) {
			root =new Lnode<T>(a);
			It = root;
			return;
		}
		Lnode<T>* temp = root;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new Lnode<T>(a);
		It = root;
	}
	void Itset() { It = root; }
	T ITget() { 
		if (It) {
			Lnode<T>* temp = It;
			It = It->next; 
			return temp->data;
		}
		return NULL; 
	}
};
template<class T>
class Vnode {
	public:
	T data;
	LList<Vnode<T>*> edges;
	bool visited = false;

	T getdata() { return data; }
	Vnode(T a):data(a){}
	void display() {
		cout << data << "->";
		if (edges.Empty())
			edges.DisplayEdg();
	}
	Vnode<T>* Fedge() { return edges.front(); }
	void InsertEgde(Vnode<T>* a) {
		edges.PushEdge(a);
	}
	void reset() { visited = false; }
	bool status() { return visited; }
	void set() { visited = true; }
};
template<class T>
class Graph {
	bool* ar;
	T* darr;
	LList<Vnode<T>*> Vertices;
public:
	void insertVertice(T a) {
		Vertices.PushVertice(new Vnode<int>(a));

	}
	void DInsertEdges(T a, T b) {
		Vnode <T>* trav1 = Vertices.Contains<int>(a);
		Vnode <T>* trav2 = Vertices.Contains<int>(b);
		trav1->InsertEgde(trav2);
	}
	void UInsertEdges(T a, T b) {
		Vnode <T>* trav1 = Vertices.Contains<int>(a);
		Vnode <T>* trav2 = Vertices.Contains<int>(b);
		trav1->InsertEgde(trav2);
		trav2->InsertEgde(trav1);
	}
	void Display() {
		Vertices.DisplayVer();
	}
	void resetvist() {
		Vertices.reset();
	}
	void Bfs() {
		cout << endl;
		Queue<Vnode<T>*> beta;
		Vertices.Itset();
		beta.Enqueue( Vertices.ITget());
		Vnode<T>* trav = beta.Front();
		beta.DeQueue();
		while (1) {
			if (!trav->status()) {
				trav->edges.Itset();
				Vnode<T>* temp = trav->edges.ITget();
				while (temp) {
					if (!temp->status()) {
						beta.Enqueue(temp);
					}
					temp = trav->edges.ITget();
				}
				trav->set();
				cout << trav->getdata() << "->";
			}
			if (beta.Empty()) {
				trav = Vertices.ITget();
				if(!trav)
				break;
			}
			else {
				trav = beta.Front();
				beta.DeQueue();
			}
		}
	}
	void Dfs() {
		cout << endl;
		Stack<Vnode<T>*> beta;
		Vertices.Itset();
		beta.Enqueue(Vertices.ITget());
		Vnode<T>* trav = beta.Front();
		beta.DeQueue();
		while (1) {
			if (!trav->status()) {
				trav->edges.Itset();
				Vnode<T>* temp = trav->edges.ITget();
				while (temp) {
					if (!temp->status()) {
						beta.Enqueue(temp);
					}
					temp = trav->edges.ITget();
				}
				trav->set();
				cout << trav->getdata() << "->";
			}
			if (beta.Empty()) {
				trav = Vertices.ITget();
				if (!trav)
					break;
			}
			else {
				trav = beta.Front();
				beta.DeQueue();
			}
		}
	}
};



#endif // !GGRAPH_H

