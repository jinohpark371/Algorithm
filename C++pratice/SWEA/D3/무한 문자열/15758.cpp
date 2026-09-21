#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    string S, T;
    cin >> S >> T;
    if (S + T == T + S)
    {
      cout << '#' << i + 1 << ' ' << "yes" << '\n';
    }
    else
    {
      cout << '#' << i + 1 << ' ' << "no" << '\n';
    }
  }
}