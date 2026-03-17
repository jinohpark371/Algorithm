#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for (int i = 0; i < progresses.size(); i++) {
        int days = 0; //100%가 될때까지 걸리는 기간
        for (int j = progresses[i]; j < 100; j = j + speeds[i]) days++;
        q.push(days);
    }

    while (!q.empty()) {
        int cnt = 1;
        int cur = q.front(); q.pop();

        //현재 앞 기능이 개발 기간이 기준이 되며 
        //이후 기능이 현재 기능보다 개발기간이 같거나 작다면 카운트하며 pop;
        //이후 기능 개발기간이 더 길다면 현재 배포엔 해당 기능만 배포
        while (!q.empty() && cur >= q.front()) {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    return answer;
}