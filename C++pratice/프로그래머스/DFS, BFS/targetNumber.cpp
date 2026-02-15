#include <string>
#include <vector>

using namespace std;
int cnt;

//각 숫자에 대해 더하거나 뺴는 경우에 대해서 모든 경우의수 탐색
void DFS(vector<int>& numbers, int idx, int target, int sum) {

    if (idx == numbers.size()) {
        if (sum == target) cnt++;
        return;
    }

    //현재 수를 더하기 선택
    DFS(numbers, idx + 1, target, sum + numbers[idx]);
    //현재 수를 빼기
    DFS(numbers, idx + 1, target, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    cnt = 0;
    DFS(numbers, 0, target, 0);
    return cnt;
}