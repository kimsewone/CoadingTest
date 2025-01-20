//URL :https://github.com/kimsewone/CoadingTest

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int idx = 0;
    int tempIdx1 = 10000;
    int tempIdx2 = 0;
    bool checkChange = false;
    for (int m = 0; m < targets.size();++m)
    {
        idx = 0;
        for (int j = 0; j < targets[m].length();++j)
        {
            checkChange = false;
            tempIdx1 = 1000;
            tempIdx2 = -1;
            for (int i = 0; i < keymap.size();++i)
            {
                tempIdx2 = keymap[i].find(targets[m][j]);
                if (-1 < tempIdx2 && tempIdx1 > tempIdx2)
                {
                    tempIdx1 = tempIdx2;
                    checkChange = true;
                }
            }
            if (checkChange)
                idx += tempIdx1+1;
            else
            {
                idx = -1;
                break;
            }
        }
        if (idx == 0)
            idx = -1;
        answer.push_back(idx);
    }
    return answer;
}