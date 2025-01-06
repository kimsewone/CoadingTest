//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12901

#include <string>
#include <vector>

using namespace std;
int GetDay(int week, int b)
{
    int temp = week + (b % 7);

    return temp;
}
string solution(int a, int b) {
    string answer = "";
    int WeekArr[] = { 5,1,2,5,0,3,5,1,4,6,2,4 };
    vector<string> WeekStrArr = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
    int calcul = (WeekArr[a - 1] + (b % 7) - 1);
    calcul = calcul < 0 ? 7 + calcul : calcul;
    string day = WeekStrArr[calcul % 7];
    return answer = day;
}