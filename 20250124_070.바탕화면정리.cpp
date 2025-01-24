//URL :https://school.programmers.co.kr/learn/courses/30/lessons/161990

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct XYPos
{
    int x = 0 ;
    int y = 0;
    XYPos(int _x , int _y)
    {
        x= _x;
        y= _y;
    }
};
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
    XYPos A = XYPos( XArr[0],YArr[0] );
    XYPos B = XYPos( XArr[XArr.size()-1], YArr[YArr.size()-1] );
    B.x +=1;
    B.y +=1;
    answer.push_back(A.x);
    answer.push_back(A.y);
    answer.push_back(B.x);
    answer.push_back(B.y);   
    return answer;
}