#include<iostream>

using namespace std;

int num; // ���� ��
int h[20000]; // �� ���� ����

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
	if (start == end) return maxH = max(maxH, h[start]); // ���ڰ� 1�� �ۿ� ���� ���
	
	int n = 2; // Ž�� ��
	int left_idx = mid; 
	int right_idx = mid+1;
	int curH = min(h[mid], h[mid + 1]); // ���� �ڸ� ���ڴ��� 1�� ũ��(���� ����)
	maxH = max(maxH, curH * n); 
	
	while (true) // �ִ� ���� Ž��(������ ���� ����鼭 Ž�������� ū�� �켱���� Ž���Ѵ�.) 
	{
		if (right_idx < end)
		{
			if (left_idx == start || h[right_idx + 1] >= h[left_idx - 1])
			{
				n++;
				right_idx++;
				curH = min(curH, h[right_idx]);
				maxH = max(maxH, curH * n); // Ž���� ���ڼ��� ���� �ڸ� �������ڸ� ���Ѵ�.
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
		
		if (n == (end-start)+1) // ��� ���ڸ� �� Ž���ϸ� ����
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