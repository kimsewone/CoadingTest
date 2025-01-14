//URL :https://school.programmers.co.kr/learn/courses/30/lessons/131128

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int findIdx = 0;
    vector<char> V;
    char str = ' ';
    vector<char> V1;
    vector<char> V2;
    for (int i = 0; i < X.length();++i)
        V1.push_back(X[i]);
    sort(V1.rbegin(), V1.rend());
    for (int i = 0; i < Y.length();++i)
        V2.push_back(Y[i]);

    sort(V2.begin(), V2.end());
    for (int j = 0; j < V1.size();++j)
    {
        str = V1[j];
        for (int i = V2.size() - 1; i >= 0;--i)
        {
            if (str == V2[i])
            {
                V2.erase(V2.begin() + i);
                V.push_back(str);
                break;
            }
        }
    }

    if (0 == V.size())
    {
        answer = "-1";
    }
    else
    {
        sort(V.rbegin(), V.rend());
        if (V[0] == '0' && V[1] == '0')
            answer = "0";
        else
        {
            for (int i = 0; i < V.size();++i)
                answer += V[i];
        }
    }

    return answer;
}