#include<iostream>
using namespace std;
class A
{
public:
    int data;
    A* next;
public:
    A()
    {}
    A(int a)
    {
        next = NULL;
        data = a;
    }
};
class Handle
{
public:
    A* head;
    A* tail;
    A* temp;
public:
    Handle()
    {
        temp = NULL;
        head = NULL;
        tail = NULL;

    }
    void insertValue(int a)
    {
        A* obj = new A(a);
        if (head == NULL)
        {
            head = obj;
            tail = head;
            return;
        }
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail = obj;
    }
    int getdata(int pos) {
        temp = head;
        for (int i = 0; i < pos-1; i++)
            temp = temp->next;
        return temp->data;
    }
    bool check(int size)
    {
        for (int i = 0; i < size / 2; i++) {
            if (getdata(i) != getdata(size - 1 - i))
                return false;
        }
        return true;
    }
    void display(int size)
    {
        cout << tail->data;
    }

};
int main()
{
    Handle obj;
    int size, d;
    cout << "Enter number of data lists" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        //cout << "Enter data in list" << endl;
        //cin >> d;
        obj.insertValue(i);
    }
    if (obj.check(size))
        cout << "It is a Pallindrome";
    else
        cout << "It is not a Pallindrome";

}