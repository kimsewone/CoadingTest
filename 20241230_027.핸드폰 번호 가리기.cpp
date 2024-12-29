//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12948

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";

    int Size = phone_number.length() > 20 ? 20 : phone_number.length();
    int FirstPos = Size - 4;
    int LastPos = Size;
    string tempStr = "";
    for (int i = 0; i < Size - 4;++i)
    {
        tempStr += "*";
    }
    for (int i = Size - 4; i < Size;++i)
    {
        tempStr += phone_number[i];
    }
    return answer = tempStr;
}
