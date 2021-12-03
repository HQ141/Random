#include<iostream>
using namespace std;
template <class T>
class Node {
public:
	T data;
	Node<T>* left=NULL;
	Node<T>* right=NULL;
	Node(T d) :data(d) {}
	Node() {}
	void Insert(T a) {
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
	void Inorder() {
		if(left)
		left->Inorder();
		cout << data << endl;
		if(right)
		right->Inorder();
	}
	void Preorder() {
		cout << data << endl;
		if (left)
			left->Preorder();
		if (right)
			right->Preorder();
	}
	void Postorder() {
		cout << data << endl;
		if (left)
			left->Postorder();
		if (right)
			right->Postorder();
	}
	Node* Search(T a) {
		if (data == a) {
			cout << "FOUND\n";
			return this;
		}
		if (data > a) {
			if (left)
				return left->Search(a);
			else {
				cout << "NOT FOUND\n";
				return NULL;
			}
		}
		else{
			if (right)
				return right->Search(a);
			else {
				cout << "NOT FOUND\n";
				return NULL;
			}
		}
	}
	Node<T>* RemoveMin(Node<T> *a) {
		if (left) {
			Node<T>* temp = left;
			left = left->RemoveMin(a);
			if (temp == left)
				return this;
			else {
				delete temp;
				return this;
			}
		}
		a->data = data;
		return right;
	}
	Node<T>* Delete(T a) {
		if (data == a) {
			if (!left && !right)
				return NULL;
			if (left && !right)
				return left;
			if (right && !left)
				return right;
			right = right->RemoveMin(this);
			return this;
		}
		if (data > a) {
			if (left) {
				Node<T>* temp = left;
				left = left->Delete(a);
				if (left == temp)
					return this;
				else {
					delete temp;
					return this;
				}
			}
			else {
				cout << "NOT FOUND\n";
				return this;
			}
		}
		else {
			if (right) {
				Node<T>* temp = right;
				right = right->Delete(a);
				if (right == temp)
					return this;
				else {
					delete temp;
					return this;
				}
			}
			else {
				cout << "NOT FOUND\n";
				return this;
			}
		}
	}
};
template<class T>
class BST {
private:
	Node<T>* root = NULL;
public:
	BST():root(NULL){}
	void Insert(T a) {
		if(root)
		root->Insert(a);
		else {
			root = new Node<T>(a);
		}
	}
	void Inorder() {
		if(root)
		root->Inorder();
	}
	void Preorder() {
		if (root)
			root->Preorder();
	}
	void Postorder() {
		if (root)
			root->Postorder();
	}
	Node<T>* Search(T a) {
		if (root)
			return root->Search(a);
		else
			return NULL;
	}
	bool Delete(T a) {
		if (root) {
			Node< T >* temp = root;
			root = root->Delete(a);
			if (root == temp)
				return true;
			else delete temp;
			return false;
		}
		return false;
	}
};