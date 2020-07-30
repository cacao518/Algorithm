#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<deque>
using namespace std;

string pi;
int cache[10000][10000];
int minLevel = 99999;

int level(deque<int> &idx, int cur)
{
	if (idx.empty()) return 0;
	int range = idx.front() + cur;
	int& ret = cache[cur][range - 1];
	if (ret != -1)
	{
		return ret;
	}
	
	ret = 10;

	int inter = 0;
	for (int i = cur; i < range; i++)
	{
		if(i == cur)
			inter = pi.at(i + 1) - pi.at(i);
		else
		{
			if (i + 1 != range)
			{
				if (pi.at(i + 1) - pi.at(i) != inter)
					break;
			}
		}
		if (i == range - 1)
			ret = 5;
	}
	for (int i = cur; i < range; i++)
	{
		if (i + 1 != range)
		{
			if (!(pi.at(i) > pi.at(i + 1)))
				break;
		}
		else
		{
			if (!(pi.at(i) < pi.at(i - 1)))
				break;
		}
		if (i == range - 1)
			ret = 5;
	}
	for (int i = cur; i < range; i++)
	{
		if (i + 2 != range)
		{
			if (i + 2 <= range - 1)
				if (pi.at(i) != pi.at(i + 2))
					break;
		}
		else
		{
			if (i - 2 >= cur)
				if (pi.at(i) != pi.at(i - 2))
					break;
		}
		if (i == range - 1)
			ret = 4;
	}
	for (int i = cur; i < range; i++)
	{
		if (i + 1 != range)
		{
			if (pi.at(i + 1) - pi.at(i) != 1)
				break;
		}
		else
			if (pi.at(i) - pi.at(i - 1) != 1)
				break;
		if (i == range - 1)
			ret = 2;
	}
	for (int i = cur; i < range; i++)
	{
		if (i + 1 != range)
		{
			if (pi.at(i + 1) - pi.at(i) != -1)
				break;
		}
		else
			if (pi.at(i) - pi.at(i - 1) != -1)
				break;
		if (i == range - 1)
			ret = 2;
	}
	for (int i = cur; i < range; i++)
	{
		if (i + 1 != range)
		{
			if (pi.at(i) != pi.at(i + 1))
				break;
		}
		else
		{
			if (pi.at(i) != pi.at(i - 1))
				break;
		}
		if (i == range - 1)
			ret = 1;
	} 
	
	int f = idx.front();
	idx.pop_front();
	ret += level(idx, cur + f);

	return ret;
}

void sepa(int remain, deque<int> all_idx)
{
	if (remain == 0)
	{
		minLevel = min(minLevel, level(all_idx, 0));
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
		for (int i = 0; i < 10000; i++)
			for (int j = 0; j < 10000; j++)
				cache[i][j] = -1;

		deque<int> all_idx;
		minLevel = 99999;

		cin >> pi;
		sepa(pi.size(), all_idx);
		cout << minLevel << endl;
	}

	return 0;
}

