#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, limit;
vector<pair<int, int>> items;
int answer;

void DFS(int st, int score, int calories)
{
  if (calories > limit)
    return;
  else
  {
    answer = max(answer, score);
  }

  for (int i = st; i < N; i++)
  {
    score += items[i].first;
    calories += items[i].second;
    DFS(i + 1, score, calories);
    score -= items[i].first;
    calories -= items[i].second;
  }
}

int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    cin >> N >> limit;

    for (int i = 0; i < N; i++)
    {

      int score, calo;
      cin >> score >> calo;
      items.push_back({score, calo});
    }

    answer = 0;
    DFS(0, 0, 0);
    items.clear();
    cout << '#' << i + 1 << ' ' << answer << '\n';
  }
}