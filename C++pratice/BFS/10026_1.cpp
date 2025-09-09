#include <iostream>
using namespace std;

int dx[4] = {0, 0, -1 ,1};
int dy[4] = {-1 ,1, 0, 0};
char board[100][100];
bool visited[100][100];
int n;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

void dfs(int x, int y, char ch, bool isVaild) {
	visited[x][y] = true;
	
	if (isVaild) {
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (ch == 'G' || ch=='R') {
				if (!visited[nx][ny] && (board[nx][ny] == 'G' || board[nx][ny] == 'R')) {
					dfs(nx, ny, ch, isVaild);
					}
			}
			else {
					if (!visited[nx][ny] && board[nx][ny] == ch) {
						dfs(nx, ny, ch, isVaild);
					}
			}
		}
	}
	else {
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (!visited[nx][ny] && board[nx][ny] == ch) {
				dfs(nx, ny, ch, isVaild);
			}
		}
	}
	
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int a = 0;  //정상인이 보는 영역의 수
	int b = 0;	//적록색약이 보는 영역의 수
	bool isVaild = false; //적록색약 구분

	//정상인이 보는 영역의 수 세기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j, board[i][j], isVaild);
				a++;
			}

		}
	}

	//방문 여부 배열 초기화
	init();

	//적록색약이 보는 영역의 수 세기
	isVaild = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j, board[i][j], isVaild);
				b++;
			}

		}
	}

	cout << a << " " << b;
	
	return 0;
}