#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) q.push({ priorities[i], i });

    int order = 1;
    while (!q.empty()) {
        auto [prior, idx] = q.front(); q.pop();

        bool hasHigher = false;
        queue<pair<int, int>> temp = q;
        while (!temp.empty()) {
            if (temp.front().first > prior) {
                hasHigher = true;
                break;
            }
            else temp.pop();
        }

        if (hasHigher) {
            q.push({ prior, idx });
        }
        else {
            if (idx == location) {
                answer = order;
            }
            order++;
        }

    }
    return answer;
}