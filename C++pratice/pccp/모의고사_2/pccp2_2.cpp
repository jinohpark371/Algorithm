#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> ability, int number) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    //우선순위 큐에 원소 모두 넣기
    for (int i = 0; i < ability.size(); i++) pq.push(ability[i]);

    while (number--) {
        //첫번째 작은 수
        int a = pq.top(); pq.pop();
        //두번째 작은 수
        int b = pq.top(); pq.pop();

        int sum = a + b;
        pq.push(sum);
        pq.push(sum);
    }

    //우선순위 큐에서 모드에서 모두 꺼내기기
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    return answer;
}