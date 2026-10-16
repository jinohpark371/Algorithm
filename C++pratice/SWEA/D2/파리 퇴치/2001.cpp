#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cin >> board[i][j];
      }
    }

    int max_area = 0;
    for (int i = 0; i <= N - M; i++)
    {
      for (int j = 0; j <= N - M; j++)
      {
        int current_area = 0;

        for (int r = i; r < i + M; r++)
        {
          for (int k = j; k < j + M; k++)
          {
            current_area += board[r][k];
          }
        }
        max_area = max(current_area, max_area);
      }
    }

    cout << '#' << i + 1 << ' ' << max_area << '\n';
  }
}