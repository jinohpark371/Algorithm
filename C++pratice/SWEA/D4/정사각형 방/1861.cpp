#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    int N;
    cin >> N;

    int total = N * N;
    vector<int> r(total + 1, 0);
    vector<int> c(total + 1, 0);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
      {
        int x;
        cin >> x;
        r[x] = i;
        c[x] = j;
      }

    vector<int> len(total + 1, 0);
    int bestRoom = total;
    int bestLen = 1;
    len[bestRoom] = 1;
    for (int v = total - 1; v >= 1; v--)
    {
      bool adj = abs(r[v] - r[v + 1]) + abs(c[v] - c[v + 1]) == 1;
      len[v] = adj ? len[v + 1] + 1 : 1;

      if (bestLen <= len[v])
      {
        bestLen = len[v];
        bestRoom = v;
      }
    }

    cout << '#' << i + 1 << ' ' << bestRoom << ' ' << bestLen << '\n';
  }
}