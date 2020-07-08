#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int num;
string wc; // 와일드카드 워드
string word[50];
vector<string> result;
bool onceFlag = true;

int cache[101][101]; 

void solve(string word, int wc_idx, int word_idx)
{
	if (cache[wc_idx][word_idx] == 1) // *에 검사된 글자들은 재귀호출하지말고 바로 wc_idx 증가
		wc_idx++;
	
	if (wc[wc_idx] == '?')
	{ 
		wc_idx++;
		word_idx++;
	}
	else if (wc[wc_idx] == '*')
	{
		if (word_idx != word.size())
		{
			cache[wc_idx][word_idx] = 1; // *에 검사된 글자들은 캐시에 저장
			solve(word, wc_idx, word_idx + 1);
		}
		wc_idx++;
	}
	else if (wc[wc_idx] == word[word_idx])
	{
		wc_idx++;
		word_idx++;
	}
	else
	{ 
		return;
	}

	if (wc.size() + 1 == wc_idx && word.size() + 1 == word_idx)
	{
		if (onceFlag)
		{
			word.pop_back(); // 골뱅이 제거
			result.push_back(word);
			onceFlag = false;
		}
		return;
	}
	if (wc.size() + 1 == wc_idx)
		return;
	
	if (word.size() + 1 <= word_idx)
		return;

	solve(word, wc_idx, word_idx);
}

int main()
{
	int tc;
	cin >> tc;

	for (int T = 0; T < tc; ++T)
	{
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				cache[i][j] = -1;

		for (int j = 0; j < 50; j++)
			word[j] = '0';

		cin >> wc;
		cin >> num;
		wc.push_back('@');
		for (int i = 0; i < num; ++i)
		{
			onceFlag = true;
			cin >> word[i];
			word[i].push_back('@');
			solve(word[i], 0, 0);
		}
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); ++i)
		cout << result.at(i) << endl;

	return 0;
}