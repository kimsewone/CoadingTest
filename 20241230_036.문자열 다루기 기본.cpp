//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12918

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    int TempNum = 0;
    bool checkNum = true;
    bool chekcLength = false;

    if (4 != s.length() && 6 != s.length())
        return false;


    for (int i = 0; i < s.length();++i)
    {
        TempNum = (int)(s[i] - '0');
        if (9 < TempNum)
        {
            checkNum = false;
            break;
        }
    }

    return checkNum;
}