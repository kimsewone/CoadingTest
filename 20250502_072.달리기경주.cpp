//URL :https://school.programmers.co.kr/learn/courses/30/lessons/178871

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> nameToIndex; 

    // 초기 선수 위치 
    for (int i = 0; i < players.size(); i++) {
        nameToIndex[players[i]] = i;
    }

    for (int i = 0; i < callings.size(); i++) {
        string called = callings[i];
        int idx = nameToIndex[called]; 

        if (idx == 0) continue; 

        // swap players[idx] <-> players[idx - 1]
        string frontPlayer = players[idx - 1];
        players[idx - 1] = players[idx];
        players[idx] = frontPlayer;

       
        nameToIndex[called] = idx - 1;
        nameToIndex[frontPlayer] = idx;
    }

    return players;
}