//URL :https://school.programmers.co.kr/learn/courses/30/lessons/155652

#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string tempSkip = "";
    int result = 0;
    int curCnt = 0;
    for (int i = 0; i < s.length();++i)
    {
        char tempChr = s[i];
        tempSkip = skip;
        curCnt = 0;
        while(true)
        {
            tempChr++;
            tempChr = 'z' < tempChr ? tempChr - 26 : tempChr;
          
             result = tempSkip.find(tempChr);

            if (result == string::npos)
            {
                curCnt++;
                if (index <= curCnt)
                    break;
            }
        }
        answer += tempChr;
    }

    return answer;
}