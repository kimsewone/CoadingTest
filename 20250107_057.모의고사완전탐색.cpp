//URL : https://school.programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compareSecond(pair<int, int> A, pair<int, int> B)
{
    return A.second > B.second;
}
bool compareFirst(int A, int B)
{
    return A < B;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> student1 = { 1, 2, 3, 4, 5 };
    vector<int> student2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> student3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<vector<int>> studentsArr = { student1,student2,student3 };
    int stIdx = 0;
    int answerCnt = 0;
    map<int, int> answerResultMap;
    vector< pair<int, int>> answerResultArr;
    for (int j = 0; j < studentsArr.size(); ++j)
    {
        vector<int> st = studentsArr[j];
        for (int i = 0; i < answers.size(); ++i)
        {
            if (st.size() <= stIdx)
                stIdx = 0;
            if (st[stIdx] == answers[i])
                answerCnt++;
            stIdx++;
        }
        if (answerCnt != 0)
            answerResultArr.push_back(make_pair(j + 1, answerCnt));
        answerCnt = 0;
        stIdx = 0;
    }
    pair<int, int> firstSt;
    vector<int> rank;
    if (answerResultArr.size() > 1) {
        sort(answerResultArr.begin(), answerResultArr.end(), compareSecond);
        firstSt = answerResultArr[0];
        for (int i = 0; i < answerResultArr.size(); ++i)
        {
            if (firstSt.second == answerResultArr[i].second)
            {
                rank.push_back(answerResultArr[i].first);
            }
        }
        if (rank.size() > 1)
        {
            sort(rank.begin(), rank.end(), compareFirst);
            for (int i = 0; i < rank.size(); ++i)
                answer.push_back(rank[i]);
        }
        else
            answer.push_back(answerResultArr[0].first);
    }
    else
        answer.push_back(answerResultArr[0].first);


    return answer;
}