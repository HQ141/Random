#include<iostream>
using namespace std;
int main() {
	int** suduko = new int* [9];
		for (int i = 0; i < 9; i++) {
			suduko[i] = new int[9];
			for (int j = 0; j < 9; j++)
				suduko[i][j] = 0;
		}
	for (int i = 0; i < 8; i++) {
		suduko[i][8] = 45;
		for (int j = 0; j < 8; j++) {
			cin >> suduko[i][j];
			suduko[i][8] -= suduko[i][j];
			suduko[8][j] -= suduko[i][j];
		}
		suduko[8][8] -= suduko[i][8];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 8) {
				suduko[i][j] += 45;
			}
			cout << suduko[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}