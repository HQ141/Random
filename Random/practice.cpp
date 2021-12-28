#include<iostream>
using namespace std;
class Node {
public:
	string data;
	Node* next;
	Node(string a):data(a),next(NULL) {};
};
class Stack {
	Node* top;
public:
	Stack():top(NULL){}
	void Push_back(string a) {
		Node* temp = new Node(a);
		temp->next = top;
		top = temp;
	}
	void Pop() {
		if (!top)
			return;
		Node* temp = top;
		top = top->next;
		delete temp;
	}
	string Top() {
		if(top)
		return top->data;
	}
	bool empty() {
		if (top == NULL)
			return true;
		return false;
	}
};
int main() {
	Stack alpha;
	char a;
	string str;
	a=getchar();
	while (a != '\n') {
		if (a != ')') {
			str = a;
			alpha.Push_back(str);
		}
		else{
			str = a;
			for (int i = 0; i < 3; i++) {
				str += alpha.Top();
				alpha.Pop();
			}
			str += '(';
			alpha.Push_back(str);
		}
		a = getchar();
	}
	str = "";
	while (!alpha.empty()) {
		str += alpha.Top();
		alpha.Pop();
	}
	string ab="";
	for (int i = 0; i < str.size(); i++) {
		ab = str[i];
		alpha.Push_back(ab);
	}
	while (!alpha.empty()) {
		cout << alpha.Top();
		alpha.Pop();
	}
}