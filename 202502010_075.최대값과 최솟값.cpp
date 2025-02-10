//URL :https://school.programmers.co.kr/learn/courses/30/lessons/12939

#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string s) {
    string answer = "";
    map<int,int> numMap;
    int result = -1;
    int curPos = 0;
    string temp = "";
    while (true)
    {

        temp += s[curPos] ;
        curPos++;
        if (s[curPos] == ' ' || curPos == s.length())
        {
            result = stoi(temp);
            numMap.emplace(result, result);
            temp = "";
            curPos++;

        }
        if (curPos >= s.length() )
        {
            break;
        }
    }
  
    map<int,int>::iterator iter = numMap.begin();
    answer += to_string(iter->first);
    answer += ' ';
    iter = numMap.end();
    iter--;
    answer += to_string(iter->first);

    return answer;
}