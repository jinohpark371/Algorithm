#include <iostream>
#include <vector>
using namespace std;

int N;
int answer = 0;
vector<bool> col(10, false);
vector<bool> diag1(20, false);
vector<bool> diag2(20, false);

void DFS(int r)
{
  // 모든 퀸을 다 놓았음
  if (r == N)
  {
    answer++;
    return;
  }

  for (int c = 0; c < N; c++)
  {
    // 이미 행, 열, 두 대각선 방향으로 퀸 존재
    if (col[c] || diag1[r - c + N - 1] || diag2[r + c])
      continue;
    // 퀸 놓기
    col[c] = diag1[r - c + N - 1] = diag2[r + c] = true;
    DFS(r + 1); // 다음 행에서 탐색
    // 백트래킹
    col[c] = diag1[r - c + N - 1] = diag2[r + c] = false;
  }
}

int main()
{
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
    cin >> N;
    DFS(0);
    cout << '#' << t + 1 << ' ' << answer << '\n';
    answer = 0;
  }
}