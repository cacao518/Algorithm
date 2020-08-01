#include<iostream>
using namespace std;


int func(int n, int m, int k)
{
    int ret = 0;
    if (k < 0) return 0;
    if (m <= 0 && n <= 0) return 1;

    if (n > 0) ret += func(n - 1, m, k + 1);
    if (m > 0) ret += func(n, m - 1, k - 1);

    return ret;
}

int main()
{
    int n, m, k;

    cin >> n >> m >> k;
    cout << "ÃÑ " << func(n, m, k) << "°¡Áö";

    return 0;
}