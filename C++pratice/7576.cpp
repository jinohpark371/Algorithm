#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0 , 0, - 1, 1 };
int dy[4] = { -1, 1, 0 , 0 };
int board[1000][1000];
int n, m;
queue<pair<int, int>> q;


int bfs() {
    
    //시작점 동시에 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                q.push({ i, j });
            }
           
        }
    }

    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int x = p.first;
        int y = p.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (board[nx][ny] == 0) {
                board[nx][ny] =board[x][y]+ 1; //현재 좌표에서 다음 좌표로 이동했을때 1증가하여 이 정점에 도달하는 데 걸린 단계(일수) 표시
                q.push({ nx, ny });
            }
        }
    }

    //날짜 계산은 bfs탐색을 진행할때마다 자신의 좌우 하상 좌표에 자신의 단계에 1을 증가하여 다음단계를 표시한다
    // 다음 탐색에서도 자신의 유효탐색 범위에 있는 좌표에게 자신의 단계에 1씩 증가하여 다음 단계 표시.
    //큐가 다 비게 되어 탐색을 종료하면 여기서 가장 큰 단계횟수를 가진 좌표가 마지막으로 익은 토마토이다.
    int days = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //익지 못한 토마토 존재
            if (board[i][j] == 0) return -1;
            days = max(days, board[i][j]);
        }
    }
   

    // 시작 익은 토마토의 실제 경과 일수로는 0일 차 이므로 
    return days-1;

}

int main() { 
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int days=bfs();
    cout << days;
    return 0; 
}