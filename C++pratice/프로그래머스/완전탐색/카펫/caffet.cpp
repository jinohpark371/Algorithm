#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
  vector<int> answer;
  int total = brown + yellow;
  for (int w = 2;; w++)
  {
    bool isStop = false;
    // w의 최소시작크기일때 h 탐색 시작
    if (w * w >= total)
    {
      for (int h = 3; w * h <= total; h++)
      {
        if (h > w)
          break;

        if (brown == w * h - (w - 2) * (h - 2))
        {
          answer.push_back(w);
          answer.push_back(h);
          isStop = true;
          break;
        }
      }
    }

    if (isStop)
      break;
  }
  return answer;
}