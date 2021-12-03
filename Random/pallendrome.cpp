#include<iostream>
#include"list.h"
using namespace std;
int main() {
	int temp;
	int size;
	cin >> temp;
	size = temp;
	cin >> temp;
	List_node<int> List(temp);
	
	for (int i = 0; i < size-1; i++) {
		cin >> temp;
		List.Insert_node(temp);
	}
	//List.print();
	List_node<int>* tp = &List;
	//cout << List.get_lenght()<<endl;
	if (List.Check_Palindrome(tp, tp, 0))
		cout << "Palindrome";
	else
		cout << "Not Palindrome";
	
}
