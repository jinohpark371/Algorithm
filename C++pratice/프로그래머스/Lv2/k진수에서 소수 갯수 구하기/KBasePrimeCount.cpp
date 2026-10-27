#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(long long num)
{
  if (num <= 1)
    return false;
  for (long long i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
      return false;
  }
  return true;
}

int solution(int n, int k)
{
  int answer = 0;

  string str = "";
  while (n > 0)
  {
    str += '0' + n % k;
    n = n / k;
  }
  reverse(str.begin(), str.end());

  string cur = "";
  for (char c : str)
  {
    if (c != '0')
    {
      cur += c;
    }
    else
    {
      if (!cur.empty() && isPrime(stoll(cur)))
        answer++;
      cur = "";
    }
  }
  if (!cur.empty() && isPrime(stoll(cur)))
    answer++;

  return answer;
}