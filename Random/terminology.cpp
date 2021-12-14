#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
template <class T>
class Node {
public:
	T data;
	vector<string> count;
	Node<T>* left = NULL;
	Node<T>* right = NULL;
	Node(T d):data(d){}
	Node() {}
	void Insert(string a) {
		if (a > data) {
			if (right)
				right->Insert(a);
			else
				right = new Node<T>(a);
		}
		else {
			if (left)
				left->Insert(a);
			else
				left = new Node<T>(a);
		}
	}
	Node<T>* balance() {
		if (abs(get_bal()) < 2) {
			if (right)
				right = right->balance();
			if (left)
				left = left->balance();
		}
		else if (right && abs(right->get_bal()) == 2) {
			right = right->balance();
		}
		else if (left && abs(left->get_bal()) == 2) {
			left = left->balance();
		}
		else {
			if (get_bal() > 0) {
				if (right->get_bal() > 0) {
					Node<T>* up = right;
					right = up->left;
					up->left = this;
					return up;
				}
				else {
					Node<T>* up = right->left;
					Node<T>* r = right;
					right = up->left;
					r->left = up->right;
					up->right = r;
					up->left = this;
					return up;
				}
			}
			else {
				if (left->get_bal() < 0) {
					Node<T>* up = left;
					left = up->right;
					up->right = this;
					return up;
				}
				else {
					Node<T>* up = left->right;
					Node<T>* l = left;
					left = up->right;
					l->right = up->left;
					up->left = l;
					up->right = this;
					return up;
				}
			}
		}
		return this;
	}
	int get_bal() {
		if (left && right)
			return right->get_h() - left->get_h();
		if (right)
			return right->get_h();
		if (left)
			return -left->get_h();
		return 0;
	}

	int get_h() {
		int r_h = 0;
		int l_h = 0;
		if (right)
			r_h = right->get_h();
		if (left)
			l_h = left->get_h();
		if (r_h > l_h)
			return r_h + 1;
		return l_h + 1;
	}
	void Inorder() {
		if (left)
			left->Inorder();
			cout << data << " ";
			for (int i = 0; i < count.size(); i++)
				cout << count[i] << " ";
			cout << endl;
		if (right)
			right->Inorder();
	}
	void Preorder() {
		cout << data << " ";
		for (int i = 0; i < count.size(); i++)
			cout << count[i] << " ";
		cout << endl;
		if (left)
			left->Inorder();
		
		if (right)
			right->Inorder();
	}
	Node* Search(T a,T c) {
		if (data == a) {
			bool f = true;
			for (int i = 0; i < count.size(); i++)
				if (c == count[i])
					f = false;
			if(f)
			count.push_back(c);
			return this;
		}
		if (data < a) {
			if (right)
				return right->Search(a,c);
			else {
				return NULL;
			}
		}
		else {
			
			if (left)
				return left->Search(a,c);
			else {
				return NULL;
			}
		}
	}
	
};
template<class T>
class BST {
private:
	Node<T>* root = NULL;
	int Max_words=0;
public:
	BST() :root(NULL) {}
	void Insert(T a) {
		stringstream str(a);
		string st;
		int c=0;
		while (1) {
			str >> st;
			c++;
			if (str.peek() == EOF)
				break;
		}
		if (c > Max_words)
			Max_words = c;
		if (root)
			root->Insert(a);
		else {
			root = new Node<T>(a);
		}
		balance();
	}
	void balance() {
		root = root->balance();
	}
	void find(string sss){
		stringstream str(sss);
		string a;
		string b;
		string c;
		if (str.peek() < 30)
			str.get();
		for (int i = 0; i < Max_words; i++) {
			str.clear();
			str.str(sss);
			str.seekp(ios::beg);
			str >> c;
			int back = 0;
			while (1) {
				string b = "";
				str.clear();
				str.str(sss);
				str.seekp(ios::beg);
				for (int i = 0; i < back; i++)
					str >> a;
				string a = "";
				for (int j = 0; j < i + 1; j++) {
					if (str.peek() == EOF)
						a = "";
					else
						str >> a;
					if (b == "")
						b = a;
					else {
						b += " " + a;
						
					}
				}
				back++;
				root->Search(b, c);
				if (str.peek() == EOF)
					break;
			}
		}
		
	}
	Node<T>* Search(T a) {
		if (root)
			return root->Search(a);
		else
			return NULL;
	}
	void Inorder() {
		if (root)
			root->Inorder();
	}
	void Preorder() {
		if (root)
			root->Preorder();
	}
};
int main() {
	BST <string>alpha;
	int a;
	cin >> a;
	string str;
	for (int i = 0; i < a; i++) {
		if (cin.peek() < 30)
			getchar();
		getline(cin,str);
		alpha.Insert(str);
	}
	while (cin.peek() != EOF) {
		getline(cin, str);
		alpha.find(str);
	}
		alpha.Inorder();
}