//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12903

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int centerIdx = 0;

    int length = s.length();

    if (0 == length % 2)
    {
        centerIdx = length / 2 - 1;
        answer = s[centerIdx];
        answer += s[centerIdx + 1];
    }
    else {
        centerIdx = length / 2;
        answer = s[centerIdx];
    }


    return answer;
}