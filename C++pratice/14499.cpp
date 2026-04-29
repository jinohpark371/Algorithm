#include <iostream>
using namespace std;

int dice[6] = { 0 };
//인덱스 의미
// 0: 위
// 1: 아래
// 2: 북
// 3: 남
// 4: 서
// 5: 동

//지도
int board[20][20] = { 0 };

//방향배열
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1,-1, 0, 0 };

//남쪽으로 굴리기
void rollingSouth() {
	int temp = dice[0];
	dice[0] = dice[2]; // 위 <-북
	dice[2] = dice[1]; // 북 <-아래
	dice[1] = dice[3]; //아래 <- 남
	dice[3] = temp; //남 <- 위
}

//북쪽으로 굴리기
void rollingNorth() {
	int temp = dice[0];
	dice[0] = dice[3];//위 <- 남
	dice[3] = dice[1];//남 <- 아래
	dice[1] = dice[2]; //아래 <- 북
	dice[2] = temp;//북 <- 위
}

//동쪽으로 굴리기
void rollingEast() {
	int temp = dice[0];
	dice[0] = dice[4]; //위 <- 서
	dice[4] = dice[1]; //서 <- 아래
	dice[1] = dice[5]; //아래 <- 동
	dice[5] = temp;// 동 <- 위
}

//서쪽으로 굴리기
void rollingWest() {
	int temp = dice[0];
	dice[0] = dice[5]; // 위 <- 동
	dice[5] = dice[1]; // 동 <- 아래
	dice[1] = dice[4]; //아래 <- 서
	dice[4] = temp; //서 <- 위
}

int main() {
	int n, m, x, y, cnt;
	cin >> n >> m >> x >> y >> cnt;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < cnt; i++) {
		int command;
		cin >> command;
		int nx = x + dx[command-1];
		int ny = y + dy[command-1];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (command == 1) rollingEast();
		else if (command == 2) rollingWest();
		else if (command == 3) rollingNorth();
		else rollingSouth();

		if (board[nx][ny] == 0) {
			board[nx][ny] = dice[1];
		}
		else {
			dice[1] = board[nx][ny];
			board[nx][ny] = 0;
		}

		cout << dice[0] << '\n';

		x = nx;
		y = ny;
	}

	return 0;
}