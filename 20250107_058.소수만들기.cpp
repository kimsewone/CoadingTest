//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12977

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {

    int answer = 0;
    int temp = 0;
    bool check = false;
    for (int n = 0; n < nums.size() - 2;++n)
    {
        for (int j = n + 1; j < nums.size() - 1;++j)
        {
            for (int i = j + 1; i < nums.size();++i)
            {
                check = false;
                temp = nums[n] + nums[j] + nums[i];
                if (temp % 2 == 0)
                {
                    continue;
                }
                if (temp % 3 == 0)
                {
                    if (temp == 3)
                        answer++;
                    continue;
                }
                if (temp % 5 == 0)
                {
                    if (temp == 5)
                        answer++;
                    continue;
                }
                if (temp % 7 == 0)
                {
                    if (temp == 7)
                        answer++;
                    continue;
                }

                for (int m = 11; m <= temp / 2; m += 2)
                {
                    check = false;
                    // ���� �������ٸ� ����� �ش��ϹǷ� �Ҽ��� �ƴ�.
                    if (temp % m == 0)
                    {
                        if (temp != m)
                            check = true;
                        break;
                    }
                }

                if (!check)
                    answer++;
            }
        }
    }


    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "answer : " << answer << endl;

    return answer;
}