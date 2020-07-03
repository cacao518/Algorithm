#include<iostream>

using namespace std;

int num; // 나무 수
int h[20000]; // 각 나무 높이

int max(int a, int b)
{
	if (a >= b) return a; else return b;
}
int min(int a, int b)
{
	if (a <= b) return a; else return b;
}

int fence(int start, int end, int maxH)
{
	int mid = (start + end) / 2;
	if (start == end) return maxH = max(maxH, h[start]); // 판자가 1개 밖에 없을 경우
	
	int n = 2; // 탐색 수
	int left_idx = mid; 
	int right_idx = mid+1;
	int curH = min(h[mid], h[mid + 1]); // 현재 자른 판자단위 1개 크기(가장 작은)
	maxH = max(maxH, curH * n); 
	
	while (true) // 최대 넓이 탐색(오른쪽 왼쪽 벌어가면서 탐색하지만 큰거 우선으로 탐색한다.) 
	{
		if (right_idx < end)
		{
			if (left_idx == start || h[right_idx + 1] >= h[left_idx - 1])
			{
				n++;
				right_idx++;
				curH = min(curH, h[right_idx]);
				maxH = max(maxH, curH * n); // 탐색한 판자수와 현재 자른 단위판자를 곱한다.
			}
		}
		if (left_idx > start)
		{
			if (right_idx == end || h[right_idx + 1] <= h[left_idx - 1])
			{
				n++;
				left_idx--;
				curH = min(curH, h[left_idx]);
				maxH = max(maxH, curH * n);
			}
		}
		
		if (n == (end-start)+1) // 모든 판자를 다 탐색하면 종료
			break;
	}
	return max(fence(start, mid, maxH), fence(mid + 1, end, maxH));
}


int main()
{
	int tc;
	cin >> tc;
	for (int T = 0; T < tc; ++T)
	{
		cin >> num;
		for (int i = 0; i < num; ++i)
			cin >> h[i];

		cout << fence(0, num-1, 0) << endl;
	}

	return 0;
}