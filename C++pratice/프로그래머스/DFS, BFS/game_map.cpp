#include<vector>
#include<queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<vector<int> > board;
int n, m;

int BFS(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({ sx, sy });

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (x == n - 1 && y == m - 1) return board[x][y];

        for (int dir = 0; dir < 4; dir++) {
            int nextX = x + dx[dir];
            int nextY = y + dy[dir];

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;

            if (board[nextX][nextY] == 0) continue;

            if (board[nextX][nextY] == 1) {
                board[nextX][nextY] += board[x][y];
                q.push({ nextX,nextY });
            }

        }

    }

    return 1;

}

int solution(vector<vector<int> > maps)
{
    board = maps;

    n = maps.size();
    m = maps[0].size();

    int answer = 0;
    answer = BFS(0, 0);

    return answer != 1 ? answer : -1;
}