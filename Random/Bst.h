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
	Node<T>* balance() {
		if (abs(get_bal()) < 2) {
			if(right)
			right = right->balance();
			if (left)
				left = left->balance();
		}
		else if (right&& abs(right->get_bal()) == 2) {
				right = right->balance();
		}
		else if (left&& abs(left->get_bal()) == 2) {
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
			r_h=right->get_h();
		if (left)
			l_h = left->get_h();
		if (r_h > l_h)
			return r_h + 1;
		return l_h + 1;
	}
	void Inorder() {
		if(left)
		left->Inorder();
		cout << data <<" " << get_h()<<" "<<get_bal() << endl;
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
		balance();
	}
	void balance() {
		root = root->balance();
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