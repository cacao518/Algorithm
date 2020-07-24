#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int tc;
int m, n;
int A[100], B[100], cache[100][100];

int jlis(int a, int b, int num)
{
	int &ret = cache[a+1][b+1];
	if (ret != -1) return ret;

	ret = 2;
	for (int i = a + 1; i < m; i++)
	{
		if ((a == -1 && b == -1) || num < A[i])
			ret = max(ret, jlis(i, b, A[i]) + 1);
	}
	for (int i = b + 1; i < n; i++)
	{
		if ((a == -1 && b == -1) || num < B[i])
			ret = max(ret, jlis(a, i, B[i]) + 1);
	}
	return ret;
}

int main()
{
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		cin >> m >> n;
		memset(cache, -1, sizeof(cache));

		for (int M = 0; M < m; M++)
			cin >> A[M];
		for (int N = 0; N < n; N++)
			cin >> B[N];

		cout << jlis(-1, -1, 0) -2 << endl;
	}
	return 0;
}