#include<iostream>
#include<fstream>
using namespace std;
class LNode {
public:
	char data;
	int freq;
	LNode* next;
	LNode(char a) :data(a), freq(1), next(NULL) {}
};
class List {
private:
	LNode* head;
public:
	List() :head(NULL) {}
	void Insert(char a) {
		LNode* temp = head;
		if (!temp) {
			head = new LNode(a);
			return;
		}
		while (temp->next && temp->next->data < a) {
			temp = temp->next;
		}
		if (temp->next && temp->next->data == a)
			temp->next->freq++;
		else {
			LNode* t = new LNode(a);
			t->next = temp->next;
			temp->next = t;
		}
	}
	void display() {
		LNode* temp = head;
		while (temp) {
			cout << temp->data << "," << temp->freq << "->";
			temp = temp->next;
		}
	}
	void ss() {
		LNode* althead = new LNode(0);
		althead->next = head;
		LNode* trav1 = althead;
		LNode* trav2;
		while (trav1 && trav1->next) {
			trav2 = trav1->next;
			while (trav2 && trav2->next) {
				if (trav1->next->freq < trav2->next->freq) {
					if (trav1->next == trav2) {
						if (trav1->next == head)
							head = trav1->next->next;
						LNode* temp = trav1->next;
						trav1->next = trav1->next->next;
						temp->next = trav1->next->next;
						trav1->next->next = temp;
					}
					else {
						if (trav1->next == head)
							head = trav2->next;
						LNode* temp = trav1->next->next;
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
		LNode* temp = head;
		string ab = "";
		while (temp) {
			ab += temp->data;
			temp = temp->next;
		}
		a << ab;
		a.close();
	}
};

void insert(unsigned char& ch, int a) {
	ch *= 2;
	if (a)
		ch += 1;
}
class Node {
public:
	char data;
	Node* right;
	Node* left;
	Node(char a):data(a),right(NULL),left(NULL){}
};
class HTree {
private:
	Node* root=new Node('*');
public:
	HTree(){}
	HTree(string str) {
		fstream a;
		a.open(str, ios::in);
		char ch;
		while (!a.eof()) {
			ch = a.get();
			Insert(ch);
		}
	}
	void Insert(char a) {
		if (!root->left) {
			root->left = new Node(a);
			return;
		}
		Node* temp = root;
		while (temp->right)
			temp = temp->right;
		temp->right = new Node('*');
		temp->right->left = new Node(a);
	}
	unsigned char rev(unsigned char a) {
		unsigned char ch = 0;
		for (int i = 0; i < 7; i++) {
			if (a % 2)
				ch++;
			a /= 2;
			ch *= 2;
		}
		ch += a;
		return ch;
	}
	void Display() {
		Node* temp = root;
		while (temp) {
			cout << temp->left->data << endl;
			temp = temp->right;
		}
	}
	void Decode(string a) {
		fstream re(a, ios::in | ios::binary);
		unsigned char ch;
		Node* temp = root;
		while (1) {
			re.read((char *)&ch, 1);
			ch = rev(ch);
			for (int i = 0; i < 8; i++) {
				if (ch % 2) {
						temp = temp->right;
				}
				else {
					cout << temp->left->data;
					temp = root;
				}
				ch /= 2;
			}
			if (re.peek() == EOF)
				return;
		}

	}
	void Encode(string a, string b) {
		fstream re(a, ios::in | ios::binary);
		fstream we(b, ios::out | ios::binary);
		char ch;
		unsigned char to_write = 0;
		int bit = 0;
		while (1) {
			re.read(&ch, sizeof(ch));
			Node* temp = root;
			while (temp) {
				if (bit == 8) {
					we.write((char *)&to_write, 1);
					bit = 0;
					to_write = 0;
				}
				if (temp->left->data == ch) {
					insert(to_write, 0);
					bit++;
					break;
				}
				else {
					temp = temp->right;
					insert(to_write, 1);
					bit++;
				}
			}
			if (re.peek() == EOF)
				break;
		}
		if (bit <= 8) {
			while (bit <= 8) {
				bit++;
				insert(to_write, 0);
			}
			we.write((char *)&to_write, 1);
		}
		re.close();
		we.close();
	}

};

int main() {
	fstream a;
	a.open("Text.txt", ios::in);
	unsigned char ch;
	List alp;
	while (!a.eof()) {
	ch = a.get();
	alp.Insert(ch);
	if (a.peek() == EOF)
		break;
	}
	alp.ss();
	a.close();
	alp.wtf();
	HTree alpha("Hoffman.txt");
	alpha.Encode("Text.txt", "Out.txt");
	alpha.Decode("Out.txt");
}