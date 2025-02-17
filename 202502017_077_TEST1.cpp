//URL :https://school.programmers.co.kr/learn/courses/30/lessons/12951

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int sPos = 0;
    bool checkEnd = false;
    char cuValue = ' ';
    while (true)
    {
        cuValue = s[sPos];
        int Ask = int(cuValue);
       
        if (0 == sPos)
        {
            //toupper tolower
            if (97 <= Ask && 122 >= Ask)
            {
                cuValue = toupper(cuValue);
                s[sPos] = cuValue;
            }
        }
        else if (0 != sPos &&' ' == s[sPos - 1])
        {
            cuValue = s[sPos];
            if (97 <= Ask && 122 >= Ask)
            {
                cuValue = toupper(cuValue);
                s[sPos] = cuValue;
            }
        }
        else if (65 <= Ask && 90 >= Ask)
        {
            cuValue = tolower(cuValue);
            s[sPos] = cuValue;
        }
        sPos++;

        if (sPos >= s.length())
        {

            break;
        }
    }
    //97-122
    return answer = s;
}