//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12931

#include <iostream>
#include <vector>

using namespace std;
int solution(int n)
{
    vector<int> NumPosVector;
    int answer = 0;
    int temp = 0;
    double NumPos = 100000000;

    while (true)
    {
        temp = n / NumPos;
        if (temp > 0)
            NumPosVector.push_back(temp);

        n = n - (temp * NumPos);

        NumPos *= 0.1;
        if (NumPos < 1)
            break;
    }

    if (10 <= NumPosVector.size())
        NumPosVector.resize(9);

    int TotalSum = 0;
    for (int num : NumPosVector)
    {
        TotalSum += num;
    }
    answer = TotalSum;


    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "TotalSum = " << answer << endl;

    return answer;
}