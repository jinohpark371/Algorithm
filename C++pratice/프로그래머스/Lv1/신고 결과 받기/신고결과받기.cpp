#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
  int n = id_list.size();
  vector<int> answer(n, 0);
  map<string, int> id;
  map<string, set<string>> record; // 신고한 사람 -> 신고 당한 사람들
  map<string, int> freq;           // 신고 당함 횟수

  for (int i = 0; i < n; i++)
    id[id_list[i]] = i;

  for (auto str : report)
  {
    stringstream ss(str);
    string from, to;
    ss >> from >> to;
    // 중복 신고 방지 처리
    if (record[from].insert(to).second)
      freq[to]++;
  }

  for (auto [from, targets] : record)
  {
    for (auto to : targets)
    {
      if (freq[to] >= k)
        answer[id[from]]++;
    }
  }

  return answer;
}