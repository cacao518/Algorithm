#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> AllHeight;

class Circle {

public:
	int m_id, m_x, m_y, m_r;
	vector<Circle*> m_child;

	Circle(int id, int x, int y, int r)
	{
		m_id = id;
		m_x = x;
		m_y = y;
		m_r = r;
	}
};

Circle* Insert(Circle* root, int id, int x, int y, int r)
{
	if (root == nullptr)
		return new Circle(id, x, y, r);
	else
	{
		for (int i = 0; i < root->m_child.size(); ++i)
		{
			if (Insert(root->m_child[i], id, x, y, r) != nullptr)
				return root;
		}
		// 자식노드가 없으면 아래 코드 실행
		double dist = sqrt(pow((root->m_y - y),2) + pow((root->m_x - x), 2));
		int r_b, r_s;
		if (r > root->m_r) { r_b = r; r_s = root->m_r; } else { r_b = root->m_r; r_s = r; }
		if (dist + r_s < r_b)
		{
			Circle* c = new Circle(id, x, y, r);
			root->m_child.push_back(c);
			return root;
		}
		else
			return nullptr;
	}
	return root;
}

void Find(Circle* root, int h)
{
	for (int i = 0; i < root->m_child.size(); ++i)
		Find(root->m_child[i], h+1);
	
	if (root->m_child.empty()) AllHeight.push_back(h);
}
bool desc(int a, int b)
{
	return a > b;
}
int main()
{
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; ++t)
	{
		int num;
		cin >> num;
		Circle* root = nullptr;
		for (int i = 0; i < num; ++i)
		{
			int x, y, r;
			cin >> x >> y >> r;
			root = Insert(root, i, x, y, r);
		}

		Find(root, 0);
		sort(AllHeight.begin(), AllHeight.end(), desc);

		if (AllHeight.size() == 1)
			cout << AllHeight[0] << endl;
		else 
			cout << AllHeight[0] + AllHeight[1] << endl;

		AllHeight.clear();
	}


	return 0;
}
