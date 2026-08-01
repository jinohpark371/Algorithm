#include <string>
#include <vector>
#include<algorithm>
using namespace std;
vector<vector<pair<int, int>>> blanks;
vector<vector<pair<int, int>>> puzzles;

vector<vector<int>> visited;

int N;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void DFS(vector<vector<int>>& board, int x, int y, int target, vector<pair<int, int>>& shape) {
    shape.push_back({ x, y });
    visited[x][y] = 1;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        if (board[nx][ny] == target && !visited[nx][ny]) {
            DFS(board, nx, ny, target, shape);
        }
    }

}

void normalize(vector<pair<int, int>>& shape) {
    int minX = 100;
    int minY = 100;

    for (auto& p : shape) {
        minX = min(p.first, minX);
        minY = min(p.second, minY);
    }

    for (auto& p : shape) {
        p.first -= minX;
        p.second -= minY;
    }

    sort(shape.begin(), shape.end());
}

vector<pair<int, int>> rotate(vector<pair<int, int>> shape) {
    for (auto& p : shape) {
        int x = p.first;
        int y = p.second;

        p.first = y;
        p.second = -x;
    }

    normalize(shape);

    return shape;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    N = game_board[0].size();

    visited.assign(50, vector<int>(50, 0));

    //game_board의 비어있는 칸 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && game_board[i][j] == 0) {
                vector<pair<int, int>>shape;
                DFS(game_board, i, j, 0, shape);

                normalize(shape);

                blanks.push_back(shape);
            }
        }
    }

    visited.assign(50, vector<int>(50, 0));

    //table에서 퍼즐 조각 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && table[i][j] == 1) {
                vector<pair<int, int>>shape;
                DFS(table, i, j, 1, shape);

                normalize(shape);

                puzzles.push_back(shape);
            }
        }
    }

    vector<bool> used(puzzles.size(), false);

    for (auto& blank : blanks) {

        for (int i = 0; i < puzzles.size(); i++) {

            if (used[i]) continue;
            if (blank.size() != puzzles[i].size()) continue;

            vector<pair<int, int>> cur = puzzles[i];

            for (int r = 0; r < 4; r++) {

                if (blank == cur) {
                    answer += cur.size();
                    used[i] = 1;
                    break;
                }

                cur = rotate(cur);
            }

            if (used[i]) break;
        }
    }

    return answer;
}