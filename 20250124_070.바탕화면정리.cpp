//URL :https://school.programmers.co.kr/learn/courses/30/lessons/161990

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> XArr;
    vector<int> YArr;
    for(int j = 0 ; j < wallpaper.size();++j)
    {
         for(int i = 0 ; i < wallpaper[j].length();++i)
         {
             if( '#' == wallpaper[j][i])
             {
                 XArr.push_back(j);
                 YArr.push_back(i);
             }
         }
    }
    
    sort(XArr.begin(),XArr.end());
    sort(YArr.begin(),YArr.end());
    int StartX = 0;
    int StartY = 0;
    int EndX = 0;
    int EndY = 0;
    StartX = XArr[0];
    StartY = YArr[0];
    EndX = XArr[XArr.size()-1]+1;
    EndY = YArr[YArr.size()-1]+1;

    answer.push_back(StartX);
    answer.push_back(StartY);
    answer.push_back(EndX);
    answer.push_back(EndY);   
    return answer;
}