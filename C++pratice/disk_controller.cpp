#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {

        if (a.second != b.second) {
            return a.second > b.second;
        }

        return a.first > b.first;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    sort(jobs.begin(), jobs.end());

    int now = 0;
    int idx = 0;
    while (idx < jobs.size() || !pq.empty()) {
        //현재 시간보다 작거나 같은 작업 대기 큐에 추가
        //현재 작업 처리 시간으로 건너 뛰어도
        //이전 작업 관리 가능
        while (idx < jobs.size() && jobs[idx][0] <= now) {
            pq.push({ jobs[idx][0], jobs[idx][1] });
            idx++;
        }

        //우선순위가 가장 높은 다음 작업 수행 후
        //반환 시간 누적 합산
        if (!pq.empty()) {
            answer += (pq.top().second + now) - pq.top().first;
            //해당 작업 수행 후 시간으로 이동
            now += pq.top().second;
            pq.pop();
        }
        //다음 작업의 요청시간으로 건너뛰기
        else {
            now = jobs[idx][0];
        }
    }
    return answer / jobs.size();
}