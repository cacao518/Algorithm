#include<iostream>
using namespace std;

int tc; // ����

bool areFriends[10][10]; // ¦��� ����
bool taken[10]; // �л��� üũ ����
int sn, pn; // �л���, ¦�� ��

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
		if (!taken[i] && (areFriends[First_idx][i] || areFriends[i][First_idx])) // ex) (0,3) (3,0) �� �� �� ��츸 �¾Ƶ� ok
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

		/* �ʱ�ȭ */
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


