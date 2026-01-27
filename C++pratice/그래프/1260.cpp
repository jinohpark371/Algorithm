#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj(1001);
int visited[1001] = { 0 };
queue<int> q;

void DFS(int st) {
	

	for (int v : adj[st]) {

		//미방문 정점
		if (!visited[v]) {
			//방문처리
			visited[v] = 1;
			cout << v << ' ';
			//해당 정점에서 탐색 시작
			DFS(v);
		}
	}
}

void BFS(int st) {

	//시작 정점 방문
	q.push(st);
	visited[st] = 1;
	cout << st << ' ';
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int w : adj[v]) {
			if (!visited[w]) {
				q.push(w);
				visited[w] = 1;
				cout << w << ' ';
			} 
		}

	}
}


int main() {
	int n, m, st;
	cin >> n >> m >> st;


	while (m--) {
		int v, w;
		cin >> v >> w;
		adj[v].push_back(w);
		adj[w].push_back(v);
	}


	//번호가 작은 정점부터 탐색을 위해 각 벡터 정렬
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	//시작 정점 방문
	visited[st] = 1;
	cout << st << " ";
	DFS(st);
	cout << "\n";

	//방문 처리 배열 초기화
	for (int i = 1; i < n + 1; i++) visited[i] = 0;

	BFS(st);

	return 0;
}