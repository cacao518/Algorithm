/*
https://www.algospot.com/judge/problem/read/ITES
*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>

using namespace std;

int main()
{
	int tc, N, K;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		queue<int> q;
		int count = 0, kk = 0;
		long long first = 1983;

		cin >> K >> N;
		for (int j = 0; j < N; j++)
		{
			int input = first % 10000 + 1;
			q.push(input);
			first = (first * 214013 + 2531011) % (long long)pow(2, 32);

			kk += input;
			while (kk > K)
			{
				kk -= q.front();
				q.pop();
			}
			if (kk == K)
			{
				count++;
				kk -= q.front();
				q.pop();
			}
		}
		cout << count << endl;
	}
	return 0;
}