#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
    int N;
    cin >> N;

    vector<int> weeks;
    for (int i = 0; i < 7; i++)
    {
      int num;
      cin >> num;
      weeks.push_back(num);
    }

    // 시작 요일을 다르게 해서 최소 기간 계산
    int answer = 1e9;
    for (int start = 0; start < 7; start++)
    {
      if (weeks[start] == 0)
        continue;

      int totalDays = 0, actualDays = 0, idx = start;
      while (actualDays != N)
      {
        if (weeks[idx] == 1)
          actualDays++;

        totalDays++;
        idx = (idx + 1) % 7;
      }
      answer = min(answer, totalDays);
    }

    cout << '#' << t + 1 << ' ' << answer << '\n';
  }
}