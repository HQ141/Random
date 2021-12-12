#include<iostream>
#include<vector>
using namespace std;
struct ttt {
	int arr[3][3];
	ttt() {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				arr[i][j] = 0;
	}
};
int status_check(ttt& a) {
	int temp = 0;
	int i = 0;
	int j = 0;

	bool found = false;
	for (i = 0; i < 3; i++) {
		temp = a.arr[i][0];
		found = true;
		for (j = 0; j < 3; j++) {
			if (temp != a.arr[i][j]) {
				found = false;
				break;
			}

		}
		if (found) {
			if (temp != 0)
				return temp;
		}
	}
	for (i = 0; i < 3; i++) {
		temp = a.arr[0][i];
		found = true;
		for (j = 0; j < 3; j++) {
			if (temp != a.arr[j][i]) {
				found = false;
				break;
			}

		}
		if (found)
			if (temp != 0)
				return temp;
	}
	temp = a.arr[0][0];
	found = true;
	for (i = 0, j = 0; i < 3; i++, j++) {
		if (temp != a.arr[j][i]) {
			found = false;
			break;
		}
	}
	if (found)
		if (temp != 0)
			return temp;
	temp = a.arr[0][2];
	found = true;
	for (i = 0, j = 2; i < 3; i++, j--) {
		if (temp != a.arr[i][j]) {
			found = false;
			break;
		}
	}
	if (found)
		if (temp != 0)
			return temp;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (a.arr[i][j] == 0)
				return 3;
	return 0;

}
struct score {
	int w = 0;
	int l = 0;
	int d = 0;
	score& operator+=(score& a) {
		this->w += a.w;
		this->l += a.l;
		this->d += a.d;
		return *this;
	}
	score& operator+=(score a) {
		this->w += a.w;
		this->l += a.l;
		this->d += a.d;
		return *this;
	}
};
class Node {
public:
	ttt arr;
	vector<Node*> vec;
	int stat;
	score sc;
	Node(ttt a, int a1, int a2) {
		int temp = status_check(a);
		stat = temp;
		if (temp == 3) {
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					if (a.arr[i][j] == 0) {
						if (a1 == a2) {
							a.arr[i][j] = 1;
							vec.push_back(new Node(a, a1 + 1, a2));
						}
						else {
							a.arr[i][j] = 2;
							vec.push_back(new Node(a, a1, a2 + 1));
						}
					}
				}
		}
		sc = get_s();
	}
	int find(int a1, int a2) {
		if (stat < 3)
			return (1 * sc.w + 2 * sc.l);
		score a;
		int temp;
		if (a1 == a2) {
			vector<int> points;
			for (int i = 0; i < vec.size(); i++) {
				a = vec[i]->get_s();
				temp = a.w * 2 + a.d;
				points.push_back(temp);
			}
			int k = 0;
			int max = points[0];
			for (int i = 1; i < points.size(); i++) {
				if (points[i] > max)
					max = points[i];
				k = i;
			}
			return vec[k]->find(a1 + 1, a2);
		}
		else {
			vector<int> points;
			for (int i = 0; i < vec.size(); i++) {
				a = vec[i]->get_s();
				temp = a.l * 2 + a.d;
				points.push_back(temp);
			}
			int k = 0;
			int max = points[0];
			for (int i = 1; i < points.size(); i++) {
				if (points[i] > max)
					max = points[i];
				k = i;
			}
			return vec[k]->find(a1, a2 + 1);
		}
	}
	score get_s() {
		score a;
		if (stat < 3) {
			if (stat == 1)
				a.w++;
			if (stat == 2)
				a.l++;
			if (stat == 0)
				a.d++;
			return a;
		}
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i]->stat == 1)
				a.w++;
			else if (vec[i]->stat == 2)
				a.l++;
			else if (vec[i]->stat == 0)
				a.d++;
			else {
				a += vec[i]->get_s();
			}
		}
		return a;
	}
};
int main() {
	ttt arr;
	int a1 = 0;
	int a2 = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			cin >> arr.arr[i][j];
			if (arr.arr[i][j] == 1)
				a1++;
			if (arr.arr[i][j] == 2)
				a2++;
		}
	if (a1 > a2) {
		cout << -1;
		return 0;
	}
	Node* t = new Node(arr, a1, a2);
	cout << t->find(a1, a2);
}