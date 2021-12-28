#include<iostream>
using namespace std;
void turns(int** a, int turn, int opponent, int row, int col)
{
	
	for (int i = 0; i < 3; i++)
	{
		if (a[0][i] == 1)
		{

			if (a[1][i] == 1 && a[2][i] == 1)
			{
				cout << "1";
				exit(1);
			}

			if ((i - 2) >= 0)
			{
				if (a[1][i - 1] == 1 && a[2][i - 2] == 1)
				{
					cout << "1";
					exit(1);
				}
			}
			if ((i + 2) < 3)
			{
				if (a[1][i+1] == 1 && a[2][i+2] == 1)
				{
					cout << "1";
					exit(1);
				}
			}
		}
			if (a[0][i] == 2)
			{

				if (a[1][i] == 2 && a[2][i] == 2)
				{
					cout << "2";
					exit(1);
				}

				if ((i - 2) >= 0)
				{
					if (a[1][i-1] == 2 && a[2][i-2] == 2)
					{
						cout << "2";
						exit(1);
					}
				}
				if ((i + 2) < 3)
				{
					if (a[ 1][i+1] == 2 && a[2][i+2] == 2)
					{
						cout << "2";
						exit(1);
					}
				}

			}

		}
	
	for (int j = 0; j < 3; j++)
	{
		if (a[j][0] == 1)
		{
			if (a[j+1][0] == 1 && a[j+2][0] == 1)
			{
				cout << "1";
				exit(1);
			}
		}
		if (a[j][0] == 2)
		{
			if (a[j+1][0] == 2 && a[j+2][0] == 2)
			{
				cout << "2";
				exit(1);
			}
		}
		else
		{
			cout << "0";
			exit(1);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == opponent)
			{
				if ((i - 2) >= 0 && (j-2) >=0)
				{
					if (a[i - 1][j - 1] == opponent)
					{
						a[i - 1 - 1][j - 1 - 1] = turn;
						turns(a, opponent, turn, 3, 3);
					}
				}
				if ((i + 2) <3 && (j + 2) < 3)
				{
					if (a[i + 1][j + 1] == opponent)
					{
						a[i + 1 + 1][j + 1 + 1] = turn;
						turns(a, opponent, turn, 3, 3);
					}
				}
				if ((i - 2) >= 0 && (j + 2) < 3)
				{
					if (a[i - 1][j + 1] == opponent)
					{
						a[i - 1 - 1][j + 1 + 1] = turn;
						turns(a, opponent, turn, 3, 3);
					}
				}
				if ((i + 2) < 3 && (j - 2) >= 0)
				{
					if (a[i + 1][j - 1] == opponent)
					{
						a[i + 1 + 1][j - 1 - 1] = turn;
						turns(a, opponent, turn, 3, 3);
					}
				}
				if ((i + 2) < 3)
				{
					if (a[i+1][j] == opponent)
					{
						a[i+1+1][j] = turn;
						turns(a, opponent, turn, 3, 3);
					}
				}
				if ((i - 2) >= 0 && (j - 2) >= 0)
				{
					if (a[i - 1][j - 1] == 0 && a[i-2][j-2] == opponent)
					{
						a[i - 1][j - 1] = turn;
						turns(a, opponent, turn, 3, 3);
					}
				}
				if ((i + 2) < 3 && (j + 2) < 3)
				{
					if (a[i + 1][j + 1] == 0 && a[i+2][j+2]==opponent)
					{
						a[i + 1][j + 1] = turn;
						turns(a, opponent, turn, 3, 3);
					}
				}
				if ((i - 2) >= 0 && (j + 2) < 3)
				{
					if (a[i - 2][j + 2] == opponent && a[i-1][j+1] == 0)
					{
						a[i - 1][j + 1] = turn;
						turns(a, opponent, turn, 3, 3);
					}
				}
				if ((i + 2) < 3 && (j - 2) >= 0)
				{
					if (a[i + 2][j - 2] == opponent && a[i+1][j-2] == 0)
					{
						a[i + 1 + 1][j - 1 - 1] = turn;
						turns(a, opponent, turn, 3, 3);
					}
				}
				if ((i + 2) < 3)
				{
					if (a[i + 2][j] == opponent && a[i+1][j] == 0)
					{
						a[i + 1][j] = turn;
						turns(a, opponent, turn, 3, 3);
					}
				}
				
			}
		}
	}
	

}
void validcheck(int ** a)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == 1)
			{
				count1++;
			}
			if (a[i][j] == 2)
			{
				count2++;
			}
		}
	}
	if (count1 >= 2 * (count2))
	{
		cout << "-1";
			exit(1);
	}
	if (count2 >= 2 * (count1))
	{
		cout << "-1";
		exit(1);
	}
	if (count1 == count2)
	{
		turns(a, 1, 2, 3, 3);
	}
	if (count1 > count2)
	{
		turns(a, 2, 1, 3, 3);
	}
	if (count2 > count1)
	{
		turns(a, 1, 2, 3, 3);
	}
}
int main()
{
	int** arr = new int* [3];
		for (int i = 0; i < 3; i++)
		{
			arr[i] = new int[3];
		}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	validcheck(arr);
}