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
		if (idx + 1 == arr.size()) // 끝에 도달한 경우
			idx = 0;
		else
		{
			if (arr.at(idx + 1) == 1) // 다음 사람이 살아 있을경우
			{
				idx++;
				count++;
			}
			else if (arr.at(idx + 1) == 0) // 다음 사람이 죽은 경우
				idx++;
		}
		if (count == K) // 죽이기
		{
			arr.at(idx) = 0;
			size--;
			count = 0;
		}
		if (size == 2) // 2명 남으면 탈출
			break;
	}
	
	for (int i = 0; i < arr.size(); i++) // 최후 2인 출력
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