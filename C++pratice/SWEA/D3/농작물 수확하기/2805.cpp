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
    vector<vector<int>> board(N);

    for (int i = 0; i < N; i++)
    {
      string s;
      cin >> s;
      for (char c : s)
      {
        board[i].push_back(c - '0');
      }
    }

    int sum = 0;
    // 마름모 시작, 끝 인덱스
    int st = N / 2;
    int en = N / 2;

    // 현재 계산 중인 행 인덱스
    int row = 0;
    // 마름모 위쪽 수익 계산
    while (st != 0 && en != N - 1)
    {
      for (int i = st; i <= en; i++)
      {
        sum += board[row][i];
      }
      // 다음 행으로 이동
      row++;

      st--;
      en++;
    }

    // 마름모 아래쪽 수익 계산
    while (st <= N / 2 && en >= N / 2)
    {
      for (int i = st; i <= en; i++)
      {
        sum += board[row][i];
      }
      // 다음 행으로 이동
      row++;

      st++;
      en--;
    }

    cout << '#' << i + 1 << ' ' << sum << '\n';
  }
}