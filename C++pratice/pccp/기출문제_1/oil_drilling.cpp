#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
vector<vector<int>> copied_land;
vector<vector<int>> visited;
set<int> colums;
map<int, int> oils;
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int DFS(int x, int y)
{
  visited[x][y] = 1;
  int area = 1;
  colums.insert(y);
  for (int dir = 0; dir < 4; dir++)
  {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
      continue;

    if (!visited[nx][ny] && copied_land[nx][ny])
    {
      area += DFS(nx, ny);
    }
  }

  return area;
}

int solution(vector<vector<int>> land)
{
  int answer = 0;
  copied_land = land;
  n = copied_land.size();
  m = copied_land[0].size();

  visited.assign(n, vector<int>(m, 0));
  for (int i = 0; i < m; i++)
  {
    int area = 0;
    for (int j = 0; j < n; j++)
    {
      if (!visited[j][i] && copied_land[j][i])
      {
        area = DFS(j, i);
        for (auto col : colums)
        {
          oils[col] += area;
        }
        colums.clear();
      }
    }
  }

  for (auto oil : oils)
  {
    answer = max(answer, oil.second);
  }

  return answer;
}