#include <string>
#include <vector>

using namespace std;
int n;
vector<vector<int>> copied_dungeons;
vector<int> visited;
// 현재 피로도
int DFS(int k)
{
  int best = 0;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && k >= copied_dungeons[i][0])
    {
      visited[i] = 1;
      // 현재 피로도 소모하면서 탐색 진행, 자식들 중 최댓값 계산
      best = max(best, 1 + DFS(k - copied_dungeons[i][1]));
      visited[i] = 0;
    }
  }
  return best;
}

int solution(int k, vector<vector<int>> dungeons)
{
  n = dungeons.size();
  copied_dungeons = dungeons;
  visited.assign(n, 0);
  int answer = DFS(k);
  return answer;
}