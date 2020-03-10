#include <iostream>
using namespace std;

int tc; // ����
int w, h; // �� ����,���� ũ��
char map[30][30]; // �� ����

int block[4][3][2] = // �� ���
{
	{{0,0},{1,0},{1,1}}, 
	{{0,0},{0,1},{1,1}},
	{{0,0},{0,1},{-1,1}},
	{{0,0},{1,0},{0,1}}
};

int emptyNum = 0; // ��ĭ ��
int emptyFull = 0; // ��ĭ ä�� ��

int Find(int start_x, int start_y)
{
	int count = 0;

	if (emptyNum == emptyFull) // ��� ���� ä������ ī��Ʈ 1 �߰�
		return 1;

	if (map[start_x][start_y] == '#') // ���� ���� ��� �׳� �ٷ� �̵���Ų��.
	{
		if (start_x == w - 1)
			count += Find(0, start_y + 1);
		else
			count += Find(start_x + 1, start_y);
	}
	else
	{
		for (int e = 0; e < 4; ++e)
		{
			if (map[start_x][start_y] == '.' &&
				map[start_x + block[e][1][0]][start_y + block[e][1][1]] == '.' &&
				map[start_x + block[e][2][0]][start_y + block[e][2][1]] == '.')
			{
				emptyFull += 3;
				map[start_x][start_y] =
					map[start_x + block[e][1][0]][start_y + block[e][1][1]] =
					map[start_x + block[e][2][0]][start_y + block[e][2][1]] = '#';

				if (start_x == w - 1)
					count += Find(0, start_y + 1);
				else
					count += Find(start_x + 1, start_y);

				emptyFull -= 3;
				map[start_x][start_y] =
					map[start_x + block[e][1][0]][start_y + block[e][1][1]] =
					map[start_x + block[e][2][0]][start_y + block[e][2][1]] = '.';
			}
		}
	}
	return count;
}

int main()
{
	cin >> tc;
	for (int T = 0; T < tc; ++T)
	{
		/* �ʱ�ȭ */
		for (int i = 0; i < 20; ++i)
			for (int j = 0; j < 20; ++j)
				map[j][i] = '#';
		emptyNum = 0;
		emptyFull = 0;

		cin >> h >> w;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				char a;
				cin >> a;
				map[j][i] = a;
				if (a == '.')
					emptyNum++;
			}
		}
		cout << Find(0, 0) << endl;
	}
	return 0;
}