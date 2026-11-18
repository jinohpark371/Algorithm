#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int K, N;
string answer = "";
set<pair<string, int>> visited;

void DFS(string &s, int depth)
{
  if (K == depth)
  {
    answer = max(answer, s);
    return;
  }

  // 기존에 있던 조합인데 교환 횟수 까지 같다면 건너뛰기
  if (!visited.insert({s, depth}).second)
    return;

  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      swap(s[i], s[j]);
      DFS(s, depth + 1);
      swap(s[i], s[j]);
    }
  }
}

int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    string s;
    cin >> s >> K;

    N = s.size();
    answer = "";
    DFS(s, 0);
    visited.clear();
    cout << '#' << i + 1 << ' ' << answer << '\n';
  }
}