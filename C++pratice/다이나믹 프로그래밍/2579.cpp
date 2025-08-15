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
	// ���̵�� ���
// - ��� ��� i�� '�ӽ� ������'�� ����.
// - dp[i] = ���� 3ĭ ������ ��Ű�� i�� �����ϴ� ��� �չ� ��� �� �ִ� ����.
// - �Ʒ�(���� i)���� dp�� ä���, dp[n]�� �ڿ������� ���� �����ذ� �ȴ�.
// - i�� �� �� �ִ� �չ� ���̴� �� ������:
//   1) (i-2) -> i : ������ �̵��� 2ĭ(�� ��� i-1�� ���� �����Ƿ� 3���� ����)
//   2) (i-3) -> (i-1) -> i : 2ĭ + 1ĭ(�� ��� i-2�� �ǳʶٹǷ� 3���� ����)
// - ���� ��ȭ��:
//     dp[i] = max(dp[i-2], dp[i-3] + stair[i-1]) + stair[i]
// - ������:
//     dp[1] = stair[1]
//     dp[2] = stair[1] + stair[2]  (���� 2ĭ���� ���)

����� ���̰� �ƹ��� �������� �׳� 0������ 4������� ����� �� ó�� �ڽ��� 3�ܰ� �Ʒ��� �ִ밪�� ���� dp[i-3] dp[i-2]���� �˸� ���� ����
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