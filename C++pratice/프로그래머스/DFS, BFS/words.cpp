#include <string>
#include <vector>
#include <set>

using namespace std;

int cnt = 100;
int n;
set<string> st;
vector<string> copyWords;

void DFS(string begin, string target, int depth) {
    //기존 최소 단계 보다 클땐 탐색 더이상 하지 않아도 됨
    if (depth >= cnt) return;

    if (begin == target) {
        cnt = min(cnt, depth);
        return;
    }

    for (int i = 0; i < n; i++) {
        int diffCnt = 0;
        for (int j = 0; j < begin.length(); j++) {
            if (begin[j] != copyWords[i][j]) diffCnt++;
        }

        if (!st.count(copyWords[i]) && diffCnt == 1) {
            st.insert(copyWords[i]);
            DFS(copyWords[i], target, depth + 1);
            st.erase(copyWords[i]);
        }
    }

}

int solution(string begin, string target, vector<string> words) {
    copyWords = words;
    n = words.size();

    bool exist = false;
    for (string w : words) {
        if (w == target) exist = true;
    }
    if (!exist) return 0;

    DFS(begin, target, 0);

    return cnt;
}