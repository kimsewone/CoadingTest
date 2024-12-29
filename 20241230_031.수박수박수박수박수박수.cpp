//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12922

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    if (10000 < n)
        n = 10000;

    vector<string> StrArr = { "¼ö","¹Ú" };
    int Idx = 0;
    for (int i = 1; i <= n; ++i)
    {
        answer += StrArr[Idx];
        Idx++;
        if (1 < Idx)
            Idx = 0;
    }

    return answer;
}