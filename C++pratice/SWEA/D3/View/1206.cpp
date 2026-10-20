#include <iostream>
#include <vector>
using namespace std;

int main()
{
  for (int i = 0; i < 10; i++)
  {
    int N;
    cin >> N;

    vector<int> vec(N, 0);
    for (int i = 0; i < N; i++)
    {
      cin >> vec[i];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
      if (vec[i] != 0)
      {
        // 범위 검사
        if (i - 2 < 0 || i + 2 >= N)
          continue;

        int mmax = 0;

        mmax = max(vec[i - 1], mmax);
        mmax = max(vec[i - 2], mmax);
        mmax = max(vec[i + 1], mmax);
        mmax = max(vec[i + 2], mmax);

        if (vec[i] > mmax)
          cnt += vec[i] - mmax;
      }
    }

    cout << '#' << i + 1 << ' ' << cnt << '\n';
  }
}