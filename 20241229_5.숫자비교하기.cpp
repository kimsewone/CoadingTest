#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;

    if (0 > num1)
        num1 = 0;
    else  if (10000 < num1)
        num1 = 10000;
    else if (0 > num2)
        num2 = 0;
    else  if (10000 < num2)
        num2 = 10000;



    return answer = num1 == num2 ? 1 : -1;
}