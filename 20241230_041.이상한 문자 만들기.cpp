#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int vIdx = 0;
    int fixCharValue = 0;
    char chr = '0';
    for (int i = 0; i < s.size();++i)
    {
        if (' ' == s[i])
        {
            vIdx = 0;
            answer += s[i];
        }
        else {
            fixCharValue = 0 == vIdx ? -32 : 0;
            vIdx = 1 == vIdx ? 0 : 1;
            chr = s[i];
            chr = 91 > chr ? static_cast<char>(s[i] + 32) : chr;
            answer += static_cast<char>(chr + fixCharValue);
        }
    }

    return answer ;
}