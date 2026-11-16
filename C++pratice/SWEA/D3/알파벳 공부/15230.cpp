#include <iostream>
using namespace std;

string s = "abcdefghijklmnopqrstuvwxyz";
int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    string input;
    cin >> input;

    int cnt = 0;
    for (int i = 0; i < input.size(); i++)
    {
      if (s[i] == input[i])
        cnt++;
      else
        break;
    }

    cout << '#' << i + 1 << ' ' << cnt << '\n';
  }
}