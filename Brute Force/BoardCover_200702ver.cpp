#include<iostream>
#include<vector>
using namespace std;


int tc; 
int h, w; // ÆÇ ÃÑ Å©±â
int way = 0; // ¹æ¹ý ¼ö

int emptyCount = 0; // ºóÄ­ ¼ö
int Count = 0; // ºóÄ­ Ã¤¿î ¼ö 

int block[4][3][2] =
{
	{{0,0},{1,0},{0,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{0,1},{-1,1}},
	{{0,0},{0,1},{1,1}}
};
char board[20][20];

void print()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cout << board[j][i];
		cout << endl;
	}
	cout << endl;
}
void game()
{
	int x = -1;
	int y = -1;
	bool Flag = false;

	//Á¦ÀÏ ¿ÞÂÊ, À§ÂÊ ºñ¾îÀÖ´Â Ä­ Å½»ö
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (board[j][i] == '.')
			{
				x = j;
				y = i;
				Flag = true;
				break;
			}
		}
		if (Flag) break;
	}

	if (emptyCount == Count)
		way++;
	
	if (y == -1)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (board[x + block[i][0][0]][y + block[i][0][1]] == '.' &&
			board[x + block[i][1][0]][y + block[i][1][1]] == '.' &&
			board[x + block[i][2][0]][y + block[i][2][1]] == '.')
		{
			board[x + block[i][0][0]][y + block[i][0][1]] = '@';
			board[x + block[i][1][0]][y + block[i][1][1]] = '@';
			board[x + block[i][2][0]][y + block[i][2][1]] = '@';
			Count += 3;

			game();

			board[x + block[i][0][0]][y + block[i][0][1]] = '.';
			board[x + block[i][1][0]][y + block[i][1][1]] = '.';
			board[x + block[i][2][0]][y + block[i][2][1]] = '.';
			Count -= 3;
		}
		
	}
}

int main()
{
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		way = 0;
		emptyCount = 0;
		Count = 0;
		cin >> h >> w;

		for (int i = 0; i < 20; ++i)
			for (int j = 0; j < 20; ++j)
				board[j][i] = '#';

		for (int j = 0; j < h; j++)
		{
			for (int e = 0; e < w; e++)
			{
				char c;
				cin >> c;
				board[e][j] = c;
				if (c == '.')
					emptyCount++;
			}
		}
		game();

		cout << way << endl;
	}
	return 0;
}