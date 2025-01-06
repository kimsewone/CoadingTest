//URL : https://school.programmers.co.kr/learn/courses/30/lessons/68644

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int, int> tempMap;
    sort(numbers.begin(), numbers.end());
    int tempV = 0;
    for (int j = 0; j < numbers.size();++j)
    {
        for (int i = 1 + j; i < numbers.size();++i)
        {
            tempV = numbers[j] + numbers[i];
            tempMap.insert(make_pair(tempV, tempV));
        }
    }
    for (pair<int, int> item : tempMap)
    {
        answer.push_back(item.first);
    }

    return answer;
}