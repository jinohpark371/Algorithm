#include <iostream>
#include <algorithm>
using namespace std;

/*
DFS 탐색 순서
어떤 한 점에서 시작한다 (dfs(x, y) 호출)

그 점에서 **갈 수 있는 방향(상하좌우)**을 하나씩 살핀다

갈 수 있다면, 그 방향으로 계속 깊이 들어간다 (dfs(nx, ny) 호출)

더 이상 갈 수 없는 지점에 도달하면 → 재귀가 종료되고 원래 자리로 돌아온다

돌아온 곳에서 남은 방향들을 다시 살핀다

모든 방향을 다 탐색했으면 → 완전히 종료되고 처음 호출한 dfs()로 반환
*/
int dx[4] = { 0 , 0, -1, 1 }; //상하방향
int dy[4] = { -1, 1, 0 , 0 }; //좌우방향
int board[500][500] = { 0 }; //도화지 
int visited[500][500] = { 0 };//방문여부표시배열
int n, m;

int dfs(int x, int y) {
	visited[x][y] = true;
	int area = 1;
	//현재 좌표에서  좌우하상 이동
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		//좌표가 현재 도화지 크기를 넘어간다면 다시 좌표계산
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		//모든 방향을 조사했는데 더이상 유효방향 좌표가 없거나 방문하지 않은 좌표가 없다면
		//그동안 들어갔던 재귀를 끝내고 area값을 재귀를 처음 호출한 dfs함수에서
		//area값을 누적한 값을 받아 반환
		if (board[nx][ny] == 1 && !visited[nx][ny]) {
			//재귀를 통해 다음 좌표로 이동 
			area += dfs(nx, ny);
		}
	}
	return area;
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

		}
	}

	int picturecount = 0;
	int maxarea = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				//현재 좌표에서 구한 지역크기계산
				int area = dfs(i, j);
				//사진의 갯수 증가
				picturecount++;
				//사진의 최대 넓이 계산
				maxarea = max(maxarea, area);
			}
		}
	}

	cout << picturecount << "\n" << maxarea;

	return 0;
}

