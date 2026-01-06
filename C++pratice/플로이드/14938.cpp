#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int>items(101);
vector<vector<pair<int, int>>> adj(101);

const int INF = 1e9;

int dijkstra(int start) {
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;


	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		auto [cost, cur] = pq.top();
		pq.pop();

		for (auto [next, len] : adj[cur]) {
			int nextcost = cost + len;
			if (nextcost < dist[next]) {
				dist[next] = nextcost;
				pq.push({ nextcost, next });
			}
		}
	}

	//한 정점에서 다른 정점까지의 최단 거리를 수색범위와 비교해서 최대 아이템 갯수 구하기
	int sum = 0;
	for (int i = 1; i < n + 1; i++) {
		if (dist[i] <= m) {
			sum += items[i];
		}
	}

	return sum;
}

int main() {
	cin >> n >> m >> r;

	for (int i = 1; i < n + 1; i++) {
		cin >> items[i];
	}


	for (int i = 0; i < r; i++) {
		int u, v, len;
		cin >> u >> v >> len;

		adj[u].push_back({ v, len });
		adj[v].push_back({ u, len });

	}

	//각 정점에서 최대 아이템의 갯수를 구해서 최대 아이템 갯수 계산
	int ans = 0;
	for (int i = 1; i < n + 1; i++)
		ans = max(ans, dijkstra(i));


	cout << ans;
	return 0;
}