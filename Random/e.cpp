#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;

int main()
{
	fstream a;
	a.open("te.txt");
	//a << data;
	a << "hello world";
	a.close();
	//	std::cout << data;
		//auto f = data.find("hamdan");
		//cout << (f != data.end());
		//cout << *f;
	//	std::string a= data;
	//	std::cout << a;
	//	int b=0;
	//	for (int i = 0; i < a.size(); i++)
	//		b += a[i];
	//	std::cout<<std::endl << b;
}
