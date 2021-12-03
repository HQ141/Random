#include<iostream>
using namespace std;
bool** arr = new bool* [4];
bool safecheck() {
	int a[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (arr[i][j])
				a[i] = j;
		}
	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 4; j++) {
			if (a[i] == a[j])
				return 0;
			if (abs(i - j) == abs(a[i] - a[j]))
				return 0;
		}
	}
}
bool NQueen(int i, int j) {
	if (i > 3)
		return safecheck();
	if (j > 3)
		return false;
	arr[i][j] = true;
	if (NQueen(i + 1, 0))
		return true;
	arr[i][j] = false;
	return NQueen(i, j + 1);
}
int main() {

	for (int i = 0; i < 4; i++) {
		arr[i] = new bool[4];
		for (int j = 0; j < 4; j++)
			arr[i][j] = false;
	}
	arr[0][1] = 1;
	NQueen(1, 0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}