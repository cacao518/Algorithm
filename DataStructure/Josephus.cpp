/*
https://www.algospot.com/judge/problem/read/JOSEPHUS
*/


#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
int N, K;

void jos()
{
	arr.clear();
	int size = 0;
	for (int i = 0; i < N; i++)
	{
		arr.push_back(1);
		size++;
	}

	int idx = 0;
	int count = 0;
	arr.at(idx) = 0;
	size--;
	
	while (1)
	{
		if (idx + 1 == arr.size()) // ���� ������ ���
			idx = 0;
		else
		{
			if (arr.at(idx + 1) == 1) // ���� ����� ��� �������
			{
				idx++;
				count++;
			}
			else if (arr.at(idx + 1) == 0) // ���� ����� ���� ���
				idx++;
		}
		if (count == K) // ���̱�
		{
			arr.at(idx) = 0;
			size--;
			count = 0;
		}
		if (size == 2) // 2�� ������ Ż��
			break;
	}
	
	for (int i = 0; i < arr.size(); i++) // ���� 2�� ���
	{
		if (arr.at(i) == 1)
			cout << i+1 << " ";
	}
	cout << endl;
}

int main()
{
	int tc;
	cin >> tc;
	for (int T = 0; T < tc; T++)
	{
		cin >> N >> K;
		jos();
	}
	return 0;
}