#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
  int answer = 0;
  int n = queue1.size();

  long long sum1 = 0;
  long long sum2 = 0;
  for (int i = 0; i < n; i++)
  {
    sum1 += queue1[i];
    sum2 += queue2[i];
  }

  if ((sum1 + sum2) % 2 != 0)
    return -1;

  int queue1_idx = 0;
  int queue2_idx = 0;

  while (sum1 != sum2)
  {
    if (queue1_idx >= 2 * n || queue2_idx >= 2 * n)
      return -1;

    if (sum1 < sum2)
    {
      sum2 -= queue2[queue2_idx];
      queue1.push_back(queue2[queue2_idx]);
      sum1 += queue2[queue2_idx];
      queue2_idx++;
    }
    else
    {
      sum1 -= queue1[queue1_idx];
      queue2.push_back(queue1[queue1_idx]);
      sum2 += queue1[queue1_idx];
      queue1_idx++;
    }
    answer++;
  }
  return answer;
}