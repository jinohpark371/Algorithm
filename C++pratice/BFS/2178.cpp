#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int dx[4] = { 0 , 0, -1 ,1 }; //방향 좌표: 하 상
int dy[4] = { -1 , 1 , 0 , 0 }; //방향 좌표: 좌 우
int min_distance[100][100] = { -1 }; //모든 1좌표 최소거리
queue<pair<int, int>> q;
int board[100][100]; //좌표배열
int visited[100][100]; //방문 여부 확인 배열
int n, m;
string row;

void bfs() {
  
	while (!q.empty()) {
		pair<int, int>node = q.front(); q.pop();
		int x = node.first;
		int y = node.second;
		//현재 정점 방문 처리
		visited[x][y] = true;
		//좌우상하 순으로 현재 좌표에서 4방향계산
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			//좌표를 벗어남
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			//갈수 있는 좌표이고 아직 방문하지 않은 좌표라면
			if (board[nx][ny] == 1 && !visited[nx][ny]) {
				//아직 해당 좌표의 최소거리가 결정되지 않았다면
				if (min_distance[nx][ny] == -1) {
					//방문처리
					visited[nx][ny] =true;
					//현재 좌표의 최소거리에서 자신까지 거리인 1을 증가하여 해당방향 좌표 최소거리 계산
					min_distance[nx][ny] = min_distance[x][y]+1;
					//큐에 push
					q.push({ nx, ny });
				}
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> row;
		for (int j = 0; j < m; j++) {
			//string( 1,row[j]):문자 row[j]를 길이 1 짜리 문자열로 만듬
			board[i][j] = stoi(string( 1,row[j]));
		}
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			min_distance[i][j] = -1;

	//원점은 1칸 이동으로 간주
	min_distance[0][0] = 1;
	q.push({ 0,0 });
	bfs();

	//끝점 까지 가는데 걸리는 최소 칸
	cout << min_distance[n-1][m-1];
	return 0;
}