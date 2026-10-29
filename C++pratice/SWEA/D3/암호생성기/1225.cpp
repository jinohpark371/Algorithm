#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  for (int tc = 0; tc < 10; tc++)
  {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 0; i < 8; i++)
    {
      int num;
      cin >> num;
      q.push(num);
    }

    int cycle = 0;
    while (true)
    {
      cycle = cycle % 5 + 1;

      int top = q.front();
      q.pop();
      if (top - cycle <= 0)
      {
        q.push(0);
        break;
      }
      else
      {
        q.push(top - cycle);
      }
    }

    cout << '#' << tc + 1 << ' ';
    while (!q.empty())
    {
      cout << q.front() << ' ';
      q.pop();
    }
    cout << '\n';
  }
}