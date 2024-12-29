//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12932

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;
	vector<int> tempV;
	if (10000000000 < n)
		n = 10000000000;

	long long NumPos = 10000000000;
	while (NumPos > n)
	{
		NumPos /= 10;
	}

	long long temp = 0;
	long long n2 = n;
	while (true)
	{
		temp = n2 / NumPos;
		tempV.push_back((int)temp);
		n2 -= temp * NumPos;

		NumPos /= 10;
		if (NumPos == 0)
			break;
	}
	for (int i = tempV.size() - 1; i >= 0;--i)
	{
		answer.push_back(tempV[i]);
	}

	return answer;
}