#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> hackingCnt;
queue<int> q;
int n, m;

int BFS(int st) {;
	visited[st] = 1;
	q.push(st);

	int cnt = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();

		for (int next : adj[v]) {
			if (!visited[next]) {
				cnt++;
				visited[next] = 1;
				q.push(next);
			}
		}
	}

	return cnt;
}

int main() {
	cin >> n >> m;
	adj.assign(n+1, vector<int>(0));
	visited.assign(n + 1, 0);
	hackingCnt.assign(n + 1, 0);
	while (m--) {
		int v, w;
		cin >> v >> w;
		//해킹 가능한 방향은 신뢰관계의 반대 방향
		adj[w].push_back(v);
	}

	int mmax = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = BFS(i);
		mmax = max(mmax, cnt);
		//각 컴퓨터별 해킹 가능 컴터 수 저장
		hackingCnt[i] = cnt;
		//방문처리 배열 초기화
		for (int j = 1; j <= n; j++) visited[j] = 0;
	}

	for (int i = 1; i <= n; i++) {
		if (mmax == hackingCnt[i]) {
			cout << i << " ";
		}
	}

	return 0;
}