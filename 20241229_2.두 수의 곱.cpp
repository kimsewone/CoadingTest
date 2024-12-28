#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {

    if (0 >= num1)
        num1 = 0;
    else if (100 < num1)
        num1 = 100;
    if (0 >= num2)
        num2 = 0;
    else if (100 < num2)
        num2 = 100;
    int answer = num1 * num2;
    return answer;
}