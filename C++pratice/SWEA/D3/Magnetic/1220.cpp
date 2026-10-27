#include <iostream>
#include <vector>
using namespace std;

int main()
{
  for (int tc = 0; tc < 10; tc++)
  {
    int n;
    cin >> n;
    vector<string> board(100);
    for (int i = 0; i < 100; i++)
    {
      string s = "";
      for (int j = 0; j < 100; j++)
      {
        char c;
        cin >> c;
        s += c;
      }
      board[i] = s;
    }

    // 자성체 1 기준 교착상태 판단
    int cnt = 0;
    for (int y = 0; y < 100; y++)
    {
      bool seenOne = false;
      for (int x = 0; x < 100; x++)
      {
        if (board[x][y] == '1')
        {
          seenOne = true;
        }
        else if (board[x][y] == '2' && seenOne)
        {
          cnt++;
          seenOne = false;
        }
      }
    }
    cout << '#' << tc + 1 << ' ' << cnt << '\n';
  }
}