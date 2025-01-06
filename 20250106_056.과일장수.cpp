//URL : https://school.programmers.co.kr/learn/courses/30/lessons/135808

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> V1;
    sort(score.rbegin(), score.rend());
    //3.3.2.2.1.1.1
    int cnt = 0;
    int value = 0;

    while (true) {
        for (int i = 0; i < m;++i)
        {
            value = score[cnt];
            V1.push_back(value);
            cnt++;
            if (cnt >= score.size())
                break;
        }
        if (m == V1.size())
        {
            sort(V1.begin(), V1.end());
            answer += V1[0] * m;
            V1.clear();
        }
        if (cnt >= score.size())
            break;
    }
    return answer;
}