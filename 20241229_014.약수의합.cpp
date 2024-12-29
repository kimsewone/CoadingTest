//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12928

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {

	vector<int> Vector;
	if (3000 < n)
		n = 3000;

	int answer = 0;

	int n2 = sqrt(n);
	for (int i = 1; i <= n2;++i)
	{
		if (0 == n % i) {
			Vector.push_back(i);
			if (i != n / i)
				Vector.push_back(n / i);
		}
	}


	int TotalSum = 0;
	for (int num : Vector)
	{
		TotalSum += num;
	}

	return answer = TotalSum;
}