#include <string>
#include <vector>

using namespace std;
vector<int> visited;
vector<vector<int>> copied;
int ssize;

int DFS(int node, int skip) {
    visited[node] = 1;
    int area = 1;
    for (int i = 0; i < ssize; i++) {
        //해당 간선 제거
        if (i == skip) continue;
        if (!visited[copied[i][1]] && copied[i][0] == node) {
            area += DFS(copied[i][1], skip);
        }
        //양방향 확인
        if (!visited[copied[i][0]] && copied[i][1] == node) {
            area += DFS(copied[i][0], skip);
        }
    }
    return area;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    copied = wires;
    ssize = wires.size();
    for (int skip = 0; skip < wires.size(); skip++) {
        visited.assign(n + 1, 0);
        int cnt = DFS(1, skip);
        answer = min(answer, abs(cnt - (n - cnt)));
    }
    return answer;
}