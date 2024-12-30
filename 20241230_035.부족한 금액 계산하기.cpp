//URL : https://school.programmers.co.kr/learn/courses/30/lessons/82612

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;

    if (1 > price)
        price = 1;
    else if (2500 < price)
        price = 2500;

    if (1 > money)
        money = 1;
    else if (1000000000 < money)
        money = 1000000000;

    if (1 > count)
        count = 1;
    else if (2500 < count)
        count = 2500;


    long long TotalPrice = 0;
    for (int i = 0; i < count;++i)
    {
        TotalPrice += price * (i + 1);
    }

    answer = money - TotalPrice;
    if (0 > answer)
    {
        return -answer;
    }
    else
        return 0;
}