//URL : https://school.programmers.co.kr/learn/courses/30/lessons/131705

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int A, B, C = 0;
    int sucess = 0;
    int cnt = 0;
    for (int n = 0; n < number.size() - 2;++n)
    {
        A = number[n];
        for (int j = n + 1; j < number.size() - 1;++j)
        {
            B = number[j];
            for (int i = n + 2; i < number.size();++i)
            {
                if (n < j && j < i)
                {
                    C = number[i];
                    if (0 == A + B + C)
                    {
                        answer++;
                    }
                }
            }
        }
    }
    return answer;
}
