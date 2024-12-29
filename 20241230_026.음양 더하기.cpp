



//URL : https://school.programmers.co.kr/learn/courses/30/lessons/76501

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;

    int Idx = 0;
    int Sum = 0;
    for (int num : absolutes)
    {
        if (signs[Idx])
        {
            Sum += num;
        }
        else {
            Sum -= num;
        }
        Idx++;
        if (1000 <= Idx)
            break;
    }

    return answer = Sum;
}
