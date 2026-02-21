#include <iostream>
#include <queue>
using namespace std;

int i;
int board[300][300] = { 0 };
queue<pair<int, int>> q;
//방향 배열
int dx[] = { -1, -2, -2, -1,1, 2, 2,1 };
int dy[] = { -2, -1, 1, 2, 2,1, -1, -2 };

void BFS(int sx, int sy) {
	q.push({ sx, sy });
	board[sx][sy] = 1;

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			//경계 검사
			if (nx < 0 || nx >= i || ny < 0 || ny >= i) continue;

			//미방문 좌표 최단거리 계산
			if (!board[nx][ny]) {
				board[nx][ny] = board[x][y] + 1;
				q.push({ nx, ny });
			} 
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> i;
		int sx, sy;
		cin >> sx >> sy;


		int ex, ey;
		cin >> ex >> ey;
		
		BFS(sx, sy);
		cout << board[ex][ey] -1 << '\n';
		
		//배열 초기화
		for (int x = 0; x < i; x++) {
			for (int y = 0; y < i; y++)
				board[x][y] = 0;
		}
	}
}