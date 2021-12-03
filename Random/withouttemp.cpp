#include<iostream>
using namespace std;
int main() {
	int lmax=10000000000;
	int max = -100000000;
	int count=0;
	int print = 10;
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < print; i++) {
		max = -100000000;
		for (int j = 0; j < 10; j++) {
			if (arr[j] == max) {
				count++;
			}
			if (arr[j] < lmax && arr[j]>max) {
				max = arr[j];
				count = 1;
			}
		}
		if (count > 1) {
			print = print - count + 1;
		}
		for (int i = 0; i < count; i++) {
			cout << max << endl;
		}
		lmax = max;
	}
}