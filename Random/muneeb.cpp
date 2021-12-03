#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* next;
	Node* prev;

	Node* head;
	Node* tail;
	Node* last;
	Node* temp;
	Node* temp2;

	Node()
	{
		next = NULL;
		prev = NULL;
        head=NULL;
        tail=NULL;
        last=NULL;
        temp=NULL;
        temp2=NULL;
	}

	// Parameterised Constructor
	Node(T data)
	{
		this->data = data;
		next = NULL;
		prev = NULL;
        head=NULL;
        tail=NULL;
        last=NULL;
        temp=NULL;
        temp2=NULL;
	}

	void addToTail(T data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
			last = tail;
		}
	}

	void print() {
		temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

	void deleteFromAny(Node* t) {
		if (t->next != NULL)
			t->next->prev = t->prev;
		if (t->prev != NULL)
			t->prev->next = t->next;
	}

	void removeDup() {
		Node* nextNode = NULL;
		temp = head;
		for (int i = 1; temp != NULL; i++) {
			temp2 = temp->next;
			while (temp2 != NULL) {
				if (temp->data == temp2->data) {
					nextNode = temp2->next;
					deleteFromAny(temp2);
					temp2 = nextNode;
				}
				else
					temp2 = temp2->next;
			}
			temp = temp->next;
		}
	}

	void swap(Node* first, Node* second) {
		T value = first->data;
		first->data = second->data;
		second->data = value;
	}

	void sort() {
		if (head == NULL)
			return;
		bool task = true;
		temp = head;
		while (task == true) {
			task = false;
			while (temp != NULL && temp->next != NULL) {
				if (tolower(temp->data[0]) > tolower(temp->next->data[0])) {
					swap(temp, temp->next);
					task = true;
				}
				temp = temp->next;
			}
			temp = head;
		}
	}
};


int main() {

	Node<string> words;

	string text;
	getline(cin, text);

	stringstream ss(text);
	string Buf;

	while (ss >> Buf)
		words.addToTail(Buf);

	words.removeDup();
	words.sort();
	words.print();
	getchar();
}