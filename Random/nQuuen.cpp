#include<iostream>
using namespace std;
bool track(int**, int, int,int);
bool safe(int** arr,int);
int main() {
	int s;
	cin >> s;
	int** arr = new int* [s];
	for (int i = 0; i < s; i++) {
		arr[i] = new int[s];
		for (int j = 0; j < s; j++)
			arr[i][j] = 0;
	}
	track(arr, 0, 0,s);
	if(safe(arr,s))
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
bool track(int **arr,int i,int j,int s){
	if (i >= s || j >= s)
		return false;
	arr[i][j]=1;
	track(arr, i+1 , 0,s);
	if (safe(arr,s))
		return true;
	arr[i][j] = 0;
	return track(arr, i ,j+1,s );
}
bool safe(int **arr,int s) {
	int sum = 0;
	int *a=new int [s];
	int aa = 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (arr[i][j] == 1) {
				a[aa++] = i * s + j;
				break;
			}
		}
	}
	int diff;
	int ix, iy, jx, jy;
	for (int i = 0; i < s-1; i++) {
		for (int j = i+1; j < s; j++) {
			diff = abs(a[i] - a[j]);
			ix = a[i] / s;
			jx = a[j] / s;
			iy = a[i] % s;
			jy = a[j] % s;
			if (iy == jy) {
				return 0;
			}
			if (ix ==iy) {
				return 0;
			}
			if (diff % (s-1) == 0) {
				if (abs(ix - jx) == abs(iy - jy)) {
					
					return 0;
				}
			}
			if (diff % (s+1) == 0) {
				if (abs(ix - jx) == abs(iy - jy))
				return 0;
			}
			
		}
	}
	return true;
	
}