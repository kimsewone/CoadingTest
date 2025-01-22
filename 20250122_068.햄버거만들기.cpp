//URL :https://school.programmers.co.kr/learn/courses/30/lessons/133502

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string StrHam = { "1231" };
    string StrIngredient = "";
    int SucessIdx = 0;
    int nPos = 0;
    int cnt = 0 ;

    for (int i = 0; i < ingredient.size();++i)
        StrIngredient += to_string(ingredient[i]);//+'0';  
   
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