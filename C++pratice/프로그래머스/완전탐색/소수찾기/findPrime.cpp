#include <string>
#include <vector>
#include <set>

using namespace std;
string copied_numbers;
vector<bool> visited(8, false);
set<int> st;
int n;

bool isPrime(string s)
{
  int num = stoi(s);
  if (num == 1 || num == 0)
    return false;

  for (int i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
      return false;
  }

  return true;
}

void DFS(string num)
{
  if (num != "" && isPrime(num))
  {
    st.insert(stoi(num));
  }

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      num += copied_numbers[i];
      visited[i] = true;
      DFS(num);
      visited[i] = false;
      num.pop_back();
    }
  }
}

int solution(string numbers)
{
  n = numbers.length();
  copied_numbers = numbers;
  DFS("");
  return st.size();
}