#include<iostream>
using namespace std;

int tc; // 테케

bool areFriends[10][10]; // 짝꿍들 정보
bool taken[10]; // 학생들 체크 여부
int sn, pn; // 학생수, 짝꿍 수

int Pairings()
{
	int Count = 0;
	int First_idx = -1;

	for (int i = 0; i < sn; i++)
	{
		if (taken[i] == false)
		{
			First_idx = i;
			break;
		}
	}
	if (First_idx == -1) return 1;

	for (int i = First_idx+1; i < sn; i++)
	{
		if (!taken[i] && (areFriends[First_idx][i] || areFriends[i][First_idx])) // ex) (0,3) (3,0) 둘 중 한 경우만 맞아도 ok
		{
			taken[First_idx] = taken[i] = true;
			Count += Pairings();
			taken[First_idx] = taken[i] = false;
		}
	}
	return Count;
}
int main()
{
	cin >> tc;

	for (int t = 0; t < tc; t++)
	{
		cin >> sn >> pn;

		/* 초기화 */
		for (int i = 0; i < sn; i++) taken[i] = false;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				areFriends[i][j] = false;
		
		for (int i = 0; i < pn; i++)
		{
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = true;
		}

		cout << Pairings() << endl;

	}
	return 0;
}


