#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<deque>
using namespace std;

string pi;
int cache[10002];
int INF = 999999;

int level(int a, int b)
{
	string M = pi.substr(a, b - a + 1);
	if (M == string(M.size(), M[0])) return 1; 
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; ++i)
		if (M[i + 1] - M[i] != M[1] - M[0])
			progressive = false;
	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;
	bool alternating = true;
	for (int i = 0; i < M.size(); ++i)
		if (M[i] != M[i % 2])
			alternating = false;
	if (alternating) return 4;
	if (progressive) return 5;
	return 10;
}

int memorize(int begin)
{
	if (begin == pi.size()) return 0;
	int& ret = cache[begin];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int L = 3; L <= 5; ++L)
	{
		if (begin + L <= pi.size())
			ret = min(ret, memorize(begin + L) + level(begin, begin + L - 1));
	}
	return ret;
}
int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		for (int j = 0; j < 10002; j++)
			cache[j] = -1;

		cin >> pi;
		cout << memorize(0) << endl;
	}

	return 0;
}

