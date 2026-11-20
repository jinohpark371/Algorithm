#include <iostream>
#include <vector>
using namespace std;

vector<string> weeks = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main()
{
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
    string day;
    cin >> day;

    int idx = 0;
    for (int j = 0; j < 7; j++)
    {
      if (day == weeks[j])
      {
        idx = j;
        break;
      }
    }

    // 현재 요일에서 다음 일요일까지 날짜 차이 계산
    cout << '#' << t + 1 << ' ' << 7 - idx << '\n';
  }
}