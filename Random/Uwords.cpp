#include<iostream>
using namespace std;
class Node {
public:
	string data;
	Node* prev=NULL;
	Node* next=NULL;
	Node() {};
	Node(string a):data(a){}
};
int strcmp(string a, string b) {
	int as, bs;
	as = a.size();
	bs = b.size();
	for (int i = 0; i < bs && i < as; i++) {
		if (tolower(a[i]) > tolower(b[i]))
			return 1;
		if (tolower(a[i]) < tolower(b[i]))
			return -1;
	}
	if (as > bs)
		return 1;
	if (bs > as)
		return -1;
	return 0;
}
class Dlist {
private:
	Node* top=NULL;
public:
	void Insert(const string &b) {
		string a(b);
		Node* althead = new Node();
		althead->next = top;
		Node* temp = althead;
		if (!top) {
			top = new Node(a);
			return;
		}
		while (temp && temp->next&&(strcmp(temp->next->data, a) <=0)) {
			if (strcmp(temp->next->data, a) == 0) {
				delete althead;
				return;
			}
			temp = temp->next;
		}
		if (!temp->next) {
			temp->next = new Node(a);
			temp->next->prev = temp;
		}
		else {
			Node* t = new Node(a);
			t->next = temp->next;
			t->next->prev = t;
			t->prev = temp;
			temp->next = t;
		}
		top = althead->next;
		delete althead;
	}
	void Display(){
		Node* temp = top;
		if(temp)
		while (temp) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};
int main() {
	Dlist a;
	string temp;
	char t;
	t = getchar();
	while (t < 48) {
		t = getchar();
	}
	while (!cin.eof()&&t!='\n') {
		if (t ==' ') {
			a.Insert(temp);
			temp.clear();
		}
		else
		temp += t;
		t = getchar();
		if(t==EOF)
		break;
	}
	a.Display();
	getchar();
}