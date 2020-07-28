/*
https://www.algospot.com/judge/problem/read/BRACKETS2
*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
string str;

void func()
{
	stack<char> st;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			st.push(str[i]);
		else if (st.empty()) { st.push('('); break; }
		else if (str[i] == ')' && st.top() == '(')
			st.pop();
		else if (str[i] == '}' && st.top() == '{')
			st.pop();
		else if (str[i] == ']' && st.top() == '[')
			st.pop();
	}

	if (st.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> str;
		func();
	}

	return 0;
}