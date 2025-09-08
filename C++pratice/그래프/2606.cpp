#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj(101);
bool visited[101];

int dfs(int st) {
	visited[st] = true;
	int area = 1;

	for (int v : adj[st]) {
		if (!visited[v]) { //아직 방문 되지 않은 정점에 대해서 방문
			area += dfs(v);
		}
	}

	return area;
}


int main() {
	int n, m;
	cin >> n;
	cin >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int cnt = dfs(1);

	cout << cnt-1;
	return 0;
}