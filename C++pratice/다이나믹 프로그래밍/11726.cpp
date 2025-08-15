#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	//1번 인덱스부터 n번 인덱스 까지 사용을 위해 n+1크기로 벡터 선언
	vector<int> dp(n+1);
	dp[1] = 1;
	if (n >= 2) {
		dp[2] = 2;
	}
	//타일의 한 종류씩 끝에 있을떄 경우의 수를 합한 dp값
	// 2*1타일 끝에 있을때 i-1번까지의 길이의 경우의 수와
	//1*2 타일 두개가 겹쳐서 쌓여 있을때 i-2번까지의 길이의 경우의 수를
	//합한 것이 i번째 길이까지의 경우의 수
	for (int i = 3; i < n+1; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	cout << dp[n] ;

	
	return 0;
}