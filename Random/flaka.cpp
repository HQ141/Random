#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
    char variable;
    int coefficient;
    int power;
    Node* next;
    Node* prev;
    bool flag;
    Node(int i, char d, int j)
    {
        coefficient = i;
        variable = d;
        power = j;
        next = NULL;
        prev = NULL;
        flag = false;
    }
};
class DoublyLinkedList
{
    Node* head;
public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void AppendNode(int i, char d, int j)
    {
        Node* obj = new Node(i, d, j);
        if (head == NULL)
        {
            head = obj;
            return;
        }
        else
        {
            Node* tail = head;
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = obj;
            obj->prev = tail;
        }
    }

    //bool CheckDuplicate(Node* head, Node* ptr)
    //{
    //    Node* traverse = head;
    //    while (traverse != NULL)
    //    {
    //        if (traverse->coefficient == ptr->coefficient && traverse->variable == ptr->variable && traverse->power == ptr->power)
    //            return 1;
    //        traverse = traverse->next;
    //    }
    //    return 0;
    //}

    void SolvePolynomial(const DoublyLinkedList& obj)
    {
        int flag1 = -1;
        int counter = 0;
        int f = -1;
        DoublyLinkedList d;
        Node* previous1 = NULL;
        Node* previous2 = NULL;
        int value = 0;
        for (Node* i = head; i != NULL; i = i->next)
        {
            for (Node* j = obj.head; j != NULL; j = j->next)
            {
                if (i->variable == j->variable && i->power == j->power)
                {
                    if (!j->flag)
                    {
                        i->coefficient += j->coefficient;
                        j->flag = true;
                        f = 1;
                    }
                }
            }
            d.AppendNode(i->coefficient, i->variable, i->power);
                //counter++;
        //    if (f)
            //    i->flag = true;
            //f = -1;
        }
        Node* ptr1 = head;
        Node* ptr = obj.head;
        while (ptr != NULL)
        {
            if (!ptr->flag)
            {
                d.AppendNode(ptr->coefficient, ptr->variable, ptr->power);
                //counter++;
            }
            ptr = ptr->next;
        }
        d.Sort();
        for (Node* y = d.head; y != NULL; y = y->next)
        {
            for (Node* z = y->next; z != NULL; z = z->next)
            {
                if (y->variable == z->variable && y->power == z->power && !z->flag)
                {
                    y->coefficient += z->coefficient;
                    z->flag = true;
                    //counter++;
                }
            }
        }
        //cout << counter << endl;
        d.print();
    }
    
    void Sort()
    {
        for (Node* i = head; i != NULL; i = i->next)
        {
            for (Node* j = i->next; j != NULL; j = j->next)
            {
                if(i->power > j->power)
                //if (i->power == j->power)
                    swap(i, j);
                else if (i->variable > j->variable)
                    swap(i, j);
            }
        }
    }
    void swap(Node* i, Node* j)
    {
        int temp1;
        temp1 = j->power;
        j->power = i->power;
        i->power = temp1;

        int temp2;
        temp2 = j->coefficient;
        j->coefficient = i->coefficient;
        i->coefficient = temp2;

        char temp3;
        temp3 = j->variable;
        j->variable = i->variable;
        i->variable = temp3;

        return;
    }
    void print()
    {
        int counter = 0;
        Node* temp = head;
        while (temp != NULL)
        {
            if (!temp->flag)
                counter++;
            temp = temp->next;
        }
        cout << counter << endl;;
        temp = head;
        while (temp != NULL)
        {
            if (!temp->flag)
            {
                cout << temp->coefficient << " " << temp->variable << " " << temp->power << endl;
            }            
            temp = temp->next;
        }
    }
};
int main()
{
    char s;
    int a, b;
    DoublyLinkedList l1;
    int n1, n2;
    cin >> n1;
    if(n1 < 0)
        exit(0);
    for (int i = 0; i < n1; i++)
    {
        cin >> a >> s >> b;
        l1.AppendNode(a, s, b);
    }
    DoublyLinkedList l2;
    cin >> n2;
    if(n2 < 0)
        exit(0);
    for (int i = 0; i < n2; i++)
    {
        cin >> a >> s >> b;
        l2.AppendNode(a, s, b);
    }
    l1.SolvePolynomial(l2);
}