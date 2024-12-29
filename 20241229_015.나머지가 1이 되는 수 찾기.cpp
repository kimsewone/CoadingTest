//URL : https://school.programmers.co.kr/learn/courses/30/lessons/87389

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    if (3 > n)
        n = 3;
    else if (1000000 < n)
        n = 1000000;

    int temp = 2;
    while (true)
    {
        if (1 == n % temp)
            break;
        temp++;

    }


    return answer = temp;
}