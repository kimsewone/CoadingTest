//URL : https://school.programmers.co.kr/learn/courses/30/lessons/77484

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> tempArr;
    sort(lottos.rbegin(), lottos.rend());
    sort(win_nums.rbegin(), win_nums.rend());
    int zeroCnt = 0;
    for (int j = win_nums.size() - 1; j >= 0;--j)
    {
        for (int i = lottos.size() - 1; i >= 0;--i)//for(int i = 0 ; i < lottos.size();++i)
        {
            if (lottos[i] == 0)
            {
                continue;
            }
            if (win_nums[j] == lottos[i])
            {
                win_nums.erase(win_nums.begin() + j);
                lottos.erase(lottos.begin() + i);
                break;
            }
        }
    }
    for (int i = 0; i < lottos.size();++i)
    {
        if (lottos[i] == 0)
            zeroCnt++;
    }
    int low = 0;
    int high = 0;

    if (lottos.size() == 0)
    {
        low = 1;
        high = 1;
    }
    else if (6 == zeroCnt)
    {
        low = 6;
        high = 1;
    }
    else if (lottos.size() == 6 && 0 == zeroCnt)
    {
        low = 6;
        high = 6;
    }
    else
    {
        low = lottos.size() + 1;//- > 6 ? 6 : lottos.size() + 1;
        high = lottos.size() - zeroCnt + 1 <= 0 ? 1 : lottos.size() - zeroCnt + 1;
    }


    answer.push_back(high);
    answer.push_back(low);

    return answer;
}