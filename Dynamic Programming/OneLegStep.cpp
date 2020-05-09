#include <iostream>
#include <string>
using namespace std;

int n = 100; // 게임판 가로,세로 크기
int board[100][100];
int cache[100][100];

int jump2(int x, int y)
{
	if (x >= n || y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;

	int& ret = cache[x][y];
	if (ret != -1) return ret;

	int jumpsize = board[x][y];

	return ret = jump2(x + jumpsize, y) || jump2(x, y + jumpsize);
}

int main() {

	int x = 0;
	int y = 0;
	
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			board[i][j] = 1;

	cout << jump2(0, 0);

	return 0;
}