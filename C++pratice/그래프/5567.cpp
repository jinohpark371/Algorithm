#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dist[501];
queue<int> q;
int n, m;

int main() {
	cin >> n;
	cin >> m;
	vector<vector<int>> adj(n+1);

	for (int i = 1; i <= m; i++) {
		int u, v; //친구 두명
		cin >> u >> v;
		adj[u].push_back(v); //각 친구들의 연결 1로 표시
		adj[v].push_back(u);
	}

	q.push(1); //시작 정점부터 탐색
	fill(dist, dist + n + 1, -1); //모든 정점 아직 방문 못한걸로 초기화
	dist[1] = 0;
	while (!q.empty()) {
		int u=q.front(); 
		q.pop();

		if (dist[u] < 2) { //친구의 친구까지만 탐색 진행
			for (int v : adj[u]) {
				if (dist[v] ==-1) { //아직 방문하지 않은 정점이라면
					dist[v] = dist[u] + 1; //현재 정점의 최단거리+1로 시작 정점에서 해당 정점까지의 거리 갱신
					q.push(v);
				}
			}
		}
	}

	int cnt = 0; //친구의 친구까지의 수
	//최단거리가 2이하인 정점까지만 세고 최단거리가 0이 아니면 친구의 친구까지만 셀수 있음
	for (int i = 2; i <= n; i++) {
		if (dist[i] !=-1 && dist[i] <= 2) {
			cnt++; 
		}
	}

	cout << cnt;
	return 0;
}