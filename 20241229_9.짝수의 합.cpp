//URL : https://school.programmers.co.kr/learn/courses/30/lessons/120831

#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    int answer = 0;

    if (0 > n)
        n = 0;
    else if (1000 < n)
        n = 1000;

    int temp = 0;
    int sum = 0;

    while (true)
    {
        temp += 2;
        if (temp <= n)
        {
            sum += temp;
        }
        else {
            break;
        }
    }

    return answer = sum;
}