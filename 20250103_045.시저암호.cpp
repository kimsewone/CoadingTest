//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12926

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size();++i)
    {
        if (97 <= s[i] && 122 >= s[i])
        {
            if (s[i] + n > 122)
                answer += s[i] - 26 + n;
            else
                answer += s[i] + n;
        }
        else  if (65 <= s[i] && 90 >= s[i])
        {
            if (s[i] + n > 90)
                answer += s[i] - 26 + n;
            else
                answer += s[i] + n;
        }
        else {
            answer += s[i];
        }
    }
    return answer;
}