#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> dist;
vector<vector<int>> graph;

int BFS(int st)
{
  queue<int> q;
  q.push(st);

  int max_dist = 0;
  while (!q.empty())
  {
    int v = q.front();
    q.pop();

    for (int w : graph[v])
    {
      // 아직 방문하지 않은 정점, 시작 정점이 아닐때
      if (dist[w] == 0 && w != st)
      {
        dist[w] = dist[v] + 1;
        max_dist = max(dist[w], max_dist);
        q.push(w);
      }
    }
  }
  return max_dist;
}

int solution(int n, vector<vector<int>> edge)
{
  int answer = 0;

  graph.assign(n + 1, vector<int>(0));
  for (const auto &ed : edge)
  {
    graph[ed[0]].push_back(ed[1]);
    graph[ed[1]].push_back(ed[0]);
  }

  dist.assign(n + 1, 0);
  // 1번 노드부터 탐색 시작
  int mmax = BFS(1);
  // 1번 노드와 최대 거리를 가진 노드 탐색
  for (int i = 2; i <= n; i++)
  {
    if (mmax == dist[i])
      answer++;
  }
  return answer;
}