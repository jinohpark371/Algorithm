#include <string>
#include <vector>

using namespace std;
vector<vector<int>> copys;
vector<int> visited;
int answer = -1;
int ssize;
void DFS(int k, int depth) {
    answer = max(answer, depth);

    for (int i = 0; i < ssize; i++) {
        if (!visited[i] && k >= copys[i][0]) {
            visited[i] = 1;
            DFS(k - copys[i][1], depth + 1);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    copys = dungeons;
    ssize = dungeons.size();
    visited.assign(ssize, 0);
    DFS(k, 0);
    return answer;
}