//URL : https://school.programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tempV;
    int beginPos = 0;
    int endPos = 0;
    int selectPos = 0;

    for (int j = 0; j < commands.size();++j)
    {
        for (int i = 0; i < commands[j].size();++i)
        {
            beginPos = commands[j][0] - 1;
            endPos = commands[j][1];
            selectPos = commands[j][2] - 1;
        }
        for (int n = beginPos; n < endPos;n++)
            tempV.push_back(array[n]);

        sort(tempV.begin(), tempV.end());
        answer.push_back(tempV[selectPos]);
        tempV.clear();
    }
    return answer;
}