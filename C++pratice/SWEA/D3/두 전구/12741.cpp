#include <iostream>

using namespace std;

int main()
{
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // 겹치는 구간 길이 = 끝나는 시각중 최솟값 - 시작 시간 중 최댓값
    // 0이하면 겹치지 않음
    int answer = max(0, (min(B, D) - max(A, C)));

    cout << '#' << t + 1 << ' ' << answer << '\n';
  }
}