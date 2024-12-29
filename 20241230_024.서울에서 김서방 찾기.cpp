//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12919

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    int idx = 0;
    int findIdx = -1;
    for (string str : seoul)
    {
        if (str.find("Kim") != string::npos)
        {
            findIdx = idx;
            break;
        }
        idx++;
        if (1000 <= idx)
            break;
    }

    answer = "김서방은 " + to_string(idx) + "에 있다";
    return answer;
}