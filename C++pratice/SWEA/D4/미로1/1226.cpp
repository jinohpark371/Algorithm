#include <iostream>
#include <vector>
using namespace std;
vector<string> board(16);
int sx = 0;
int sy = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool isArrive = false;

void DFS(int x, int y)
{
  if (board[x][y] == '3')
    isArrive = true;
  // 해당 좌표 방문 처리
  board[x][y] = '1';

  for (int dir = 0; dir < 4; dir++)
  {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16)
      continue;

    if (board[nx][ny] == '1')
      continue;

    DFS(nx, ny);
  }
}

int main()
{
  for (int i = 0; i < 10; i++)
  {
    int tc;
    cin >> tc;
    for (int i = 0; i < 16; i++)
    {
      string s;
      cin >> s;
      if (s.find("2") != string::npos)
      {
        sx = i;
        sy = s.find("2");
      }

      board[i] = s;
    }
    DFS(sx, sy);

    if (isArrive)
    {
      cout << '#' << i + 1 << ' ' << 1 << '\n';
    }
    else
    {
      cout << '#' << i + 1 << ' ' << 0 << '\n';
    }
    isArrive = false;
  }
}