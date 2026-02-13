#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
//각 숫자는 선택과 선택X 분기로 빠지게 됨
//이전 숫자가 선택된 분기와 선택되지 못한 분기에서 다시
// 두 갈래로 나뉘면서 현재 까지 선택한 숫자의 합을 더함
//선택횟수가 현재 주어진 수열의 크기가 되었을때 
// 즉 현재분기에서 부분수열을 다 만들었을때 현째까지
//더한 부분 수열의 합을 s와 비교
int n, s;
int cnt = 0;
void DFS(int idx, int sum) {
	if (idx == n) {
		if (sum == s) cnt++;
		return;
	}

	DFS(idx + 1, sum + vec[idx]); //선택
	DFS(idx + 1, sum); //미선택
}

int main() {
	cin >> n >> s;
	vec.assign(n, 0);

	for (int i = 0; i < n; i++) cin >> vec[i];

	DFS(0, 0);

	//공집합 처리
	if (s == 0) cnt--;
	cout << cnt;
	return 0;
}