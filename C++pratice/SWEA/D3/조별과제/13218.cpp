#include <iostream>
using namespace std;

int main()
{
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
    int num;
    cin >> num;
    cout << '#' << t + 1 << ' ' << num / 3 << '\n';
  }
}