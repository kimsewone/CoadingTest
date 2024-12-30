//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12969

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)//최대공약수
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    int Result1 = 0;

    Result1 = gcd(n, m);
    int Result2 = n * m / Result1;//최소공배수

    answer.push_back(Result1);
    answer.push_back(Result2);

    return answer;
}
