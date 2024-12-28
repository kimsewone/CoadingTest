//URL : https://school.programmers.co.kr/learn/courses/30/lessons/120817

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {

	if (numbers.size() == 0)
		return 0;

	double answer = 0;
	int TotalSum = 0;
	int vectorSize = 0;
	for (int num : numbers)
	{
		if (vectorSize > 100)
			break;

		if (num > 1000)
			num = 1000;

		TotalSum += num;
		vectorSize++;
	}

	int temp = (TotalSum * 10) / vectorSize;
	answer = (double)temp / 10;

	return answer;
}