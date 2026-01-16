#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> tri(n + 1, vector<int>(n+1));
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	//dp[i][j] = 꼭대기부터 (i, j) 위치까지 내려왔을 때의 누적 최대 합
	//dp[i][j] = max(위에서 올 수 있는 값들) + 자기 자신

	//초기 dp값
	dp[1][1] = tri[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			//맨 왼쪽(경계, 이전 경로는 정해져 있음)
			if (j == 1) {
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			}
			//맨 오른쪽(경계, 이전 경로는 정해져 있음)
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			}
			// 가운데
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j])+tri[i][j];
			}
		}
	}

	//최대값은 마지막 층에서 가장 큰 값
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, dp[n][i]);
	}

	cout << answer;
	return 0;
}


