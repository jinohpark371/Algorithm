#include <iostream>
#include <vector>
using namespace std;

vector<string> board(100);

// line행에서 start열부터 len 길이
bool isRowPal(int line, int start, int len)
{
  for (int l = start, r = start + len - 1; l < r; l++, r--)
    if (board[line][l] != board[line][r])
      return false;
  return true;
}

// line열에서 start행부터 len 길이
bool isColPal(int line, int start, int len)
{
  for (int l = start, r = start + len - 1; l < r; l++, r--)
    if (board[l][line] != board[r][line])
      return false;
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
          if (isRowPal(x, y, len) || isColPal(x, y, len))
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