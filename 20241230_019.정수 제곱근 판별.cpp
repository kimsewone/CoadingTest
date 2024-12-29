//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12934

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long num) {

	/* sqrt 함수 사용
	* 
		long long result = 0;
		double TempResult = sqrt(static_cast<double>(num));
		if (TempResult != static_cast<int>(TempResult))
			return -1;
		result = (long long)TempResult;
		return  (result + 1) * (result + 1);
	
	*/


	//이진트리 활용
	long long answer = 0;
	long long high = num;
	long long mid = 0;
	long long low = 0;

	int cnt = 0;

	if (1 > num)
		num = 1;
	else if (50000000000000 < num)
		num = 50000000000000;

	while (true)
	{
		mid = (high + low) / 2;
		if (mid * mid == num)
			break;
		else if (mid * mid > num)
		{
			if (high == mid)
				return -1;

			high = mid;
		}
		else
		{
			if (low == mid)
				return -1;

			low = mid;
		}
		cnt++;
	}
	answer = (mid + 1) * (mid + 1);
	return answer;
}