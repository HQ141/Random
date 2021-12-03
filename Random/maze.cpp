#include<iostream>
#include<fstream>
#include"dsa.h"
#define s 9
using namespace std;
int func(bool arr[s][s], int i, int j, DSA<int>** ptr);
bool fun(DSA<int>** , int , int ,int ,int);
int main() {
	ifstream file;
	file.open("tre.txt", ios::in);
	DSA<int >** ptr = new DSA<int > *[s];
	bool maze[s][s];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			//maze[i][j] = rand() % 2;
			file >> maze[i][j];
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	func(maze, 0, 0,ptr);
	/*for (int i = 0; i < s; i++) {
		int temp = ptr[i]->get_size();
		for (int j = 0; j < temp; j++) 
			cout << (*ptr[i])[j]<< " ";
		cout << endl;
	}*/
	fun(ptr, 0, 0,0,0);
	

}
bool fun(DSA<int>** ptr, int i, int j,int pi,int pj) {
	cout << "At " << i << " " << (*ptr[i])[j] << endl;
	if (i == s - 1 && ((*ptr[i])[j] == s - 1)) {
		cout << "Reached Destination" << endl;
		return 1;
	}
	bool p = false;
	if(j != s - 1)
		if((i != pi && (j+1) != pj))
		if (((*ptr[i])[j] + 1 == (*ptr[i])[j + 1])) {
			p = fun(ptr, i, j + 1, i, j);
		}
	if(j!=1)
		if(!p)
	if((!(i != pi && (j-1)!= pj))  )
		if (((*ptr[i])[j] - 1 == (*ptr[i])[j - 1])) {
			cout << "CHECK" << endl;
			p = fun(ptr, i, j -1, i, j);
		}
	int x;
	if (i != 8&&!p) {
		bool t=false;
		int temp = ptr[i + 1]->get_size();
		for (x = 0; x < temp; x++) {
			if ((*ptr[i + 1])[x] == (*ptr[i])[j]) {
				t = true;
				break;
			}
		}
		if (t)
			p= fun(ptr, i + 1, x, i, j);
	}
	if (i != 0 &&!p) {
		bool t;
		int temp = ptr[i - 1]->get_size();
		for (x = 0; x < temp; x++) {
			if ((*ptr[i - 1])[x] == (*ptr[i])[j]) {
				t = true;
				break;
			}
		}
		if (t)
			p = fun(ptr, i - 1, x, i, j);
	}
	if(p)
	cout << "At " << i << " " << (*ptr[i])[j] << endl;
	return p;

}
int func(bool arr[s][s], int i, int j,DSA<int>**ptr) {
	if (i ==s)
		return 0;
	if (j == 0)
		ptr[i] = new DSA<int>;
	if (arr[i][j] == 1) 
		ptr[i]->push(j);
	if (j == s-1)
		return func(arr, i + 1, 0, ptr);
	return func(arr, i, j + 1, ptr);
}