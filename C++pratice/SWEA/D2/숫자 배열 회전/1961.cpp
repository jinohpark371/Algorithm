#include <iostream>
#include <vector>
using namespace std;

void rotate_90(vector<string> &row, vector<string> &rotated, int N)
{
  // 90도 회전 1번
  for (int i = 0; i < N; i++)
  {
    int roatated_idx = 0;
    for (int j = N - 1; j >= 0; j--)
    {
      rotated[i][roatated_idx] = row[j][i];
      roatated_idx++;
    }
  }
  row = rotated;
}

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int N;
    cin >> N;
    vector<string> row(N);
    vector<string> rotated(N);
    for (int i = 0; i < N; i++)
    {
      string s = "";
      for (int j = 0; j < N; j++)
      {
        char c;
        cin >> c;
        s += c;
      }
      row[i] = s;
      rotated[i] = s;
    }

    cout << '#' << i + 1 << '\n';

    rotate_90(row, rotated, N);
    vector<string> rot_90 = row;
    rotate_90(row, rotated, N);
    vector<string> rot_180 = row;
    rotate_90(row, rotated, N);
    vector<string> rot_270 = row;

    for (int i = 0; i < N; i++)
    {
      cout << rot_90[i] << ' ' << rot_180[i] << ' ' << rot_270[i] << '\n';
    }
  }
}