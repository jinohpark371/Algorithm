#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<vector<int>> tri(n + 1, vector<int>(n + 1));
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	dp[1][1] = tri[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
			}
		}

	}


	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, dp[n][i]);
	}

	cout << answer;
	return 0;
}