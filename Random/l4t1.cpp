#include<iostream>
using namespace std;
int main() {
	string a;
	char temp;
	a = "helloworld";
	for (int i = 0; i < a.size(); i++)
		for (int j = i; j < a.size(); j++)
			if (a[i] > a[i+1]) {
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
	cout << a;
}