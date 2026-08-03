#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int scov : scoville) {
        pq.push(scov);
    }

    while (pq.size() >= 2 && pq.top() < K) {
        int left = pq.top(); pq.pop();
        int right = pq.top(); pq.pop();
        pq.push(left + right * 2);
        answer++;
    }

    //top이 k보다 클때 나머지 스코빌 지수는 k이상 보장됨
    if (pq.top() < K) return -1;

    return answer;
}