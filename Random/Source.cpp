#include<iostream>
#include"Bst.h"
int main(){
	BST<int> a;
	a.Insert(55);
	a.Insert(66);
	a.Insert(77);
	a.Insert(11);
	a.Insert(33);
	a.Insert(22);
	a.Insert(35);
	a.Insert(25);
	a.Insert(44);
	a.Insert(88);
	a.Insert(99);
	a.Inorder();
}