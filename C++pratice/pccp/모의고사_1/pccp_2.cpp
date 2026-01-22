#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int answer = 0;
vector<vector<int>> ability;
vector<int> used;

void DFS(int L, int sum) {
    
    if (L == M) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            used[i] = 1;
            DFS(L + 1, sum + ability[i][L]);
            used[i] = 0;
        }
    }
}

int solution(vector<vector<int>> ability_input) {
    ability = ability_input;
    N = ability_input.size();
    M = ability_input[0].size();

    used.assign(N, 0);

    DFS(0, 0);

    return answer;
}
