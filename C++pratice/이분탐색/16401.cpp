#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<long long> a(n);

	long long high = 0; //오른쪽 구간 시작 위치
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		high = max(high, a[i]); //가장 긴 길이로 항상 high 갱신
	}
	long long ans = 0; //나눠줄 최대 길이의 과자의 수
	long long low = 1; //왼쪽 구간 시작 위치
	while (low <= high) {
		long long mid = (low + high) / 2; //나눠줄 과자의 길이

		long long cnt = 0; //나눠줄 과자의 수
		for (auto x : a) cnt += x / mid; //현재 과자의 길이 mid로 자를때 나눠 줄 수 있는 과자의 수
		// 나눠줄 과자의 수가 조카의 수보다 많거나 같으면
		if (cnt >= m) {
			ans = mid; //현재 선택한 과자의 길이는 정답 후보
			low = mid + 1; //더 긴 길이에서 최적의 길이 탐색 시작
		}
		//나눠줄 과자의 수가 조카의 수 보다 적음
		else {
			high = mid - 1; //현재 기준길이 보다 더 짧은 길이에서 탐색 시작
		}

	}

	//만약 기준 길이로 나눈 과자의 수가 항상 조카의 수보다 적다면
	//과자를 나눠줄 수 없는 0 출력
	cout << ans;
	return 0;
}