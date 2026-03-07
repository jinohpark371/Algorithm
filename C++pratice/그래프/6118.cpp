#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> dist;
queue<int> q;

int BFS(int st) {
	dist[st] = 1;
	q.push(st);

	int maxDist = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();

		for (int next : adj[v]) {
			if (!dist[next]) {
				dist[next] = dist[v] + 1;
				maxDist = max(maxDist, dist[next]);
				q.push(next);
			}
		}
	}

	return maxDist;
}

int main() {
	cin >> n >> m;
	adj.assign(n+1, vector<int>(0));
	dist.assign(n + 1, 0);

	while (m--) {
		int v, w;
		cin >> v >> w;
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	int maxDist=0;
	//1번 헛간부터 다른 헛간까지 거리 계산 후 최대 거리 계산
	maxDist=BFS(1);

	int cnt=0;
	int idx = -1;
	for (int i = 0; i < dist.size(); i++) {
		//1번헛간에서 가장 멀고 가장 작은 헛간번호 찾기
		if (idx == -1 && dist[i] == maxDist) idx = i;
		//최대 거리와 같은 헛간 카운트
		if (dist[i] == maxDist) cnt++;
	}

	cout << idx << " " << maxDist - 1 << " " << cnt;
	return 0;
}