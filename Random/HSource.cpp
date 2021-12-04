#include<iostream>
#include<fstream>
using namespace std;
void insert(char& ch, int a) {
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
	void Display() {
		Node* temp = root;
		while (temp) {
			cout << temp->left->data << endl;
			temp = temp->right;
		}
	}
	void Encode(string a, string b) {
		fstream re(a, ios::in | ios::binary);
		fstream we(b, ios::out | ios::binary);
		char ch;
		while (1) {
			re.read(&ch, sizeof(ch));
			char to_write = 0;
			Node* temp = root;
			while (temp) {
				if (temp->left->data == ch);
				insert(ch, 0);
				else {
					temp=temp->
				}
			}
		}
	}
};

int main() {
	fstream a;
	a.open("Hoffman.txt", ios::in);
	HTree alpha;
	char ch;
	while (!a.eof()) {
		ch = a.get();
		alpha.Insert(ch);
	}
	alpha.Display();
}