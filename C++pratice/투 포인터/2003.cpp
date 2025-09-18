#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m; //수열의 크기와 원하는 수
	cin >> n >> m;

	vector<int> seq(n); //수열

	for (int i = 0; i < n; i++) cin >> seq[i];

	int en = 0, sum = 0; //구간 시작과 끝
	int cnt = 0; //m과 동일한 경우의 수
	for (int st = 0; st < n; st++) {
		while (sum < m) { //현재 구간의 합이 m보다 작다면 구간을 늘려가며 구간의 합 증가
			if (en >= n)break; //끝 구간이 수열의 크기를 넘어서면 종료
			sum += seq[en];
			en++;
		}
		if (sum >= m) {
			if (sum == m) {
				cnt++; //현재 연속된 수열의 구간의 합이 m과 같을 때 경우의 수 1증가
			}
			sum -= seq[st];//현재 구간의 합이 더 크다면 앞쪽 구간의 길이를 줄여 합을 감소
		}
	}
	cout << cnt;
	return 0;
}