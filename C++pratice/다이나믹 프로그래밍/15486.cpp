#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> vec(n);
	vector<long long> dp(n + 1, 0);

	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	long long mmax = 0;
	for (int i = n - 1; i >= 0; i--) {
		int t = vec[i].first;
		int p = vec[i].second;

		if (i + t <= n) {
			dp[i] = max(dp[i + 1], p + dp[i + t]);
		}
		else {
			dp[i] = dp[i + 1];
		}

		mmax = max(mmax, dp[i]);
	}

	cout << mmax;
	return 0;
}