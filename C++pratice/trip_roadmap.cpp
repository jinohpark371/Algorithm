#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> answer;
vector<vector<string>> copyed;
vector<int> visited;
int ssize = 0;
bool DFS(string arrive, int depth) {
    answer.push_back(arrive);
    if (depth == ssize) return true;


    for (int i = 0; i < ssize; i++) {
        if (copyed[i][0] == arrive && !visited[i]) {
            visited[i] = 1;
            if (DFS(copyed[i][1], depth + 1)) return true;
            visited[i] = 0;
            answer.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    copyed = tickets;
    ssize = tickets.size();
    visited.assign(ssize, 0);
    sort(copyed.begin(), copyed.end());

    DFS("ICN", 0);


    return answer;
}