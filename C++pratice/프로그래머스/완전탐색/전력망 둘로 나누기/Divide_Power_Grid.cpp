#include <string>
#include <vector>

using namespace std;
vector<int> visited;
vector<vector<int>> adj;

int DFS(int cur, int bannded_a, int bannded_b)
{
  visited[cur] = 1;
  int area = 1;
  for (auto v : adj[cur])
  {
    bool isBanned = (cur == bannded_a && v == bannded_b) || (v == bannded_a && cur == bannded_b);
    if (!visited[v] && !isBanned)
    {
      area += DFS(v, bannded_a, bannded_b);
    }
  }
  return area;
}

int solution(int n, vector<vector<int>> wires)
{
  int answer = 101;
  visited.assign(n + 1, 0);
  adj.assign(n + 1, vector<int>());
  for (auto wire : wires)
  {
    int v = wire[0];
    int w = wire[1];
    adj[v].push_back(w);
    adj[w].push_back(v);
  }

  for (auto wire : wires)
  {
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        int area = DFS(i, wire[0], wire[1]);
        answer = min(answer, abs(area - (n - area)));
      }
    }
    visited.assign(n + 1, 0);
  }
  return answer;
}