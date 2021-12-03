#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
	string data;
	Node* prev;
	Node* next;
	Node(string x)
	{
		data = x;
		prev= NULL;
		next = NULL;
	}
};
class LinkedList
{
	Node* head;
	Node* tail;
public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	void insert(string a)
	{
		for (auto temp1 = head; temp1 != NULL; temp1 = temp1->next)
		{
			if (a == temp1->data)
				return;
		}
		Node* newnode = new Node(a);
		if (!head && !tail)
		{
			head = newnode;
			tail = newnode;
			return;
		}
		else if (newnode->data > head->data)
		{
			Node* temp = head;
			for (; temp->next != NULL && (newnode->data > temp->next->data); temp = temp->next);
			Node* ptr = temp->next;
			temp->next = newnode;
			newnode->prev = temp;
			newnode->next = ptr;
			tail = newnode;
			return;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}
	void Display()
	{
		for (auto temp = head; temp != NULL; temp = temp->next)
			cout << temp->data << endl;
	}
};
int main()
{
	LinkedList l1;
	/*l1.insert("AA");
	l1.insert("BAA");
	l1.insert("BAB");
	l1.insert("CCC");
	l1.insert("AAA");
	l1.insert("AAP");
	l1.insert("CCD");
	l1.insert("DAB");
	l1.insert("DBA");
	l1.insert("AAA");
	l1.insert("AAA");
	l1.insert("AAP");*/
	string x;
	char ch;
	while(1)
	{
		ch = getchar();
		if (ch == 10)
			break;
		else if (ch == 32)
		{
			if (x.size())
			{
				l1.insert(x);
				x.clear();

			}
			else
			{
				x.clear();
			}
		}
		else
		{
			x.push_back(ch);
		}
	}
	//getchar();
	l1.Display();
	getchar();
}