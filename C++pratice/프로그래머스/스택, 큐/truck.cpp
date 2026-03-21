#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    for (int i = 0; i < bridge_length; i++) q.push(0);

    int t = 0;
    int idx = 0;
    int curWeight = 0;
    while (idx < truck_weights.size()) {
        //시간증가
        t++;
        //다리 맨 앞쪽 트럭이 나가면서 해당 무게를 뺴줌
        curWeight -= q.front(); q.pop();
        //다음 트럭 무게를 더 했을때 최대 무게 비교
        if (curWeight + truck_weights[idx] <= weight) {
            curWeight += truck_weights[idx];
            q.push(truck_weights[idx]);
            idx++;
        }
        //안된다면 다리 위 무게 유지를 위해 0추가
        else {
            q.push(0);
        }
    }

    //마지막 트럭처리후 다리길이 만큼 시간 추가 소요
    return t + bridge_length;
}