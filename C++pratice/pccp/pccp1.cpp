#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> solution(vector<vector<int>> players) {
    int n = players.size();
    vector<int> answers;

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back({ players[i][1],i });
    }
    // 시간 기준 정렬 (작은게 더 빠름)
    //pair는 먼저 first 를 기준으로 
    // 비교 first가 같다면 second를 기준으로 비교
    sort(arr.begin(), arr.end());

    /*
   pair의 second에 원래 인덱스를 기억해 두는 게 핵심이었고,
   정렬 후 rank+1을 다시 actualRank[원래인덱스]에 집어넣는 방식으로
   위치는 그대로, 순위는 정렬된 결과를 반영
   */
    vector<int> actualRank(n);
    for (int rank = 0; rank < n; rank++) {
        int idx = arr[rank].second;
        //원래 위치(인덱스)에 현재 정렬된 idx순서+1(rank+1)한 순위값 저장
        actualRank[idx] = rank + 1;
    }

    for (int i = 0; i < n; i++) {
        //목표 순위가 실제 순위 보다 크다면 통과
        if (players[i][0] >= actualRank[i]) answers.push_back(1);
        else answers.push_back(0);
    }

    return answers;
}

int main() {
    vector<vector<int>> players = {
        {3, 12}, {1, 10}, {3, 15}, {3, 14}, {2, 11}
    }; // 1 1 0 0 1

    vector<int> ans = solution(players);
    for (int x : ans) cout << x << " ";
}