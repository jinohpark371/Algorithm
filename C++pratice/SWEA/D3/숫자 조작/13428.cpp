#include <iostream>
#include <climits>
using namespace std;

int N;
string num;

int main()
{
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
    cin >> num;
    N = num.size();

    string mmax = num, mmin = num;

    for (int i = 0; i < N - 1; i++)
    {
      for (int j = i + 1; j < N; j++)
      {
        // 맨앞에 0이 오는걸 방지
        if (i == 0 && num[j] == '0')
          continue;

        swap(num[i], num[j]);
        mmax = max(mmax, num);
        mmin = min(mmin, num);
        // 백트래킹
        swap(num[i], num[j]);
      }
    }
    cout << '#' << t + 1 << ' ' << mmin << ' ' << mmax << '\n';
  }
}