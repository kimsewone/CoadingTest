//URL : https://school.programmers.co.kr/learn/courses/30/lessons/68935

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;

    vector<int> v;
    int temp = n;
    int temp2 = 0;
    while (true)
    {
        temp2 = temp / 3;
        v.push_back(temp % 3);
        temp = temp2;
        if (0 == temp)
            break;
    }

    reverse(v.begin(), v.end());
    int result = 0;
    int multiply3 = 1;
    for (int i = 0; i < v.size();i++)
    {
        result += v[i] * multiply3;
        multiply3 *= 3;
    }

    return answer = result;
}