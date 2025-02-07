//URL :https://school.programmers.co.kr/learn/courses/30/lessons/92334

#include <string>
#include <vector>
#include <map>
using namespace std;

struct IDInfo
{
    IDInfo(string _id)
    {
        id = _id;
    }
    string id;
    vector<string> secondArr;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    multimap<string, string> Map2;
    vector<IDInfo> idArr;

  string sameStr = "";
  string tempSecond = "";
  int strStarLen = 0;
  int strEndLen = 0;
  char chr = '0';
  vector<string> tempSameArr;
  bool checkSame = false;
  for (int j = 0; j < id_list.size();++j)
  {
      tempSameArr.clear();
      idArr.push_back(IDInfo(id_list[j]));
      strStarLen = id_list[j].length() +1;
      for (int i = 0; i < report.size();++i) //for (int i = report.size() - 1; i >=0 ;--i) //
      {
          checkSame = false;
          chr = report[i][strStarLen-1];
          if (0 == report[i].find(id_list[j]) && ' ' == chr)
          {
              strEndLen = report[i].length();
              tempSecond = report[i].substr(strStarLen, strEndLen);

              for (int n = 0;n < tempSameArr.size();++n)
              {
                  if (tempSameArr[n] == tempSecond)
                  {
                      checkSame = true;
                      break;
                  }
              }
              if (!checkSame)
              {
                  Map2.emplace(tempSecond, id_list[j]);
                  idArr[j].secondArr.push_back(tempSecond);
                  tempSameArr.push_back(tempSecond);
              }
          }
      }
  }
  string findStr = "";
  int findCnt = 0;
  int findTotalCnt = 0;
  for (int j = 0; j < idArr.size();++j)
  {
      findTotalCnt = 0;
      for (int i = 0; i < idArr[j].secondArr.size();++i)
      {
          findStr = idArr[j].secondArr[i];
          findCnt = Map2.count(findStr);
          if (k <= findCnt)
              findTotalCnt++;
      }
      answer.push_back(findTotalCnt);
  }

  return answer;
}