#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> vec(n);
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		dp[i] = vec[i];
	}
	//dp[j]는 j를 마지막으로 하는 최대 증가 부분 수열의 합
	//j까지는 증가 부분수열로 보장이 되어 있으로
	//j번쨰, i번쨰 끼리만 비교하면 성립함
	//i번쨰 요소를 붙일 수 있는지만 확인하면 됨
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[j] < vec[i]) {
				dp[i] = max(dp[i], dp[j] + vec[i]);
			}
		}
	}

	int mmax = 0;
	for (int i = 0; i < n; i++) {
		mmax = max(mmax, dp[i]);
	}


	cout << mmax;
	return 0;
}