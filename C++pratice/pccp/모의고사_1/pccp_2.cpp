#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int answer = 0;
vector<vector<int>> ability;
vector<int> used;

void DFS(int L, int sum)
{

  // L : 현재 고르는 종목 번호
  // sum : 지금까지 능력치 합

  // 모든 종목을 다 골랐으면
  // 기존에 알고 있던 합과 현재 선택한 마지막 학생이  능력을 합한 값과 비교 해서 최대값 계산

  if (L == M)
  {
    answer = max(answer, sum);
    return;
  }

  for (int i = 0; i < N; i++)
  {
    if (!used[i])
    {
      used[i] = 1;                     // 학생 i 사용
      DFS(L + 1, sum + ability[i][L]); // L번 종목에 i번 학생 배정
      used[i] = 0;                     // 다음 종목 탐색 때는 이번 학생은 계산에 포함되게 구성
    }
  }
}

int solution(vector<vector<int>> ability_input)
{
  ability = ability_input;
  N = ability_input.size();    // 학생 수
  M = ability_input[0].size(); // 종목 수

  used.assign(N, 0);

  DFS(0, 0);

  return answer;
}
