//URL : https://school.programmers.co.kr/learn/courses/30/lessons/134240

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int CurFoodCnt = 0;
    string MyGetFoods = "";
    for (int i = 1; i < food.size();++i)
    {
        CurFoodCnt = food[i] / 2;
        if (0 < CurFoodCnt)
        {
            while (0 < CurFoodCnt)
            {
                MyGetFoods += char(i + 48);
                CurFoodCnt--;
            }
        }
    }
    string ReverseStr = MyGetFoods;
    reverse(ReverseStr.begin(), ReverseStr.end());
    MyGetFoods += '0' + ReverseStr;

    return answer = MyGetFoods;
}