#include <string>
#include <vector>

using namespace std;

char vobel[5] = { 'A', 'E', 'I', 'O', 'U' };
string copied = "";
string cur = "";

int answer = 0;
int cnt = 0;

bool found = false;

void DFS(int depth) {
    if (found) return;
    if (depth > 5) return;
    if (cur != "") {
        cnt++;
        if (cur == copied) {
            answer = cnt;
            found = true;
        }
    }

    for (int i = 0; i < 5; i++) {
        cur += vobel[i];
        DFS(depth + 1);
        cur.pop_back();
    }

}

int solution(string word) {
    copied = word;
    DFS(0);
    return answer;
}