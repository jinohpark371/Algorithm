#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	vector<int> dp(n + 1, 0);

	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		vec.push_back({ t, p });
	}

	// dp[i] = i일부터 시작해서 얻을 수 있는 최대 수익으로 보장되어 있음
	int mmax = 0;
	for (int i = n - 1; i >= 0; i--) {
		int t = vec[i].first;
		int p = vec[i].second;


		//상담이 가능한 경우
		//현재 상담을 건너뛴 다음날 기준 이후부터의 최대 수익,
		//현재 상담을 진행헀을때
		//현재 금액과 t일 이후 기준 최대금액 더한 값과 중 큰 금액이 해당 값
		if (i + t <= n) {
			dp[i] = max(dp[i + 1], p + dp[i + t]);
		}
		//현재 상담이 불가능할때
		//다음날 기준부터 끝까지의 최대 수익이
		//현재 날짜 기준 최대 수익
		else {
			dp[i] = dp[i + 1];
		}

		mmax = (mmax, dp[i]);
	}

	cout << mmax;
}