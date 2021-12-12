#ifndef  HASH_TABLE_H
#define HASH_TABLES_H
#include<iostream>
using namespace std;
template <class T>
class Hash_table_entry {
public:
	int key;
	T value;
	Hash_table_entry(int k, T v):key(k),value(v){}
};
template<class T>
class HashMap {
private:
	Hash_table_entry<T>** entries;
	int size;
public:
	HashMap(int);
	int HashFunc(int);
	void Insert(int, T);
	int SearchKey(int);
	void Remove(int);
	void Display();
	~HashMap();
};
template<class T>
HashMap<T>::HashMap(int s):size(s) {
	entries = new Hash_table_entry<T> * [size];
	for (int i = 0; i < size; i++)
		entries[i] = NULL;
}
int division_hash(int key,int s){
	return key%s;
}
int multiplication_hash(int a,int s){
	double b = 0.618033;
	double c = b * a;
	c = c - (int)(b * a);
	return s * c;
	
}
int mid_square_hash(int key,int s){
	int value = key * key;
	value = value / 100;
	value = value % s;
	return key;
}

int Folding_hash(int value1, int value2, int value3,int s){
	return (value1 + value2 + value3)%s;
}
template<class T>
int HashMap<T>::HashFunc(int k) {
	return k % size;
}
template<class T>
void HashMap<T>::Insert(int k, T v) {
	Hash_table_entry<T>* New = new Hash_table_entry<T>(k, v);
	int Index = HashFunc(k);
	if (entries[Index] == NULL) {
		entries[Index] = New;
		return;
	}
	for (int i = Index+1; i % size != Index; i++) {
		if (entries[HashFunc(i%size)] == NULL) {
			entries[HashFunc(i % size)] = New;
			return;
		}
	}
	cout << "NO MORE SPACE" << endl;
	delete New;
}
template<class T>
int HashMap<T>::SearchKey(int k) {
	int Index = HashFunc(k);
	if (entries[Index]->key == k)
		return Index;
	for (int i = Index + 1; i % size == Index; i++) {
		if (entries[HashFunc(i%size)]->key == k)
			return i%size;
	}
	return -1;
}
template<class T>
void HashMap<T>::Remove(int k) {
	int Index = SearchKey(k);
	if (Index == -1)
		return;
	Hash_table_entry<T> *a = entries[Index];
	entries[Index] = NULL;
	delete a;
	return;
}
template<class T>
HashMap<T>::~HashMap() {
	for (int i = size - 1; i >= 0; i--)
		delete entries[i];
	delete entries;
}
template<class T>
void HashMap<T>::Display() {
	for (int i = 0; i < size; i++) {
		if (entries[i])
			cout << "KEY :" << entries[i]->key << " Value :" << entries[i]->value << endl;
		else
			cout << "NULL" << endl;
	}
}

#endif // ! HASH_TABLE_H
