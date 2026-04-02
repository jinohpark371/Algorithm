#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>vec(n);
	vector<int>dp(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		dp[i] = 1;
	}

	//dp[j]는 j번째를 마지막으로 했을때 최대 증가 부분 수열 길이
	//i번쨰가 j번째 요소보다 크다면 j번쨰까지는 증가 부분 수열이
	//보장되어 있기에 그냥 길이를 dp[j]에서 1 증가 시키면 됨
	//항상 최대 유지 기존 길이가 더 길다면 넘어감
	int mmax = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[j] < vec[i]) {
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		mmax = max(mmax, dp[i]);
	}

	cout << mmax;
	return 0;
}