//URL : https://school.programmers.co.kr/learn/courses/30/lessons/161989

#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int idx = 0;
    int clearCnt = 0;
    int Max = 0;

    while (clearCnt < section.size())
    {
        idx = section[clearCnt] - 1;
        Max = n < idx + m ? n : idx + m;
        for (int i = idx; i < Max; ++i)
        {
            if (i == section[clearCnt] - 1)
            {
                clearCnt++;
                if (clearCnt >= section.size())
                    break;
            }
        }
        answer++;
    }

    return answer;
}