//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12910

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (int num : arr)
    {
        if (0 == num % divisor)
        {
            answer.push_back(num);
        }
    }
    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }
    else {
        sort(answer.begin(), answer.end());
    }

    return answer;
}