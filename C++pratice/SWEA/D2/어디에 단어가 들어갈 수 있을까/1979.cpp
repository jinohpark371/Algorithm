#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cin >> board[i][j];
      }
    }

    int cnt = 0;
    // 가로 순회
    for (int i = 0; i < N; i++)
    {
      int ssize = 0;
      for (int j = 0; j < N; j++)
      {
        // 흰색(빈 공간)
        if (board[i][j])
        {
          ssize++;
        }
        // 검정(벽)을 만났을때
        else
        {
          if (ssize == K)
          {
            cnt++;
          }
          ssize = 0;
        }
      }
      // 끝나는 구간일때 ssize 검사
      if (ssize == K)
        cnt++;
    }

    // 세로 순회
    for (int i = 0; i < N; i++)
    {
      int ssize = 0;
      for (int j = 0; j < N; j++)
      {
        // 흰색(빈 공간)
        if (board[j][i])
        {
          ssize++;
        }
        // 끝나는 구간,검정(벽)을 만났을때
        else
        {
          if (ssize == K)
          {
            cnt++;
          }
          ssize = 0;
        }
      }

      // 끝나는 구간일떄 ssize 검사
      if (ssize == K)
        cnt++;
    }

    cout << '#' << i + 1 << ' ' << cnt << '\n';
  }
}