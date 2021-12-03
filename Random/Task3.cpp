#include<iostream>
using namespace std;
#define size 10
int main() {
	int tmax, tmin;
	int arr[size] = { 10,9,8,7,6,5,4,3,2,1 };
	tmax = arr[0];
	tmin = arr[size - 1];
	for (int i = 0; i < 10; i=i+2) {
		arr[i] = tmax;
		tmax = arr[i + 1];
		arr[i + 1] = arr[size - i - 1];
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
}