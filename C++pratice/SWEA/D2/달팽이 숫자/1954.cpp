#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    int st_row = 0;
    int end_row = N - 1;

    int st_col = 0;
    int end_col = N - 1;

    int num = 1;

    while (st_row <= end_row && st_col <= end_col)
    {
      for (int i = st_col; i <= end_col; i++)
      {
        board[st_row][i] = num;
        num++;
      }
      st_row++;

      for (int i = st_row; i <= end_row; i++)
      {
        board[i][end_col] = num;
        num++;
      }
      end_col--;

      for (int i = end_col; i >= st_col; i--)
      {
        board[end_row][i] = num;
        num++;
      }
      end_row--;

      for (int i = end_row; i >= st_row; i--)
      {
        board[i][st_col] = num;
        num++;
      }
      st_col++;
    }

    cout << '#' << i + 1 << '\n';
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cout << board[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}