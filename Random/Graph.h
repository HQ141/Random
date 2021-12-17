#include<iostream>
#include<vector>
using namespace std;
#ifndef GRAPH_H
#define GRAPH_H
template<class T>
class Enode {
public:
	T data;
	Enode<T>* next = NULL;
	Enode(T a):data(a){}
	void Insert(T a) {
		if (!next)
			next = new Enode<T>(a);
		else {
			next->Insert(a);
		}
	}
	void display() {
		cout << data << "->";
		if (next)
			next->display();
		else
			cout << "NULL";
	}
};
template<class T>
class Vnode {
public:
	T Vertice;
	Enode<T>* data;
	Vnode<T>* next = NULL;

	Vnode(T a) {
		Vertice = a;
		data = NULL;
	}
	void Insert_vertice(T a) {
		if (!next)
			next = new Vnode<T>(a);
		else
			next->Insert_vertice(a);
	}
	void display() {
		cout << Vertice << "->";
		if (data)
			data->display();
		else
			cout << "NULL";
		cout << endl;
		if(next)
		next->display();
	}
	void Insert_edge(T a) {
		if (!data)
			data = new Enode<T>(a);
		else
			data->Insert(a);
	}
};
template<class T>
class Adjacency_Graph {
private:
	Vnode<T>* head;
public:
	Adjacency_Graph():head(NULL){}
	void Insert_Vertices(T a) {
		if (!head) {
			head =new  Vnode<T>(a);
		}
		else {
			head->Insert_vertice(a);
		}
			
	}
	void Insert_edges(T a,T b) {
		Vnode<T>* trav = head;
		bool found = false;
		while (trav ) {
			if (trav->Vertice == a) {
				trav->Insert_edge(b);
				found = true;
			}
			trav = trav->next;
		}
		if (!found)
			return;
		trav = head;
		while (trav ) {
			if (trav->Vertice == b) {
				trav->Insert_edge(a);
				found = true;
			}
			trav = trav->next;
		}
	}
	void display() {
		if(head)
		head->display();
	}
};
class Adjuncy_matrix {
private:
	int** arr;
	int xa, ya;
public:
	Adjuncy_matrix(int x, int y):xa(x),ya(y) {
		arr = new int* [x];
		for (int i = 0; i < x; i++) {
			arr[i] = new int[y];
			for (int j = 0; j < y; j++)
				arr[i][j] = 0;
		}
	}
	~Adjuncy_matrix() {
		for (int i = xa - 1; i >= 0; i--)
			delete arr[i];
		delete arr;
	}
	void Insert_edges(int x, int y) {
		arr[x][y]++;
		arr[y][x]++;
	}
	void Display() {
		for (int i = 0; i < xa; i++) {
			for (int j = 0; j < ya; j++)
				cout << arr[i][j];
			cout << endl;
		}
	}

};
#endif // !GRAPH_H
