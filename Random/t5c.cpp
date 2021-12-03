#include<iostream>
#include<vector>
#include"dsa.h"
using namespace std;
#define s 4
int a = 0;
int m = 100000;
int func(bool maze[s][s], int i, int j, int sp ,DSA <int >& ptr);
int main() {
	bool maze[s][s] = { {0,0,0,0},{0,1,1,1},{0,1,1,1},{0,0,0,0}};
	DSA<int >ptr;
	//bool maze[s][s];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			//maze[i][j] = 0;
			//cin >> maze[i][j];
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	func(maze, 0, 0,0,ptr);
	for (int i = 0; i < ptr.get_size(); i++)
		cout << ptr[i] / s << "," << ptr[i] % s << endl;
	cout<<"Number of swaps=" << m << endl;
}
int func(bool maze[s][s], int i, int j, int sp,DSA <int >& ptr) {
	bool r = false;
	bool l = false;
	bool rc = false;
	bool lc = false;
	ptr.push((i * s) + j);
	if (i == s - 1 && j == s - 1) {
		if (sp < m) {
			m = sp;
			if (ptr.get_size() == (s-1)*2+1) {
				//cout << "check" << endl;
				return 1;
			}
			ptr.erase(ptr.get_size()-((ptr.get_size()- ((s - 1) * 2 + 1))*2), ((s - 1) * 2 ) );
			return 1;
		}
		return 0;
	}
	if (j + 1 != s) {
		rc = true;
		if (maze[i][j + 1])
			r = func(maze, i, j + 1, sp + 1,ptr);
		if (!maze[i][j + 1])
			r = func(maze, i, j + 1, sp,ptr);
	}
	if (!r&&rc)
		ptr.pop();

	if (i + 1 != s) {
		lc = true;
		if (maze[i + 1][j])
			l = func(maze, i + 1, j, sp + 1,ptr);
		if (!maze[i + 1][j])
			l = func(maze, i + 1, j, sp,ptr);
	}
	if (!l&&lc)
		ptr.pop();
	return (l||r);
}
	