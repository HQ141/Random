#include<iostream>
using namespace std;
template<class K, class T>
class Hash_table_entry {
public:
	K key;
	T value;
	Hash_table_entry(K k, T v) :key(k), value(v) {}
	Hash_table_entry<K, T> *Next = NULL;
	void Insert(Hash_table_entry<K, T>* N) {
		if (!Next)
			Next = N;
		else
		Next->Insert(N);
	}
	Hash_table_entry<K, T>* del(K k) {
		if (k == key)
			return Next;
		Hash_table_entry<K, T>* temp = Next;
		if (temp) {
			
			Next = Next->del(k);
			if (Next != temp)
				delete temp;
		}
		return this;
	}
	bool Search(K k) {
		if (k == key)
			return true;
		if (Next)
			return Next->Search(k);
		return false;
	}
	void Display() {
			cout << "KEY :" << key << " Value :" << value << "->";
			if (Next)
				Next->Display();
			else
			cout << "NULL";
	}
};
template<class K,class T>
class HashMap {
private:
	Hash_table_entry<K,T>** entries;
	int size;
public:
	HashMap(int s) :size(s) {
		entries = new Hash_table_entry<K,T> *[size];
		for (int i = 0; i < size; i++)
			entries[i] = NULL;
	}
	int HashFunc(K k) {
		int a=0;
		for (int i = 0; i < k.size(); i++) {
			a += k[i];
		}
		return a % size;
	}
	void Insert(K k, T v) {
		Hash_table_entry<K,T>* New = new Hash_table_entry<K,T>(k, v);
		int Index = HashFunc(k);
		if (entries[Index] == NULL) {
			entries[Index] = New;
			return;
		}
		entries[Index]->Insert(New);
	}
	int SearchKey(K k) {
		int Index = HashFunc(k);
		if (entries[Index]->key == k)
			return Index;
		if (entries[Index]->Search(k))
			return Index;
		return -1;
	}
	void Remove(K k) {
		int Index = SearchKey(k);
		if (Index == -1)
			return;
		if (entries[Index]->key == k) {
			Hash_table_entry<K, T>* a = entries[Index];
			entries[Index] = NULL;
			delete a;
		}
		else {
			entries[Index] = entries[Index]->del(k);
		}
		return;
	}
	void Display() {
		for (int i = 0; i < size; i++) {
			if (entries[i]) {
				entries[i]->Display();
				cout << endl;
			}
			else
				cout << "NULL" << endl;
		}
	}
	~HashMap() {
		for (int i = size - 1; i >= 0; i--)
			delete entries[i];
		delete entries;
	}
	int get_size() {
		int a=0;
		for (int i = 0; i < size; i++)
			if (entries[i] != NULL)
				a++;
		return a;
	}
	bool empty() {
		for (int i = 0; i < size; i++)
			if (entries[i] != NULL)
				return false;
		return true;
	}
};
int main() {
	HashMap<string, string>Contact_Form(10);
	Contact_Form.Insert("20k-0327", "03112268187");
	Contact_Form.Insert("20k-0324", "03131114552");
	Contact_Form.Insert("20k-1051", "03214206923");
	Contact_Form.Insert("20k-0327", "03112268188");
	Contact_Form.Display();
	cout<<endl<<Contact_Form.SearchKey("20k-0327")<<endl<<endl;
	Contact_Form.Remove("20k-0324");
	Contact_Form.Display();
}