#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void PrintPostOrder(vector<int> preOrder, vector<int> inOrder)
{
	if (preOrder.empty())
		return;

	int root = preOrder[0];
	int rootIdx;
	for (int i = 0; i < inOrder.size(); ++i) if (inOrder[i] == root) { rootIdx = i; break; }
	int L = rootIdx;
	int R = inOrder.size() - rootIdx - 1;

	vector<int> preOrderSubL(preOrder.begin()+1, preOrder.begin()+L+1);
	vector<int> preOrderSubR(preOrder.begin() + L + 1, preOrder.end());
	vector<int> inOrderSubL(inOrder.begin(), inOrder.begin() + rootIdx);
	vector<int> inOrderSubR(inOrder.begin()+rootIdx+1, inOrder.end());
	
	PrintPostOrder(preOrderSubL, inOrderSubL);
	PrintPostOrder(preOrderSubR, inOrderSubR);
	cout << root << " ";
}



int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; ++i)
	{
		int num;
		cin >> num;
		vector<int> preOrder, inOrder;
		for (int j = 0; j < num; ++j)
		{
			int data;
			cin >> data;
			preOrder.push_back(data);
		}
		for (int j = 0; j < num; ++j)
		{
			int data;
			cin >> data;
			inOrder.push_back(data);
		}
		PrintPostOrder(preOrder, inOrder);
		cout << endl;
	}

	return 0;
}