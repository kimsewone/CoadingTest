//URL : https://school.programmers.co.kr/learn/courses/30/lessons/86051

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;

    sort(numbers.begin(), numbers.end());

    int Idx = 0;
    int Idx2 = 0;
    int Sum = 0;

    for (int i = 0; i < 10;++i)
    {
        if (i != numbers[Idx])
        {
            Sum += i;
        }
        else {
            Idx++;
        }
    }

    return answer = Sum;
}