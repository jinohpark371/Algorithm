#include <string>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations)
{
  vector<int> answer;
  map<int, int> cnt;
  priority_queue<int> max_pq;
  priority_queue<int, vector<int>, greater<int>> min_pq;

  int total = 0;
  for (string oper : operations)
  {
    stringstream ss(oper);
    char cmd;
    int num;
    ss >> cmd >> num;

    if (cmd == 'I')
    {
      total++;
      cnt[num]++;
      max_pq.push(num);
      min_pq.push(num);
    }
    else if (cmd == 'D')
    {
      if (num == 1)
      {
        // 기존의 이미 삭제된 값이라면 무시
        while (!max_pq.empty() && cnt[max_pq.top()] <= 0)
        {
          max_pq.pop();
        }

        if (!max_pq.empty())
        {
          cnt[max_pq.top()]--;
          max_pq.pop();
          total--;
        }
      }
      else if (num == -1)
      {
        // 기존의 이미 삭제된 값이라면 무시
        while (!min_pq.empty() && cnt[min_pq.top()] <= 0)
        {
          min_pq.pop();
        }

        if (!min_pq.empty())
        {
          cnt[min_pq.top()]--;
          min_pq.pop();
          total--;
        }
      }
    }
  }
  if (total <= 0)
  {
    answer.push_back(0);
    answer.push_back(0);
  }
  else
  {
    // 이미 삭제된 요소 제거
    while (cnt[max_pq.top()] <= 0)
    {
      max_pq.pop();
    }

    while (cnt[min_pq.top()] <= 0)
    {
      min_pq.pop();
    }

    answer.push_back(max_pq.top());
    answer.push_back(min_pq.top());
  }
  return answer;
}