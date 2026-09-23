#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    vector<string> board(8);
    for (int i = 0; i < 8; i++)
    {
      string s;
      cin >> s;
      board[i] = s;
    }

    vector<bool> rows(8, false);
    vector<bool> cols(8, false);

    bool isVaild = true;
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        if (board[i][j] == 'O')
        {
          if (!rows[i] && !cols[j])
          {
            rows[i] = true;
            cols[j] = true;
            cnt++;
          }
          else
          {
            isVaild = false;
            break;
          }
        }
      }
      if (!isVaild)
        break;
    }
    if (isVaild && cnt == 8)
    {
      cout << '#' << i + 1 << ' ' << "yes" << '\n';
    }
    else
    {
      cout << '#' << i + 1 << ' ' << "no" << '\n';
    }
  }
}