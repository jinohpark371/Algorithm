#include <string>
#include <vector>

using namespace std;
string copied_word;
char vobel[5] = {'A', 'E', 'I', 'O', 'U'};
int answer = 0;
int cnt = 0;
bool found = false;

void DFS(string cur)
{
  if (found)
    return;
  if (copied_word == cur)
  {
    answer = cnt;
    found = true;
    return;
  }

  if (cur.size() == 5)
    return;

  for (int i = 0; i < 5; i++)
  {
    cnt++;
    DFS(cur + vobel[i]);
    if (found)
      return;
  }
  return;
}

int solution(string word)
{
  copied_word = word;
  DFS("");
  return answer;
}