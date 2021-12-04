#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;
int main() {
	fstream config;
	uint64_t hash;
	config.open("Config/Merkel_Tree.txt", ios::in|ios::binary);
	while(!config.eof()){
		config.read((char *)&hash,8);
		cout<<hash<<endl;
		if(config.peek()==EOF)
		break;
}
config.close();
getchar();
}