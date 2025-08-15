#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> stair(n + 1);
	vector<int> dp(n + 1);

	/*
	// 아이디어 요약
// - 모든 계단 i를 '임시 목적지'로 본다.
// - dp[i] = 연속 3칸 금지를 지키며 i에 도달하는 모든 합법 경로 중 최대 점수.
// - 아래(작은 i)부터 dp를 채우면, dp[n]은 자연스럽게 전역 최적해가 된다.
// - i로 올 수 있는 합법 전이는 두 가지뿐:
//   1) (i-2) -> i : 마지막 이동이 2칸(이 경우 i-1을 밟지 않으므로 3연속 방지)
//   2) (i-3) -> (i-1) -> i : 2칸 + 1칸(이 경우 i-2를 건너뛰므로 3연속 방지)
// - 따라서 점화식:
//     dp[i] = max(dp[i-2], dp[i-3] + stair[i-1]) + stair[i]
// - 기저값:
//     dp[1] = stair[1]
//     dp[2] = stair[1] + stair[2]  (연속 2칸까지 허용)

계단의 높이가 아무리 높아져도 그냥 0번부터 4번계단을 계산한 거 처럼 자신의 3단계 아래의 최대값을 가진 dp[i-3] dp[i-2]부터 알면 문제 없음
	*/

	for (int i = 1; i < n + 1; i++) cin >> stair[i];
	dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	if (n >= 3) {
		for (int i = 3; i < n + 1; i++) {
			dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 1]) + stair[i];
		}
	}


	cout << dp[n];


}