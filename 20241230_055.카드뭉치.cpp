//URL : https://school.programmers.co.kr/learn/courses/30/lessons/159994#qna

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    string nStr = "";
    string C1Str = "";
    string C2Str = "";
    int card1Idx = 0;
    int card2Idx = 0;
    for (int n = 0;n < goal.size();++n)
    {
        nStr = goal[n];
        C1Str = cards1[card1Idx];
        C2Str = cards2[card2Idx];
        if (nStr == C1Str)
        {
            card1Idx = card1Idx < cards1.size() - 1 ? card1Idx + 1 : card1Idx;
        }
        else if (nStr == C2Str)
        {
            card2Idx = card2Idx < cards2.size() - 1 ? card2Idx + 1 : card2Idx;
        }
        else
        {
            answer = "No";
            break;
        }
    }
    if (answer == "")
        answer = "Yes";


    return answer;
}