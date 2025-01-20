//URL :https://school.programmers.co.kr/learn/courses/30/lessons/140108

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
     int answer = 0;
    char Chr = s[0];
    int CharCnt = 0;
    int CharCnt2 = 0;
    string tempStr = "";
    vector<string> V1;
    CharCnt++;
    tempStr = s[0];
    for (int j = 1; j < s.size();++j)
    {
        if (Chr == s[j])
        {
            CharCnt++;
            tempStr += s[j];
        }
        else {
            CharCnt2++;
            tempStr += s[j];
            if (CharCnt == CharCnt2)
            {
                CharCnt= 1;
                CharCnt2 = 0;

                V1.push_back(tempStr);
                tempStr = "";
                
                if (j + 1 >= s.size())
                {
                    break;
                }
                else
                {
                    Chr = s[j + 1];
                    ++j;
                    tempStr += Chr;
                }
            }
        }
    }
       
    int add = tempStr != "" ? 1 : 0;
    return answer = V1.size()+ add;
}