#include <iostream>
#include <vector>

using namespace std;
vector<long long> dp;

//(n - 1)자리 이친수 전부에 0을 붙일 수 있음
// 개수 = dp[n - 1]
//1이 붙은 건 이전 자리수에선 끝자리에 0이 붙어야 가능
//11이 안 되니까
//1을 붙이려면 바로 앞이 0이어야 함
// n-2 자리수에서 0을 붙인 거니까 n-2 자리수의 경우를 더함
//(n - 1)자리에서 끝이 0인 것들은 n-2 자리 이찬수에서 +0
//이들은 전부(n - 2)자리 이친수 + 0
//그래서 개수 = dp[n - 2]

int main() {
	int n; 
	cin >> n;

	dp.assign(n, 0);

	//1자리, 2자리 수 일때 이친수를 만들 수 있는 경우의 수
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n - 1];

	return 0;

}