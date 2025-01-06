//URL : https://school.programmers.co.kr/learn/courses/30/lessons/132267

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    long long answer = 0;
    long long GetColaCnt = 0;
    long long GetColaCnt2 = 0;
    while (a <= n)
    {
        GetColaCnt = n / a;
        GetColaCnt *= b;
        answer += GetColaCnt;
        GetColaCnt2 = n % a;
        n = GetColaCnt + GetColaCnt2;

    }
    return answer;
}