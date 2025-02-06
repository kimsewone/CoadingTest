//URL :https://school.programmers.co.kr/learn/courses/30/lessons/172928

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
     int W = park[0].length();
   int posW = -1;
   int posH = -1;
   for (int j = 0; j < park.size();++j)
   {
       posH = j;
       posW = park[j].find("S");
       if (posW != string::npos)
           break;
   }
   int moveW = 0;
   int moveH = 0;
   bool checkSucess = false;
       for (int i = 0; i < routes.size();++i)
       {
           char dir = routes[i][0];
           int movePos = routes[i][2] - '0';
           moveW = 0;
           moveH = 0;
           if (dir == 'E')
               moveW = movePos;
           else if (dir == 'W')
               moveW = -movePos;
           else if (dir == 'N')
               moveH = -movePos;
           else if (dir == 'S')
               moveH = movePos;

           int fixH = moveH < 0 ? -1 : 1;
           int fixW = moveW < 0 ? -1 : 1;

           if (posH + moveH >= park.size() || posH + (moveH* fixH)< 0 )
               continue;
           if (posW + moveW >= park[0].length() || posW + (moveW * fixW) < 0)
               continue;
           checkSucess = true;
      
           for (int H = 0; H < abs(moveH)+1;++H)
           {
               for (int W = 0; W < abs(moveW)+1;++W)
               {
                   if ('X' == park[posH + (H* fixH)][posW + (W* fixW)])
                   {
                       checkSucess = false;
                       break;
                   }
               }
               if (!checkSucess)
                   break;
           }
           if (checkSucess)
           {
               posW += moveW;
               posH += moveH;
           }
       }
   answer.push_back(posH);
   answer.push_back(posW);
   return answer;
}