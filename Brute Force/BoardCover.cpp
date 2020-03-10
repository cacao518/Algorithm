#include <iostream>
using namespace std;

int tc; // 테케
int w, h; // 맵 가로,세로 크기
char map[30][30]; // 맵 정보

int block[4][3][2] = // 블럭 모양
{
	{{0,0},{1,0},{1,1}}, 
	{{0,0},{0,1},{1,1}},
	{{0,0},{0,1},{-1,1}},
	{{0,0},{1,0},{0,1}}
};

int emptyNum = 0; // 빈칸 수
int emptyFull = 0; // 빈칸 채운 수

int Find(int start_x, int start_y)
{
	int count = 0;

	if (emptyNum == emptyFull) // 모든 블럭을 채웠으면 카운트 1 추가
		return 1;

	if (map[start_x][start_y] == '#') // 막혀 있을 경우 그냥 바로 이동시킨다.
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
		/* 초기화 */
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