#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int m, n, k;
vector<vector<int>>adj;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int area = 0;


void DFS(int sx, int sy) {
	adj[sx][sy] = -1;
	area++;
	for (int dir = 0; dir < 4; dir++) {
		int nx = sx + dx[dir];
		int ny = sy + dy[dir];

		if (nx <0 || nx >=m || ny <0 || ny >=n) continue;

		if (adj[nx][ny] == 1) continue;

		if (adj[nx][ny] == 0) {
			adj[nx][ny] = -1;
			DFS(nx, ny);
		}
	}
}

int main() {
	cin >> m >> n >> k;
	adj.assign(m , vector<int>(n , 0));
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1;
		cin >> x2 >> y2;

		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				adj[i][j] = 1;
			}
		}
	}

	int cnt = 0;
	vector<int> answer;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (adj[i][j] == 0) {
				DFS(i, j);
				cnt++;
				answer.push_back(area);
				area = 0;
			}
		}
	}

	cout << cnt << '\n';
	sort(answer.begin(), answer.end());
	for (int i = 0; i < cnt; i++) {
		cout << answer[i] << ' ';
	}
	return 0;
}