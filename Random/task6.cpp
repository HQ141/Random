#include<iostream>
using namespace std;
int compare(string s1, string s2);
void swap(void** ptr1, void** ptr2);
class Animal {
private:
	string name;
	int legs;
	int wings;
public:
	Animal(){}
	string getname() { return name; }
	Animal(string n,int l,int w):
		name(n),legs(l),wings(w){}
	Animal(string n) :
		name(n), legs(0), wings(0) {}
};

int main() {
	string temp;
	Animal* ptr = new Animal[5];
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		ptr[i] = Animal(temp);
	}
	Animal tem;
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 5; j++) {
			if (compare(ptr[i].getname(), ptr[j].getname()) == 2) {
				swap(ptr[i], ptr[j]);
			}
		}
	}
	cout << "\n\n\n";
	for (int i = 0; i < 5; i++) {
		cout << ptr[i].getname() << endl;
	}
		
	delete[] ptr;
}
int compare(string s1,string s2){
	bool eval = false;
	int i = 0;
		
	while (!eval) {
		char a, b;
		a = tolower(s1[i]);
		b = tolower(s2[i]);
		if (a > b)
			return 2;
		if (a < b)
			return 1;
		if (a == b) {
			if (a == '\0'&& b == '\0')
				return 0;
			if (a == '\0')
				return 2;
			if (b == '\0')
				return 1;
			i++;
		}
	}
}
void swap(void** ptr1, void** ptr2) {
	void* temp=*ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;

}