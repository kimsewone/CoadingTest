//URL :https://school.programmers.co.kr/learn/courses/30/lessons/133502

#include <string>
#include <vector>
#include <deque>
#include <map>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> hamArr = { 1,2,3,1 };
    string StrHam = { "1231" };
    string StrIngredient = "";//211231231
    int HamIdx = 0;
    int hamValue = 0;
    int SucessIdx = 0;
    int nPos = 0;
    
    for (int i = 0; i < ingredient.size();++i)
        StrIngredient += to_string(ingredient[i]);//+'0';  
        int cnt = 0 ;
    while (true)
    {
        nPos = StrIngredient.find(StrHam,cnt);
        if (nPos != string::npos)
        {
            StrIngredient.erase(nPos, 4);
            SucessIdx++;
         if (nPos > 2)
            cnt = nPos-3;
        }
        else
            break;
    }
    return answer = SucessIdx;
}