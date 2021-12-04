#include<iostream>
#include<fstream>
using namespace std;
class Node {
public:
	char data;
	int freq;
	Node* next;
	Node(char a):data(a),freq(1),next(NULL){}
};
class List {
private:
	Node* head;
public:
	List():head(NULL){}
	void Insert(char a) {
		Node* temp = head;
		if (!temp) {
			head = new Node(a);
			return;
		}
		while (temp->next&&temp->next->data < a) {
			temp = temp->next;
		}
		if (temp->next&&temp->next->data == a)
			temp->next->freq++;
		else {
			Node* t = new Node(a); 
			t->next = temp->next;
			temp->next = t;
		}
	}
	void display() {
		Node* temp = head;
		while (temp) {
			cout << temp->data <<","<<temp->freq << "->";
			temp = temp->next;
		}
	}
	void ss() {
		Node* althead = new Node(0);
		althead->next = head;
		Node* trav1 = althead;
		Node* trav2;
		while (trav1 && trav1->next) {
			trav2 = trav1->next;
			while (trav2 && trav2->next) {
				if (trav1->next->freq < trav2->next->freq) {
					if (trav1->next == trav2) {
						if (trav1->next == head)
							head = trav1->next->next;
						Node* temp = trav1->next;
						trav1->next = trav1->next->next;
						temp->next = trav1->next->next;
						trav1->next->next = temp;
					}
					else {
						if (trav1->next == head)
							head = trav2->next;
						Node* temp = trav1->next->next;
						trav1->next->next = trav2->next->next;
						trav2->next->next = temp;
						temp = trav1->next;
						trav1->next = trav2->next;
						trav2->next = temp;
					}
				}
				trav2 = trav2->next;
			}
			trav1 = trav1->next;
		}
		delete althead;
	}
	void wtf() {
		fstream a;
		a.open("Hoffman.txt", ios::out);
		Node* temp = head;
		string ab = "";
		while (temp) {
			ab+=temp->data;
			temp = temp->next;
		}
		a << ab;
		a.close();
	}
};

//int main() {
//	fstream a;
//	a.open("text.txt", ios::in);
//	unsigned char ch;
//	List alpha;
//	while (!a.eof()) {
//		ch = a.get();
//		if(ch>10&&ch<128)
//		alpha.Insert(ch);
//	}
//	alpha.ss();
//	a.close();
//	alpha.wtf();
//}