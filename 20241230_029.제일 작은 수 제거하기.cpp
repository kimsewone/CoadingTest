//URL : https://school.programmers.co.kr/learn/courses/30/lessons/12935

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> tempArr;


    int smallValue = 0;

    if (1 < arr.size())
    {
        for (int num : arr)
            tempArr.push_back(num);

        sort(tempArr.begin(), tempArr.end());
        smallValue = tempArr[0];

        int CurIdx = 0;
        for (int num : arr)
        {
            if (num == smallValue)
                arr.erase(arr.begin() + CurIdx);
            CurIdx++;
        }
    }
    else
        arr[0] = -1;

    return arr;
}