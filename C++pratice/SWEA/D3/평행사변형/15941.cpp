#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int n;
    cin >> n;
    // 최대 넓이 -> 각 변이 n길이인 정사각형
    cout << '#' << i + 1 << ' ' << n * n << '\n';
  }
}