#include<iostream>
using namespace std;
#include<vector>
#include<string>

/*
https://www.algospot.com/judge/problem/read/QUADTREE
*/

int tc; // 테케
std::string image; // 입력 값 이미지

int idx = 0; // 이미지 탐색 인덱스

std::string Draw()
{
	std::string r_image; // 총 뒤집어진 이미지
	std::string sub_image[4]; // x뒤로 나오는 작은 이미지
	vector<char> piece; // 이미지당 조각은 4개

	if (image.size() > 1)
	{
		r_image += 'x';
		if(idx == 0) idx++;
	}
	else
		return image;

	for (int i = 0; i < 4; i++)
	{
		if (image[idx] == 'x')
		{ 
			idx++;
			sub_image[i] += Draw();
			piece.push_back('0');
		}
		else
		{
			piece.push_back(image[idx]);
			idx++;
		}
	}

	/* 그림 위치 swap */
	char temp;
	temp = piece[0];
	piece[0] = piece[2];
	piece[2] = temp;

	temp = piece[1];
	piece[1] = piece[3];
	piece[3] = temp;

	std::string sub_temp;
	sub_temp = sub_image[0];
	sub_image[0] = sub_image[2];
	sub_image[2] = sub_temp;

	sub_temp = sub_image[1];
	sub_image[1] = sub_image[3];
	sub_image[3] = sub_temp;

	for (int i = 0; i < 4; i++)
		if (piece.at(i) == '0')
			r_image += sub_image[i];
		else
			r_image += piece.at(i);

	return r_image;
}

int main()
{
	cin >> tc;
	
	for (int T = 0; T < tc; ++T)
	{
		idx = 0;
		cin >> image;
		cout << Draw() << endl;
	}
	
	return 0;
}
