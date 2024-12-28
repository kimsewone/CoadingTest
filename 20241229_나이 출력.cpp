#include <string>
#include <vector>

using namespace std;

int solution(int age) {

    int answer = 0;

    if (0 > age)
        age = 0;
    else if (120 < age)
        age = 120;


    answer = 2023 - age;


    return answer;
}