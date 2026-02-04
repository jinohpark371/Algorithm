#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;;
int visited[51] = { 0 };
int dist[51] = { 0 };
queue<int> q;

int BFS(int start) {
	//시작 정점 방문
	visited[start] = 1;
	q.push(start);

	int score = 0;;
	while (!q.empty()) {
		int v = q.front(); q.pop();

		for (int next : adj[v]) {
			if (!visited[next]) {
				visited[next] = 1;
				dist[next] = dist[v] + 1;
				//최대 점수 계산
				score = max(score, dist[next]);
				q.push(next);
			}
		}
	}

	return score;
}


int main() {
	int n;
	cin >> n;
	adj.assign(n + 1, vector<int>(0));

	while (true) {
		int v, w;
		cin >> v >> w;
		if (v == -1 && w == -1) break;

		//간선 연결
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	//후보 점수, 후보 번호
	vector<pair<int, int>> answer;
	for (int i = 1; i < n + 1; i++) {
		int score = BFS(i);
		answer.push_back({ score, i });
		//거리 배열, 방문 여부 배열 초기화
		for (int i = 1; i < n + 1; i++) {
			dist[i] = 0;
			visited[i] = 0;
		}
	}

	sort(answer.begin(), answer.end());

	//최소 점수
	int minScore = answer[0].first;

	//최소 점수 후보 세기
	int count = 0;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i].first == minScore) count++;
	}

	//최소 점수, 최소 점수 후보 갯수 출력
	cout << minScore << ' ' << count << '\n';

	//후보 출력
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i].first == minScore) {
			cout << answer[i].second << " ";
		}
		else break;
	}

	return 0;
}