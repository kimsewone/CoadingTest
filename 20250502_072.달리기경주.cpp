//URL :https://school.programmers.co.kr/learn/courses/30/lessons/178871

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> nameToIndex; // 선수 이름 → 현재 등수

    // 초기 선수 위치 매핑
    for (int i = 0; i < players.size(); i++) {
        nameToIndex[players[i]] = i;
    }

    for (int i = 0; i < callings.size(); i++) {
        string called = callings[i];
        int idx = nameToIndex[called]; // 불린 선수의 현재 인덱스

        if (idx == 0) continue; // 이미 1등이면 skip (문제에선 안불리지만 안전장치)

        // swap players[idx] <-> players[idx - 1]
        string frontPlayer = players[idx - 1];
        players[idx - 1] = players[idx];
        players[idx] = frontPlayer;

        // map에 인덱스 업데이트
        nameToIndex[called] = idx - 1;
        nameToIndex[frontPlayer] = idx;
    }

    return players;
}