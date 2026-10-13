#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<int> copied_numbers;
int n;

void DFS(int sum, int depth, int target)
{
  if (depth == n)
  {
    if (sum == target)
      answer++;
    return;
  }

  int num = copied_numbers[depth];
  DFS(sum + num, depth + 1, target);
  DFS(sum - num, depth + 1, target);
}

int solution(vector<int> numbers, int target)
{
  copied_numbers = numbers;
  n = numbers.size();

  DFS(0, 0, target);
  return answer;
}