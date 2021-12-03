#include<iostream>
#include<fstream>
using namespace std;
#include"dsa.h"
#define s 4
int func(bool arr[s][s], int i, int j, DSA<int >* ptr);
bool fun(DSA<int >*, int, int);
int main() {
	ifstream file;
	file.open("t.txt", ios::in);
	DSA<int >*ptr=new DSA<int>[s];
	for (int i = 0; i < s; i++)
		ptr[i] = DSA<int>();
	bool maze[s][s];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			//maze[i][j] = rand() % 2;
			file >> maze[i][j];
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	func(maze, 0, 0, ptr);
	/*for (int i = 0; i < s; i++) {
		int temp = ptr[i].get_size();
		for (int j = 0; j < temp; j++)
			cout << ptr[i][j]<< " ";
		cout << endl;
	}*/
	cout << endl << endl;
	fun(ptr, 0, 0);
}
int func(bool arr[s][s], int i, int j, DSA<int >* ptr){
	if (i == s)
		return 0;
	if (arr[i][j] == 1)
		ptr[i].push(j);
	if (j == s - 1)
		return func(arr, i + 1, 0, ptr);
	return func(arr, i, j + 1, ptr);
}
bool fun(DSA<int >* ptr , int i, int j) {
	cout << "At " << i << " " << ptr[i][j] << endl;
	if (i == s - 1 && ptr[i][j] == s - 1) {
		cout << "Reached Destination" << endl;
		return 1;
	}
	if (j + 1 < ptr[i].get_size()) {
		if (ptr[i][j] + 1 == ptr[i][j + 1]) {
			return fun(ptr, i, j + 1);
		}
	}
	if (i != s-1 ) {
		int x;
		bool t = false;
		int temp = ptr[i + 1].get_size();
		for (x = 0; x < temp; x++) {
			if (ptr[i+1][x] == ptr[i][j]) {
				t = true;
				break;
			}
		}
		if (t)
			return fun(ptr, i + 1, x);
	}
}