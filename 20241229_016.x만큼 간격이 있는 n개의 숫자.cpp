//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12954

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    if (-10000000 > n)
        n = -10000000;
    else if (10000000 < n)
        n = 10000000;


    for (int i = 0; i < n;++i)
    {
        answer.push_back(x + (x * i));
    }


    return answer;
}