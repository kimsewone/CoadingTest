#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    bool check = false;
    if (-50000 > num1) {
        num1 = -50000;
    }
    else if (50000 < num1)
    {
        num1 = 50000;
    }
    else if (-50000 > num2) {
        num2 = -50000;
    }
    else if (50000 < num2)
    {
        num2 = 50000;
    }

    int answer = num1 - num2;
    return answer;
}