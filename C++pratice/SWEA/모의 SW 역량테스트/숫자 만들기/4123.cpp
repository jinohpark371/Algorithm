#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> numbers;
vector<int> op;
vector<char> commands;
vector<char> seq;
int mmax = -100000000;
int mmin = 100000000;

void DFS(int idx, int cur)
{
  if (idx == N)
  {
    mmax = max(mmax, cur);
    mmin = min(mmin, cur);
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    if (op[i] == 0)
      continue;

    int next;
    if (i == 0)
      next = cur + numbers[idx];
    else if (i == 1)
      next = cur - numbers[idx];
    else if (i == 2)
      next = cur * numbers[idx];
    else
      next = cur / numbers[idx];

    op[i]--;
    DFS(idx + 1, next);
    op[i]++;
  }
}

int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {

    cin >> N;

    op.assign(4, 0);

    for (int i = 0; i < 4; i++)
    {
      cin >> op[i];
    }

    numbers.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
      cin >> numbers[i];
    }

    DFS(1, numbers[0]);
    cout << '#' << i + 1 << ' ' << (mmax - mmin) << '\n';
    mmax = -100000000;
    mmin = 100000000;
  }
}