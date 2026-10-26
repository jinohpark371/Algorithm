#include <iostream>
#include <vector>
using namespace std;

bool isPlindrome(string &s)
{
  int l = 0;
  int r = s.length() - 1;
  while (l < r)
  {
    if (s[l] != s[r])
      return false;
    l++;
    r--;
  }
  return true;
}

int main()
{
  for (int tc = 0; tc < 10; tc++)
  {
    int len;
    cin >> len;

    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        cin >> board[i][j];
      }
    }

    int cnt = 0;
    for (int x = 0; x < 8; x++)
    {
      for (int y = 0; y < 8; y++)
      {
        // 하 뱡향 회문 검사
        if (x + len <= 8)
        {
          string s;
          for (int nx = x; nx < x + len; nx++)
          {
            s += board[nx][y];
          }
          if (isPlindrome(s))
            cnt++;
        }

        // 오른쪽 뱡향 회문 검사
        if (y + len <= 8)
        {
          string s;
          for (int ny = y; ny < y + len; ny++)
          {
            s += board[x][ny];
          }
          if (isPlindrome(s))
            cnt++;
        }
      }
    }

    cout << '#' << tc + 1 << ' ' << cnt << '\n';
  }
}