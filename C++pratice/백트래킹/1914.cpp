#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> adj(5, vector<char>(5, 0));
vector<int> selected(25, 0);
vector<int> visited(25, 0);
int dx[4] = { -1, 1 ,0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cnt = 0;

void DFS(int idx, int depth, int sCnt) {
	if (depth == 7 && sCnt >= 4) {
		int start = 0;
		for (int i = 0; i < 25; i++) {
			if (selected[i]) {
				start = i;
				break;
			}
		}

		queue<int> q;
		q.push(start);
		visited[start] = 1;

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			//2차원 인덱스로 변환
			int x = cur / 5;
			int y = cur % 5;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;

				//1차원 idx로 변환
				int next = nx * 5+ny;
				//탐색에서 선택된 자리가 아니라면 제외
				if (!selected[next]) continue;

				if (!visited[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}
		}

		//선택되어 있고 상하좌우 방향으로 인접해있는 칸의 갯수 계산
		int adCnt = 0;
		for (int i = 0; i < 25; i++) {
			if (visited[i])adCnt++;
		}

		if (adCnt == 7) cnt++;

		for (int i = 0; i < 25; i++) visited[i] = 0;
		return;
	}

	//모든 자리 조합 만들기
	for (int i = idx; i < 25; i++) {
		selected[i] = 1;
		if (adj[i / 5][i % 5] == 'S')DFS(i + 1, depth + 1, sCnt + 1);
		else DFS(i + 1, depth + 1, sCnt);
		selected[i] = 0;
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		string s; cin >> s;
		for (int j = 0; j < 5; j++) {
			adj[i][j] = s[j];
		}
	}

	DFS(0, 0, 0);
	cout << cnt;
	return 0;
}