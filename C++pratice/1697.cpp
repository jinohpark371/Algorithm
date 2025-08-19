#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int st, en;
	cin  >> st >> en;

	vector<int> dist(100001, -1);
	dist[st] = 0;

	queue<int> q;
	q.push(st);

	while (!q.empty()) {
		int cursor = q.front(); q.pop();

		//원하는 정점이 나왔을때 그 정점까지의 최소시간
		if (cursor == en) {
			cout << dist[cursor];
			return 0;
		}

		//항상 정점에서 갈 수 있는 정점은 -1, +1, 2배 뿐임
		//그 정점까지의 최소시간은 자기까지 온 시간 +1
		//BFS는 레벨 단위로 퍼지므로 더 짧은 경로가 뒤 늦게 나올 수 없음
		for (int next : {cursor - 1, cursor + 1, cursor * 2}) {
			if (next < 0 || next >100000) continue;
			if (dist[next] != -1) continue;

			dist[next] = dist[cursor] + 1;
			q.push(next);
		}
	}

	return 0;
}