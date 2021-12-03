#include<iostream>
using namespace std;
class BHeap{
private:
	int cap;
	int currentsize;
	int * arr;
public:
	BHeap(int n){
		cap=n;
		arr=new int [n];
		currentsize=0;
	}
	bool isEmpty(){
		return currentsize;
	}
	void Insert(int a){
		int hole=++currentsize;
		arr[0]=a;
		for(;a<arr[hole/2];hole/=2)
			arr[hole]=arr[hole/2];
		arr[hole]=arr[0];
	}
	void deleteMin(){
		arr[0]=arr[currentsize--];
		int hole=1;
		int child;
		for(;hole*2<=currentsize;hole=child){
			child=hole*2;
			if(child!=currentsize&&arr[child+1]<arr[child])
			child++;
			if(arr[child]<arr[0])
			arr[hole]=arr[child];
			else break;
		}
		arr[hole]=arr[0];
	}
};