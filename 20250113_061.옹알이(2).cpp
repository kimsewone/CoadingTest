//URL :https://school.programmers.co.kr/learn/courses/30/lessons/133499

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> words = { "aya", "ye", "woo", "ma" };
    int findIdx = -2;
    string str = "";
    int tempfindCnt = 0;
    int wordIdx = -1;
    bool isBreak = false;
    int tempFirstPosIdxCnt = -1;
    for (int j = 0; j < babbling.size();++j)
    {
        tempfindCnt = 0;
        isBreak = false;
        wordIdx = -1;
        while (true)
        {
            wordIdx = -1;
            tempFirstPosIdxCnt = 0;
            for (int i = 0; i < words.size();++i)
            {
                if (babbling[j] == words[i])
                {
                    if (wordIdx == i)
                    {
                        tempfindCnt = 0;
                        isBreak = true;
                        break;
                    }
                    tempfindCnt++;
                    isBreak = true;
                    break;
                }

                if (babbling[j].length() < 2)
                {
                    isBreak = true;
                    tempfindCnt = 0;
                    break;
                }

                findIdx = babbling[j].find(words[i]);

                if (findIdx == 0)
                {
                    if (wordIdx == i)
                    {
                        tempfindCnt = 0;
                        isBreak = true;
                        break;
                    }
                    babbling[j].erase(findIdx, words[i].length());
                    tempfindCnt++;
                    wordIdx = i;
                    tempFirstPosIdxCnt ++;
                    --i;
                }
                else
                    wordIdx = -1;

            }
            if (isBreak || tempfindCnt == 0)
                break;
            else if (0 == tempFirstPosIdxCnt)
            {
                tempfindCnt = 0;
                break;
            }
            else if (babbling[j].length() == 2)
            {
                if (babbling[j] != words[1] && babbling[j] != words[3])
                {
                    tempfindCnt = 0;
                    break;
                }
            }
            else  if (babbling[j].length() == 3)
            {
                if (babbling[j] != words[0] && babbling[j] != words[2])
                {
                    tempfindCnt = 0;
                    break;
                }
            }
            else if (babbling[j].length() > 3)
            {
                int tempFirstPosIdxCnt = -1;
                for (int i = 0; i < words.size();++i) {
                    if (0 == babbling[j].find(words[i]))
                    {
                        tempFirstPosIdxCnt++;
                    }
                }
                if (tempFirstPosIdxCnt == -1)
                {
                    tempfindCnt = 0;
                    break;
                }
            }
        }
        tempfindCnt = tempfindCnt > 0 ? 1 : 0;
        answer += tempfindCnt;
    }
    return answer;
}