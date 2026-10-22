#include <iostream>
#include <vector>
using namespace std;

int main()
{

  for (int i = 0; i < 10; i++)
  {
    int dump;
    cin >> dump;
    vector<int> vec(100, 0);
    int max = 0;
    int max_idx = -1;
    int min = 150;
    int min_idx = -1;
    for (int i = 0; i < 100; i++)
    {
      cin >> vec[i];
      if (max < vec[i])
      {
        max = vec[i];
        max_idx = i;
      }
      if (min > vec[i])
      {
        min = vec[i];
        min_idx = i;
      }
    }

    while (dump--)
    {
      // 최고 높이에서 최소 높이로 하나 주기
      vec[max_idx] -= 1;
      vec[min_idx] += 1;

      // 연산후의 최대, 최소 찾기
      max = 0;
      max_idx = -1;
      min = 150;
      min_idx = -1;
      for (int i = 0; i < 100; i++)
      {
        if (max < vec[i])
        {
          max = vec[i];
          max_idx = i;
        }
        if (min > vec[i])
        {
          min = vec[i];
          min_idx = i;
        }
      }
    }
    cout << '#' << i + 1 << ' ' << max - min << '\n';
  }
}