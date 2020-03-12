#include <iostream>
using namespace std;

/*
https://www.algospot.com/judge/problem/read/ClockSYNC
*/

int tc;
const char linked[10][17] =
{
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};
int Clock[16];
int Num12 = 0;

int check(int num)
{
	int ret = 9999;

	if (num == 10) // 스위치 10개 경우를 다봤을때 (0,1,2,3,4,5,6,7,8,9 다음은 10이니까)
		if (Num12 == 16) // 전부 12시 인지 체크 
			return 0; // cnt의 합만 알아내기 위해서
		else
			return ret;

	for (int cnt = 0; cnt < 4; ++cnt)
	{
		int cand = cnt + check(num + 1); // for문에 있는 cnt를 더해가는게 포인트 
		if (ret > cand) ret = cand;

		/* 버튼 누르는 코드*/ // 버튼 누르는 코드가 재귀함수 밑에 있어야 한다. 0번 누른것도 알아야하기 때문. 
		for (int j = 0; j < 16; j++)
		{
			if (linked[num][j] == 'x')
			{
				Clock[j]++;
				if (Clock[j] == 4)
				{
					Clock[j] = 0;
					Num12++;
				}
				if (Clock[j] == 1)
					Num12--;
			}
		}
	}
	return ret;
}

int main()
{
	cin >> tc;

	for (int T = 0; T < tc; ++T)
	{
		Num12 = 0;
		for (int i = 0; i < 16; ++i)
		{
			int a;
			cin >> a;
			switch (a)
			{
			case 12:
				Clock[i] = 0;
				Num12++;
				break;
			case 3:
				Clock[i] = 1;
				break;
			case 6:
				Clock[i] = 2;
				break;
			case 9:
				Clock[i] = 3;
				break;
			}
		}

		int result = check(0);
		if (check(0) == 9999)
			cout << "-1" << endl;
		else
			cout << result << endl;
	}

	return 0;
}