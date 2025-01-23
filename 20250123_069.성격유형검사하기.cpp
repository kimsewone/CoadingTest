//URL :https://school.programmers.co.kr/learn/courses/30/lessons/118666

#include <string>
#include <vector>

using namespace std;
struct SData
{
    char Name = '0';
    int Score = 0;
    SData(char c1)
    {
        Name = c1;
    }
};
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<SData> ResultInfoArr;
    ResultInfoArr.push_back(SData('R'));
    ResultInfoArr.push_back(SData('T'));
    ResultInfoArr.push_back(SData('C'));
    ResultInfoArr.push_back(SData('F'));
    ResultInfoArr.push_back(SData('J'));
    ResultInfoArr.push_back(SData('M'));
    ResultInfoArr.push_back(SData('A'));
    ResultInfoArr.push_back(SData('N'));
  
    for (int j = 0; j < choices.size();++j)
    {
        if (1 == choices[j])
        {
            for (int i = 0; i < ResultInfoArr.size();++i)
            {
                if (ResultInfoArr[i].Name == survey[j][0])
                    ResultInfoArr[i].Score += 3;
            }
        }
        else if (2 == choices[j])
        {
            for (int i = 0; i < ResultInfoArr.size();++i)
            {
                if (ResultInfoArr[i].Name == survey[j][0])
                    ResultInfoArr[i].Score += 2;
            }
        }
        else if (3 == choices[j])
        {
            for (int i = 0; i < ResultInfoArr.size();++i)
            {
                if (ResultInfoArr[i].Name == survey[j][0])
                    ResultInfoArr[i].Score += 1;
            }
        }
        else if (4 == choices[j])
        {
            for (int i = 0; i < ResultInfoArr.size();++i)
            {
                if (ResultInfoArr[i].Name == survey[j][0])
                    ResultInfoArr[i].Score += 0;
            }
        }
        else if (5 == choices[j])
        {
            for (int i = 0; i < ResultInfoArr.size();++i)
            {
                if (ResultInfoArr[i].Name == survey[j][1])
                    ResultInfoArr[i].Score += 1;
            }
        }
        else if (6 == choices[j])
        {
            for (int i = 0; i < ResultInfoArr.size();++i)
            {
                if (ResultInfoArr[i].Name == survey[j][1])
                    ResultInfoArr[i].Score += 2;
            }
        }
        else if (7 == choices[j])
        {
            for (int i = 0; i < ResultInfoArr.size();++i)
            {
                if (ResultInfoArr[i].Name == survey[j][1])
                    ResultInfoArr[i].Score += 3;
            }
        }
    }
    int idx = 0;
    for (int i = 0; i < 4; ++i)
    {
        answer += ResultInfoArr[idx].Score >= ResultInfoArr[idx + 1].Score ? ResultInfoArr[idx].Name : ResultInfoArr[idx + 1].Name;
        idx += 2;
    }

    return answer;
}