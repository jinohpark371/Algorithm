#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int N;
    cin >> N;
    vector<int> vec(N, 0);
    for (int i = 0; i < N; i++)
    {
      cin >> vec[i];
    }

    cout << '#' << i + 1 << ' ';
    int maxPrice = 0;
    long long profit = 0;
    for (int i = N - 1; i >= 0; i--)
    {
      if (vec[i] >= maxPrice)
      {
        maxPrice = vec[i];
      }
      else
      {
        profit += maxPrice - vec[i];
      }
    }
    cout << profit << '\n';
  }
}