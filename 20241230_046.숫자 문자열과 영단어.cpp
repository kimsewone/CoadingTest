//URL : https://school.programmers.co.kr/learn/courses/30/lessons/81301

#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> V =
    {
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
    multimap<int, string> mapResult;
    int temp = -1;
    int pos = 0;
    multimap<int, int> v2;
    int curPos = 0;
    int temp2 = -1;
    string findStr = "";
    vector<int> findStrIdxArr;
    int findIdx = 0;
    while (true) {
        for (int i = 0; i < V.size(); ++i)
        {
            temp = s.find(V[i], curPos);
            if (temp != string::npos && curPos == temp)
            {
                findIdx = 10 <= i ? i - 10 : i;
                findStrIdxArr.push_back(findIdx);

                findStr = V[i];
                curPos = temp + findStr.length();
                break;
            }
        }
        if (curPos >= s.length())
            break;
    }
    string resut = "";
    for (int i = 0; i < findStrIdxArr.size();++i)
        resut += to_string(findStrIdxArr[i]);
    answer = stoi(resut);
    return answer;
}