#include <iostream>
#include <vector>
using namespace std;

vector<string> board(100);

bool isRowPal(int x, int y, int len)
{
  for (int l = y, r = y + len - 1; l < r; l++, r--)
  {
    if (board[x][l] != board[x][r])
      return false;
  }
  return true;
}

bool isColPal(int x, int y, int len)
{
  for (int l = x, r = x + len - 1; l < r; l++, r--)
  {
    if (board[l][y] != board[r][y])
      return false;
  }
  return true;
}

int main()
{
  for (int tc = 0; tc < 10; tc++)
  {
    int t;
    cin >> t;
    for (int i = 0; i < 100; i++)
    {
      cin >> board[i];
    }

    int ans = 0;
    for (int len = 100; len >= 1; len--)
    {
      bool found = false;
      for (int x = 0; x < 100 && !found; x++)
      {
        for (int y = 0; y + len <= 100; y++)
        {
          if (isRowPal(x, y, len) || isColPal(y, x, len))
          {
            found = true;
            break;
          }
        }
      }

      if (found)
      {
        ans = len;
        break;
      }
    }

    cout << '#' << t << ' ' << ans << '\n';
  }
}