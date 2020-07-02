#include<iostream>
#include<vector>
using namespace std;

int snum = 0; // ÇÐ»ý¼ö
int pnum = 0; // Â¦ ¼ö

int num[100];
bool taken[100];
bool isPair[10][10];

int Pair()
{
	int a = -1;
	for (int i = 0; i < snum; i++)
	{
		if (taken[i] == false)
		{
			a = i;
			break;
		}
	}
	if (a == -1) return 1;
	
	int ret = 0;

	for (int i = a+1; i < snum; i++)
	{
		if ((isPair[a][i] == true || isPair[i][a] == true) &&
			taken[a] == false && taken[i] == false)
		{
			taken[a] = true;
			taken[i] = true;
			ret += Pair();
			taken[a] = false;
			taken[i] = false;
		}
	}

	return ret;
}
int main()
{
	int tc;
	cin >> tc;
	
	for (int T = 0; T < tc; ++T)
	{
		cin >> snum >> pnum;

		for (int i = 0; i < snum; i++)
			for (int j = 0; j < snum; j++)
				isPair[i][j] = false;
		for (int i = 0; i < snum; i++)
			taken[i] = false;

		for (int i = 0; i < pnum; i++)
		{
			int a, b;
			cin >> a >> b;
			isPair[a][b] = true;
		}
		cout << Pair() << endl;
	}

	return 0;
}