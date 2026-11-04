#include <iostream>
#include <vector>
using namespace std;

bool isArrived = false;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void DFS(int r, int c, vector<string> &board)
{

  if (board[r][c] == '3')
  {
    isArrived = true;
    return;
  }
  else
    board[r][c] = '1';

  for (int dir = 0; dir < 4; dir++)
  {
    int nr = r + dr[dir];
    int nc = c + dc[dir];

    if (nr < 0 || nr >= 100 || nc < 0 || nc >= 100)
      continue;

    if (board[nr][nc] == '0' || board[nr][nc] == '3')
    {
      DFS(nr, nc, board);
      if (isArrived)
        return;
    }
  }
}

int main()
{
  for (int tc = 0; tc < 10; tc++)
  {
    int t;
    cin >> t;
    vector<string> board(100);

    int c, r;
    for (int i = 0; i < 100; i++)
    {
      cin >> board[i];
      int pos = board[i].find('2');
      if (pos != string::npos)
      {
        c = i;
        r = pos;
      }
    }

    DFS(c, r, board);
    cout << '#' << tc + 1 << ' ' << (isArrived ? 1 : 0) << '\n';
    isArrived = false;
  }
}