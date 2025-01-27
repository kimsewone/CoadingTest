//URL :https://school.programmers.co.kr/learn/courses/30/lessons/150370

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> todayArr; 
    int temp = 0;
    temp = stoi(today.substr(0, 4));
    todayArr.push_back(temp);
    temp = stoi(today.substr(5,7));
    todayArr.push_back(temp);
    temp = stoi(today.substr(8, 10));
    todayArr.push_back(temp);

    map<string, int> termsMap;
    for (int i = 0; i < terms.size();++i) 
    {
        string key = "";
        key +=terms[i][0];

        int second = stoi( terms[i].substr(2, terms[i].length()) );
        termsMap.insert({ key , second  });
    }

    int tepmtodayArr1;
    vector<int> tempArr(3, 0);
    for (int i = 0; i < privacies.size();++i)
    {
        tempArr[0 ]= 0;
        tempArr[1] = 0;
        tempArr[2] = 0;
        string key = privacies[i].substr(11, privacies[i].length());

        int secondValue = termsMap.find(key)->second;
        tempArr[0] = todayArr[0] - stoi( privacies[i].substr(0, 4) );
        if (0 < tempArr[0])
            tepmtodayArr1 = todayArr[1] + tempArr[0] * 12;
        else
            tepmtodayArr1 = todayArr[1];
        int tempB = stoi(privacies[i].substr(5, 7));
        tempArr[1] = tepmtodayArr1 - ( tempB + secondValue);
        if (0 < tempArr[1]  )
        {
            answer.push_back(i+1);
        }
        else if (0 == tempArr[1])
        {
            int temp = todayArr[2] - stoi(privacies[i].substr(8, 10));
            if (0 <= temp)
            {
                answer.push_back(i+1);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}