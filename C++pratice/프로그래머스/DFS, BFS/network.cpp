#include <string>
#include <vector>

using namespace std;
vector<int> visited(200, 0);

void DFS(vector<vector<int>>& computers, int st) {
    //방문
    visited[st] = 1;

    for (int i = 0; i < computers[st].size(); i++) {
        if (!visited[i] && computers[st][i] == 1) {
            DFS(computers, i);
        }
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            //DFS 진행횟수가 곧 네트워크 갯수
            DFS(computers, i);
            answer++;
        }
    }

    return answer;
}