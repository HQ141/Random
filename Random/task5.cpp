#include<iostream>
using namespace std;
void MinMax(int* arr,int size,int *min,int *max) {
	*max = -100000;
	 *min = 1000000;
	for (int i = 0; i < size; i++) {
		if (arr[i] > *max)
			*max = arr[i];
		if (arr[i] < *min)
			*min = arr[i];
	}
	
}
int main() {
	int arr[10] = { 10,12,34,56,78,97,23,89,7,4};
	int min, max;
	MinMax(arr,10,&min,&max);
	cout << "Max is " << max << endl << "Min is " << min << endl;

}