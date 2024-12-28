//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12937

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    int VectorSize = 0;
    int TotalSum = 0;
    for (int num : arr)
    {
        if (VectorSize > 100)
            break;

        if (-10000 > num)
            num = -10000;
        else if (10000 < num)
            num = 10000;

        TotalSum += num;

        VectorSize++;
    }

    return answer = (double)TotalSum / (double)VectorSize;
}