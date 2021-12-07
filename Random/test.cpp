#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;
struct hash_data {
	uint64_t hash;
	bool level;
};
int main() {
	fstream config;
	hash_data hash;
	config.open("Config/Merkel_Tree.txt", ios::in|ios::binary);
	while(!config.eof()){
		config.read((char *)&hash,sizeof(hash));
		cout<<hash.hash<<" "<<int(hash.level)<<endl;
		if(config.peek()==EOF)
		break;
}
config.close();
getchar();
}