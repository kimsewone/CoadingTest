//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12950

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> tempArr;


    for (int j = 0; j < arr1.size();++j) {
        vector<int> v;
        answer.push_back(v);

        for (int i = 0; i < arr1[j].size();++i)
            answer[j].push_back(arr1[j][i] + arr2[j][i]);
    }

    return answer;
}