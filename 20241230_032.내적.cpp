//URL : https://school.programmers.co.kr/learn/courses/30/lessons/70128

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    int TempSize = a.size();
    if (1000 < a.size())
        TempSize = 1000;

    for (int i = 0; i < TempSize;++i)
    {
        answer += a[i] * b[i];
    }


    return answer;
}