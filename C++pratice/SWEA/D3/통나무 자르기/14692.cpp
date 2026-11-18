#include <iostream>
using namespace std;

int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    int tongnamu;
    cin >> tongnamu;

    bool isAliceWin = ((tongnamu - 1) % 2 == 1);
    cout << '#' << i + 1 << ' ' << (isAliceWin ? "Alice" : "Bob") << '\n';
  }
}