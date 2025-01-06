//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12915

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool campare(const string& A, const string& B, int n)
{
    if (A[n] < B[n])
        return true;
    else  if (A[n] > B[n])
        return false;
    else if (A[n] == B[n])
    {
        string C = A.length() > B.length() ? B : A;

        for (int i = 0; i < C.length();++i)
        {
            if (A[i] < B[i])
                return true;
            else if (A[i] > B[i])
                return false;
        }

        if (A.length() < B.length())
            return true;
        else if (A.length() > B.length())
            return false;
        else if (A.length() == B.length())
        {
            return false;
        }
    }
    else
        return false;
}
vector<string> solution(vector<string> strings, int n) {

    vector<string> answer;
 
    for (int i = 0; i < strings.size();++i)
        answer.push_back(strings[i]);

    sort(answer.begin(), answer.end(), [n](const string& A, const string& B) {
        return campare(A, B, n);
     });

    return answer;
}