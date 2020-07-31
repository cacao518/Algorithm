#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<deque>
using namespace std;

string pi;
int cache[10002];
int minLevel = 99999;

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

void sepa(int remain, deque<int> all_idx)
{
	if (remain == 0)
	{
		int total = 0, a = 0, b = 0;
		for (int i = 0; all_idx.size(); i++)
		{
			a = b;
			b = b + all_idx.front();

			int& ret = cache[a];
			if (ret != -1)
				total += ret;
			else
				total += (ret = level(a, b));

			all_idx.pop_front();
		}
		minLevel = min(minLevel, total);
		return;
	}
	else if (remain < 3)
		return;
	
	for (int i = 3; i <= 5; i++)
	{
		if ((remain - i) >= 0)
		{
			all_idx.push_back(i);
			sepa(remain - i, all_idx);
			all_idx.pop_back();
		}	
	}
}

int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		for (int j = 0; j < 10002; j++)
			cache[j] = -1;

		deque<int> all_idx;
		minLevel = 99999;

		cin >> pi;
		sepa(pi.size(), all_idx);
		cout << minLevel << endl;
	}

	return 0;
}

