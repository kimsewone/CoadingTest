//URL : https://school.programmers.co.kr/learn/courses/30/lessons/142086

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string tempStr = "";
    string tempCurStr = "";
    int findIdx = 0;
    int findResutIndx = 0;
    for (int j = 0; j < s.length();++j)
    {
        tempCurStr = s[j];
        findIdx = tempStr.length() - 1;
        while (true)
        {
            findResutIndx = tempStr.rfind(tempCurStr, findIdx);
            if (findResutIndx == string::npos)
            {
                answer.push_back(-1);
                break;
            }
            else
            {
                answer.push_back(j - findResutIndx);
                break;
            }
        }
        tempStr += s[j];
    }
    return answer;
}