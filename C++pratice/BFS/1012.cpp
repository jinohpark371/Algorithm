#include <iostream>
using namespace std;

int dx[4] = { 0, 0, -1 ,1 };
int dy[4] = { -1, 1, 0 ,0 };
int board[50][50];
bool visited[50][50];

int t, m, n, k;

void bfs(int x, int y) {
	visited[x][y] = true;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;


		if (!visited[nx][ny] && board[nx][ny]==1) {
			visited[nx][ny] = true;
			bfs(nx, ny);
		}
	}

}

void init() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

int main() {
	

	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		while (k--) {
			//문제에서 첫번째 좌표는 가로 좌표(열)은 x좌표
			//문제에서 첫번째 좌표는 세로 좌표(행)은 y좌표
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n;i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && board[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		init();
	}
}