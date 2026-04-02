#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<int>> adj(101, vector<int>(101, 0));
vector<vector<int>> dist(101, vector<int>(101, -1));

void BFS(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nextX = x + dx[dir];
            int nextY = y + dy[dir];

            if (nextX < 0 || nextX >= 101 || nextY < 0 || nextY >= 101) continue;

            if (adj[nextX][nextY] != 1) continue;

            if (dist[nextX][nextY] == -1) {
                dist[nextX][nextY] = dist[x][y] + 1;
                q.push({ nextX, nextY });
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {

    for (vector<int> rect : rectangle) {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;


        //사각형 모든  1로 채우기
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                adj[i][j] = 1;
            }
        }
    }

    for (vector<int> rect : rectangle) {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;

        //내부를 0으로 채워서 테두리 생성
        for (int i = x1 + 1; i < x2; i++) {
            for (int j = y1 + 1; j < y2; j++) {
                adj[i][j] = 0;
            }
        }
    }


    BFS(characterX * 2, characterY * 2);

    int answer = dist[itemX * 2][itemY * 2] / 2;
    return answer;
}