#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> board;

int simulate(int c)
{
  int r = 0;
  int cnt = 0;
  // 왼쪽으로 갈 수 있을때 왼쪽 끝까지 이동
  while (r < 99)
  {
    if (c - 1 >= 0 && board[r][c - 1] == 1)
    {
      while (c - 1 >= 0 && board[r][c - 1] == 1)
      {
        c--;
        cnt++;
      }
    }
    // 오른쪽으로 갈 수 있을 때 오른쪽 끝까지 이동
    else if (c + 1 <= 99 && board[r][c + 1] == 1)
    {
      while (c + 1 <= 99 && board[r][c + 1] == 1)
      {
        c++;
        cnt++;
      }
    }
    // 아래로 내려가기
    r++;
    cnt++;
  }
  return cnt;
}

int main()
{
  for (int tc = 0; tc < 10; tc++)
  {
    int t;
    cin >> t;
    board.assign(100, vector<int>(100, 0));
    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++)
        cin >> board[i][j];

    int min = 1e9;
    int min_idx = 0;
    for (int c = 0; c < 100; c++)
    {
      if (board[0][c] == 1)
      {
        int dist = simulate(c);
        if (min >= dist)
        {
          min = dist;
          min_idx = c;
        }
      }
    }

    cout << '#' << tc + 1 << ' ' << min_idx << '\n';
  }
}