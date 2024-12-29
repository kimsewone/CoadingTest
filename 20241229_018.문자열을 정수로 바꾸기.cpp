//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12925

#include <string>
#include <vector>
#include <cctype>
using namespace std;

int solution(string s) {
	int answer = 0;
	vector<int> vInt;
	int value = 0;
	int i = 0;
	int sign = 1;
	char ch = '0';
	for (int i = 0; i < s.length();++i)
	{
		ch = s[i];
		value = (int)ch - '0';
		if (i == 0)
		{
			if (!isdigit(ch))
			{
				if ('+' == ch)
					sign = 1;
				else
					sign = -1;
				continue;
			}
			if (0 == value)
				continue;
		}
		vInt.push_back(value);
	}

	int NumPosSize = 1;
	for (int i = 1; i < vInt.size();++i)
	{
		NumPosSize *= 10;
	}
	for (int value : vInt)
	{
		answer += value * NumPosSize;
		NumPosSize /= 10;
	}
	answer *= sign;

	return answer;
}