#include <iostream>
#include <vector>
using namespace std;

int N, K;
int cnt = 0;
vector<bool> visited;
vector<int> nums;
void DFS(int st, int cur)
{
  if (cur == K)
    cnt++;

  for (int i = st; i < N; i++)
  {
    cur += nums[i];
    DFS(i + 1, cur);
    cur -= nums[i];
  }
}

int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    cin >> N >> K;

    nums.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
      cin >> nums[i];
    }
    DFS(0, 0);
    visited.clear();
    cout << '#' << i + 1 << ' ' << cnt << '\n';
    cnt = 0;
  }
}