//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12943

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;

    if (0 == num)
        return 0;
    if (1 > num)
        num = 1;
    else if (8000000 < num)
        num = 8000000;

    long long TempNum = num;
    int Cnt = 0;
    while (TempNum > 1)
    {
        if (0 == TempNum % 2)//Â¦¼ö
        {
            TempNum /= 2;
        }
        else {//È¦¼ö
            TempNum = TempNum * 3 + 1;
        }

        Cnt++;
        if (500 <= Cnt)
        {
            Cnt = -1;
            break;
        }
    }

    return answer = Cnt;
}