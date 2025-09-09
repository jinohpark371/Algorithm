#include <iostream>
using namespace std;

int dx[4] = { 0, 0, -1 ,1 };
int dy[4] = { -1 ,1, 0, 0 };
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

bool inrange(int x, int y) {
	return x < 0 || y < 0 ||x >= n || y >= n;
}

bool sameColor(char a, char b, bool colorBlind) {
	if (!colorBlind) return a == b; //일반인 전용 색 구분

	if (a == 'B' || b == 'B') return a == b; //적록색약인 사람의 파란색 영역 구분

	return (a == 'R' || a == 'G') && (b == 'R' || b == 'G');//적록색약인 사람의 빨강, 초록 영역을 하나로 구분
}

void dfs(int x, int y, bool colorBlind) {
	visited[x][y] = true;
	char here = board[x][y]; //현재 좌표의 색깔

	for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (inrange(nx, ny) || visited[nx][ny]) continue;
			//현재 좌표와 다음 좌표의 색구분을 통한 영역 확장
			if (sameColor(here, board[nx][ny], colorBlind)) {
				dfs(nx, ny, colorBlind);
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
	int normal = 0;  //정상인이 보는 영역의 수
	bool colorBlind = false; //적록색약 구분
	//정상인이 보는 영역의 수 세기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j, colorBlind);
				normal++;
			}

		}
	}

	//방문 여부 배열 초기화
	init();

	//적록색약이 보는 영역의 수 세기
	int cb = 0;
	colorBlind = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j, colorBlind);
				cb++;
			}
		}
	}

	cout << normal << " " << cb;

	return 0;
}