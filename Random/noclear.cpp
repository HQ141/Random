#include <iostream>
#include <sstream>
using namespace std;
class lnode
{
	public:
		string data;
		lnode* next;
		lnode()
		{
			next=NULL;
		}
		lnode(string x)
		{
			data=x;
			next=NULL;
		}
};
class ll
{
	public:
		lnode* head;
		ll()
		{
			head=NULL;
		}
		void display()
		{
			lnode *current=head;
			while(current!=NULL)
			{
				cout<<current->data<<"->";
				current=current->next;
			}
			cout<<"NULL\n";
		}
		int listlen()
		{
			int count=0;
			lnode *ptr=head;
			while(ptr!=NULL)
			{
				ptr=ptr->next;
				count++;
			}
			return count;
		}
		void insertnode(string d)
	    {
	        lnode *ptr=new lnode();
	        if(head==NULL)
	        {
	            head=ptr;
	            ptr->data=d;
	            return;
	        }
	        lnode *last=head;
	        while(last->next!=NULL)
	        {
	            last=last->next;
	        }
	        last->next=ptr;
	        ptr->data=d;
	    }
		void swap(int x,int y)
		{
			lnode *n1=head;
			lnode *n2=head;
			lnode *p1;
			lnode *p2;
			lnode *temp;
			if(x==y)
			{
				return;
			}
			if(x==1)
			{
				for(int i=0;i<y-1;i++)
				{
					p2=n2;
					n2=n2->next;
				}
				p2->next=n1;
				temp=n2->next;
				n2->next=n1->next;
				n1->next=temp;
				head=n2;
				return;
			}
			if(y==1)
			{
				for(int i=0;i<x-1;i++)
				{
					p1=n1;
					n1=n1->next;
				}
				p1->next=n2;
				temp=n1->next;
				n1->next=n2->next;
				n2->next=temp;
				head=n1;
				return;
			}
			for(int i=0;i<x-1;i++)
			{
				p1=n1;
				n1=n1->next;
			}
			for(int i=0;i<y-1;i++)
			{
				p2=n2;
				n2=n2->next;
			}
			p1->next=n2;
			p2->next=n1;
			temp=n1->next;
			n1->next=n2->next;
			n2->next=temp;
		}
		void bubblesort()
		{
			int count=1;
			
			while(count<listlen())
			{		
				for(int i=0;i<listlen()-count;i++)
				{
					lnode *ptr1=head;
					for(int k=0;k<i;k++)
					{
						ptr1=ptr1->next;
					}
					lnode *ptr2=ptr1->next;	
					if(ptr1->data>ptr2->data)
					{
						swap(i+1,i+2);
					}
				}
				count++;
			}
		}
};
class node
{
	public:
		string data;
		string name;
		node* right;
		node* left;
		node()
		{
			right=NULL;
			left=NULL;
		}
		node(string x,string y)
		{
			data=x;
			name=y;
			right=NULL;
			left=NULL;
		}
};
class bst
{
	public:
		node *root;
		bst()
		{
			root=NULL;
		}
		node *insert(node* here, string data,string name) 
		{
  			if(here==NULL) 
  			{
  				return new node(data,name);	
			}
  			if (data<here->data)
  			{
  				here->left=insert(here->left,data,name);
			}	
  			else
  			{
  				here->right=insert(here->right,data,name);
			}
  			return here;
		}
		void inorder(node* ptr) 
		{
	        if (ptr!=NULL) 
			{
	            inorder(ptr->left);
	            cout<<ptr->data<<" ";
	            inorder(ptr->right);
	        }
    	}
    	node* search(node* root,string key)
		{
			if(root==NULL)
			{
				return NULL;
			}
		    if (root == NULL || root->data == key)
		        return root;
		    if (root->data < key)
		        return search(root->right, key);
			else
		    	return search(root->left, key);
		}
};
int main()
{
	int size,size2;
	cin>>size;
	string s;
	ll list;
	for(int i=0;i<=size;i++)
	{
		getline(cin,s);
		list.insertnode(s);
	}
	list.display();
	list.bubblesort();
	cin>>size2;
	string t,word;
	bst *tree=new bst[size2+1];
	for(int i=0;i<=size2;i++)
	{
		getline(cin,t);
	    istringstream iss(t);
	    iss>>s;
	    while(iss>>word) 
		{
	        tree[i].root=tree[i].insert(tree[i].root,word,s);
	    }
	}
	lnode* ptr=list.head->next;
	node* curr;
	string ans="\0";
	bool check=false;
	int count;
	for(int i=0;i<=size;i++)
	{
		t=ptr->data;
		cout<<t<<" ";
		for(int j=1;j<=size2;j++)
		{
			check=false;
			ans="\0";
			count=0;
			istringstream iss(t);
		    while(iss>>word) 
			{
				if(check==false)
				{
					if(count>0)
					{
						break;
					}
					curr=tree[j].search(tree[j].root,word);
					if(curr!=NULL)
					{
						ans=curr->name;
			        	check=true;	
					}
				}
		        if(check==true)
		        {
		        	curr=tree[j].search(tree[j].root,word);
		        	if(curr==NULL || ans!=curr->name)
		        	{
						check=false;
						ans="\0";
						break;
					}
				}
				count++;
		    }
		    if(ans!="\0")
		    {
		    	cout<<ans<<" ";	
			}
		}		
		ptr=ptr->next;
		cout<<endl;
	}
	return 0;
}
