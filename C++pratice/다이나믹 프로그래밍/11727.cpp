#include <iostream>
using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;

	//dp[n] = n번째까지 채우는 경우의 수
	//끝에 세로 1×2 타일 1개를 놓는 경우 -> n-1칸,  dp[n-1]
	//끝에 가로로 채우는 경우 (2칸 사용) -> 앞쪽은 n-2칸, dp[n-2] * 2 (폭이 2칸이 타일이 두개)
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[n] % 10007;
	return 0;
}