#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
class result {
	public:
	double win ;
	double lose ;
	double draw ;
	result()
	{
		win=0;
		lose=0;
		draw=0;
	}
	result& operator+(result r) {
		win += r.win;
		lose += r.lose;
		draw += r.draw;
		return *this;
	}
};
class Game {
public:
	int array[3][3];
	vector<Game*> vecdata;
	int perf;
	result r;
	Game(int a[3][3], int n1, int n2)
	{
		for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++) {
			array[i][j]=a[i][j];
		}
		perf=0;
		int t = applying_check(array);
		bool best = false;
		perf = t;
		if (t == 3) {
			for (int i = 0; i <= 2 && !best; i++)
			for (int j = 0; j <= 2&& !best; j++) {
				if (array[i][j] == 0) {
					if (n1== n2) {
					array[i][j] = 1;
						if (applying_check(array) == 1) {
							vecdata.clear();
							best = true;
							}
						Game* g = new Game(array, n1+ 1, n2);
						vecdata.push_back(g);
						}
						else {
						array[i][j] = 2;
						if (applying_check(array) == 2) {
							vecdata.clear();
							best = true;
							}
						Game* g = new Game(array, n1, n2 + 1);
						vecdata.push_back(g);
						}
						array[i][j] = 0;
					}
				}
		}
		r = attain_res();
	}
	int applying_check(int arr[3][3]);
	int winner(int n1, int n2);
	result attain_res(void);
};
result Game :: attain_res() {
		result r1;
		if (perf < 3) {
			if (perf == 1)
				r1.win++;
			if (perf == 2)
				r1.lose++;
			if (perf == 0)
				r1.draw++;
			return r1;
		}
		for (int i = 0; i < vecdata.size(); i++) {
			if (vecdata[i]->perf == 1)
				r1.win++;
			else if (vecdata[i]->perf == 2)
				r1.lose++;
			else if (vecdata[i]->perf == 0)
				r1.draw++;
			else {
				r1=r1 + vecdata[i]->attain_res();
			}
		}
		return r1;
	}
int Game :: winner(int n1, int n2) {
		if (perf < 3)
			return (1 * r.win + 2 * r.lose);
		result r1;
		double t;
		if (n1== n2) {
			vector<double> points;
			for (int i = 0; i < vecdata.size(); i++) {
				r1 = vecdata[i]->r;
				t = (2 * r1.win);
				if (r1.draw)
					t += r1.draw;
				if (r1.lose != 0)
					t /= 2 * r1.lose;
				else 
					if (r1.draw == 0)
						return 1;
				points.push_back(t);
			}
			int k = 0;
			double max = points[0];
			for (int i = 1; i < points.size(); i++) {
				if (points[i] > max) {
					max = points[i];
					k = i;
				}
			}
			return vecdata[k]->winner(n1+ 1, n2);
		}
		else {
			vector<double> points;
			for (int i = 0; i < vecdata.size(); i++) {
				r1 = vecdata[i]->r;
				t = (2 * r1.lose);
				if (r1.draw)
					t += r1.draw;
				if (r1.win != 0)
					t /= 2 * r1.win;
				else
					if (r1.draw == 0)
						return 2;
				points.push_back(t);
			}
			int k = 0;
			double max = points[0];
			for (int i = 1; i < points.size(); i++) {
				if (points[i] > max) {
					max = points[i];
					k = i;
				}
			}
			return vecdata[k]->winner(n1, n2 + 1);
		}
	}
int Game :: applying_check(int arr[3][3]) {
	bool f = false;
	int t;
	for (int i = 0; i <= 2; i++) {
		t = arr[i][0];
		f = true;
		for (int j = 0; j <= 2; j++) {
			if (t != arr[i][j]) {
				f = false;
				break;
			}
		}
		if (f==true) {
			if (t != 0)
				return t;
		}
	}
	for (int i = 0; i <= 2; i++) {
		t = arr[0][i];
		f = true;
		for (int j = 0; j <= 2; j++) {
			if (t != arr[j][i]) {
				f = false;
				break;
			}
		}
		if (f==true)
			if (t != 0)
				return t;
	}
	t = arr[0][0];
	f = true;
	for (int i = 0, int j = 0; i <= 2; i++, j++) {
		if (t != arr[j][i]) {
			f = false;
			break;
		}
	}
	if (f==true)
		if (t != 0)
			return t;
	t = arr[0][2];
	f = true;
	for (int i = 0, int j = 2; i <= 2; i++, j--)
		if (t != arr[i][j])
		 {
			f = false;
			break;
		}
	if (f==true)
	{
		if (t != 0)
			return t;
	}
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == 0)
			{
				return 3;
			}
	}
}
	return 0;
}
int main() {
	int array[3][3];
	int p1c = 0,p2c = 0;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cin >> array[i][j];
			if (array[i][j] == 1)
				p1c++;
			if (array[i][j] == 2)
				p2c++;
		}
	}
	if (!(p2c == p1c || p2c == p1c- 1)) {
		cout<<-1;
		}
	else {
		Game g(array, p1c, p2c);
		cout << g.winner(p1c,p2c);
	}
	return 0;
}
