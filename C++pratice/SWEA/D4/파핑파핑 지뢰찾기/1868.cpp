#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<string> board;
vector<vector<int>> cnt;
vector<vector<bool>> opened;

void BFS(int sx, int sy)
{
  queue<pair<int, int>> q;
  opened[sx][sy] = true;
  q.push({sx, sy});

  while (!q.empty())
  {
    auto [x, y] = q.front();
    q.pop();

    for (int dir = 0; dir < 8; dir++)
    {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;
      if (opened[nx][ny])
        continue;
      opened[nx][ny] = true;
      if (cnt[nx][ny] == 0)
      {
        q.push({nx, ny});
      }
    }
  }
}

int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    cin >> N;

    board.assign(N, "");
    cnt.assign(N, vector<int>(N, 0));
    opened.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
      string s;
      cin >> s;
      board[i] = s;
    }

    for (int x = 0; x < N; x++)
    {
      for (int y = 0; y < N; y++)
      {
        if (board[x][y] == '.')
        {
          int click = 0;
          for (int dir = 0; dir < 8; dir++)
          {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
              continue;

            if (board[nx][ny] == '*')
            {
              click++;
            }
          }

          cnt[x][y] = click;
        }
      }
    }

    // 0인칸부터 탐색 시작
    int click = 0;
    for (int x = 0; x < N; x++)
      for (int y = 0; y < N; y++)
        if (board[x][y] == '.' && cnt[x][y] == 0 && !opened[x][y])
        {
          click++;
          BFS(x, y);
        }

    for (int x = 0; x < N; x++)
      for (int y = 0; y < N; y++)
        if (board[x][y] == '.' && cnt[x][y] != 0 && !opened[x][y])
        {
          click++;
        }

    cout << '#' << i + 1 << ' ' << click << '\n';
  }
}