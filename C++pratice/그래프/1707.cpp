#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int v, e;
vector<vector<int>> adj;
vector<int> color; // 0:미방문 , 1: 집합 A, -1: 집합 B

bool BFS(int st) {
	queue<int> q;
	q.push(st);
	color[st] = 1; //시작 정점은 집합 A로 고정

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int next : adj[cur]) {
			if (color[next] == 0) {
				//인접 정점은 반대편 집합으로 지정
				color[next] = -color[cur];
				q.push(next);
			}
			//이미 방문한 인접 정점일때 본인과 같은 집합이 속할땐 false
			else if (color[cur] == color[next]) {
				return false;
			}
		}
	}


	return true;
}

int main() {
	int k;
	cin >> k;
	while (k--) {
		cin >> v >> e;
		adj.assign(v + 1, vector<int>(0));
		color.assign(v + 1, 0);

		for (int i = 0; i < e; i++) {
			int u, w;
			cin >> u >> w;
			adj[u].push_back(w);
			adj[w].push_back(u);
		}

		bool isValid = true;
		for (int i = 1; i <= v; i++) {
			//연결되지 않는 그래프 처리
			if (color[i] == 0) {
				if (!BFS(i)) {
					isValid = false;
					break;
				}
			}
			
		}

		if (isValid) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;

}
