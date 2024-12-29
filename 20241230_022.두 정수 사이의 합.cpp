//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12912

#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if (a == b)
        return a;
    if (-10000000 > a)
        a = -10000000;
    else if (10000000 < a)
        a = 10000000;
    if (-10000000 > b)
        b = -10000000;
    else if (10000000 < b)
        b = 10000000;

    long long tempValue = abs(a - b);
    long long tempValue2 = a + b;
    if (a < b)
    {
        for (int i = 1; i < tempValue;++i)
            tempValue2 += a + i;
    }
    else {
        for (int i = 1; i < tempValue;++i)
            tempValue2 += a - i;
    }

    return answer = tempValue2;
}