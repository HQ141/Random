#include<iostream>
#include"Bst.h"
int main(){
	BST<int> a;
	a.Insert(90);
	a.Insert(80);
	a.Insert(85);
	a.Insert(7);
	a.Insert(5);
	a.Insert(6);
	a.Inorder();
}