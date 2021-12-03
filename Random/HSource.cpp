#include<iostream>
#include<fstream>
using namespace std;
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