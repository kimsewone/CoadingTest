//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12947

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;
	vector<int> Vector;
	int NumPos = 10000;

	if (1 > x)
		x = 1;
	else if (10000 < x)
		x = 10000;

	while (NumPos > x)
	{
		NumPos /= 10;
	}
	int temNum1 = x;
	int temNum2 = 0;
	int NumPos2 = NumPos;
	while (true)
	{
		temNum2 = temNum1 / NumPos;
		temNum1 -= temNum2 * NumPos;
		Vector.push_back(temNum2);
		NumPos /= 10;
		if (NumPos < 1)
			break;
	}

	int tempNum = 0;
	for (int num : Vector)
	{
		tempNum += num;
	}
	answer = x % tempNum == 0 ? true : false;

	return answer;
}