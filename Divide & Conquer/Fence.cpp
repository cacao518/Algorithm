/*
https://www.algospot.com/judge/problem/read/FENCE
*/

#include <iostream>

using namespace std;

int tc;
int num = 0;
int h[20000];

int result = 0;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	cin >> tc;

	for (int T = 0; T < tc; ++T)
	{
		result = 0;
		cin >> num;

		for (int n = 0; n < num; ++n)
			cin >> h[n];
		
		for (int i = 0; i < num; i++)
		{
			result = max(h[i], result);

			if (h[i + 1] > h[i])
			{
				int w = 1;
				for (int e = i + 1; e < num; ++e)
					if (h[i] <= h[e]) w++; else break;

				result = max(w*h[i], result);
			}
			else 
			{
				int w = 1;
				for (int e = i + 1; e < num; ++e)
					if (h[i+1] <= h[e]) w++; else break;
				
				result = max(w*h[i + 1], result);
			}
			///////////////////////////////
			if (h[i - 1] > h[i])
			{
				
				int w = 1;
				for (int e = i - 1; e > -1; e--)
					if (h[i] <= h[e]) w++; else break;

				result = max(w*h[i], result);
			}
			else
			{
				int w = 1;
				for (int e = i - 1; e > -1; e--)
					if (h[i - 1] <= h[e]) w++; else break;

				result = max(w*h[i - 1], result);
			}
		}
		cout << result << endl;
	}

	return 0;
}