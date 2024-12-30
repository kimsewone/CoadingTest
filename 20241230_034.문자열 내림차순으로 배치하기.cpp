//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12917

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
	string answer = "";
	vector<char> StrArr;

	for (int i = 0; i < s.length();++i)
	{
		StrArr.push_back(s[i]);
	}
	sort(StrArr.rbegin(), StrArr.rend());


	for (int i = 0; i < StrArr.size();++i)
	{
		answer += StrArr[i];
	}

	return answer;
}