//URL : https://school.programmers.co.kr/learn/courses/30/lessons/147355

#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long A = 0;
    long long B = stoll(p);
    long long BLength = p.length();
    int moveIdx = 0;

    while (true) {

        A = stoll(t.substr(moveIdx, p.length()));

        if (A <= B)
            answer++;

        moveIdx++;
        if (t.length() < moveIdx + p.length())
            break;
    }
    return answer;
}