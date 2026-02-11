#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<vector<vector<int>>>board;
queue<tuple<int, int, int>> q;

int M, N, H;

//앞, 뒤, 좌, 우, 위, 아래
int dx[] = {1, -1, 0 ,0, 0, 0};
int dy[] = {0 , 0, -1, 1, 0, 0,};
int dz[] = {0, 0, 0, 0, 1, -1};

void BFS() {

	while (!q.empty()) {
		auto [z, x, y] = q.front(); q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nz = z + dz[dir];
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			
			//경계 체크
			if (nz < 0 || nz >= H) continue;
			if (nx < 0 || nx >= N) continue;
			if (ny < 0 || ny >= M) continue;

			//비어있는 칸은 탐색 X
			if (board[nz][nx][ny] == -1)continue;

			//해당 방향으로 아직 안익은 토마토 있을 시
			if ( board[nz][nx][ny] == 0) {
				//익은 토마토의 날짜 +1이 해당 토마토가 익은 날짜
				board[nz][nx][ny] = board[z][x][y] + 1;
				q.push({ nz, nx, ny });
			}
		}
	}
}


int main() {
	cin >> M >> N >> H;
	board.assign(H, vector<vector<int>>(N, vector<int>(M, 0)));
	
	for (int r = 0; r < H; r++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[r][i][j];
			}
		}
	}
	
	//각 높이에 존재하는 익은 토마토에서 전체 토마토가 익은 날짜 탐색 및 계산
	for (int r = 0; r < H; r++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[r][i][j] == 1) {
					q.push({ r, i, j });
				}
			}
		}
	}
	BFS();
	int maxDay = 0;
	//익혀진 토마토의 최대 날짜 찾기
	for (int r = 0; r < H; r++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//방문 못한 토마토 있을 시 모든 토마토 익힘 X
				if (board[r][i][j] == 0) {
					cout << -1;
					return 0;
				}
				//최대 날짜 찾기
				maxDay = max(maxDay, board[r][i][j]);
			}

		}
	}
	
	//처음 토마토는 1부터 이므로 1을 다시 빼줌
	cout << maxDay-1;

		
	return 0;
}
