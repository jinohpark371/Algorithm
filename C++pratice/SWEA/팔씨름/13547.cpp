#include <iostream>
using namespace std;

int main()
{
  int tc;
  cin >> tc;

  for (int i = 0; i < tc; i++)
  {
    int N;
    string s;
    cin >> s;

    int win = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == 'o')
      {
        win++;
      }
    }

    // 이긴 경기 수 + 남은 경기 수 가 8보다 클 경우 이길 가능성 있음
    bool isWin = false;
    int remain = 15 - (int)s.size();
    isWin = (win + remain >= 8);

    cout << '#' << i + 1 << ' ' << (isWin ? "YES" : "NO") << '\n';
  }
}