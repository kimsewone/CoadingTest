//URL : https://school.programmers.co.kr/learn/courses/30/lessons/136798

#include <string>
#include <vector>
#include <algorithm>
#include <valarray>
#include <cmath>
#include <map>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> numArr;
    map<int, int > Map;
    int number2 = number;

    for (int i = 1; i <= number2; i++)
    {
        int secondValue = 0;
        int temp = sqrt(i);
        for (int j = 1; j <= temp; j++)
        {
            if (0 == i % j)
            {
                secondValue++;
                if (j != i / j)
                    secondValue++;
            }
        }

        numArr.push_back(secondValue);
    }

    for (int i = 0; i < numArr.size(); i++)
    {
        if (numArr[i] > limit)
            numArr[i] = power;

        answer += numArr[i];
    }

    return answer;
}