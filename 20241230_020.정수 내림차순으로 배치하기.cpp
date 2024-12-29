//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12933

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	long long NumPos = 1000000000;
	vector<int> Vector;

	if (1 > n)
		n = 1;
	else if (8000000000 < n)
		n = 8000000000;

	while (NumPos > n)
	{
		NumPos /= 10;
	}
	long long temNum1 = n;
	long long temNum2 = 0;
	long long NumPos2 = NumPos;
	while (true)
	{
		temNum2 = temNum1 / NumPos;
		temNum1 -= temNum2 * NumPos;
		Vector.push_back(temNum2);
		NumPos /= 10;
		if (NumPos < 1)
			break;
	}
	sort(Vector.rbegin(), Vector.rend());

	int i = 1;
	for (int num : Vector)
	{
		answer += num * NumPos2;
		NumPos2 /= 10;
	}

	return answer;
}