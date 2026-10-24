#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  for (int tc = 0; tc < 10; tc++)
  {
    vector<vector<int>> vec(100, vector<int>(100, 0));

    int t;
    cin >> t;
    for (int i = 0; i < 100; i++)
    {
      for (int j = 0; j < 100; j++)
      {
        cin >> vec[i][j];
      }
    }

    // 최댓값
    int mmax = 0;
    // 두 대각선 합
    int d1 = 0;
    int d2 = 0;
    for (int i = 0; i < 100; i++)
    {
      int row_sum = 0;
      int col_sum = 0;
      // 가로 방향, 세로 방향 합 계산 후 최댓값 갱신
      for (int j = 0; j < 100; j++)
      {
        row_sum += vec[i][j];
        col_sum += vec[j][i];
      }

      mmax = max({mmax, row_sum, col_sum});
      d1 += vec[i][i];
      d2 += vec[i][100 - 1 - i];
    }
    mmax = max({mmax, d1, d2});

    cout << '#' << t << ' ' << mmax << '\n';
  }
}