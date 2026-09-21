#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> color(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
      cin >> color[i];
    }

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++)
    {
      int v, w;
      cin >> v >> w;
      adj[v].push_back(w);
      adj[w].push_back(v);
    }

    int full = 1 << K; // 마스크 갯수(모든 색 조합의 갯수)

    // dp[v][mask] : v에 있고 사용한 조합이 mask인 경로의 수
    vector<vector<long long>> dp(N + 1, vector<long long>(full, 0));

    // 1단계: 정점이 1개인 경로
    for (int v = 1; v <= N; v++)
    {
      int bit = 1 << (color[v] - 1);
      dp[v][bit] = 1;
    }

    long long answer = 0;
    // 2단계: 정점의 갯수가 2이상 k개 이하 경로에서 계산
    for (int len = 2; len <= K; len++)
    {
      vector<vector<long long>> ndp(N + 1, vector<long long>(full, 0));

      for (int v = 1; v <= N; v++)
      {
        for (int mask = 0; mask < full; mask++)
        {
          if (dp[v][mask] == 0)
            continue;
          // 지금 까지 사용한 색조합 mask를 찾았을때 인접 정점 탐색
          for (auto w : adj[v])
          {
            // 정점 w의 색
            int wbit = 1 << color[w] - 1;
            // 이미 해당 색을 사용해서 안됨
            if (mask & wbit)
              continue;
            // 정점 w까지 경로까지 사용한 색조합에 경로 갯수 누적 계산
            ndp[w][mask | wbit] += dp[v][mask];
          }
        }
      }

      // 정점 하나 추가한 경로 갯수 계산
      for (int v = 1; v <= N; v++)
      {
        for (int mask = 0; mask < full; mask++)
        {
          answer += ndp[v][mask];
        }
      }
      // 정점을 하나 더 추가한 dp로 변경
      dp = ndp;
    }

    cout << answer << '\n';
  }
}