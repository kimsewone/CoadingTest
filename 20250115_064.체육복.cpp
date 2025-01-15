//URL :https://school.programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> V1;
    sort(lost.rbegin(), lost.rend());
    sort(reserve.rbegin(), reserve.rend());
    
    for (int j = lost.size() - 1; j >= 0;--j)
        for (int i = reserve.size() - 1; i >= 0;--i)
        {
            if (reserve[i]  == lost[j] )
            {
                lost.erase(lost.begin() + j);
                reserve.erase(reserve.begin()+i);  
                 break;
            }
        }
            
            
    for (int j = lost.size() - 1; j >= 0;--j)
    {
        for (int i = reserve.size() - 1; i >= 0;--i)
        {
            if (reserve[i] - 1 == lost[j] )
            {
                lost.erase(lost.begin() + j);
                reserve.erase(reserve.begin()+i);
                break;
            }
            else if ( reserve[i] + 1 == lost[j])
            {
                lost.erase(lost.begin() + j);
                reserve.erase(reserve.begin()+i);
                break;
            }
        }
    }

    return answer = n - lost.size();
}