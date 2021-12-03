#include<iostream>
using namespace std;
class Numbers {
private:
	int size;
	int* ptr;
public:
	Numbers(int a) :size(a) {
		ptr = new int[a];
	}
	~Numbers() {
		delete[]ptr;
	}
	void set(int a,int *b) {
		size = a;
		ptr = b;
	}
	Numbers(Numbers& a) {
		size = a.size;
		ptr = new int [size];
	}
};
int main() {
	Numbers a = 10;
	Numbers b = a;
}