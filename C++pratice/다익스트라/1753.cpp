#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;

int main() {
	int v, e, st;
	cin >> v >> e;
	cin >> st;

	//인접 리스트
	vector< vector<pair<int, int>>> adj(v + 1);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	vector<int> dist(v + 1, INF);

	//최단거리 배열 초기화
	for (int i = 1; i < v + 1; i++) {
		dist[i] = INF;
	}
	dist[st] = 0;

	pq.push({ 0, st });
	while (!pq.empty()) {
		
		//현재 시작정점으로 부터 가장 적은 가중치를 가지는 정점을 선택
		//해당 노드는 현재 알고 있는 거리에서 가장 작은 값을 가지는 정점이므로
		//다른 미확정 경로의 합보다 항상 작으므로 최단거리로 확정
		auto [curDist, u] = pq.top(); pq.pop();
		//최단 경로를 가지는 정점의 인접한 정점까지의 거리가
		//현재 시작점으로 부터 알고 있는 거리보다 작일때만  최단거리 갱신
		for (auto& [v, w] : adj[u]) {
			if (dist[v] > curDist + w) {
				dist[v] = curDist + w;
				//다음 탐색을 위해 우선순위  큐에 push
				pq.push({ dist[v], v });
			}
		}
	}

	for (int i = 1; i < v + 1; i++) {
		if (dist[i] != INF) {
			cout << dist[i] << '\n';
		}
		else {
			cout << "INF" << '\n';
		}
	}

	return 0;
}