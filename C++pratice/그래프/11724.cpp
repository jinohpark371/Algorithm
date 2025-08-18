#include <iostream>
#include <vector>
using namespace std;

bool visited[1000];
vector<vector<int>> adj(1001);
int n, m;
void dfs(int st) {
	visited[st] = true;

	for (auto& cursor : adj[st]) {
		
		if (!visited[cursor]) {
			dfs(cursor);

		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	int count = 0;
	for (int i = 1; i < n + 1; i++) {
		//dfs 진행 횟수가 연결 요소의 갯수
		//방문한 정점은 뛰어넘기 때문에 방문하지 않은 정점에 대해
		//dfs 수행시 연결요소 1증가
		if (!visited[i]) {
			dfs(i);
			count++;
		}
	}

	cout << count;
	return 0;
}