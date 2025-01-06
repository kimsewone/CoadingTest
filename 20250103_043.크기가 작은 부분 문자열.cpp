//URL : https://school.programmers.co.kr/learn/courses/30/lessons/86491

#include <iostream>
#include <vector>
using namespace std;
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxValue = 0;
    int sArr1[2] = { 0 };
    int sArr2[2] = { -1 };
    int tempsize = 0;
    for (int j = 0; j < sizes.size();++j)
    {
        if (sizes[j][0] < sizes[j][1]) {
            tempsize = sizes[j][0];
            sizes[j][0] = sizes[j][1];
            sizes[j][1] = tempsize;
        }
    }

    for (int j = 0; j < sizes.size();++j)
    {
        for (int i = 0; i < sizes[j].size();++i)
        {
            if (sizes[j][i] > maxValue)
            {
                sArr1[0] = j;
                sArr1[1] = i;
                maxValue = sizes[j][i];
            }
        }
    }
    int firstWValue = sizes[sArr1[0]][sArr1[1]];

    int secondHValue = -1;
    for (int j = 0; j < sizes.size();++j)
    {
        if (secondHValue < sizes[j][1]) {
            secondHValue = sizes[j][1];
            sArr2[0] = j;
            sArr2[1] = sizes[j][1];
        }
    }
  
    secondHValue = sizes[sArr2[0]][1];
    answer = firstWValue * secondHValue;
    return answer;
}