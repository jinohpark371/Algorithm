#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define X first
#define Y second
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
string board[1000];
int dist1[1000][1000];
int dist2[1000][1000];
int r, c;

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }


    for (int i = 0; i < r; i++) {
        //각 행 -1로 채우기
        fill(dist1[i], dist1[i] + c, -1);
        fill(dist2[i], dist2[i] + c, -1);
    }

    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            //불의 초기 시작 점 추가, 시작점은 초기거리 0
            if (board[i][j] == 'F') {
                dist1[i][j] = 0;
                q1.push({ i, j });
            }
            //지훈이의 초기 시작점 추가, 시작점은 초기거리 0
            if (board[i][j] == 'J') {
                dist2[i][j] = 0;
                q2.push({ i, j });
            }
        }
    }

    //불에 대한 bfs로 각 이동가능한 각 좌표에 대해서 최단 시간계산
    while (!q1.empty()) {
        auto cursor = q1.front(); q1.pop();

        //접근 가능 좌표에 대한 계산
        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cursor.X;
            int ny = dy[dir] + cursor.Y;

            //범위 조건 검사
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            //벽 조건 검사
            if (board[nx][ny] == '#') continue;
            //아직 방문하지 않았다면 
            if (dist1[nx][ny] == -1) {
                dist1[nx][ny] = dist1[cursor.X][cursor.Y] + 1;
                //해당 좌표 방문을 위해 큐에 추가
                q1.push({ nx, ny });
            }
        }
    }


    //지훈이에 대한 bfs로 각 좌표에 대해 도달가능한 최단 시간계산
    while (!q2.empty()) {
        auto cursor = q2.front(); q2.pop();

        //접근 가능 좌표에 대한 계산
        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cursor.X;
            int ny = dy[dir] + cursor.Y;

            //범위 조건 검사
            //범위를  나갔다면 나간거에 대한 +1시간추가하여 탈출시간 출력
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                cout << dist2[cursor.X][cursor.Y] + 1;
                return 0;
            }


            //벽 조건 검사
            if (board[nx][ny] == '#') continue;
            //이미 방문 
            if (dist2[nx][ny] != -1) continue;

            //한 점에서 이동한 좌표에 대한 다음 시간
            int nt = dist2[cursor.X][cursor.Y] + 1;

            //해당 좌표에 불이 존재 하고
            // 만약 해당 좌표에서 불과 같거나 더 많은 시간을 썼다면 해당 좌표 방문 불가
            if (dist1[nx][ny] != -1 && nt >= dist1[nx][ny]) continue;
            //해당좌표는 불보다 빠른 시간을 가지므로 좌표까지 걸리는 시간 추가
            dist2[nx][ny] = nt;
            //큐에 push하여 다음 방문 준비
            q2.push({ nx, ny });

        }
    }
    //시간을 출력하지 못하고 여기까지 왔다면 지훈이는 탈출 불가능
    cout << "IMPOSSIBLE";
    return 0;
}
