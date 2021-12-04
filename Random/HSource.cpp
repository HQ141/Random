#include<iostream>
#include<fstream>
using namespace std;
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
	HTree alpha("Hoffman.txt");
	alpha.Display();
	alpha.Encode("Text.txt", "Out.txt");
	alpha.Decode("Out.txt");
}