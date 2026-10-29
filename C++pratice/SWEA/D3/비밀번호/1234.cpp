#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
  for (int tc = 0; tc < 10; tc++)
  {
    int n;
    cin >> n;
    stack<char> st;

    string s;
    while (n--)
    {
      char c;
      cin >> c;
      if (!s.empty() && s.back() == c)
      {
        s.pop_back();
      }
      else
      {
        s.push_back(c);
      }
    }
    cout << '#' << tc + 1 << ' ' << s << '\n';
  }
}