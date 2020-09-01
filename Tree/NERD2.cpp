#include<iostream>
#include<map>
using namespace std;

int func(map<int, int>& tree, int p, int q)
{
	if (!tree.empty())
	{
		map<int, int>::iterator iter;
		iter = tree.lower_bound(p);
		if (iter == tree.end())
			tree.insert(pair<int,int>(p,q));
		else if(p > (*iter).first || q > (*iter).second)
			tree.insert(pair<int, int>(p, q));

		iter = tree.lower_bound(p);
		if (iter == tree.begin()) return tree.size();
		iter--;
		while (1)
		{
			if (q < (*iter).second)
				break;
			else if (iter == tree.begin())
			{
				tree.erase(iter);
				break;
			}
			else
			{
				map<int, int>::iterator iter2 = iter;
				iter2--;
				tree.erase(iter);
				iter = iter2;
			}
		}
	}
	else
		tree.insert(pair<int, int>(p, q));

	return tree.size();
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; ++t)
	{
		map<int, int> tree;
		int playerNum;
		cin >> playerNum;
		int sum = 0;
		for (int i = 0; i < playerNum; ++i)
		{
			int p, q;
			cin >> p >> q;
			sum += func(tree, p, q);
		}
		cout << sum << endl;
	}
	return 0;
}