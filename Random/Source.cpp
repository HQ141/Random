#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int nrows, ncolums;
	cin >> nrows >> ncolums;
	int** arr = new int*[nrows];
	int** value = new int* [nrows];
	for (int i = 0; i < nrows; i++)
	{
		value[i] = new int[ncolums];
		arr[i] = new int[ncolums];
		for (int j = 0; j < ncolums; j++){
			
			value[i][j] = 0;
			arr[i][j] = rand()%9 +1;
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
	int j, k;
	bool present = false;
	for (int i = 0; i < ncolums; i++)
	{
		for (j = 0; j < nrows; j++)
		{
			for (k = 0; k < nrows; k++)
			{
				present = false;
				if (arr[j][i] == arr[k][i+1])
				{
					for (int a = 0; a < j; a++) 
						if (value[a][i] == arr[j][i]) {
							present = true;
						}
					if (!present) {
						value[j][i] = arr[j][i];
					}
				}
			}
		}
	}
	for (int i = 0; i < ncolums-1; i++)
	{
		cout << "Common friends in " << i + 1 << " column and " << i + 2 << " column are" << endl;
		for (int j = 0; j < nrows; j++)
		{
			if (value[j][i] != 0)
			{
				cout << value[j][i] << " \n";
			}
		}
	}
}