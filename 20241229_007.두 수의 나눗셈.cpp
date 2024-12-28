#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;

    if (0 > num1)
        num1 = 0;
    else  if (100 < num1)
        num1 = 100;
    else if (0 > num2)
        num2 = 0;
    else  if (100 < num2)
        num2 = 100;

    return answer = (int)(((float)num1 / (float)num2) * 1000.f);
}