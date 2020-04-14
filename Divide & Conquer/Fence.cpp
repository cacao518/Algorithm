/*
https://www.algospot.com/judge/problem/read/FENCE
*/

#include <iostream>

using namespace std;

int tc;
int num = 0;
int h[20000];

int result = 0;

void max(int a, int b)
{
	if (a > b)
		result = a;
	else
		result = b;
}
void Part(int start, int end)
{
	if (start == end)
	{
		max(h[start], result);
		return;
	}

	int mid = (int)(start+end) / 2;

	int w = 2;
	int left = mid;
	int right = mid + 1;
	int min = h[right];
	int New = h[left];

	while (1)
	{
		if (New < min)
			min = New;

		max(min * w, result);

		if (w >= (end - start) + 1)
			break;

		if (!(left - 1 >= start))
		{
			right++;
			New = h[right];
			w++;
			continue;
		}
		if (!(right + 1 <= end))
		{
			left--;
			New = h[left];
			w++;
			continue;
		}
		
		if (h[left - 1] >= h[right + 1] && left - 1 >= start)
		{
			left--;
			New = h[left];
		}

		else if (h[left - 1] <= h[right + 1] && right + 1 <= end)
		{
			right++;
			New = h[right];
		}

		w++;
	}
	
	Part(start, mid);
	Part(mid+1, end);
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


		Part(0, num - 1);
		cout << result << endl;
	}
	
	return 0;
}