#include<iostream>
using namespace std;
int Am(int* arr, int size, int& nx, int& ny) {
	int max = -1000000;
	bool p = false;
	int nmax = 0;
	int x = 0, y = 0;
	nx = x, ny = y;
	for (int i = 0; i < size; i++) {
		nmax += arr[i];
		y = i;
		if (nmax > max) {
			max = nmax;
			nx = x;
			ny = y;
		}
		if (nmax < 0) {
			x = i+1, y = i+1;
			nmax = 0;
		}
		
	}
	return max;

}
int main() {
	int n;
	int max = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x, y;
	int temp = Am(arr, n, x, y);
	for (; x <= y; x++)
		cout << arr[x] << " ";
	cout << endl<<temp;
}