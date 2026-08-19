#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
  int answer = health;
  int maxTime = attacks[attacks.size() - 1][0];

  int attack_idx = 0;
  int success_time = 0;
  int time = bandage[0];
  int secToPlus = bandage[1];
  int extarPlus = bandage[2];
  for (int t = 1; t <= maxTime; t++)
  {

    if (attack_idx < attacks.size() &&
        t == attacks[attack_idx][0])
    {
      answer -= attacks[attack_idx][1];
      attack_idx++;
      success_time = 0;

      if (answer <= 0)
        break;
      else
        continue;
    }

    answer = min(health, answer + secToPlus);
    success_time++;
    if (success_time == time)
    {
      answer = min(health, answer + extarPlus);
      success_time = 0;
    }
  }
  return answer <= 0 ? -1 : answer;
}