#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> wait(N, 0);
    for (int i = 0; i < N; i++)
    {
      cin >> wait[i];
    }

    sort(wait.begin(), wait.end());
    bool ok = true;

    for (int j = 0; j < N; j++)
    {
      if (wait[j] / M * K < j + 1)
      {
        ok = false;
        break;
      }
    }

    cout << '#' << i + 1 << ' ' << (ok ? "Possible" : "Impossible") << '\n';
  }
}