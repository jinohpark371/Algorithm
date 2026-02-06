#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
int visited[101] = { 0 };
int dist[101] = { 0 };
queue<int> q;

int BFS(int st) {
	//시작정점방문
	visited[st] = 1;
	q.push(st);

	//최소 단계의 합
	int sum = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();

		for (int next : adj[v]) {
			if (!visited[next]) {
				//미방문 정점 방문
				visited[next] = 1;
				//부모 정점으로부터 최소단계(거리) 계산
				dist[next] = dist[v] + 1;
				q.push(next);//다음 탐색을 위한 큐에 삽입
				//최소 단계의 합 누적
				sum += dist[next];
			}
		}
	}

	return sum;
}

int main() {
	int n, m;
	cin >> n >> m;

	adj.assign(n+1, vector<int>(0));
	
	while (m--) {
		int v, w;
		cin >> v >> w;
		//친구관계 연결
		adj[v].push_back(w);
		adj[w].push_back(v);
	}
	//최소 케빈 베이컨 수를 가진 정점 번호
	int idx = -1;
	int mmin = 5001;
	for (int i = 1; i < n + 1; i++) {
		int sum = BFS(i);
		if (sum < mmin) {
			//최소 값을 가진 정점 수 갱신
			idx = i;
			//최소 케빈 베이컨 수의 합 갱신
			mmin = sum;
		}
		//방문여부 배열, 거리 배열 초기화
		for (int i = 1; i < n + 1; i++) {
			visited[i] = 0;
			dist[i] = 0;
		}
	}

	//해당 정점 번호 출력
	cout << idx;
	return 0;
}