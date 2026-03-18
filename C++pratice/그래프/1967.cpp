#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> visited;

int maxDist = 0;
void DFS(int st, int dist) {
	maxDist = max(maxDist, dist);
	visited[st] = 1;
	for (auto [next, w] : adj[st]) {
		if (!visited[next]) {
			DFS(next, dist+w);
		}
	}
}

int main() {
	int n;
	cin >> n;
	adj.assign(n + 1, vector<pair<int, int>>(0));
	visited.assign(n + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	for (int i = 1; i < n + 1; i ++ ) {
		DFS(i, 0);
		visited.assign(n + 1, 0);
	}

	cout << maxDist;
	return 0;
}